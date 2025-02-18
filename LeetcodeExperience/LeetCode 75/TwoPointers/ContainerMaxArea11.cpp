#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;

    vector<int> container(r + 1, 0);

    int num = 0;

    while(l != r){
        if(height[l] >= height[r]){
            num = height[r] * (r - l);
            container[r] = num;
            r--;
        }else{
            num = height[l] * (r - l);
            container[l] = num;
            l++;
        }
    }

    return *max_element(container.begin(), container.end());
}

int main(){
    vector<int> nums = {1,8,6,2,5,4,8,3,7};

    cout<<maxArea(nums);
}