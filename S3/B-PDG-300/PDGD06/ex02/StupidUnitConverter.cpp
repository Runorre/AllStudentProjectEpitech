/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** StupidUnitConverter
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <sstream>

int main(void)
{
    std::string line;
    while (std::getline(std::cin, line)) {
        std::string temp;
        std::string format;
        std::stringstream ss(line);
        double tempValue = 0.0;

        ss >> temp;
        ss >> format;
        if (temp.empty() || format.empty())
            continue;
        try {
            tempValue = std::stod(temp);
        } catch (const std::invalid_argument&) {
            continue;
        }
        if (format == "Fahrenheit") {
            double result = 5.0 / 9.0 * (tempValue - 32.0 );
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << result << std::setw(16) <<"Celsius" << std::endl;
        }
        else if (format == "Celsius") {
            double result = tempValue * 9.0 / 5.0 + 32.0;
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << result << std::setw(16) << "Fahrenheit" << std::endl;
        }
    }
}
