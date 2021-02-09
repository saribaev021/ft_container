//
// Created by Kanat Saribaew on 1/15/21.
//

#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include "Sfinae.hpp"
template <typename T>
void print(T, EnableIf<IsSame<T, >>)
//void swap(Test &x);
//
//std::ostream  &operator<<(std::ostream &os, const Test &test);
#endif //TEST_HPP
