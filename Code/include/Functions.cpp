
/**
 * @file Functions.cpp
 * The file with the functions that solve the exercises.
 */
#include "Functions.h"

/**
 * Calculates the total distance of a path.
 * @complexity O(N^2)
 * @param path
 * @param graph
 * @return Returns the distance of the path
 */
float calculate_distance(vector<int>& path, const Graph& graph){
    float dist = 0;

    for (int i=0; i<path.size() -1 ; i++){
        for (auto b: graph.findVertex(path[i])->getAdj()){
            if (b->getDest()->getID()== path[i+1]){
                dist += b->getDist();
            }

        }
    }

    return dist;

}

/**
 * Gets the minimum distance using backtracking
 * @complexity O(n)
 * @param graph
 * @param path
 * @param visited
 * @param total_distance
 * @param min_distance
 * @param path_min
 * @return Returns the minimum distance
 */
float backtrack(const Graph& graph, vector <int> path, vector<bool>& visited, float total_distance, float min_distance, vector<int> &path_min) {
    visited[path.back()] = true;

    if (total_distance >= min_distance){
        return min_distance;
    }

    if (find(begin(visited), end(visited), false) == end(visited)){
        if (find (graph.findVertex(path.back())->getAdj().begin(), graph.findVertex(path.back())->getAdj().end(), graph.findVertex(0)->getAdj().front())==graph.findVertex(path.back())->getAdj().end()){
            return numeric_limits<float>::infinity();
        }

        int flag =0;
        for (auto a: graph.findVertex(path.back())->getAdj()){
            if (a->getDest()->getID()==0){
                flag=1;
                total_distance+=a->getDist();
                break;
            }
        }

        if (flag==0){
            return numeric_limits<float>::infinity();
        }
        path.push_back(0);
//        total_distance+=graph.findVertex(path.back())->getAdj().front()->getDist();
//        total_distance = calculate_distance(path, graph);

        if (total_distance < min_distance){
            min_distance = total_distance;
            path_min = path;

        }
        return min_distance;
    }

    auto b= graph.findVertex(path.back())->getAdj();
    while (!b.empty()){
        auto a = b.front();
        b.erase(b.begin());
        if (find (path.begin(), path.end(), a->getDest()->getID())==path.end()) {
            path.push_back(a->getDest()->getID());
            total_distance+=a->getDist();
            if (total_distance >= min_distance){
                return min_distance;
            }
            float atmin = backtrack(graph, path, visited, total_distance, min_distance, path_min);
            if (atmin < min_distance){
                min_distance = atmin;
            }
            visited[path.back()]=false;
            path.pop_back();
            total_distance-=a->getDist();
        }
    }

    return min_distance;

}

/**
 * Main function for the TSP of exercise 4.1
 * @complexity O(n)
 * @param graph
 * @return Returns the tie taken by backtracking, the min path and min distance.
 */
float tsp(const Graph& graph) {
    cout << "starting tsp Process \n";
    int n = graph.getVertexSet().size();
    float min_distance = numeric_limits<float>::infinity();
    vector <int> path;
    path.push_back(0);
    vector<bool> visited(n, false);
    float max = numeric_limits<float>::infinity();
    vector <int> path_min;
    clock_t startTime = clock();
    float distance = backtrack(graph, path, visited, 0.0, max, path_min);
    clock_t endTime = clock();
    min_distance = min (min_distance, distance);

    cout << "Time taken by function: " << (double)(endTime - startTime)/CLOCKS_PER_SEC << " seconds" << endl;
    cout << "the min path is: ";
    int cont=0;
    for (auto a:path_min){
        if (cont!=path_min.size()-1) {
            cout << a << " -> ";
        }
        else{
            cout << a;
        }
        cont ++;
    }
    cout << endl;
    cout << "the min distance is: " << min_distance << endl;
    return min_distance;
}

/**
 * Function that goes through the graph and finds the minimum distance between the edges
 * returns a vector with the path that adds the min distance
 * @complexity O(N^3)
 * @param graph
 * @return Returns the minimum distance path
 */
vector<int> min_path(const Graph& graph){

    int n= graph.getVertexSet().size();
    vector <int> path;
    path.push_back(0);



    while (path.size()!=n){
        float min = numeric_limits<float>::infinity();
        int cur=0;
        for (auto a:graph.findVertex(path.back())->getAdj()){
            int flag=0;
            for (auto b: path){
                if (a->getDest()->getID()==b){
                    flag =1;
                }
            }
            if (flag==0) {
                if (a->getDist() < min){
                    min = a->getDist();
                    cur = a->getDest()->getID();
                }
            }
        }
        path.push_back(cur);
    }


    int out=0;

    while (path.back()!=0){
        for (auto a : graph.findVertex(path.back())->getAdj()){
            if (a->getDest()->getID()==0){
                path.push_back(0);
            }
        }
        out++;

        if (out==10){
            break;
        }



    }
    return path;

}
/**
 * Function that returns the minimum distance between the edges not present in the path
 * @complexity O(n)
 * @param graph
 * @param id
 * @param path
 * @return Returns ret -> the min distance obtained
 */
