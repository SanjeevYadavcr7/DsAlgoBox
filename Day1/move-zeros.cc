#include<iostream>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;
    int n = nums.size();
    while(j < n) {
        if(nums[i] == 0 && nums[j] == 0) j++;
        else if(nums[i] != 0 && nums[j] != 0) i++, j++;
        else if(nums[i] == 0 && nums[j] != 0) {
            nums[i] = nums[j];
            nums[j] = 0;
            i++, j++;
        } 
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    moveZeroes(arr);
    for(int &i : arr) cout << i << " ";

    return 0;
}