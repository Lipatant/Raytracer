/*
** EPITECH PROJECT, 2023
** Unit_tests.cpp
** File description:
** Unit_tests.cpp
*/

//Code à tester de Core.cpp ..................................................
#include "../include/Argument/Argument.hpp"
#include <iostream>
#include <map>

bool displayErrorKey(std::string const &key)
{
    std::cerr << "Invalid key '" << key << "'" << std::endl;
    return false;
}

bool displayErrorCount(void)
{
    std::cerr << "Invalid amount of arguments" << std::endl;
    return false;
}

bool setArguments(int const ac, char **av)
{
    std::string key;

    if (ac < 2)
        return displayErrorCount();
    key = av[1];
    return true;
}
//.............................................................................

#include <criterion/criterion.h>

Test(raytracer, basic_test)
{
    cr_assert_eq(0, 0);
}

Test(raytracer, test_displayErrorKey)
{
    std::string const &key = "test";

    int result = displayErrorKey(key);

    cr_assert_eq(result, 0);
}

Test(raytracer, test_displayErrorCount)
{
    int result = displayErrorCount();

    cr_assert_eq(result, 0);
}

Test(raytracer, test_setArguments1)
{
    int const ac = 2;
    char str1[15] = "./raytracer";
    char str2[5] = "test";
    char *av[ac] = {str1, str2};

    int result = setArguments(ac, av);

    cr_assert_eq(result, 1);
}

Test(raytracer, test_setArguments2)
{
    int const ac = 1;
    char str1[15] = "./raytracer";
    char *av[ac] = {str1};

    int result = setArguments(ac, av);

    cr_assert_eq(result, 0);
}
