#pragma once

#include "../Token/token.h"
#include "../Trees/abstractsyntaxtree.h"
#include "../ErrorHandling/compileerror.h"

#include <sstream>

namespace parser
{

/**
 * The parser is the second phase of our compiler. It handles the secondary
 * lexical analysis pertaining to the grammar, not syntax, of the language.
 **/
class Parser
{
public:
    /**
     * Creates a new parser instance.
     **/
	Parser();
	
	/**
	 * Destructor stub.
	 **/
	virtual ~Parser();

    /**
     * Parses a token stream as created by the scanner.
     * \param stream Token stream in the form of a linked list. In reality,
     * this parameter is a single token, linked with the rest of the stream.
     * \return Root node of the resulting AST.
     **/
	trees::AbstractSyntaxNode *parse(tokens::Token *stream);

private:
    /**
     * Advances the token stream.
     * \todo Read and analyse this method. I'm getting the bit operations, but
     * not the results.
     **/
	tokens::Token *advance(FORMAT_TOKENTYPE type = tokens::TokentypeAny);
	
	/**
	 * Reads the next token in the stream.
	 * \param lookahead Amount of lookahead to apply before returning.
	 * \return The i'th token in the stream from current token, where i is the
	 * requested lookahead. Will return TokentypeEnd if at, or beyond, the last
	 * token in the stream.
	 **/
	FORMAT_TOKENTYPE input(std::size_t lookahead = 0);

    /**
     * Verifies and ultimately accepts a langname program.
     * \return ProgramNode, the root of our AST.
     **/
	trees::AbstractSyntaxNode *accept_program();
	
	/**
	 * Verifies a langname declaration (i.e. a "make" statement).
	 * \return A populated DeclarationNode.
	 **/
	trees::AbstractSyntaxNode *accept_declaration();

	/* Deprecated */
	trees::AbstractSyntaxNode *accept_assingment_list();

	trees::AbstractSyntaxNode *accept_assignment();
	trees::AbstractSyntaxNode *accept_value();
	trees::AbstractSyntaxNode *accept_set();
	trees::AbstractSyntaxNode *accept_condition();
	trees::AbstractSyntaxNode *accept_call();
	trees::AbstractSyntaxNode *accept_expression();
	trees::AbstractSyntaxNode *accept_term();
	trees::AbstractSyntaxNode *accept_factor();
	trees::AbstractSyntaxNode *accept_single_value();
	trees::AbstractSyntaxNode *accept_class_member();

    /**
     * First token in the stream. Reference point or useless?
     **/
	tokens::Token *start;
	
	/**
	 * Token currently being parsed.
	 **/
	tokens::Token *current;
};

} /* namespace parser */
