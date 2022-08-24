/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_enable_if.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:23:10 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/13 14:10:25 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/enable_if.hpp"
#include <type_traits>

#define LIB ft

// Enable_if est utilise pour permettre l'overload de fonction a partir du  
// type de parametre
// "On active cette fonction si ..."
// Si les conditions de type ne sont pas respectees, la fonction est ignoree
// par le compilateur qui cherche alors une autre fonction activable, ou alors
// lance une erreur de compilation

template <class T>
void myfunction(T)
{
    std::cout << "T is signed" << std::endl;
}

// "On active cette fonction si le type recu en parametre est unsigned"
// Ici std::is_unsigned<T>::value va renvoyer true ou false
// et std::enable_if<std::is_unsigned<T>::value>::type va etre active ou desactive 
// en fonction du retour de std::is_unsigned<T>::value
template <class T, class = typename LIB::enable_if<std::is_unsigned<T>::value>::type>
void myfunction(T)
{
    std::cout << "T is unsigned" << std::endl;
}

struct A {};

struct B : A {};

template<class T, class = typename LIB::enable_if<std::is_base_of<A, T>::value>::type>
struct C: T {};

int    main(void)
{
    std::cout << "#####$      TEST ENABLE IF      #####" << std::endl;
    int x = 5;
    // unsigned int y = 5;
    std::cout << "Checking myfunction's result with signed int : " << std::endl;
    myfunction(x);
    // std::cout << "Checking myfunction's result with unsigned int : " << std::endl;
    // myfunction(y);
    C<B> c;
    return 0;
}