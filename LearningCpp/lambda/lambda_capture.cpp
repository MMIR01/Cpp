/***********************************
 * MMIR01. Using capture clause
 * with lambda
************************************/

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Car
{
	std::string_view make {};
	std::string_view model {};
	
};


int main()
{
	//Array with 5 cars
	const std::array <Car, 5> cars{
		{{"VW", "Golf"},
		{"Ford", "Fiesta"},
		{"Tesla", "Model 3"},
		{"Toyota", "Yaris"},
		{"Mercedes", "Class A"}}
	};

	//Search car model in the "database"
	std::string user_search{};
	std::cout << "Introduce car model to search: ";
	std::cin >> user_search;

	// The capture clause is used to give a lambda access to variables available in the surrounding scope
	auto user_car = std::find_if(cars.begin(), cars.end(), 
		[user_search](const auto& a) {
			return (a.model.find(user_search) != std::string_view::npos);
	});
	//Note: find return npos if the substring is not found

	std::cout << "Car found: " << user_car->model << "\n";
	std::cout << "Car make: " << user_car->make << "\n";


	return 0;
}