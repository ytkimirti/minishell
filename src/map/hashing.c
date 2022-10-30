/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:56:39 by emakas            #+#    #+#             */
/*   Updated: 2022/10/30 17:54:08 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashing.h"
#include "libft.h"
#include <unistd.h>

static t_hash ft_pow(t_hash number, size_t power){
	size_t times;
	t_hash result = 1;

	times = 0;
	while (times < power)
	{
		result *= number;
		times++;
	}
	return (result);
}

t_hash	hashcode(void *data, size_t len)
{
	char	*cdata;
	size_t	index;
	t_hash	code;
	t_hash	prime;
	t_hash	module;

	cdata = (char *) data;
	index = 0;
	code = 0;
	prime = 53;
	module = ~(-1);
	while (index < len)
	{
		code += (t_hash)(cdata[index] * ft_pow(prime, index));
		index++;
	}
	return (code % module);
}

// TODO: Make this faster
t_hash	hashcode_str(const char *str)
{
	return (hashcode((void *)str, ft_strlen(str)));
}
