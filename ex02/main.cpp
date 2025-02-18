/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:05:03 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/02/18 13:12:56 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main()
{
    std::cout << "Running tests...\n";
    
    for (int i = 0; i < 5; ++i)
	{
        Base* obj = generate();
        std::cout << "Test " << i + 1 << "\n";
        
        std::cout << "Identify by pointer: ";
        identify(obj);
        
        std::cout << "Identify by reference: ";
        identify(*obj);
        
        delete obj;
        std::cout << "------------------\n";
    }
    
    return 0;
}
