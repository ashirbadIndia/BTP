#include<bits/stdc++.h>
#include "graph.h"

using namespace std;

bool compare_segment_connector(segment_connector s1, segment_connector s2){
    return s1.d<s2.d;
}

Graph::Graph(){}

Graph::Graph(vector<vector<float>> input){
    int n = input.size();
    vertices.resize(n*2);
    segments.resize(n);
    adj_matrix.resize(n*2,vector<int>(n*2));
    for(int i=0;i<n;i++){
        vertices[2*i] = {input[i][0],input[i][1]};
        vertices[2*i + 1] = {input[i][2],input[i][3]};
        segments[i] = {2*i, 2*i + 1};
        adj_matrix[2*i][2*i +1] = 1;
        adj_matrix[2*i + 1][2*i] = 1;
    }
    find_segment_connectors();
    sort(ISC.begin(),ISC.end(),compare_segment_connector);
}

float Graph::dist(float x1,float y1,float x2,float y2){
    return sqrtf(powf(x1-x2,2)+powf(y1-y2,2));
}

segment_connector Graph::find_segment_connector(int s1, int s2){
    //cout<<endl<<s1<<" "<<s2<<"\t";
    // x11, segment no. 1, vertex no. 2
    float x11 = vertices[segments[s1].p1].x, y11 = vertices[segments[s1].p1].y;
    float x12 = vertices[segments[s1].p2].x, y12 = vertices[segments[s1].p2].y;
    float x21 = vertices[segments[s2].p1].x, y21 = vertices[segments[s2].p1].y;
    float x22 = vertices[segments[s2].p2].x, y22 = vertices[segments[s2].p2].y;
    //cout<<"("<<x11<<","<<y11<<") "<<"("<<x12<<","<<y12<<") "<<"("<<x21<<","<<y21<<") "<<"("<<x22<<","<<y22<<") \n";
    // dxy, segment 1,vertex x,  segment 2 vertex y
    float d11 = dist(x11,y11,x21,y21);
    float d12 = dist(x11,y11,x22,y22);
    float d21 = dist(x12,y12,x21,y21);
    float d22 = dist(x12,y12,x22,y22);
    float min_ = min(min(d11,d12),min(d21,d22));
    //cout<<d11<<" "<<d12<<" "<<d21<<" "<<d22<<endl<<endl;
    if(min_ == d11){
        return segment_connector(s1,s2,segments[s1].p1,segments[s2].p1,d11);
    }
    else if(min_ == d12){
        return segment_connector(s1,s2,segments[s1].p1,segments[s2].p2,d12);
    }
    else if(min_ == d21){
        return segment_connector(s1,s2,segments[s1].p2,segments[s2].p1,d21);
    }
    else {
        return segment_connector(s1,s2,segments[s1].p2,segments[s2].p2,d22);
    }
}

void Graph::find_segment_connectors(){
    int n = segments.size();
    ISC.resize((n*(n-1))/2);
    int l = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            ISC[l++] = find_segment_connector(i,j);
        }
    }
}


void Graph::print_graph(){
    int n = segments.size();
    cout<<endl<<"Vertices"<<endl;
    for(int i=0;i<vertices.size();i++){
        cout<<i<<"\t"<<"("<<vertices[i].x<<", "<<vertices[i].y<<") "<<endl;
    }
    cout<<endl<<endl;
    cout<<endl<<"Segments"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<segments[i].p1<<" "<<segments[i].p2<<"\t"<<"("<<vertices[segments[i].p1].x<<", "<<vertices[segments[i].p1].y<<") "<<"\t("<<vertices[segments[i].p2].x<<", "<<vertices[segments[i].p2].y<<") "<<endl;
    }
    cout<<endl<<endl;
    cout<<endl<<"Adj Matrix"<<endl;
    for(int i=0;i<adj_matrix.size();i++){
        for(int j=0;j<adj_matrix[i].size();j++){
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl<<"ISC"<<endl;
    for(int i=0;i<ISC.size();i++){
        cout<<ISC[i].s1<<" "<<ISC[i].s2<<" "<<ISC[i].p1<<" "<<ISC[i].p2<<" "<<ISC[i].d<<endl;
    }
}