#ifndef GRAPH_H
#define GRAPH_H


#include<bits/stdc++.h>
#include "containers.h"
using namespace std;

class Graph{
    public:
    vector<vertex> vertices;
    vector<segment> segments;
    vector<vector<int>> adj_matrix;
    vector<segment_connector> ISC;
    Graph();
    Graph(vector<vector<float>> input);
    void print_graph();
    private:
    float dist(float x1,float y1,float x2,float y2);
    segment_connector find_segment_connector(int s1, int s2);
    void find_segment_connectors();
};
#endif