//
// Created by Kanat Saribaew on 2/2/21.
//
#include "stack.hpp"
#include <iostream>
#include <list>
#include <vector>
# define RESET   "\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define BOLDBLACK   "\033[1m\033[30m"
# define BOLDRED     "\033[1m\033[31m"
# define BOLDGREEN   "\033[1m\033[32m"
# define BOLDYELLOW  "\033[1m\033[33m"
# define BOLDBLUE    "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDCYAN    "\033[1m\033[36m"
# define BOLDWHITE   "\033[1m\033[37m"
typedef std::list<std::string>::iterator SitStr;
typedef ft::list<std::string>::iterator itStr;
typedef ft::list<int>::iterator itInt;
typedef std::list<int>::iterator SitInt;
void relational_operators()
{
    std::cout << BLUE << "    RELATIONAL OPERATORS" <<RESET << std::endl;
    std::cout <<GREEN << "----------------STD-----------"<<RESET <<std::endl;
    std::list<int>a1(4, 56);
    std::list<int>a2(6,1);
    std::cout <<RED<< "a1(4, 56)"<<RESET<<std::endl;
    std::cout <<RED<< "a2(6, 1)"<<RESET<<std::endl;
    std::cout <<BLUE <<"a1 == a2"<<RESET<<std::endl;
    if (a1 == a2)
        std::cout <<RED<< "true"<<RESET<<std::endl;
    else
        std::cout <<RED<< "false"<<RESET<<std::endl;
    std::cout <<BLUE <<"a1 != a2"<<RESET<<std::endl;
    if (a1 != a2)
        std::cout <<RED<< "true"<<RESET<<std::endl;
    else
        std::cout <<RED<< "false"<<RESET<<std::endl;
    std::cout <<BLUE <<"a1 < a2"<<RESET<<std::endl;
    if (a1 < a2)
        std::cout <<RED<< "true"<<RESET<<std::endl;
    else
        std::cout <<RED<< "false"<<RESET<<std::endl;
    std::cout <<BLUE <<"a1 > a2"<<RESET<<std::endl;
    if (a1 > a2)
        std::cout <<RED<< "true"<<RESET<<std::endl;
    else
        std::cout <<RED<< "false"<<RESET<<std::endl;
    std::cout <<BLUE <<"a1 >= a2"<<RESET<<std::endl;
    if (a1 >= a2)
        std::cout <<RED<< "true"<<RESET<<std::endl;
    else
        std::cout <<RED<< "false"<<RESET<<std::endl;
    std::cout <<BLUE <<"a1 <= a2"<<RESET<<std::endl;
    if (a1 <= a2)
        std::cout <<RED<< "true"<<RESET<<std::endl;
    else
        std::cout <<RED<< "false"<<RESET<<std::endl;
    std::cout <<GREEN << "----------------FT-----------"<<RESET <<std::endl;
    {
        ft::list<int>a1(4, 56);
        ft::list<int>a2(6,1);
        std::cout <<RED<< "a1(4, 56)"<<RESET<<std::endl;
        std::cout <<RED<< "a2(6, 1)"<<RESET<<std::endl;
        std::cout <<BLUE <<"a1 == a2"<<RESET<<std::endl;
        if (a1 == a2)
            std::cout <<RED<< "true"<<RESET<<std::endl;
        else
            std::cout <<RED<< "false"<<RESET<<std::endl;
        std::cout <<BLUE <<"a1 != a2"<<RESET<<std::endl;
        if (a1 != a2)
            std::cout <<RED<< "true"<<RESET<<std::endl;
        else
            std::cout <<RED<< "false"<<RESET<<std::endl;
        std::cout <<BLUE <<"a1 < a2"<<RESET<<std::endl;
        if (a1 < a2)
            std::cout <<RED<< "true"<<RESET<<std::endl;
        else
            std::cout <<RED<< "false"<<RESET<<std::endl;
        std::cout <<BLUE <<"a1 > a2"<<RESET<<std::endl;
        if (a1 > a2)
            std::cout <<RED<< "true"<<RESET<<std::endl;
        else
            std::cout <<RED<< "false"<<RESET<<std::endl;
        std::cout <<BLUE <<"a1 >= a2"<<RESET<<std::endl;
        if (a1 >= a2)
            std::cout <<RED<< "true"<<RESET<<std::endl;
        else
            std::cout <<RED<< "false"<<RESET<<std::endl;
        std::cout <<BLUE <<"a1 <= a2"<<RESET<<std::endl;
        if (a1 <= a2)
            std::cout <<RED<< "true"<<RESET<<std::endl;
        else
            std::cout <<RED<< "false"<<RESET<<std::endl;
    }
}
int main()
{
    ft::stack<int>a1;
    a1.push(10);
    a1.push(10);
    a1.push(10);
    for (; !a1.empty();) {
        std::cout << a1.top()<<std::endl;
        a1.pop();
    }
    relational_operators();
}
