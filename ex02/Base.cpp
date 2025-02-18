/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:11:20 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/02/18 13:04:46 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    std::srand(std::time(0));
    int randNum = std::rand() % 3;
    if (randNum == 0)
        return new A;
    else if (randNum == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
	catch (...) {}
    
    try
	{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
	catch (...) {}
    
    try
	{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
	catch (...) {}
}
