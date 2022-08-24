/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:45:29 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/13 14:16:46 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_stack(void)
{
    std::cout << "#####$      TEST STACK      #####" << std::endl;

    std::vector<int> myvector;
    myvector.reserve(20);

    STACK<int> mystack;
    std::cout << "Is my stack empty ? (1 = Yes, 0 = No) = " << mystack.empty() << std::endl;
    std::cout << "Adding -1, 666666666 and 1" << std::endl;
    mystack.push(-1);
    std::cout << "My stack size  = " << mystack.size() << std::endl;
    mystack.push(666666666);
    mystack.push(1);
    std::cout << "Is my stack empty ? (1 = Yes, 0 = No) = " << mystack.empty() << std::endl;
    std::cout << "My stack's top = " << mystack.top() << std::endl;
    std::cout << "My stack size  = " << mystack.size() << std::endl;
    std::cout << "Popping from my stack " << std::endl;
    mystack.pop();
    std::cout << "My stack's top = " << mystack.top() << std::endl;
    std::cout << "My stack size  = " << mystack.size() << std::endl;
    std::cout << "Adding 0" << std::endl;
    mystack.push(0);
    std::cout << "My stack's top = " << mystack.top() << std::endl;
    std::cout << "My stack size  = " << mystack.size() << std::endl;

    STACK<int> mysecondstack;
    STACK<int> mythirdstack;
    mysecondstack = mystack;
    std::cout << "inferieur : " << (mystack < mysecondstack) << std::endl;
    std::cout << "superieur : " << (mystack > mysecondstack) << std::endl;
    std::cout << "egal      : " << (mystack == mysecondstack) << std::endl;
    std::cout << "different : " << (mystack != mysecondstack) << std::endl;
    std::cout << "inferieur : " << (mythirdstack < mystack) << std::endl;
    std::cout << "superieur : " << (mythirdstack > mystack) << std::endl;
    std::cout << "egal      : " << (mythirdstack == mystack) << std::endl;
    std::cout << "different : " << (mythirdstack != mystack) << std::endl;

    VECTOR<std::string> lst;
	lst.push_back("salut");
	lst.push_back("tu vas bien?");
	lst.push_back("super");
	lst.push_back("et toi?");

    STACK<std::string, VECTOR<std::string> >    my_string_stack(lst);

    std::cout << my_string_stack.empty() << std::endl;
    std::string caca = my_string_stack.top();
    std::cout << "top: " << my_string_stack.top() << '\n';
	while (!my_string_stack.empty())
	{
		std::cout << my_string_stack.top() << '\n';
		my_string_stack.pop();
	}
    return;
}
