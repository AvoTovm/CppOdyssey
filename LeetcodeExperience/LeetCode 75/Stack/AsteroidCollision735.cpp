#include<iostream>
#include<vector>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stack;

    for(int asteroid : asteroids){
        bool destroied = false;

        while(!stack.empty() && asteroid < 0 && stack.back() > 0){
            if(abs(stack.back()) < abs(asteroid)){
                stack.pop_back();
            }else if(abs(stack.back()) == abs(asteroid)){
                stack.pop_back();
                destroied = true;
                break;
            }else{
                destroied = true;
                break;
            }
        }

        if(!destroied){
            stack.push_back(asteroid);
        }
    }

     for(int i = 0; i < stack.size(); i++){
        cout<<stack[i]<<" ";
    }

    return stack;
}

int main(){
    vector<int> asteroids = {10,2,-5};

    asteroidCollision(asteroids);
}