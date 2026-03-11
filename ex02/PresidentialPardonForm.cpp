/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:41:07 by hsamira           #+#    #+#             */
/*   Updated: 2026/02/24 12:41:08 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PresidentialPardonForm : pardonne quelqu’un


#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") 
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;  
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) 
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;   
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
} 

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other) 
{
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if(this != &other)
        _target = other._target;  
    return(*this);
} 
  
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;   
} 
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(!getSigned())
        throw AForm:: FormNotSignedException();
    if(executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
} 

