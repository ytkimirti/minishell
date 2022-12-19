
#include "gc.h"
#include "vector.h"

static t_pvec	*get_garbages()
{
	static t_pvec *garbages;

	if (garbages == NULL)
		garbages = pvec_new(10);
}

void	gc()
{
	t_pvec	*garbages;
	int		index;

	garbages = get_garbages();
	index = garbages->len;
	while (index >= 0)
	{
		free(garbages->arr[index]);
		garbages->arr[index] = NULL;
		garbages->len -= 1;
	}
}

void	*new(size_t size)
{
	void	*allocated;
	t_pvec	*garbages;

	allocated = malloc(size);
	garbages = get_garbages();
	pvec_append(garbages, allocated);
	return (allocated);
}

