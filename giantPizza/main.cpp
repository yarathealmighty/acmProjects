//https://cses.fi/problemset/task/1684
#include <bits/stdc++.h>
#define endl "\n"
#define Clause pair<int,int>

using namespace std;

vector<Clause> sigma;

vector<char> confine(vector<Clause> sigma){
    vector<char> output;
    //todo confine
    return output;
}

int main(){
    int n,m,x,y;
    char tmpx,tmpy;
    bool possible=true;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tmpx >> x >> tmpy >> y;
        if(tmpx=='-'){
            x*=-1;
        }
        if(tmpy=='-'){
            y*=-1;
        }
        sigma.push_back(make_pair(x,y));
    }
    vector<char> output = confine(sigma);

    if(possible) {
        for (auto itr: output) {
            cout << itr << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}