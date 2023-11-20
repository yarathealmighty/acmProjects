#include <bits/stdc++.h>

using namespace std;

int n,m;
int pos=0;
vector<vector<pair<int,int>>> rooms;
vector<vector<char>> charmap;
vector<vector<bool>> visited;

void roomFinder(pair<int,int> startPos){
    pair<int,int> tempRoom;
    visited[startPos.first][startPos.second]=true;
    if(startPos.first!=0){
        if(charmap[startPos.first-1][startPos.second] =='.' && !visited[startPos.first-1][startPos.second]){
            tempRoom = make_pair(startPos.first-1,startPos.second);
            rooms[pos].push_back(tempRoom);
            roomFinder(make_pair(startPos.first-1,startPos.second));
        }
    }
    if(startPos.first!=n-1){
        if(charmap[startPos.first+1][startPos.second] =='.' && !visited[startPos.first+1][startPos.second]){
            tempRoom = make_pair(startPos.first+1,startPos.second);
            rooms[pos].push_back(tempRoom);
            roomFinder(make_pair(startPos.first+1,startPos.second));
        }
    }
    if(startPos.second!=0){
        if(charmap[startPos.first][startPos.second-1] =='.' && !visited[startPos.first][startPos.second-1]){
            tempRoom = make_pair(startPos.first,startPos.second-1);
            rooms[pos].push_back(tempRoom);
            roomFinder(make_pair(startPos.first,startPos.second-1));
        }
    }
    if(startPos.second!=m){
        if(charmap[startPos.first][startPos.second+1] =='.' && !visited[startPos.first][startPos.second+1]){
            tempRoom = make_pair(startPos.first,startPos.second+1);
            rooms[pos].push_back(tempRoom);
            roomFinder(make_pair(startPos.first,startPos.second+1));
        }
    }


}

int main() {
    char x;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        vector<char> v;
        vector<bool> v1;
        for(int j=0;j<m;j++){
            cin >> x;
            v.push_back(x);
            v1.push_back(false);
        }
        charmap.push_back(v);
        visited.push_back(v1);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(charmap[i][j]=='.'&& !visited[i][j]){
                vector<pair<int,int>> v;
                rooms.push_back(v);
                roomFinder(make_pair(i,j));
                pos++;
            }
        }
    }
    cout << pos << endl;






    return 0;
}
