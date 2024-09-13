#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES];

// Function to mark all nodes as unvisited
void initialize() {
  for (int i = 0; i < MAX_VERTICES; i++) {
    visited[i] = 0;
  }
}

// Function to add an edge to the adjacency list
void add_edge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v) {
  graph[u][v] = 1;
  graph[v][u] = 1; // Assuming undirected graph
}

// BFS traversal
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int start) {
  int queue[MAX_VERTICES];
  int front = -1, rear = -1;

  // Enqueue starting node
  queue[++rear] = start;
  visited[start] = 1;

  while (front != rear) {
    // Dequeue a node and print it
    start = queue[++front];
    printf("%d ", start);

    // Enqueue all unvisited adjacent nodes
    for (int v = 0; v < MAX_VERTICES; v++) {
      if (graph[start][v] == 1 && !visited[v]) {
        queue[++rear] = v;
        visited[v] = 1;
      }
    }
  }
}

// DFS traversal
void DFS_recursive(int graph[MAX_VERTICES][MAX_VERTICES], int start) {
  visited[start] = 1;
  printf("%d ", start);

  for (int v = 0; v < MAX_VERTICES; v++) {
    if (graph[start][v] == 1 && !visited[v]) {
      DFS_recursive(graph, v);
    }
  }
}

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int start) {
  initialize();
  DFS_recursive(graph, start);
}

int main() {
  int graph[MAX_VERTICES][MAX_VERTICES] = {0};
  int vertices, edges, u, v;

  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  printf("Enter the edges (u v):\n");
  for (int i = 0; i < edges; i++) {
    scanf("%d %d", &u, &v);
    add_edge(graph, u, v);
  }

  printf("BFS traversal: ");
  initialize();
  BFS(graph, 0); // You can change the starting vertex here

  printf("\nDFS traversal: ");
  DFS(graph, 0); // You can change the starting vertex here

return 0;
}
