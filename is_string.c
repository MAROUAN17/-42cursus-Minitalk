/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:33:30 by maglagal          #+#    #+#             */
/*   Updated: 2023/12/27 14:07:18 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	isstring(const char *string, int *ptr_c)
{
	if (string == 0)
	{
		isstring("(null)", ptr_c);
		return ;
	}
	while (*string != 0)
		ft_putchar(*string++, ptr_c);
}
