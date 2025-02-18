#include <iostream>
#include <string>

using  std::cout;

bool isCircularSentence(std::string sentence) {
    int k = sentence.size();
    
    if(sentence[0] != sentence[k - 1]){
        return false;
    }

    char Temp1;
    char Temp2;


    for(int i = 0; i < k; i++){
        if(sentence[i] == ' '){
            Temp1 = sentence[i - 1];
            Temp2 = sentence[i + 1];
            if(Temp1 != Temp2){
                return false;
            }
        }
    }

    return true;
}


int main(){

    std::string a = "hello oni ims sanh";

    cout<<isCircularSentence(a);

}