/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:25 by emakas            #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/10/20 13:16:36 by emakas           ###   ########.fr       */
=======
/*   Updated: 2022/10/26 13:15:41 by emakas           ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_ADAPTER
# define TOKEN_ADAPTER
# include "../tokenizer/token.h"

t_token 	*get_first_word(t_token **tokens);
<<<<<<< Updated upstream

=======
id_t		read_args(t_token **, char ***argv);
>>>>>>> Stashed changes

#endif