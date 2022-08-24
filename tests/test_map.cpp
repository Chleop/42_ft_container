/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:37:28 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/10 16:05:03 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
 
// void print_map(std::string comment, const MAP<std::string, int>& m)
// {
//     std::cout << comment ;
//     for (MAP<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++) {
//         std::cout << it->first << " = " << it->second << "; ";
//     }
//     std::cout << '\n';
// }
 
// void test_map()
// {
//     // Default constructor
//     MAP<std::string, int> map1;
//     map1["something"] = 69;
//     map1["anything"] = 199;
//     map1["that thing"] = 199;
//     print_map("1) Initial map   : ", map1);
    
//     // Range constructor
//     MAP<std::string, int> iter(map1.find("something"), map1.end());
//     print_map("2) Iter map      : ", iter);

//     // Copy constructor
//     MAP<std::string, int> copied(map1);
//     print_map("3) Copied map    : ", copied);

//     map1["cPU"] = 25;  // update an existing value
//     map1["DSD"] = 30;  // insert a new value
//     print_map("4) Updated map   : ", map1);
 
//     // using operator[] with non-existent key always performs an insert
//     std::cout << "5) map1[UPS] = " << map1["UPS"] << '\n';
//     print_map("6) Updated map   : ", map1);
 
//     map1.erase("cPU");
//     print_map("7) After erase   : ", map1);
 
//     std::cout << "8) map1.size() = " << map1.size() << '\n';


//     std::cout << std::endl << "### ITERATORS TEST ###" << std::endl;
//     MAP<std::string, int>::iterator it2 = --map1.end();
//     std::cout << "before end = " << it2->first << std::endl;
//     MAP<std::string, int>::iterator it3 = map1.begin();
//     std::cout << "begin = " << it3->first << std::endl;
//     while (it2 != it3){
//         std::cout << "Node = " << it2->first << std::endl;
//         it2--;
//     }

//     std::cout << std::endl << "### REVERSE ITERATORS TEST ###" << std::endl;
//     MAP<std::string, int>::reverse_iterator it4 = ++map1.rend();
//     std::cout << "rend = " << it4->first << std::endl;
//     MAP<std::string, int>::reverse_iterator it5 = map1.rbegin();
//     std::cout << "rbegin = " << it5->first << std::endl;
//     while (it4 != it5){
//         std::cout << "Node = " << it4->first << std::endl;
//         it4--;
//     }
 
//     map1.clear();
//     std::cout << std::boolalpha << "9) Map is empty: " << map1.empty() << '\n';

//     return;
// }


# include <iostream>
# include <string>

// --- Class foo
template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}

#define _pair ft::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T1, typename T2>
void	printReverse(ft::map<T1, T2> &mp)
{
	typename ft::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}


#define T1 char
#define T2 foo<std::string>

int		main(void)
{
	ft::map<T1, T2> mp;

	mp['a'] = "an element";
	mp['b'] = "another element";
	mp['c'] = mp['b'];
	mp['b'] = "old element";

	printSize(mp);

	std::cout << "insert a new element via operator[]: " << mp['d'] << std::endl;

	printSize(mp);
	return (0);
}