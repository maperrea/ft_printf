/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:32:38 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/06 17:34:38 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned long long n, int base_size)
{
	int size;

	size = 0;
	while (n > 0)
	{
		n = n / base_size;
		size++;
	}
	return (size);
}

char		*ft_utoa_base(unsigned long long n, const char *base)
{
	int					size;
	char				*nbr;
	int					base_size;

	size = n <= 0 ? 1 : 0;
	base_size = ft_strlen(base);
	size += get_size(n, base_size);
	if (!(nbr = ft_calloc(1, sizeof(char) * (size + 1))))
		return (NULL);
	size--;
	while (size >= 0)
	{
		nbr[size] = base[n % base_size];
		size--;
		n = n / base_size;
	}
	return (nbr);
}
