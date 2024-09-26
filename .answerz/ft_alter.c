/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouvenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:56:14 by tjouvenc          #+#    #+#             */
/*   Updated: 2024/09/26 15:02:41 by tjouvenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void ft_putstr_rev(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i = i - 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i % 2 == 1)
		{
			ft_putstr(argv[i]);
		}
		else
		{
			ft_putstr_rev(argv[i]);
		}
		write(1, "\n", 1);
		i++;
	}
}
