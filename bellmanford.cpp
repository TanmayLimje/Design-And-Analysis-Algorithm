#include <iostream>
#include <string.h>
using namespace std;
#define INT_MAX 9999999


struct Edge{
    char u, v;
    int wt;
};

struct Graph{
    int V;
    int E;
    struct Edge* edge;
};

class MinimumDistance{
private:
    struct Graph* graph;
    char vertex_array[20],src;
    int vertices, edges;
    bool status = false;
    int distance[20];
    int previous[20];
    int getVertex_i(char c);
    int iterations;

public:
	void showIterations();
    MinimumDistance();
    void input();
    void display();
    void bellmanFord();
    void display_result();
    virtual ~MinimumDistance();
};
MinimumDistance::MinimumDistance(){
    graph = new Graph;
    graph->V = 0;
    graph->E = 0;
}

int MinimumDistance::getVertex_i(char c)
{
    for (int i=0; i<vertices; i++)
    {
        if (c == vertex_array[i])
            return i;
    }
    cout << "Error!"<< endl;
    return -1;
}

void MinimumDistance::input(){
    int v, e;

    cout << "Enter no of Vertices: ";
    cin >> v;
    cout << "Enter no of Edges: ";
    cin >> e;

    graph->V = v;
    graph->E = e;

    cout << "Enter Vertices name: ";
    for(int i=0; i<graph->V; i++) cin >> vertex_array[i];
    cout << "\nEnter 'Starting' 'Ending' 'Weight'" << endl;
    graph->edge = new Edge[graph->E];

    for (int i=0; i<graph->E; i++){
        cout << "Edge " << i+1 << ": " ;
        cin >> graph->edge[i].u >> graph->edge[i].v >> graph->edge[i].wt;
    }

    cout << "\nGraph Created Successfully!\n" << endl;

    cout<<" Enter Source Vertex : ";
    cin>>src;

    status = true;

}

void MinimumDistance::display(){
    if(!status)
    {
        cout<<"Input graph first !!!! \n";
        return;
    }

    cout << "\n-------------------------------\n";
    cout << "Edge Starting Ending  Weight";
    cout << "\n-------------------------------\n";

    for (int i=0; i<graph->E; i++){
        cout << i+1 <<"\t"<< graph->edge[i].u <<"\t"<< graph->edge[i].v <<"\t"<< graph->edge[i].wt<<"\n";
    }
    cout << "\n-------------------------------\n";
}

void MinimumDistance::display_result(){
    if(!status)
    {
        cout<<"Input graph first !!!! \n";
        return;
    }

    cout << "\n------------------------------------\n";
    cout << "Vertex \tDistance \t Path";
    cout << "\n------------------------------------\n";
    for (int i=0; i<graph->V; i++)
    {
        int temp1, target = getVertex_i(src);

        cout << vertex_array[i] << "\t" << distance[i] << "\t\t" << vertex_array[i];
        temp1 = previous[i];

        while(temp1 != target)
        {
            cout << "<-" << vertex_array[temp1];
            temp1 = previous[temp1];
        }

        cout << "<-" << src << endl;
    }
    cout << "\n------------------------------------\n";
}

void MinimumDistance::showIterations()
{
	
}

void MinimumDistance::bellmanFord(){
    if(!status)
    {
        cout<<"Input graph first !!!! \n";
        return;
    }
    int src_index = getVertex_i(src);
    int i, j;

    for (i=0; i<graph->V; i++)
    {
        distance[i] = INT_MAX;
    }

    distance[src_index] = 0;
    previous[src_index] = src_index;

    int temp;
    int u, v;

    for (i=1; i < graph->V; i++)
    {
        for (j=0; j < graph->E; j++)
        {
            u = getVertex_i(graph->edge[j].u);
            v = getVertex_i(graph->edge[j].v);
            temp = distance[u] + graph->edge[j].wt;

            if (distance[u]!=INT_MAX && temp < distance[v])
            {
                distance[v] = temp;
                previous[v] = u;
            }
            
       

        }
        
        //cout << distance[v] << endl;
    }
    
    //cout << distance[v] << " " << previous[v] << endl;

    cout<<"\nBellman Ford Applied Successfully."<<endl;

}

MinimumDistance::~MinimumDistance() {
    delete graph;
}



int main(){
    int choice;
    MinimumDistance M;
    cout<<"=================  WELCOME  =================\n";
    while(1)
    {
        cout<<"\n----------------------------------------------\n";
        cout<<"1. Input"<<endl;
        cout<<"2. Display Graph"<<endl;
        cout<<"3. Apply Bellman Ford"<<endl;
        cout<<"4. Show Iterations" << endl;
        cout<<"5. Result"<<endl;
        cout<<"6. exit"<<endl<<endl;
        cout<< "Enter the Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                M.input();
                break;
            case 2:
                M.display();
                break;
            case 3:
                M.bellmanFord();
                break;
            case 4:
                M.display_result();
                break;
            case 5:
            	M.showIterations();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout<<"Enter Valid Choice..."<<endl<<endl;
                break;
        }

    }

    return 0;
}
