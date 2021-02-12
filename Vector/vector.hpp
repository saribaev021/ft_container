//
// Created by Kanat Saribaew on 2/3/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <cstddef>
#include <limits>
//#include <string.h>
#include "../Iterator/Iterator.hpp"
namespace ft {
    template<class T, class Alloc = std::allocator<T> >
    class vector {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef VectorIterator<value_type> iterator;
        typedef VectorIterator<value_type const> const_iterator;
        typedef reverse_iterator<const_iterator> const_reverse_iterator;
        typedef reverse_iterator<iterator> reverse_iterator;
    private:
        std::allocator<T> _alloc;
        size_type _size;
        size_type _capacity;
        value_type *_arr;
        value_type *_new_arr(size_type count = 1) {
            if (count > this->max_size())
                throw std::length_error("length_error");
            return _alloc.allocate(count);
        }

        template<typename TYPE>
        void _swap(TYPE &a, TYPE &b)
        {
            TYPE tmp = a;
            a = b;
            b = tmp;
        }
        template<class IT>
        size_type distance(IT first, IT last){
            size_type  i = 0;
            for (; first != last ; ++first) {
                ++i;
            }
            return i;
        }
        void _copy(value_type *dst, value_type *src, size_type size){
            if (dst > src)
            {
                while (size-- > 0)
                {
                    this->_alloc.construct(&dst[size], src[size]);
                }
            } else{
                for (size_type i = 0;  i < size ; ++i) {
                    this->_alloc.construct(&dst[i], src[i]);
                }
            }
        }
        void _realoc(size_type capacity) {

            value_type *tmp = this->_new_arr(capacity);
            size_type i = this->_size;
            this->_copy(tmp, this->_arr, this->_size);
            this->clear();
            this->_arr = tmp;
            this->_size = i;
            this->_capacity = capacity;
        }
    public:
        explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0) {
            this->_arr = this->_new_arr();
        }
        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(0),  _capacity(0) {
            this->assign(n, val);
        }
        template<class InputIterator>
        vector(InputIterator first, InputIterator last, typename InputIterator::iterator_category* = nullptr, const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0){
            this->assign(first, last);
        }
        vector(const vector &other) : _alloc(other._alloc), _size(0), _capacity(0) {
            this->_arr =  _new_arr(other._capacity);
            this->_size = 0;
            this->_capacity = other._capacity;
            this->assign(other.begin(), other.end());
        }

        vector &operator=(const vector &other) {
            if (this == &other)
                return *this;
            this->clear();
            this->_arr =  _new_arr(other._capacity);
            this->_size = 0;
            this->_capacity = other._capacity;
            this->assign(other.begin(), other.end());
            return *this;
        }
        iterator begin() {
            return iterator(this->_arr);
        }
        const_iterator begin() const {
            return const_iterator(this->_arr);
        }
        iterator end() {
            return (iterator(this->_arr + this->_size));
        }

        const_iterator end() const {
            return (const_iterator(this->_arr + this->_size));
        }

        reverse_iterator rbegin() {
            return (reverse_iterator(--this->end()));
        }

        const_reverse_iterator rbegin() const {
            return (const_reverse_iterator(--this->end()));
        }

        reverse_iterator rend() {
            return (reverse_iterator(this->_arr - 1));
        }

        const_reverse_iterator rend() const {
            return (const_reverse_iterator(this->_arr - 1));
        }

        bool empty() const {
            if (_size == 0)
                return true;
            return false;
        }

        size_type size() const {
            return this->_size;
        }
        size_type capacity() const {
            return this->_capacity;
        }

        size_type max_size() const {
            return std::numeric_limits<size_type>::max() / sizeof(value_type);
        }

