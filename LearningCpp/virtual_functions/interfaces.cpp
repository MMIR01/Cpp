/***********************************
 * MMIR01. An example where virtual is very important
 * In this case we have an interface with 2 implementations and we are
 * using a pointer to an interface. Because we are using virtual, we can
 * execute the methods from the derived classes. The method executed
 * depends on the object the interface pointer is pointing out
 * More info:
 * https://stackoverflow.com/questions/43082109/pointers-to-interfaces-c
************************************/

#include <iostream>
#include <string_view>
#include <memory>

class Base_I
{
public:
	virtual void print(std::string_view errorMessage) = 0;

	virtual ~Base_I(){};
};

//Class that implements the interface
class Derived: public Base_I
{
private:
	int m_derived_value;

public:
	Derived() : m_derived_value{1}
	{	
	};

	virtual ~Derived(){};

	void print(std::string_view errorMessage) override
	{
		std::cout << "Message from " << m_derived_value << " : " << errorMessage <<"\n";
	}
};

//Another class that implements the interface
class Derived2: public Base_I
{
private:
	int m_derived2_value;

public:
	Derived2() : m_derived2_value{2}
	{	
	};

	virtual ~Derived2(){};

	void print(std::string_view errorMessage) override
	{
		std::cout << "Message from " << m_derived2_value << " : " << errorMessage <<"\n";
	}
};


int main()
{
	//We can use the same pointer to the interface to use two different implementation types
	std::string myMessage {"Printed by the derived object"};

  	std::shared_ptr<Base_I> object = std::make_shared<Derived>();
	object->print(myMessage);

	object = std::make_shared<Derived2>();
	object->print(myMessage);

	return 0;
}