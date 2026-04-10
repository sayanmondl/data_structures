#include <stdio.h>
#include "stack.h"
#include "graph.h"

void dfs(graph *g, int start_vertex)
{
	int visited[MAX_VERTICES] = { 0 };
	stack s;

	init_stack(&s);
	push(&s, start_vertex);

	while (!is_stack_empty(&s)) {
		int current = pop(&s);

		if (!visited[current]) {
			visited[current] = 1;
			printf("%d ", current);

			node *temp = g->head[current];

			while (temp != NULL) {
				if (!visited[temp->vertex]) {
					push(&s, temp->vertex);
				}
				temp = temp->next;
			}
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

	printf("DFS: ");
	dfs(g, 0);

	free_graph(g);
	return 0;
}