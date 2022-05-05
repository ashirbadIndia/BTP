#include<bits/stdc++.h>
#include "graph.h"
#include "containers.h"
#include "mds_config_forest.h"

using namespace std;

int main(){
    vector<vector<float>> input = {{-17,-12,-12,-14},
                                 {-9,-11,-3,-9},
                                 {-15,-10,-11,-4},
                                 {-4,-6,-9.75,-2.75},
                                 {-15,-4,-13,1}
                                };

    int V = 4;

    Graph G(input);
    G.print_graph();
    vector<mds_config_of_forest> ans = Find_MDS_CONFIG_FOREST(G,V);

    int n = ans.size();
    for(int i=0;i<n;i++){
        cout<<"ITERATION "<<i+1<<endl;
        cout<<"DIST "<<ans[i].dist<<endl;
        cout<<"MDS REQUIRED "<<ans[i].mds_req<<endl<<endl;
        /*for(int j=0;j<ans[i].trees.size();j++){
            cout<<"TREE "<<j+1<<endl;
            cout<<"\t"<<;
        }*/
    }
    return 0;
}