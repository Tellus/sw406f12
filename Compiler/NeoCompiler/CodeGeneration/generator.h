/// generator.h
///
/// This file contains ...

#pragma once

#include <map>
#include <list>
#include <string>
#include <fstream>

namespace codegen
{

typedef void(*Template)(std::fstream);

class Generator
{
public:
	Generator();
	virtual ~Generator();

	void character_template(std::fstream &stream);
	void character_post(std::fstream &stream, std::list<std::string> &assignments);
	void ability_post(std::fstream &stream, std::list<std::string> &assignments);

private:

	bool list_contains(std::list<std::string> &list, std::string item);
};

Generator &Gen();

} /* namespace codegen */
