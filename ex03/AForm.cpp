/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:40:54 by hsamira           #+#    #+#             */
/*   Updated: 2026/02/24 12:40:55 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm():_name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    std::cout << "AForm constructor called" << std::endl;
    if(gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if(gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}


AForm::AForm( const AForm& other): _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    std::cout << "AForm copy constructor called" << std::endl;

}
AForm& AForm::operator=( const AForm& other)
{
    std::cout << "AForm assignment operator called" << std::endl;
    if(this != &other)
        _signed = other._signed;
    return(*this);
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return(_name);   
}

bool AForm::getSigned() const
{
    return(_signed);   
}

int AForm::getGradeSign() const
{
    return(_gradeSign);   
}

int AForm::getGradeExec() const
{
    return(_gradeExec);   
}

//le bureaucrat est-il trop faible pour signer ?
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
  if(bureaucrat.getGrade() > _gradeSign) //si bureaucrat trop faible
        throw GradeTooLowException(); //erreur
    else
        _signed = true; //le Aformulaire est signé
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("Grade too low");
}

const char*  AForm:: FormNotSignedException::what() const throw()
{
    return("Form is not signed");
}

std::ostream&   operator<<(std::ostream &o, AForm const &other)
{
    o << "AForm " << other.getName() << ", signed: " << other.getSigned() << ", grade to sign: " << other.getGradeSign() << ", grade to execute: " << other.getGradeExec();
    return o;
}