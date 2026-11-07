#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// Base Graph interface
class Graph {
public:
    virtual bool areAdjacent(int u, int v) = 0;
    virtual vector<int> listAllAdjacent(int vertex) = 0;
    virtual void addEdge(int u, int v) = 0;
    virtual void deleteEdge(int u, int v) = 0;
    virtual int getVertexCount() = 0;
    virtual int getEdgeCount() = 0;
    virtual bool isConnected() = 0;
    virtual vector<int> findPath(int u, int v) = 0;
    virtual vector<int> findShortestPath(int u, int v) = 0;
    virtual vector<vector<int>> findAllPath(int u, int v) = 0;
    virtual vector<vector<int>> findCycle() = 0;
};

// Graph Traversal Class
class GraphTraversal {
public:
    static vector<int> bfs(Graph& graph, int start, int target) {
        int vertexCount = graph.getVertexCount();
        vector<bool> visited(vertexCount, false);
        vector<int> prev(vertexCount, -1);
        queue<int> queue;
        queue.push(start);
        visited[start] = true;

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();

            if (current == target) {
                return reconstructPath(start, target, prev);
            }

            for (int neighbor : graph.listAllAdjacent(current)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    prev[neighbor] = current;
                    queue.push(neighbor);
                }
            }
        }

        return {};
    }

    static void dfsRecursive(Graph& graph, int current, int target, vector<bool>& visited, vector<int>& path) {
        visited[current] = true;
        path.push_back(current);

        if (current == target) return;

        for (int neighbor : graph.listAllAdjacent(current)) {
            if (!visited[neighbor]) {
                dfsRecursive(graph, neighbor, target, visited, path);
                if (!path.empty() && path.back() == target) return;
            }
        }

        path.pop_back();
    }

    static vector<vector<int>> findAllPaths(Graph& graph, int start, int target) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        vector<bool> visited(graph.getVertexCount(), false);
        findAllPathsDFS(graph, start, target, visited, currentPath, allPaths);
        return allPaths;
    }

    static void findAllPathsDFS(Graph& graph, int current, int target, vector<bool>& visited, vector<int>& currentPath, vector<vector<int>>& allPaths) {
        visited[current] = true;
        currentPath.push_back(current);

        if (current == target) {
            allPaths.push_back(currentPath);
        } else {
            for (int neighbor : graph.listAllAdjacent(current)) {
                if (!visited[neighbor]) {
                    findAllPathsDFS(graph, neighbor, target, visited, currentPath, allPaths);
                }
            }
        }

        currentPath.pop_back();
        visited[current] = false;
    }

    static vector<vector<int>> findAllCycles(Graph& graph) {
        vector<vector<int>> allCycles;
        vector<bool> visited(graph.getVertexCount(), false);
        vector<bool> inStack(graph.getVertexCount(), false);
        stack<int> stack;

        for (int i = 0; i < graph.getVertexCount(); i++) {
            if (!visited[i]) {
                findAllCyclesDFS(graph, i, -1, visited, inStack, stack, allCycles);
            }
        }

        return allCycles.empty() ? vector<vector<int>>() : allCycles;
    }

    static void findAllCyclesDFS(Graph& graph, int current, int parent, vector<bool>& visited, vector<bool>& inStack, std::stack<int>& dfsStack, vector<vector<int>>& allCycles) {
    visited[current] = true;
    inStack[current] = true;
    dfsStack.push(current);

    for (int neighbor : graph.listAllAdjacent(current)) {
        if (!visited[neighbor]) {
            findAllCyclesDFS(graph, neighbor, current, visited, inStack, dfsStack, allCycles);
        } else if (inStack[neighbor] && neighbor != parent) {
            vector<int> cycle;
            std::stack<int> tempStack = dfsStack; // Copy the stack
            while (!tempStack.empty()) {
                int node = tempStack.top();
                tempStack.pop();
                cycle.push_back(node);
                if (node == neighbor) break;
            }
            reverse(cycle.begin(), cycle.end());
            allCycles.push_back(cycle);
        }
    }

    dfsStack.pop();
    inStack[current] = false;
}


