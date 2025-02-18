#include<iostream>
#include<queue>

using namespace std;

string predictPartyVictory(string senate) {
    queue<int> qR;
    queue<int> qD;

    for(int i = 0; i < senate.size(); i++){
        if(senate[i] == 'R') qR.push(i); else{
            qD.push(i);
        }
    }
    while(!qR.empty() && !qD.empty()){
        if(qR.front() < qD.front()){
            qR.push(qR.front() + senate.size());
            qR.pop();
            qD.pop();
        }else{
            qD.push(qD.front() + senate.size());
            qR.pop();
            qD.pop();
        }
    }

    if(qR.empty()){
        return "Dire";
    }else return "radiant";
}

int main(){
    string s = "DDD";

    cout<<predictPartyVictory(s);
}