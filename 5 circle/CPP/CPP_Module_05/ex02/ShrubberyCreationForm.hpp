#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        // Attributes
        std::string _target;

        ShrubberyCreationForm();

    public:
        // Constructors
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        ~ShrubberyCreationForm();

        // Getters
        std::string getTarget() const;

        // Methods
        void execute(const Bureaucrat& executor) const;

        // Exceptions
        class FileException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif