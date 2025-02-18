#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        Bureaucrat b("Bob", 149);
        Form formA("FormA", 1, 1);
        Form formB("FormB", 150, 150);

        std::cout <<  "==============================" << std::endl;
        std::cout << a;
        std::cout << b;
        std::cout << formA;
        std::cout << formB;



        std::cout <<  "==============================" << std::endl;
        a.upGrade();
        b.downGrade();

        std::cout << a;
        std::cout << b;



        std::cout <<  "==============================" << std::endl;
        formA.beSigned(a);
        formB.beSigned(b);

        std::cout << formA;
        std::cout << formB;
    }
    catch(const std::exception& except)
    {
        std::cerr << except.what() << std::endl;
    }

    return 0;
}