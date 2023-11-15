#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<set<int>> g;

void traverse(int pos){
    //todo actual implementation here
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n,m,a,b;
    bool possible=true;
    cin >> n >> m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        cin >> a >>b;
        g[a].insert(b);
    }

    traverse(1);

    if(possible){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        //todo print vertices that make this impossible here
    }


    return 0;
}