private:
    static vector<int> reconstructPath(int start, int target, const vector<int>& prev) {
        vector<int> path;
        for (int at = target; at != -1; at = prev[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

// Adjacency Matrix Implementation
class AdjacencyMatrixGraph : public Graph {
private:
    vector<vector<bool>> adjacencyMatrix;
    int vertexCount;
    int edgeCount;

public:
    AdjacencyMatrixGraph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        adjacencyMatrix.resize(vertexCount, vector<bool>(vertexCount, false));
    }

    bool areAdjacent(int u, int v) override {
        return adjacencyMatrix[u][v];
    }

    vector<int> listAllAdjacent(int vertex) override {
        vector<int> adjacentVertices;
        for (int i = 0; i < vertexCount; i++) {
            if (adjacencyMatrix[vertex][i]) {
                adjacentVertices.push_back(i);
            }
        }
        return adjacentVertices;
    }

    void addEdge(int u, int v) override {
        if (!adjacencyMatrix[u][v]) {
            adjacencyMatrix[u][v] = true;
            adjacencyMatrix[v][u] = true;
            edgeCount++;
        }
    }

    void deleteEdge(int u, int v) override {
        if (adjacencyMatrix[u][v]) {
            adjacencyMatrix[u][v] = false;
            adjacencyMatrix[v][u] = false;
            edgeCount--;
        }
    }

    int getVertexCount() override {
        return vertexCount;
    }

    int getEdgeCount() override {
        return edgeCount;
    }

    bool isConnected() override {
        return !GraphTraversal::bfs(*this, 0, -1).empty();
    }

    vector<int> findPath(int u, int v) override {
        vector<bool> visited(vertexCount, false);
        vector<int> path;
        GraphTraversal::dfsRecursive(*this, u, v, visited, path);
        return path;
    }

    vector<int> findShortestPath(int u, int v) override {
        return GraphTraversal::bfs(*this, u, v);
    }

    vector<vector<int>> findAllPath(int u, int v) override {
        return GraphTraversal::findAllPaths(*this, u, v);
    }

    vector<vector<int>> findCycle() override {
        return GraphTraversal::findAllCycles(*this);
    }
};

// Adjacency List Implementation
class AdjacencyListGraph : public Graph {
private:
    unordered_map<int, vector<int>> adjacencyList;
    int vertexCount;
    int edgeCount;

public:
    AdjacencyListGraph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {}

    bool areAdjacent(int u, int v) override {
        for (int neighbor : adjacencyList[u]) {
            if (neighbor == v) return true;
        }
        return false;
    }

    vector<int> listAllAdjacent(int vertex) override {
        return adjacencyList[vertex];
    }

    void addEdge(int u, int v) override {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
        edgeCount++;
    }

    void deleteEdge(int u, int v) override {
        adjacencyList[u].erase(remove(adjacencyList[u].begin(), adjacencyList[u].end(), v), adjacencyList[u].end());
        adjacencyList[v].erase(remove(adjacencyList[v].begin(), adjacencyList[v].end(), u), adjacencyList[v].end());
        edgeCount--;
    }

    int getVertexCount() override {
        return vertexCount;
    }

    int getEdgeCount() override {
        return edgeCount;
    }

    bool isConnected() override {
        return !GraphTraversal::bfs(*this, 0, -1).empty();
    }

    vector<int> findPath(int u, int v) override {
        vector<bool> visited(vertexCount, false);
        vector<int> path;
        GraphTraversal::dfsRecursive(*this, u, v, visited, path);
        return path;
    }

    vector<int> findShortestPath(int u, int v) override {
        return GraphTraversal::bfs(*this, u, v);
    }

    vector<vector<int>> findAllPath(int u, int v) override {
        return GraphTraversal::findAllPaths(*this, u, v);
    }

    vector<vector<int>> findCycle() override {
        return GraphTraversal::findAllCycles(*this);
    }
};

// Edge List Implementation
class EdgeListGraph : public Graph {
private:
    vector<pair<int, int>> edgeList;
    int vertexCount;

public:
    EdgeListGraph(int vertexCount) : vertexCount(vertexCount) {}

    bool areAdjacent(int u, int v) override {
        for (auto& edge : edgeList) {
            if ((edge.first == u && edge.second == v) || (edge.first == v && edge.second == u)) {
                return true;
            }
        }
        return false;
    }

    vector<int> listAllAdjacent(int vertex) override {
        vector<int> adjacentVertices;
        for (auto& edge : edgeList) {
            if (edge.first == vertex) adjacentVertices.push_back(edge.second);
            if (edge.second == vertex) adjacentVertices.push_back(edge.first);
        }
        return adjacentVertices;
    }

    void addEdge(int u, int v) override {
        edgeList.emplace_back(u, v);
    }

    void deleteEdge(int u, int v) override {
        edgeList.erase(remove(edgeList.begin(), edgeList.end(), make_pair(u, v)), edgeList.end());
    }

    int getVertexCount() override {
        return vertexCount;
    }

    int getEdgeCount() override {
        return edgeList.size();
    }

    bool isConnected() override {
        return !GraphTraversal::bfs(*this, 0, -1).empty();
    }

    vector<int> findPath(int u, int v) override {
        vector<bool> visited(vertexCount, false);
        vector<int> path;
        GraphTraversal::dfsRecursive(*this, u, v, visited, path);
        return path;
    }

    vector<int> findShortestPath(int u, int v) override {
        return GraphTraversal::bfs(*this, u, v);
    }

    vector<vector<int>> findAllPath(int u, int v) override {
        return GraphTraversal::findAllPaths(*this, u, v);
    }

    vector<vector<int>> findCycle() override {
        return GraphTraversal::findAllCycles(*this);
    }
};
