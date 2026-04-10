#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

node *create_node(int vertex)
{
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL)
		return NULL;

	new_node->vertex = vertex;
	new_node->next = NULL;
	return new_node;
}

graph *create_graph(int vertices)
{
	if (vertices > MAX_VERTICES)
		return NULL;

	graph *g = malloc(sizeof(graph));
	if (g == NULL)
		return NULL;

	g->num_vertices = vertices;

	for (int i = 0; i < vertices; i++)
		g->head[i] = NULL;

	return g;
}

void add_edge(graph *g, int src, int dest)
{
	node *new_node = create_node(dest);
	new_node->next = g->head[src];
	g->head[src] = new_node;

	new_node = create_node(src);
	new_node->next = g->head[dest];
	g->head[dest] = new_node;
}

void print_graph(graph *g)
{
	for (int i = 0; i < g->num_vertices; i++) {
		printf("%d -> ", i);

		node *temp = g->head[i];
		while (temp != NULL) {
			printf("%d ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

void free_graph(graph *g)
{
	for (int i = 0; i < g->num_vertices; i++) {
		node *temp = g->head[i];

		while (temp != NULL) {
			node *next = temp->next;
			free(temp);
			temp = next;
		}
	}
	free(g);
}
