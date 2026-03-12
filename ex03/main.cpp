/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:34:42 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/12 13:35:07 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try  //ShrubberyCreationForm : 145 gradeSign et 137 gradeExcec
    {
        Bureaucrat a("A", 40);
        ShrubberyCreationForm garden("garden");
        a.signForm(garden);
        a.executeForm(garden);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try  //RobotomyRequestForm : 72 gradeSign et 45 execGrade 
    {
        Bureaucrat b("B", 1);
        RobotomyRequestForm robot("robot");
        b.signForm(robot);
        b.executeForm(robot);
    }

    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try  //PresidentialPardonForm : signGrade 25 et 5 gradeExcec
    {
        Bureaucrat c("B", 20);
        PresidentialPardonForm pardon("Olivier");
        c.signForm(pardon);
        c.executeForm(pardon);
    }

    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

