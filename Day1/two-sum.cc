#include<iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // int x,y;
    // unordered_map<int,int> mp;
    // for(int &i: nums) mp[i]++;
    // for(int &i: nums) {
    //     mp[i]--;
    //     if(mp[target-i] > 0) {
    //         x = i, y = target - i;
    //         break;
    //     }
    //     mp[i]++;
    // }

    // int i = 0, j = nums.size()-1;
    // while(i<j) {
    //     if(nums[i] == x && nums[j] == y) return {i,j};
    //     if(nums[i] != x) i++;
    //     if(nums[j] != y) j--;
    // }
    // return {};
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        int curr_num = nums[i];
        int req_num = target - curr_num;
        if(mp[req_num] > 0) {
            return  {mp[req_num] - 1, i};
        }
    }
    return {};
}

int main() {
    int n, tar;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> tar;

    vector<int> pair_idx = twoSum(arr, tar);
    for(int &i: pair_idx) cout << i << " ";
    cout << endl;

    return 0;
}