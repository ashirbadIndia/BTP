#include<bits/stdc++.h>
#include "graph.h"
#include "containers.h"
#include "mds_config_forest.h"
#include "debug.h"

using namespace std;

pair<int, vector<vector<float>>> readInput(){
    ifstream file;
	file.open("input.txt");

    string s;
	getline(file, s);
	stringstream ss(s);
	int n;
	ss >> n;
	getline(file, s);
	ss.str(s);
	ss.clear();
	int v;
	ss >> v;
    vector<vector<float>> coordinates(n);
    for(int i=0;i<n;i++){
        vector<float> cur(4,0);
        getline(file, s);
		ss.str(s);
		ss.clear();
		ss >> cur[0] >> cur[1] >> cur[2] >> cur[3];
        coordinates[i] = cur;
    }
    return {v,coordinates};
}

int main(){

    pair<int, vector<vector<float>>> input = readInput();

    Graph G(input.second);
    if(DEBUG) G.print_graph();
    vector<mds_config_of_forest> ans = Find_MDS_CONFIG_FOREST(G,input.first);

    int n = ans.size();
    for(int i=0;i<n;i++){
        cout<<"ITERATION "<<i+1<<endl;
        cout<<"DIST "<<ans[i].dist<<endl;
        cout<<"MDS REQUIRED "<<ans[i].mds_req<<endl<<endl;
        for(int j=0;j<ans[i].trees.size();j++){
            cout<<"TREE "<<j+1<<endl;
            cout<<"\t DIST: "<<ans[i].trees[j].dist<<endl;
            cout<<"\t MDS REQUIRED: "<<ans[i].trees[j].mds_req<<endl;
            cout<<"\t EDGES ";
            vector<edge> edge_seq = ans[i].trees[j].edge_seq;
            for(int k=0;k<edge_seq.size();k++){
                cout<<"[("<<edge_seq[k].S.x<<","<<edge_seq[k].S.y<<"), ";
                cout<<"("<<edge_seq[k].E.x<<","<<edge_seq[k].E.y<<")],\t";
            }
            cout<<endl<<endl;
        }
        cout<<endl<<endl<<endl;
    }
    return 0;
}