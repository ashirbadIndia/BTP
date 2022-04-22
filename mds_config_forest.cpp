#include<bits/stdc++.h>
#include "graph.h"
#include "containers.h"

using namespace std;

void DFS(vector<vector<int>> &mat, vector<bool> &vis,vector<int> &nodes,int u){
    if(!vis[u]){
        vis[u]=1;
        nodes.push_back(u);
        for(int i=0;i<mat[u].size();i++){
            if(mat[u][i]==1 || mat[u][i]==2){
                DFS(mat,vis,nodes,i);
            }
        }
    }
}

Graph createSubGraph(Graph &P,vector<vector<int>> &new_forest,vector<int> &nodes){
    Graph subG;
    int n = nodes.size();
    subG.vertices.resize(n);
    subG.segments.resize(n/2);
    subG.adj_matrix.resize(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        subG.vertices[i] = P.vertices[nodes[i]];
    }
    int l = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(new_forest[nodes[i]][nodes[j]] == 1){
                subG.adj_matrix[i][j]=1;
                subG.adj_matrix[j][i]=1;
                subG.segments[l] = {j,i};
                l++;
            }
            else if(new_forest[nodes[i]][nodes[j]] == 2){
                subG.adj_matrix[i][j]=2;
                subG.adj_matrix[j][i]=2;
            }
        }
    }
    return subG;
}

void Find_MDS_CONFIG_FOREST(Graph &G){
    int m = G.segments.size();
    int n = G.adj_matrix.size();
    for(int k=0;k<m;k++){
        vector<vector<int>> new_forest = G.adj_matrix;
        for(int i=0;i<k;i++){
            new_forest[G.ISC[i].p2][G.ISC[i].p1] = 2;
            new_forest[G.ISC[i].p1][G.ISC[i].p2] = 2;
        }
        for(int i=0;i<new_forest.size();i++){
            for(int j=0;j<new_forest[i].size();j++){
                cout<<new_forest[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> nodes;
                DFS(new_forest,vis,nodes,i);
                for(int j=0;j<nodes.size();j++){
                    cout<<nodes[j]<<" ";
                }
                cout<<endl;
                Graph subG = createSubGraph(G,new_forest,nodes);
                subG.print_graph();
                cout<<"-------"<<endl<<"-------"<<endl;
            }
            //cout<<endl;
        }
        cout<<"*************************************/n"<<endl<<"*************************************/n"<<endl;
    }
}