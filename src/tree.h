/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:51:45 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/04 16:12:51 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H

# define TREE_H

typedef struct s_node
{
	struct s_node	*left;
	struct s_node	*right;
} t_node;

#endif
