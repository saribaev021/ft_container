//
// Created by Kanat Saribaew on 1/5/21.
//

#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
namespace ft {
    template<typename T>
    struct t_node {
        T data;
        t_node(){
        }
        t_node(const T &_data):data(_data){}
        struct t_node *next;
        struct t_node *prev;
    };
}
#endif //NODE_HPP
