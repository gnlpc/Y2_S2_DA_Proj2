
/**
 * @file LoadFiles.cpp
 * The file that takes care of loading the data.
 */
#include "LoadFiles.h"

Graph extraGraph;
Graph toyGraph;
Graph realGraph;


void LoadFiles::chooseToy(){
    cout << "\nWhich toy graph would you like to work with?" << std::endl;
    cout << "For stadiums graph, press [1]" << std::endl;
    cout << "For tourism graph, press [2]" << std::endl;
    cout << "For shipping graph, press [3]" << std::endl;
    int numVertices;
    cin >> numVertices;
    string result;


    switch(numVertices) {
        case 1:
            return readToy("../Code/dataset/Project2Graphs/Toy-Graphs/stadiums.csv");

        case 2:
            return readToy("../Code/dataset/Project2Graphs/Toy-Graphs/tourism.csv");

        case 3:
            return readToy("../Code/dataset/Project2Graphs/Toy-Graphs/shipping.csv");

        default:
            cout << "Invalid input, please try again\n";
            return chooseToy();
    }

}

void LoadFiles::readToy(string path){
    string extraFilePath = path;
    fstream extraFile;
    extraFile.open(extraFilePath);

    if (extraFile.fail()) {
        cerr << "Unable to open " << extraFilePath << endl;
        return;
    }

    cout << "Reading File..." << endl;


    int jump = 0;
    while (extraFile.peek() != EOF) {
        string line;
        vector<string> strings;
        getline(extraFile, line);
        if (jump==1) {
            loadToy(line);
        }
        jump=1;
    }

    cout << "File read successfully!" << endl;
    extraFile.close();
}

void LoadFiles::loadToy(string str){
    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(item);
    }

    int pA = stoi(result[0]);
    int pB = stoi(result[1]);
    float pC = stof(result[2]);

    ToyGraph aux (pA, pB, pC);

    for (auto e: toy){
        if (aux.getOrig()==e.getOrig() && aux.getDest()==e.getDest() && aux.getDist()==e.getDist() ){
            return;
        }
    }

    toyGraph.addVertex(aux.getOrig());
    toyGraph.addVertex(aux.getDest());
    toy.push_back(aux);

    toyGraph.findVertex(pA)->addEdge(toyGraph.findVertex(pA), toyGraph.findVertex(pB), pC);
    toyGraph.findVertex(pB)->addEdge(toyGraph.findVertex(pB), toyGraph.findVertex(pA), pC);

}

Graph LoadFiles::getToyGraph() {
    return toyGraph;
}

void LoadFiles::chooseExtra() {

    cout << "\nHow many vertices do you want? Choose from: 25, 50, 75, 100, 200, 300, 400, 500, 600, 700, 800, 900" << std::endl;
    int numVertices;
    cin >> numVertices;
    string result;

    switch (numVertices) {
        case 25:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_25.csv");

        case 50:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_50.csv");

        case 75:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_75.csv");

        case 100:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_100.csv");

        case 200:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_200.csv");

        case 300:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_300.csv");

        case 400:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_400.csv");

        case 500:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_500.csv");

        case 600:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_600.csv");

        case 700:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_700.csv");

        case 800:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_800.csv");

        case 900:
            return readExtra("../Code/dataset/Project2Graphs/Extra_Fully_Connected_Graphs/edges_900.csv");
        default:
            cout << "YOUR CHOICE IS INVALID\n";
            return chooseExtra();
    }
}

void LoadFiles::readExtra(string str) {
    string extraFilePath = str;
    fstream extraFile;
    extraFile.open(extraFilePath);

    if (extraFile.fail()) {
        cerr << "Unable to open " << extraFilePath << endl;
        return;
    }

    cout << "Reading File..." << endl;

    while (extraFile.peek() != EOF) {
        string line;
        vector<string> strings;
        getline(extraFile, line);
        loadExtra(line);
    }

    cout << "File read successfully" << endl;
    extraFile.close();

}

void LoadFiles::loadExtra(string str) {

    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(item);
    }

    int pA = stoi(result[0]);
    int pB = stoi(result[1]);
    float pC = stof(result[2]);

    ToyGraph aux (pA, pB, pC);

    for (auto e: getExtraVector()){
        if (aux.getOrig()==e.getOrig() && aux.getDest()==e.getDest() && aux.getDist()==e.getDist()){
            return;
        }
    }

    extraGraph.addVertex(aux.getOrig());
    extraGraph.addVertex(aux.getDest());
    extra.push_back(aux);

    extraGraph.findVertex(pA)->addEdge(extraGraph.findVertex(pA), extraGraph.findVertex(pB), pC);
    extraGraph.findVertex(pB)->addEdge(extraGraph.findVertex(pB), extraGraph.findVertex(pA), pC);

}

