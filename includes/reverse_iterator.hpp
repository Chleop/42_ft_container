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


// template <class Iterator>
// class const_reverse_iterator
// {

// protected:
//         Iterator current;

// public:
//         typedef Iterator                                                iterator_type;
//         typedef typename iterator_traits<Iterator>::difference_type     difference_type;
//         typedef typename iterator_traits<Iterator>::reference           reference;
//         typedef const typename iterator_traits<Iterator>::reference     const_reference;
//         typedef typename iterator_traits<Iterator>::pointer             pointer;
//         typedef const typename iterator_traits<Iterator>::pointer       const_pointer;

//         const_reverse_iterator(): current() {}
//         explicit const_reverse_iterator(Iterator x): current(x) {}
//         template <class U>
//         const_reverse_iterator(const const_reverse_iterator<U>& u) : current(u.base()) {}
//         template <class U>
//         const_reverse_iterator(const ft::reverse_iterator<U>& u) : current(u.base()) {}

//         Iterator base() const { return current;}

//         const_reverse_iterator& operator=(const const_reverse_iterator & rhs)  {
//                 current = rhs.base();
//                 return *this;
//         }

//         template <class U>
//         const_reverse_iterator& operator=(const ft::reverse_iterator<U> & rhs)  {
//                 current = rhs.base();
//                 return *this;
//         }

//         const_reference operator*() const {
//                 Iterator tmp = base();
//                 return const_cast<reference>(*--tmp);
//         }

//         const_pointer operator->() const {
//                 return const_cast<pointer>(&(operator*()));
//         }

//         const_reverse_iterator& operator++() {
//                 --current;
//                 return *this;
//         }

//         const_reverse_iterator operator++(int) {
//                 const_reverse_iterator tmp = *this;
//                 --current;
//                 return tmp;
//         }

//         const_reverse_iterator& operator--() {
//                 ++current;
//                 return *this;
//         }

//         const_reverse_iterator operator--(int) {
//                 const_reverse_iterator tmp = *this;
//                 ++current;
//                 return tmp;
//         }

//         const_reverse_iterator operator+ (typename const_reverse_iterator<Iterator>::difference_type n) const {
//                 return const_reverse_iterator(base() - n);
//         }

//         const_reverse_iterator& operator+=(typename const_reverse_iterator<Iterator>::difference_type n) {
//                 current += n;
//                 return *this;
//         }

//         const_reverse_iterator operator- (typename const_reverse_iterator<Iterator>::difference_type n) const {
//                 return const_reverse_iterator(base() + n);
//         }

//         const_reverse_iterator& operator-=(typename const_reverse_iterator<Iterator>::difference_type n) {
//                 current += n;
//                 return *this;
//         }

//         reference operator[](typename const_reverse_iterator<Iterator>::difference_type n) const {
//                 return current[-n-1];
//         }

// };

// template <class Iterator>
// bool operator==(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<Iterator>& y) {
//         return x.base() == y.base();
// }

// template <class Iterator, class constIterator>
// bool operator==(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<constIterator>& y) {
//         return x.base() == y.base();
// }

// template <class Iterator>
// bool operator<(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<Iterator>& y) {
//         return x.base() > y.base();
// }

// template <class Iterator, class constIterator>
// bool operator<(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<constIterator>& y) {
//         return x.base() > y.base();
// }

// template <class Iterator>
// bool operator!=(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<Iterator>& y) {
//         return x.base() != y.base();
// }

// template <class Iterator, class constIterator>
// bool operator!=(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<constIterator>& y) {
//         return x.base() != y.base();
// }

// template <class Iterator>
// bool operator>(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<Iterator>& y) {
//         return x.base() < y.base();
// }

// template <class Iterator, class constIterator>
// bool operator>(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<constIterator>& y) {
//         return x.base() < y.base();
// }

// template <class Iterator>
// bool operator>=(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<Iterator>& y) {
//         return x.base() <= y.base();
// }

// template <class Iterator, class constIterator>
// bool operator>=(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<constIterator>& y) {
//         return x.base() <= y.base();
// }

// template <class Iterator>
// bool operator<=(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<Iterator>& y) {
//         return x.base() >= y.base();
// }

// template <class Iterator, class constIterator>
// bool operator<=(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<constIterator>& y) {
//         return x.base() >= y.base();
// }

// template <class Iterator>
// typename const_reverse_iterator<Iterator>::difference_type operator-(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<Iterator>& y) {
//         return y.base() - x.base();
// }

