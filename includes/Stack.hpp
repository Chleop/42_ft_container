/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:16:57 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/15 11:01:37 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

// # include "iterators_traits.hpp"
// # include "reverse_iterator.hpp"
# include "Vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack {
    public:
// Member types
        typedef typename    Container::value_type       value_type;
        typedef typename    Container::size_type        size_type;
        typedef typename    Container::reference        reference;
        typedef typename    Container::const_reference  const_reference;
        typedef             Container                   container_type;

// Member objects
    protected:
        Container c;
    
    public:
// Constructor
        explicit stack(const Container& container = Container()): c(container){return;}
        
// // Destructor
//         ~stack(void){}

// Member functions
        bool empty() const              { return c.empty(); }
        size_type size() const          { return c.size(); }
        value_type& top()               { return c.back(); }
        const value_type& top() const   { return c.back(); }
        void push(const value_type& x)  { c.push_back(x); }
        void pop()                      { c.pop_back(); }
    
// Member operators
        stack & operator=(const stack<T, Container>& rhs)
        {
            this->c = rhs.c;
            return *this;
        }

// Non-member operators
        friend bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
        {return x.c == y.c;}

        friend bool operator< (const stack<T, Container>& x, const stack<T, Container>& y)
        {return (x.c < y.c);}

        friend bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
        {return x.c != y.c;}

        friend bool operator> (const stack<T, Container>& x, const stack<T, Container>& y)
        {return x.c > y.c;}

        friend bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
        {return x.c >= y.c;}

        friend bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
        {return x.c <= y.c;}
    };

}

#endif