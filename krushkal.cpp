#include <iostream>
using namespace std;

class Edge
{
public:
    int u, v, weight;
};

class Kruskal
{
public:
    int parent[100];

    void makeSet(int v)
    {
        parent[v] = v;
    }

    int findSet(int v)
    {
        if (parent[v] == v)
            return v;

        return findSet(parent[v]);
    }

    void unionSet(int u, int v)
    {
        u = findSet(u);
        v = findSet(v);

        parent[v] = u;
    }

    void sortEdges(Edge edge[], int E)
    {
        for (int i = 0; i < E - 1; i++)
        {
            for (int j = i + 1; j < E; j++)
            {
                if (edge[i].weight > edge[j].weight)
                {
                    Edge temp = edge[i];
                    edge[i] = edge[j];
                    edge[j] = temp;
                }
            }
        }
    }

    void findMST(Edge edge[], int V, int E)
    {
        for (int i = 1; i <= V; i++)
            makeSet(i);

        int count = 0;

        cout << "Edges in MST:\n";

        for (int i = 0; i < E; i++)
        {
            int u = edge[i].u;
            int v = edge[i].v;

            if (findSet(u) != findSet(v))
            {
                cout << u << " - " << v
                     << " : " << edge[i].weight << endl;

                unionSet(u, v);
                count++;

                if (count == V )
                    break;
            }
        }
    }
};

int main()
{
    int V, E;
    Edge edge[100];
    Kruskal k;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].weight;

    k.sortEdges(edge, E);

    k.findMST(edge, V, E);

    return 0;
}