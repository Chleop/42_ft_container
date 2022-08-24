/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vectors.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:05:25 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/05 15:05:25 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

// template <typename T>
// void empty_test(T &vect, std::string str)
// {
//     std::cout << std::endl;
// // Size
//     std::cout << str << " size is : " << vect.size() << std::endl;
// // Capacity
//     std::cout << str << " capacity is : " << vect.capacity() << std::endl;
// // Empty
//     std::cout << str << " is empty ? : " << vect.empty() << std::endl;
//     std::cout << std::endl;
// }

// template <typename T>
// void single_test(T &vect, std::string str)
// {
//     std::cout   << std::endl
//                 << "The content of "
//                 << str
//                 << " is : ";
// // Iterators, begin, end
//     for (typename T::iterator it = vect.begin(); it != vect.end(); ++it)
//         std::cout << ' ' << *it;
//     std::cout << std::endl;
// // Max size
//     std::cout << str << " max size is : " << vect.max_size() << std::endl;
// // Size
//     std::cout << str << " size is : " << vect.size() << std::endl;
// // Capacity
//     std::cout << str << " capacity is : " << vect.capacity() << std::endl;
// // // Rbegin
// //     std::cout << str << " rbegin is : " << *(vect.rbegin()) << std::endl;
// // End
//     std::cout << str << " end is : " << *(vect.end() - 1) << std::endl;
// // At
//     std::cout << str << " at is : " << vect.at(2) << std::endl;
// // Front
//     std::cout << str << " front is : " << vect.front() << std::endl;
// // Back
//     std::cout << str << " back is : " << vect.back() << std::endl;
// // Empty
//     std::cout << str << " is empty ? : " << vect.empty() << std::endl;
//     std::cout << std::endl;
//     return;
// }

// void test_vectors(void)
// {
//     std::cout << "#####$      TEST VECTORS      #####" << std::endl;

//     VECTOR<int> first;                                  // empty vector of ints
//     VECTOR<int> second (4, 100);                        // four ints with value 100
//     VECTOR<int> third (second.begin(),second.end());    // iterating through second
//     VECTOR<int> fourth (third);                         // a copy of third
//     int myints[] = {16, 2, 77, 29};                     // iterator constructor used to construct from arrays
//     VECTOR<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
//     VECTOR<int> sixth (6, 666);
//     sixth = fifth;                                      // assignment from smaller vector
//     VECTOR<int> seven (2, 666);                         
//     seven = fifth;                                      // assignment from bigger vector

//     empty_test(first, "first");
//     single_test(second, "second");
//     single_test(third, "third");
//     single_test(fourth, "fourth");
//     single_test(fifth, "fifth");
//     single_test(sixth, "sixth");
//     single_test(seven, "seven");
// // Swap
//     std::cout << "After swapping fifth and second:";
//     fifth.swap(second);
//     single_test(second, "second");
//     single_test(fifth, "fifth");
// // Clear
//     std::cout << "After clearing fourth:";
//     fourth.clear();
//     empty_test(fourth, "fourth");
// // Reserve
//     std::cout << "After reserving 20 elements for second:";
//     second.reserve(20);
//     single_test(second, "second");
// // Insert
//     std::cout << "After inserting 3 elements of fifth inside second:";
//     second.insert(second.begin() + 2, fifth.begin(), fifth.begin() + 3);
//     single_test(second, "second");
// // Assign
//     std::cout << "After assigning elements of second to first:";
//     first.assign(second.begin(), second.end());
//     single_test(first, "first");
//     std::cout << "After assigning elements of 'Array' to fifth, elements:" << std::endl;
//     int array [] = {10,25,36,47,52};
//     fifth.assign(array, array + 4);
//     for (size_t i = 0; i < fifth.size(); i++)
//         std::cout << ' ' << fifth[i];
//     std::cout << std::endl;
// // Resize
//     std::cout << "After resizing elements of fifth to size 2:";
//     fifth.resize(2);
//     for (size_t i = 0; i < fifth.size(); i++)
//         std::cout << ' ' << fifth[i];
//     std::cout << std::endl;
//     std::cout << " size is : " << fifth.size() << std::endl;
//     std::cout << " capacity is : " << fifth.capacity() << std::endl;
//     std::cout << "After resizing elements of fifth to size 11:";
//     fifth.resize(11);
//     for (size_t i = 0; i < fifth.size(); i++)
//         std::cout << ' ' << fifth[i];
//     std::cout << std::endl;
//     std::cout << " size is : " << fifth.size() << std::endl;
//     std::cout << " capacity is : " << fifth.capacity() << std::endl;
// // Push back
//     fifth.push_back(666);
//     fifth.push_back(666);
//     fifth.push_back(666);
//     std::cout << "After pushing back 3 times 666 after fifth:";
//     for (size_t i = 0; i < fifth.size(); i++)
//         std::cout << ' ' << fifth[i];
//     std::cout << std::endl;
//     std::cout << " size is : " << fifth.size() << std::endl;
//     std::cout << " capacity is : " << fifth.capacity() << std::endl;
// // Pop back
//     fifth.pop_back();
//     fifth.pop_back();
//     fifth.pop_back();
//     std::cout << "After poping back 3 times after fifth:";
//     for (size_t i = 0; i < fifth.size(); i++)
//         std::cout << ' ' << fifth[i];
//     std::cout << std::endl;
//     std::cout << " size is : " << fifth.size() << std::endl;
//     std::cout << " capacity is : " << fifth.capacity() << std::endl;
//     std::cout << "Comparing fifth and second:";
//     std::cout << "inferieur : " << (fifth < second) << std::endl;
//     std::cout << "superieur : " << (fifth > second) << std::endl;
//     std::cout << "egal      : " << (fifth == second) << std::endl;
//     std::cout << "different : " << (fifth != second) << std::endl;
//     std::cout << "Comparing fifth and second after equalization:";
//     fifth = second;
//     std::cout << "inferieur : " << (fifth < second) << std::endl;
//     std::cout << "superieur : " << (fifth > second) << std::endl;
//     std::cout << "egal      : " << (fifth == second) << std::endl;
//     std::cout << "different : " << (fifth != second) << std::endl;
//     std::cout << std::endl;
//     return;
// }

template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const int size = vct.size();
	const int capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

#include <list>

#define TESTED_TYPE int

int		main(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	ft::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	printSize(vct);
	return (0);
}
