/*
** EPITECH PROJECT, 2023
** GetFileStream.cpp
** File description:
** Get stream from filepath
*/

#include <fstream>
#include <iostream>
#include "nts/Exception.hpp"

std::ifstream setupGetFileStream(std::string const &filename)
{
    std::ifstream fileStream(filename);

    if (!fileStream.is_open())
        throw nts::exception::parsing::CantOpenFile(filename);
    return fileStream;
}
