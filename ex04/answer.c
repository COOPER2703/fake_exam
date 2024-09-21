/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:32:53 by jcochet           #+#    #+#             */
/*   Updated: 2024/09/21 09:40:00 by jcochet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int count_words(char *str)
{
	int	count;
	int	index;

	count = 0;
	while (str[index])
	{
		if (!is_space(str[index]) && (is_space(str[index + 1]) || !str[index + 1]))
			count++;
		index++;
	}
	return (count);
}
