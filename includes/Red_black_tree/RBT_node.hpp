/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:12:50 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/25 15:01:53 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

# define BLACK  0
# define RED    1

namespace ft
{

/* ************************************************************************** */
/*                                  NODE CLASS                                */
/* ************************************************************************** */

template <class T>
class Node
{
public:
// MEMBER TYPES
    typedef T                           value_type;
    typedef Node <value_type>*          node_ptr;
    typedef const Node <value_type>*    const_node_ptr;

// ATTRIBUTES
    value_type  data;
    node_ptr    left;
    node_ptr    right;
    node_ptr    parent;
    int         color;

// CONSTRUCTORS / DESTRUCTORS
    Node(void)  : data(value_type()) {
        this->left      = NULL;
        this->right     = NULL;
        this->parent    = NULL;
        this->color     = RED;
    }

    Node(value_type d) : data(d){
        this->left      = NULL;
        this->right     = NULL;
        this->parent    = NULL;
        this->color     = RED;
    }
    
    ~Node(void) {}

    void swapNode(node_ptr successor) {
        node_ptr    oldleft = left;
        node_ptr    oldright = right;
        node_ptr    oldparent = parent;
        bool        oldcolor = color;
        node_ptr    successorOldleft = successor->left;
        node_ptr    successorOldright = successor->right;
        node_ptr    successorOldparent = successor->parent;

        if (right != successor && left != successor) {
            left = successor->left;
            right = successor->right;
            parent = successor->parent;
            color = successor->color;
            
            successor->left = oldleft;
            successor->right = oldright;
            successor->parent = oldparent;
            successor->color = oldcolor;

            if (oldparent && oldparent->left == this)
                oldparent->left = successor;
            else if (oldparent && oldparent->right == this)
                oldparent->right = successor;
            if (oldleft)
                oldleft->parent = successor;
            if (oldright)
                oldright->parent = successor;

            if (successorOldparent && successorOldparent->left == successor)
                successorOldparent->left = this;
            else if (successorOldparent && successorOldparent->right == successor)
                successorOldparent->right = this;
            if (successorOldleft)
                successorOldleft->parent = this;
            if (successorOldright && successorOldright->parent->parent != NULL)
                successorOldright->parent = this;
        }
        else if (right == successor) {
            left = successor->left;
            right = successor->right;
            parent = successor;
            color = successor->color;

            successor->left = oldleft;
            successor->right = this;
            successor->parent = oldparent;
            successor->color = oldcolor;

            if (oldparent && oldparent->left == this)
                oldparent->left = successor;
            else if (oldparent && oldparent->right == this)
                oldparent->right = successor;
            if (oldleft)
                oldleft->parent = successor;

            if (successorOldleft)
                successorOldleft->parent = this;
            if (successorOldright && successorOldright->parent->parent != NULL)
                successorOldright->parent = this;
        }
        else {
            left = successor->left;
            right = successor->right;
            parent = successor;
            color = successor->color;

            successor->left = this;
            successor->right = oldright;
            successor->parent = oldparent;
            successor->color = oldcolor;
            
            if (oldparent && oldparent->left == this)
                oldparent->left = successor;
            else if (oldparent && oldparent->right == this)
                oldparent->right = successor;
            if (oldright)
                oldright->parent = successor;
            
            if (successorOldleft)
                successorOldleft->parent = this;
            if (successorOldright && successorOldright->parent->parent != NULL)
                successorOldright->parent = this;
        }

    }

};

}

#endif