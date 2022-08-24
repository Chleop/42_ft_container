/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_RBT.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:37:28 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/18 12:56:38 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include "../includes/RBT.hpp"
#include <deque>
#include <utility>

 
int main()
{
// Default constructor
    ft::RedBlackTree<ft::pair<char, int>, std::less<ft::pair<char, int> > > mymap;
    ft::RedBlackTree<ft::pair<char, int>, std::less<ft::pair<char, int> > >::iterator it;

    mymap.insert(ft::make_pair<char, int>('a', 50));
    mymap.insert(ft::make_pair<char, int>('b', 100));
    mymap.insert(ft::make_pair<char, int>('c', 150));
    mymap.insert(ft::make_pair<char, int>('d', 200));

  it = mymap.find(ft::make_pair<char, int>('b', 100));
  if (it != mymap.end())
    mymap.erase (ft::make_pair<char, int>('b', 100));

//   print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find(ft::make_pair<char, int>('a', 50))->second << '\n';
  std::cout << "b => " << mymap.find(ft::make_pair<char, int>('b', 100))->second << '\n';
  std::cout << "c => " << mymap.find(ft::make_pair<char, int>('c', 150))->second << '\n';
  std::cout << "d => " << mymap.find(ft::make_pair<char, int>('d', 200))->second << '\n';


ft::RedBlackTree<int, std::less<int> > myrbt;

// Test size
    std::cout << "Size of myrbt is : " << myrbt.size() << std::endl;

// Test insert function
    std::cout << "TESTING INSERT" << std::endl;
    myrbt.insert(50);
    myrbt.insert(10);
    myrbt.insert(40);
    myrbt.insert(60);
    myrbt.insert(9);
    myrbt.insert(1);
    myrbt.insert(7);
    myrbt.insert(88);
    myrbt.insert(889);
    myrbt.visualize();

// Test iterators()
    ft::RedBlackTree<int, std::less<int> >::iterator itu = myrbt.begin();

    std::cout << std::endl << "### ITERATORS TEST 1 ###" << std::endl;
    while (itu != myrbt.end()){
        std::cout << "Node = " << *itu << std::endl;
        itu++;
    }

// Test iterators() 2
    ft::RedBlackTree<int, std::less<int> >::iterator it2 = --myrbt.end();
    ft::RedBlackTree<int, std::less<int> >::iterator it3 = --myrbt.begin();

    std::cout << std::endl << "### ITERATORS TEST 2 ###" << std::endl;
    while (it2 != it3){
        std::cout << "Node = " << *it2 << std::endl;
        it2--;
    }

// // Test reverse iterators()
//     ft::RedBlackTree<int, std::less<int> >::reverse_iterator it4 = myrbt.rbegin();
//     int h = 0;

//     std::cout << std::endl << "### REVERSE ITERATORS TEST 1 ###" << std::endl;
//     while (it4 != myrbt.rend() && h < 10){
//         std::cout << "Node = " << *it4 << std::endl;
//         it4++;
//         h++;
//     }

// // Test reverse iterators() 2
//     ft::RedBlackTree<int, std::less<int> >::reverse_iterator it6 = myrbt.rend();
//     ft::RedBlackTree<int, std::less<int> >::reverse_iterator it7 = myrbt.rbegin();

//     std::cout << std::endl << "### REVERSE ITERATORS TEST 2 ###" << std::endl;
//     while (it6 != it7){
//         std::cout << "Node = " << *it6 << std::endl;
//         it6--;
//     }

// // Test delete function
//     std::cout << std::endl << "### DELETE TEST ###" << std::endl;
//     std::cout << std::endl << "ERASE 50" << std::endl;
//     myrbt.erase(50);
//     std::cout << std::endl << "ERASE 60" << std::endl;
//     myrbt.erase(60);
//     std::cout << std::endl << "ERASE 10" << std::endl;
//     myrbt.erase(10);
//     std::cout << std::endl << "ERASE 9" << std::endl;
//     myrbt.erase(9);
//     std::cout << std::endl << "ERASE 40" << std::endl;
//     myrbt.erase(40);
//     myrbt.visualize();

// // Test iterators
//     ft::RedBlackTree<int, std::less<int> >::iterator itu = myrbt.begin();

//     std::cout << std::endl << "### ITERATORS TEST 1 ###" << std::endl;
//     while (itu != myrbt.end()){
//         std::cout << "Node = " << *itu << std::endl;
//         itu++;
//     }

// // Test delete last node
//     std::cout << std::endl << "### DELETE LAST NODE TEST ###" << std::endl;
//     std::cout << std::endl << "ERASE 1" << std::endl;
//     myrbt.erase(1);
//     std::cout << std::endl << "ERASE -7" << std::endl;
//     myrbt.erase(7);
//     std::cout << std::endl << "ERASE -88" << std::endl;
//     myrbt.erase(88);
//     std::cout << std::endl << "ERASE -889" << std::endl;
//     myrbt.erase(889);
//     myrbt.visualize();

// // Test begin()
//     std::cout << std::endl << "### BEGIN TEST ###" << std::endl;
//     std::cout << "BEGIN = " << *myrbt.begin() << std::endl;

// // Test end()
//     std::cout << std::endl << "### END TEST ###" << std::endl;
//     std::cout << "END = " << *(myrbt.end()) << std::endl;


ft::RedBlackTree<int, std::less<int> > myrbt2;
int myints[] = {16, 2, 77, 29, 66, 88, 777, 22};
std::deque<int> deq(myints, myints + sizeof(myints) / sizeof(int) );

// // Test insert 2
//     std::cout << "TESTING INSERT BY ITERATORS" << std::endl;
    myrbt2.insert(deq.begin(), deq.end());
// // Test iterators
    ft::RedBlackTree<int, std::less<int> >::iterator iter = myrbt2.begin();

//     std::cout << std::endl << "### ITERATORS TEST COPY DEQUE ###" << std::endl;
//     while (iter != myrbt2.end()){
//         std::cout << "Node = " << *iter << std::endl;
//         iter++;
//     }
// // Test erase by iterators
//     std::cout << "TESTING ERASE BY ITERATORS" << std::endl;
//     std::deque<int>::iterator first = deq.begin();
//     std::deque<int>::iterator last = deq.begin() + 4;
//     for (; first < last ; first++) {
//             myrbt2.erase(*first);
//         }
//     std::cout << std::endl << "### TESTING COPY DEQUE ###" << std::endl;
//     iter = myrbt2.begin();
//     while (iter != myrbt2.end()){
//         std::cout << "Node = " << *iter << std::endl;
//         iter++;
//     }

//     // myrbt2.swap(myrbt);
//     iter = myrbt2.begin();
//     while (iter != myrbt2.end()){
//         std::cout << "Node = " << *iter << std::endl;
//         iter++;
//     }

//     std::cout << (myrbt2 < myrbt) << std::endl;

//     std::deque<int> deq2(deq);
//     ft::RedBlackTree<int, std::less<int> > myrbt3;
//     ft::RedBlackTree<int, std::less<int> > myrbt4;
//     myrbt3.insert(deq2.begin(), deq2.end());
//     std::cout << std::endl << "### TESTING OPERATOR =  AND == ###" << std::endl;
//     myrbt4 = myrbt3;
//     std::cout << (myrbt4 == myrbt3) << std::endl;

//     iter = myrbt2.begin();
//     while (iter != myrbt2.end()){
//         std::cout << "Node = " << *iter << std::endl;
//         iter++;
//     }

//     std::cout << std::endl << "### TESTING FIND ###" << std::endl;
//     iter = myrbt2.begin();
//     while (iter != myrbt2.find(88)){
//         std::cout << "Node = " << *iter << std::endl;
//         iter++;
//     }

    std::cout << std::endl << "### TESTING LOWER BOUND ###" << std::endl;
    iter = myrbt2.lower_bound(88);
    std::cout << "lower_bound = " << *iter << std::endl;

    std::cout << std::endl << "### TESTING UPPER BOUND ###" << std::endl;
    iter = myrbt2.upper_bound(88);
    std::cout << "upper_bound = " << *iter << std::endl;

    std::cout << std::endl << "### TESTING EQUAL RANGE ###" << std::endl;
    std::cout << "equal_range first = " << *(myrbt2.equal_range(67).first) << std::endl;
    std::cout << "equal_range second = " << *(myrbt2.equal_range(67).second) << std::endl;

    std::cout << std::endl << "### TESTING EQUAL RANGE ###" << std::endl;
    std::cout << "equal_range first = " << *(myrbt2.equal_range(22).first) << std::endl;
    std::cout << "equal_range second = " << *(myrbt2.equal_range(22).second) << std::endl;

//     return 0;
}