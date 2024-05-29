#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> numIndexMap;
    for(int i=0; i<nums.size(); i++) {
        int reqNum = target - nums[i];
        if(numIndexMap[reqNum] > 0) {
            ans.push_back(numIndexMap[reqNum]-1);
            ans.push_back(i);
        }
        numIndexMap[nums[i]] = i+1;
    }
    return ans;
}

// vector<int> twoSum(vector<int>& nums, int target) {
//     int n = nums.size();
//     unordered_map<int, int> numIndexMap;
//     for(int i=0; i<n; i++) numIndexMap[nums[i]]++;

//     int x,y;

//     for(int i=0; i<n; i++) {
//         int currNum = nums[i];
//         numIndexMap[currNum]--;
//         if(numIndexMap[target - currNum] > 0) {
//             x = currNum, y = target - currNum;
//             cout << "2::X = " << x << ", Y = " << y << endl;
//             break;
//         }
//         numIndexMap[currNum]++;
//     }

//     int n1 = -1, n2 = -1;
//     for(int i=0; i<n; i++) {
//         if(n1 == -1 && nums[i] == x) n1 = i;
//         else if(nums[i] == y && n1 != -1) n2 = i;
//     }
//     return {n1,n2};
// }

int main() {
    int n, tar;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> tar;

    vector<int> ans(2);
    ans = twoSum(arr, tar);
    cout << ans[0] << " " << ans[1];

    return 0;

}