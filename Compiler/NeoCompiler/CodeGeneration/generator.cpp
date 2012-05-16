/// generator.cpp
///
/// This file contains ...

#include "generator.h"

namespace codegen
{

Generator::Generator()
{ }

Generator::~Generator()
{ }

void Generator::character_template(std::fstream &stream)
{
	stream << "\t// Add attributes...\n";
}

void Generator::character_post(std::fstream &stream, std::list<std::string> &assignments)
{
	std::string req_attr[] = {"strength", "agility", "intelligence", "stamina"};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (!this->list_contains(assignments, req_attr[i]))
		{
			stream << "\t\tthis->add_attribute(\"" << req_attr[i] << "\", 0);\n";
		}
	}

	if (!this->list_contains(assignments, "defense"))
	{
		stream << "\t\tthis->add_attribute(\"defense\", (" <<
				"\n\t\t\t\tthis->get_attribute(\"stamina\")->get_current() + " <<
				"\n\t\t\t\tthis->get_attribute(\"agility\")->get_current()) / 3" <<
				");\n";
	}

	if (!this->list_contains(assignments, "magic_defense"))
	{
		stream << "\t\tthis->add_attribute(\"magic_defense\", (" <<
				"\n\t\t\t\tthis->get_attribute(\"stamina\")->get_current() + " <<
				"\n\t\t\t\tthis->get_attribute(\"intelligence\")->get_current()) / 3" <<
				");\n";
	}

	if (!this->list_contains(assignments, "attack_power"))
	{
		stream << "\t\tthis->add_attribute(\"attack_power\", (" <<
				"\n\t\t\t\tthis->get_attribute(\"strength\")->get_current() " <<
				"/ 2) + 1);\n";
	}

	if (!this->list_contains(assignments, "magic_power"))
	{
		stream << "\t\tthis->add_attribute(\"magic_power\", (" <<
				"\n\t\t\t\tthis->get_attribute(\"intelligence\")->get_current() " <<
				"/ 2) + 1);\n";
	}

	if (!this->list_contains(assignments, "health"))
	{
		stream << "\t\tthis->add_resource(\"health\", 0, " <<
				"\n\t\t\t\tthis->get_attribute(\"stamina\")->get_current() * 20);\n";
	}

	if (!this->list_contains(assignments, "mana"))
	{
		stream << "\t\tthis->add_resource(\"mana\", 0, " <<
				"\n\t\t\t\tthis->get_attribute(\"intelligence\")->get_current() * 15);\n";
	}

	if (!this->list_contains(assignments, "behaviour"))
	{
		stream << "\t\tthis->behaviour = new FullBehaviour();\n";
	}

	if (!this->list_contains(assignments, "name"))
	{
		stream << "\t\tthis->name = \"No Name\";\n";
	}

	// TODO: Dummy ability:
}

void Generator::ability_post(std::fstream &stream, std::list<std::string> &assignments)
{
	if (!this->list_contains(assignments, "targets"))
	{
		stream << "\t\tthis->add_rgr(ENEMY);\n";
	}

	if (!this->list_contains(assignments, "effects"))
	{
		stream << "\t\tthis->add_effect(new PhysicalDamage(OWNER, TARGET, 0));\n";
	}

	if (!this->list_contains(assignments, "name"))
	{
		stream << "\t\tthis->name = \"No Name\";\n";
	}
}

bool Generator::list_contains(std::list<std::string> &list, std::string item)
{
	std::list<std::string>::iterator it;

	for (it = list.begin(); it != list.end(); it++)
	{
		if ((*it) == item)
			return true;
	}

	return false;
}

Generator &Gen()
{
	static Generator g;
	return g;
}

} /* namespace codegen */
