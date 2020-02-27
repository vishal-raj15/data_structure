#include <iostream>
#include <list>

using namespace std;

class graph
{
    public:
    int v;
    list <int> *adj;

    graph(int v);

    void addedge(int x , int y);

    void bfs(int s);

};

graph::graph(int v)
{
    this->v = v;
    adj = new list<int>[v];

}

void graph::addedge(int x,int y)
{
    adj[x].push_back(y);
}

void graph::bfs(int s)
{
       bool *visited = new bool[v]; 
    for(int i = 0; i < v; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        s = queue.front(); 
        cout << s << " "; 
        
        queue.pop_front(); 
  
        
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    }

}


int main() 
{ 
    // Create a graph given in the above diagram 
    graph g(4); 
    g.addedge(0, 1); 
    g.addedge(0, 2); 
    g.addedge(1, 2); 
    g.addedge(2, 0); 
    g.addedge(2, 3); 
    g.addedge(3, 3);
    //g.addedge(2,1); 
   
    g.bfs(2); 
  
    return 0; 
} 
