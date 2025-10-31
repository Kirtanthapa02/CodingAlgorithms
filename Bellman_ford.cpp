//Bellman-ford algorithm - loop over edges not nodes

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    //no negative weight cycle input
    int v = 5;
    int src = 0;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 1},
                                {1, 3, 2}, {2, 4, 1}, 
                                {4, 3, -1}};
    
    //negative weight cycle input
    // int v = 4;
    // int src = 0;
    // vector<vector<int>> edges = {
    //     {0, 1, 4}, {1, 2, -6}, {2, 3, 5}, {3, 1, -2}
    // };
    
    vector<int> distances(v,INT_MAX);
    distances[src] = 0;
    
    for(int i=0;i<=v;i++){
        for(vector<int> edge:edges){
            if(distances[edge[1]] > distances[edge[0]] + edge[2]){
                if(i == v-1){
                    cout<<"negative weight cycle exist"<<endl;
                    return 0;
                }
                distances[edge[1]] = distances[edge[0]] + edge[2];
            }
        }
    }
    
    cout<<"shortest distances from "<<src<<endl;
    for(int i=0;i<distances.size();i++){
        cout<<i<<":"<<distances[i]<<endl;
    }
    return 0;
}