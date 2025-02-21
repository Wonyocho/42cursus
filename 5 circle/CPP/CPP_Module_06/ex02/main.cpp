#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		Base* ptr = generate();
		identify(ptr);
		identify(*ptr);

		delete ptr;
		std::cout << "-\n";
	}
	return (0);
}
