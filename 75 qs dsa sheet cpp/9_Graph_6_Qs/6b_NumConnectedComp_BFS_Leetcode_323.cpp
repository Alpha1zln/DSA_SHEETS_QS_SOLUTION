

// 6 - Num of connected comp - in un-directed graph
// Leetcode 323

// adj matrix  ... with bfs

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


// fn prototype
void bfsGraph(int node, int vertices, vector<int>& vis, 
    vector<vector<int>>& adjList);

void printAdjList(int vertices, vector<vector<int>>& adjList);




// main
int main() {
    int vertices = 6; vector<vector<int>> edges = { {1,2}, {6,1}, {3,4}, {2,6} };
    int numEdges = edges.size();

    // vector<int> adjList[vertices + 1];     array of vec 
    // or 
    vector<vector<int>> adjList(vertices+1);    // as 0 idx extra ... so, v+1

    // for adj List
    for(int i=0; i<numEdges; i++) {
        int u = edges[i][0], v = edges[i][1];
        adjList[u].push_back(v); // un-directed graph ... so, u->v ...  v->u too
        adjList[v].push_back(u);
    }

    vector<int> vis(vertices+1, 0);  int connectedComp = 0;
    // check all nodes
    for(int i=1; i<=vertices; i++) {
        if(vis[i]==0) {
            connectedComp++;
            bfsGraph(i, vertices, vis, adjList);
        }
    }

    cout << "Num of connected comp.s : " << connectedComp << endl;
    cout << endl;
    printAdjList(vertices, adjList);

}




// fn definition
void bfsGraph(int node, int vertices, vector<int>& vis, 
    vector<vector<int>>& adjList) 
{
    queue<int> qu;
    qu.push(node);

    while(!qu.empty() ) {
        int size = qu.size();

        for(int i=0; i<size; i++) {
            int elt = qu.front(); qu.pop();
            for(auto nbr : adjList[elt]) {
                if(vis[nbr] == 0) {
                    vis[nbr] = 1;
                    qu.push(nbr);
                }
            }
        }// for
    } // wl
 
}

void printAdjList(int vertices, vector<vector<int>>& adjList){

    for(int i=0; i<=vertices; i++) {
        cout << "Elt : " << i  << " -> " ;
        for(auto e : adjList[i]) {
            cout << e << " ";
        }
        cout << endl;
    }

}


/*

/*
// { {1,2}, {6,1}, {3,4}, {2,6} };
// 1-2-6 and 3-4 and 5

Num of connected comp.s : 3

Elt : 0 ->
Elt : 1 -> 2 6
Elt : 2 -> 1 6
Elt : 3 -> 4
Elt : 4 -> 3
Elt : 5 ->
Elt : 6 -> 1 2
*/