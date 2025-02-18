#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
        // 이름, 등급
        const std::string _name;
        int _grade;
        

        Bureaucrat();

    public:
        // OCCF
        Bureaucrat(const std::string& name, int grade); // 이름, 등급
        Bureaucrat(Bureaucrat const &rhs);              // 복사
        Bureaucrat &operator=(Bureaucrat const &rhs);   // 대입
        ~Bureaucrat();                                  // 소멸


        // Getter
        std::string getName() const;
        int getGrade() const;


        // UpGrade, DownGrade
        void upGrade();
        void downGrade();


        // GradeTooHighException, GradeTooLowException
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif
