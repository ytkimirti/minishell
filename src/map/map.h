

#ifndef MAP_H
#define MAP_H

#include "hashing.h"

struct s_entry{
    t_hash  key;
    void    *value;
    struct s_entry *next;
};
typedef struct s_entry  t_entry;

struct s_map{
    t_entry   **entries;
    int       size;
};
typedef struct s_map    t_map;

t_map   *create_map(int size);
void    destroy_map(t_map *map, void (*del)(void *));
void    map_insert(t_map *map, t_hash key, void *value);
void	map_remove(t_map *map, t_hash key, void (*del)(void *));
void	*map_get(t_map *map, t_hash key);
void	copy_map(t_map *map_dst, t_map *map_src);

#endif //MAP_H
