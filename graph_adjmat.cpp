#include <iostream>

#include<bits/stdc++.h> 

using namespace std;


class graph{
    public:
        int n;
        int ** adjMatrix;
    
    graph(int n)
    {
        this->n = n;
        adjMatrix = new int*[n];
        for(int i=1 ; i<=n ; i++)
        {
            adjMatrix[i] = new int[n];
            for(int j=1 ; j<=n ;j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
   
    }

    void addEdge(int n1 , int n2){
        adjMatrix[n1][n2] =1;
        adjMatrix[n2][n1] = 1;
    }

    void print(){
        for(int i=1 ; i<=n ;i++){
            for(int j=1 ; j<=n ;j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    graph obj(4);
    obj.addEdge(1,2);
    obj.addEdge(3,4);
    obj.addEdge(2,4);
    obj.addEdge(1,4);
    obj.print();
    return 0;
}