class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int number = digits.size();
        //std::reverse(digits.begin(), digits.end());
        int carry = 0;
        int sum;
        
        do{
            sum = digits[number-1] + 1;
            digits[number-1] = sum%10;
            carry = sum/10;
            if(number-1==0 && carry)
                digits.insert(digits.begin(), 0);
            else
                number--;
        }
        while(carry);
        return digits;
    }
};
