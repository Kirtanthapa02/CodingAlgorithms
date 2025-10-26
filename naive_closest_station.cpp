// Naive BFS approach to find closest police_station distance

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    int v = 6;
    int n_edge = 9;
    vector<int> police_station = {1,5};
    vector<int> edges[n_edge] = {
                            {1,2},{1,6},{2,3},{2,6},{3,6},
                            {6,5},{3,4},{5,4},{5,3}
                        };
    // int v = 7;
    // int n_edge = 6;
    // vector<int> police_station = {1, 7};
    // vector<int> edges[n_edge] = {
    //     {1,2},{2,3},{3,4},{4,5},{5,6},{6,7}
    // };
    // int v = 6;
    // int n_edge = 3;
    // vector<int> police_station = {1};
    // vector<int> edges[n_edge] = {
    //     {1,2},{2,3},{4,5}
    // };
    // int v = 5;
    // int n_edge = 4;
    // vector<int> police_station = {1,2,3,4,5};
    // vector<int> edges[n_edge] = {
    //     {1,2},{2,3},{3,4},{4,5}
    // };

    vector<int> graph[v+1];
    //create adjacency graph
    for(vector<int> edge:edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<int> distances[v+1];
    //initialize distances
    for(int i=1;i<=v;i++){
        distances[i].push_back(i);
        distances[i].push_back(INT_MAX);
    }
    function<void(int)> find_closest_dist = [&] (int src){
        vector<int> visited(v+1,false);
        queue<int> q;
        q.push(src);
        distances[src] = {src,0};
        while(!q.empty()){
            int cur_node = q.front();
            visited[cur_node] = true;
            int cur_distance = distances[cur_node][1];
            q.pop();
            for(int neighbour:graph[cur_node]){
                if(!visited[neighbour] && distances[neighbour][1] > cur_distance + 1){
                    distances[neighbour] = {neighbour,cur_distance + 1};
                    q.push(neighbour);
                }
            }
        }
    };
    for(int src:police_station){
        find_closest_dist(src);
    }
    //print adjacency graph
    cout<<"adjacency graph:"<<endl;
    for(int i=1;i<=v;i++){
        cout<<i<<":";
        for(int neighbour:graph[i])
            cout<<neighbour<<" ";
        cout<<endl;
    }
    //print distances
    cout<<"nearest police station distances:"<<endl;
    for(int i=1;i<=v;i++)
        cout<<distances[i][0]<<":"<<distances[i][1]<<endl;
    return 0;
}