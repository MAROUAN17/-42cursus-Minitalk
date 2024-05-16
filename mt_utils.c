/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:06 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/09 12:10:21 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	expected_bytes(char *binary)
{
	int	bits;
	int	index;

	index = 0;
	bits = 0;
	while (*(binary + index) && *(binary + index) == '1')
	{
		bits++;
		index++;
	}
	return (bits);
}

int	check_null_terminator(char *string)
{
	int	i;
	int	all_zeros;

	i = 0;
	all_zeros = 0;
	while (*(string + i) && *(string + i) == '0')
	{
		all_zeros++;
		i++;
	}
	return (all_zeros);
}

int	check_pid(char *pid)
{
	int	i;
	int	is_char;

	i = 0;
	is_char = 0;
	while (*(pid + i) && is_char == 0)
	{
		if (!(*(pid + i) >= '0' && *(pid + i) <= '9'))
			is_char = 1;
		i++;
	}
	return (is_char);
}
