#include <bits/stdc++.h>

using namespace std;

typedef struct {
    set<int> neighbors;
    int represent;
}Node;

Node nodes[100001];

void connect(Node& node){
    for(auto itr : node.neighbors){
        if(node.represent != nodes[itr-1].represent) {
            nodes[itr - 1].represent = node.represent;
            connect(nodes[itr - 1]);
        }
    }
}

int main() {
    int n,m,a,b;
    cin >> n >> m;

    //graf
    for(int i=0;i<n;i++){
        nodes[i].represent = i+1;
    }

    //parok
    for(int i=0;i<m;i++){
        cin >> a >> b;
        nodes[a-1].neighbors.insert(b);
        nodes[b-1].neighbors.insert(a);
    }

    //reprezentansok beallitasa
    for(int i=1;i<n;i++){
        if(nodes[i-1].represent != nodes[i].represent){
            connect(nodes[i-1]);
        }
    }

    //komponensek osszeszamolasa es eltarolas
    set<int> componentRepresentants;
    componentRepresentants.insert(nodes[0].represent);
    for(int i=1;i<n;i++){
        if(nodes[i-1].represent != nodes[i].represent){
            componentRepresentants.insert(nodes[i].represent);
        }
    }

    //mennyi
    cout << componentRepresentants.size()-1 << endl;

    //melyikek (fúj de kókány)
    for(auto itr : componentRepresentants){
        if(itr!=nodes[0].represent){
            cout << nodes[0].represent << " " << itr << endl;
        }
    }

    return 0;
}
