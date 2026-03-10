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


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("bureaucrat", 10);
        std::cout << bureaucrat << std::endl;

        Form form("form", 40, 20);
        std::cout << form << std::endl;
        
        bureaucrat.signForm(form);

    }

    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
return 0;
}
