/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:22:26 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 11:39:20 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_UTILS_H

# define PROMPT_UTILS_H

char	*get_git_branch(void);

/*
 * Returns NULL if no prefix is found at the start
 * of str. Otherwise returns a new heap allocated null
 * terminated string with the replaced prefix.
 */
char	*replace_prefix(const char *str,
			const char *prefix,
			const char *new_prefix);

#endif
