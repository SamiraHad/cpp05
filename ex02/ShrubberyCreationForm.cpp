/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:40:48 by hsamira           #+#    #+#             */
/*   Updated: 2026/02/24 12:40:49 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ShrubberyCreationForm	crée un fichier avec des arbres

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"



ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") 
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;  
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;   
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = other;   
} 

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other) 
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if(this != &other)
        _target = other._target;  
    return(*this);
} 
  
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;   
} 
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(!getSigned())
        throw AForm:: FormNotSignedException();
    if(executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();
    std::ofstream file((_target+ "_shrubbery").c_str());
    file << "    /\\\n";
    file << "   /**\\\n";
    file << "  /****\\\n";
    file << " /******\\\n";
    file << "    ||\n";
} 
