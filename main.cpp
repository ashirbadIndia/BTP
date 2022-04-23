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
    Graph G(input);
    G.print_graph();
    Find_MDS_CONFIG_FOREST(G);
    return 0;
}