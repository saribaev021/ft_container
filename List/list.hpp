//
// Created by Kanat Saribaew on 1/5/21.
//

#ifndef LIST_HPP
#define LIST_HPP
#include "Node.hpp"
#include <cstddef>
#include <limits>
#include "../Iterator/Iterator.hpp"
//#include "Sfinae.hpp"
namespace ft {

    template<class T, class Alloc = std::allocator<T> >
    class list {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef  typename allocator_type::const_reference const_reference;
        typedef  typename allocator_type::pointer pointer;
        typedef  typename allocator_type::const_pointer const_pointer;
        typedef ptrdiff_t  difference_type;
        typedef size_t  size_type;
        typedef SimpleListIterator<value_type> iterator;
        typedef ConstListIterator<value_type> const_iterator;
        typedef reverse_iterator<const_iterator> const_reverse_iterator;
        typedef reverse_iterator<iterator> reverse_iterator;
    private:
        Alloc _alloc;
        std::allocator<t_node<T> > _base_alloc;
        size_type _size;
        t_node<value_type> *head;
        t_node<value_type> *tail;
//        t_node<value_type> *list_node;
//        t_node<value_type> *front_list;
//        t_node<value_type> *back_list;
        template<typename TYPE>
        void _swap(TYPE &a, TYPE &b)
        {
            TYPE tmp = a;
            a = b;
            b = tmp;
        }

        void list_new()
        {
            this->head = _base_alloc.allocate(1);
            this->tail = _base_alloc.allocate(1);
//            this->list_node = new t_node<T>();
//            this->list_node->next = nullptr;
//            this->list_node->prev= nullptr;
//            this->front_list = list_node;
//            this->back_list = list_node;
            head->prev = nullptr;
            head->next = tail;
            tail->prev = this->head;
            tail->next = nullptr;
        }
        static bool compare(value_type &val1, value_type &val2)
        {
            if (val2 < val1)
                return true;
            return false;
        }
        void _insert(iterator position, iterator val)
        {

            val.ptr_node()->next = position.ptr_node();
            val.ptr_node()->prev = position.ptr_node()->prev;
            position.ptr_node()->prev->next = val.ptr_node();
            position.ptr_node()->prev = val.ptr_node();
            this->_size++;
        }
        iterator _erase(iterator position)
        {
            t_node<value_type> *tmp;
            t_node<value_type> *tmp2;
            tmp = position.ptr_node();
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            tmp2 = tmp->next;
            this->_size--;
            return (iterator(tmp2));
        }
    public:
        explicit list(const allocator_type &alloc = allocator_type()) : _size(0)
        {
            (void)alloc;
            this->list_new();
        }

        explicit list(size_type n, const value_type& val = value_type(), const allocator_type &alloc = allocator_type()) : _size(0)
        {
            (void)alloc;
            this->list_new();
            assign(n, val);
        }

