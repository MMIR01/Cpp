/***********************************
 * MMIR01. An example where lambda
 * is used
************************************/

#include <algorithm>
#include <array>
#include <iostream>

struct Car
{
	std::string model {};
	double price{};
	
};


int main()
{
	//Array with 5 cars
	const std::array <Car, 5> cars{
		{{"VW Golf", 32500.0},
		{"Ford Fiesta", 22500.0},
		{"Tesla Model 3", 68200.0},
		{"Toyota Yaris", 25300.0},
		{"Mercedes Class A", 37100.0}}
	};

	//Look for the most expensive car
	//We define a lambda function 
	const auto most_expensive = std::max_element(cars.begin(), cars.end(), 
		[](const auto& a, const auto &b) {
			return (a.price < b.price);
	});
	
	std::cout << "Most expensive car is: " << most_expensive->model << "\n";
	std::cout << "Price: " << most_expensive->price << "\n";

	return 0;
}