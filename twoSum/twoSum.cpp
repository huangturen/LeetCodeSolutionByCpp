#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    map<int, int> bridge;
    for (int i=0; i<nums.size(); i++) {
        auto iter = bridge.find(target-nums[i]);
        if (iter != bridge.end()) {
            return {iter->second, i};
        }
        bridge[nums[i]] = i;
    }
    return {};
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,7,9,11,5};

    vector<int> indexs = twoSum(nums, 9);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
