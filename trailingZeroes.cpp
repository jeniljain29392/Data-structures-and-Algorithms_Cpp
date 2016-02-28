class Solution {
public:
    int trailingZeroes(int n) {
        int num = 0;
        while (n > 4){
            n /= 5;
            num += n;  
        } 
        return num;
    }
};
