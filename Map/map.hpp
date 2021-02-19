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
		class value_compare: public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};
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
        typedef tree<key_type, mapped_type> node;
        allocator_type _alloc;
        node *_head;
        node *_root;
        node *_end;
        node *_null_leaf;
        key_compare _compare;
        size_type _size;
        key_type _min;
        key_type _max;

		template<typename TYPE>
		void _swap(TYPE &a, TYPE &b)
		{
			TYPE tmp = a;
			a = b;
			b = tmp;
		}
        void _new_node(){
            _root = new node();
            _null_leaf = new node();
			_end = new node();
			_head = new node();
			_head->type = 2;
			_head->color = 1;

			_end->color = 1;
			_end->type = 2;

			_head->left = _null_leaf;
			_head->right = _null_leaf;
			_end->left = _null_leaf;
			_end->right = _null_leaf;

			_head->parent = _root;
			_end->parent = _root;

            _root->type = 3;
			_root->left = _null_leaf;
			_root->right = _null_leaf;

            _null_leaf->type = 0;
            _null_leaf->color = 1;
        }
        void change_head_begin(node *n){
			if (n->key == _min){
				_min = n->parent->key;
				_head->parent = n->parent;
				n->parent->left = _head;
			}
			if (n->key == _max){
				_max = n->parent->key;
				_end->parent = n->parent;
				n->parent->right = _end;
			}
        }
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
                return NULL;
            if (n->parent == g->left)
                return g->right;
            else
                return g->left;
        }
        void rotate_left(node *n)
        {
            node *pivot = n->right;

            pivot->parent = n->parent;
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

            pivot->parent = n->parent;
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
                return;
            else
                insert_case3(n);
        }
        void insert_case3(node *n)
        {
            node *u = uncle(n), *g;
            if ((u != NULL) && (u->color == 0)) {
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
                n = n->left;
            } else if ((n == n->parent->left) && (n->parent == g->right)) {
                rotate_right(n->parent);
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
            } else {
                rotate_left(g);
            }
        }

		void replace_node(node* n, node* child) {
			child->parent = n->parent;
			if (n == n->parent->left) {
				n->parent->left = child;
			} else {
				n->parent->right = child;
			}
		}
		node *sibling(node *n)
		{
			if (n == n->parent->left)
				return n->parent->right;
			else
				return n->parent->left;
		}
		void
		delete_case1(node *n)
		{
			if (n->parent->type == 1)
				delete_case2(n);
		}
		void delete_case2(node *n)
		{
			node *s = sibling(n);

			if (s->color == 0) {//red
				n->parent->color = 0;//red
				s->color = 1;//black
				if (n == n->parent->left)
					rotate_left(n->parent);
				else
					rotate_right(n->parent);
			}
			delete_case3(n);
		}
		void delete_case3(node *n)
		{
			node *s = sibling(n);

			if ((n->parent->color == 1) &&//black
				(s->color == 1) &&//black
				(s->left->color == 1) &&//black
				(s->right->color == 1)) {//black
				s->color = 0;//red
				delete_case1(n->parent);
			} else
				delete_case4(n);
		}
		void delete_case4(node *n)
		{
			node *s = sibling(n);

			if ((n->parent->color == 0) &&//red
				(s->color == 1) &&//black
				(s->left->color == 1) &&//black
				(s->right->color == 1)) {//black
				s->color = 0;//red
				n->parent->color = 1;//black
			} else
				delete_case5(n);
		}
		void delete_case5(node *n)
		{
			node *s = sibling(n);

			if  (s->color == 1) {//black
				if ((n == n->parent->left) &&
					(s->right->color == 1) &&//black
					(s->left->color == 0)) {//red
					s->color = 0;//red
					s->left->color = 1;//black
					rotate_right(s);
				} else if ((n == n->parent->right) &&
						   (s->left->color == 1) &&//black
						   (s->right->color == 0)) {//red
					s->color = 0;//red
					s->right->color = 1;//black
					rotate_left(s);
				}
			}
			delete_case6(n);
		}
		void delete_case6(node *n)
		{
			node *s = sibling(n);
			s->color = n->parent->color;
			n->parent->color = 1;//black
			if (n == n->parent->left) {
				s->right->color = 1;//black
				rotate_left(n->parent);
			} else {
				s->left->color = 1;//black
				rotate_right(n->parent);
			}
		}
		void delete_node(node *n){
			node *parent = n->parent;
			if (parent->right == n)
				parent->right = _null_leaf;
			else  if (parent->left == n)
				parent->left = _null_leaf;
			delete n;
		}
