

/**
 * @file VertexEdge.cpp
 * Vertex and Edge related functions
 */
#include "VertexEdge.h"

Vertex::Vertex(int id) {
    this->id=id;
}

int Vertex::getID() const {
    return this->id;
}

vector<Edge *> Vertex::getAdj() const {
    return this->adj;
}

bool Vertex::isVisited() const {
    return this->visited;
}

void Vertex::setVisited(bool _bool) {
    this->visited=_bool;
}

float Vertex::getDist() const {
    return dist;
}

void Vertex::setDist(float dist) {
    this->dist=dist;
}

Edge *Vertex::addEdge(Vertex *orig, Vertex *dest, float dist) {
    auto newEdge = new Edge (orig, dest, dist);
    adj.push_back(newEdge);
    return newEdge;
}

Edge *Vertex::getEdge(const Vertex *dest) const {
    for (auto edge : this->adj) {
        if (edge->getDest() == dest) {
            return edge;
        }
    }
    return nullptr;
}

bool Vertex::removeEdge(Vertex *orig, Vertex *dest) {
    return false;
}

Vertex::Vertex(int id, double longitude, double latitude) {
    this->id=id;
    this->longitude=longitude;
    this->latitude=latitude;
}

double Vertex::getLongitude() const {
    return this->longitude;
}

double Vertex::getLatitude() const {
    return this->latitude;
}

Edge::Edge(Vertex *orig, Vertex *dest, float dist) {
    this->orig = orig;
    this->dest=dest;
    this->dist=dist;
}

Vertex *Edge::getDest() const {
    return this->dest;
}

Vertex *Edge::getOrig() const {
    return this->orig;
}

float Edge::getDist() const {
    return this->dist;
}

void Vertex::preorderDFS(vector<unsigned> &preorder) {
    this->visited = true;
    preorder.push_back(this->id);
    for (auto edge : this->adj) {
        auto aux = edge->getDest();
        if(!aux->isVisited()) aux->preorderDFS(preorder);
    }
}

bool Vertex::operator<(Vertex & vertex) const {
    return this->dist < vertex.dist;
}

Edge *Vertex::getPath() const {
    return this->path;
}

void Vertex::setPath(Edge *path) {
    this->path = path;
}

double Vertex::distance(const Vertex *destination) const {
    double lat1 = this->getLatitude();
    double lon1 = this->getLongitude();
    double lat2 = destination->getLatitude();
    double lon2 = destination->getLongitude();

    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    double lat1rad = lat1 * M_PI / 180.0;
    double lat2rad = lat2 * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1rad) * cos(lat2rad);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return 6371 * c;
}
