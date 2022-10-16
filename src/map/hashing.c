/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:56:39 by emakas            #+#    #+#             */
/*   Updated: 2022/10/16 14:00:06 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	hashcode(void *data)
{
	char	*cdata;
	int		index;
	int		code;

	cdata = (char *) data;
	index = 0;
	code = 0;
	while (cdata[index] != 0)
	{
		code += (int)cdata[index] * (index + 1);
		index++;
	}
}