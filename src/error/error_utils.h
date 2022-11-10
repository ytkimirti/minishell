/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:22:09 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/10 17:55:11 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_UTILS_H

# define ERROR_UTILS_H

# include "token.h"

typedef struct s_errdata
{
	t_token		**tokens;
	char		*line;
	bool		is_tracing;
}	t_errdata;

t_errdata	*get_errdata_singleton(void);

#endif
