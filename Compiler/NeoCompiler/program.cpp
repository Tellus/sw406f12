#include "Scanner/scanner.h"
#include "Parser/parser.h"

int main(int argc, char* argv[])
{
    /** PHASE 1 - SCAN **/
    scanner::Scanner *scanner = new scanner::Scanner();

    // For each file passed from the command line, add it.
    for (int i = 1; i < argc; i++)
    {
        scanner->add_file(argv[i]);
        std::cout << "Adding file " << argv[i] << std::endl;
    }

    // Prep the token stream.
    // Seems to be an unbounded array. Dangerous stuff.
    tokens::Token *stream;

    // Invoke the scanner itself. Breaks, possibly, if any syntax error is
    // encountered.
    // TODO: Add detail on when exceptions are thrown.
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

    /** PHASE 2 - PARSE **/

    // New parser.
    parser::Parser *parser = new parser::Parser();

    // New AST.
    trees::AbstractSyntaxNode *tree = NULL;

    // As with the scanner, invoke the parser and wait for success or failure.
    try
    {
        tree = parser->parse(stream);
    }
    catch (errors::CompileError *e)
    {
        std::cout << e->what() << " at " << e->where();
        return 0;
    }

    // Recursively prints the node and its children.
    tree->print(0);

    /** PHASE 3 - CONTEXTUAL ANALYSIS **/

    // Symbol table.
    typecheck::SymbolTable &table = typecheck::SymbolTable::handle();

    // Visitor pattern. Recursively visit nodes through the tree.
    // TODO: Determine if this is good or misunderstood visitor pattern.
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

    // Emit the code for the final AST.
    tree->emit();

    return 0;
}

