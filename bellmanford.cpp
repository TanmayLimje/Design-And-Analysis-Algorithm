#include <iostream>
#include <string.h>
using namespace std;

struct Edge
{
	char u, v;
	int wt;
};

struct Graph
{
	int V;
	int E;
	struct Edge* edge;
};

class pathfinder
{
	private:
		struct Graph* graph;
		int vertices, edges;
		char vertex_arr[20];
		char source;
	
	public:
		void input();
		void display();
		void bellmanford();
		void resultshower();
		
};

void pathfinder::input()
{
	int v,e;
	
	cout << "Enter number for Vertices: ";
	cin >> v;
	
	cout << "Enter number of Edges: ";
	cin >> e;
	
	graph->V = v;
	graph->E = e;
	
	cout << "Enter the names of vertices:" << endl;
	for (int i = 0; i < v; i++)
		cin >> vertex_arr[i];
	
	
}

int main()
{
	int ch;
	
	pathfinder p;
	
	cout << "---------------------------WELCOME-----------------------------" << endl;
	cout << "FIND THE SHORTEST PATH FOR A GRAPH USING BELLMAN FORD ALGORITHM" << endl;
	
	while(ch != 5)
	{		
		cout << "1. Input" << endl;
		cout << "2. Display" << endl;
		cout << "3. Use Bellman Ford" << endl;
		cout << "4. Show Result" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >>  ch;			
		
		switch(ch)
		{
			case 1:
				p.input();
				break;
			case 2:
				p.display();
				break;
			case 3:
				p.bellmanford();
				break;
			case 4:
				p.resultshower();
				break;
			case 5:	
				exit(0);
				break;
			default:
				cout<<"Enter Valid Choice!"<<endl;
				break;
			
		}
	}
	
	return 0;
}

