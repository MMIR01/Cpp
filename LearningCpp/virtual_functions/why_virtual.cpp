/***********************************
 * MMIR01. In this example we are
 * going to demonstrate why virtual
 * functions are needed
************************************/

#include <iostream>

class Base
{
	private:
		int m_value;

	public:
		Base(int value)
		: m_value{value}
		{};

		std::string_view getName() const { return "Base"; }
};

//public is the type of inheritance used
class Derived : public Base 
{
	private:
		int m_derived_value;

	public:
		//Derived constructor calls Base constructor
		Derived (int value1, int value2)
		: Base{value1}, m_derived_value{value2}
		{};

		std::string_view getName() const { return "Derived"; }
};

int main()
{
	Derived derived1{6,7};
	//This is ok
	std::cout << "My name is: " << derived1.getName() << "\n";
	//Same if we use reference and pointer
	Derived& rDerived1{derived1};
	std::cout << "My name is: " << rDerived1.getName() << " (from reference)\n";
	Derived * pDerived1{&derived1};
	std::cout << "My name is: " << pDerived1->getName() << " (from pointer)\n";

	//We can use a Base reference and pointer
	Base& rBase1{derived1};
	std::cout << "My name is: " << rBase1.getName() << " (from reference)\n";
	Base * pBase1{&derived1};
	std::cout << "My name is: " << pBase1->getName() << " (from pointer)\n";
	
	/*We can only see members and functions from Base. We are unable to see 
	anything from Derived. To change this, we use "virtual functions". See
	virtual_example.cpp to know more */

	return 0;
}