/// emissiondata.h
///
/// This file contains ...

#pragma once

#include <fstream>

namespace codegen
{

#define FORMAT_EMISSIONDATA unsigned int

/**
 * Far as I can tell, denotes the type of data currently being emitted. It is
 * used by AbstractNode subclasses to properly branch their emissions.
 **/
struct EmissionData
{
	std::fstream stream;
	FORMAT_EMISSIONDATA data;
};

const std::string EmitHeaderDirectory = "Headers/";

const FORMAT_EMISSIONDATA EmitNone = 0;

const FORMAT_EMISSIONDATA EmitCharacter = 1u;
const FORMAT_EMISSIONDATA EmitAbility = EmitCharacter << 1;
const FORMAT_EMISSIONDATA EmitBehaviour = EmitAbility << 1;
const FORMAT_EMISSIONDATA EmitEvent = EmitBehaviour << 1;

const FORMAT_EMISSIONDATA EmitClass = EmitCharacter | EmitAbility | EmitBehaviour | EmitEvent;

const FORMAT_EMISSIONDATA EmitAbilityList = EmitEvent << 1;
const FORMAT_EMISSIONDATA EmitEventList = EmitAbilityList << 1;
const FORMAT_EMISSIONDATA EmitTargetsList = EmitEventList << 1;
const FORMAT_EMISSIONDATA EmitEffectList = EmitTargetsList << 1;
const FORMAT_EMISSIONDATA EmitNegativeList = EmitEffectList << 1;

const FORMAT_EMISSIONDATA EmitEventCondition = EmitNegativeList << 1;

} /*namespace codegen*/
