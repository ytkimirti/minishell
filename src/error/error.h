/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:56:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 17:03:18 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H

# include <stdbool.h>

bool	*error_false(const char *msg);

void	*error_null(const char *msg);

void	error(const char *msg);

void	*malloc_error(void);

#endif
