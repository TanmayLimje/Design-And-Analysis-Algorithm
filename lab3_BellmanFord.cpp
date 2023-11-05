// bellmanford

#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int source, dest, weight;
};

struct Graph{
    int V, E;
    struct Edge * edge;
};

struct Graph * createGraph(int V, int E)
{
    struct Graph * graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    return graph;
}

void printArr(int data[], int V)
{
    for(int i = 0; i < V; i++)
    {
        cout << "\t" << data[i];
    }
    cout << '\n' ;
}

void bellmanFord(struct Graph * graph, int source)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    int i = 0;

    for( i = 0; i < V-1; i++)
    {
        cout << "Iterations " << i << ":" ;
        printArr(dist,V);

        for(int j = 0; j < E; j++)
        {
            int v = graph->edge[i].dest;
            int u = graph->edge[i].source;
            int w = graph->edge[i].weight;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
     for (int j = 0; j < E; j++)
     {
         int v = graph->edge[i].dest;
         int u = graph->edge[i].source;
         int w = graph->edge[i].weight;

         if(dist[u] != INT_MAX && dist[u] + w < dist[v])
         {
            cout << "Graph has negative cycle!" << endl;
            cout << "final iteraion: ";
             printArr(dist,V);
            cout << endl;
            return ;
         }
     }

     cout << "Final iteraiont: ";
    printArr(dist,V);
    return ;
}

int main()
{
    int V, E, Source;

    cout << "Enter no of vertices: ";
    cin >> V;

    cout << "Enter no of Edges: ";
    cin >> E;

    struct Graph * graph = createGraph(V,E);

    for (int i = 0; i < E; i++)
    {
        cout << "Enter source of Edge " << i+1 << ":";
        cin >> graph->edge[i].source;

        cout << "Enter destination of Edge " << i+1 << ':';
        cin >> graph->edge[i].dest;

        cout << "Enter weight of Edge " << i+1 << ":";
        cin >> graph->edge[i].weight;

        cout << "\n";
    }

    Source = graph->edge[0].source;

    bellmanFord(graph,Source);

    return 0;
}

/*

Enter no of vertices:5
 Enter no of Edges:6
 Enter source of Edge 1:1
Enter destination of Edge 1:2
Enter weight of Edge 1:2

Enter source of Edge 2:1
Enter destination of Edge 2:3
Enter weight of Edge 2:4

Enter source of Edge 3:2
Enter destination of Edge 3:4
Enter weight of Edge 3:2

Enter source of Edge 4:3
Enter destination of Edge 4:4
Enter weight of Edge 4:4

Enter source of Edge 5:3
Enter destination of Edge 5:5
Enter weight of Edge 5:3

Enter source of Edge 6:4
Enter destination of Edge 6:5
Enter weight of Edge 6:-5

Iterations 0:   2147483647      0       2147483647      2147483647      2147483647
Iterations 1:   2147483647      0       2       2147483647      2147483647
Iterations 2:   2147483647      0       2       4       2147483647
Iterations 3:   2147483647      0       2       4       4
Graph has negative cycle!
final iteraion:         2147483647      0       2       4       4

*/