        template<class InputIterator>
        list(InputIterator first, InputIterator last, typename InputIterator::iterator_category* = nullptr, const allocator_type &alloc = allocator_type()) : _size(0)
        {
            (void)alloc;
            this->list_new();
            assign(first, last);

        }
        list(const list &other) : _size(0)
        {
            this->list_new();
            this->assign(other.begin(), other.end());
        }
        list &operator = (const list &other)
        {
            if (this == &other)
                return *this;
            this->clear();
            _base_alloc.deallocate(this->head, 1);
            _base_alloc.deallocate(this->tail, 1);
            this->list_new();
            this->assign(other.begin(), other.end());
            return  (*this);
        }
        iterator begin()
        {
            return (iterator(this->head->next));
        }
        const_iterator  begin() const
        {
            return (const_iterator(this->head->next));
        }
        iterator end()
        {
            return (iterator(this->tail));
        }
        const_iterator end() const
        {
            return (const_iterator(this->tail));
        }
        reverse_iterator rbegin()
        {
            return (reverse_iterator(iterator(this->tail->prev)));
        }
        const_reverse_iterator rbegin() const
        {
            return ( const_reverse_iterator(const_iterator(this->tail->prev)));
        }
        reverse_iterator rend()
        {
            return (reverse_iterator(iterator(this->head)));
        }
        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(const_iterator(this->head)));
        }

        bool empty() const
        {
            if (_size == 0)
                return true;
            return false;
        }
        size_type size() const
        {
            return  this->_size;
        }
        size_type max_size() const
        {
            return std::numeric_limits<size_type>::max() / sizeof(t_node<value_type>);
        }
        void pop_back()
        {
            if(this->_size == 0)
                return;
            t_node<value_type> *tmp;
            tmp = this->tail->prev->prev;
            delete this->tail->prev;
            this->tail->prev = tmp;
            this->tail->prev->next = tail;
            this->_size--;
        }
        void pop_front()
        {
            if (this->_size == 0)
                return;
            t_node<value_type> *tmp;
            tmp = this->head->next->next;
            delete this->head->next;
            this->head->next = tmp;
            tmp->prev = this->head;
            this->head->prev = nullptr;
            this->_size--;
        }
        void push_back(const value_type &val)
        {
            t_node<value_type> *tmp = this->tail->prev;
            this->tail->prev = new t_node<value_type>(val);
            tail->prev->next = this->tail;
            tail->prev->prev = tmp;
            tmp->next = tail->prev;
            this->_size++;
        }
        void push_front(const value_type &val)
        {
            t_node<value_type> *tmp = new t_node<value_type>(val);
            tmp->next = this->head->next;
            tmp->prev = this->head;
            this->head->next->prev = tmp;
            this->head->next = tmp;
            this->_size++;
        }
        void clear()
        {
            for (size_type i = 0; _size != 0; ++i) {
                pop_front();
            }
        }

        reference front()
        {
            return  (this->head->next->data);
        }
        reference back()
        {
            return  (this->tail->prev->data);
        }
        const_reference back() const
        {
            return  (this->tail->prev->data);
        }
        const_reference front() const
        {
            return  (this->list_node->data);
        }
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last, typename InputIterator::iterator_category* = nullptr)
        {
            this->clear();
            for (;  first != last; ++first) {
                push_back(*first);
            }
        }
        void assign(size_type n, const value_type &val)
        {
            this->clear();
            for (size_type i = 0;  i < n ; ++i) {
                push_back(val);
            }
        }
       iterator insert(iterator position, const value_type &val)
        {

            if (position == this->begin()){
                this->push_front(val);
                return (this->begin());
            }
            else if (position == this->end())
            {
                this->push_back(val);
                return (this->end());
            }
            t_node<value_type> *tmp = new t_node <value_type>(val);
            tmp->next = position.ptr_node();
            tmp->prev = position.ptr_node()->prev;
            tmp->prev->next = tmp;
            tmp->next->prev = tmp;
            this->_size++;
            return (iterator(tmp));
        }
        void insert(iterator position, size_type n, const value_type &val)
        {
            for (size_type i = 0; i != n; ++i)
            {
                this->insert(position, val);
            }
        }
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last, typename InputIterator::iterator_category* = nullptr)
        {

            for (; first != last; ++first)
            {
                this->insert(position, *first);
            }
        }
        iterator erase(iterator position)
        {
            t_node<value_type> *tmp;
            t_node<value_type> *tmp2;
            tmp = position.ptr_node();
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            tmp2 = tmp->next;
            delete tmp;
            this->_size--;
            return (iterator(tmp2));
        }
        iterator erase(iterator first, iterator last)
        {
            iterator it;
            for(; first != last; ++first)
                it = this->erase(first);
            return it;
        }
        void resize (size_type n, value_type val = value_type ())
        {
            if (n < this->_size)
            {
                iterator it = --this->end();
                for (; this->_size != n && this->_size != 0;) {
                    it = this->erase(it);
                    --it;
                }
            }
            else{
                for (size_type i = 0; i < n; ++i) {
                    this->push_back(val);
                }
            }
        }
        void splice(iterator position, list &x)
        {
            iterator it = x.begin();
            for (; it!= x.end();) {

                iterator tmp = x._erase(it);
                this->_insert(position, it);
                it = tmp;
            }
        }
        void splice(iterator position, list &x, iterator i)
        {
            x._erase(i);
            this->_insert(position, i);
        }
        void splice(iterator position, list &x, iterator first, iterator last)
        {
            for (; first != last;) {
                iterator tmp = x._erase(first);
                this->_insert(position, first);
                first = tmp;
            }
        }
        void remove(const value_type &val)
        {
            iterator it = this->begin();
            for (;  it != this->end(); ++it) {
                if (*it == val)
                {
                    it = this->erase(it);
                    --it;
                }
            }
        }
        template <class Predicate>
        void remove_if (Predicate pred)
        {
            iterator it = this->begin();
            for (;  it != this->end(); ++it) {
                if (pred(*it)) {
                    it = this->erase(it);
                    --it;
                }
            }
        }
        void unique()
        {
            iterator it = this->begin();
            iterator it2 = this->begin();
            ++it2;
            for (;  it != this->end() && it2 != this->end(); ++it, ++it2) {
                while (*it == *it2) {
                    it2 = this->erase(it2);

//                    --it2;
                }
//                ++it2;
            }
        }
        template <class BinaryPredicate>
        void unique (BinaryPredicate binary_pred)
        {
            iterator it = this->begin();
            iterator it2 = this->begin();
            ++it2;
            for (;  it != this->end(); ++it) {
                if (binary_pred(*it2, *it))
                    it2 = this->erase(it2);
                ++it2;
            }
        }
        void merge(list &x)
        {
            if (&x == this)
                return;
            this->merge(x, compare);

        }

        template<class Compare>
        void merge(list &x, Compare comp)
        {
            if (&x == this)
                return;
            iterator it = this->begin();
            iterator it1 = x.begin();
            iterator tmp;
            for (; it != this->end(); ++it)
            {
                while(comp(*it, *it1) && it1 != x.end())
                {
                    tmp = x._erase(it1);
                    this->_insert(it, it1);
                    it1 = tmp;
                }
            }
            if (it1 != x.end())
                this->splice(it, x, it1, x.end());
        }
        template <class Compare>
        void sort(Compare comp)
        {
            if (this->_size == 1)
                return;
            for (size_type i = 0; i < this->_size; ++i) {
                t_node<value_type> *current =  this->head->next;
                for (;  current->next != this->tail && current != this->tail ; current = current->next) {
                    if (comp(current->data, current->next->data))
                    {
                        t_node<value_type> *next = current->next;
                        t_node<value_type> *prev = current->prev;
                        current->next = next->next;
                        next->next->prev = current;
                        next->prev = prev;
                        next->next = current;
                        current->prev = next;
                        prev->next = next;
                    }
                }
            }
        }
        void sort()
        {
            this->sort(compare);
        }
        void reverse()
        {
            if (this->_size == 1)
                return;
            t_node<value_type> *current =  this->head->next;
            t_node<value_type> *next = current->next;
            for (;  current != this->tail ; current = current->prev) {
                current->next = current->prev;
                current->prev = next;
                next = next->next;
            }
            current->next = current->prev;
            current->prev = next;
            this->tail = this->head;
            this->head = current;
        }

        void swap(list &x)
        {
            _swap(this->head, x.head);
            _swap(this->tail, x.tail);
            _swap(this->_alloc, x._alloc);
            _swap(this->_size, x._size);
        }
        friend void swap(list &x, list &y);
        ~list(){
            this->clear();
            _base_alloc.deallocate(this->head, 1);
            _base_alloc.deallocate(this->tail, 1);
        };
    };

    template <class T, class Alloc>
    bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        typename ft::list<T, Alloc>::const_iterator lit = lhs.begin();
        typename ft::list<T, Alloc>::const_iterator rit = rhs.begin();
        for (; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
        {
            if (*lit != *rit)
                return false;
        }
        if (lit == lhs.end() && rit == rhs.end())
            return true;
        return false;
    }
    template <class T, class Alloc>
    bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>
    bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        typename ft::list<T, Alloc>::const_iterator lit = lhs.begin();
        typename ft::list<T, Alloc>::const_iterator rit = rhs.begin();
        for (; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
        {
            if (*lit != *rit)
            {
                return (*lit < *rit);
            }
        }
        if (rit == rhs.end())
            return false;
        return true;
    }
    template <class T, class Alloc>
    bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class T, class Alloc>
    bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return rhs < lhs;
    }
    template <class T, class Alloc>
    bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }
    template <class T, class Alloc>
    void swap (list<T,Alloc>& x, list<T,Alloc>& y)
    {
        x.swap(y);
    }
}
//template <class T, class Alloc = allocator<T>>
//list<T, Alloc = allocator<T>>::list<class T, class Alloc = allocator<T>>() {
//    this->_size = 0;
//    this->_max_size = 0;
//    this->list_node = a;
//}

#endif //LIST_HPP
