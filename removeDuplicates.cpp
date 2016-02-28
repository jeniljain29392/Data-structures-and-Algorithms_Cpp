class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 1, j = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1])
                nums[j++] = nums[i];
            else
                count++;
        }
        return nums.size() - count;
    }
};
