/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:34:35 by hsamira           #+#    #+#             */
/*   Updated: 2026/02/24 12:34:36 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("B"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
}


Bureaucrat::Bureaucrat( const Bureaucrat& other): _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}
Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl; 
    if( this != &other)
        _grade = other._grade;
    return(*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return(_name);   
}

int Bureaucrat::getGrade() const
{
    return(_grade);   
}

//incrementGrade() : Augmente le rang, donc diminue le nombre. 
//incrementer <==  1  >  2  >  3  >  ...  > 150  ==> decrementer
void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
         throw GradeTooHighException();
    else
        _grade--;
}

//decrementGrade(): Diminue le rang, donc augmente le nombre.
//incrementer <==  1  >  2  >  3  >  ...  > 150  ==> decrementer
void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade too low");
}

std::ostream&   operator<<(std::ostream &o, Bureaucrat const &other)
{
    o << other.getName() << " , bureaucrat grade " << other.getGrade();
    return o;
}