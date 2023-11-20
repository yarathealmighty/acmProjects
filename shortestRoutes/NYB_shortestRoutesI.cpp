#include <bits/stdc++.h>
//#define BUG

using namespace std;

//egy csúcs
typedef struct{
    int index;
    long long int cost;
    map<int,long long int> neighbors;
}Node;

//maga a gráf
Node graph[100001];
priority_queue<pair<long long int,int>> pq;

void dijkstra(){
        //amíg van ellenőrizendő csúcsunk, addig megyünk
        while (!pq.empty()) {
            //kivesszük a "legfontosabb" csúcsot
            pair<long long int,int> node = pq.top();
            pq.pop();
            //megnézzük az adott csúcs szomszédjait
            for (auto itr: graph[node.second].neighbors) {
                //debug
#ifdef BUG
                cout << "[LOG] " << node.second << ": " << itr.first << " " << itr.second << endl;
#endif
                //ha optimálisabb utat találunk, átírjuk és megvizsgáljuk az adott csúcsot (ha kell újra)
                if (node.first + itr.second < graph[itr.first].cost) {
                    graph[itr.first].cost = node.first + itr.second;
                    pq.push(make_pair(graph[itr.first].cost,itr.first));
                }
            }
        }
}

int main() {
    //minimális gyorsítás
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //beolvasás
    int n,m,a,b;
    long long int c;
    cin >> n >> m;

    //minden csúcsba vezető út kvázi végtelen
    for(int i=0;i<=n;i++){
        graph[i].cost=LLONG_MAX;
    }
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        graph[a].neighbors.insert(make_pair(b,c));
    }

    //bejárás
    graph[1].cost=0;
    pq.push(make_pair(0,1));
    dijkstra();

    //kiiratás
    for(int i=1;i<=n;i++){
        cout << graph[i].cost << " ";
    }
    cout << endl;
    return 0;
}
