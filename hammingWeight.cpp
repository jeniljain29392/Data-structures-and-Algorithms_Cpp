class Solution {
public:
    int hammingWeight(uint32_t n) {
        int number = 0;
        for(int i = 0; i < 32; i++){
            number += (n & (1<<i)) ? 1:0;
        }
        return number;
    }
};
