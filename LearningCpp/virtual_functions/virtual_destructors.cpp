/***********************************
 * MMIR01. Virtual destructors example
************************************/

#include <iostream>

class Base
{
public:
	virtual std::string_view getName() const { return "Base"; };

	virtual ~Base() = default;
};

class Derived: public Base 
{
private:
	int* m_value;

public:
	//Derived constructor calls Base constructor
	Derived (int value1)
	: m_value{new int{value1}}
	{};

	//Custom destructor for Derived class
	virtual ~Derived()
	{
		std::cout << "Calling Derived destructor\n";
		delete m_value;
		m_value = nullptr;
	}
};


int main()
{
	Derived* pDerived{ new Derived(7)};
	
	//Using base pointer
	Base* pBase{ pDerived };

	delete pBase;
	pBase = nullptr;
	
	//Segmentation fault, since the object has been deleted
	//std::cout << pDerived->getName() <<"\n";


	return 0;
}