//Topological sorting with DFS

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool topological_sort(int start_vertex,vector<vector<int>> &adj,
                        vector<bool> &visited,vector<bool> &local,stack<int> &s){
    visited[start_vertex] = true;
    local[start_vertex] = true;
    
    vector<int> neighbour = adj[start_vertex]; 
    for(int i=0;i<neighbour.size();i++){
        if(!visited[neighbour[i]] && !topological_sort(neighbour[i],adj,visited,local,s)){
            return false;
        }
        else if(local[neighbour[i]]){
            cout<<"Cycle detected, topological_sort not possible"<<endl;
            return false;
        }
    }
    local[start_vertex] = false;
    s.push(start_vertex);
    return true;
}
 /*
    call stack1:
        (0,adj,[0,0,0,0,0,0],[0,0,0,0,0],[]):
            visited = [1,0,0,0,0,0]
            local = [1,0,0,0,0,0]
            neighbour = []
            local = [0,0,0,0,0,0]
            s = [0]
    call stack2:
        (1,adj,[1,0,0,0,0,0],[0,0,0,0,0],[0]):
            visited = [1,1,0,0,0,0]
            local = [0,1,0,0,0,0]
            neighbour = []
            local = [0,0,0,0,0,0]
            s = [1,0]
    call stack3:
        (2,adj,[1,1,0,0,0,0],[0,0,0,0,0,0],[1,0]):
            visited = [1,1,1,0,0,0]
            local = [0,0,1,0,0,0]
            neighbour = [3]
            visited[3] == false
                call stack31:
                    (3,adj,[1,1,1,0,0,0],[0,0,1,0,0,0],[1,0]):
                        visited = [1,1,1,1,0,0]
                        local = [0,0,1,1,0,0]
                        neighbour = [1]
                        visited[1] == true
                        local[1] == false
                        
                        local = [0,0,1,0,0,0]
                        s = [3,1,0]
                return true;
            local = [0,0,0,0,0,0]
            s = [2,3,1,0]
            return;
*/
int main()
{
    //with cycle
    //int v = 6;
    // vector<vector<int>> edges = {
    //     {1,2},{2,3}, {3,1}, {4,0}, {4,1}, {5,0}, {5,2}  
    // };
    
    //without cycle
    int v = 6;
    vector<vector<int>> edges = {
        {2,3}, {3,1}, {4,0}, {4,1}, {5,0}, {5,2}  
    };
    //int v = 5;
    // vector<vector<int>> edges = {{0,1}, {1,2}, {3,2}, {3,4}};
    //build adjacencylist 
    vector<vector<int>> adj(v);
    for(vector<int> edge:edges)
        adj[edge[0]].push_back(edge[1]);
    /*
        0: []
        1: []
        2: [3]
        3: [1]
        4: [0,1]
        5: [0,2]
    */
    //visited vector                //vertices = 0,1,2,3,4,5
    vector<bool> visited(v,false); // visited = [0,0,0,0,0,0]
    
    vector<bool> local(v,false); //this detects cycles 
    stack<int> s;
    for(int i=0;i<visited.size();i++){
        if(visited[i]==0){
            if(!topological_sort(i,adj,visited,local,s)){
                return 0;
            }
        }
    }
    /*
        (0,adj,[0,0,0,0,0,0],[])
    */
    cout<<"Adjacency list graph"<<endl;
    for(int i=0;i<adj.size();i++){
        cout<<i<<":";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<",";
        }
        cout<<endl;
    }
    vector<int> ans;
    for(int i=0;i<v;i++){
        ans.push_back(s.top());
        s.pop();
    }
    cout<<"topological_sort: ";
    for(int i:ans)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}