/* Mélina Deneuve ID#40153103
   Rudy Zoghaib   ID#40025399
Assignment - 5 - COEN 244
Environment : Visual Studio 2019 */

#include <iostream>
#include <fstream>
#include "Array.h"
#include "Array.cpp"

int main()
{
    std::ofstream TemplateTxtFile("Template.txt", std::ios::out); // Creating the Template.txt file

    if (!TemplateTxtFile) // Exit program if it is unable to creat that txt file
    {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    } // End if

    Array<int> intArray{ 5 };
    Array<double> doubleArray{ 5 };
    Array<std::string> stringArray{ 3 };

    std::cout << "Please enter the members of your array of integers." << std::endl;
    for (int i = 0; i < intArray.getSize(); i++)
    {
        std::cin >> intArray[i];
        TemplateTxtFile << intArray[i];
    }

    std::cout << "Please enter the members of your array of doubles." << std::endl;
    for (int i = 0; i < doubleArray.getSize(); i++)
    {
        std::cin >> doubleArray[i];
        TemplateTxtFile << doubleArray[i] << std::endl;
    }

    std::cout << "Please enter the members of your array of strings." << std::endl;
    for (int i = 0; i < stringArray.getSize(); i++)
    {
        std::cin >> stringArray[i];
        TemplateTxtFile << stringArray[i];
    }
    return 0;
}
