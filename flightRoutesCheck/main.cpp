#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<set<int>> g;
vector<set<int>> invg;
queue<int> q;
vector<bool> visited;
vector<bool> invVisited;
int last;

void BFS(){
    while(!q.empty()){
        int node = q.front();
        visited[node]=true;
        q.pop();
        for(auto itr: g[node]){
            if(!visited[itr]){
                q.push(itr);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n,m,a,b;
    cin >> n >> m;
    g.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<m;i++){
        cin >> a >>b;
        g[a].insert(b);
        invg[b].insert(a);
    }

    //normal traverse
    fill(visited.begin(),visited.end(),false);
    q.push(1);
    BFS();
    //inverted traverse
    fill(visited.begin(),visited.end(),false);
    //todo figure out last
    q.push(last);
    BFS();
    if(accumulate(visited.begin(),visited.end(),0)!=n && accumulate(invVisited.begin(),invVisited.end(),0)!=n){
        cout << "NO" << endl;
        //todo print vertices that don't match (also figure out how to do that) or find out the first one that neither visited nor invVisited contains
    } else {
        cout << "YES" << endl;
    }

    return 0;
}
