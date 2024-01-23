

#ifndef TRABALHO2_VERTEXEDGE_H
#define TRABALHO2_VERTEXEDGE_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <memory>
#include <cmath>
#include "MutablePriorityQueue.h"

using namespace std;

class Edge;
class Vertex;

#define MAXNUM std::numeric_limits<double>::max()

class Edge{
public:
    Edge(Vertex *orig, Vertex *dest, float dist);
    Vertex* getDest() const ;
    Vertex* getOrig() const ;
    float getDist() const ;
    double getWeight() const;

protected:
    Vertex *dest;
    Vertex *orig;
    float dist;
    double weight;
};



class Vertex{

public:
    Vertex(int id);
    Vertex(int id, double longitude, double latitude);
    int getID() const;
    vector<Edge*> getAdj() const ;
    bool isVisited() const ;
    void setVisited(bool _bool);
    float getDist() const ;
    void setDist (float dist);
    Edge * addEdge (Vertex *orig, Vertex *dest, float dist);
    Edge * getEdge(const Vertex *dest) const;
    bool removeEdge(Vertex * orig, Vertex *dest);

    void preorderDFS(vector<unsigned> &preorder);
    double distance(const Vertex *destination) const;
    bool operator<(Vertex & vertex) const;

    Edge *getPath() const;
    void setPath(Edge *path);


    double getLongitude() const;
    double getLatitude() const;

    friend class MutablePriorityQueue<Vertex>;

protected:
    int id;
    vector<Edge *> adj;
    float dist;
    bool visited = false;
    double longitude;
    double latitude;
    int queueIndex = 0;
    Edge *path = nullptr;

};





#endif //TRABALHO2_VERTEXEDGE_H

