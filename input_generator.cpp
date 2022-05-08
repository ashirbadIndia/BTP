#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<vector<bool>> grid(40,vector<bool>(40,0));

    int dis = 3;

    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            if(grid[i][j]==0){
                float x = ((float)(rand()%(1000)))/1000;
                float y = ((float)(rand()%(1000)))/1000;
                //cout<<i+x1<<" "<<j+y1<<endl;
                int d = dis;
                float dx = ((float)(rand()%(1000*d)))/1000;
                float dy = sqrt(pow(d,2)-pow(dx,2));
                for(int k=i;k<=(i+d);k++){
                    for(int l=j;l<=j+d;l++){
                        grid[k][l]=1;
                    }
                }
                //cout<<i<<" "<<j<<" "<<i+d+1<<" "<<j+d+1<<endl;
                if(rand()%2==1){
                    //cout<<i+x<<" "<<j+y<<" "<<i+x+dx<<" "<<j+y+dy<<" "<<d<<" up"<<endl<<endl;
                    cout<<i+x<<" "<<j+y<<" "<<i+x+dx<<" "<<j+y+dy<<endl;
                }
                else{
                    //cout<<i+x<<" "<<j+d+y<<" "<<i+x+dx<<" "<<j+d+y-dy<<" "<<d<<" down"<<endl<<endl;
                    cout<<i+x<<" "<<j+d+y<<" "<<i+x+dx<<" "<<j+d+y-dy<<endl;
                }
            }
        }
    }
}