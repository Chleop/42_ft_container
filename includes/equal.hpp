/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:42:09 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/05 14:20:20 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

#include <bits/stdc++.h>
#include <iostream>

namespace ft
{
    
    template<class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        InputIterator1 i = first1;
        while(i < last1)
        {
            if (*i != *(first2 + (i++ - first1)))
                return false;
        }
        return true;
    }

    template<class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        InputIterator1 i = first1;
        while(i < last1)
        {
            if (pred(*i, *(first2 + (i++ - first1))) == false)
                return false;
        }
        return true;
    }

}

#endif
