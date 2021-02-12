//
// Created by Kanat Saribaew on 2/6/21.
//

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "../List/Node.hpp"
#include "../Map/Tree.hpp"
namespace ft{
    struct iterator_tag{};
    template<typename T>
    class ListIterator {
    protected:
        t_node<T> *list_node;
    public:
        ListIterator(): list_node(nullptr){};
        ListIterator(t_node<T> *node): list_node(node) {
        }
        ListIterator(const ListIterator &other):list_node(other.list_node) {
        }
        virtual ~ListIterator() {}

        ListIterator &operator=(const ListIterator &other) {
            this->list_node = other.list_node;
            return *this;
        }
        ListIterator operator++(int)//postfix i++
        {
            ListIterator<T> tmp = *this;
            this->list_node = this->list_node->next;
            return (tmp);
        }
        ListIterator &operator--(int)//postfix i--
        {
            ListIterator<T> tmp = *this;
            this->list_node = this->list_node->prev;
            return (tmp);
        }
        ListIterator &operator++()//prefix ++i
        {
            this->list_node = this->list_node->next;
            return (*this);
        }
        ListIterator &operator--()//prefix --i
        {
            this->list_node = this->list_node->prev;
            return (*this);
        }
        bool operator!=(const ListIterator &other) const {
            if (this->list_node != other.list_node)
                return (true);
            return (false);
        }
        bool operator==(const ListIterator &other) const {
            if (this->list_node == other.list_node)
                return (true);
            return (false);
        }
        t_node<T> *ptr_node() const {

            return (this->list_node);
        }
    };
    template <typename T>
    class SimpleListIterator : public ListIterator<T>{
    public:
        typedef T value_type;
        typedef iterator_tag iterator_category;
        typedef value_type *pointer;
        typedef value_type &reference;
        typedef std::ptrdiff_t difference_type;
        SimpleListIterator(t_node<T> *node): ListIterator<T>(node){}
        virtual ~SimpleListIterator() {}
        SimpleListIterator(const ListIterator<T> &other) : ListIterator<T>(other) {}
        SimpleListIterator() : ListIterator<T>(){}
        pointer operator->() {
            return (&this->list_node->data);
        }
        reference operator*() {
            return (this->list_node->data);
        }
    };
    template <typename T>
    class ConstListIterator : public ListIterator<T>{
    public:
        typedef T value_type;
        typedef iterator_tag iterator_category;
        typedef value_type const *const_pointer;
        typedef value_type const &const_reference;
        typedef std::ptrdiff_t difference_type;

        ConstListIterator() : ListIterator<T>(){}

        ConstListIterator(const ListIterator<T> &other) : ListIterator<T>(other) {}

        virtual ~ConstListIterator() {}

        ConstListIterator(t_node <T> *node) : ListIterator<T>(node) {}

