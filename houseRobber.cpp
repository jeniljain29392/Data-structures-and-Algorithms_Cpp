class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
            
        int amount[nums.size()];
        amount[0] = nums[0];
        amount[1] = max(nums[1], nums[0]);
        
        for(int i = 2; i < nums.size(); i++){
            amount[i] = max(amount[i-1], nums[i] + amount[i-2]);
        }
        return amount[nums.size()-1];
    }
};

