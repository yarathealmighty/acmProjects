#include <bits/stdc++.h>
//#define BUG

using namespace std;

typedef struct{
    int index;
    int moves;
    set<int> neighbors;
}Node;

Node nodes[100001];
int n;
string route[100001];

void DFS(Node node){
    if(node.index==n){
        return;
    } else {
        for(auto itr : node.neighbors){
            if(nodes[itr].moves>node.moves+1){
                route[node.moves]=to_string(itr);
                nodes[itr].moves = node.moves+1;
                DFS(nodes[itr]);
            }
        }
    }
}

int main() {
    int m,a,b;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        nodes[i+1].index=i+1;
        nodes[i+1].moves=INT32_MAX;
        route[i]="#";
    }

    for(int i=0;i<m;i++){
        cin >> a >> b;
        nodes[a].neighbors.insert(b);
        nodes[b].neighbors.insert(a);
    }

    nodes[1].moves=1;
    route[0]="1";
    DFS(nodes[1]);

    if(nodes[n].moves==INT32_MAX){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    } else {
        cout << nodes[n].moves << endl;
        for(int i=0;i<nodes[n].moves;i++){
            cout << route[i] << " ";
        }
    }
    cout << endl;

#ifdef BUG
    for(int i=0;i<n;i++){
        cout << nodes[i+1].index << ": " << nodes[i+1].moves << endl;
    }
#endif

    return 0;
}