        const_reference operator*() const {
            return (this->list_node->data);
        }
        const_pointer operator->() const {
            return (&this->list_node->data);
        }
    };
    //--------------------------VECTOR ITERATOR-----------------------//
    template<typename T>
    class VectorIterator {
    public:
        typedef T value_type;
        typedef iterator_tag iterator_category;
        typedef value_type *pointer;
        typedef value_type &reference;
        typedef std::ptrdiff_t difference_type;
    private:
        T *arr;
    public:
        T *getArr() const {
            return arr;
        }
        VectorIterator(): arr(nullptr){};
        template<class TYPE>
        VectorIterator(const VectorIterator<TYPE> &other): arr(other.getArr()){}
        VectorIterator(const VectorIterator &other) :arr(other.arr){}
        VectorIterator(T *node): arr(node) {
        }
        virtual ~VectorIterator() {}
        VectorIterator &operator=(const VectorIterator &other) {
            this->arr = other.arr;
            return *this;
        }
        VectorIterator operator++(int)//postfix i++
        {
            VectorIterator<T> tmp = *this;
            ++this->arr;
            return (tmp);
        }
        VectorIterator operator--(int)//postfix i--
        {
            VectorIterator<T> tmp = *this;
            --this->arr;
            return (tmp);
        }
        VectorIterator &operator++()//prefix ++i
        {
            ++this->arr;
            return (*this);
        }
        VectorIterator &operator--()//prefix --i
        {
            --this->arr;
            return (*this);
        }
        VectorIterator operator +(difference_type n) const
        {
            return (VectorIterator(this->arr + n));
        }
        VectorIterator operator - (difference_type n) const{
            return (VectorIterator(this->arr - n));
        }
        VectorIterator &operator +=(int n)
        {
            this->arr += n;
            return (*this);
        }
        VectorIterator &operator -=(int n)
        {
            this->arr -= n;
            return (*this);
        }
        difference_type operator - (const VectorIterator it) const{
            return (this->arr - it.arr);
        }
        pointer operator->() const{
            return ((*this->arr));
        }
        reference operator*() const{
            return (*this->arr);
        }
        reference operator[](difference_type n) const {return this->arr[n];}
        bool operator!=(const VectorIterator &other) const {
            if (this->arr != other.arr)
                return (true);
            return (false);
        }
        bool operator==(const VectorIterator &other) const {
            if (this->arr == other.arr)
                return (true);
            return (false);
        }
        bool operator < (const VectorIterator &other){
            return this->arr < other.arr;
        }
        bool operator > (const VectorIterator &other){
            return this->arr > other.arr;
        }
        bool operator <= (const VectorIterator &other){
            return this->arr <= other.arr;
        }
        bool operator >= (const VectorIterator &other){
            return this->arr >= other.arr;
        }

    };
    template <typename T>
    VectorIterator<T> operator +(int n, VectorIterator<T> it)
    {
        it += n;
        return (it);
    }
    //----------------------REVERSE ITERATOR--------------//
    template <typename _Iter>
    class reverse_iterator{
    public:
        typedef _Iter                                   iterator_type;
        typedef typename iterator_type::difference_type difference_type;
        typedef typename iterator_type::reference       reference;
        typedef typename iterator_type::pointer         pointer;
    protected:
        _Iter it;
    public:
        reverse_iterator(){it();}
        explicit reverse_iterator (iterator_type other) : it(other) {}
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it): it(rev_it){}
        virtual ~reverse_iterator() {}
        _Iter base() const {return  it;}
        reverse_iterator operator++(int)//postfix i++
        {
            _Iter tmp = it;
            --it;
            return (reverse_iterator(tmp));
        }
        reverse_iterator operator--(int)//postfix i--
        {
            _Iter tmp = it;
            ++it;
            return (reverse_iterator(tmp));
        }
        reverse_iterator &operator++()//prefix ++i
        {
            --it;
            return (*this);
        }
        reverse_iterator &operator--()//prefix --i
        {   ++it;
            return (*this);
        }
        reverse_iterator operator +(int n) const
        {
            return (reverse_iterator(this->it - n));
        }
        reverse_iterator operator - (int n) const{
            return (reverse_iterator(this->it + n));
        }
        reverse_iterator &operator +=(int n)
        {
            this->it -= n;
            return (*this);
        }
        reverse_iterator &operator -=(int n)
        {
            this->it += n;
            return (*this);
        }
        reference operator[](difference_type n){return *(*this + n);}
        pointer operator->() {
            return (&operator*());
        }
        reference operator*() {
            return (*this->it);
        }
    };
    template <typename _Iter>
    reverse_iterator<_Iter> operator +(int n, reverse_iterator<_Iter> it){it += n; return (it);}
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator - (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() - rhs.base();}
    template <class Iterator>
    //-----------------------------RELATIONAL OPERATORS-----------------------------//
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() == rhs.base();}
    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() != rhs.base();}
    template <class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() > rhs.base();}
    template <class Iterator>
    bool operator<=  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() >= rhs.base();}
    template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() < rhs.base();}
    template <class Iterator>
    bool operator>=  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() <= rhs.base();}
    template <typename K, typename V>
    class MapIterator{
    public:
        typedef std::pair<K, V> value_type;
        typedef iterator_tag iterator_category;
        typedef value_type *pointer;
        typedef value_type &reference;
        typedef std::ptrdiff_t difference_type;
    protected:
        tree<K, V> *ptr_node;
        std::pair<K, V>p;
    public:
        MapIterator(): ptr_node(nullptr),p(){}
        MapIterator(tree<K, V> *node): ptr_node(node),p(node->key, node->vallue) {}
        MapIterator(const value_type &val): ptr_node(val.first, val.second),p(val) {}
        MapIterator(const  MapIterator &other):ptr_node(other.ptr_node), p(other.p.first, other.p.second) {}
        virtual ~ MapIterator() {}

        MapIterator &operator=(const  MapIterator &other) {
            this->ptr_node = other.ptr_node;
            return *this;
        }
        MapIterator operator++(int)//postfix i++
        {
            MapIterator tmp = *this;
            if (ptr_node->right->type) {
                if (ptr_node->right->left->type && ptr_node->right->left->key > ptr_node->key) {
                    ptr_node = ptr_node->right;
                    while (ptr_node->left->type)
                        ptr_node = ptr_node->left;
                }else
                    ptr_node = this->ptr_node->right;
            }
            else if (ptr_node->parent->type && ptr_node->parent->key > ptr_node->key)
                ptr_node = this->ptr_node->parent;
            else if (ptr_node->parent->key < ptr_node->key){
                while (ptr_node->parent->type && ptr_node->parent->key < ptr_node->key)
                    ptr_node = ptr_node->parent;
            }
            return (tmp);
        }
        MapIterator &operator--(int)//postfix i--
        {
            MapIterator tmp = *this;
            if (ptr_node->left->type){
                if (ptr_node->left->right->type && ptr_node->left->right->key < ptr_node->key) {
                    ptr_node = ptr_node->left;
                    while (ptr_node->right->type)
                        ptr_node = ptr_node->right;
                } else
                    ptr_node = this->ptr_node->left;
            }
            else if (ptr_node->parent->type && ptr_node->parent->key < ptr_node->key)
                ptr_node = this->ptr_node->parent;
            else if (ptr_node->parent->key > ptr_node->key) {
                while (ptr_node->parent->type && ptr_node->parent->key > ptr_node->key)
                    ptr_node = ptr_node->parent;
            }
            return (tmp);
        }
        MapIterator &operator++()//prefix ++i
        {
            if (ptr_node->right->type) {
                if (ptr_node->right->type == 1 && ptr_node->right->left->type == 1 && ptr_node->right->left->key > ptr_node->key) {
                    ptr_node = ptr_node->right;
                    while (ptr_node->left->type)
                        ptr_node = ptr_node->left;
                }else
                    ptr_node = this->ptr_node->right;
            }
            else if (ptr_node->parent->type && ptr_node->parent->key > ptr_node->key)
                ptr_node = this->ptr_node->parent;
            else if (ptr_node->parent->key < ptr_node->key){
                while (ptr_node->parent->type && ptr_node->parent->key < ptr_node->key)
                    ptr_node = ptr_node->parent;
            }
            return (*this);
        }
        MapIterator &operator--()//prefix --i
        {
            if (ptr_node->left->type){
                if (ptr_node->left->right->type && ptr_node->left->right->key < ptr_node->key) {
                    ptr_node = ptr_node->left;
                    while (ptr_node->right->type)
                        ptr_node = ptr_node->right;
                } else
                    ptr_node = this->ptr_node->left;
            }
            else if (ptr_node->parent->type && ptr_node->parent->key < ptr_node->key)
                ptr_node = this->ptr_node->parent;
            else if (ptr_node->parent->key > ptr_node->key) {
                while (ptr_node->parent->type && ptr_node->parent->key > ptr_node->key)
                    ptr_node = ptr_node->parent;
            }
            return (*this);
        }
        bool operator!=(const  MapIterator &other) const {
            if (this->ptr_node != other.ptr_node)
                return (true);
            return (false);
        }
        bool operator==(const  MapIterator &other) const {
            if (this->ptr_node == other.ptr_node)
                return (true);
            return (false);
        }
    };
    template <typename K, typename V>
    class SimpleMapIterator : public MapIterator<K, V>{
    public:
        typedef std::pair<K, V> value_type;
        typedef iterator_tag iterator_category;
        typedef value_type *pointer;
        typedef value_type &reference;
        typedef std::ptrdiff_t difference_type;
        SimpleMapIterator(tree<K, V> *node): MapIterator<K, V>(node){}
        SimpleMapIterator(const value_type &val): MapIterator<K, V>(val){}
        virtual ~SimpleMapIterator() {}
        SimpleMapIterator(const MapIterator<K, V> &other) : MapIterator<K, V>(other) {}
        SimpleMapIterator() :MapIterator<K, V>(){}
        pointer operator->() {
            return (&operator*());
        }
        reference operator*() {
            this->p.first = this->ptr_node->key;
            this->p.second = this->ptr_node->vallue;
            return this->p;
        }
    };
    template <typename K, typename V>
    class ConstMapIterator : public MapIterator<K, V>{
    public:
        typedef std::pair<K, V> value_type;
        typedef iterator_tag iterator_category;
        typedef value_type const *const_pointer;
        typedef value_type const &const_reference;
        typedef std::ptrdiff_t difference_type;
        ConstMapIterator(tree<K, V> *node): MapIterator<K, V>(node){}
        virtual ~ConstMapIterator() {}
        ConstMapIterator(const MapIterator<K, V> &other) : MapIterator<K, V>(other) {}
        ConstMapIterator() :MapIterator<K, V>(){}
        const_pointer operator->() {
            return (&value_type(this->ptr_node->key, this->ptr_node->vallue));
        }
        const_reference operator*() {
            return (value_type(this->ptr_node->key, this->ptr_node->vallue));
        }
    };
}

#endif //ITERATOR_HPP
