
/**
 * @file Graph.cpp
 * Graph functions
 */
#include "Graph.h"

Graph::Graph() : n(0){}

vector<Vertex*> Graph::vertexSet;


bool Graph::addVertex(const int id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id));
    return true;}

Vertex *Graph::findVertex(const int &id) {
    for (auto v: vertexSet){
        if (v->getID() == id) {
            return v;
        }
    }
    return nullptr;
}

vector<Vertex *> Graph::getVertexSet() const{
    return this->vertexSet;
}

void Graph::deleteGraph() {
    for (auto a: vertexSet){
        for (auto c: a->getAdj()){
            delete c;
        }
        a->getAdj().clear();
    }
    for (auto a: vertexSet){
        delete a;
    }
    vertexSet.clear();
}

bool Graph::has_edge(int u, int v) const {

    vector<Edge*> ret = findVertex(u)->getAdj();

    for (auto neighbor : ret) {
        if (neighbor->getDest()->getID() == v) {
            return true;
        }
    }
    return false;
}

bool Graph::addVertex(const Vertex *vertex) {
    if (findVertex(vertex->getID()) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(vertex->getID(), vertex->getLongitude(), vertex->getLatitude()));
    return true;
}

bool Graph::addEdge(const int &source, const int &dest, double w) {
    auto v1 = findVertex(source);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v1, v2, w);
    return true;
}


pair<Graph, double> Graph::prim() const {
    for (const auto v : vertexSet) {
        v->setDist(MAXNUM);
        v->setPath(nullptr);
        v->setVisited(false);
    }

    MutablePriorityQueue<Vertex> q;
    Vertex* r = findVertex(0);
    r->setDist(0);
    q.insert(r);
    for(auto v : vertexSet) {
        if(v->getID() != 0) q.insert(v);
    }

    while(!q.empty()) {
        auto aux = q.extractMin();
        aux->setVisited(true);

        for(const auto &edge : aux->getAdj()) {
            Vertex* v = edge->getDest();
            if(!v->isVisited()) {
                double dist = v->getDist();
                if(edge->getDist() < dist) {
                    v->setDist(edge->getDist());
                    v->setPath(edge);
                    if(dist == MAXNUM) q.insert(v);
                    else q.decreaseKey(v);
                }
            }
        }
    }

    Graph mst;
    double total = 0;

    for(const auto v : vertexSet) {
        v->setVisited(false);
        mst.addVertex(v);
    }

    for(const auto v : vertexSet) {
        if(v->getPath()) {
            mst.addEdge(v->getID(), v->getPath()->getOrig()->getID(), v->getPath()->getDist());
            total += v->getPath()->getDist();
        }
    }
    return make_pair(mst, total);
}

pair<double, double> Graph::tspTriApprox(vector<unsigned> &path) const {
    pair<Graph, double> p = prim();
    Graph mst = p.first;
    double total = 0.0;
    for(auto v : mst.getVertexSet()) {
        if(!v->isVisited()) v->preorderDFS(path);
    }

    for(unsigned i = 0; i < path.size() - 1; i++) {
        const Vertex *s = findVertex(path[i]);
        const Vertex *d = findVertex(path[i + 1]);
        const Edge *e = s->getEdge(d);
        total += e ? e->getDist() : s->distance(d);
    }

    const Edge *e = findVertex(path.back())->getEdge(findVertex(0));
    total += e ? e->getDist() : findVertex(path.back())->distance(findVertex(0));

    return make_pair(p.second, total);
}

