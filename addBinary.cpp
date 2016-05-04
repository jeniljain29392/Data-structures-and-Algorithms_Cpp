class Solution {
private:
    void padding(string &s, int n){
        for(int i = 0; i < n; i++){
            s.insert(0, "0");
        }
    }

public:
    string addBinary(string a, string b) {
        string res = "", temp = "";
        int n = a.size(), m = b.size();
        int digit_a = 0, digit_b = 0, carry = 0;
        
        if(n > m) padding(b, n - m);
        else padding(a, m - n);
        
        for(int i = a.size()-1; i >= 0; i--){
            digit_a = a[i]-'0';
            digit_b = b[i]-'0';
            temp  = (digit_a ^ digit_b ^ carry) ? "1":"0";
            carry = (digit_a & digit_b) || 
                    ((digit_a ^ digit_b) & carry) ? 1:0;
            res.insert(0, temp);
        }
        if(carry) res.insert(0, "1");
        return res;
    }
};
