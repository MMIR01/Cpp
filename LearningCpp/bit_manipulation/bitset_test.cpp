/***********************************
 * MMIR01. Bit manipulation using
 * bitset library
************************************/

#include <bitset>
#include <iostream>

int main()
{
	// Flag initialized with all 0s
	std::bitset<8> flag{ 0b0000'0000 };

	// Activating bit 1 and 5
	flag.set(1);
	flag.set(5);

	// Checking bit 1 is active
	std::cout << "Is bit 1 active?: " << flag.test(1) << '\n';
	std::cout << "Is bit 3 active?: " << flag.test(3) << '\n';
	std::cout << "Is bit 5 active?: " << flag.test(5) << '\n';

	// Restart value of bit 1
	flag.reset(1);
	std::cout << "Restart. Is bit 1 active?: " << flag.test(1) << '\n';

	// Flipping value of bit 5
	flag.flip(5);
	std::cout << "Flip. Is bit 5 active?: " << flag.test(5) << '\n';

	// Flip bit again
	flag.flip(5);
	std::cout << "Flip. Is bit 5 active?: " << flag.test(5) << '\n';

	return 0;
}