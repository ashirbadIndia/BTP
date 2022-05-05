#include <bits/stdc++.h>
#include "graph.h"
#include "containers.h"

using namespace std;

void add_to_edge_seq(Graph &G,stack<edge> &S,edge E){
    if(S.empty()){
        S.push(E);
    }
    else{
        edge top = S.top();
        if(top.type == 1 || E.type == 1){
            S.push(E);
        }
        else{
            S.pop();
            edge tmp;
            tmp.s = top.s;
            tmp.e = E.e;
            tmp.S = G.vertices[tmp.s];
            tmp.E = G.vertices[tmp.e];
            tmp.type = 4;
            tmp.dist= G.dist(G.vertices[tmp.s].x,G.vertices[tmp.s].y,G.vertices[tmp.e].x,G.vertices[tmp.e].y);
            S.push(tmp);
        }
    }
}
    

vector<edge> euler_path_edge_seq(Graph &G,vector<vector<int>> alt_edges,vector<int> &euler_path){
    vector<vector<int>> def_edges = G.adj_matrix;
    stack<edge> S;
    for(int i=0;i<euler_path.size()-1;i++){
        edge E;
        E.s = euler_path[i];
        E.e = euler_path[i+1];
        E.S = G.vertices[E.s];
        E.E = G.vertices[E.e];
        if(def_edges[E.s][E.e]>0){

            E.type=def_edges[E.s][E.e];
            E.dist = G.dist(G.vertices[E.s].x,G.vertices[E.s].y,G.vertices[E.e].x,G.vertices[E.e].y);
            
            def_edges[E.s][E.e]=0;
            def_edges[E.e][E.s]=0;

            add_to_edge_seq(G,S,E);
        }
        else if(alt_edges[E.s][E.e]>0){

            E.type=alt_edges[E.s][E.e];
            E.dist = G.dist(G.vertices[E.s].x,G.vertices[E.s].y,G.vertices[E.e].x,G.vertices[E.e].y);
            
            alt_edges[E.s][E.e]=0;
            alt_edges[E.e][E.s]=0;

            add_to_edge_seq(G,S,E);
        }
    }
    vector<edge> edge_seq(S.size());
    int mx_e = -1;
    for(int i=S.size()-1;i>=0;i--){
        edge_seq[i] = S.top();
        S.pop();
        if(edge_seq[i].type!=1){
            if(mx_e==-1){
                mx_e = i;
            }
            else{
                mx_e = (edge_seq[mx_e].dist < edge_seq[i].dist)? i : mx_e;
            }
        }
        
    }
    //cout<<mx_e<<endl;
    vector<edge> path_edge_seq(edge_seq.size()-1);

    if(mx_e!=-1){
        int l = 0;
        for(int i=mx_e+1;i<edge_seq.size();i++){
            path_edge_seq[l] = edge_seq[i];
            l++;
        }
        for(int i=0;i<mx_e;i++){
            path_edge_seq[l]=edge_seq[i];
            l++;
        }
    }

    return path_edge_seq;
}

void find_euler_path(vector<vector<int>> &def_edges,vector<vector<int>> &alt_edges,vector<int> &euler_path,int V){
    int n = def_edges.size();
    for(int i=0;i<n;i++){
        if(def_edges[V][i]!=0){
            def_edges[V][i]=0;
            def_edges[i][V]=0;
            find_euler_path(def_edges,alt_edges,euler_path,i);
        }
    }
    for(int i=0;i<n;i++){
        if(alt_edges[V][i]!=0){
            alt_edges[V][i]=0;
            alt_edges[i][V]=0;
            find_euler_path(def_edges,alt_edges,euler_path,i);
        }
    }
    euler_path.push_back(V);
}

vector<edge> find_optimal_path(Graph &G,vector<vector<int>> &new_added_edges){
    vector<vector<int>> def_edges = G.adj_matrix;
    vector<vector<int>> alt_edges = new_added_edges;
    vector<int> euler_path; 
    find_euler_path(def_edges,alt_edges,euler_path,0);

    vector<edge> opt_edge_seq = euler_path_edge_seq(G,new_added_edges,euler_path);

    for(int i=0;i<opt_edge_seq.size();i++){
        cout<<opt_edge_seq[i].s<<" "<<opt_edge_seq[i].e<<" "<<opt_edge_seq[i].type<<" "<<opt_edge_seq[i].dist<<endl;
    }
    cout<<endl;
    return opt_edge_seq;
}