/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:49:30 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/08 16:54:37 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_number.h"

//TODO subnormals?
//TODO negative input for + and -
//maybe optimize shit by reading longs instead of chars but ugh

int					main(void)
{
	t_big_number	*bn1;
	t_big_number	*bn2;
	t_big_number	*bn3;


//	printf("\033[38;5;5mcomparison : %d\033[0m\n\n", bn_compare(bn1, bn2));
	double n = 255;
	print_bits(&n, 64);
	printf("\n");
	printf("\033[38;5;33mbn1: \n");
	bn1 = dbl_to_bn((double)256.);
	print_bn(bn1);
	printf("binary int:\n");
	print_bits(bn1->int_part, bn1->int_size * 8);
	printf("\nbinary dec:\n");
	print_bits(bn1->decimal_part, bn1->decimal_size * 8);
	printf("\n");
	printf("\n");
	printf("\033[38;5;160mbn2: \n");
	bn2 = dbl_to_bn((double)0.1);
	print_bn(bn2);
	printf("binary int:\n");
	print_bits(bn2->int_part, bn2->int_size * 8);
	printf("\nbinary dec:\n");
	print_bits(bn2->decimal_part, bn2->decimal_size * 8);
	printf("\n");
	printf("\n");
	printf("\033[38;5;2mbn3: \n");
	bn3 = big_number_mult(bn1, bn2);
	print_bn(bn3);
	printf("binary int:\n");
	print_bits(bn3->int_part, bn3->int_size * 8);
	printf("\nbinary dec:\n");
	print_bits(bn3->decimal_part, bn3->decimal_size * 8);
	printf("\n\033[0m");
	
}
