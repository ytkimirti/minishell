/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_state.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:28:03 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 15:29:27 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_STATE_H

# define TOKENIZE_STATE_H

# include <stdbool.h>

typedef struct s_state
{
	bool	in_quotes;
}	t_state;

#endif
