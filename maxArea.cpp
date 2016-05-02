class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        while(left < right){
            maxWater = max(maxWater, min(height[left], height[right]) * (right - left));
            height[left] > height[right] ? right-- : left++;
        }
        return maxWater;
    }
};
