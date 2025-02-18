#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        // Attributes
        std::string _target;

        PresidentialPardonForm();

    public:
        // Constructors
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& rhs);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        ~PresidentialPardonForm();

        // Getters
        std::string getTarget() const;

        // Methods
        void execute(const Bureaucrat& executor) const;
};

#endif