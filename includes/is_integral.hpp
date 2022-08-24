/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:24:20 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/22 15:41:48 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL
# define IS_INTEGRAL

namespace ft
{
    
    template<class T, T v>
    struct integral_constant {
    static const T value = v;
    };
    
    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

    template <class T>
    struct is_integral : public false_type{};
    template <>
    struct is_integral<bool> : public true_type{};
    template <>
    struct is_integral<char> : public true_type{};
    template <>
    struct is_integral<signed char> : public true_type{};
    template <>
    struct is_integral<unsigned char> : public true_type{};
    template <>
    struct is_integral<wchar_t> : public true_type{};
    template <>
    struct is_integral<short> : public true_type{};
    template <>
    struct is_integral<int> : public true_type{};
    template <>
    struct is_integral<long> : public true_type{};
    template <>
    struct is_integral<long long> : public true_type{};
    template <>
    struct is_integral<unsigned short> : public true_type{};
    template <>
    struct is_integral<unsigned int> : public true_type{};
    template <>
    struct is_integral<unsigned long> : public true_type{};
    template <>
    struct is_integral<unsigned long long> : public true_type{};

    template <>
    struct is_integral<const bool> : public true_type{};
    template <>
    struct is_integral<const char> : public true_type{};
    template <>
    struct is_integral<const signed char> : public true_type{};
    template <>
    struct is_integral<const unsigned char> : public true_type{};
    template <>
    struct is_integral<const wchar_t> : public true_type{};
    template <>
    struct is_integral<const short> : public true_type{};
    template <>
    struct is_integral<const int> : public true_type{};
    template <>
    struct is_integral<const long> : public true_type{};
    template <>
    struct is_integral<const long long> : public true_type{};
    template <>
    struct is_integral<const unsigned short> : public true_type{};
    template <>
    struct is_integral<const unsigned int> : public true_type{};
    template <>
    struct is_integral<const unsigned long> : public true_type{};
    template <>
    struct is_integral<const unsigned long long> : public true_type{};
    
}

#endif
