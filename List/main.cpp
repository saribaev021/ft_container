#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <ostream>
#include <iterator>
#include "list.hpp"
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



template<typename TYPE>
void t_swap(TYPE &a, TYPE &b)
{
    TYPE tmp = b;
    b = a;
    a = tmp;
}
bool pred(const std::string &a)
{
    std::string s1 = "qwert";
    if (a == s1)
    {
        return true;
    }
    return false;
}

void constructor()
{
    std::string tab("qwertyuiopasdfghjklzxcvbnm1234567890");
    std::cout << BLUE << "             constructor   " <<RESET<< std::endl;
    std::cout <<GREEN << "-------------STD--------"<<RESET<<std::endl;
    std::list<std::string> default_constructor;
    std::cout << RED <<"default_constructor: size = "<<RESET << default_constructor.size() << std::endl;
    std::list<std::string> fill_constructor(10);
    std::cout << BOLDBLUE << "fill_constructor(10)"<<RESET <<std::endl;
    std::cout << RED <<"fill_constructor: size = "<<RESET << fill_constructor.size() << std::endl;
    std::list<std::string> fill2_constructor(10, "qwerert");
    std::cout << BOLDBLUE << "fill2_constructor(10, \"qwerert\")"<<RESET <<std::endl;
    std::cout << RED <<"fill2_constructor: size = "<<RESET << fill2_constructor.size() << std::endl;
    SitStr it = fill2_constructor.begin();
    std::cout << RED <<"fill2_constructor: value = " <<RESET;
    for (; it != fill2_constructor.end(); ++it) {
       std::cout<< *it << " ";
    }
    std::cout  << std::endl;
    std::list<std::string> range_constructor(fill2_constructor.begin(), fill2_constructor.end());
    std::cout << BOLDBLUE << "range_constructor(fill2_constructor.begin(), fill2_constructor.end())"<<RESET <<std::endl;
    std::cout << RED <<"range_constructor: size = " <<RESET<< range_constructor.size() << std::endl;
    it = range_constructor.begin();
    std::cout << RED <<"range_constructor: value = " <<RESET;
    for (; it != range_constructor.end(); ++it) {
        std::cout<< *it << " ";
    }
    std::cout  << std::endl;
    std::list<std::string> copy_constructor(fill2_constructor);
    std::cout << BOLDBLUE <<"copy_constructor(flill2_constructor())" <<RESET<< copy_constructor.size() << std::endl;
    std::cout << RED <<"copy_constructor: size = " <<RESET<< copy_constructor.size() << std::endl;
    it = copy_constructor.begin();
    std::cout << RED <<"copy_constructor: value = "<<RESET;
    for (; it != copy_constructor.end(); ++it) {
        std::cout<< *it << " ";
    }
    std::cout  << std::endl;
    std::cout <<GREEN << "-------------FT--------"<<RESET<<std::endl;
    {
        ft::list<std::string> default_constructor;
        std::cout << RED <<"default_constructor: size = "<<RESET << default_constructor.size() << std::endl;
        ft::list<std::string> fill_constructor(10);
        std::cout << BOLDBLUE << "fill_constructor(10)"<<RESET <<std::endl;
        std::cout << RED <<"fill_constructor: size = "<<RESET << fill_constructor.size() << std::endl;
        ft::list<std::string> fill2_constructor(10, "qwerert");
        std::cout << BOLDBLUE << "fill2_constructor(10, \"qwerert\")"<<RESET <<std::endl;
        std::cout << RED <<"fill2_constructor: size = "<<RESET << fill2_constructor.size() << std::endl;
        itStr it = fill2_constructor.begin();
        std::cout << RED <<"fill2_constructor: value = " <<RESET;
        for (; it != fill2_constructor.end(); ++it) {
            std::cout<< *it << " ";
        }
        std::cout  << std::endl;
        ft::list<std::string> range_constructor(fill2_constructor.begin(), fill2_constructor.end());
        std::cout << BOLDBLUE << "range_constructor(fill2_constructor.begin(), fill2_constructor.end())"<<RESET <<std::endl;
        std::cout << RED <<"range_constructor: size = " <<RESET<< range_constructor.size() << std::endl;
        it = range_constructor.begin();
        std::cout << RED <<"range_constructor: value = "<<RESET;
        for (; it != range_constructor.end(); ++it) {
            std::cout<< *it << " ";
        }
        std::cout  << std::endl;
        ft::list<std::string> copy_constructor(fill2_constructor);
        std::cout << BOLDBLUE <<"copy_constructor(flill2_constructor())" <<RESET<< copy_constructor.size() << std::endl;
        std::cout << RED <<"copy_constructor: size = " <<RESET<< copy_constructor.size() << std::endl;
        it = copy_constructor.begin();
        std::cout << RED <<"copy_constructor: value = "<<RESET;
        for (; it != copy_constructor.end(); ++it) {
            std::cout<< *it << " ";
        }
        std::cout  << std::endl;
    }
}
void splice()
{
    std::cout << BLUE << "         SPLICE" <<RESET<<std::endl;
    std::cout << GREEN << "---------STD------" <<RESET<<std::endl;
    std::list<int>a1(4, 34);
    std::list<int>a2(4, 67);
    a1.push_front(243);
    a2.push_front(2453);
    std::cout << YELLOW << "       BEFORE SPLICE"<<RESET<<std::endl;
    std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
    std::cout << RED<<"list a1: value = "<<RESET;
    for (SitInt it = a1.begin(); it != a1.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
    std::cout << RED<<"list a2: value = "<<RESET;
    for (SitInt it = a2.begin(); it != a2.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout<<GREEN<<"a1.splice(a1.begin(), a2)"<<RESET<<std::endl;
    a1.splice(a1.begin(), a2);
    SitInt a2_it = a2.begin();
    SitInt a1_it = a1.begin();
    std::cout << YELLOW << "       AFTER SPLICE"<<RESET<<std::endl;
    std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
    std::cout << RED<<"list a1: value = "<<RESET;
    for (; a1_it != a1.end(); ++a1_it)
    {
        std::cout << *a1_it <<" ";
    }
    std::cout <<std::endl;
    std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
    std::cout << RED<<"list a2: value = "<<RESET;
    for (; a2_it != a2.end(); ++a2_it)
    {
        std::cout << *a2_it <<" ";
    }
    std::cout <<std::endl;
    {
        std::cout << GREEN << "---------FT------" <<RESET<<std::endl;
        ft::list<int>a1(4, 34);
        ft::list<int>a2(4, 67);
        a1.push_front(243);
        a2.push_front(2453);
        std::cout << YELLOW << "       BEFORE SPLICE"<<RESET<<std::endl;
        std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
        std::cout << RED<<"list a1: value = "<<RESET;
        for (itInt it = a1.begin(); it != a1.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
        std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
        std::cout << RED<<"list a2: value = "<<RESET;
        for (itInt it = a2.begin(); it != a2.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
        std::cout<<GREEN<<"a1.splice(a1.begin(), a2)"<<RESET<<std::endl;
        a1.splice(a1.begin(), a2);
        itInt a2_it = a2.begin();
        itInt a1_it = a1.begin();
        std::cout << YELLOW << "       AFTER SPLICE"<<RESET<<std::endl;
        std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
        std::cout << RED<<"list a1: value = "<<RESET;
        for (; a1_it != a1.end(); ++a1_it)
        {
            std::cout << *a1_it <<" ";
        }
        std::cout <<std::endl;
        std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
        std::cout << RED<<"list a2: value = "<<RESET;
        for (; a2_it != a2.end(); ++a2_it)
        {
            std::cout << *a2_it <<" ";
        }
        std::cout <<std::endl;
    }
}
void splice_single_element()
{
    std::cout << BLUE << "     SPLICE SINGLE ELEMENT" <<RESET<<std::endl;
    std::cout << GREEN << "---------STD------" <<RESET<<std::endl;
    std::list<int>a1(4, 34);
    std::list<int>a2(4, 67);
    a1.push_front(243);
    a2.push_front(2453);
    std::cout << YELLOW << "       BEFORE SPLICE"<<RESET<<std::endl;
    std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
    std::cout << RED<<"list a1: value = "<<RESET;
    for (SitInt it = a1.begin(); it != a1.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
    std::cout << RED<<"list a2: value = "<<RESET;
    for (SitInt it = a2.begin(); it != a2.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout<<GREEN<<"a1.splice(a1.begin(), a2, ++a2.begin())"<<RESET<<std::endl;
    a1.splice(a1.begin(), a2, ++a2.begin());
    SitInt a2_it = a2.begin();
    SitInt a1_it = a1.begin();
    std::cout << YELLOW << "       AFTER SPLICE"<<RESET<<std::endl;
    std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
    std::cout << RED<<"list a1: value = "<<RESET;
    for (; a1_it != a1.end(); ++a1_it)
    {
        std::cout << *a1_it <<" ";
    }
    std::cout <<std::endl;
    std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
    std::cout << RED<<"list a2: value = "<<RESET;
    for (; a2_it != a2.end(); ++a2_it)
    {
        std::cout << *a2_it <<" ";
    }
    std::cout <<std::endl;
    {
        std::cout << GREEN << "---------FT------" <<RESET<<std::endl;
        ft::list<int>a1(4, 34);
        ft::list<int>a2(4, 67);
        a1.push_front(243);
        a2.push_front(2453);
        std::cout << YELLOW << "       BEFORE SPLICE"<<RESET<<std::endl;
        std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
        std::cout << RED<<"list a1: value = "<<RESET;
        for (itInt it = a1.begin(); it != a1.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
        std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
        std::cout << RED<<"list a2: value = "<<RESET;
        for (itInt it = a2.begin(); it != a2.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
        std::cout<<GREEN<<"a1.splice(a1.begin, a2, ++a2.begin())"<<RESET<<std::endl;
        a1.splice(a1.begin(), a2, ++a2.begin());
        itInt a2_it = a2.begin();
        itInt a1_it = a1.begin();
        std::cout << YELLOW << "       AFTER SPLICE"<<RESET<<std::endl;
        std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
        std::cout << RED<<"list a1: value = "<<RESET;
        for (; a1_it != a1.end(); ++a1_it)
        {
            std::cout << *a1_it <<" ";
        }
        std::cout <<std::endl;
        std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
        std::cout << RED<<"list a2: value = "<<RESET;
        for (; a2_it != a2.end(); ++a2_it)
        {
            std::cout << *a2_it <<" ";
        }
        std::cout <<std::endl;
    }
}
void assignOperator(){
    std::cout << BLUE <<"             operator =      " <<RESET<< std::endl;
    {
        std::cout << GREEN << "--------STD-------" <<RESET<<std::endl;
        {
            std::list<int> operator_assign;
            std::cout << RED << "list operator_assign: size = " << RESET << operator_assign.size() << std::endl;
            std::cout << BLUE << "list tmp: tmp(4, 43)" << RESET << std::endl;
            std::list<int> tmp(4, 34);
            std::cout << RED << "list tmp: size = " << RESET << tmp.size() << std::endl;
            SitInt it = tmp.begin();
            std::cout <<RED<< "list tmp: value = " <<RESET;
            for (; it != tmp.end(); ++it) {

                std::cout << *it <<" ";
            }
            std::cout << std::endl;
            operator_assign = tmp;
            std::cout << BLUE << "operator_assign = tmp" << RESET << std::endl;
            it = operator_assign.begin();
            std::cout << RED << "operator_assign: value = " << RESET;
            for (; it != operator_assign.end(); ++it) {

                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
        std::cout << GREEN << "--------FT-------" <<RESET<<std::endl;
        {
            ft::list<int> operator_assign;
            std::cout << RED << "list operator_assign: size = " << RESET << operator_assign.size() << std::endl;
            std::cout << BLUE << "list tmp: tmp(4, 43)" << RESET << std::endl;
            ft::list<int> tmp(4, 34);
            std::cout << RED << "list tmp: size = " << RESET << tmp.size() << std::endl;
            itInt it = tmp.begin();
            std::cout <<RED<< "list tmp: value = " <<RESET;
            for (; it != tmp.end(); ++it) {

                std::cout << *it <<" ";
            }
            std::cout << std::endl;
            operator_assign = tmp;
            std::cout << BLUE << "operator_assign = tmp" << RESET << std::endl;
            it = operator_assign.begin();
            std::cout << RED << "operator_assign: value = " << RESET;
            for (; it != operator_assign.end(); ++it) {

                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
    }
}
void reverse_iterator()
{
    std::cout << "             reverse_iterator      " << std::endl;
    {
        std::cout<<GREEN << "---------------STD------------"<<RESET<<std::endl;
        std::list<std::string> tmp;
        for (int i = 0; i < 26; ++i) {
            std::string str("a");
            str[0] += i;
            tmp.push_back(str);
        }
        SitStr it = tmp.begin();
        std::cout <<BLUE<<"SitStr it = tmp.begin()"<<RESET<<std::endl;
        std::cout <<RED<< "simple iterator: value =  "<<RESET;
        for (; it != tmp.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout <<BLUE<<"std::list<std::string>::reverse_iterator reverse_it = tmp.rbegin()"<<RESET<<std::endl;
        std::list<std::string>::reverse_iterator reverse_it = tmp.rbegin();
        std::cout <<RED << "reverse iterator: value = "<<RESET;
        for (; reverse_it != tmp.rend(); ++reverse_it) {
            std::cout << *reverse_it << " ";
        }
        std::cout << std::endl;
        {
            std::cout<<GREEN << "---------------FT------------"<<RESET<<std::endl;
            ft::list<std::string> tmp;
            for (int i = 0; i < 26; ++i) {
                std::string str("a");
                str[0] += i;
                tmp.push_back(str);
            }
            itStr it = tmp.begin();
            std::cout <<BLUE<<"itStr it = tmp.begin()"<<RESET<<std::endl;
            std::cout << RED << "simple iterator: value =  " << RESET;
            for (; it != tmp.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
            ft::list<std::string>::reverse_iterator reverse_it = tmp.rbegin();
            std::cout <<BLUE<<"ft::list<std::string>::reverse_iterator reverse_it = tmp.rbegin()"<<RESET<<std::endl;
            std::cout << RED << "reverse iterator: value = " << RESET;
            for (; reverse_it != tmp.rend(); ++reverse_it) {
                std::cout << *reverse_it << " ";
            }
            std::cout << std::endl;
        }
    }
}
void splice_element_range()
{
    std::cout << BLUE << "    SPLICE ELEMENT RANGE" <<RESET<<std::endl;
    std::cout << GREEN << "---------STD------" <<RESET<<std::endl;
    std::list<int>a1(4, 34);
    std::list<int>a2(4, 67);
    a1.push_front(243);
    a2.push_front(2453);
    std::cout << YELLOW << "       BEFORE SPLICE"<<RESET<<std::endl;
    std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
    std::cout << RED<<"list a1: value = "<<RESET;
    for (SitInt it = a1.begin(); it != a1.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
    std::cout << RED<<"list a2: value = "<<RESET;
    for (SitInt it = a2.begin(); it != a2.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout<<GREEN<<"a1.splice(a1.begin(), a2, a2.begin(), a2.end())"<<RESET<<std::endl;
    a1.splice(a1.begin(), a2, a2.begin(), a2.end());
    SitInt a2_it = a2.begin();
    SitInt a1_it = a1.begin();
    std::cout << YELLOW << "       AFTER SPLICE"<<RESET<<std::endl;
    std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
    std::cout << RED<<"list a1: value = "<<RESET;
    for (; a1_it != a1.end(); ++a1_it)
    {
        std::cout << *a1_it <<" ";
    }
    std::cout <<std::endl;
    std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
    std::cout << RED<<"list a2: value = "<<RESET;
    for (; a2_it != a2.end(); ++a2_it)
    {
        std::cout << *a2_it <<" ";
    }
    std::cout <<std::endl;
    {
        std::cout << GREEN << "---------FT------" <<RESET<<std::endl;
        ft::list<int>a1(4, 34);
        ft::list<int>a2(4, 67);
        a1.push_front(243);
        a2.push_front(2453);
        std::cout << YELLOW << "       BEFORE SPLICE"<<RESET<<std::endl;
        std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
        std::cout << RED<<"list a1: value = "<<RESET;
        for (itInt it = a1.begin(); it != a1.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
        std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
        std::cout << RED<<"list a2: value = "<<RESET;
        for (itInt it = a2.begin(); it != a2.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
        std::cout<<GREEN<<"a1.splice(a1.begin, a2, a2.begin(), a2.end())"<<RESET<<std::endl;
        a1.splice(a1.begin(), a2, a2.begin(), a2.end());
        itInt a2_it = a2.begin();
        itInt a1_it = a1.begin();
        std::cout << YELLOW << "       AFTER SPLICE"<<RESET<<std::endl;
        std::cout << RED<<"list a1: size = "<<RESET <<a1.size()<<std::endl;
        std::cout << RED<<"list a1: value = "<<RESET;
        for (; a1_it != a1.end(); ++a1_it)
        {
            std::cout << *a1_it <<" ";
        }
        std::cout <<std::endl;
        std::cout << RED<<"list a2: size = "<<RESET <<a2.size()<<std::endl;
        std::cout << RED<<"list a2: value = "<<RESET;
        for (; a2_it != a2.end(); ++a2_it)
        {
            std::cout << *a2_it <<" ";
        }
        std::cout <<std::endl;
    }
}
void capacity()
{
    std::cout << "             capacity      " << std::endl;
    {
        ft::list<int> capacity;
        if (capacity.empty())
            std::cout << "empty" << std::endl;
        else
            std::cout << "not empty" << std::endl;
        std::cout << "size " << capacity.size() << std::endl;
        capacity.push_back(1);
        if (capacity.empty())
            std::cout << "empty" << std::endl;
        else
            std::cout << "not empty" << std::endl;
        std::cout << "size " << capacity.size() << std::endl;
        std::list<std::vector<std::string> >tmp;
        ft::list<std::vector<std::string> >tmp2;
        std::cout << "max size " << tmp.max_size() << std::endl;
        std::cout << "max size " << tmp2.max_size() << std::endl;
    }
}
void front_back(){
    std::cout <<BLUE<< "             FRONT AND BACK     " << RESET<<std::endl;
    std::cout <<GREEN << "----------------STD-----------"<<RESET <<std::endl;
    std::list<std::string> tmp;
    for (int i = 0; i < 26; ++i) {
        std::string str("a");
        str[0] += i;
        tmp.push_back(str);
    }
    SitStr it = tmp.begin();
    std::cout << RED<<"list value: "<<RESET;
    for (; it != tmp.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << RED<<"front = "<<RESET << tmp.front()<< std::endl;
    std::cout << RED<<"back = " <<RESET<< tmp.back()<< std::endl;
    std::cout <<GREEN << "----------------FT-----------"<<RESET <<std::endl;
    {
        ft::list<std::string> tmp;
        for (int i = 0; i < 26; ++i) {
            std::string str("a");
            str[0] += i;
            tmp.push_back(str);
        }
        itStr it = tmp.begin();
        std::cout << RED<<"list value: "<<RESET;
        for (; it != tmp.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << RED<<"front = "<<RESET << tmp.front()<< std::endl;
        std::cout << RED<<"back = " <<RESET<< tmp.back()<< std::endl;
    }
}
void assign()
{
    std::cout << BLUE << "             assign      " << RESET<<std::endl;
    std::cout <<GREEN << "----------------STD-----------"<<RESET <<std::endl;
    std::list<std::string> assign_fill;
    std::cout << BLUE<<"assign_fill.assign(10, \"adfasfd\")"<<RESET<<std::endl;
    assign_fill.assign(10, "adfasfd");
    SitStr it_beg = assign_fill.begin();
    SitStr it_end = assign_fill.end();
    std::cout <<RED<< "assign_fill: value = "<<RESET;
    for (; it_beg != it_end; ++it_beg) {
        std::cout << *it_beg << " ";
    }
    std::cout << std::endl;
    std::list<std::string> assign_range;
    std::cout << BLUE<<"assign_fill.assign(assign_fill.begin(), assign_fill.end())"<<RESET<<std::endl;
    assign_range.assign(assign_fill.begin(), assign_fill.end());
    std::cout <<RED<< "assign_range: value = "<<RESET;
    it_beg = assign_range.begin();
    it_end = assign_range.end();
    for (; it_beg != it_end; ++it_beg) {
        std::cout << *it_beg << " ";
    }
    std::cout << std::endl;
    std::cout <<GREEN << "----------------FT-----------"<<RESET <<std::endl;
    {
        ft::list<std::string> assign_fill;
        std::cout << BLUE<<"assign_fill.assign(10, \"adfasfd\")"<<RESET<<std::endl;
        assign_fill.assign(10, "adfasfd");
        itStr it_beg = assign_fill.begin();
        itStr it_end = assign_fill.end();
        std::cout <<RED<< "assign_fill: value = "<<RESET;
        for (; it_beg != it_end; ++it_beg) {
            std::cout << *it_beg << " ";
        }
        std::cout << std::endl;
        ft::list<std::string> assign_range;
        std::cout << BLUE<<"assign_fill.assign(assign_fill.begin(), assign_fill.end())"<<RESET<<std::endl;
        assign_range.assign(assign_fill.begin(), assign_fill.end());
        std::cout <<RED<< "assign_range: value = "<<RESET;
        it_beg = assign_range.begin();
        it_end = assign_range.end();
        for (; it_beg != it_end; ++it_beg) {
            std::cout << *it_beg << " ";
        }
        std::cout << std::endl;
    }
}
void push_pop(){
    std::cout << "             push and pop     " << std::endl;
    std::list<int> tmp;
    for (int i = 0; i < 10; ++i) {
        tmp.push_back(rand() % 1000);
    }
    SitInt it_beg = tmp.begin();
    SitInt it_end = tmp.end();
    std::cout <<RED<< "list: value = "<<RESET;
    for (; it_beg != it_end; ++it_beg) {
        std::cout << *it_beg << " ";
    }
    std::cout << std::endl;
    std::cout <<BLUE << "push_front(345)" <<RESET<<std::endl;
    std::cout<<BLUE << "push_back(543)" << RESET<<std::endl;
    tmp.push_front(345);
    tmp.push_back(543);
    it_beg = tmp.begin();
    it_end = tmp.end();
    std::cout <<RED<< "list: value = "<<RESET;
    for (; it_beg != it_end; ++it_beg) {
        std::cout << *it_beg << " ";
    }
    std::cout << std::endl;
    std::cout <<BLUE << "pop_front()" <<RESET<<std::endl;
    std::cout<<BLUE << "pop_back()" << RESET<<std::endl;
    tmp.pop_front();
    tmp.pop_back();
    it_beg = tmp.begin();
    it_end = tmp.end();
    std::cout <<RED<< "list: value = " <<RESET;
    for (; it_beg != it_end; ++it_beg) {
        std::cout << *it_beg << " ";
    }
    std::cout << std::endl;
    {
        ft::list<int> tmp;
        for (int i = 0; i < 10; ++i) {
            tmp.push_back(rand() % 1000);
        }
        itInt it_beg = tmp.begin();
        itInt it_end = tmp.end();
        std::cout <<RED<< "list: value = "<<RESET;
        for (; it_beg != it_end; ++it_beg) {
            std::cout << *it_beg << " ";
        }
        std::cout << std::endl;
        std::cout <<BLUE << "push_front(345)" <<RESET<<std::endl;
        std::cout<<BLUE << "push_back(543)" << RESET<<std::endl;
        tmp.push_front(345);
        tmp.push_back(543);
        it_beg = tmp.begin();
        it_end = tmp.end();
        std::cout <<RED<< "list: value = "<<RESET;
        for (; it_beg != it_end; ++it_beg) {
            std::cout << *it_beg << " ";
        }
        std::cout << std::endl;
        std::cout <<BLUE << "pop_front()" <<RESET<<std::endl;
        std::cout<<BLUE << "pop_back()" << RESET<<std::endl;
        tmp.pop_front();
        tmp.pop_back();
        it_beg = tmp.begin();
        it_end = tmp.end();
        std::cout <<RED<< "list: value = " <<RESET;
        for (; it_beg != it_end; ++it_beg) {
            std::cout << *it_beg << " ";
        }
        std::cout << std::endl;
    }
}
void insert()
{
    std::cout<<BLUE << "             insert       " <<RESET<< std::endl;
    std::string tab("qwertyuiopasdfghjklzxcvbnm1234567890");
    std::cout <<GREEN << "----------------STD-----------"<<RESET <<std::endl;
    std::list<std::string> single_element;
    for (int i = 0; i < 20; ++i) {
        std::string str;
        for (int j = 0; j < 5; ++j) {

            str.push_back(tab[rand() % tab.length()]);
        }
        single_element.push_back(str);
    }
    SitStr it_beg = single_element.begin();
    SitStr it_end = single_element.end();
    std::cout <<RED<< "list: value = "<<RESET;
    for (; it_beg != it_end; ++it_beg) {
        std::cout << *it_beg << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl << BLUE << "single_element.insert(single_element.begin(), \"qwert\")" << RESET<<std::endl;
    single_element.insert(single_element.begin(), "qwert");
    single_element.insert(single_element.end(), "abcd");
    std::cout << BLUE << "single_element.insert(single_element.end(), \"abcd\")" << std::endl << RESET<<std::endl;
    it_beg = single_element.begin();
    it_end = single_element.end();
    std::cout << "list: value = ";
    for (; it_beg != it_end; ++it_beg) {
        std::cout << *it_beg << " ";
    }
    std::cout << std::endl;
    std::list<std::string> insert_range;
    std::cout <<BLUE
              << "insert_range.insert(insert_range.begin(), single_element.begin(), single_element.end())"
              <<RESET<< std::endl;
    insert_range.insert(insert_range.begin(), single_element.begin(), single_element.end());
    std::cout <<RED<< "list: value = "<<RESET;
    it_beg = insert_range.begin();
    it_end = insert_range.end();
    for (; it_beg != it_end; ++it_beg) {
        std::cout << *it_beg << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout <<BLUE<< "insert_fill(insert_fill.begin(), 10, \"qee\")" << RESET<<std::endl;
    std::cout << std::endl;
    std::list<std::string> insert_fill;
    insert_fill.insert(insert_fill.begin(), 10, "qee");
    std::cout << "list: value = ";
    it_beg = insert_fill.begin();
    it_end = insert_fill.end();
    for (; it_beg != it_end; ++it_beg) {
        std::cout << *it_beg << " ";
    }
    std::cout << std::endl;
    std::cout <<GREEN << "----------------FT-----------"<<RESET <<std::endl;
    {
        ft::list<std::string> single_element;
        for (int i = 0; i < 20; ++i) {
            std::string str;
            for (int j = 0; j < 5; ++j) {

                str.push_back(tab[rand() % tab.length()]);
            }
            single_element.push_back(str);
        }
        itStr it_beg = single_element.begin();
        itStr it_end = single_element.end();
        std::cout <<RED<< "list: value = "<<RESET;
        for (; it_beg != it_end; ++it_beg) {
            std::cout << *it_beg << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl << BLUE << "single_element.insert(single_element.begin(), \"qwert\")" << RESET<<std::endl;
        single_element.insert(single_element.begin(), "qwert");
        single_element.insert(single_element.end(), "abcd");
        std::cout << BLUE << "single_element.insert(single_element.end(), \"abcd\")" << std::endl << RESET<<std::endl;
        it_beg = single_element.begin();
        it_end = single_element.end();
        std::cout << "list: value = ";
        for (; it_beg != it_end; ++it_beg) {
            std::cout << *it_beg << " ";
        }
        std::cout << std::endl;
        ft::list<std::string> insert_range;
        std::cout <<BLUE
                  << "insert_range.insert(insert_range.begin(), single_element.begin(), single_element.end())"
                  <<RESET<< std::endl;
        insert_range.insert(insert_range.begin(), single_element.begin(), single_element.end());
        std::cout <<RED<< "list: value = "<<RESET;
        it_beg = insert_range.begin();
        it_end = insert_range.end();
        for (; it_beg != it_end; ++it_beg) {
            std::cout << *it_beg << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout <<BLUE<< "insert_fill(insert_fill.begin(), 10, \"qee\")" << RESET<<std::endl;
        std::cout << std::endl;
        ft::list<std::string> insert_fill;
        insert_fill.insert(insert_fill.begin(), 10, "qee");
        std::cout << "list: value = ";
        it_beg = insert_fill.begin();
        it_end = insert_fill.end();
        for (; it_beg != it_end; ++it_beg) {
            std::cout << *it_beg << " ";
        }
        std::cout << std::endl;
    }
}
void erase()
{
    std::cout << BLUE <<"             ERASE     " << RESET<<std::endl;
    std::cout <<GREEN << "----------------STD-----------"<<RESET <<std::endl;
    std::list<int> simple_erase(5, 45);
    simple_erase.push_front(456);
    simple_erase.push_front(19);
    simple_erase.push_back(343);
    simple_erase.push_back(763);
    SitInt it_beg = simple_erase.begin();
    SitInt it_end = simple_erase.end();
    std::cout << "list: value = ";
    for (; it_beg != it_end; ++it_beg)
        std::cout << *it_beg << " ";
    std::cout << std::endl;
    it_beg = simple_erase.begin();
    it_end = simple_erase.end();
    std::cout << BLUE<<"simple_erase.erase(it_beg)"<<RESET<<std::endl;
    it_beg = simple_erase.erase(it_beg);
    std::cout <<RED<< "list: value = "<<RESET;
    for (; it_beg != it_end; ++it_beg)
        std::cout << *it_beg << " ";
    std::cout << std::endl;
    simple_erase.erase(++simple_erase.begin(), --simple_erase.end());
    std::cout << BLUE<<"simple_erase.erase(++simple_erase.begin(),++simple_erase.end())"<<RESET<<std::endl;
    it_beg = simple_erase.begin();
    it_end = simple_erase.end();
    std::cout<< RED<< "list: value = "<<RESET;
    for (; it_beg != it_end; ++it_beg)
        std::cout << *it_beg << " ";
    std::cout << std::endl;
    std::cout <<GREEN << "----------------FT-----------"<<RESET <<std::endl;
    {
        ft::list<int> simple_erase(5, 45);
        simple_erase.push_front(456);
        simple_erase.push_front(19);
        simple_erase.push_back(343);
        simple_erase.push_back(763);
        itInt it_beg = simple_erase.begin();
        itInt it_end = simple_erase.end();
        std::cout << "list: value = ";
        for (; it_beg != it_end; ++it_beg)
            std::cout << *it_beg << " ";
        std::cout << std::endl;
        it_beg = simple_erase.begin();
        it_end = simple_erase.end();
        std::cout << BLUE<<"simple_erase.erase(it_beg)"<<RESET<<std::endl;
        it_beg = simple_erase.erase(it_beg);
        std::cout <<RED<< "list: value = "<<RESET;
        for (; it_beg != it_end; ++it_beg)
            std::cout << *it_beg << " ";
        std::cout << std::endl;
        simple_erase.erase(++simple_erase.begin(), --simple_erase.end());
        std::cout << BLUE<<"simple_erase.erase(++simple_erase.begin(),++simple_erase.end())"<<RESET<<std::endl;
        it_beg = simple_erase.begin();
        it_end = simple_erase.end();
        std::cout<< RED<< "list: value = "<<RESET;
        for (; it_beg != it_end; ++it_beg)
            std::cout << *it_beg << " ";
        std::cout << std::endl;
    }
}
void swap()
{
    std::cout << BLUE<<"             swap     " << RESET<<std::endl;
    std::cout <<GREEN << "----------------STD-----------"<<RESET <<std::endl;
    std::cout << YELLOW << "      BEFORE SWAP"<<RESET<<std::endl;
    std::list<std::string> a1(4, "qwert");
    std::list<std::string> a2(5, "hesoyam");
    a1.push_back("wer");
    a1.push_front("456r");
    a2.push_back("trer");
    a2.push_front("67556r");
    SitStr it_beg = a1.begin();
    SitStr it_end = a1.end();
    std::cout <<RED<< "list a1: size = " << a1.size() <<RESET<<std::endl;
    std::cout <<RED<< "list a1: value = "<<RESET;
    for (; it_beg != it_end; ++it_beg)
        std::cout << *it_beg << " ";
    std::cout << std::endl;
    it_beg = a2.begin();
    it_end = a2.end();
    std::cout <<RED<< "list a2: size = " << a2.size() <<RESET<<std::endl;
    std::cout <<RED<< "list a2: value = "<<RESET;
    for (; it_beg != it_end; ++it_beg)
        std::cout << *it_beg << " ";
    std::cout << std::endl;
    std::cout <<BLUE<< "a1.swap(a2)" << RESET<<std::endl;
    a1.swap(a2);
    it_beg = a1.begin();
    it_end = a1.end();
    std::cout << YELLOW << "      AFTER SWAP"<<RESET<<std::endl;
    std::cout <<RED<< "list a1: size = " << a1.size() <<RESET<<std::endl;
    std::cout <<RED<< "list a1: value = "<<RESET;
    for (; it_beg != it_end; ++it_beg)
        std::cout << *it_beg << " ";
    std::cout << std::endl;
    it_beg = a2.begin();
    it_end = a2.end();
    std::cout <<RED<< "list a2: size = " << a2.size() <<RESET<<std::endl;
    std::cout <<RED<< "list a2: value = "<<RESET;
    for (; it_beg != it_end; ++it_beg)
        std::cout << *it_beg << " ";
    std::cout << std::endl;
    std::cout <<GREEN << "----------------FT-----------"<<RESET <<std::endl;
    {
        std::cout << YELLOW << "      BEFORE SWAP"<<RESET<<std::endl;
        ft::list<std::string> a1(4, "qwert");
        ft::list<std::string> a2(5, "hesoyam");
        a1.push_back("wer");
        a1.push_front("456r");
        a2.push_back("trer");
        a2.push_front("67556r");
        itStr it_beg = a1.begin();
        itStr it_end = a1.end();
        std::cout <<RED<< "list a1: size = " << a1.size() <<RESET<<std::endl;
        std::cout <<RED<< "list a1: value = "<<RESET;
        for (; it_beg != it_end; ++it_beg)
            std::cout << *it_beg << " ";
        std::cout << std::endl;
        it_beg = a2.begin();
        it_end = a2.end();
        std::cout <<RED<< "list a2: size = " << a2.size() <<RESET<<std::endl;
        std::cout <<RED<< "list a2: value = "<<RESET;
        for (; it_beg != it_end; ++it_beg)
            std::cout << *it_beg << " ";
        std::cout << std::endl;
        std::cout <<BLUE<< "a1.swap(a2)" << RESET<<std::endl;
        a1.swap(a2);
        it_beg = a1.begin();
        it_end = a1.end();
        std::cout << YELLOW << "      AFTER SWAP"<<RESET<<std::endl;
        std::cout <<RED<< "list a1: size = " << a1.size() <<RESET<<std::endl;
        std::cout <<RED<< "list a1: value = "<<RESET;
        for (; it_beg != it_end; ++it_beg)
            std::cout << *it_beg << " ";
        std::cout << std::endl;
        it_beg = a2.begin();
        it_end = a2.end();
        std::cout <<RED<< "list a2: size = " << a2.size() <<RESET<<std::endl;
        std::cout <<RED<< "list a2: value = "<<RESET;
        for (; it_beg != it_end; ++it_beg)
            std::cout << *it_beg << " ";
        std::cout << std::endl;
    }
}

void resize()
{
    std::cout << "  RESIZE" << std::endl;
    std::cout <<GREEN << "----------------STD-----------"<<RESET <<std::endl;
    std::vector<int> tmp(3, 4);
    std::list<int> reseize(5, 10);
    SitInt it_beg = reseize.begin();
    SitInt it_end = reseize.end();
    std::cout << RED<<"list: size = " <<RESET<<reseize.size()<<std::endl;
    std::cout << RED<< "list: value = "<<RESET <<std::endl;
    for (; it_beg != it_end; ++it_beg)
        std::cout << *it_beg << " ";
    std::cout << std::endl;
    std::cout <<BLUE<<"resize.resize(2, 6)" <<RESET<<std::endl;
    reseize.resize(2, 6);
    it_beg = reseize.begin();
    it_end = reseize.end();
    --it_beg;
    --it_end;
    std::cout << RED<<"list: size = " <<RESET<<reseize.size()<<std::endl;
    std::cout << RED<< "list: value = "<<RESET <<std::endl;
    for (; it_beg != it_end; --it_end) {
        std::cout << *it_end << " ";
    }
    std::cout << std::endl;
    reseize.resize(10, 45);
    it_beg = reseize.begin();
    it_end = reseize.end();
    std::cout << RED<<"list: size = " <<RESET<<reseize.size()<<std::endl;
    std::cout << RED<< "list: value = "<<RESET <<std::endl;
    for (; it_beg != it_end; ++it_beg) {
        std::cout << *it_beg << " ";
    }
    std::cout << std::endl;
    std::cout <<GREEN << "----------------FT-----------"<<RESET <<std::endl;
    {
        std::vector<int> tmp(3, 4);
        ft::list<int> reseize(5, 10);
        itInt it_beg = reseize.begin();
        itInt it_end = reseize.end();
        std::cout << RED<<"list: size = " <<RESET<<reseize.size()<<std::endl;
        std::cout << RED<< "list: value = "<<RESET <<std::endl;
        for (; it_beg != it_end; ++it_beg)
            std::cout << *it_beg << " ";
        std::cout << std::endl;
        std::cout <<BLUE<<"resize.resize(2, 6)" <<RESET<<std::endl;
        reseize.resize(2, 6);
        it_beg = reseize.begin();
        it_end = reseize.end();
        --it_beg;
        --it_end;
        std::cout << RED<<"list: size = " <<RESET<<reseize.size()<<std::endl;
        std::cout << RED<< "list: value = "<<RESET <<std::endl;
        for (; it_beg != it_end; --it_end) {
            std::cout << *it_end << " ";
        }
        std::cout << std::endl;
        reseize.resize(10, 45);
        it_beg = reseize.begin();
        it_end = reseize.end();
        //it_beg;
        //it_end;
        std::cout << RED<<"list: size = " <<RESET<<reseize.size()<<std::endl;
        std::cout << RED<< "list: value = "<<RESET <<std::endl;
        for (; it_beg != it_end; ++it_beg) {
            std::cout << *it_beg << " ";
        }
        std::cout << std::endl;
    }

}
void clear()
{
    std::cout << BLUE<<"         CLEAR "<<RESET << std::endl;
    std::cout <<GREEN << "----------------STD-----------"<<RESET <<std::endl;
    std::list<std::string> a1(4, "sfdfg");
    std::cout<<BLUE<<"a1(4, \"sfdfg\")"<<RESET<<std::endl;
    std::cout <<RED<< "list a1: size = "<<RESET<<a1.size()<<std::endl;
    std::cout<<BLUE<<"a1.clear()"<<RESET<<std::endl;
    a1.clear();
    std::cout <<RED<< "list a1: size = "<<RESET<<a1.size()<<std::endl;
    std::cout <<GREEN << "----------------FT-----------"<<RESET <<std::endl;
    {
        ft::list<std::string> a1(4, "sfdfg");
        std::cout<<BLUE<<"a1(4, \"sfdfg\")"<<RESET<<std::endl;
        std::cout <<RED<< "list a1: size = "<<RESET<<a1.size()<<std::endl;
        std::cout<<BLUE<<"a1.clear()"<<RESET<<std::endl;
        a1.clear();
        std::cout <<RED<< "list a1: size = "<<RESET<<a1.size()<<std::endl;
    }
}
void remove()
{
    std::cout << BLUE << "           REMOVE  "<<RESET<<std::endl;
    std::cout <<GREEN << "----------------STD-----------"<<RESET <<std::endl;
    std::list<std::string>s1(4, "abcdef");
    s1.push_front("sfs");
    s1.push_front("qwer");
    s1.push_back("dgfd");
    std::cout <<RED<< "list s1: size = "<<RESET << s1.size()<<std::endl;
    std::cout <<RED<< "list s1: value = "<<RESET;
    for (SitStr it = s1.begin(); it != s1.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    s1.remove("abcdef");
    std::cout << BLUE << "s1.remove(\"abcdef\")"<<RESET<<std::endl;
    std::cout <<RED<< "list s1: size = "<<RESET << s1.size()<<std::endl;
    std::cout <<RED<< "list s1: value = "<<RESET;
    for (SitStr it = s1.begin(); it != s1.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << BLUE << "s1.resize(\"qwert\")"<<RESET<<std::endl;
    s1.resize(10, "qwert");
    std::cout <<RED<< "list s1: size = "<<RESET << s1.size()<<std::endl;
    std::cout <<RED<< "list s1: value = "<<RESET;
    for (SitStr it = s1.begin(); it != s1.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << BLUE << "s1.remove_if(pred)"<<RESET<<std::endl;
    s1.remove_if(pred);
    std::cout <<RED<< "list s1: size = "<<RESET << s1.size()<<std::endl;
    std::cout <<RED<< "list s1: value = "<<RESET;
    for (SitStr it = s1.begin(); it != s1.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout <<GREEN << "----------------FT-----------"<<RESET <<std::endl;
    {
        ft::list<std::string>s1(4, "abcdef");
        s1.push_front("sfs");
        s1.push_front("qwer");
        s1.push_back("dgfd");
        std::cout <<RED<< "list s1: size = "<<RESET << s1.size()<<std::endl;
        std::cout <<RED<< "list s1: value = "<<RESET;
        for (itStr it = s1.begin(); it != s1.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
        s1.remove("abcdef");
        std::cout << BLUE << "s1.remove(\"abcdef\")"<<RESET<<std::endl;
        std::cout <<RED<< "list s1: size = "<<RESET << s1.size()<<std::endl;
        std::cout <<RED<< "list s1: value = "<<RESET;
        for (itStr it = s1.begin(); it != s1.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
        std::cout << BLUE << "s1.resize(\"qwert\")"<<RESET<<std::endl;
        s1.resize(10, "qwert");
        std::cout <<RED<< "list s1: size = "<<RESET << s1.size()<<std::endl;
        std::cout <<RED<< "list s1: value = "<<RESET;
        for (itStr it = s1.begin(); it != s1.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
        std::cout << BLUE << "s1.remove_if(pred)"<<RESET<<std::endl;
        s1.remove_if(pred);
        std::cout <<RED<< "list s1: size = "<<RESET << s1.size()<<std::endl;
        std::cout <<RED<< "list s1: value = "<<RESET;
        for (itStr it = s1.begin(); it != s1.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
    }
}
void unique()
{
    std::cout <<BLUE<< "            UNIQUE     "<<RESET << std::endl;
    std::cout <<GREEN << "----------------STD-----------"<<RESET <<std::endl;
    std::list<int>a1(3, 87);
    a1.push_back(45);
    a1.push_back(65);
    a1.push_back(6);
    a1.push_back(123);
    a1.push_front(187);
    a1.push_front(3487);
    std::cout <<RED<< "list a1: size = "<<RESET << a1.size()<<std::endl;
    std::cout <<RED<< "list a1: value = "<<RESET;
    for (SitInt it = a1.begin(); it != a1.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << BLUE << "a1.unique()"<<RESET<<std::endl;
    a1.unique();
    std::cout <<RED<< "list a1: size = "<<RESET << a1.size()<<std::endl;
    std::cout <<RED<< "list a1: value = "<<RESET;
    for (SitInt it = a1.begin(); it != a1.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout <<GREEN << "----------------FT-----------"<<RESET <<std::endl;
    {
        ft::list<int>a1(3, 87);
        a1.push_back(45);
        a1.push_back(65);
        a1.push_back(6);
        a1.push_back(123);
        a1.push_front(187);
        a1.push_front(3487);
        std::cout <<RED<< "list a1: size = "<<RESET << a1.size()<<std::endl;
        std::cout <<RED<< "list a1: value = "<<RESET;
        for (itInt it = a1.begin(); it != a1.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
        std::cout << BLUE << "a1.unique()"<<RESET<<std::endl;
        a1.unique();
        std::cout <<RED<< "list a1: size = "<<RESET << a1.size()<<std::endl;
        std::cout <<RED<< "list a1: value = "<<RESET;
        for (itInt it = a1.begin(); it != a1.end(); ++it)
        {
            std::cout << *it <<" ";
        }
        std::cout <<std::endl;
    }
}
void merge()
{
    std::cout <<BLUE<< "            MERGE     "<<RESET << std::endl;
    {
        std::list<int>a1;
        std::list<int>a2;
        a1.push_back(0);
        a1.push_back(15);
        a1.push_back(1);
        a1.push_back(19);

        a2.push_back(0);
        a2.push_back(1);
        a2.push_back(0);
        a2.push_back(20);

        std::cout << GREEN<<"------STD--------"<<RESET<<std::endl;
        std::cout << RED<<"------BEFORE MERGE--------"<<RESET<<std::endl;
        std::cout << "list a1: value = ";
        for (SitInt it = a1.begin(); it != a1.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << "list a2: value = ";
        for (SitInt it = a2.begin(); it != a2.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        a1.sort();
//        a2.sort();
        std::cout << YELLOW << "a1.sort()"<<RESET<<std::endl;
//        std::cout << YELLOW << "a2.sort()"<<RESET<<std::endl;
        std::cout << YELLOW << "a1.merge(a2)"<<RESET<<std::endl;
        a1.merge(a2);
        std::cout << RED<<"------AFTER MERGE--------"<<RESET<<std::endl;
        for (SitInt it = a1.begin(); it != a1.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        {
            std::cout << GREEN<<"-------FT------"<<RESET<<std::endl;
            ft::list<int>a1;
            ft::list<int>a2;
            a1.push_back(0);
            a1.push_back(15);
            a1.push_back(1);
            a1.push_back(19);

            a2.push_back(0);
            a2.push_back(1);
            a2.push_back(0);
            a2.push_back(20);
            std::cout << RED<<"------BEFORE MERGE--------"<<RESET<<std::endl;
            std::cout << "list a1: value = ";
            for (itInt it = a1.begin(); it != a1.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
            std::cout << "list a2: value = ";
            for (itInt it = a2.begin(); it != a2.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
            a1.sort();
//            a2.sort();
            std::cout << YELLOW << "a1.sort()"<<RESET<<std::endl;
//            std::cout << YELLOW << "a2.sort()"<<RESET<<std::endl;
            std::cout << YELLOW << "a1.merge(a2)"<<RESET<<std::endl;
            a1.merge(a2);
            std::cout << RED<<"------AFTER MERGE--------"<<RESET<<std::endl;
            for (itInt it = a1.begin(); it != a1.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

    }
}
void sort()
{
    std::string tab("qwertyuiopasdfghjklzxcvbnm1234567890");
    std::cout <<BLUE<< "             sort int      "<<RESET << std::endl;
    {
        ft::list<int> a1;
        for (int i = 0; i < 20; ++i) {
            a1.push_back(i + (rand() % 42000));
        }
        ft::list<int>::iterator it = a1.begin();
        std::cout <<GREEN<< "BEFORE  SORTING"<<RESET << std::endl;
        for (; it != a1.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        a1.sort();
        std::cout << "AFTER SORTING" <<RESET<< std::endl;
        it = a1.begin();
        for (; it != a1.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    {
        std::cout << BLUE<<"             sort string  simple    " << RESET<<std::endl;
        ft::list<std::string> s1;
        std::string str("a");
        for (int i = 0; i < 20; ++i) {
            std::string str("a");
            str[0] += rand() % 27;
            s1.push_back(str);
        }
        std::cout <<GREEN<< "BEFORE  SORTING"<<RESET << std::endl;
        ft::list<std::string>::iterator it = s1.begin();
        for (; it != s1.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        s1.sort();
        std::cout << "AFTER SORTING" <<RESET<< std::endl;
        it = s1.begin();
        for (; it != s1.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    {
        std::cout <<BLUE<< "             sort string      "<<RESET << std::endl;
        ft::list<std::string> s1;
//        std::string str("a");

        for (int i = 0; i < 20; ++i) {
            std::string str;
            for (int j = 0; j < 5; ++j) {

                str.push_back(tab[rand() % tab.length()]);
            }
            s1.push_back(str);
        }
        std::cout <<GREEN<< "BEFORE  SORTING"<<RESET << std::endl;
        ft::list<std::string>::iterator it = s1.begin();
        for (; it != s1.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        s1.sort();
        std::cout << "AFTER SORTING" <<RESET<< std::endl;
        it = s1.begin();
        for (; it != s1.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
//        std::list<int>::iterator::iterator_category
    }
}
void reverse(){
    std::cout << BLUE << "     REVERSE" <<RESET << std::endl;
    {
        ft::list<int>a1;
        for (int i = 0; i <10 ; ++i) {
            a1.push_back(i);
        }
        std::cout << "list a1: value = ";
        for (itInt it = a1.begin(); it != a1.end(); ++it)
        {
            std::cout << *it<<" ";
        }
        std::cout <<std::endl;
        std::cout << RED << "a1.reverse()"<<RESET<<std::endl;
        a1.reverse();
        std::cout << "list a1: value = ";
        for (itInt it = a1.begin(); it != a1.end(); ++it)
        {
            std::cout << *it<<" ";
        }
        std::cout <<std::endl;
    }
}
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

int main() {
    std::srand(time(nullptr));
    std::string tab("qwertyuiopasdfghjklzxcvbnm1234567890");
    constructor();
    splice();
    splice_single_element();
    splice_element_range();
    assignOperator();
    reverse_iterator();
    front_back();
    capacity();
    assign();
    push_pop();
    insert();
    erase();
    swap();
    resize();
    clear();
    remove();
    unique();
    merge();
    sort();
    reverse();
    relational_operators();
}