//
// Created by Kanat Saribaew on 2/11/21.
//

#ifndef MAP_HPP
#define MAP_HPP
#include "Tree.hpp"
#include "../Iterator/Iterator.hpp"
#include <cstddef>
#include <limits>
#include <iostream>
namespace ft{
    template < class Key,                                  //   map::key_type
            class T,                                       // map::mapped_type
            class Compare = std::less<Key>,                     // map::key_compare
            class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
    > class map{
    public:
        typedef Key                                     key_type;
        typedef T                                       mapped_type;
        typedef std::pair<const key_type, mapped_type>  value_type;
        typedef Compare                                 key_compare;
        typedef Alloc                                   allocator_type;
        typedef typename allocator_type::reference               reference;
        typedef typename allocator_type::const_reference         const_reference;
        typedef typename allocator_type::pointer                 pointer;
        typedef typename allocator_type::const_pointer           const_pointer;
        typedef SimpleMapIterator<Key, T>               iterator;
        typedef ConstMapIterator<Key, T>                const_iterator;
        typedef reverse_iterator<const_iterator>        const_reverse_iterator;
        typedef reverse_iterator<iterator>              reverse_iterator;
        typedef ptrdiff_t                               difference_type;
        typedef size_t                                  size_type;
    private:
//        #define BLACk 1
//        #define 0 0
        typedef tree<key_type, mapped_type> node;
        std::allocator<tree<key_type, mapped_type> > _base_alloc;
        allocator_type _alloc;
        node *_head;
        node *_root;
        node *_end;
        node *_null_leaf;
        key_compare _compare;
        size_type _size;
        key_type _min;
        key_type _max;
        void _new_node(){
            _root = new node();
            _null_leaf = new node();
            _head = _root;
            _end = _root;
            _root->type = 3;
            _null_leaf->type = 0;
            _null_leaf->color = 1;
            _root->left = _null_leaf;
            _root->right = _null_leaf;
        }
//        bool _insert(node *n){
//            }
//        }
        node *grandparent(node *n)
        {
            if ((n != NULL) && (n->parent->type == 1))
                return n->parent->parent;
            else
                return NULL;
        }
        node *uncle(node *n)
        {
            node *g = grandparent(n);
            if (g == NULL)
                return NULL; // No grandparent means no uncle
            if (n->parent == g->left)
                return g->right;
            else
                return g->left;
        }
        void rotate_left(node *n)
        {
            node *pivot = n->right;

            pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
            if (n->parent->type == 1 || n->parent->type == 3) {
                if (n->parent->left==n)
                    n->parent->left = pivot;
                else
                    n->parent->right = pivot;
            }
            n->right = pivot->left;
            if (pivot->left->type == 1)
                pivot->left->parent = n;
            n->parent = pivot;
            pivot->left = n;
        }
        void rotate_right(node *n)
        {
            node *pivot = n->left;

            pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
            if (n->parent->type == 1 || n->parent->type == 3) {
                if (n->parent->left==n)
                    n->parent->left = pivot;
                else
                    n->parent->right = pivot;
            }
            n->left = pivot->right;
            if (pivot->right->type == 1)
                pivot->right->parent = n;
            n->parent = pivot;
            pivot->right = n;
        }
        void insert_case1(node *n)
        {
            if (n->parent->type == 3)
                n->color = 1;
            else
                insert_case2(n);
        }
        void insert_case2(node *n)
        {
            if (n->parent->color == 1)
                return; /* Tree is still valid */
            else
                insert_case3(n);
        }
        void insert_case3(node *n)
        {
            node *u = uncle(n), *g;

            if ((u != NULL) && (u->color == 0)) {
                // && (n->parent->color == 0) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
                n->parent->color = 1;
                u->color = 1;
                g = grandparent(n);
                g->color = 0;
                insert_case1(g);
            } else {
                insert_case4(n);
            }
        }
        void insert_case4(node *n)
        {
            node *g = grandparent(n);

            if ((n == n->parent->right) && (n->parent == g->left)) {
                rotate_left(n->parent);

                /*
                 * rotate_left может быть выполнен следующим образом, учитывая что уже есть *g =  grandparent(n)
                 *
                 * node *saved_p=g->left, *saved_left_n=n->left;
                 * g->left=n;
                 * n->left=saved_p;
                 * saved_p->right=saved_left_n;
                 *
                 */

                n = n->left;
            } else if ((n == n->parent->left) && (n->parent == g->right)) {
                rotate_right(n->parent);

                /*
                 * rotate_right может быть выполнен следующим образом, учитывая что уже есть *g =  grandparent(n)
                 *
                 * node *saved_p=g->right, *saved_right_n=n->right;
                 * g->right=n;
                 * n->right=saved_p;
                 * saved_p->left=saved_right_n;
                 *
                 */

                n = n->right;
            }
            insert_case5(n);
        }
        void insert_case5(node *n)
        {
            node *g = grandparent(n);

            n->parent->color = 1;
            g->color = 0;
            if ((n == n->parent->left) && (n->parent == g->left)) {
                rotate_right(g);
            } else { /* (n == n->parent->right) && (n->parent == g->right) */
                rotate_left(g);
            }
        }
    public:
        explicit map(const key_compare &compare = key_compare(), const Alloc &alloc = allocator_type()): _alloc(alloc), _compare(compare), _size(0), _min(), _max(){
            _new_node();
        }
        std::pair<iterator,bool> insert(const value_type &val){
            int flag = 0;
            node *n = new node();
            n->key = val.first;
            n->vallue = val.second;
            n->color = 0;
            n->type = 1;
            if (_size == 0){
                _root->right = n;
                _end = new node();
                _head = new node();
                _head->type = 2;
                _head->color = 1;
                _head->parent = n;
                _end->parent = n;
                _head->left = _null_leaf;
                _head->right = _null_leaf;
                _end->color = 1;
                _end->type = 2;
                _end->left = _null_leaf;
                _end->right = _null_leaf;
                n->left = _head;
                n->right = _end;
                n->color = 1;
                n->parent = _root;
                _min = n->key;
                _max = n->key;
                _size++;
            }
            else {
                node *tmp = this->_root->right;
                while(tmp->type == 1) {
                    if (_compare(n->key, tmp->key)) {
                        flag = 1;
                        if (tmp->left->type == 1)
                            tmp = tmp->left;
                        else
                            break;
                    } else if (_compare(tmp->key, n->key)) {
                        flag = 2;
                        if (tmp->right->type == 1)
                            tmp = tmp->right;
                        else
                            break;
                    } else {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 2){
                    tmp->right = n;
                    n->parent = tmp;
                }else if (flag == 1){
                    tmp->left = n;
                    n->parent = tmp;
                } else{
                    delete n;
                    return std::pair<iterator, bool>(iterator(tmp), false);
                }
                n->left = _null_leaf;
                n->right = _null_leaf;
                if (n->key > _max) {
                    n->right = _end;
                    _end->parent = n;
                    _max = n->key;

                }
                else if (n->key < _min){
                    _head->parent = n;
                    n->left = _head;
                    _min = n->key;
                }
                insert_case1(n);
            }
            return std::pair<iterator, bool>(iterator(n), false);
        }
        iterator begin(){
            return iterator(_head->parent);
        }
        iterator end(){
            return iterator(_end);
        }
    };

}
#endif //MAP_HPP