//		void delete_one(node *n) {
////			node *parent = n->parent;
////			if (parent->type == 3) {
////				delete _end;
////				delete _head;
////				_end = parent;
////				_head = parent;
////			} else if (n->color == 0) {
////				delete_node(n);
////			} else{
//				delete_case1(n);
//				delete_node(n);
////			}
//		}

		void delete_one(node *n)
		{
			node *child = n;
			if (n->right->type == 1 || n->left->type == 1){
				child = n->right->type != 1 ? n->left : n->right;
				replace_node(n, child);
			}
			if (n->color == 1) {
				if (child->color == 0)
					child->color = 1;
				else
					delete_case1(child);
			}
			delete_node(n);
		}

	public:
        explicit map(const key_compare &compare = key_compare(), const Alloc &alloc = allocator_type()): _alloc(alloc), _compare(compare), _size(0), _min(), _max(){
            _new_node();
        }
		map(const map &x): _alloc(x._alloc), _compare(x._compare), _size(x._size), _min(x._min), _max(x._max){
			_new_node();
			_root->right = x._root->right;
			_head->parent = x._head->parent;
			_end->parent = x._end->parent;
		}

		template<class InputIterator>
		map(InputIterator first, InputIterator last, typename InputIterator::iterator_category* = nullptr, key_compare &compare = key_compare(), const Alloc &alloc = allocator_type()): _alloc(alloc), _compare(compare), _size(0), _min(), _max(){
			_new_node();
			insert(first, last);
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
                _head->parent = n;
                _end->parent = n;
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
                _size++;
            }
            return std::pair<iterator, bool>(iterator(n), true);
        }
		iterator insert(iterator position, const value_type &val){(void)position; return (insert(val).first);}
		template<class InputIterator>
        void insert(InputIterator first, InputIterator last, typename InputIterator::iterator_category* = nullptr){
        	for (; first != last; ++first){
        		insert(*first);
        	}
        }
        iterator begin(){
            return iterator(_head->parent);
        }
        node *max_node(node *n){
			while (n->right->type == 1)
				n = n->right;
			return n;
        }
		node *min_node(node *n){
			while (n->left->type == 1)
				n = n->left;
			return n;
		}
        iterator end(){
            return iterator(_end);
        }
        void erase(iterator position){
			iterator it = position;
			node *n = it.ptr_node;
			node *descendant = nullptr;
			if (n->type == 1 && n->left->type == 1)
				descendant = max_node(n->left);
			else if (n->type == 1 && n->right->type == 1)
				descendant = min_node(n->right);
			if (descendant)
			{
				_swap(n->key, descendant->key);
				_swap(n->vallue, descendant->vallue);
				delete_one(descendant);
				change_head_begin(descendant);
				_size--;

			} else{
				delete_one(n);
				change_head_begin(n);
				_size--;
			}

		}
        size_type erase(const key_type &k){
        	iterator it = finde(k);
        	if (it != end())
        		this->erase(it);
			return _size;
        }
        void erase(iterator first, iterator last){
        	for (; first != last; ++first){
        		erase(first);
        	}
        }
		value_compare value_comp() const{
			return value_compare(_compare);
		}
		key_compare key_comp() const{
			return _compare;
		}
		size_type count(const key_type &k)const{
			if (finde(k) == end())
				return 0;
			return 1;
		}
		iterator upper_bound(const key_type &k){
			node *tmp = _root->right;
			while(tmp->type == 1){
				if (_compare(k, tmp->key)){
					tmp = tmp->left;
				}else if (_compare(tmp->key, k)){
					tmp = tmp->right;
				}else{
					if (tmp->right == _end)
						return iterator (tmp->right);
					else if (tmp->right->type == 1)
						return tmp->right;
					else{
						tmp = tmp->parent;
						while (_compare(tmp->key, k))
							tmp = tmp->parent;
						return tmp;
					}
				}
			}
			if (tmp == _end)
				return iterator(_end);
			return iterator (tmp->parent);
		}
		iterator upper_bound(const key_type &k) const{
			node *tmp = _root->right;
			while(tmp->type == 1){
				if (_compare(k, tmp->key)){
					tmp = tmp->left;
				}else if (_compare(tmp->key, k)){
					tmp = tmp->right;
				}else{
					if (tmp->right == _end)
						return iterator (tmp->right);
					else if (tmp->right->type == 1)
						return tmp->right;
					else{
						tmp = tmp->parent;
						while (_compare(tmp->key, k))
							tmp = tmp->parent;
						return tmp;
					}
				}
			}
			if (tmp == _end)
				return iterator(_end);
			return iterator (tmp->parent);
		}
		iterator lower_bound(const key_type &k){
			node *tmp = _root->right;
			while(tmp->type == 1){
				if (_compare(k, tmp->key)){
					tmp = tmp->left;
				}else if (_compare(tmp->key, k)){
					tmp = tmp->right;
				}else{
					return iterator (tmp);
				}
			}
			if (tmp == _end)
				return iterator(_end);
			return iterator (tmp->parent);
		}
		iterator lower_bound(const key_type &k) const{
			node *tmp = _root->right;
			while(tmp->type == 1){
				if (_compare(k, tmp->key)){
					tmp = tmp->left;
				}else if (_compare(tmp->key, k)){
					tmp = tmp->right;
				}else{
					return const_iterator(tmp);
				}
			}
			if (tmp == _end)
				return const_iterator(_end);
			return const_iterator(tmp->parent);
		}
		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
			return std::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
		}
		std::pair<iterator,iterator>             equal_range (const key_type& k){
			iterator l = lower_bound(k);
			iterator u = upper_bound(k);
			return std::pair<const_iterator, const_iterator>(l, u);
		}
		iterator finde(const key_type &k){
			node *tmp = _root->right;
			while(tmp->type == 1){
				if (_compare(k, tmp->key)){
					tmp = tmp->left;
				}else if (_compare(tmp->key, k)){
					tmp = tmp->right;
				}else{
					return iterator (tmp);
				}
			}
			return iterator (_end);
		}
		size_type size()const{
			return _size;
		}
		void swap(map &x){
			_swap(this->_root, x._root);
			_swap(this->_head, x._head);
			_swap(this->_end, x._end);
			_swap(this->_null_leaf, x._null_leaf);
			_swap(this->_alloc, x._alloc);
			_swap(this->_size, x._size);
			_swap(this->_compare, x._compare);
			_swap(this->_max, x._max);
			_swap(this->_min, x._min);
		}
		void _clear(node *n){
			if (n->left->type == 1) {
				_clear(n->left);
			}
			if (n->right->type == 1){
				_clear(n->right);
			}
			delete_node(n);
		}
		void clear(){
			node *n = _root->right;
			_clear(n);
			_size = 0;
		}
		mapped_type &operator[](const key_type &k){
			return (*insert(std::pair<key_type, mapped_type>(k, mapped_type())).first).second;
		}
		int print(int deep, int new_line ,node *p)
		{
			if(p->type == 1)
			{
				print(deep + 1, new_line,p->right);
				if (p->parent->type == 1)
					std::cout << p->parent->key;
				if (p->color == 1)
					std::cout << GREEN;
				else if(p->color == 0)
					std::cout << RED;
				for ( int i = 0; i < deep; i ++ )
					std::cout<< "    ";
				if (p->type == 1)
					std::cout << p->key<< RESET<<"\n";
				print(deep + 1,new_line, p->left);
			}
			std::cout << RESET;
			return (0);
		}
		void show(){
        	std::cout <<this->_root->right->key<<std::endl;
        	this->print(10, 25,this->_root->right);
        }
    };

}
#endif //MAP_HPP
