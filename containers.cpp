#include<bits/stdc++.h>
#include "containers.h"
#include "debug.h"

using namespace std;

vertex::vertex(float X,float Y){
    x=X;
    y=Y;
}
vertex::vertex(pair<float,float> P){
    x=P.first;
    y=P.second;
}

segment::segment(int P1,int P2){
    p1 = P1;
    p2 = P2;
}
segment::segment(pair<int,int> P){
    p1 = P.first;
    p2 = P.second;
}

segment_connector::segment_connector(int S1,int S2,int P1,int P2,float D){
    s1 = S1;
    s2 = S2;
    p1 = P1;
    p2 = P2;
    d = D;
}

mds_config_of_tree::mds_config_of_tree(){
    mds_req = 0;
    dist = 0;
}

mds_config_of_tree::mds_config_of_tree(vector<edge> &seq, int v){
    edge_seq = seq;
    dist = 0;
    for(int i=0;i<seq.size();i++){
        dist += seq[i].dist;
    }
    mds_req = dist/v + ((fmod(dist,v))>0?1:0);
}

mds_config_of_forest::mds_config_of_forest(){
    dist = 0;
    mds_req = 0;
}

void mds_config_of_forest::add_(mds_config_of_tree i){
    trees.push_back(i);
    mds_req += i.mds_req;
    dist += i.dist;
}