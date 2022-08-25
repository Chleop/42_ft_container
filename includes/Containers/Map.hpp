/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:44:45 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/25 16:04:19 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../Red_black_tree/RBT.hpp"

namespace ft
{

template    <class Key,
            class T,
            class Compare = std::less<Key>,
            class Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
    
public:
/* ************************************************************************** */
/*                               MEMBER TYPES                                 */
/* ************************************************************************** */

    typedef Key                                     key_type;
    typedef T                                       mapped_type;
    typedef ft::pair<const Key, T>                  value_type;
    typedef Compare                                 key_compare;
    typedef Allocator                               allocator_type;
    typedef typename Allocator::reference           reference;
    typedef typename Allocator::const_reference     const_reference;
    typedef typename ft::RedBlackTree<value_type, Compare, Allocator>::iterator iterator;
    typedef typename ft::RedBlackTree<value_type, Compare, Allocator>::const_iterator const_iterator;
    typedef std::size_t                             size_type;
    typedef std::ptrdiff_t                          difference_type;
    typedef typename Allocator::pointer             pointer;
    typedef typename Allocator::const_pointer       const_pointer;
    typedef ft::reverse_iterator<iterator>          reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

/* ************************************************************************** */
/*                            VALUE-COMPARE CLASS                             */
/* ************************************************************************** */

    class value_compare : public std::binary_function<value_type,value_type,bool>
    {
        friend class map;
    protected:
        Compare comp;
        value_compare(Compare c) : comp(c) {}
    public:
        bool operator()(const value_type& x, const value_type& y) const 
        {return comp(x.first, y.first);}
    };


/* ************************************************************************** */
/*                              MY SECRET GARDEN                              */
/* ************************************************************************** */
     
private:
    size_t                                                      _size;
    ft::RedBlackTree<value_type, value_compare, allocator_type> _RedBlackTree;


/* ************************************************************************** */
/*                        CONSTRUCTORS / DESTRUCTORS                          */
/* ************************************************************************** */

public:
// Default
    explicit map(const Compare& comp = Compare(), const Allocator& a = Allocator()):
    _size(0), _RedBlackTree(value_compare(comp), a){}

// Range
    template <class InputIterator>
    map (InputIterator first,
        InputIterator last,
        const Compare& comp = Compare(),
        const Allocator& a = Allocator()):
        _size(0), _RedBlackTree(value_compare(comp), a){
        insert(first, last);
    }

// Copy
    map (const map<Key,T,Compare,Allocator>& x):
    _size(0), _RedBlackTree(x._RedBlackTree)
    {}

// Destructor
    ~map(void) {}


/* ************************************************************************** */
/*                            ASSIGNMENT OPERATOR                             */
/* ************************************************************************** */

    map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x){
        _RedBlackTree = x._RedBlackTree;
        _size = x._size;
        return *this;
    }

/* ************************************************************************** */
/*                                 ITERATORS                                  */
/* ************************************************************************** */

    iterator begin()                        {return _RedBlackTree.begin();}
    const_iterator begin() const            {return _RedBlackTree.begin();}
    iterator end()                          {return _RedBlackTree.end();}
    const_iterator end() const              {return _RedBlackTree.end();}
    reverse_iterator rbegin()               {return _RedBlackTree.rbegin();}
    const_reverse_iterator rbegin() const   {return _RedBlackTree.rbegin();}
    reverse_iterator rend()                 {return _RedBlackTree.rend();}
    const_reverse_iterator rend() const     {return _RedBlackTree.rend();}


/* ************************************************************************** */
/*                                  CAPACITY                                  */
/* ************************************************************************** */

    bool empty() const          {return _RedBlackTree.empty();}
    size_type size() const      {return _RedBlackTree.size();}
    size_type max_size() const  {return _RedBlackTree.max_size();}

/* ************************************************************************** */
/*                               ELEMENTS ACCESS                              */
/* ************************************************************************** */

    T& operator[](const key_type& x) {
        return (*((insert(ft::make_pair(x, T()))).first)).second;
    }

/* ************************************************************************** */
/*                                  MODIFIERS                                 */
/* ************************************************************************** */

    pair<iterator, bool> insert(const value_type& x) {
        return (_RedBlackTree.insert(x));
    }

    iterator insert(iterator position, const value_type& x) {
        return (_RedBlackTree.insert(position, x));
    }

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
        _RedBlackTree.insert(first, last);
        return;
    }
    
    void erase(iterator position) {
        _RedBlackTree.erase(ft::make_pair((*position).first, mapped_type()));
        return;
    }

    size_type erase(const key_type& x) {
        return _RedBlackTree.erase(ft::make_pair(x, mapped_type()));
    }

    void erase(iterator fist, iterator last) {
        while (fist != last)
            _RedBlackTree.erase(ft::make_pair((*fist++).first, T()));
        return;
    }

    void swap(map<Key,T,Compare,Allocator>& x) {
        _RedBlackTree.swap(x._RedBlackTree);
    }

    void clear() {
        _RedBlackTree.clear();
    }


/* ************************************************************************** */
/*                                  OBSERVERS                                 */
/* ************************************************************************** */

    key_compare key_comp() const {
        return key_compare();
    }

    value_compare value_comp() const {
        return value_compare(key_compare());
    }


/* ************************************************************************** */
/*                               MAP OPERATIONS                               */
/* ************************************************************************** */

    iterator find(const key_type& x) {
        return _RedBlackTree.find(ft::make_pair(x, T()));
    }

    const_iterator find(const key_type& x) const {
        return _RedBlackTree.find(ft::make_pair(x, T()));
    }

    size_type count(const key_type& x) const {
        if ((_RedBlackTree.find(ft::make_pair(x, T()))) == (_RedBlackTree.end()))
            return 0;
        return 1;
    }
    
    iterator lower_bound(const key_type& x) {
        return _RedBlackTree.lower_bound(ft::make_pair(x, T()));
    }

    const_iterator lower_bound(const key_type& x) const {
        return _RedBlackTree.lower_bound(ft::make_pair(x, T()));
    }
    
    iterator upper_bound(const key_type& x) {
        return _RedBlackTree.upper_bound(ft::make_pair(x, T()));
    }

    const_iterator upper_bound(const key_type& x) const {
        return _RedBlackTree.upper_bound(ft::make_pair(x, T()));
    }

    ft::pair<iterator,iterator>
    equal_range(const key_type& x) {
        ft::pair<iterator,iterator> p = _RedBlackTree.equal_range(ft::make_pair<key_type,T>(x, T()));
        return p;
    }

    ft::pair<const_iterator,const_iterator>
    equal_range(const key_type& x) const {
        return _RedBlackTree.equal_range(ft::make_pair<key_type,T>(x, T()));
    }


/* ************************************************************************** */
/*                            NON MEMBER OPERATORS                            */
/* ************************************************************************** */

    friend bool operator==(const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y) {
            return x._RedBlackTree == y._RedBlackTree;
    }

    friend bool operator< (const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y) {
            return x._RedBlackTree < y._RedBlackTree;
    }

    friend bool operator!=(const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y) {
            return !(x == y);
    }

    friend bool operator> (const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y) {
            return y < x;
    }

    friend bool operator<=(const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y) {
            return !(y < x);
    }

    friend bool operator>=(const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y) {
            return !(x < y);
    }

};


/* ************************************************************************** */
/*                          SPECIALIZED ALGORITHMS                            */
/* ************************************************************************** */

template <class Key, class T, class Compare, class Allocator>
void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y){
    x.swap(y);
}

}

#endif
