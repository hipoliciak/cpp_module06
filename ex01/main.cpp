/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:44:24 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/02/18 13:00:39 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data original;
    original.number = 42;
    original.text = "Hello, World!";

    uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized: " << raw << std::endl;
    
    Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized: " << deserialized << std::endl;

    if (deserialized == &original)
	{
        std::cout << "Serialization and deserialization are successful!" << std::endl;
        std::cout << "Number: " << deserialized->number << std::endl;
        std::cout << "Text: " << deserialized->text << std::endl;
    }
	else
	{
        std::cout << "Error in serialization or deserialization!" << std::endl;
    }
    
    return 0;
}
