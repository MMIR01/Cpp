/***********************************
 * MMIR01. Virtual functions example
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

	std::string_view getName() const { return "Base"; };
	virtual std::string_view getName2() const { return "New Base"; };

	virtual ~Base() = default;
};

//public is the type of inheritance used
class Derived: public Base 
{
private:
	int m_derived_value;

public:
	//Derived constructor calls Base constructor
	Derived (int value1, int value2)
	: Base{value1}, m_derived_value{value2}
	{};

	//Making this virtual, only affects to class derived from this one
	virtual std::string_view getName() const { return "Derived"; };

	//It is not necessary to type "virtual" here
	virtual std::string_view getName2() const { return "New Derived"; };
};

class Derived2: public Derived 
{
public:
	//Derived2 constructor calls Derived constructor
	Derived2 (int value1, int value2)
	: Derived{value1, value2}
	{};

	virtual std::string_view getName() const { return "Derived2"; };

	/*"override" allows the compiler to warn us. When use it, it is not
	necessary to use "virtual"*/
	std::string_view getName2() const override { return "New Derived2"; };
};


int main()
{
	//It uses constructor of its base class
	Derived2 derived2{6,7};
	
	//Using base reference
	Base& rBase{derived2};
	//It will print "Base", as it is not virtual
	std::cout << rBase.getName() <<"\n";
	//It will print "New Derived2". Why? It
	//calls the most derived matching function between Base and Derived2
	std::cout << rBase.getName2() <<"\n";


	//Using derived reference
	Derived& rDerived{derived2};
	//It will print "Derived2", as we made it virtual, so it will calls 
	//the most derived matching function between Derived and Derived2
	std::cout << rDerived.getName() <<"\n";
	//It will print "New Derived2"
	std::cout << rDerived.getName2() <<"\n";

	return 0;
}