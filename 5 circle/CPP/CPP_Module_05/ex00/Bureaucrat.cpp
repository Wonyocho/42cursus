#include "Bureaucrat.hpp"

// OCCF
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    // 등급이 1보다 작으면 GradeTooHighException 예외를 던진다.
    if (grade < 1)
        throw GradeTooHighException();
    // 등급이 150보다 크면 GradeTooLowException 예외를 던진다.
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



// Getter
std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}


// UpGrade, DownGrade
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