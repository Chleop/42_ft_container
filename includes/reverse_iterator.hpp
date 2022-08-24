// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   reverse_iterator.hpp                               :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/06/28 16:38:42 by cproesch          #+#    #+#             */
// /*   Updated: 2022/07/16 12:19:33 by cproesch         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{


template <class Iterator>
class reverse_iterator
{

protected:
        Iterator current;

public:
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename iterator_traits<Iterator>::reference           reference;
        typedef typename iterator_traits<Iterator>::pointer             pointer;

        reverse_iterator(): current() {}
        explicit reverse_iterator(Iterator x): current(x) {}
        template <class U>
        reverse_iterator(const reverse_iterator<U>& u) : current(u.base()) {}

        Iterator base() const { return current;}

        template<typename T>
        reverse_iterator& operator=(const reverse_iterator<T> & rhs)  {
                current = rhs.base();
                return *this;
        }

        reference operator*() const {
                Iterator tmp = base();
                return (*--tmp);
        }

        pointer operator->() const {
                return (&(operator*()));
        }

        reverse_iterator& operator++() {
                --current;
                return *this;
        }

        reverse_iterator operator++(int) {
                reverse_iterator tmp = *this;
                --current;
                return tmp;
        }

        reverse_iterator& operator--() {
                ++current;
                return *this;
        }

        reverse_iterator operator--(int) {
                reverse_iterator tmp = *this;
                ++current;
                return tmp;
        }

        reverse_iterator operator+ (typename reverse_iterator<Iterator>::difference_type n) const {
                return reverse_iterator(base() - n);
        }

        reverse_iterator& operator+=(typename reverse_iterator<Iterator>::difference_type n) {
                current -= n;
                return *this;
        }

        reverse_iterator operator- (typename reverse_iterator<Iterator>::difference_type n) const {
                return reverse_iterator(base() + n);
        }

        reverse_iterator& operator-=(typename reverse_iterator<Iterator>::difference_type n) {
                current += n;
                return *this;
        }

        reference operator[](typename reverse_iterator<Iterator>::difference_type n) const {
                return current[-n-1];
        }

};

template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
        return x.base() == y.base();
}

template <class Iterator, class constIterator>
bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<constIterator>& y) {
        return x.base() == y.base();
}

template <class Iterator>
bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
        return x.base() > y.base();
}

template <class Iterator, class constIterator>
bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<constIterator>& y) {
        return x.base() > y.base();
}

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
        return x.base() != y.base();
}

template <class Iterator, class constIterator>
bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<constIterator>& y) {
        return x.base() != y.base();
}

template <class Iterator>
bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
        return x.base() < y.base();
}

template <class Iterator, class constIterator>
bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<constIterator>& y) {
        return x.base() < y.base();
}

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
        return x.base() <= y.base();
}

template <class Iterator, class constIterator>
bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<constIterator>& y) {
        return x.base() <= y.base();
}

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
        return x.base() >= y.base();
}

template <class Iterator, class constIterator>
bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<constIterator>& y) {
        return x.base() >= y.base();
}

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
        return y.base() - x.base();
}

template <class Iterator, class constIterator>
typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<constIterator>& y) {
        return y.base() - x.base();
}

template <class Iterator>
reverse_iterator<Iterator> operator+(
typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x) {
        return reverse_iterator<Iterator> (x.base() - n);
}

}

#endif
