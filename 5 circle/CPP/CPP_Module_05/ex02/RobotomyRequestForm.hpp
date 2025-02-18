#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        // Attributes
        std::string _target;

        RobotomyRequestForm();

    public:
        // Constructors
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& rhs);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        ~RobotomyRequestForm();

        // Getters
        std::string getTarget() const;

        // Methods
        void execute(const Bureaucrat& executor) const;

        // Exceptions
        class RobotomyFailureException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif