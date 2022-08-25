/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:16:57 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/25 15:50:23 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "Vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack {
    public:

/* ************************************************************************** */
/*                               MEMBER TYPES                                 */
/* ************************************************************************** */

        typedef typename    Container::value_type       value_type;
        typedef typename    Container::size_type        size_type;
        typedef typename    Container::reference        reference;
        typedef typename    Container::const_reference  const_reference;
        typedef             Container                   container_type;

// Member objects
    protected:
        Container c;
    
    public:
/* ************************************************************************** */
/*                        CONSTRUCTORS / DESTRUCTORS                          */
/* ************************************************************************** */

        explicit stack(const Container& container = Container()): c(container){return;}
        
        ~stack(void){}


/* ************************************************************************** */
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

        bool empty() const              { return c.empty(); }
        size_type size() const          { return c.size(); }
        value_type& top()               { return c.back(); }
        const value_type& top() const   { return c.back(); }
        void push(const value_type& x)  { c.push_back(x); }
        void pop()                      { c.pop_back(); }
    

/* ************************************************************************** */
/*                            ASSIGNMENT OPERATOR                             */
/* ************************************************************************** */

        stack & operator=(const stack<T, Container>& rhs) {
            this->c = rhs.c;
            return *this;
        }


/* ************************************************************************** */
/*                            NON MEMBER OPERATORS                            */
/* ************************************************************************** */

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