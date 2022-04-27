#ifndef CONTAINER_H
#define CONTAINER_H

#include<bits/stdc++.h>

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

#endif