#include<iostream>
#include <vector>
class Graph{
    private:
        int numvertices;
        std::vector<std::vector<int>> adjList;
        
        void dfsLogic(int current, std::vector<bool> &visited) const{
            visited[current]  = true;
            std::cout<<"Vertex of DFS: "<<current<<"\n";
            for(auto i : adjList[current]){
                if(!visited[i]){
                    dfsLogic(i,visited);
                }
            }
        }
        
    public:
        Graph(int vertices) : numvertices(vertices), adjList(vertices){};
        
        void addEdge(int u, int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        void dfs(int startNode) const {
            if(startNode < 0 || startNode >= adjList.size()){
                std::cout<<"Invalide Starting Point!";
                return ;
            }
            std::vector<bool> visited(adjList.size(), false);
            dfsLogic(startNode, visited);
            std::cout<<"\n";
        }
};

int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    g.dfs(0);

    return 0;
}