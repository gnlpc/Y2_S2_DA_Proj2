
/**
 * @file ToyGraph.cpp
 * Toy Graph functions
 */
#include "ToyGraph.h"

ToyGraph::ToyGraph(int orig, int dest, float dist) {
    this->orig=orig;
    this->dest=dest;
    this->dist=dist;
}

int ToyGraph::getOrig() const {
    return this->orig;
}

int ToyGraph::getDest() const {
    return this->dest;
}

float ToyGraph::getDist() const {
    return this->dist;
}
