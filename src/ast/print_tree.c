/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:00:36 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/03 13:13:54 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>
#include "colors.h"
#include "libft.h"
#include "utils.h"

static void	print_command(t_command *command)
{
	int	i;

	ft_printf(BYEL "COMMAND" GRN " -> ");
	i = 0;
	while (command->argv[i] != NULL)
	{
		ft_printf(" %s", command->argv[i]);
		i++;
	}
	ft_printf(RST "\n");
}

static void	print_recursive(t_node *node, int depth)
{
	int	i;

	if (node == NULL)
		return ;
	i = 0;
	while (i < depth)
	{
		write(1, "  ", 2);
		i++;
	}
	if (node->type == COMMAND_NODE)
	{
		print_command(node->command);
	}
	else
		ft_printf(BYEL "%s\n" RST, node_type_tostr(node->type));
	if (node->left != NULL)
		print_recursive(node->left, depth + 1);
	if (node->right != NULL)
		print_recursive(node->right, depth + 1);
}

void	print_tree(t_node *root)
{
	print_recursive(root, 0);
}