vector<ToyGraph> LoadFiles::getExtraVector() {
    return extra;
}

Graph LoadFiles::getExtraGraph() {
    return extraGraph;
}

void LoadFiles::chooseReal() {

    cout << "\nWhich one of the real world graph would you like to choose?" << endl;
    cout << "For real 1 press [1]" << endl;
    cout << "For real 2 press [2]" << endl;
    cout << "For real 3 press [3]" << endl;

    int num;
    cin >> num;

    switch (num) {
        case 1:
            readReal("../Code/dataset/Project2Graphs/Real-World-Graphs/graph1/nodes.csv");
            readNodesReal("../Code/dataset/Project2Graphs/Real-World-Graphs/graph1/edges.csv");
            break;


        case 2:
            readReal("../Code/dataset/Project2Graphs/Real-World-Graphs/graph2/nodes.csv");
            readNodesReal("../Code/dataset/Project2Graphs/Real-World-Graphs/graph2/edges.csv");
            break;

        case 3:
           readReal("../Code/dataset/Project2Graphs/Real-World-Graphs/graph3/nodes.csv");
           readNodesReal("../Code/dataset/Project2Graphs/Real-World-Graphs/graph3/edges.csv");
           break;

        default:
            cout << "YOUR CHOICE IS INVALID\n";
            return chooseReal();
    }


}

void LoadFiles::readReal(const string& path) {

    string realFilePath = path;
    ifstream realFile;
    realFile.open(realFilePath);

    if (realFile.fail()) {
        cerr << "Unable to open " << realFilePath << endl;
        return;
    }

    cout << "Reading File..." << endl;

    string line;
    getline(realFile, line); // Skip the first line

    for (string line; getline(realFile, line);) {
        loadReal(line);
    }

    realFile.close();

}

void LoadFiles::loadReal(const string& str) {

    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(item);
    }


    int pA = stoi(result[0]);
    double pB = stod(result[1]);
    double pC = stod(result[2]);

    Vertex aux(pA, pB, pC);

    realGraph.addVertex(const_cast<const Vertex*>(&aux));

}

void LoadFiles::readNodesReal (const string& path){
    string realFilePath = path;
    fstream realFile;
    realFile.open(realFilePath);

    if (realFile.fail()) {
        cerr << "Unable to open " << realFilePath << endl;
    }

    string line;
    getline(realFile, line); // Skip the first line

    for (string line; getline(realFile, line);) {
        createAdj(line);
    }

    cout << "File read successfully" << endl;
    realFile.close();
}

Graph LoadFiles::getRealGraph() {
    return realGraph;
}

vector<Vertex*> LoadFiles::getRealVector() {
    return real;
}

void LoadFiles::createAdj(const string& str){

    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(item);
    }

    int pA = stoi(result[0]);
    int pB = stoi(result[1]);
    double pC = stod(result[2]);

    realGraph.findVertex(pA)->addEdge(realGraph.findVertex(pA), realGraph.findVertex(pB), pC);
    realGraph.findVertex(pB)->addEdge(realGraph.findVertex(pB), realGraph.findVertex(pA), pC);

}



void LoadFiles::deleteAll() {
    extraGraph.deleteGraph();
    toyGraph.deleteGraph();
    realGraph.deleteGraph();
    extra.clear();
    toy.clear();
    real.clear();
}

vector<vector<float>> LoadFiles::createDistanceMatrix(const Graph& graph) const {
    int n = graph.getVertexSet().size();

    // Initialize the distance matrix and set all distances to infinity
    vector<vector<float>> distanceMatrix(n, vector<float>(n, numeric_limits<float>::max()));

    // Set the distance from a vertex to itself as 0
    for (int i = 0; i < n; i++) {
        distanceMatrix[i][i] = 0;
    }

    // Calculate the actual distances based on the graph's edges
    for (const Vertex* vertex : graph.getVertexSet()) {
        int srcIndex = vertex->getID();
        for (const Edge* edge : vertex->getAdj()) {
            int destIndex = edge->getDest()->getID();
            float weight = edge->getDist();
            distanceMatrix[srcIndex][destIndex] = weight;
        }
    }

    // Apply Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distanceMatrix[i][k] != numeric_limits<float>::max() &&
                    distanceMatrix[k][j] != numeric_limits<float>::max() &&
                    distanceMatrix[i][k] + distanceMatrix[k][j] < distanceMatrix[i][j]) {
                    distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                }
            }
        }
    }

    return distanceMatrix;
}