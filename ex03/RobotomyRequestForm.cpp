/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:41:16 by hsamira           #+#    #+#             */
/*   Updated: 2026/02/24 12:41:17 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//RobotomyRequestForm : robotise quelqu’un


#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") 
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;  
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) 
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;   
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;  
} 

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other) 
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if(this != &other)
        _target = other._target;  
    return(*this);
} 
  
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;   
} 

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(!getSigned())
        throw AForm:: FormNotSignedException();
    if(executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();
    std::cout << "* bzzzzz.....Drilling noises... *" << std::endl;
    if(rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
} 

