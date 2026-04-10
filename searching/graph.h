#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 100

typedef struct node {
	int vertex;
	struct node *next;
} node;

typedef struct {
	node *head[MAX_VERTICES];
	int num_vertices;
} graph;

node *create_node(int vertex);
graph *create_graph(int vertices);
void add_edge(graph *g, int src, int dest);
void print_graph(graph *g);
void free_graph(graph *g);

void bfs(graph *g, int start_vertex);
void dfs(graph *g, int start_vertex);

#endif
