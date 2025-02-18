#include<iostream>
#include<vector>

using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> res;
    int sum = 0;

    if(k > 0){
        for(int i = 0; i < n; i++){
            int sum = 0;
            for (int j = 0, l = 1; j < k; j++, l++) {
                int index = (i + l) % n;
                sum += code[index];
            }
            res.push_back(sum);
        }
    }else if(k < 0){
        k = -k; 
        for(int i = 0; i < n; i++){
            int sum = 0;
            for (int j = 0, l = 1; j < k; j++, l++) {
                int index = (i - l + n) % n;
                sum += code[index];
            }
            res.push_back(sum);
        }
    }else{
        for(int i = 0; i < n; i++){
            res.push_back(0);
        }
    }
    
    for(int i = 0; i < code.size(); i++){
        cout<<res[i]<<" ";
    }

    return res;

}

int main(){
    vector<int> code = {5,7,1,4};
    int k = 0;

    decrypt(code, k);
}