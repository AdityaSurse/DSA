class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Start from index 1 and add the previous element to the current one
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};