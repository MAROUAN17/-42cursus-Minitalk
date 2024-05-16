/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:24:32 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/09 12:12:16 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_atoi(const char *str);
int			ft_printf(const char *format, ...);
size_t		ft_strlen(const char *s);
int			check_null_terminator(char *string);
int			expected_bytes(char *binary);
int			check_pid(char *pid);

#endif
