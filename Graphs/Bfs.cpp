#include<iostream>
#include<queue>
#include <vector>

class Graph{
    private:
        int numvertices;
        std::vector<std::vector<int>> adjList;
    public:
        Graph(int vertices) : numvertices(vertices),        adjList(vertices) {}
        
        void addEdge(int u,int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        void bfs(int startNode) const{
            if(startNode < 0 || startNode>=numvertices){
                std::cout<<"StartNode is not valid!: ";
                return;
            }
            std::vector<bool> visited(numvertices, false);
            std::queue<int> q;
            
            visited[startNode] = true;
            q.push(startNode);
            
            while(!q.empty()){
                int current = q.front();
                q.pop();
                std::cout<<"Vertex is: "<<current<<"\n";
                for(auto i: adjList[current]){
                    if(!visited[i]){
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
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

    g.bfs(4);
    return 0;
    
}








