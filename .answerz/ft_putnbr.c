/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouvenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:30:00 by tjouvenc          #+#    #+#             */
/*   Updated: 2024/09/25 17:42:51 by tjouvenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_rec(int nbr)
{
	if (nbr == 0)
		return ;
	ft_putnbr_rec(nbr / 10);
	ft_putchar('0' + (nbr % 10));
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nbr == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
		}
		ft_putnbr_rec(nbr);
	}
}
