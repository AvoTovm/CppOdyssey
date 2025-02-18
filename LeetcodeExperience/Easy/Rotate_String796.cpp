#include <iostream>
#include <string>

using namespace std;

bool rotateString(string s, string goal) {
        if(s.size() != goal.size() || s.empty() || goal.empty()){
            return false;
        }

        if(s == goal){
            return true;
        }

        for(int i = 0; i < s.size(); i++){
            char leftmostChar = s[0];       
            s.erase(0, 1);                
            s += leftmostChar;
            if(s == goal){
                return true;
            }
        }


        return false;


}

int main(){

    string a = "aabb";
    string c = "bkaa";

    if(rotateString(a,c)){
        cout<<"is true";
    }else{
        cout<<"is false";
    }
}