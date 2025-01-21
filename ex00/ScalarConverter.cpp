/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:08:34 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/01/21 12:24:11 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input)
{
    char c;
    int i;
    float f;
    double d;

    bool charValid = false;
    bool intValid = false;
    bool floatValid = false;
    bool doubleValid = false;

    if (isSpecialLiteral(input))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (input.find('f') != std::string::npos)
        {
            std::cout << "float: " << input << std::endl;
        }
        else
        {
            std::cout << "float: " << input << "f" << std::endl;
        }
        std::cout << "double: " << input << std::endl;
        return;
    }
    else if (isInteger(input))
    {
        i = std::strtol(input.c_str(), NULL, 10);
        intValid = true;
        c = static_cast<char>(i);
        charValid = (i >= 0 && i <= 127 && std::isprint(c));
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        floatValid = true;
        doubleValid = true;
    }
    else if (isFloat(input))
    {
        f = std::strtof(input.c_str(), NULL);
        floatValid = true;
        d = static_cast<double>(f);
        doubleValid = true;
        if (f >= 0 && f <= 127 && std::isprint(static_cast<int>(f)))
        {
            c = static_cast<char>(f);
            charValid = true;
        }
        i = static_cast<int>(f);
        intValid = !(f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min());
    }
    else if (isDouble(input))
    {
        d = std::strtod(input.c_str(), NULL);
        doubleValid = true;
        f = static_cast<float>(d);
        floatValid = !(d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max());
        if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
        {
            c = static_cast<char>(d);
            charValid = true;
        }
        i = static_cast<int>(d);
        intValid = !(d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min());
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // Output results
    if (charValid)
        std::cout << "char: '" << c << "'" << std::endl;
    else if (intValid && i >= 0 && i <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    if (intValid)
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    if (floatValid)
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;

    if (doubleValid)
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

bool ScalarConverter::isSpecialLiteral(const std::string &input)
{
    return input == "nan" || input == "nanf" ||
           input == "+inf" || input == "-inf" ||
           input == "+inff" || input == "-inff";
}

bool ScalarConverter::isInteger(const std::string &input)
{
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (i == 0 && (input[i] == '+' || input[i] == '-'))
            continue;
        if (!std::isdigit(input[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &input)
{
    if (input.find('f') == std::string::npos || input.find('.') == std::string::npos)
        return false;

    std::string numberPart = input.substr(0, input.length() - 1);
    return isDouble(numberPart);
}

bool ScalarConverter::isDouble(const std::string &input)
{
    bool dotFound = false;
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (i == 0 && (input[i] == '+' || input[i] == '-'))
            continue;
        if (input[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!std::isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}
