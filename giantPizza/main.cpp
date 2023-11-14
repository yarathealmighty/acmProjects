//https://cses.fi/problemset/task/1684
#include <bits/stdc++.h>
#define endl "\n"
#define Clause pair<int,int>

using namespace std;

vector<Clause> sigmaO;

vector<int> confine(vector<Clause> sigma){
    vector<int> output;
    vector<Clause> newSigma;
    int l;
    if(sigma[0].first==0){
        l=sigma[0].second;
    } else {
        l = sigma[0].first;
    }
    output.push_back(l);
    for(auto itr: sigma){
        Clause newClause = itr;
        //take out the clause from the sigma
        if(l==itr.first || l==itr.second){
            continue;
        }
        //take out the number from the clause
        if(l*-1==itr.first){
            newClause.first=0;
            newClause.second=itr.second;
        } else {
            if(l*-1==itr.second){
                newClause.first=itr.first;
                newClause.second=0;
            }
        }
        //take clause out entirely if it's empty
        //todo this indicates impossibility
        if(newClause.first==0 && newClause.second==0){
            continue;
        }
        newSigma.push_back(newClause);
    }

    //repeat until sigma is empty
    if(!newSigma.empty()){
        vector<int> newAdd = confine(newSigma);
        for(int i=0;i<newAdd.size();i++){
            output.push_back(newAdd[i]);
        }
    }
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
        sigmaO.push_back(make_pair(x,y));
    }
    vector<int> output = confine(sigmaO);

    if(possible) {
        int counter=0;
        for(int i=1;i<=m;i++){
            if(i==counter){
                if(output[i]>0){
                    cout << "+ ";
                } else {
                    cout << "- ";
                }
                counter++;
            } else {
                cout << "+ ";
            }
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}