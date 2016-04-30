class Solution {
public:
    int titleToNumber(string s) {
        if(s.size() == 0)
            return 0;
        int column = 0;
        for(int i = 0; i < s.size(); i++){
            column = column*26 + (int)s[i] - 64;
        }
        return column;
    }
};
