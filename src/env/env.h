/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:11:23 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/15 15:04:25 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H

# define ENV_H

/*
 * Returns a string representing only the env part of
 * the string. So get_env("USER") is just ytkimirti.
 * The returned string should NOT be freed by the user.
 * It is just a pointer to the internal string
 * */
const char	*get_env(const char *key, int len);

/*
 * Returns length of the value of the env
 */
int			get_env_length(const char *key, int len);

/*
 * Returns a heap allocated array of pointers to full
 * environment strings. For example "USER=ytkimirti"
 *
 * The holded strings should not be freeable. So no string
 * duplicating is required when implementing the function.
 */
char		**extract_env(void);

/*
 * Updates the internal $PWD variable using getcwd. If
 * none exist, it creates one.
 *
 * Since this is the only dynamically changing environment
 * variable, we only need this function.
 */
void		update_pwd_variable(void);

/*
 *	If no entry is found with key. A new one is created and
 *	internally a new string is created with format "key=value".
 *
 *	This can also be used to edit environment variables.
 */
void		set_env(const char *key, const char *value);

/*
 * Deletes an environment variable from the list. Users can
 * delete every environment variable.
 */
void		unset_env(const char *key, int len);

/*
 * This is used for testing
 */
void		free_env_singleton(void);

/*
 * Init all standard environment variables from outside
 */
void		init_env(char **envp);

/*
 * Returns a non freeable string which is like this
 * path[index] + '/' + executable_name
 *
 * So if you have /bin in index 0 of your path
 * get_joined_path("ls", 0);
 * returns you
 * "/bin/ls"
 */
const char	*get_joined_path(const char *executable_name, int index);

/*
 * This must be executed whenever the PATH environment
 * variable changes.
 */
void		update_path(void);

/*
 * Tries to find executable in path. If found, returns
 * the path of the executable. Else returns NULL
 */
const char	*find_executable(const char *name);

#endif
