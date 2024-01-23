

#ifndef TRABALHO2_GRAPH_H
#define TRABALHO2_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <list>
#include "VertexEdge.h"
#include "MutablePriorityQueue.h"

class Graph {
    int n;

public:
    Graph();

    bool addVertex(const int id);

    bool addVertex (const Vertex* vertex);

    bool addEdge(const int &source, const int &dest, double w);

    static Vertex *findVertex (const int &id);

    vector<Vertex *> getVertexSet() const;

    void deleteGraph();

    bool has_edge(int u, int v) const;

    pair<Graph, double> prim() const;

    pair<double, double> tspTriApprox(vector<unsigned> &path) const;

private:
    static vector<Vertex *> vertexSet;


};


#endif //TRABALHO2_GRAPH_H
