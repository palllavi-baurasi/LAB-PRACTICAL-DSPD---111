// Consider the undirected graph G , consisting of n nodes laid out in a 3-by-3 grid : 
// Start searching at node 1 and break ties for exploring the next node based on lower numerical order 
// ( i,e. add node to  a queue low to high , add node to a stack high to low ) . 
// (a) in what order are nodes marked as explored by BFS ? 
// (b) in what order are nodes marked as explored by DFS ? 

#include <stdio.h>
#define N 9

int graph[N + 1][N + 1] = {
    {0},
    {0,0,1,0,1,0,0,0,0,0},   
    {0,1,0,1,0,1,0,0,0,0},   
    {0,0,1,0,0,0,1,0,0,0},   
    {0,1,0,0,0,1,0,1,0,0},   
    {0,0,1,0,1,0,1,0,1,0},   
    {0,0,0,1,0,1,0,0,0,1},   
    {0,0,0,0,1,0,0,0,1,0},   
    {0,0,0,0,0,1,0,1,0,1},   
    {0,0,0,0,0,0,1,0,1,0}    
};

// BFS traversal (queue - add low to high)
void bfs(int start) {
    int visited[N + 1] = {0}, queue[N + 1], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 1; i <= N; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// DFS traversal (stack - add high to low)
void dfs(int start) {
    int visited[N + 1] = {0}, stack[N + 1], top = -1;
    stack[++top] = start;

    printf("\nDFS Traversal: ");
    while (top != -1) {
        int node = stack[top--];
        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);
            // push in high to low order
            for (int i = N; i >= 1; i--) {
                if (graph[node][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}

int main() {
    int start = 1;
    bfs(start);
    dfs(start);
    return 0;
}

/* 
 Output:
 BFS Traversal: 1 2 4 3 5 7 6 8 9 
 DFS Traversal: 1 2 3 6 5 4 7 8 9
*/