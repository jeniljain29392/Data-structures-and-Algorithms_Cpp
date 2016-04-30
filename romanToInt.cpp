class Solution {
public:
    int letterToInt(char c){
        return (c == 'M')? 1000 : (c == 'D')? 500 : (c == 'C')? 100 :
                    (c == 'L')? 50 : (c == 'X')? 10 : (c == 'V')? 5 : 
                    (c == 'I')? 1 : 0;
    }
    int romanToInt(string s) {
        int number = 0;
        if(s.size() == 0)
            return number;
        
        number = letterToInt(s[0]);
        int curr_num = number, prev_num = 0;
        
        for(int i = 1; i < s.size(); i++){
            prev_num = curr_num;
            curr_num = letterToInt(s[i]);
            
            number += curr_num;
            if(curr_num > prev_num){
                number -= 2*prev_num;
            }
        }
        return number;
    }
};