        void push_back(const value_type &val) {
            if (this->_capacity == 0 || this->_size == this->_capacity) {
                this->_realoc(this->_capacity >= 4 ? this->_capacity * 2 : this->_capacity + 1);
                this->_alloc.construct(this->_arr + this->_size, val);
                ++this->_size;
                return;
            } else {
                this->_alloc.construct((this->_arr + this->_size), val);
                ++this->_size;
            }
        }
        void pop_back(){
            _alloc.destroy(this->_arr + this->_size - 1);
            this->_size--;
        }
        void clear() {
            for (size_type i = 0; i != this->_size; ++i){
                _alloc.destroy(this->_arr + i);
            }
            _alloc.deallocate(this->_arr, this->_capacity);
            this->_size = 0;
            this->_capacity = 0;
        }
        void resize (size_type n, value_type val = value_type()){
            if (n < this->_size) {
                for (size_type i = this->_size - 1; i != n; --i) {
                    this->_alloc.destroy(this->_arr + i);
                }
                this->_size = n;
            }else if (n > this->_capacity){
                this->_realoc(n > this->_capacity * 2 ? n : this->_capacity * 2);
                for (; this->_size != n; ++this->_size){
                    this->_alloc.construct(this->_arr + this->_size, val);
                }
            }
        }
        void reserve (size_type n){
            if (n <= this->_capacity)
                return;
            this->_realoc(n);
        }
        void assign(size_type n, const value_type &val) {
            if (this->_size)
                clear();
            this->_arr =  _new_arr(n);
            this->_capacity = n;
            for (size_type i = 0; i != n; ++i)
                this->push_back(val);
        }
        template<class InputIterator>
        void assign(InputIterator first, InputIterator last, typename InputIterator::iterator_category * = nullptr) {
            if (this->_size)
                this->clear();
            size_type n = this->distance(first, last);
            this->_arr = this->_new_arr(n);
            this->_capacity = n;
            for (;first != last; ++first)
                this->push_back(*first);
        }
        iterator insert(iterator position, const value_type &val){
            difference_type difference_begin = position - this->begin();
            this->insert(position, 1, val);
            return iterator(this->_arr + difference_begin);
        }
        void insert (iterator position, size_type n, const value_type& val){
             difference_type difference_end = this->end() - position;
             difference_type difference_begin = position - this->begin();
             if (this->_size + n <  _capacity) {
                 this->_copy(this->_arr + difference_begin + n, this->_arr + difference_begin, difference_end + n);
                 for (size_type i = 0; i != n; ++i){
                     this->_alloc.construct(this->_arr + difference_begin + i, val);
                     this->_size++;
                 }
             }else{
                 value_type *tmp = this->_new_arr(_capacity == 0 ? n : _capacity * 2);
                 this->_copy(tmp, this->_arr, difference_begin);
                 size_type i = 0;
                 for (; i != n; ++i){
                     this->_alloc.construct(tmp + difference_begin + i, val);
                 }
                 this->_copy(tmp + difference_begin + n, this->_arr + difference_begin, difference_end);
                 i += _size;
                 this->clear();
                 this->_size = i;
                 this->_capacity = _capacity == 0 ? n : _capacity * 2;
                 this->_arr = tmp;
             }
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, typename InputIterator::iterator_category * = nullptr){
            difference_type difference_end = this->end() - position;
            difference_type difference_begin = position - this->begin();
            size_type n = distance(first, last);
            if (_size + n < _capacity)
            {
                this->_copy(this->_arr + difference_begin + n, this->_arr + difference_begin, difference_end + n);
                for (size_type i = 0; first != last; ++first, ++i){
                    this->_alloc.construct(this->_arr + difference_begin + i, *first);
                    this->_size++;
                }
            }else{
                value_type *tmp = this->_new_arr(_capacity == 0 ? n : _capacity * 2);
                this->_copy(tmp, this->_arr, difference_begin);
                size_type i = 0;
                for (; first != last; ++first, ++i){
                    this->_alloc.construct(tmp + difference_begin + i, *first);
                }
                this->_copy(tmp + difference_begin + n, this->_arr + difference_begin, difference_end);
                i += _size;
                this->clear();
                this->_size = i;
                this->_capacity = _capacity == 0 ? n : _capacity * 2;
                this->_arr = tmp;
            }
        }
        iterator erase (iterator position){
            difference_type difference_end = this->end() - position;
            difference_type difference_begin = position - this->begin();
            _alloc.destroy(_arr + difference_begin);
            this->_copy(_arr + difference_begin, _arr + difference_begin + 1, difference_end);
            this->_size--;
            return iterator(_arr + difference_begin);
        }
        iterator erase (iterator first, iterator last){
            difference_type difference_begin = first - this->begin();
            difference_type difference_end = this->end() - last;
            size_type  n = 0;
            for (; first != last; ++first, ++n){
                _alloc.destroy(_arr + difference_begin + n);
            }
            this->_copy(_arr + difference_begin, _arr + n, difference_end);
            this->_size -= n;
            return iterator(_arr + difference_end);
        }
        void swap (vector& x){
            _swap(this->_arr, x._arr);
            _swap(this->_size, x._size);
            _swap(this->_capacity, x._capacity);
            _swap(this->_alloc, x._alloc);
        }
        reference operator[](size_type n){
            return this->_arr[n];
        }
        const_reference operator[](size_type n) const{
            return this->_arr[n];
        }
        reference at (size_type n){
            if (n >= this->_size || n < 0)
                throw std::out_of_range("out of range");
            return this->_arr[n];
        }
        const_reference at (size_type n) const{
            if (n >= this->_size || n < 0)
                throw std::out_of_range("out of range");
            return this->_arr[n];
        }
        reference front(){return *this->_arr;}
        const_reference front() const{return *this->_arr;}
        reference back(){return this->_arr[this->_size - 1];}
        const_reference back() const{return this->_arr[this->_size - 1];}
        friend void swap(vector &x, vector &y);
        ~vector()
        {
            this->clear();
        }
    };
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        typename ft::vector<T, Alloc>::const_iterator lit = lhs.begin();
        typename ft::vector<T, Alloc>::const_iterator rit = rhs.begin();
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
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        typename ft::vector<T, Alloc>::const_iterator lit = lhs.begin();
        typename ft::vector<T, Alloc>::const_iterator rit = rhs.begin();
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
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return rhs < lhs;
    }
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}
#endif //VECTOR_HPP
