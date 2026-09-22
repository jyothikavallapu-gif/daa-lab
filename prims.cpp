#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int V;
    int graph[10][10];

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    int parent[10];
    int key[10];
    bool visited[10];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int min = INT_MAX;
        int u;

        // Find vertex with minimum key
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "\nEdges in MST:\n";

    int total = 0;

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        total = total + graph[i][parent[i]];
    }

    cout << "Total weight = " << total << endl;

    return 0;
}