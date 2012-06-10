/// @file
///
/// This file contains definitions related to the types of token

#pragma once

/**
 * All types are simple represented as uints.
 **/
#define FORMAT_TOKENTYPE unsigned int

namespace tokens
{

// For checks which might incorrectly match others
const FORMAT_TOKENTYPE TokentypeDelay = 0x800;

/**
 * Special token denoting the end of the token stream.
 **/
const FORMAT_TOKENTYPE TokentypeEnd = 0x10;

/**
 * Special token denoting a null token.
 **/
const FORMAT_TOKENTYPE TokentypeNone = 0x11;

/**
 * Token for semicolons.
 **/
const FORMAT_TOKENTYPE TokentypeSemicolon = 0x20;

/**
 * Token for commas.
 **/
const FORMAT_TOKENTYPE TokentypeComma = 0x21;

/**
 * Token for periods.
 **/
const FORMAT_TOKENTYPE TokentypeDot = 0x22;

/**
 * Token type denoting left brace ("{").
 **/
const FORMAT_TOKENTYPE TokentypeLBrace = 0x30;

/**
 * Token type denoting right brace (("}").
 **/
const FORMAT_TOKENTYPE TokentypeRBrace = 0x31;

/**
 * Token type denoting left brackets ("[").
 **/
const FORMAT_TOKENTYPE TokentypeLBracket = 0x32;

/**
 * Token type denoting right bracket ("]").
 **/
const FORMAT_TOKENTYPE TokentypeRBracket = 0x33;

/**
 * Token type denoting left parentheses ("(").
 **/
const FORMAT_TOKENTYPE TokentypeLParan = 0x34;

/**
 * Token type denoting right parentheses (")").
 **/
const FORMAT_TOKENTYPE TokentypeRParan = 0x35;

/**
 * Token type denoting a number (primitive).
 **/
const FORMAT_TOKENTYPE TokentypeNumber = 0x40;

/**
 * Token type denoting a string (primitive).
 **/
const FORMAT_TOKENTYPE TokentypeString = 0x41;

/**
 * Token type denoting a boolean value (primitive).
 **/
const FORMAT_TOKENTYPE TokentypeBool = 0x42;

/**
 * Token type denoting an assignment ("=").
 **/
const FORMAT_TOKENTYPE TokentypeAssign = 0x50;

/**
 * Token type denoting addition assignment compositional ("+:").
 **/
const FORMAT_TOKENTYPE TokentypePlusAssign = 0x51;

/**
 * Token type denoting subtraction assignment compositional ("-:").
 **/
const FORMAT_TOKENTYPE TokentypeMinusAssign = 0x52;

/**
 * Token type denoting multiplication assignment compositional ("*:").
 **/
const FORMAT_TOKENTYPE TokentypeMultiplyAssign = 0x53;

/**
 * Token type denoting divition assignment compositional ("/:")
 **/
const FORMAT_TOKENTYPE TokentypeDivideAssign = 0x54;

/**
 * Token type denoting addition ("+").
 **/
const FORMAT_TOKENTYPE TokentypePlus = 0x60 | TokentypeDelay;

/**
 * Token type denoting subtraction ("-").
 **/
const FORMAT_TOKENTYPE TokentypeMinus = 0x61 | TokentypeDelay;

/**
 * Token type denoting multiplication ("*").
 **/
const FORMAT_TOKENTYPE TokentypeMultiply = 0x62 | TokentypeDelay;

/**
 * Token type denoting division ("/").
 **/
const FORMAT_TOKENTYPE TokentypeDivide = 0x63 | TokentypeDelay;

/**
 * Token type denoting equality test ("==" - I think).
 **/
const FORMAT_TOKENTYPE TokentypeEqual = 0x70;

/**
 * Token type denoting inequality ("!=" - I think).
 **/
const FORMAT_TOKENTYPE TokentypeNotEqual = 0x71;

/**
 * Token type denoting greater than or equal (">=").
 **/
const FORMAT_TOKENTYPE TokentypeGreaterEqual = 0x72;

/**
 * Token type denoting greater than (">").
 **/
const FORMAT_TOKENTYPE TokentypeGreater = 0x73 | TokentypeDelay;

/**
 * Token type denoting less than or equal ("<=").
 **/
const FORMAT_TOKENTYPE TokentypeLessEqual = 0x74;

/**
 * Token type denoting less than ("<").
 **/
const FORMAT_TOKENTYPE TokentypeLess = 0x75 | TokentypeDelay;

/**
 * Token type denoting a comment.
 **/
const FORMAT_TOKENTYPE TokentypeComment = 0x80;

/**
 * Token type denoting a Primarch declaration ("make" part).
 **/
const FORMAT_TOKENTYPE TokentypeMake = 0x91;

/**
 * Token type denoting declaration ("from" part).
 **/
const FORMAT_TOKENTYPE TokentypeFrom = 0x92;

/**
 * Token type denoting a reference (i.e. "ability = [Fireball]" - that last
 * bit). I'm assuming this is for usage in RHS.
 **/
const FORMAT_TOKENTYPE TokentypeReference = 0x93;

/**
 * Token type denoting a value (... I'm blank.).
 **/
const FORMAT_TOKENTYPE TokentypeValue = 0x94;

/**
 * Token type denoting an identifier (... wasn't that also a reference?). I'm
 * assuming this is for any LHS identifier.
 * \todo Figure out difference between this and TokentypeReference in greater
 * detail.
 **/
const FORMAT_TOKENTYPE TokentypeIdentifier = 0x95 | TokentypeDelay;

/**
 * Token type denoting any type of token. Any. Any at all.
 **/
const FORMAT_TOKENTYPE TokentypeAny = 0xFFFFFFFF;

} /* namespace tokentypes */
