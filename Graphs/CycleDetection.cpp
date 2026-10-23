#include <iostream>
#include <vector>
class Graph{
    private:
        std::vector<std::vector<int>> adjList;

        bool dfsCycleCheck(int current, int parent, std::vector<bool> &visited) const {
            visited[current] = true;
            for(auto i : adjList[current]){
                if(!visited[i]){
                    if(dfsCycleCheck(i, current, visited)){
                        return true;
                    }
                }
                else if(i != parent){
                    return true;
                }
            }
            return false;
        }
    public:
        Graph(int vertices): adjList(vertices) {};

        void addEdge(int u, int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        bool dfs() const{
            std::vector<bool> visited(adjList.size(), false);
            for(int i = 0; i < adjList.size(); ++i){
                if(!visited[i]){
                    if(dfsCycleCheck(i, -1, visited)){
                        return true;
                    }
                }
            }
            return false;
        }
};
int main() {
 
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);

    std::cout << "Graph 1 has cycle: " << (g1.dfs() ? "YES" : "NO") << "\n";

  
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    std::cout << "Graph 2 has cycle: " << (g2.dfs() ? "YES" : "NO") << "\n";

    return 0;
}