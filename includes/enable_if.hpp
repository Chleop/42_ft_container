/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:52:45 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/11 19:09:12 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

#include <iostream>

namespace ft
{
    template< bool B, class T = void >
    struct enable_if {};

// Specialisation complete du template 
// Si le type envoye a enable_if est true, enable_if va posseder une variable type
// Et la fonction sera activee
// Sinon pas de variable type et la fonction est ignoree par le compilateur
    template<class T>
    struct enable_if<true, T> { typedef T type; };
}

#endif