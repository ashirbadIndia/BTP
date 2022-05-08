#include<bits/stdc++.h>

using namespace std;

int main(){

    float dis = 3;
    vector<vector<float>> points;
    int n = points.size();
    int d = 3;
    for(int i=0;i<20;i++){
        float x1 = ((float)(rand()%(1000*d)))/1000;
        float y1 = sqrt(pow(d,2)-pow(x1,2));
        cout<<x1<<" "<<y1<<endl;
        //cout<<points[i][0]<<" "<<points[i][1]<<" "<<points[i][0]+x1<<" "<<points[i][1]+y1<<endl;
    }
    return 0;
}