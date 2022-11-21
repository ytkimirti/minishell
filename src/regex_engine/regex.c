/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:46:49 by emakas            #+#    #+#             */
/*   Updated: 2022/11/21 18:57:54 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex.h"
#include <stdlib.h>
#include "libft.h"

static char	*search_str(char *str, char *regex);
static char	*search_forward(char *str, char *position, char *regex);
static char	*search_backward(char *str, char *position, char *regex);

// Garip bir recursive işlemimiz olacak
// En sonda bir imleç işaretçisi dönecek. Onun pozisyonuna göre 1 veya 0 dönecek
int	match_string(char *str, char *regex)
{
	char    *cursor;

	cursor = search_str(str, regex);
	return (ft_strlen(str) == (size_t) ((cursor - str) + 1));
}

static char	*search_str(char *str, char *regex)
{
	char	*cursor;
	int     search_direction;

	search_direction = 1;
	cursor = str;
	if (regex && *regex != '\0')
	{
		if (*regex == '*')
		{
			cursor = jump_last(str);
			search_direction = -1;
		}
		if (search_direction > 0)
			cursor = search_forward(str, cursor, (regex + 1));
		else
			cursor = search_backward(str, cursor, (regex + 1));
	}
	return (cursor);
}

static char	*search_forward(char *str, char *position, char *regex)
{}

static char	*search_backward(char *str, char *position, char *regex)
{}