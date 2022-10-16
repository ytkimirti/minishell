

#ifndef MAP_H
#define MAP_H

struct s_map{
    char    **data;
    int     size;
};
typedef struct s_map    t_map;

t_map   *create_map(int size);
void    destroy_map(t_map *map);
void    map_insert(char *key, char *value);
void    map_remove(char *key);
char    *map_get(char *key);

#endif //MAP_H