// template <class Iterator, class constIterator>
// typename const_reverse_iterator<Iterator>::difference_type operator-(const const_reverse_iterator<Iterator>& x, const const_reverse_iterator<constIterator>& y) {
//         return y.base() - x.base();
// }

// template <class Iterator>
// const_reverse_iterator<Iterator> operator+(
// typename const_reverse_iterator<Iterator>::difference_type n, const const_reverse_iterator<Iterator>& x) {
//         return const_reverse_iterator<Iterator> (x.base() - n);
// }

}

#endif


// template <class T>
// class iterator
// {


// public:
//         typedef T                           value_type;
//         typedef ptrdiff_t                   difference_type;
//         typedef T&                          reference;
//         typedef T*                          iterator_type;
//         typedef T*                          pointer;
//         typedef const T*                    const_iterator;
//         typedef random_access_iterator_tag  iterator_category;

// protected:
//         iterator_type current;

// public:
//         iterator(): current() {}
//         explicit iterator(value_type* x): current(x) {}
//         template <class U>
//         iterator(const iterator<U>& u) : current(u.base()) {}

//         iterator_type base() const { return current;}

//         template<typename Tp>
//         iterator& operator=(const iterator<Tp> & rhs)  {
//                 current = rhs.base();
//                 return *this;
//         }

//         reference operator*() const {
//                 iterator_type tmp = base();
//                 return *tmp;
//         }

//         pointer operator->() const {
//                 return &(operator*());
//         }

//         iterator& operator++() {
//                 ++current;
//                 return *this;
//         }

//         iterator operator++(int) {
//                 iterator tmp = *this;
//                 ++current;
//                 return tmp;
//         }

//         iterator& operator--() {
//                 --current;
//                 return *this;
//         }

//         iterator operator--(int) {
//                 iterator tmp = *this;
//                 --current;
//                 return tmp;
//         }

//         iterator operator+ (typename iterator<value_type>::difference_type n) const {
//                 return iterator(base() + n);
//         }

//         iterator& operator+=(typename iterator<value_type>::difference_type n) {
//                 current += n;
//                 return *this;
//         }

//         iterator operator- (typename iterator<value_type>::difference_type n) const {
//                 return iterator(base() - n);
//         }

//         iterator& operator-=(typename iterator<value_type>::difference_type n) {
//                 current -= n;
//                 return *this;
//         }

//         reference operator[](typename iterator<value_type>::difference_type n) const {
//                 return current[n];
//         }

// };

// template <class T>
// bool operator==(const iterator<T>& x, const iterator<T>& y) {
//         return x.base() == y.base();
// }

// template <class T, class constT>
// bool operator==(const iterator<T>& x, const iterator<constT>& y) {
//         return x.base() == y.base();
// }

// template <class T>
// bool operator<(const iterator<T>& x, const iterator<T>& y) {
//         return x.base() < y.base();
// }

// template <class T, class constT>
// bool operator<(const iterator<T>& x, const iterator<constT>& y) {
//         return x.base() < y.base();
// }

// template <class T>
// bool operator!=(const iterator<T>& x, const iterator<T>& y) {
//         return x.base() != y.base();
// }

// template <class T, class constT>
// bool operator!=(const iterator<T>& x, const iterator<constT>& y) {
//         return x.base() != y.base();
// }

// template <class T>
// bool operator>(const iterator<T>& x, const iterator<T>& y) {
//         return x.base() > y.base();
// }

// template <class T, class constT>
// bool operator>(const iterator<T>& x, const iterator<constT>& y) {
//         return x.base() > y.base();
// }

// template <class T>
// bool operator>=(const iterator<T>& x, const iterator<T>& y) {
//         return x.base() >= y.base();
// }

// template <class T, class constT>
// bool operator>=(const iterator<T>& x, const iterator<constT>& y) {
//         return x.base() >= y.base();
// }

// template <class T>
// bool operator<=(const iterator<T>& x, const iterator<T>& y) {
//         return x.base() <= y.base();
// }

// template <class T, class constT>
// bool operator<=(const iterator<T>& x, const iterator<constT>& y) {
//         return x.base() <= y.base();
// }

// template <class T>
// typename iterator<T>::difference_type operator-(const iterator<T>& x, const iterator<T>& y) {
//         return x.base() - y.base();
// }

// template <class T, class constT>
// typename iterator<T>::difference_type operator-(const iterator<T>& x, const iterator<constT>& y) {
//         return x.base() - y.base();
// }

// template <class T>
// iterator<T> operator+(
// typename iterator<T>::difference_type n, const iterator<T>& x) {
//         return iterator<T> (x.base() + n);
// }

// // #######################################################################################################################3