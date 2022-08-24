/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:40:12 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/24 15:10:47 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <functional>
# include <memory>
# include <algorithm>
# include "RBT_iterator.hpp"
# include "pairs.hpp"
# include "reverse_iterator.hpp"
# include "lex_compare.hpp"

# define BLACK  0
# define RED    1

namespace ft
{

template <class T,
        class Compare = std::less<T>,
        class Allocator = std::allocator<T> >
class RedBlackTree
{
public:
/* ************************************************************************** */
/*                               MEMBER TYPES                                 */
/* ************************************************************************** */

    typedef T                                   value_type;
    typedef ft::Node<T>                         node_type;
    typedef value_type*                         pointer;
    typedef const value_type*                   const_pointer;
    typedef value_type&                         reference;
    typedef const value_type&                   const_reference;
    typedef std::size_t                         size_type;
    typedef std::ptrdiff_t                      difference_type;
    typedef typename Allocator::template rebind<node_type>::other  node_alloc_type;
    typedef Compare                             comp_type;
    typedef Node<value_type>*                   node_ptr;
    typedef const Node<value_type>*             const_node_ptr;
    typedef ft::RBT_iterator<value_type>        iterator;
    typedef ft::RBT_const_iterator<value_type>  const_iterator;
    typedef ft::reverse_iterator<iterator>      reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;


/* ************************************************************************** */
/*                              MY SECRET GARDEN                              */
/* ************************************************************************** */

private:

    node_ptr        _root;
    node_ptr        _nil;
    node_ptr        _header;
    size_type       _size;
    node_alloc_type _alloc;
    comp_type       _comp;
    

/* ************************************************************************** */
/*                        CONSTRUCTORS / DESTRUCTORS                          */
/* ************************************************************************** */

public:

    RedBlackTree(const comp_type& cmp = comp_type(), const node_alloc_type& a = node_alloc_type()):
    _root(NULL), _nil(NULL), _header(NULL), _size(0), _alloc(a), _comp(cmp) {
        _nil = createNode(value_type());
        _nil->color     = BLACK;
        _root = _nil;
        _header = createNode(value_type());
        _header->parent = _root;
        _header->color = RED;
        _header->left = _header;
        _header->right = _header;
        _root->right = _header;
    }

    RedBlackTree(const RedBlackTree<value_type, comp_type, Allocator> & x) :
    _root(NULL), _nil(NULL), _header(NULL), _size(0), _alloc(x._alloc), _comp(x._comp) {
        _nil = createNode(value_type());
        _nil->color     = BLACK;
        _root = _nil;
        _header = createNode(value_type());
        _header->parent = _root;
        _header->color = RED;
        _header->left = _header;
        _header->right = _header;
        _root->right = _header;
        const_iterator first = x.begin();
        for (; first != x.end(); first++) {
            insert(*first);
        }
    }

    ~RedBlackTree(void) {
        if (_root && _root != _nil)
            deleteFrom(&_root);
        _size = 0;
        deleteNode(&_nil);
        deleteNode(&_header);
    }


/* ************************************************************************** */
/*                    ASSIGNMENT OPERATORS AND FUNCTIONS                      */
/* ************************************************************************** */

    RedBlackTree<T, comp_type, Allocator>& operator= \
        (const RedBlackTree<T, comp_type, Allocator>& x) {
        if (*this == x)
            return *this;
        if (_root && _root != _nil)
            deleteFrom(&_root);
        _size = 0;
        _root = _nil;
        _header->parent = _root;
        _header->color = RED;
        _header->left = _header;
        _header->right = _header;
        _root->right = _header;
        _alloc = x._alloc;
        insert(x.begin(), x.end());
        return *this;
    }


/* ************************************************************************** */
/*                                 ITERATORS                                  */
/* ************************************************************************** */

