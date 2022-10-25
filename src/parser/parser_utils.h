/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:19:17 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/25 14:22:19 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H

# define PARSER_UTILS_H

# include "parser.h"
# include "libft.h"
# include "vector.h"

int		calculate_length(const t_token **tokens);
char	*get_executable_path(const char *name);
void	expand_all_args(t_cmd *cmd, const t_token **tokens);
char	*expand_tokens(const t_token ***tokens_ref);

#endif
