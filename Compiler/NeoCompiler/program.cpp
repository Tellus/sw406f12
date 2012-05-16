#include "Scanner/scanner.h"
#include "Parser/parser.h"

int main(int argc, char* argv[])
{
	scanner::Scanner *scanner = new scanner::Scanner();

	for (int i = 1; i < argc; i++)
	{
		scanner->add_file(argv[i]);
		std::cout << "Adding file " << argv[i] << std::endl;
	}

	tokens::Token *stream;

	try
	{
		stream = scanner->scan();
	}
	catch (errors::CompileError *e)
	{
		std::cout << e->what() << " at " << e->where();
		return 0;
	}

	std::cout << "Scanning done." << std::endl;

	parser::Parser *parser = new parser::Parser();

	trees::AbstractSyntaxNode *tree = NULL;

	try
	{
		tree = parser->parse(stream);
	}
	catch (errors::CompileError *e)
	{
		std::cout << e->what() << " at " << e->where();
		return 0;
	}

	tree->print(0);

	typecheck::SymbolTable &table = typecheck::SymbolTable::handle();

	try
	{
		tree->visit(&table.declarations);
	}
	catch (char const *ex) // TODO: Switch to CompileError
	{
		std::cout << ex << std::endl;
		return 0;
	}
	catch (errors::CompileError *e)
	{
		std::cout << e->what();
		return 0;
	}

	tree->emit();

	return 0;
}

