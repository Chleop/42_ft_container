/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:42:14 by cproesch          #+#    #+#             */
/*   Updated: 2022/08/25 16:54:51 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
# include <sys/time.h>

int main (void)
{
    struct timeval begin, end;
	gettimeofday(&begin, 0);

    try
    {
        test_pairs();
        test_equal();
        test_lex_comp();
        test_reverse_iterators();
        test_vectors();
        test_stack();
        test_map();
        test_set();
    }
    catch (const std::length_error& le) 
    {
	    std::cerr << "Length error: " << le.what() << std::endl;
    }

    gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	double elapsed = seconds + microseconds*1e-6;

    std::cout << "Time elapsed : " << elapsed << std::endl;
    
    return 0;
}