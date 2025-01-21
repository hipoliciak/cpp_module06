/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:08:53 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/01/21 12:26:34 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <limits>

class ScalarConverter
{
    public:
        static void convert(const std::string &input);

    private:
        static bool isSpecialLiteral(const std::string &input);
        static bool isInteger(const std::string &input);
        static bool isFloat(const std::string &input);
        static bool isDouble(const std::string &input);
};
