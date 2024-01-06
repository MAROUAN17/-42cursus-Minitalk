/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:34:24 by maglagal          #+#    #+#             */
/*   Updated: 2023/12/27 14:07:18 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr(long d, int *ptr_c)
{
	if (d < 0)
	{
		ft_putchar('-', ptr_c);
		d = -d;
	}
	if (d >= 10)
	{
		ft_putnbr(d / 10, ptr_c);
		ft_putnbr(d % 10, ptr_c);
	}
	if (d < 10)
	{
		d = d + 48;
		ft_putchar(d, ptr_c);
	}
}