    iterator begin()             { return iterator (_header->left); }
    const_iterator begin() const { return const_iterator (_header->left); }
    iterator end()               { return iterator (_header); }
    const_iterator end() const   { return const_iterator (_header); }
    reverse_iterator rbegin()    { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const    {
        return const_reverse_iterator(end()); 
    }
    reverse_iterator rend()      { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const  { 
        return const_reverse_iterator(begin());
    }


/* ************************************************************************** */
/*                                  CAPACITY                                  */
/* ************************************************************************** */

    bool empty() const          {return _size == 0;}
    size_type size() const      {return _size;}
    size_type max_size() const  {return (_alloc.max_size());}


/* ************************************************************************** */
/*                               ELEMENTS ACCESS                              */
/* ************************************************************************** */

    node_ptr parent(node_ptr n) {
    if (n)
        return n->parent;
    return NULL;
    }

    node_ptr grandparent(node_ptr n) {
    return parent(parent(n));
    }

    node_ptr sibling(node_ptr n) {
    node_ptr p = parent(n);
    if (!p)
        return NULL;
    if (n == p->left)
        return p->right;
    return p->left;
    }

    node_ptr aunt(node_ptr n) {
    node_ptr p = parent(n);
    return sibling(p);
    }

    node_ptr findMinimum(node_ptr node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    node_ptr findMaximum(node_ptr node) {
        while (node->right != _header)
            node = node->right;
        return node;
    }

    const_node_ptr findMinimum(const_node_ptr node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    const_node_ptr findMaximum(const_node_ptr node) {
        while (node->right != _header)
            node = node->right;
        return node;
    }

    node_ptr searchNode(const value_type& x) const {
        node_ptr node = _root;
        while (node && node != _nil && node != _header)
        {
            if (_comp(x, node->data))
                node = node->left;
            else if (_comp(node->data, x))
                node = node->right;
            else
                return node;
        }
        return NULL;
    }

    bool    equal_comp(const value_type& x, const value_type& y) {
        if (_comp(x, y) || _comp(y, x))
            return false;
        return true;
    }


/* ************************************************************************** */
/*                                  ROTATIONS                                 */
/* ************************************************************************** */

    void rotateLeft(node_ptr n) {
        node_ptr parent = n->parent;
        node_ptr rightChild = n->right;

        n->right = rightChild->left;

        if (rightChild->left && rightChild->left != NULL)
            rightChild->left->parent = n;
        rightChild->left = n;
        n->parent = rightChild;
        if (parent == NULL)
            _root = rightChild;
        else if (parent->right == n)
            parent->right = rightChild;
        else if (parent->left == n)
            parent->left = rightChild;
        if (rightChild != NULL)
            rightChild->parent = parent;
    }

    void rotateRight(node_ptr n) {
        node_ptr parent = n->parent;
        node_ptr leftChild = n->left;

        n->left = leftChild->right;

        if (leftChild->right && leftChild->right != _header)
            leftChild->right->parent = n;
        leftChild->right = n;
        n->parent = leftChild;
        if (parent == NULL)
            _root = leftChild;
        else if (parent->left == n)
            parent->left = leftChild;
        else if (parent->right == n)
            parent->right = leftChild;
        if (leftChild != NULL)
            leftChild->parent = parent;
    }


/* ************************************************************************** */
/*                                  INSERTION                                 */
/* ************************************************************************** */

    ft::pair<iterator, bool> insert(const value_type& x) {
        if (alreadyExistingKey(x))
            return ft::make_pair(iterator(searchNode(x)), false);
        node_ptr newNode = createNode(x);
        node_ptr newParent = findNewParent(newNode);
        insertNode(newNode, newParent);
        reequilibrateAfterInsert(newNode);
        _header->parent = _root;
        return ft::make_pair(iterator(searchNode(x)), true);
    }

    iterator insert(const_iterator position, const value_type& x) {
        position = begin();
        insert(x);
        return iterator(searchNode(x));
    }

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
        for (; first != last ; first++) {
            insert(*first);
        }
        return;
    }


/* ************************************************************************** */
/*                              INSERTION UTILS                               */
/* ************************************************************************** */

    void insertNode(node_ptr newNode, node_ptr newParent) {
        newNode->parent = newParent;
        if (newParent == NULL) {
            _root = newNode;
            newNode->right = _header;
        }
        else if (_comp(newNode->data, newParent->data))
            newParent->left = newNode;
        else {
            if (newParent->right == _header)
                newNode->right = _header;
            newParent->right = newNode;
        }
        if (_header->right == _header || _comp(_header->right->data, newNode->data))
            _header->right = newNode;
        if (_header->left == _header || _comp(newNode->data, _header->left->data))
            _header->left = newNode;
        _size++;
        return;
    }

    void reequilibrateAfterInsert(node_ptr n) {
        node_ptr myparent = parent(n);
        node_ptr mygrandparent = grandparent(n);
        node_ptr myaunt = aunt(n);

        if ((myparent == NULL) || (myparent->color == BLACK))
            return;
        if (mygrandparent == NULL)
            myparent->color = BLACK;
        else if (myaunt != NULL && myaunt != _header && myaunt->color == RED) {
            myaunt->color = BLACK;
            myparent->color = BLACK;
            mygrandparent->color = RED;
            reequilibrateAfterInsert(mygrandparent);
        }
        else if (myparent == mygrandparent->left) {
            if (n == myparent->right) {
                rotateLeft(myparent);
                myparent = n;
            }
            rotateRight(mygrandparent);
            myparent->color = BLACK;
            mygrandparent->color = RED;
        }
        else {
            if (n == myparent->left) {
                rotateRight(myparent);
                myparent = n;
            }
            rotateLeft(mygrandparent);
            myparent->color = BLACK;
            mygrandparent->color = RED;
        }
        return;
    }
    
    bool alreadyExistingKey(const value_type& x) const {
        node_ptr node = searchNode(x);
        if (node) {
            // node->data = x;
            return true;
        }
        return false;
    }

    node_ptr findNewParent(node_ptr newNode){
        node_ptr    currentNode = _root;
        node_ptr    newParent   = NULL;

        while(currentNode != NULL && currentNode != _nil && currentNode != _header) {
            newParent = currentNode;
            if (_comp(newNode->data, currentNode->data))
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;
        }
        return newParent;
    }

    node_ptr createNode(const value_type& x) {
        node_ptr newNode = _alloc.allocate(1);
        _alloc.construct(newNode, x);
        return newNode;
    }


/* ************************************************************************** */
/*                                  DELETION                                  */
/* ************************************************************************** */

    size_type erase(const value_type& x) {
        node_ptr node = searchNode(x);
        if (node == NULL)
            return 0;
        node_ptr movedUpNode;
        bool deletedNodeColor;
        value_type prevMin = _header->left->data;
        value_type prevMax = _header->right->data;
        value_type prevX = x;
        if (node->left == NULL || node->right == NULL) {
            deletedNodeColor = node->color;
            movedUpNode = deleteWithZeroOrOneChild(node);
        }
        else {
            node_ptr successor;
            if (node->right == _header)
                successor = findMinimum(node);
            else
                successor = findMinimum(node->right);
            if (node->parent == NULL)
                _root = successor;
            (*node).swapNode(successor);
            deletedNodeColor = node->color;
            movedUpNode = deleteWithZeroOrOneChild(node);
        }
        if (deletedNodeColor == BLACK) {
            deleteReequilibrateTree(movedUpNode);
            if(movedUpNode && equal_comp(movedUpNode->data, prevX))
                replaceParentsChild(movedUpNode->parent, movedUpNode, movedUpNode->right);
        }
        keepHeaderUpToDate(prevMin, prevMax, prevX);
        _size--;
        _header->parent = _root;
        return 1;
    }


/* ************************************************************************** */
/*                              DELETION UTILS                                */
/* ************************************************************************** */

    node_ptr deleteWithZeroOrOneChild(node_ptr node) {
        node_ptr res;
        if (node->left != NULL) {
            res = node->left;
            replaceParentsChild(node->parent, node, node->left);
        }
        else if (node->right != NULL && node->right != _header && node->right != _nil) {
            res = node->right;
            replaceParentsChild(node->parent, node, node->right);
        }
        else {
            if (node->color == BLACK){
                res = node;
            }
            else {
                res = node->right;
                replaceParentsChild(node->parent, node, node->right);
            }
        }
        return res;
    }

    void deleteReequilibrateTree(node_ptr node) {
        // Case 1: Examined node is root, end of recursion
        if (node == _root)
        return;

        node_ptr mysibling = sibling(node);
        // Case 2: Red sibling
        if (mysibling && mysibling->color == RED) {
            handleRedSibling(node, mysibling);
            mysibling = sibling(node); // Get new sibling for fall-through to cases 3-6
        }
        // Cases 3+4: Black sibling with two black children
        if (mysibling && (mysibling->left == NULL || mysibling->left->color == BLACK) 
            && (mysibling->right == NULL || mysibling->right == _header 
            || mysibling->right->color == BLACK)) {
            mysibling->color = RED;
        // Case 3: Black sibling with two black children + red parent
            if (node->parent->color == RED)
                node->parent->color = BLACK;
        // Case 4: Black sibling with two black children + black parent
            else
                deleteReequilibrateTree(node->parent);
        }
        // Case 5+6: Black sibling with at least one red child
        else
            handleBlackSiblingWithAtLeastOneRedChild(node, mysibling);
    }

    void replaceParentsChild(node_ptr parent, node_ptr oldChild, node_ptr newChild) {
        if (parent == NULL && newChild == _header) {
            deleteFrom(&oldChild);
            return;
        }
        if (parent == NULL)
            _root = newChild;
        else if (parent->left == oldChild)
            parent->left = newChild;
        else if (parent->right == oldChild)
            parent->right = newChild;
        if (newChild != NULL)
            newChild->parent = parent;
        deleteNode(&oldChild);
    }
    
    void handleRedSibling(node_ptr node, node_ptr mysibling) {
        mysibling->color = BLACK;
        node->parent->color = RED;
        if (node == node->parent->left)
            rotateLeft(node->parent);
        else
            rotateRight(node->parent);
    }

    void handleBlackSiblingWithAtLeastOneRedChild(node_ptr node, node_ptr mysibling) {
        bool nodeIsLeftChild = 0;
        
        if (node == node->parent->left)
            nodeIsLeftChild = 1;
        // Case 5: Black mysibling with at least one red child + "outer nephew" is black
        // --> Recolor mysibling and its child, and rotate around mysibling
        if (nodeIsLeftChild && (mysibling->right == NULL ||mysibling->right == _header || mysibling->right->color == BLACK)) {
            mysibling->left->color = BLACK;
            mysibling->color = RED;
            rotateRight(mysibling);
            mysibling = node->parent->right;
        }
        else if (!nodeIsLeftChild && (mysibling->left == NULL || mysibling->left->color == BLACK)) {
            mysibling->right->color = BLACK;
            mysibling->color = RED;
            rotateLeft(mysibling);
            mysibling = node->parent->left;
        }

        // Case 6: Black mysibling with at least one red child + "outer nephew" is red
        // --> Recolor mysibling + parent + mysibling's child, and rotate around parent
        mysibling->color = node->parent->color;
        node->parent->color = BLACK;
        if (nodeIsLeftChild) {
            mysibling->right->color = BLACK;
            rotateLeft(node->parent);
        }
        else {
            mysibling->left->color = BLACK;
            rotateRight(node->parent);
        }
    }

    void deleteNode(node_ptr *tbDestroyed) {
        if (!*tbDestroyed)
            return;
        (*tbDestroyed)->left = NULL;
        (*tbDestroyed)->right = NULL;
        (*tbDestroyed)->parent = NULL;
        (*tbDestroyed)->color = RED;
        _alloc.destroy(*tbDestroyed);
        _alloc.deallocate(*tbDestroyed, 1);
        *tbDestroyed = NULL; 
    }

    void deleteFrom(node_ptr *node) {
        if (!(*node))
            return;
        if ((*node)->right != NULL && (*node)->right != _header)
            deleteFrom(&(*node)->right);
        if ((*node)->left != NULL)
            deleteFrom(&(*node)->left);
        if (((*node)->right == NULL || (*node)->right == _header) && (*node)->left == NULL) {
            if ((*node) == _root) {
                if (_nil != _root)
                    deleteNode(&_root);
                else
                    _root = NULL;
            }
            else
                replaceParentsChild((*node)->parent, (*node), (*node)->right);
        }
        return;
    }

    void keepHeaderUpToDate(value_type prevMin, value_type prevMax, const value_type& x) {
        if (equal_comp(prevMin, prevMax)) {
            _header->right = _header;
            _header->left = _header;
        }
        else if (equal_comp(prevMax, x))
            _header->right = findMaximum(_root);
        else if (equal_comp(prevMin, x))
            _header->left = findMinimum(_root);
    }

    
/* ************************************************************************** */
/*                                  MODIFIERS                                 */
/* ************************************************************************** */

    void    clear(void) {
        if (_root && _root != _nil)
            deleteFrom(&_root);
        _root = _nil;
        _header->left = _header;
        _header->right = _header;
        _size = 0;
    }

    void    swap(RedBlackTree<T, comp_type, Allocator> & x) {
        node_ptr oldroot = _root;
        node_ptr oldnil = _nil;
        node_ptr oldheader = _header;
        size_type oldsize = _size;

        _root = x._root;
        _nil = x._nil;
        _header = x._header;
        _size = x._size;
        x._root = oldroot;
        x._nil = oldnil;
        x._header = oldheader;
        x._size = oldsize;
        return;
    }


/* ************************************************************************** */
/*                                 OPERATIONS                                 */
/* ************************************************************************** */

    iterator find(const value_type& x) {
        node_ptr no = searchNode(x);

        if (no)
            return iterator(no);
        else
            return end();
    }

    const_iterator find(const value_type& x) const {
        node_ptr no = searchNode(x);

        if (no)
            return const_iterator(no);
        else
            return end();
    }

    iterator lower_bound(const value_type& x) {
        iterator iter = begin();
        while (iter != end() && _comp(*iter, x))
            iter++;
        return iter;
    }

    const_iterator lower_bound(const value_type& x) const {
        const_iterator iter = begin();
        while (iter != end() && _comp(*iter, x))
            iter++;
        return iter;
    }

    iterator upper_bound(const value_type& x) {
        iterator iter = begin();
        while (iter != end() && _comp(*iter, x))
            iter++;
        if (iter != end() &&  !_comp(x, *iter))
            iter++;
        return iter;
    }
    
    const_iterator upper_bound(const value_type& x) const {
        const_iterator iter = begin();
        while (iter != end() && _comp(*iter, x))
            iter++;
        if (iter != end() &&  !_comp(x, *iter))
            iter++;
        return iter;
    }
    
    ft::pair<iterator,iterator> equal_range(const value_type& x) {
        return ft::make_pair<iterator,iterator>(lower_bound(x), upper_bound(x));
    }

    ft::pair<const_iterator,const_iterator> equal_range(const value_type& x) const {
        return ft::make_pair<const_iterator,const_iterator>(lower_bound(x), upper_bound(x));
    }


/* ************************************************************************** */
/*                            NON MEMBER OPERATORS                            */
/* ************************************************************************** */

    friend bool operator==(const RedBlackTree<T, comp_type, Allocator>& x, \
        const RedBlackTree<T, comp_type, Allocator>& y) {
        if (x._size != y._size)return false;
        return (std::equal (x.begin(), x.end(), y.begin()));
    }
        
    friend bool operator< (const RedBlackTree<T, comp_type, Allocator>& x, \
        const RedBlackTree<T, comp_type, Allocator>& y) {
        return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
    }


/* ************************************************************************** */
/*                              PRINT FUNCTIONS                               */
/* ************************************************************************** */

    void    printNode(node_ptr node) const
    {
        std::cout << "Node address: " << node << std::endl;
        // std::cout << "Node data   : " << node->data.first << std::endl;
        std::cout << "Node data   : " << node->data << std::endl;
        std::cout << "Node left   : " << node->left << std::endl;
        std::cout << "Node right  : " << node->right << std::endl;
        std::cout << "Node parent : " << node->parent << std::endl;
        std::cout << "Node color  : " << node->color << std::endl;
    }

    void    printNode(const value_type& x) const
    {
        node_ptr node = searchNode(x);
        std::cout << "Node address: " << node << std::endl;
        // std::cout << "Node data   : " << node->data.first << std::endl;
        std::cout << "Node data   : " << node->data << std::endl;
        std::cout << "Node left   : " << node->left << std::endl;
        std::cout << "Node right  : " << node->right << std::endl;
        std::cout << "Node parent : " << node->parent << std::endl;
        std::cout << "Node color  : " << node->color << std::endl;
    }

    void visualize(node_ptr node, std::string indent, bool right) const
    {
        if (node != NULL && (node != _header)) {
            printNode(node);
            std::cout << indent;
            if (right)
            {
                std::cout << "R----";
                indent += "     ";
            }
            else
            { 
                if (node != _root)
                {
                    std::cout << "L----";
                    indent += "|    ";
                }
            }
            // std::cout << node->data.first << "(" << (node->color ? "RED" : "BLACK") << ")" << std::endl;
            std::cout << node->data << "(" << (node->color ? "RED" : "BLACK") << ")" << std::endl;
            visualize(node->left, indent, false);
            visualize(node->right, indent, true);
        }
    }

    void visualize(void) const
    {
        std::cout << "_nil address is    : " << _nil << std::endl;
        std::cout << "_root address is   : " << _root << std::endl;
        std::cout << "_header address is : " << _header << std::endl;
        std::cout << "_header right is : " << _header->right << std::endl;
        std::cout << "_header left is : " << _header->left << std::endl;

        visualize(_root, "", false);
    }

    void print(std::string str) const {
        std::cout << str << std::endl;
        return;
    }

};
}

#endif