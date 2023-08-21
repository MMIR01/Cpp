/***********************************
 * MMIR01. Inheritance example
************************************/

#include <iostream>

class Base
{
	private:
		int m_value;

		void myPrintPrivate()
		{
			std::cout << "Private base function\n";
		}
	
	public:
		Base(int value)
		: m_value{value}
		{};

		void myPrintPublic()
		{
			std::cout << "Public base function\n";
		}

		void myPrintPublic2()
		{
			std::cout << "Public base function 2\n";
		}
		
		void myPrintPublic3()
		{
			std::cout << "Public base function 3\n";
		}
		
	//Protected is not accesible from outside
	//But is accesible by friends and derived
	protected:
		void myPrintProtected()
		{
			std::cout << "Protected base function\n";
		}
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

		//Function redifened as public
		using Base::myPrintProtected;

		void myPrintPublic()
		{
			//Extend functionality from Base function
			Base::myPrintPublic();
			std::cout << "And derived function\n";
		}

		//Function Overriding
		void myPrintPublic3()
		{
			std::cout << "New derived function 3\n";
		}
};

int main()
{
	//Creating object from class Base
	Base base1{5};
	//This will fail as we can't see a private function outside
	//base1.myPrintPrivate();
	//This is OK
	base1.myPrintPublic();
	
	//Creating object from class Derived
	Derived derived1{6,7};
	//This is ok, as we have redifened that base function as public
	derived1.myPrintProtected();
	//Print extended functionality
	derived1.myPrintPublic();
	//We are able to use functions from Base Class
	derived1.myPrintPublic2();

	//This derived function shadows the base one
	base1.myPrintPublic3();
	derived1.myPrintPublic3();
	//However, there is still a way to use the base one from derived object
	derived1.Base::myPrintPublic3();

	return 0;
}