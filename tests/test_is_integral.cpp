/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_integral.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:05:14 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/22 17:15:26 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/is_integral.hpp"

struct A{
int a;
int f(int){return 2011;}
};

enum E{
e= 1,
};

union U{
int u;
};


// Main a compiler AVEC LE FLAG c++98
// int test_is_integral (void)
// {
    
// // // ORIGINAL WITH STD LIBRARY TESTS
// //     std::cout << "\033[32m### TESTING STANDARD LIBRARY\033[37m" << std::endl;
// //     std::cout << "char: " << std::is_integral<char>::value << std::endl;
// //     std::cout << "int: " << std::is_integral<int>::value << std::endl;
// //     std::cout << "float: " << std::is_integral<float>::value << std::endl;
// //     std::cout << "double: " << std::is_integral<double>::value << std::endl;
// //     std::cout << "std::string: " << std::is_integral<std::string>::value << std::endl;
// //     std::cout << "const char: " << std::is_integral<const char>::value << std::endl;
// //     std::cout << "const int: " << std::is_integral<const int>::value << std::endl;
// //     std::cout << "const float: " << std::is_integral<const float>::value << std::endl;
// //     std::cout << "const double: " << std::is_integral<const double>::value << std::endl;
// //     std::cout << "const std::string: " << std::is_integral<const std::string>::value << std::endl;
// //     std::cout << "Struct A: " << std::is_integral<A>::value << std::endl;
// //     std::cout << "Enum E: " << std::is_integral<E>::value << std::endl;
// //     std::cout << "Union U: " << std::is_integral<U>::value << std::endl;
    
// // COPY WITH MY FT LIBRARY TESTS
//     std::cout << std::endl << "\033[32m### TESTING MY FT LIBRARY\033[37m" << std::endl;
//     std::cout << "char: " << ft::is_integral<char>::value << std::endl;
//     std::cout << "int: " << ft::is_integral<int>::value << std::endl;
//     std::cout << "float: " << ft::is_integral<float>::value << std::endl;
//     std::cout << "double: " << ft::is_integral<double>::value << std::endl;
//     std::cout << "std::string: " << ft::is_integral<std::string>::value << std::endl;
//     std::cout << "const char: " << ft::is_integral<const char>::value << std::endl;
//     std::cout << "const int: " << ft::is_integral<const int>::value << std::endl;
//     std::cout << "const float: " << ft::is_integral<const float>::value << std::endl;
//     std::cout << "const double: " << ft::is_integral<const double>::value << std::endl;
//     std::cout << "const std::string: " << ft::is_integral<const std::string>::value << std::endl;
//     std::cout << "Struct A: " << ft::is_integral<A>::value << std::endl;
//     std::cout << "Enum E: " << ft::is_integral<E>::value << std::endl;
//     std::cout << "Union U: " << ft::is_integral<U>::value << std::endl;

//     return 0;
// }

#include <type_traits>
int main (void)
{
    std::cout << "#####$      TEST IS INTEGRAL      #####" << std::endl;
    int nb_test = 13;
    bool test[nb_test];
    test[0] = (std::is_integral<char>::value) == (ft::is_integral<char>::value);
    test[1] = (std::is_integral<int>::value) == (ft::is_integral<int>::value);
    test[2] = (std::is_integral<float>::value) == (ft::is_integral<float>::value);
    test[3] = (std::is_integral<double>::value) == (ft::is_integral<double>::value);
    test[4] = (std::is_integral<std::string>::value) == (ft::is_integral<std::string>::value);
    test[5] = (std::is_integral<const char>::value) == (ft::is_integral<const char>::value);
    test[6] = (std::is_integral<const int>::value) == (ft::is_integral<const int>::value);
    test[7] = (std::is_integral<const float>::value) == (ft::is_integral<const float>::value);
    test[8] = (std::is_integral<const double>::value) == (ft::is_integral<const double>::value);
    test[9] = (std::is_integral<const std::string>::value) == (ft::is_integral<const std::string>::value);
    test[10] = (std::is_integral<A>::value) == (ft::is_integral<A>::value);
    test[11] = (std::is_integral<E>::value) == (ft::is_integral<E>::value);
    test[12] = (std::is_integral<U>::value) == (ft::is_integral<U>::value);

    for(int i=0;i<nb_test;i++)
    {
        if(test[i] == true)
            std::cout << "\033[32m[   PASSED   ]\033[37m   Test " << i << std::endl;
        else
            std::cout << "\033[31m[!!!FAILED!!!]\033[37m   Test " << i << std::endl;
    }

    return 0;
}