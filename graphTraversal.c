#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX], visited[MAX], queue[MAX];
int front = 0, rear = -1;

void bfs(int start, int n) {
    printf("The nodes which are reachable from %d: ", start + 1);
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int curr = queue[front++];
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    // Print reachable nodes, excluding the starting node
    for (int i = 1; i <= rear; i++) {
        printf("%d ", queue[i] + 1);  // Convert back to 1-based indexing
    }
    printf("\n");
}

void dfs(int curr, int n) {
    if (!visited[curr]) {
        printf("%d ", curr + 1);  // Convert back to 1-based indexing
        visited[curr] = 1;
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] && !visited[i]) dfs(i, n);
        }
    }
}

int main() {
    int n, start, choice;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("1.BFS  2.DFS  3.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    start--;  // Adjust input for 0-based indexing

    for (int i = 0; i < n; i++) visited[i] = 0;
    if (choice == 1) bfs(start, n);
    else if (choice == 2) {
        printf("DFS: ");
        dfs(start, n);
        printf("\n");
    } else printf("Invalid choice\n");

    return 0;
}
