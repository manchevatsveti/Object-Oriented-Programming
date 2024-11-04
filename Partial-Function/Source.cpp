#include "PartialFunctionFactory.h"

#include <iostream>
#include <fstream>

int main() {
	PartialFunction* func = PartialFunctionFactory::readFromFile("func.dat");

	std::cout << "Choose a regime to work in:" << std::endl;
	std::cout << "Option 1: Type two numbers and all the defined point in this interval will be displayed." << std::endl;
	std::cout << "Option 2: All points will be generated one by one if wanted." << std:: endl;

	while (true) {
		int input;
		std::cin >> input;

		if (input == 1) {
			int beg;
			int end;

			std::cin >> beg >> end;

			for (int i = beg; i <= end; i++) {
				if (func->isDefined(i)) {
					std::cout << i << " -> " << func->operator()(i) << std::endl;
				}
			}
			break;
		}
		else if (input == 2) {
			
			char response = 'Y';
			for (int i = INT32_MIN; i < INT32_MAX; i++) {//too many numbers - try it with more realistic ones
				if (response == 'Y' || response == 'y') {
					if (func->isDefined(i)) {
						std::cout << i << " -> " << func->operator()(i) << std::endl;
						std::cout << "Do you want to continue? : Y/N" << std::endl;
						std::cin >> response;
					}
				}
				else {
					break;
				}
			}
			break;
		}
		else {
			std::cout << "Invalid input. Please choose one of the options 1 or 2." << std::endl;
		}

	}
}
