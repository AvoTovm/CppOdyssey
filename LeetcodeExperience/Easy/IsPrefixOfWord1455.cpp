#include<iostream>
#include<string>

using namespace std;

int isPrefixOfWord(string sentence, string searchWord) {
    int k = searchWord.size();
    int z = sentence.size();

    int count = 0;
    int l = 0;

    while(l < z){

        count++;
        int r = l;

        while(r < z && sentence[r] != ' '){
            r++;
        }

        if(r - l >= k && sentence.substr(l, k) == searchWord){
            return count;
        }

        l = r  + 1;
        
    }
    return -1;
}



int main(){
    string sentence = "i love eating burger";
    string searchWord = "burg";

    cout<<isPrefixOfWord(sentence, searchWord);
}