/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:06:22 by jcochet           #+#    #+#             */
/*   Updated: 2024/09/23 16:17:26 by jcochet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (!ft_is_in_charset(str[i], charset) && str[i])
		i++;
	return (i);
}

int	ft_result_len(char *str, char *charset)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (str[index])
	{
		if (!ft_is_in_charset(str[index], charset)
			&& (ft_is_in_charset(str[index + 1], charset) || !str[index + 1]))
			count++;
		index++;
	}
	return (count);
}

char	*ft_copy_word(char *str, int *cursor, char *charset, char *word)
{
	int	word_len;

	word_len = 0;
	if (ft_is_in_charset(str[*cursor], charset) && *cursor == 0)
		return (NULL);
	word = malloc((ft_word_len(&str[*cursor], charset) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (!ft_is_in_charset(str[*cursor], charset) && str[*cursor])
	{
		word[word_len] = str[*cursor];
		word_len++;
		(*cursor)++;
	}
	word[word_len] = '\0';
	if (*word == '\0')
		return (NULL);
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		cursor;
	int		result_len;

	if (!charset || !str)
		return (NULL);
	result = malloc((ft_result_len(str, charset) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	cursor = 0;
	result_len = 0;
	while (str[cursor])
	{
		result[result_len] = ft_copy_word(
				str, &cursor, charset, result[result_len]);
		if (result[result_len])
			result_len++;
		while (ft_is_in_charset(str[cursor], charset))
			cursor++;
	}
	result[result_len] = 0;
	return (result);
}
