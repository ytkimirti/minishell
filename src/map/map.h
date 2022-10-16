

#ifndef MAP_H
#define MAP_H

struct s_map{
    char    **data;
    int     size;
};
typedef struct s_map    t_map;

t_map   *create_map(int size);
void    destroy_map(t_map *map);
void    map_insert(t_map *map, char *key, char *value);
void	map_remove(t_map *map, char *key);
char	*map_get(t_map *map, char *key);
void	copy_map(t_map *map_dst, t_map *map_src);

#endif //MAP_H
