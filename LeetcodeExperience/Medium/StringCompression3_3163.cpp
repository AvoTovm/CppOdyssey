#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compressedString(string word) {
    if (word.empty()) return "";

    ostringstream compressedText;
    int count = 1;

    for (int i = 0; i < word.size(); ++i) {
        if (i < word.size() - 1 && word[i] == word[i + 1]) {
            count++;
            if(count == 9){
                compressedText << count << word[i];
                count = 1;
            }
        } else {
            compressedText << count << word[i];
            count = 1;
        }
    }

    return compressedText.str();
}

int main(){
    string a = "aaaaaaaaaaaaaabb";

    cout<<compressedString(a);
}