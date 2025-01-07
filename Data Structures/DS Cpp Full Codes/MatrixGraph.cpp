#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

class MatrixGraph {
private:
    vector<vector<int>> adjMatrix;
    int vertices;
    bool isDirected;

public:
    MatrixGraph(int vertices, bool isDirected = false);

    void addEdge(int src, int dest, int weight = 1);
    void removeEdge(int src, int dest);

    bool isAdjacent(int src, int dest) const;
    vector<int> getNeighbors(int vertex) const;

    void printMatrix() const;
    int getVertexCount() const;
    int getEdgeCount() const;

    bool isGraphDirected() const;
};

MatrixGraph::MatrixGraph(int vertices, bool isDirected) 
    : vertices(vertices), isDirected(isDirected) {
    adjMatrix.resize(vertices, vector<int>(vertices, 0));
}

void MatrixGraph::addEdge(int src, int dest, int weight){
    if(src < 0 || src >= vertices || dest < 0 || dest >= vertices){
        throw out_of_range("Vertex index out of range");
    }
    adjMatrix[src][dest] = weight;
    if(!isDirected){
        adjMatrix[dest][src] = weight;
    }
}

void MatrixGraph::removeEdge(int src, int dest){
    if(src < 0 || src >= vertices || dest < 0 || dest >= vertices){
        throw out_of_range("Vertex index out of range");
    }
    adjMatrix[src][dest] = 0;
    if (!isDirected) {
        adjMatrix[dest][src] = 0;
    }
}

bool MatrixGraph::isAdjacent(int src, int dest) const{
    if(src < 0 || src >= vertices || dest < 0 || dest >= vertices){
        throw out_of_range("Vertex index out of range");
    }
    return adjMatrix[src][dest] != 0;
}

vector<int> MatrixGraph::getNeighbors(int vertex) const{
    if(vertex < 0 || vertex >= vertices){
        throw out_of_range("Vertex index out of range");
    }
    vector<int> neighbors;
    for(int i = 0; i < vertices; ++i){
        if(adjMatrix[vertex][i] != 0){
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

void MatrixGraph::printMatrix() const{
    for(const auto& row : adjMatrix){
        for(int val : row){
            cout<<val<<" ";
        }
        cout<<"\n";
    }
}

int MatrixGraph::getVertexCount() const {
    return vertices;
}

int MatrixGraph::getEdgeCount() const{
    int count = 0;
    for(int i = 0; i < vertices; ++i){
        for(int j = 0; j < vertices; ++j){
            if(adjMatrix[i][j] != 0){
                count++;
            }
        }
    }
    return isDirected ? count : count / 2;
}

bool MatrixGraph::isGraphDirected() const{
    return isDirected;
}

int main() {
    MatrixGraph graph(6, true);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 3, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);
    graph.addEdge(5, 0);

    cout<<"Adjacency Matrix:\n";
    graph.printMatrix();

    cout<<"Neighbors of given vertex\n";
    for(int neighbor : graph.getNeighbors(1)){
        cout<<neighbor<<" ";
    }
    cout<<"\n";
}

