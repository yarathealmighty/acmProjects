#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<vector<int>> mtx;
int n;

bool twoLog(int num){
    int tmp=1;
    while(tmp<=num){
        if(tmp==num){
            return true;
        } else {
            tmp*=2;
        }
    }
    return false;
}

vector<int> greedyTwos(int n){
    vector<int> v;
    int tmp=1;
    while(n>0){
        while(tmp*2<=n){
            tmp*=2;
        }
        v.push_back(tmp);
        n-=tmp;
        tmp=1;
    }
    return v;
}

void calcNext(){
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(mtx[mtx.size()-1][mtx[mtx.size()-1][i]-1]);
    }
    mtx.push_back(v);
}

vector<int> find(int n){
    //nem kell szetbontani
    if(twoLog(n)){
        cout << "[LOG]: mtx.size()-1: " << mtx.size()-1 << " log2(n): " << log2(n) << endl;
        while(mtx.size()-1<log2(n)){
            calcNext();
        }
        return mtx[log2(n)];
    }
    //szet kell bontani
    vector<int> tmp= greedyTwos(n);
    vector<int> v;
    while(mtx.size()-1<log2(tmp[0])){
        calcNext();
    }
    v=mtx[log2(tmp[0])];
    cout << "[LOG] adott 2 hatvany: " << tmp[0] << endl;
    //todo ezt megcsinalni
    cout << "-------------------" << endl;
    for(int i=1;i<tmp.size();i++){
        //todo 2^0 gáz mert 1 2 2 4 a 2 1 1 4 helyett
        cout << "[LOG] adott 2 hatvany: " << tmp[i] << endl;
        for(int j=0;j<v.size();j++){
            v[j] = mtx[log2(tmp[i])][mtx[log2(tmp[i])][j]-1];
            cout << v[j] << " ";
        }
        cout << endl << "----------------------" << endl;
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q,t,x,k;
    cin >> n >> q;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin >> t;
        v.push_back(t);
    }
    mtx.push_back(v);
    for(int i=0;i<q;i++){
        cin >> x >> k;
        vector<int> v = find(k);
        cout << v[x-1] << endl;
    }

    return 0;
}
