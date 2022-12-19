
#ifndef GC_H
# define GC_H
# include <stdlib.h>

/**
 * Flushes all data that allocated.
 * It should be used only when exiting the program
 *
 */
void	gc();

/**
 * The new() function allocates a memory area.
 * It differs from malloc(t_size) in that when you use new(t_size),
 * the allocated memory is tracked for garbage collection with gc().
 *
 * @param size size of the data will be allocated
 */
void	*new(size_t size);

#endif
