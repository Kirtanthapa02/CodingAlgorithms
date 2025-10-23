//kahn's algorithm for topological sorting

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    //without cycle
    int v = 6;
    vector<vector<int>> edges = {{0,1},{1,2},{4,5},{2,3},{5,1},{5,2}};
    
    // //with cycle
    // int v = 6;
    // vector<vector<int>> edges = {{0,1},{1,2},{4,5},{2,3},{5,1},{5,2},{3,1}};
    
    vector<vector<int>> adj(v);
    for(const vector<int> edge:edges){
        adj[edge[0]].push_back(edge[1]);
    }
    
    cout<<"adjacency graph:"<<endl;
    for(int i=0;i<adj.size();i++){
        cout<<i<<":";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    
    vector<int> indegree(v,0);
    for(const vector<int> edge:edges){
        indegree[edge[1]]++;
    }
    cout<<"indegree of each vertex: ";
    
    for(int i:indegree)
        cout<<i<<" ";
    cout<<endl;
    
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){ 
            q.push(i);
        }
    }
    
    vector<int> ans;
    while(!q.empty()){
        int vertex = q.front();
        ans.push_back(vertex);
        q.pop();
        for(int neighbour:adj[vertex]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
                q.push(neighbour);
        }
    }
    if (ans.size() != v) {
        cout << "Cycle detected. Topological sort not possible" << endl;
        return 0;
    }
    cout<<"Topological sorting: ";
    for(const int i:ans)
        cout<<i<<" ";
    cout<<endl;
    
    return 0;
}