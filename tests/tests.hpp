/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:11:23 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/25 16:00:34 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#ifndef LIB
# define PAIR       ft::pair
# define MAKE_PAIR  ft::make_pair
# define EQUAL      ft::equal
# define STACK      ft::stack
# define REV_ITER   ft::reverse_iterator
# define VECTOR     ft::vector
# define LEX        ft::lexicographical_compare
# define MAP        ft::map
# define SET        ft::set
#else
# define PAIR       std::pair
# define MAKE_PAIR  std::make_pair
# define EQUAL      std::equal
# define STACK      std::stack
# define REV_ITER   std::reverse_iterator
# define VECTOR     std::vector
# define LEX        std::lexicographical_compare
# define MAP        std::map
# define SET        std::set
#endif

# include <iostream> 
# include <utility>
# include <map>
# include <string>
# include <vector>
# include "../includes/utils/pairs.hpp"
# include "../includes/utils/equal.hpp"
# include "../includes/utils/enable_if.hpp"
# include "../includes/utils/is_integral.hpp"
# include "../includes/utils/lex_compare.hpp"
# include "../includes/utils/reverse_iterator.hpp"
# include "../includes/Containers/Stack.hpp"
# include "../includes/Containers/Vector.hpp"
# include "../includes/Containers/Map.hpp"
# include "../includes/Containers/Set.hpp"

void test_pairs(void);
void test_equal(void);
void test_stack(void);
void test_reverse_iterators(void);
void test_lex_comp(void);
void test_vectors(void);
void test_map(void);
void test_set(void);

#endif