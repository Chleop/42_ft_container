/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lex_comp.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:01:51 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/13 14:11:11 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

void test_lex_comp(void)
{
  std::cout << "#####$      TEST LEXICOGRAPHICAL COMPARE      #####" << std::endl;

  char foo[]="apple";
  char bar[]="apartment";

  std::cout << std::boolalpha;

  std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

  std::cout << "Using default comparison (operator<): ";
  std::cout << LEX(foo,foo+5,bar,bar+9);
  std::cout << '\n';

  // std::cout << "Using mycomp as comparison object: ";
  // std::cout << LEX(foo,foo+5,bar,bar+9,mycomp);
  // std::cout << '\n';

    return;
}
