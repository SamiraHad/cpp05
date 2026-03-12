/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:34:42 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/12 10:18:27 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//grade = 150 le plus bas
//  incrementer <==  1  >  2  >  3  >  ...  > 150  ==> decrementer

#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat sam("sam", 3);
        std::cout << sam << std::endl;

        sam.incrementGrade();
        std::cout << sam << std::endl;

        sam.decrementGrade();
        std::cout << sam << std::endl;
    }

    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat sam("sam", 1);
        std::cout << sam << std::endl;

        sam.incrementGrade();
        std::cout << sam << std::endl;

        sam.decrementGrade();
        std::cout << sam << std::endl;
    }

    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat sam("sam", 151);
        std::cout << sam << std::endl;

        sam.incrementGrade();
        std::cout << sam << std::endl;

        sam.decrementGrade();
        std::cout << sam << std::endl;
    }

    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }   
    

return 0;
}
