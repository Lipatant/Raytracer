/*
** EPITECH PROJECT, 2023
** Generate.cpp
** File description:
** Generate, setting up the main loop from Setup data
*/

#include "nts/ComponentMap.hpp"
#include "nts/Instruction.hpp"
#include "nts/Exception.hpp"

void generateAdd(struct nts::Instruction_s const list, nts::ComponentMap &map);

bool generate(nts::InstructionList &instructionList, \
    nts::ComponentMap &componentMap)
{
    size_t listSize = instructionList.size();

    try {
        for (size_t i = 0; i < listSize; i++) {
            generateAdd(instructionList.front(), componentMap);
            instructionList.pop_front();
        }
    } catch (nts::exception::InvalidPin &error) {
        return nts::drawException(error.what(), error.content());
    } catch (nts::exception::InvalidKey &error) {
        return nts::drawException(error.what(), error.content());
    } catch (nts::exception::parsing::UnknownComponentName &error) {
        return nts::drawException(error.what(), error.content());
    } catch (nts::exception::parsing::UnknownComponentType &error) {
        return nts::drawException(error.what(), error.content());
    } catch (nts::exception::parsing::ShareSameName &error) {
        return nts::drawException(error.what(), error.content());
    } catch (nts::exception::parsing::UnknownStatement &error) {
        return nts::drawException(error.what(), error.content());
    } catch (nts::exception::parsing::ChipsetOutside &error) {
        return nts::drawException(error.what(), error.content());
    } catch (nts::exception::parsing::LinkOutside &error) {
        return nts::drawException(error.what(), error.content());
    } catch (nts::exception::parsing::LinkToItself &error) {
        return nts::drawException(error.what(), error.content());
    }
    return true;
}
