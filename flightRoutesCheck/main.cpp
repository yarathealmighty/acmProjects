#include <bits/stdc++.h>
#define endl "\n"
#define BUG

using namespace std;

vector<set<int>> g;
vector<set<int>> invg;
queue<int> q;
vector<bool> visited;
vector<bool> invVisited;
int last;

void BFS(bool normal=true){
    while(!q.empty()){
        last = q.front();
        int node = q.front();
        //normal/inverted switch
        if(normal) {
            visited[node] = true;
        } else {
            invVisited[node] = true;
        }
        q.pop();
        //normal/inverted switch
        if(normal) {
            for (auto itr: g[node]) {
                if (!visited[itr]) {
                    q.push(itr);
                }
            }
        } else {
            for(auto itr: invg[node]){
                if(!invVisited[itr]){
                    q.push(itr);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n,m,a,b;
    cin >> n >> m;
    g.resize(n+1);
    invg.resize(n+1);
    visited.resize(n+1);
    invVisited.resize(n+1);
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
    q.push(last);
    BFS(false);
#ifdef BUG
    cout << "[LOG]last: " << last << endl;
    cout << "[LOG]visited: " << accumulate(visited.begin(),visited.end(),0) << endl;
    for(int i=1;i<=n;i++){
        if(visited[i]){
            cout << "+";
        } else {
            cout << "-";
        }
    }
    cout << endl;

    cout << "[LOG]invVisited: " << accumulate(invVisited.begin(),invVisited.end(),0) << endl;
    for(int i=1;i<=n;i++){
        if(invVisited[i]){
            cout << "+";
        } else {
            cout << "-";
        }
    }
    cout << endl;
#endif
    if(accumulate(visited.begin(),visited.end(),0)!=n || accumulate(invVisited.begin(),invVisited.end(),0)!=n){
        cout << "NO" << endl;
        //todo print vertices that don't match (also figure out how to do that) or find out the first one that neither visited nor invVisited contains
    } else {
        cout << "YES" << endl;
    }

    return 0;
}
