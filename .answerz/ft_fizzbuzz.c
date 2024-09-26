/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouvenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:05:03 by tjouvenc          #+#    #+#             */
/*   Updated: 2024/09/25 18:12:12 by tjouvenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_simple_putnbr(int nb)
{
	// Ne fonctionne qu'avec des entiers a 1 ou 2 chiffres
	// Un putnbr complet marche aussi mais prend plus de temps
	char	c;

	if (nb < 10)
	{
		c = '0' + nb;
		write(1, &c, 1);
	}
	else if (nb < 100)
	{
		c = '0' + (nb / 10);
		write(1, &c, 1);
		c = '0' + (nb % 10);
		write(1, &c, 1);
	}
}

int main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_simple_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}
