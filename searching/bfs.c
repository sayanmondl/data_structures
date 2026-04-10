#include <stdio.h>
#include "queue.h"
#include "graph.h"

void bfs(graph *g, int start_vertex)
{
	int visited[MAX_VERTICES] = { 0 };
	queue q;

	init_queue(&q);

	visited[start_vertex] = 1;
	enqueue(&q, start_vertex);

	while (!is_empty(&q)) {
		int current = dequeue(&q);
		printf("%d ", current);

		node *temp = g->head[current];

		while (temp != NULL) {
			int adj_vertex = temp->vertex;

			if (!visited[adj_vertex]) {
				visited[adj_vertex] = 1;
				enqueue(&q, adj_vertex);
			}

			temp = temp->next;
		}
	}
	printf("\n");
}

int main()
{
	graph *g = create_graph(8);

	add_edge(g, 0, 1);
	add_edge(g, 0, 2);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 1, 4);
	add_edge(g, 2, 4);
	add_edge(g, 3, 4);
	add_edge(g, 3, 7);
	add_edge(g, 4, 5);
	add_edge(g, 4, 6);
	add_edge(g, 5, 7);

	print_graph(g);

	printf("BFS: ");
	bfs(g, 0);

	free_graph(g);
	return 0;
}
