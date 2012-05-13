/// @file
///
/// This file contains definitions related to the types of token

#pragma once

// Types
#define FORMAT_TOKENTYPE unsigned int

namespace tokens
{

// For checks which might incorrectly match others
const FORMAT_TOKENTYPE TokentypeDelay = 0x800;

// Special tokens
const FORMAT_TOKENTYPE TokentypeEnd = 0x10;
const FORMAT_TOKENTYPE TokentypeNone = 0x11;

// Punctuation
const FORMAT_TOKENTYPE TokentypeSemicolon = 0x20;
const FORMAT_TOKENTYPE TokentypeComma = 0x21;
const FORMAT_TOKENTYPE TokentypeDot = 0x22;

// Brackets, etc
const FORMAT_TOKENTYPE TokentypeLBrace = 0x30;
const FORMAT_TOKENTYPE TokentypeRBrace = 0x31;
const FORMAT_TOKENTYPE TokentypeLBracket = 0x32;
const FORMAT_TOKENTYPE TokentypeRBracket = 0x33;
const FORMAT_TOKENTYPE TokentypeLParan = 0x34;
const FORMAT_TOKENTYPE TokentypeRParan = 0x35;

// Primitives
const FORMAT_TOKENTYPE TokentypeNumber = 0x40;
const FORMAT_TOKENTYPE TokentypeString = 0x41;
const FORMAT_TOKENTYPE TokentypeBool = 0x42;

// Assignments
const FORMAT_TOKENTYPE TokentypeAssign = 0x50;
const FORMAT_TOKENTYPE TokentypePlusAssign = 0x51;
const FORMAT_TOKENTYPE TokentypeMinusAssign = 0x52;
const FORMAT_TOKENTYPE TokentypeMultiplyAssign = 0x53;
const FORMAT_TOKENTYPE TokentypeDivideAssign = 0x54;

// Arithmentic Operators
const FORMAT_TOKENTYPE TokentypePlus = 0x60 | TokentypeDelay;
const FORMAT_TOKENTYPE TokentypeMinus = 0x61 | TokentypeDelay;
const FORMAT_TOKENTYPE TokentypeMultiply = 0x62 | TokentypeDelay;
const FORMAT_TOKENTYPE TokentypeDivide = 0x63 | TokentypeDelay;

// Comparisons
const FORMAT_TOKENTYPE TokentypeEqual = 0x70;
const FORMAT_TOKENTYPE TokentypeNotEqual = 0x71;
const FORMAT_TOKENTYPE TokentypeGreaterEqual = 0x72;
const FORMAT_TOKENTYPE TokentypeGreater = 0x73 | TokentypeDelay;
const FORMAT_TOKENTYPE TokentypeLessEqual = 0x74;
const FORMAT_TOKENTYPE TokentypeLess = 0x75 | TokentypeDelay;

// Ignored
const FORMAT_TOKENTYPE TokentypeComment = 0x80;

// Variables, keywords
const FORMAT_TOKENTYPE TokentypeMake = 0x91;
const FORMAT_TOKENTYPE TokentypeFrom = 0x92;
const FORMAT_TOKENTYPE TokentypeReference = 0x93;
const FORMAT_TOKENTYPE TokentypeValue = 0x94;
const FORMAT_TOKENTYPE TokentypeIdentifier = 0x95 | TokentypeDelay;

// Anymask
const FORMAT_TOKENTYPE TokentypeAny = 0xFFFFFFFF;

} /* namespace tokentypes */
