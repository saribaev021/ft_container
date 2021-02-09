//
// Created by Kanat Saribaew on 2/5/21.
//
#include <iostream>
#include <vector>
#include <list>
//#include "../List/list.hpp"
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
class Test{
private:
    char *str;
    int _n;
    Test(){
        std::cout << "constructor"<<std::endl;
    };
public:
    virtual ~Test() {
        delete[] str;
        std::cout << "destructor"<<std::endl;
    }
    Test(int n)
    {
        this->_n = n;
        std::cout << "constructor2"<<std::endl;
        this->str = new char [n];
        for (int i = 0; i != n; ++i) {
            this->str[i] = 'a' + i;
        }
    }
    Test(const char *val) {
        this->str = new char [10];
        for (int i = 0;val[i]; ++i) {
            this->str[i] = val[i];
        }
        this->_n = 10;
        std::cout << "constructor2"<<std::endl;
    }
    Test (const Test &other)
    {
        std::cout << "copy constructor"<<std::endl;
        this->str =  new char[10];
        int i = 0;
        for (; i < other._n; ++i) {
            this->str[i] = other.str[i];
        }
        this->_n =other._n;
    }
    Test &operator = (const Test &other)
    {

        if (this == &other)
            return *this;
        delete[] this->str;
        this->str =  new char[10];
        int i = 0;
        for (; i < other._n; ++i) {
            this->str[i] = other.str[i];
        }
        this->str[i] = other.str[i];
        this->_n =other._n;
        return *this;
    }
    char *getStr() const {
        return str;
    }
    void change(int i, char c)
    {
        this->str[i] = c;
    }
};
int main()
{
    std::allocator<Test> alloc;
    Test *test = alloc.allocate(1);
    Test *test2 = alloc.allocate(1);
//    Test *t1 = new Test(10);
    alloc.construct(test, 10);
    std::cout<< test->getStr()<<std::endl;
    alloc.construct(test2, test[0]);
    std::cout<< test2->getStr()<<std::endl;
    alloc.deallocate(test, 1);
//    std::cout<< t1->getStr()<<std::endl;
//    t1->change(4, '1');
//    std::cout<< (*test)->getStr()<<std::endl;
//    std::cout<< t1->getStr()<<std::endl;
    alloc.destroy(test2);
    alloc.deallocate(test2, 1);
    // clang++ -g -Wall -Wextra -Werror main.cpp

    return 0;
}