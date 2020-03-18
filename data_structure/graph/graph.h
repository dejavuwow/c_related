#ifndef GRAPH_H
#define GRAPH_H
void graph_init(Graph *graph, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));
void graph_destroy(Graph *graph);
int graph_ins_vertex(Graph *graph, const void *data);
int graph_ins_edge(Graph *graph, const void *data1, const void *data2);
int graph_rem_vertex(Graph *graph, void **data);
int graph_rem_edge(Graph *graph, const void *data1, const void **data);
int graph_adjlist(Graph *graph, const void *data, AdjList **adjlist);
int graph_is_adjacent(Graph *graph, const void *data1, const void *data2);
List graph_adjlists(const Graph *graph);
int graph_vcount(const Graph *graph);
int graph_ecount(const Graph *graph);
#endif
