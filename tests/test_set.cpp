/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:12:45 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/24 14:23:48 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

// template <class T>
// void	print(SET<T>& lst)
// {
// 	for (typename SET<T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << *it << '\n';
// }

// void test_set()
// {
//   SET<int> myset;
//   SET<int>::iterator it;

//   // insert some values:
//   for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

//   it = myset.begin();
//   ++it;                                         // "it" points now to 20
    
//   myset.erase (it);
//   myset.erase (40);


//   it = myset.find (60);
//   myset.erase (it, myset.end());

//   std::cout << "myset contains:";
//   for (it=myset.begin(); it!=myset.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return;
// }

#include <list>

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "value: " << *iterator;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_SET>
void	printSize(T_SET const &st, bool print_content = 1)
{
	std::cout << "max_size: " << st.max_size() << std::endl;
	if (print_content)
	{
		typename T_SET::const_iterator it = st.begin(), ite = st.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "size: " << st.size() << std::endl;
	std::cout << "###############################################" << std::endl;
}

template <typename T1>
void	printReverse(ft::set<T1> &st)
{
	typename ft::set<T1>::iterator it = st.end(), ite = st.begin();

	std::cout << "printReverse:" << std::endl;
	while (it-- != ite)
		std::cout << "-> " << printPair(it, false) << std::endl;
	std::cout << "_______________________________________________" << std::endl;
}
#include <list>

#define T1 std::string

static int iter = 0;

template <typename ST, typename U>
void	ft_erase(ST &st, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.erase(param);
	printSize(st);
}

template <typename ST, typename U, typename V>
void	ft_erase(ST &st, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.erase(param, param2);
	printSize(st);
}

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(std::string((lst_size - i), i + 65));
	ft::set<T1> st(lst.begin(), lst.end());
	printSize(st);

	ft_erase(st, ++st.begin());

	ft_erase(st, st.begin());
	ft_erase(st, --st.end());

	ft_erase(st, st.begin(), ++(++(++st.begin())));
	ft_erase(st, --(--(--st.end())), --st.end());

	st.insert("Hello");
	st.insert("Hi there");
	printSize(st);
	ft_erase(st, --(--(--st.end())), st.end());
   
	st.insert("ONE");
	st.insert("TWO");
	st.insert("THREE");
	st.insert("FOUR");
	printSize(st);
	ft_erase(st, st.begin(), st.end());

	return (0);
}
