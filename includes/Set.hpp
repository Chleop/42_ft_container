/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:58:48 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/24 15:45:05 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "RBT.hpp"

namespace ft
{
    
template <  class Key, 
            class Compare = std::less<Key>,
            class Allocator = std::allocator<Key> >
class set {

    public:
/* ************************************************************************** */
/*                               MEMBER TYPES                                 */
/* ************************************************************************** */

    typedef Key                                 key_type;
    typedef Key                                 value_type;
    typedef Compare                             key_compare;
    typedef Compare                             value_compare;
    typedef Allocator                           allocator_type;
    typedef typename Allocator::reference       reference;
    typedef typename Allocator::const_reference const_reference;
    typedef typename ft::RedBlackTree<value_type, Compare, Allocator>::const_iterator iterator;
    typedef typename ft::RedBlackTree<value_type, Compare, Allocator>::const_iterator const_iterator;
    typedef std::size_t                         size_type;
    typedef std::ptrdiff_t                      difference_type;
    typedef typename Allocator::pointer         pointer;
    typedef typename Allocator::const_pointer   const_pointer;
    typedef ft::reverse_iterator<iterator>      reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;


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
    explicit set(const Compare& comp = Compare(), const Allocator& a= Allocator()):
    _size(0), _RedBlackTree(comp, a){}

    // Range
    template <class InputIterator>
    set(InputIterator first, InputIterator last,
    const Compare& comp = Compare(), const Allocator& a= Allocator()):
    _size(0), _RedBlackTree(comp, a){
        insert(first, last);
    }

    // Copy
    set(const set<Key,Compare,Allocator>& x):
    _size(0), _RedBlackTree(x._RedBlackTree) {}

    // Destructor
    ~set(void) {}


/* ************************************************************************** */
/*                            ASSIGNMENT OPERATOR                             */
/* ************************************************************************** */

    set<Key,Compare,Allocator>& operator= (const set<Key,Compare,Allocator>& x){
        _RedBlackTree = x._RedBlackTree;
        _size = x._size;
        return *this;
    }

    allocator_type get_allocator() const {
        return value_compare();
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
        _RedBlackTree.erase(*position);
        return;
    }

    size_type erase(const key_type& x) {
        return _RedBlackTree.erase(x);
    }

    void erase(iterator first, iterator last) {
        while (first != last)
            _RedBlackTree.erase(*first++);
        return;
    }

    void swap(set<Key,Compare,Allocator>& x) {
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
        return value_compare();
    }


/* ************************************************************************** */
/*                               SET OPERATIONS                               */
/* ************************************************************************** */

    iterator find(const key_type& x) {
        return _RedBlackTree.find(x);
    }

    const_iterator find(const key_type& x) const {
        return _RedBlackTree.find(x);
    }

    size_type count(const key_type& x) const {
        if ((_RedBlackTree.find(x)) == (_RedBlackTree.end()))
            return 0;
        return 1;
    }
    
    iterator lower_bound(const key_type& x) {
        return _RedBlackTree.lower_bound(x);
    }

    const_iterator lower_bound(const key_type& x) const {
        return _RedBlackTree.lower_bound(x);
    }
    
    iterator upper_bound(const key_type& x) {
        return _RedBlackTree.upper_bound(x);
    }

    const_iterator upper_bound(const key_type& x) const {
        return _RedBlackTree.upper_bound(x);
    }

    ft::pair<iterator,iterator>
    equal_range(const key_type& x) {
        ft::pair<iterator,iterator> p = _RedBlackTree.equal_range(x);
        return p;
    }

    ft::pair<const_iterator,const_iterator>
    equal_range(const key_type& x) const {
        return _RedBlackTree.equal_range(x);
    }


/* ************************************************************************** */
/*                            NON MEMBER OPERATORS                            */
/* ************************************************************************** */

    friend bool operator==(const set<Key,Compare,Allocator>& x, \
        const set<Key,Compare,Allocator>& y) {
            return x._RedBlackTree == y._RedBlackTree;
    }

    friend bool operator< (const set<Key,Compare,Allocator>& x, \
        const set<Key,Compare,Allocator>& y) {
            return x._RedBlackTree < y._RedBlackTree;
    }

    friend bool operator!=(const set<Key,Compare,Allocator>& x, \
        const set<Key,Compare,Allocator>& y) {
            return !(x == y);
    }

    friend bool operator> (const set<Key,Compare,Allocator>& x, \
        const set<Key,Compare,Allocator>& y) {
            return y < x;
    }

    friend bool operator<=(const set<Key,Compare,Allocator>& x, \
        const set<Key,Compare,Allocator>& y) {
            return !(y < x);
    }

    friend bool operator>=(const set<Key,Compare,Allocator>& x, \
        const set<Key,Compare,Allocator>& y) {
            return !(x < y);
    }

};

/* ************************************************************************** */
/*                          SPECIALIZED ALGORITHMS                            */
/* ************************************************************************** */

template <class Key, class Compare, class Allocator>
void swap(set<Key,Compare,Allocator>& x, set<Key,Compare,Allocator>& y) {
    x.swap(y);  
}

}

#endif