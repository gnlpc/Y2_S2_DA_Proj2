

#ifndef TRABALHO2_LOADFILES_H
#define TRABALHO2_LOADFILES_H

#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <locale>
#include "Graph.h"
#include "ToyGraph.h"


using namespace std;



class LoadFiles {

public:

    void chooseExtra();

    void readExtra(string str);

    void loadExtra(string str);

    vector<ToyGraph> getExtraVector();

    Graph getExtraGraph();

    void chooseToy();

    void readToy(string path);

    void loadToy(string str);

    Graph getToyGraph();

    void chooseReal();

    void readReal(const string& path);

    void loadReal(const string& str);

    Graph getRealGraph();

    vector<Vertex*> getRealVector();

    void createAdj(const string& str);

    void readNodesReal (const string& path);

    void deleteAll();

    vector<vector<float>> createDistanceMatrix(const Graph& graph) const;


private:

    vector<ToyGraph> extra;

    vector<ToyGraph> toy;

    vector <Vertex*> real;
};


#endif //TRABALHO2_LOADFILES_H
