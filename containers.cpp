#include<bits/stdc++.h>
#include "containers.h"

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