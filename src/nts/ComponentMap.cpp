/*
** EPITECH PROJECT, 2023
** nts/ComponentMap.cpp
** File description:
** -
*/

#include "nts/ComponentMap.hpp"
#include "nts/Exception.hpp"

nts::ComponentMapPair &nts::ComponentMap::operator[](size_t const id)
{
    if (id >= _map.size())
        throw nts::exception::InvalidId();
    return _map[id];
}

nts::ComponentMapValue &nts::ComponentMap::operator[](std::string const &key)
{
    return getValue(key);
}

bool nts::ComponentMap::isKey(std::string const key)
{
    size_t size = _map.size();

    for (size_t i = 0; i < size; i++)
        if (_map[i].first == key)
            return true;
    return false;
}

bool nts::ComponentMap::addValue(std::string key, \
    nts::ComponentMapValue value)
{
    if (isKey(key))
        return false;
    _map.push_back({key, value});
    return true;
}

nts::ComponentMapValue &nts::ComponentMap::getValue(std::string key)
{
    size_t size = _map.size();

    for (size_t i = 0; i < size; i++)
        if (_map[i].first == key)
            return _map[i].second;
    throw nts::exception::InvalidKey(key);
}

nts::instruction::Mode &nts::ComponentMap::mode(void)
{
    return _mode;
}

nts::ComponentMapMap &nts::ComponentMap::map(void)
{
    return _map;
}
