#include <stdlib.h>
#include <string.h>
#include <graph.h>
#include  "../list.h"
#include  "../set.h"

/** graph init */

void graph_init(Graph *graph, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data))
{
	graph->vcount = 0;
	graph->ecount = 0;
	graph->match = match;
	graph->destroy = destroy;

	list_init(&graph->adjlist, NULL);

	return;
}

void graph_destroy(Graph *graph)
{
	adjlist *adjlist;
	while (list_size(&graph->adjlists) > 0)
	{
		if (list_rem_next(&graph->adjlists, NULL, (void **)&adjlist) == 0)
		{
			set_destroy
		}
	}
}
