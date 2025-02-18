#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << _name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : _name(rhs._name), _grade(rhs._grade)
{
    std::cout << _name << " copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs)
{
    std::cout << _name << " copy assignment operator called" << std::endl;
    if (this != &rhs)
        _grade = rhs._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << _name << " destructor called" << std::endl;
}



// Getters
std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}



// Methods
void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::upGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::downGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " could not execute " << form.getName() << " because " << e.what() << std::endl;
    }
}


// GradeTooHighException, GradeTooLowException
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("grade is too low!");
}


// 출력 연산자 오버로딩
std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
    out << rhs.getName() << ", " << rhs.getGrade() << std::endl;
    return (out);
}