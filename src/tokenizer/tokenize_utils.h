/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:44:41 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/17 20:16:49 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_UTILS_H

# define TOKENIZE_UTILS_H

# include <stdbool.h>

bool	is_metacharacter(char c);

bool	is_valid_var_name(char c);

/*
 * Looks at that character and after that character.
*/
bool	is_valid_var(const char *str);

#endif