int find_minimum(const Graph &graph, int id, vector<int> path) {

    float min = numeric_limits<float>::infinity();
    int ret;

    for (auto a:graph.findVertex(id)->getAdj()){
        if (find(path.begin(), path.end(), a->getDest()->getID())==path.end()) {
            if (a->getDist() < min) {
                min = a->getDist();
                ret = a->getDest()->getID();
            }
        }
    }

    return ret;
}

/**
 * Function that checks if it is faster to go from A to B or from A to B to C
 * if it is faster, then remove B
 *
 * After removing, checks all the elements not present in the path
 * if the two lightest edges are consecutive in the path adds it in the middle, and checks this first for every element
 * if there is still elements missing in the path, does brute force for the best solution
 * @complexity O(N^2)
 * @param graph
 * @param min
 * @return Returns a vector that contains the path obtained
 */
vector<int> triangular (const Graph& graph, vector<int>& min){

    vector<int> ret=min;
    int tam = min.size();

    for (int i=0; i<tam-1; i++){
        vector<int> aux;
        int first = min[i];
        aux.push_back(first);
        int second = min[i+1];
        aux.push_back(second);
        int third = min[i+2];
        aux.push_back(third);


        float dist1 = calculate_distance(aux, graph);
        float dist2= numeric_limits<float>::infinity();

        for (auto a: graph.findVertex(first)->getAdj()){
            if (a->getDest()->getID()==third){
                dist2 = a->getDist();
                break;
            }
        }

        if (dist1>dist2){
            ret[i]=(first);
            ret[i+1]=(third);
        }

    }

    removeDuplicates(ret);
    vector<int> unused = notUsed(graph, ret);
    insertNotUsed(graph, ret, unused);
    ret.push_back(0);
    return ret;

}

/**
 * Function to remove elements duplicated in a vector
 * @complexity O(N)
 * @param vec
 */
void removeDuplicates(std::vector<int>& vec) {
    std::unordered_set<int> uniqueElements;
    vec.erase(std::remove_if(vec.begin(), vec.end(),
                             [&uniqueElements](const int& element) {
                                 return !uniqueElements.insert(element).second;
                             }), vec.end());
}

/**
 * Function that gets a vector of elements not present in the path
 * @complexity O(N)
 * @param graph
 * @param min
 * @return Returns a vector of elements not present in the path
 */
vector<int> notUsed(const Graph& graph, vector<int>& min){

    vector<int> ret;

    for (auto a: graph.getVertexSet()){
        auto det = find(min.begin(), min.end(), a->getID());

        if (det == min.end()){
            ret.push_back(a->getID());
        }

    }
    return ret;
}

/**
 * Auxiliar function to insert the elements that are not yet present in the path
 * @complexity O(N^2)
 * @param graph
 * @param path
 * @param notUsed
 */
void insertNotUsed (const Graph& graph, vector<int>& path, vector<int> notUsed){

    int n = graph.getVertexSet().size();


    for (auto a: notUsed){
        vector<int> path2;
        int first = find_minimum(graph, a, path2);
        path2.push_back(first);
        int second = find_minimum(graph, a, path2);
        for (int i=0; i<path.size(); i++){
            if (path[i]==first && path[i+1]==second || path[i]==second && path[i+1]==first){
                path.insert(path.begin()+i+1, a);
                break;
            }
        }
    }

    vector<int> aux3 = path;
    for (auto b: notUsed) {
        vector<int> aux2 = path;
        float dist = numeric_limits<float>::infinity();
        if (find(path.begin(), path.end(), b) == path.end()) {
            for (int i=2; i<path.size(); i++){
                aux2.insert(aux2.begin()+i, b);
                float aux = calculate_distance(aux2, graph);
                if (aux < dist){
                    dist = aux;
                    aux3 = aux2;
                }
                aux2 = path;
            }
            path = aux3;
        }
    }

}

/**
 * Exercise 4.2 main function
 * @param graph
 */
void triangularApproximationH(const Graph& graph) {
    clock_t startTime = clock();

    vector<unsigned int> tour;
    pair<double, double> path;
    try {
        path = graph.tspTriApprox(tour);
    } catch (invalid_argument& e) {
        cout << "\nIts not possible to use this graph!" << endl;
        return;
    }

    cout << "\nThe min cost of the MST is: " << path.first << endl;
    cout << "The distance of the tour is: " << path.second << endl;

    clock_t endTime = clock();
    cout << "Time taken by function: " << (double)(endTime - startTime)/CLOCKS_PER_SEC << " seconds" << endl;
}


/**
 * Function that calls all function needed in the 4.3 exercise and starts the timer and stops it
 * prints the values
 * @param graph
 */
