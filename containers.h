#ifndef CONTAINER_H
#define CONTAINER_H

#include<bits/stdc++.h>

using namespace std;

class vertex{
    public:
    float x,y;
    vertex(){}
    vertex(float X,float Y);
    vertex(std::pair<float,float> P);
};

class segment{
    public:
    int p1,p2;
    segment(){}
    segment(int P1,int P2);
    segment(std::pair<int,int> P);
};

class segment_connector{
    public:
    int s1, s2;
    int p1, p2;
    float d;
    segment_connector(){}
    segment_connector(int S1,int S2,int P1,int P2, float D);
};

class edge{
    public:
    int s, e;
    int type;
    float dist;
    edge(){}
};

class mds_config_of_tree{
    public:
    vector<edge> edge_seq;
    float dist;
    int mds_req;
    mds_config_of_tree();
    mds_config_of_tree(vector<edge> &seq,int v);
};

class mds_config_of_forest{
    public:
    vector<mds_config_of_tree> trees;
    float dist;
    int mds_req;
    mds_config_of_forest();
    void add_(mds_config_of_tree i);
};

#endif