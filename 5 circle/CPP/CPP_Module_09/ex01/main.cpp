#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "error: wrong argc!\n";
		return (1);
	}

	try {
		RPN rpnCalculator;

		std::string input(argv[1]);
		rpnCalculator.execute(input);

		int result = rpnCalculator.getResult();
		std::cout << "RESULT: " << result << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}