void join4 (const Graph& graph){
    clock_t startTime = clock();

    cout << "The min path using nearest neighbor is:\n";
    vector <int> nearest = min_path(graph);
    int i=0;
    for (auto a:nearest){
        if (i!=nearest.size()-1) {
            cout << a << " -> ";
        }
        else{
            cout << a;
        }
        i++;
    }
    cout << endl;
    vector <int> path = triangular(graph, nearest);
    int j=0;
    cout << "The improved path is:\n";
    for (auto b:path) {
        if (j != path.size() - 1) {
            cout << b << " -> ";
        } else {
            cout << b;
        }
        j++;
    }

    cout << endl;

    cout << "The improved distance is: " << calculate_distance(path, graph) << endl;

    clock_t endTime = clock();

    cout << "Time taken by function: " << (double)(endTime - startTime)/CLOCKS_PER_SEC << " seconds" << endl;
}

/**
 * Applies the Lin-Kernighan heuristic algorithm to find an improved tour for the Traveling Salesperson Problem (TSP) on a given graph.
 * @complexity O(N^2)
 * @param graph
 * @return Returns the vector representing the best tour found by the algorithm.
 */
vector<int> linKernighan(const Graph& graph) {
    LoadFiles lf;
    clock_t startTime = clock();
    vector<vector<float>> distances = lf.createDistanceMatrix(graph);

    std::vector<int> bestTour;
    float bestCost = std::numeric_limits<float>::max();

    std::vector<Vertex*> vertices = graph.getVertexSet();
    std::vector<int> currentTour;
    for (const Vertex* vertex : vertices)
        currentTour.push_back(vertex->getID());
    currentTour.push_back(0);

    float initialCost = calculate_distance(currentTour, graph);
    if (initialCost < bestCost) {
        bestCost = initialCost;
        bestTour = currentTour;
    }

    bool improvement = true;
    while (improvement) {
        improvement = false;

        for (int i = 0; i < vertices.size() - 1; ++i) {
            for (int j = i + 1; j < vertices.size(); ++j) {
                std::vector<int> newTour = PerformLinKernighanOptimization(graph, currentTour, i, j, distances);
                float newCost = calculate_distance(newTour, graph);

                if (newCost < bestCost) {
                    bestCost = newCost;
                    bestTour = newTour;
                    improvement = true;
                }
            }
        }

        currentTour = bestTour;
    }
    clock_t endTime = clock();

    cout << "the improved path is: ";
    int c =0;
    for (auto a: bestTour){
        if (c!=bestTour.size()-1) {
            cout << a << " -> ";
        }
        else{
            cout << a;
        }
        c++;
    }
    cout << endl;

    cout << "The improved distance is: " << calculate_distance(bestTour, graph) << endl;
    cout << "Time took by lin Kernighan: " << (double)(endTime - startTime)/CLOCKS_PER_SEC << " seconds" << endl;
    return bestTour;
}
/**
 * Performs a local optimization step using Lin-Kernighan
 * improvement rules on a given tour within the Lin-Kernighan heuristic algorithm.
 * @complexity O(N^2)
 * @param graph
 * @param tour
 * @param u
 * @param v
 * @param distances
 * @return Returns the new tour obtained after applying the Lin-Kernighan optimization rules.
 */
vector<int> PerformLinKernighanOptimization(const Graph& graph, const std::vector<int>& tour, int u, int v, vector<vector<float>> distances) {
    std::vector<int> newTour = tour;

    // Step 1: Reverse the subsequence between vertices u and v
    std::reverse(newTour.begin() + u + 1, newTour.begin() + v + 1);

    // Step 2: Apply Lin-Kernighan improvement rules
    bool improvement = true;
    while (improvement) {
        improvement = false;

        // Iterate through the remaining tour vertices
        for (int i = 0; i < newTour.size() - 2; ++i) {
            for (int j = i + 1; j < newTour.size()-1; ++j) {
//                vector <int> aux1 = {newTour[i], newTour[i + 1]};
//                vector <int> aux2 = {newTour[j], newTour[j + 1]};
//                vector <int> aux3 = {newTour[i], newTour[j]};
//                vector <int> aux4 = {newTour[i + 1], newTour[j + 1]};
//                cout << "I: " << i << " J: " << j << "\t";
//                cout << "Distance: " << distances[i][i+1] << " " << distances[j][j+1] << " " << distances[i][j] << " " << distances[i+1][j+1] << endl;
                float currentCost = distances[newTour[i]][newTour[i+1]] + distances[newTour[j]][newTour[j+1]];
                float newCost = distances[newTour[i]][newTour[j]] + distances[newTour[i+1]][newTour[j+1]];

                // If the new cost is lower, perform the 2-opt exchange
                if (newCost < currentCost) {
                    std::reverse(newTour.begin() + i + 1, newTour.begin() + j + 1);
                    improvement = true;
                }
            }
        }
    }


    return newTour;
}

