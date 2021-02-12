//
// Created by Kanat Saribaew on 2/11/21.
//

#ifndef TREE_HPP
#define TREE_HPP
namespace ft {
    template<typename K, typename V>
    struct tree {
        K key;
        V vallue;
        bool color;
        int type;
        tree() {}
        tree(const K &key, const V &val): key(key), vallue(val){};
        tree(const tree &other): key(other.key), vallue(other.vallue){
            color = other.color;
            type = other.type;
        };
        struct tree *parent;
        struct tree *left;
        struct tree *right;
    };
}
#endif //TREE_HPP
