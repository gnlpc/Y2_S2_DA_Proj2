
#ifndef TRABALHO2_FUNCTIONS_H
#define TRABALHO2_FUNCTIONS_H



#include <algorithm>
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
#include "LoadFiles.h"
#include <ctime>



/*
 * Function to calculate distance from a vector in a certain graph
 * */

float calculate_distance(vector<int>& path, const Graph& graph);

/*
 *Function that does brute force for every possibility in the graph and returns the minimum distance
 * */
float backtrack(const Graph& graph, vector <int> path, vector<bool>& visited, float total_distance, float min_distance, vector<int> &path_min) ;

/*
 * Function that arranges and prepares the backtrack and sets the timer
 * */

/*
 * to be called for the exercise 4.1
 * */
float tsp(const Graph& graph);




/*
 * Function that goes through the graoh and finds the minimum distance between the edges
 * returns a vector with the path that adds the min distance
 * */

vector<int> min_path(const Graph& graph);


/*
 * Function that returns the minimum distance between the edges not present in the path
 * */
int find_minimum(const Graph &graph, int id, vector<int> path);

/*
 * Function that checks if it is faster to go from A to B or from A to B to C
 * if it is faster, then remove B
 *
 * After removing, checks all the elements not present in the path
 * if the two lightest edges are consecutive in the path adds it in the middle, and checks this first for every element
 * if there is still elements missing in the path, does brute force for the best solution
 * */


vector<int> triangular (const Graph& graph, vector<int>& min);


/*
 * Function to remove elements duplicated in a vector
 * */
void removeDuplicates(std::vector<int>& vec);


/*
 * Function that returns a vector of elements not present in the path
 * */


vector<int> notUsed(const Graph& graph, vector<int>& min);



/*
 * Auxiliar function to insert the elements that are not yet present in the path
 * */
void insertNotUsed (const Graph& graph, vector<int>& path, vector<int> notUsed);

/*
 * Exercise 4.2 function
 */

void triangularApproximationH(const Graph& graph);


/*
 * Function that calls all function needed in the 4.3 exercise and starts the timer and stops it
 * prints the values
 * */

/*
 * to be called for the exercise 4.3
 * */

void join4 (const Graph& graph);

vector<int> linKernighan (const Graph& graph);

vector<int> PerformLinKernighanOptimization(const Graph& graph, const std::vector<int>& tour, int u, int v, vector<vector<float>> distances);


#endif //TRABALHO2_FUNCTIONS_H