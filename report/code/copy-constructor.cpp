#include <iostream>
#include <list>

class SomeClass
{
public:
	int number;
	SomeClass() {} // Stub constructor. 
	SomeClass(int newnum) { this->number = newnum; }
	SomeClass(const SomeClass& copy) { this->number = copy.number; }

	virtual int get_number()
	{
		return this->number;
	}
};

class DerivClass1 : public SomeClass
{
public:
	int double_number;
	DerivClass1(const SomeClass& copy) : SomeClass(copy.number)
	{
		this->double_number = this->number * 2;
	}

	int get_number()
	{
		return this->double_number;
	}
};

class DerivClass2 : public SomeClass
{
public:
	int triple_number;
	DerivClass2 (const SomeClass& copy) : SomeClass(copy.number)
	{
		this->triple_number = this->number * 3;
	}

	int get_number()
	{
		return this->triple_number;
	}
};

int main (int argc, char** argv)
{
// This example works, but is static.
	SomeClass* a = new SomeClass(1); // a.number == 1;
	std::cout << "a: " << a->get_number() << '\n';

	DerivClass1* b = new DerivClass1(*a);
	std::cout << "b: " << b->get_number() << '\n';

	DerivClass2* c = new DerivClass2(*a);
	std::cout << "c: " << c->get_number() << '\n';

	c = new DerivClass2(*dynamic_cast<SomeClass*>(b));
	std::cout << "c: " << c->get_number() << '\n';

// This example will run, but lacks data.
    std::list<SomeClass*> l;
    
    l.push_back(new DerivClass1(*a));
    l.push_back(new DerivClass2(*a));
    
    // Retrieve, copy, and print. This is where the copy-constructor fail appears.
    for (std::list<SomeClass*>::iterator iter = l.begin();
            iter != l.end();
            iter++)
    {
        SomeClass* tmp = new SomeClass(**iter);
        std::cout << "List: " << tmp->get_number() << '\n';
    }
    
	return 0;
}
