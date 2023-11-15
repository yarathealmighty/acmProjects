//https://cses.fi/problemset/task/1682
#include <bits/stdc++.h>
#define endl "\n"
//#define BUG

using namespace std;

vector<set<int>> g;
vector<set<int>> invg;
queue<int> q;
vector<bool> visited;
vector<bool> invVisited;
int last;

void BFS(bool normal=true){
    while(!q.empty()){
        int node = q.front();
        //we don't need this in the inverted traverse but will come handy later
        if(normal) {
            last = node;
        }
        q.pop();
        //normal/inverted switch
        if(normal) {
            for (auto itr: g[node]) {
                if (!visited[itr]) {
                    visited[itr]=true;
                    q.push(itr);
                }
            }
        } else {
            for(auto itr: invg[node]){
                if(!invVisited[itr]){
                    invVisited[itr]=true;
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

#ifdef BUG
    cout << "[LOG]last: " << last << endl;
#endif

    //inverted traverse
    fill(invVisited.begin(),invVisited.end(),false);
    q.push(last);
    BFS(false);

#ifdef BUG
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

    int normalsum= accumulate(visited.begin(),visited.end(),0);
    int invertedsum = accumulate(invVisited.begin(),invVisited.end(),0);
    if(normalsum!=n || invertedsum!=n){
        //this part is incredibly ugly, but it essentially checks which route could access more vertices
        //and tries to find the needed path between 2 vertices based on which was visited before in which path
        cout << "NO" << endl;
        if(normalsum>invertedsum) {
            for (int i = 1; i <= n; i++) {
                if (!invVisited[i]) {
                    cout << i << " ";
                    if (i == last) {
                        for (int j = 1; j <= n; j++) {
                            if (!visited[j]) {
                                cout << j << endl;
                            }
                        }
                    } else {
                        cout << last << endl;
                    }
                    break;
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    if (i == last) {
                        for (int j = 1; j <= n; j++) {
                            if (!invVisited[j]) {
                                cout << j << " ";
                            }
                        }
                    } else {
                        cout << last << " ";
                    }
                    cout << i << endl;
                    break;
                }
            }
        }
    } else {
        cout << "YES" << endl;
    }

    return 0;
}
