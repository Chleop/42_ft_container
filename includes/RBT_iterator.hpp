/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:43:28 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/23 18:41:35 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "RBT_node.hpp"
# include "iterator_traits.hpp"


namespace ft
{

template<typename T>
struct RBT_iterator
{
    typedef T                           value_type;
    typedef T&                          reference;
    typedef T*                          pointer;
    typedef std::bidirectional_iterator_tag  iterator_category;
    typedef std::ptrdiff_t              difference_type;
    typedef RBT_iterator<T>             iterator;
    typedef ft::Node<value_type>*       node_ptr;
    
    node_ptr       _node;
    
    RBT_iterator()
    : _node() { }
    
    explicit RBT_iterator(node_ptr x)
    : _node(x) { }

    RBT_iterator & operator= (RBT_iterator const & rhs) {
        if (*this != rhs)
            _node = rhs._node;
        return *this;
    }
    
    reference operator*() const
    { return *(&_node->data); }
    
    pointer operator->() const
    { return &(operator*()); }
    
    iterator& operator++() {
        if (_node->right != 0) {
            _node = _node->right;
            if (_node->parent != NULL && _node->parent->parent == NULL && 
                _node->right->right == _node && _node->color == 1){
                return *this;
            }
            else {
                while (_node->left != 0)
                    _node = _node->left;
            }
        }
        else {
            node_ptr y = _node->parent;
            while (_node == y->right) {
                _node = y;
                y = y->parent;
            }
            if (_node->right != y)
                _node = y;
        }
        return *this;
    }
    
    iterator operator++(int) {
        iterator tmp = *this;
        this->operator++();
        return tmp;
    }
    
    iterator& operator--() {
        if (_node->parent != NULL && _node->parent->parent == NULL && 
                _node->right->right == _node && _node->color == 1)
            _node = _node->right;
        else if (_node->left != 0) {
            node_ptr y = _node->left;
            while (y->right != 0)
                y = y->right;
            _node = y;
        }
        else {
            node_ptr y = _node->parent;
            while (y && _node == y->left) {
                _node = y;
                y = y->parent;
            }
            if (!y) {
                _node = _node->right;
                while (true) {
                    if (_node->parent != NULL && _node->parent->parent == NULL && 
                        _node->right->right == _node && _node->color == 1)
                        break;
                    _node = _node->right;
                }
                y = _node;
            }
            _node = y;
        }
        return *this;
    }
    
    iterator operator--(int) {
        iterator tmp = *this;
        this->operator--();
        return tmp;
    }
    
};

template<typename T>
bool operator==(const ft::RBT_iterator<T>& lhs, const ft::RBT_iterator<T>& rhs) { 
    return lhs._node == rhs._node; }

template<typename T>
bool operator!=(const ft::RBT_iterator<T>& lhs, const ft::RBT_iterator<T>& rhs) { 
    return lhs._node != rhs._node; }


template<typename T>
struct RBT_const_iterator
{
    typedef T                           value_type;
    typedef const T&                          reference;
    typedef const T*                          pointer;
    typedef std::bidirectional_iterator_tag  iterator_category;
    typedef std::ptrdiff_t              difference_type;
    typedef RBT_const_iterator<T>       const_iterator;
    typedef const ft::Node<value_type>* const_node_ptr;
    
    const_node_ptr       _node;
    
    RBT_const_iterator()
    : _node() { }
    
    explicit RBT_const_iterator(const_node_ptr x)
    : _node(x) { }

    template<typename Tp>
    RBT_const_iterator(const ft::RBT_iterator<Tp> & x)
    : _node(x._node) { }

    RBT_const_iterator & operator= (RBT_const_iterator const & rhs) {
        if (*this != rhs)
            _node = rhs._node;
        return *this;
    }

    RBT_const_iterator & operator= (ft::RBT_iterator<T> const & rhs) {
        _node = rhs._node;
        return *this;
    }
    
    reference operator*() const
    { return *(&_node->data); }

    pointer operator->() const
    { return &(operator*()); }
    
    const_iterator& operator++() {
        if (_node->right != 0) {
            _node = _node->right;
            if (_node->parent != NULL && _node->parent->parent == NULL && 
                _node->right->right == _node && _node->color == 1){
                return *this;
            }
            else {
                while (_node->left != 0)
                    _node = _node->left;
            }
        }
        else {
            const_node_ptr y = _node->parent;
            while (_node == y->right) {
                _node = y;
                y = y->parent;
            }
            if (_node->right != y)
                _node = y;
        }
        return *this;
    }
    
    const_iterator operator++(int) {
        const_iterator tmp = *this;
        this->operator++();
        return tmp;
    }
    
    const_iterator& operator--() {
        if (_node->parent != NULL && _node->parent->parent == NULL && 
                _node->right->right == _node && _node->color == 1)
            _node = _node->right;
        else if (_node->left != 0) {
            const_node_ptr y = _node->left;
            while (y->right != 0)
                y = y->right;
            _node = y;
        }
        else {
            const_node_ptr y = _node->parent;
            while (y && _node == y->left) {
                _node = y;
                y = y->parent;
            }
            if (!y) {
                _node = _node->right;
                while (true) {
                    if (_node->parent != NULL && _node->parent->parent == NULL && 
                        _node->right->right == _node && _node->color == 1)
                        break;
                    _node = _node->right;
                }
                y = _node;
            }
            _node = y;
        }
        return *this;
    }
    
    const_iterator operator--(int) {
        const_iterator tmp = *this;
        this->operator--();
        return tmp;
    }
    
};


template<typename T>
bool operator==(const ft::RBT_const_iterator<T>& lhs, const ft::RBT_const_iterator<T>& rhs) { 
    return lhs._node == rhs._node; }

template<typename T>
bool operator==(const ft::RBT_const_iterator<T>& lhs, const ft::RBT_iterator<T>& rhs) { 
    return lhs._node == rhs._node; }

template<typename T>
bool operator==(const ft::RBT_iterator<T>& lhs, const ft::RBT_const_iterator<T>& rhs) { 
    return lhs._node == rhs._node; }

template<typename T>
bool operator!=(const ft::RBT_const_iterator<T>& lhs, const ft::RBT_const_iterator<T>& rhs) { 
    return lhs._node != rhs._node; }

template<typename T>
bool operator!=(const ft::RBT_iterator<T>& lhs, const ft::RBT_const_iterator<T>& rhs) { 
    return lhs._node != rhs._node; }

template<typename T>
bool operator!=(const ft::RBT_const_iterator<T>& lhs, const ft::RBT_iterator<T>& rhs) { 
    return lhs._node != rhs._node; }

}

#endif