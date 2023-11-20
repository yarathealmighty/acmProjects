#include <bits/stdc++.h>
#define BUG

using namespace std;

typedef struct{
    int represent;
    set<int> numbers;
} Solution;

typedef struct {
    int index;
    Solution board[9][9];
}Gamestate;

Gamestate games[81];
int currentdepth=0;
int finaldepth;
bool foundAnswer=false;
bool noAnswer=false;

void debug(const string& message){
    cout << "#################### [" << message << "] ####################" << endl;
    cout << "[LOG] current depth: " << currentdepth << endl;
    for(int j=0;j<9;j++){
        if((j+1)%3==1 && j!=0){
            cout << "----------------------" << endl;
        }
        for(int k=0;k<9;k++){
            if((k+1)%3==1 && k!=0){
                cout << "| ";
            }
            if(games[currentdepth].board[j][k].numbers.size()==1) {
                cout << games[currentdepth].board[j][k].represent << " ";
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }
}

bool gridFill(Gamestate& gameState, int i2s, int i2e, int j2s, int j2e, int j, int k){
    bool didSomething=false;
    for(int i2=i2s;i2<i2e;i2++){
        for(int j2=j2s;j2<j2e;j2++){
            if(i2==j && j2 ==k){
                continue;
            } else {
                int prevSize = gameState.board[i2][j2].numbers.size();
                gameState.board[i2][j2].numbers.erase(gameState.board[j][k].represent);
                if(gameState.board[i2][j2].numbers.size()!=prevSize){
                    didSomething=true;
                }
                if(gameState.board[i2][j2].numbers.size()==1){
                    for(auto itr : gameState.board[i2][j2].numbers){
                        gameState.board[i2][j2].represent = itr;
                    }
                }
            }
        }
    }
    return didSomething;
}

Gamestate fixFill(Gamestate& gameState){
    bool didSomething=false;
    for(int j=0;j<9;j++){
        for(int k=0;k<9;k++){
            if(gameState.board[j][k].numbers.size()==1){
                for(int l=0;l<9;l++){
                    if(l==j){
                        continue;
                    } else {
                        int prevSize=gameState.board[l][k].numbers.size();
                        gameState.board[l][k].numbers.erase(gameState.board[j][k].represent);
                        if(gameState.board[l][k].numbers.size()!=prevSize){
                            didSomething=true;
                        }
                        if(gameState.board[l][k].numbers.size()==1){
                            for(auto itr : gameState.board[l][k].numbers){
                                gameState.board[l][k].represent = itr;
                            }
                        }
                    }
                }
                for(int l=0;l<9;l++){
                    if(l==k){
                        continue;
                    } else {
                        int prevSize=gameState.board[l][k].numbers.size();
                        gameState.board[j][l].numbers.erase(gameState.board[j][k].represent);
                        if(gameState.board[l][k].numbers.size()!=prevSize){
                            didSomething=true;
                        }
                        if(gameState.board[j][l].numbers.size()==1){
                            for(auto itr : gameState.board[j][l].numbers){
                                gameState.board[j][l].represent = itr;
                            }
                        }
                    }
                }
                int i2s=j-3+(j%3);
                int i2e=j+3-(j%3);
                int j2s=k-3+(k%3);
                int j2e=k+3-(k%3);
                if(j==0){
                    i2s=0;
                }
                if(k==0){
                    j2s=0;
                }
                bool filler = gridFill(gameState,i2s,i2e,j2s,j2e,j,k);
                if(!didSomething){
                    didSomething=filler;
                }
            }
        }
    }

    games[currentdepth] = gameState;
    if(didSomething){
        fixFill(games[currentdepth]);
    }
    return gameState;
}

pair<int,int> findOptimalSlot(const Gamestate& gameState){
    int min=10;
    pair<int,int> slot;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(gameState.board[i][j].numbers.size()<min && gameState.board[i][j].numbers.size()!=1){
                slot = make_pair(i,j);
            }
        }
    }
    return slot;
}

int stateChecker(Gamestate& gamestate){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(gamestate.board[i][j].numbers.size()!=1 ){
                return 0;
            }
            if(gamestate.board[i][j].numbers.empty()){
                gamestate.board[0][0].represent = -1;
                noAnswer=true;
                return -1;
            }
        }
    }
    foundAnswer=true;
    finaldepth=currentdepth;
    return 1;
}

Gamestate branch(Gamestate& gamestate){
    if(stateChecker(gamestate) == 1 || stateChecker(gamestate) == -1){
        return gamestate;
    } else {
        currentdepth++;
        Gamestate branching = gamestate;
        pair<int,int> pos = findOptimalSlot(branching);
        for(auto itr : branching.board[pos.first][pos.second].numbers){
            if(foundAnswer || noAnswer){
                break;
            }
            games[currentdepth] = branching;
            set<int> trying;
            trying.insert(itr);
            games[currentdepth].board[pos.first][pos.second].numbers = trying;
            games[currentdepth].board[pos.first][pos.second].represent = itr;
            Gamestate filled = fixFill(games[currentdepth]);
#ifdef BUG
            string phase = "phase" + to_string(currentdepth);
            debug(phase);
            cout << "[LOG]: " << itr << " was placed here: " << pos.first+1 << "," << pos.second+1 << endl;
#endif
            return branch(filled);
        }
    }
    return gamestate;
}

int main() {

    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        string input;
        cin >> input;
        Gamestate starter;
        starter.index = 0;
        set<int> allSolutions = {1,2,3,4,5,6,7,8,9};
        int index=0;

        for(int j=0;j<9;j++){
            for(int k=0;k<9;k++){
                if(input.at(index)=='.'){
                    starter.board[j][k].numbers = allSolutions;
                } else {
                    starter.board[j][k].numbers.insert(input.at(index)-48);
                    starter.board[j][k].represent = input.at(index)-48;
                }
                index++;
            }
        }

        starter = fixFill(starter);

#ifdef BUG
        debug("POSTFILL");
#endif

        branch(starter);

        currentdepth--;
        if(games[currentdepth].board[0][0].represent == -1){
            cout << "IMPOSSIBLE";
        } else {
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 9; k++) {
                    cout << games[currentdepth].board[j][k].represent;
                }
            }
        }
        cout << endl;
    }
    return 0;
}

// ..41..3.8.1....62...82..4.....3.28.9....7....7.16.8...562..17.3.3.....4.1....5...
// ..3...2...6.98..4349..31..69.7...86..4..98.....54.71.96....39.55.81...722.9.56.38
// .2.456789457.8.236689237.4...5362974274.9.6533965748...4.618397761.4.528938725.6.