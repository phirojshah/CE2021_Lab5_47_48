#include "graph.h"

Graph::Graph(bool isDirected) : numVertices(0), directed(isDirected) {}

bool Graph::isEmpty() {
    return numVertices == 0;
}

bool Graph::isDirected() {
    return directed;
}

void Graph::addVertex(int newVertex) {
    if (numVertices == 0) {
        adjacencyMatrix.push_back(std::vector<bool>(1, false));
    } else {
        for (int i = 0; i < numVertices; i++) {
            adjacencyMatrix[i].push_back(false);
        }
        adjacencyMatrix.push_back(std::vector<bool>(numVertices + 1, false));
    }
    numVertices++;
}

void Graph::addEdge(int vertex1, int vertex2) {
    if (vertex1 >= 0 && vertex1 < numVertices && vertex2 >= 0 && vertex2 < numVertices) {
        adjacencyMatrix[vertex1][vertex2] = true;
        if (!directed) {
            adjacencyMatrix[vertex2][vertex1] = true;
        }
    }
}

void Graph::removeVertex(int vertexToRemove) {
    if (vertexToRemove >= 0 && vertexToRemove < numVertices) {
        adjacencyMatrix.erase(adjacencyMatrix.begin() + vertexToRemove);
        for (int i = 0; i < numVertices; i++) {
            adjacencyMatrix[i].erase(adjacencyMatrix[i].begin() + vertexToRemove);
        }
        numVertices--;
    }
}

void Graph::removeEdge(int vertex1, int vertex2) {
    if (vertex1 >= 0 && vertex1 < numVertices && vertex2 >= 0 && vertex2 < numVertices) {
        adjacencyMatrix[vertex1][vertex2] = false;
        if (!directed) {
            adjacencyMatrix[vertex2][vertex1] = false;
        }
    }
}

int Graph::NumVertices() {
    return numVertices;
}

int Graph::numEdges() {
    int count = 0;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j]) {
                count++;
            }
        }
    }
    return directed ? count : count / 2;
}
