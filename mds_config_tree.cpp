#include<bits/stdc++.h>
#include "graph.h"
#include "containers.h"

using namespace std;

void Find_MDS_CONFIG_TREE(Graph &G){
    int n = G.vertices.size();
    vector<int> degree(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            degree[i]+=(G.adj_matrix[i][j]!=0);
        }
    }
    cout<<"^"<<endl;
    vector<int> odd_vertices;
    for(int i=0;i<n;i++){
        cout<<degree[i]<<" ";
        if(degree[i]%2==1){
            odd_vertices.push_back(i);
        }
    }
    cout<<endl;
    for(int i=0;i<odd_vertices.size();i++){
        cout<<odd_vertices[i]<<" ";
    }
    cout<<endl;
}