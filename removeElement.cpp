class Solution {
public:
    int count = 0;
    int removeElement(vector<int>& nums, int val) {
        for(int i = 0, j = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[j++] = nums[i];
            }
            else
                count++;
        }
        return nums.size() - count;
    }
};
