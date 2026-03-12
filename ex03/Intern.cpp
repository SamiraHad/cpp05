/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:08:04 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/12 15:43:34 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() 
{
    std::cout << "Intern default constructor called" << std::endl;
}


Intern::Intern( const Intern& other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}
Intern& Intern::operator=( const Intern& other)
{
    std::cout << "Intern assignment operator called" << std::endl; 
    (void)other;
    return(*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target)
{ 
    try
    {
       name == "ShrubberyCreationForm" || name == "RobotomyRequestForm" || name == "PresidentialPardonForm"
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}



const char* Intern::FormNotExistException::what() const throw()
{
    return("Intern cannot create");
}
