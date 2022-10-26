//
// Created by master on 16.10.2022.
//

#ifndef HASHING_H
# define HASHING_H

# include <unistd.h>

typedef int t_hash;

/**
 * @brief Generates unique hashcode from data
 * @param data to be hashed
 * @return unique hash number
 */
t_hash hashcode(void *data, size_t n);

/**
 * @brief Generates unique hashcode from null terminated string
 * its the same as hashcode(*str, strlen(str))
 * @param null terminated string
 * @return unique hash number
 */
t_hash hashcode_str(const char *str);

#endif //HASHING_H
