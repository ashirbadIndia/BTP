#include<bits/stdc++.h>
#include "graph.h"
#include "containers.h"
#include "mcpm.h"
#include "find_optimal_path.h"
#include "debug.h"


using namespace std;

mds_config_of_tree Find_MDS_CONFIG_TREE(Graph &G, int v){
    int n = G.vertices.size();
    vector<int> degree(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            degree[i]+=(G.adj_matrix[i][j]!=0);
        }
    }
    if(DEBUG) cout<<"^"<<endl;
    vector<int> odd_vertices;
    if(DEBUG) cout<<endl<<"Vertices degree"<<endl;
    for(int i=0;i<n;i++){
        if(DEBUG) cout<<degree[i]<<" ";
        if(degree[i]%2==1){
            odd_vertices.push_back(i);
        }
    }
    if(DEBUG) cout<<endl<<"Odd Vertices"<<endl;
    if(DEBUG) cout<<endl;
    if(DEBUG) for(int i=0;i<odd_vertices.size();i++){
        cout<<odd_vertices[i]<<" ";
    }
    if(DEBUG) cout<<endl;
    vector<vector<int>> matching = MinimumCostPerfectMatching(G,odd_vertices);
    vector<vector<int>> new_edges(n,vector<int>(n,0));
    for(int i=0;i<matching.size();i++){
        new_edges[matching[i][0]][matching[i][1]]=3;
        new_edges[matching[i][1]][matching[i][0]]=3;
    }

    if(DEBUG) cout<<endl<<"Euler Graph config"<<endl;
    if(DEBUG) for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<"("<<G.adj_matrix[i][j]<<","<<new_edges[i][j]<<")"<<"\t";
        }
        cout<<endl;
    }
    vector<edge> opt_edge_seq = find_optimal_path(G,new_edges);

    mds_config_of_tree curr(opt_edge_seq,v);

    return curr;
}