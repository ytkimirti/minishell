/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:11:23 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/15 19:18:05 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H

# define ENV_H

/*
 * Returns a string representing only the env part of
 * the string. So get_env("USER") is just ytkimirti.
 * The returned string should not be freed by the user.
 * It is just a pointer to the internal string
 * */
const char	*get_env(const char *name);

/*
 * Returns a heap allocated array of pointers to full
 * environment strings. For example "USER=ytkimirti"
 *
 * The holded strings should not be freeable. So no string
 * duplicating is required when implementing the function.
 */
char		**extract_env();

#endif
