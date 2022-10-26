/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:16:16 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/26 14:16:29 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHING_H
# define HASHING_H

# include <unistd.h>

typedef int	t_hash;

/**
 * @brief Generates unique hashcode from data
 * @param data to be hashed
 * @return unique hash number
 */
t_hash	hashcode(void *data, size_t n);

/**
 * @brief Generates unique hashcode from null terminated string
 * its the same as hashcode(*str, strlen(str))
 * @param null terminated string
 * @return unique hash number
 */
t_hash	hashcode_str(const char *str);

#endif //HASHING_H
