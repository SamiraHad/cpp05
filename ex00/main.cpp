/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:34:42 by hsamira           #+#    #+#             */
/*   Updated: 2026/02/24 12:34:43 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//grade = 150 le plus bas
//  incrementer <==  1  >  2  >  3  >  ...  > 150  ==> decrementer

#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat sam("sam", 10);
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
