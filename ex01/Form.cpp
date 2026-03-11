
#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form():_name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    std::cout << "Form constructor called" << std::endl;
    if(gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if(gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}


Form::Form( const Form& other): _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    std::cout << "Form copy constructor called" << std::endl;

}
Form& Form::operator=( const Form& other)
{
    std::cout << "Form assignment operator called" << std::endl;
    if(this != &other)
        _signed = other._signed;
    return(*this);
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
    return(_name);   
}

bool Form::getSigned() const
{
    return(_signed);   
}

int Form::getGradeSign() const
{
    return(_gradeSign);   
}

int Form::getGradeExec() const
{
    return(_gradeExec);   
}

//le bureaucrat est-il trop faible pour signer ?
void Form::beSigned(const Bureaucrat& bureaucrat)
{
  if(bureaucrat.getGrade() > _gradeSign) //si bureaucrat trop faible
        throw GradeTooLowException(); //erreur
    else
        _signed = true; //le formulaire est signé
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Grade too low");
}

std::ostream&   operator<<(std::ostream &o, Form const &other)
{
    o << "Form " << other.getName() << ", signed: " << other.getSigned() << ", grade to sign: " << other.getGradeSign() << ", grade to execute: " << other.getGradeExec();
    return o;
}