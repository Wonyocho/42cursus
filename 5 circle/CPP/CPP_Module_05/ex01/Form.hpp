#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
        
        Form();
    
    public:
        // Constructors
        Form(const std::string &name, int signGrade, int execGrade);
        Form(const Form &rhs);
        Form &operator=(const Form &rhs);
        ~Form();

        // Getters
        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        
        // Member functions
        bool isSigned() const;
        void beSigned(Bureaucrat const &person);
        
        // Exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif