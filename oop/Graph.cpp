#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph{
    unordered_map<int,vector<int>> adj;
    public:
    void addEdge(int u,int v,bool directed = false){
        adj[u].push_back(v);
        if(!directed){
            adj[v].push_back(u);
        }
    }

    void printGraph() {
        for (auto &pair : adj) {
            cout << pair.first << " -> ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();

    return 0;
}



