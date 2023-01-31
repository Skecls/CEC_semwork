#include<bits/stdc++.h>

using namespace std;

class graphtraversal{
    public:
        void helpdfs(int node,vector<vector<int>> &graph,vector<int> &vis){
            vis[node] = 1;
            cout<<node<<" ";
            for(auto &x : graph[node]){
                if(!vis[x])
                    helpdfs(x,graph,vis);
            }
        }

        void DFS(vector<vector<int>> &graph,int n){
            vector<int> vis(n,0);
            for(int i = 0;i < n;i++){
                if(!vis[i]){
                    helpdfs(i,graph,vis);
                }
            }
        }

        void BFS(vector<vector<int>> &graph,int n){
            queue<int> q;
            vector<int> vis(n,0);
            for(int i = 0;i < n;i++){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                    while(!q.empty()){
                        int node = q.front();
                        q.pop();
                        cout<<node<<" ";
                        for(auto &x : graph[node]){
                            if(!vis[x]){
                                q.push(x);
                                vis[x] = 1;
                            }
                        }
                    }
                }
            }
        }
};

int main(){
    char ch = 'y';
    int n = 0,val;
    graphtraversal t;
    cout<<"enter the number of vertex:";
    cin>>n;
    //this is actually an adjacency list
    vector<vector<int>> graph;
    for(int i = 0;i < n;i++){
        vector<int> t;
        cout<<"enter the adjacent neighbours of node "<<i<<": \n";
        cout<<"(for next node press -1)\n";
        int temp = 0;
        while(temp != -1){
            cin>>temp;
            if(temp != -1)
                t.push_back(temp);
        }
        graph.push_back(t);
    }
    do{
        cout<<"select from the menu:\n";
        cout<<"1.DFS\n";
        cout<<"2.BFS\n";
        cout<<"enter your choice:";
        cin>>val;
        switch(val){
            case 1: t.DFS(graph,n);
                break;
            case 2: t.BFS(graph,n);
                break;
            default:cout<<"enter a valid choice";
        }
        cout<<"\ndo you want to continue(y/n):";
        cin>>ch;
        ch = tolower(ch);
        cout<<"\n\n";
    }while(ch == 'y');
    return 0;
}