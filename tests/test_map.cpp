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
 
void print_map(std::string comment, const MAP<std::string, int>& m)
{
    std::cout << comment ;
    for (MAP<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << " = " << it->second << "; ";
    }
    std::cout << '\n';
}
 
void test_map()
{
    // Default constructor
    MAP<std::string, int> map1;
    map1["something"] = 69;
    map1["anything"] = 199;
    map1["that thing"] = 199;
    print_map("1) Initial map   : ", map1);
    
    // Range constructor
    MAP<std::string, int> iter(map1.find("something"), map1.end());
    print_map("2) Iter map      : ", iter);

    // Copy constructor
    MAP<std::string, int> copied(map1);
    print_map("3) Copied map    : ", copied);

    map1["cPU"] = 25;  // update an existing value
    map1["DSD"] = 30;  // insert a new value
    print_map("4) Updated map   : ", map1);
 
    // using operator[] with non-existent key always performs an insert
    std::cout << "5) map1[UPS] = " << map1["UPS"] << '\n';
    print_map("6) Updated map   : ", map1);
 
    map1.erase("cPU");
    print_map("7) After erase   : ", map1);
 
    std::cout << "8) map1.size() = " << map1.size() << '\n';


    std::cout << std::endl << "### ITERATORS TEST ###" << std::endl;
    MAP<std::string, int>::iterator it2 = --map1.end();
    std::cout << "before end = " << it2->first << std::endl;
    MAP<std::string, int>::iterator it3 = map1.begin();
    std::cout << "begin = " << it3->first << std::endl;
    while (it2 != it3){
        std::cout << "Node = " << it2->first << std::endl;
        it2--;
    }

    std::cout << std::endl << "### REVERSE ITERATORS TEST ###" << std::endl;
    MAP<std::string, int>::reverse_iterator it4 = ++map1.rend();
    std::cout << "rend = " << it4->first << std::endl;
    MAP<std::string, int>::reverse_iterator it5 = map1.rbegin();
    std::cout << "rbegin = " << it5->first << std::endl;
    while (it4 != it5){
        std::cout << "Node = " << it4->first << std::endl;
        it4--;
    }
 
    map1.clear();
    std::cout << std::boolalpha << "9) Map is empty: " << map1.empty() << '\n';


    // MAP<int, int> testperf;
    // int i = 0;
    // while(i <1000000){
    //     testperf[i] = i;
    //     i++;}

    return;
}
