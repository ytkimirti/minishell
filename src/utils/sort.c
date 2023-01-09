/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:44:23 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/09 15:51:51 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	swap(void **a, void **b)
{
	void	*t;

	t = *a;
	*a = *b;
	*b = t;
}

void	sort(void **arr, int size, t_compare_func cmp)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (cmp(arr[j], arr[j + 1]) > 0)
			{
				swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}
