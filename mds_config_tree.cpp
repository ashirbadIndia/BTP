#include<bits/stdc++.h>
#include "graph.h"
#include "containers.h"
#include "mcpm.h"

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
    cout<<endl<<"Vertices degree"<<endl;
    for(int i=0;i<n;i++){
        cout<<degree[i]<<" ";
        if(degree[i]%2==1){
            odd_vertices.push_back(i);
        }
    }
    cout<<endl<<"Odd Vertices"<<endl;
    cout<<endl;
    for(int i=0;i<odd_vertices.size();i++){
        cout<<odd_vertices[i]<<" ";
    }
    cout<<endl;
    vector<vector<int>> matching = MinimumCostPerfectMatching(G,odd_vertices);
    vector<vector<int>> new_edges(n,vector<int>(n,0));
    for(int i=0;i<matching.size();i++){
        new_edges[matching[i][0]][matching[i][1]]=3;
        new_edges[matching[i][1]][matching[i][0]]=3;
    }

    cout<<endl<<"Euler Graph config"<<endl;
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<"("<<G.adj_matrix[i][j]<<","<<new_edges[i][j]<<")"<<"\t";
        }
        cout<<endl;
    }
}