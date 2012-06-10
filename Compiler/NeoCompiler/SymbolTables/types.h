/// types.h
///
/// This file contains type and metatype definitions.

#pragma once

#define FORMAT_TYPE unsigned int

namespace typecheck
{

/**
 * A none-type applied to AbstractSyntaxNodes during construction, as well as
 * an "empty" type during certain type comparisons.
 **/
const FORMAT_TYPE MetatypeNone = 0;

/**
 * Type representation of our number type.
 **/
const FORMAT_TYPE TypeNumber = 1u;

/**
 * Type representation of strings.
 **/
const FORMAT_TYPE TypeString = TypeNumber << 1;

/**
 * Type representation of boolean values.
 **/
const FORMAT_TYPE TypeBool = TypeString << 1;

/**
 * Type representation of calls - only used for Effect, I think.
 **/
const FORMAT_TYPE TypeCall = TypeBool << 1;

/**
 * Meta type denoting any of our primitives.
 **/
const FORMAT_TYPE MetatypePrimitive = TypeNumber |
		TypeString |
		TypeBool |
		TypeCall;

/**
 * Type representation for a group of targets
 * \todo Verify claim.
 **/
const FORMAT_TYPE TypeTargetGroup = TypeCall << 1;

/**
 * Type representation of an Ability reference.
 **/
const FORMAT_TYPE TypeReferenceAbility = TypeTargetGroup << 1;

/**
 * Type representation of a Character reference.
 **/
const FORMAT_TYPE TypeReferenceCharacter = TypeReferenceAbility << 1;

/**
 * Type representation of a Behaviour reference.
 **/
const FORMAT_TYPE TypeReferenceBehaviour = TypeReferenceCharacter << 1;

/**
 * Type representation of an Event reference.
 **/
const FORMAT_TYPE TypeReferenceEvent = TypeReferenceBehaviour << 1;

/**
 * Type representation of an Attribute reference.
 **/
const FORMAT_TYPE TypeReferenceAttribute = TypeReferenceEvent << 1;

/**
 * Type representation of a Resource reference.
 **/
const FORMAT_TYPE TypeReferenceResource = TypeReferenceAttribute << 1;

/**
 * Type representation of an Effect reference.
 **/
const FORMAT_TYPE TypeReferenceEffect = TypeReferenceResource << 1;

/**
 * Metatype denoting any (... all) of our reference types.
 **/
const FORMAT_TYPE MetatypeReference = TypeReferenceAbility |
		TypeReferenceCharacter |
		TypeReferenceBehaviour |
		TypeReferenceEvent |
		TypeReferenceAttribute |
		TypeReferenceResource |
		TypeReferenceEffect;

const FORMAT_TYPE TypePair = TypeReferenceEffect << 1;

/**
 * Type representing a list. (the syntax, as I recall is "[something,seomthing]"
 **/
const FORMAT_TYPE TypeList = TypePair << 1;

/**
 * Meta type for any collection.
 **/
const FORMAT_TYPE MetatypeCollection = TypePair |
		TypeList;

} /* namespace typecheck */
