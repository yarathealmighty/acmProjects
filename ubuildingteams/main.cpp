#include <bits/stdc++.h>

using namespace std;

typedef struct {
    bool wasChecked;
    int index;
    int color; //0 ures 1 kek 2 piros
    set<int> neighbors;
}Node;

Node nodes[100001];

bool coloring(Node& node){
    if(node.wasChecked){
        return true;
    }
    for(auto itr : node.neighbors){
        if(nodes[itr-1].color == node.color){
            cout << "IMPOSSIBLE" << endl;
            return false;
        } else {
            if(node.color == 1){
                nodes[itr-1].color = 2;
            } else {
                nodes[itr-1].color = 1;
            }
        }
    }
    node.wasChecked=true;
    for(auto itr : node.neighbors){
        if(!coloring(nodes[itr - 1])){
            return false;
        }
    }
    return true;
}

int main() {
    int n,m,a,b;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        nodes[i].wasChecked=false;
        nodes[i].index=i;
        nodes[i].color=0;
    }

    for(int i=0;i<m;i++){
        cin >> a >> b;
        nodes[a-1].neighbors.insert(b);
        nodes[b-1].neighbors.insert(a);
    }

    nodes[0].color = 1;
    if(!coloring(nodes[0])){
        return 0;
    }
    for(int i=0;i<n;i++){
        if(nodes[i].color==0){
            nodes[i].color=1;
            if(!coloring(nodes[i])){
                return 0;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << nodes[i].color << " ";
    }
    cout << endl;

    return 0;
}
