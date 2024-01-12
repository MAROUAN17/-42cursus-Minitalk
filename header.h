/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:56:31 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/09 12:11:34 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int			ft_atoi(const char *str);
int			ft_printf(const char *format, ...);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
int			expected_bytes(char *binary);
int			check_pid(char *pid);

#endif
