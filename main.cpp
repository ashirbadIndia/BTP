#include<bits/stdc++.h>
#include "graph.h"
#include "containers.h"

using namespace std;

int main(){
    vector<vector<float>> input = {{1,2,6,5},
                                 {21,10.3,100.5,120.6},
                                 {17.4,19,32.4,53},
                                 {45.4,12.6,21.3,64},
                                 {12.4,-21,54,100}
                                };
    Graph G(input);
    G.print_graph();
    return 0;
}