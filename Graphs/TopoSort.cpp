#include <iostream>
#include <vector>
#include <queue>
class directedGraph{
    private:
        std::vector<std::vector<int>> adjList;
    public:
        directedGraph(int vertices) : adjList(vertices) {};

        void addEdge(int u, int v){
            adjList[u].push_back(v);
        }

        std::vector<int> topoSort() const{
            std::vector<int> inDegree(adjList.size(),0);

            for(int vertex = 0; vertex < adjList.size(); vertex++){
                for(auto edges : adjList[vertex]){
                    inDegree[edges]++;
                }
            }

            std::queue<int> q;
            for(int checkZero = 0; checkZero < adjList.size(); checkZero++){
                if(inDegree[checkZero] == 0){
                    q.push(checkZero);
                }
            }

            std::vector<int> topoOrder;
            while(!q.empty()){
                int current = q.front();
                q.pop();
                topoOrder.push_back(current);

                for(auto nearVertex : adjList[current]){
                    inDegree[nearVertex]--;
                    if(inDegree[nearVertex] == 0){
                        q.push(nearVertex);
                    }
                }
            }

            if(topoOrder.size() != static_cast<size_t>(adjList.size())){
                std::cout<<"This Graph contains cycle! \n";
                return {};
            }
            return topoOrder;
        }
};

int main(){
    directedGraph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    std::vector<int> order = g.topoSort();

    std::cout << "Topological Sort Order:\n";
    for (auto vertex : order) {
        std::cout << vertex << " ";
    }
    std::cout << "\n";

    return 0;
}
