#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX], queue[MAX];
int front = -1, rear = -1;
void bfs(int start, int n) {
   int i;
   printf("BFS Traversal: ");
   visited[start] = 1;
   queue[++rear] = start;
   while (front != rear) {
       start = queue[++front];
       printf("%d ", start);
       for (i = 0; i < n; i++) {
           if (adj[start][i] && !visited[i]) {
               queue[++rear] = i;
               visited[i] = 1;
           }
       }
   }
}
int main() {
   int n, i, j, start;
   printf("Enter the number of vertices: ");
   scanf("%d", &n);
   printf("Enter the adjacency matrix:\n");
   for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
           scanf("%d", &adj[i][j]);
       }
   }
   printf("Enter the starting vertex: ");
   scanf("%d", &start);
   for (i = 0; i < n; i++) visited[i] = 0;
   bfs(start, n);
   return 0;
}
