#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp" // Include the Intern header

int main()
{
    try
    {
        Bureaucrat alice("Alice", 2);
        Bureaucrat bob("Bob", 149);
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << "=============================================================" << std::endl;
        std::cout << alice;
        std::cout << bob;
        std::cout << shrubbery;
        std::cout << robotomy;
        std::cout << pardon;
        
        std::cout << "=============================================================" << std::endl;
        alice.upGrade();
        bob.downGrade();

        std::cout << alice;
        std::cout << bob;

        std::cout << "=============================================================" << std::endl;
        shrubbery.beSigned(alice);
        robotomy.beSigned(alice);
        pardon.beSigned(alice);

        std::cout << shrubbery;
        std::cout << robotomy;
        std::cout << pardon;

        std::cout << "=============================================================" << std::endl;
        alice.executeForm(shrubbery);
        alice.executeForm(robotomy);
        alice.executeForm(pardon);
        std::cout << "=============================================================" << std::endl;

        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            alice.executeForm(*rrf);
            delete rrf;
        }
        std::cout << "=============================================================" << std::endl;
    }
    catch(const std::exception& except)
    {
        std::cerr << except.what() << std::endl;
    }

    return 0;
}