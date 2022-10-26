//
// Created by master on 16.10.2022.
//

#ifndef HASHING_H
#define HASHING_H

typedef int t_hash;

/**
 * @brief Generates unique hashcode from data
 * @param data to be hashed
 * @return unique hash number
 */
t_hash hashcode(void *data, size_t n);

#endif //HASHING_H
