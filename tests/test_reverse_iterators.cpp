/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_iterators.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:14:00 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/25 15:44:16 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_reverse_iterators (void)
{
    std::cout << "#####$      TEST REVERSE ITERATORS      #####" << std::endl;

    int myints[] = {10, 11, 12, 13};
    VECTOR<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    VECTOR<int>::iterator iter0 = v.begin();
    VECTOR<int>::iterator iter1 = v.end();

// TEST 1
std::cout << "TEST 1" << std::endl;
    REV_ITER<VECTOR<int>::iterator> ri0(iter0);
    REV_ITER<VECTOR<int>::iterator> ri1(iter1);
    std::cout << (*ri0) << std::endl;
    std::cout << (*ri1) << std::endl;
// TEST 2
std::cout << "TEST 2" << std::endl;
    REV_ITER<VECTOR<int>::iterator> ri2 (ri0);
    REV_ITER<VECTOR<int>::iterator> ri3 (ri1);
    std::cout << (*ri2) << std::endl;
    std::cout << (*ri3) << std::endl;
// TEST 3
std::cout << "TEST 3" << std::endl;
    std::cout << (ri2 - ri3) << ' ' << std::endl;
    std::cout << (ri3 - ri2) << std::endl;
// TEST 4
std::cout << "TEST 4" << std::endl;
    std::cout << (*ri2--) << ' ' << std::endl;
    std::cout << (*ri2--) << ' ' << std::endl;
    std::cout << (*ri2) << ' ' << std::endl;
// TEST 5
std::cout << "TEST 5" << std::endl;
    std::cout << (*ri2++) << ' ' << std::endl;
    std::cout << (*ri2) << ' ' << std::endl;
// TEST 6
std::cout << "TEST 6" << std::endl;
    for (int i = 0; i < (int)v.size(); i++)
        std::cout << ri3[i] << std::endl;
// TEST 7
std::cout << "TEST 7" << std::endl;
    int a[] = {0, 1, 2, 3};
    REV_ITER<int*>
        x(a + sizeof(a) / sizeof(int)),
        y(a + sizeof(a) / sizeof(int)),
        z(a + sizeof(int));

    std::cout
        << std::boolalpha
        << "*x == " << *x << std::endl
        << "*y == " << *y << std::endl
        << "*z == " << *z << std::endl
        << "x == y " << (x == y) << std::endl
        << "x != y " << (x != y) << std::endl
        << "x <  y " << (x <  y) << std::endl
        << "x <= y " << (x <= y) << std::endl
        << "x == z " << (x == z) << std::endl
        << "x != z " << (x != z) << std::endl
        << "x <  z " << (x <  z) << std::endl
        << "x <= z " << (x <= z) << std::endl;
    return;
}