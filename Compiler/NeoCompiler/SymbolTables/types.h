/// types.h
///
/// This file contains type and metatype definitions.

#pragma once

#define FORMAT_TYPE unsigned int

namespace typecheck
{

const FORMAT_TYPE MetatypeNone = 0;

const FORMAT_TYPE TypeNumber = 1u;
const FORMAT_TYPE TypeString = TypeNumber << 1;
const FORMAT_TYPE TypeBool = TypeString << 1;
const FORMAT_TYPE TypeCall = TypeBool << 1;

const FORMAT_TYPE MetatypePrimitive = TypeNumber |
		TypeString |
		TypeBool |
		TypeCall;

const FORMAT_TYPE TypeTargetGroup = TypeCall << 1;

const FORMAT_TYPE TypeReferenceAbility = TypeTargetGroup << 1;
const FORMAT_TYPE TypeReferenceCharacter = TypeReferenceAbility << 1;
const FORMAT_TYPE TypeReferenceBehaviour = TypeReferenceCharacter << 1;
const FORMAT_TYPE TypeReferenceEvent = TypeReferenceBehaviour << 1;
const FORMAT_TYPE TypeReferenceAttribute = TypeReferenceEvent << 1;
const FORMAT_TYPE TypeReferenceResource = TypeReferenceAttribute << 1;
const FORMAT_TYPE TypeReferenceEffect = TypeReferenceResource << 1;

const FORMAT_TYPE MetatypeReference = TypeReferenceAbility |
		TypeReferenceCharacter |
		TypeReferenceBehaviour |
		TypeReferenceEvent |
		TypeReferenceAttribute |
		TypeReferenceResource |
		TypeReferenceEffect;

const FORMAT_TYPE TypePair = TypeReferenceEffect << 1;
const FORMAT_TYPE TypeList = TypePair << 1;

const FORMAT_TYPE MetatypeCollection = TypePair |
		TypeList;

} /* namespace typecheck */
