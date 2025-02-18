#include<iostream>

using namespace std;


string mergeAlternately(string word1, string word2) {
    string merged = "";
    for(int i = 0, j = 0; i < word1.size() || j < word2.size(); i++, j++){
        if(i < word1.size()){
            merged += word1[i];
        }
        if(j < word2.size()){
            merged += word2[j];
        }
    }

    return merged;

}

int main(){
    string w1 = "ab";
    string w2 = "def";

    cout<<mergeAlternately(w1,w2);
}