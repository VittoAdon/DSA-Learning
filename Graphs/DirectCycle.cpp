#include <iostream>
#include <vector>

class Graph{
    private:
        std::vector<std::vector<int>> adjList;

        bool dfsDirectCycleHelp(int current, std::vector<bool> &visited, std::vector<bool> &inStack) const {
            visited[current] = true;
            inStack[current] = true;
            for(auto i : adjList[current]){
                if(!visited[i]){
                    if(dfsDirectCycleHelp(i, visited, inStack)){
                        return true;
                    }
                }
                else if(inStack[i]){
                    return true;
                }
            }
            inStack[current] = false;
            return false;
        }
    public:
        Graph(int vertices) : adjList(vertices) {};

        void addEdge(int u, int v){
            adjList[u].push_back(v);
        }

        bool dfs() const {
            std::vector<bool> visited(adjList.size(), false);
            std::vector<bool> inStack(adjList.size(), false);

            for(int i = 0; i < adjList.size(); i++){
                if(!visited[i]){
                    if(dfsDirectCycleHelp(i, visited, inStack)){
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
    g2.addEdge(0, 2);
    g2.addEdge(1, 3);
    g2.addEdge(2, 3);

    std::cout << "Graph 2 has cycle: " << (g2.dfs() ? "YES" : "NO") << "\n";

    return 0;
}