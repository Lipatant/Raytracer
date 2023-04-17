/*
** EPITECH PROJECT, 2023
** Setup.cpp
** File description:
** Setup, acting as a pre-main
*/

#include <fstream>
#include "nts/Exception.hpp"
#include "nts/Instruction.hpp"

std::string setupGetFilename(int const ac, char const * const * const av);
std::ifstream setupGetFileStream(std::string const &filename);
void setupParse(std::ifstream &stream, nts::InstructionList &list);

bool setup(int const ac, char const * const * const av, \
    nts::InstructionList &list)
{
    std::ifstream fileStream;

    try {
        fileStream = setupGetFileStream(setupGetFilename(ac, av));
        setupParse(fileStream, list);
        fileStream.close();
    } catch (nts::exception::usage::InvalidAmountArguments &error) {
        return nts::drawException(error.what(), error.content());
    } catch (nts::exception::parsing::CantOpenFile &error) {
        return nts::drawException(error.what(), error.content());
    } catch (nts::exception::parsing::UnknownLineFormating &error) {
        return nts::drawException(error.what(), error.content());
    }
    return true;
}
