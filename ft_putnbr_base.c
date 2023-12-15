/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:35:05 by maweiss           #+#    #+#             */
/*   Updated: 2023/10/11 15:53:38 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen_check(char *str)
{
	int	strlen;
	int	i;
	int	j;

	i = 0;
	strlen = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+' )
			return (-1);
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] == str[i] && i != j && str[i] != 0)
				return (-1);
			j++;
		}
		strlen++;
		str++;
	}
	if (strlen <= 1)
		return (-1);
	return (strlen);
}

unsigned int	ft_neg(int nbr)
{
	unsigned int	u_inp;

	if (nbr < 0)
	{
		u_inp = nbr * -1;
		ft_putchar('-');
	}
	else
		u_inp = nbr;
	return (u_inp);
}

int	ft_power(unsigned int nbr, int b_len)
{
	int	power;

	power = 0;
	while (nbr >= (unsigned int) b_len)
	{
		nbr /= b_len;
		power++;
	}
	return (power);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				b_len;
	int				power;
	unsigned int	tmp;
	int				div_count;
	unsigned int	u_inp;

	b_len = 0;
	b_len = ft_strlen_check(base);
	if (b_len < 0)
		return ;
	u_inp = ft_neg(nbr);
	power = ft_power(u_inp, b_len);
	while (power >= 0)
	{
		div_count = power;
		tmp = u_inp;
		while (div_count > 0)
		{
			tmp /= b_len;
			div_count--;
		}
		ft_putchar(base[tmp % b_len]);
		power--;
	}
}
