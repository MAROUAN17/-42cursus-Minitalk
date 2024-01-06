#include "header.h"

int	check_m(const char *str, int *ptr_i)
{
	int	i;
	int	m;

	i = 0;
	m = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13)) 
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	*ptr_i = i;
	return (m);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		m;
	long	res;

	res = 0;
	m = check_m(str, &i);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (m == 1 && (res > 922337203685477580 
				|| (res >= 922337203685477580 && str[i] > '7')))
			return (-1);
		if (m == -1 && (res > 922337203685477580 
				|| (res >= 922337203685477580 && str[i] > '8')))
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(res * m));
}

int ft_atoi_base(char *str)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while(*(str + i) && (*(str + i) == '0' || *(str + i) == '1'))
	{
		res = res * 2 + (*(str + i) - '0');
		i++;
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
