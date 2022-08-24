/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_equal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:39:33 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/13 14:10:35 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

bool pred(int i, int j)
{
    return (i != j);
}

void test_equal(void)
{
    std::cout << "#####$      TEST EQUAL      #####" << std::endl;
    int v1[] = { 10, 20, 30, 40, 50 };
    std::vector<int> vector_1 (v1, v1 + sizeof(v1) / sizeof(int) );
 
    if ( EQUAL (vector_1.begin(), vector_1.end(), v1) )
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";

    if ( EQUAL (vector_1.begin(), vector_1.end(), v1, pred) )
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";

    return;
}
