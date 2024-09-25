/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:32:53 by jcochet           #+#    #+#             */
/*   Updated: 2024/09/25 16:51:03 by tjouvenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	count_words(char *str)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	// Si la chaine est vide alors on retourne 0 mots
	if (str[0] == '\0')
		return (0);
	while (str[index])
	{
		//On peut mettre une condition sur plusieurs lignes si ca ne rentre pas
		if (!is_space(str[index]) && (is_space(str[index + 1])
				|| str[index + 1] == '\0'))
			count++;
		index++;
	}
	return (count);
}
