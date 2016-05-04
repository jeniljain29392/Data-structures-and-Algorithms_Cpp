class Solution {
private:
    string runlength(string str){
        string res = "";
        int i = 0, count = 1;
        for(i = 1; i < str.size(); i++){
            if(str[i] == str[i-1]){
                count++;
            }
            else{
                res += to_string(count) + str[i-1];
                count = 1;
            }
        }
        res += to_string(count) + str[i-1];
        return res;
    }
    string _countAndSay(int n, int k, string str){
        string res = runlength(str);
        if(n == k) return res;
        else return _countAndSay(n, k+1, res);
    }
public:
    string countAndSay(int n) {
        if(n < 2) return "1";
        return _countAndSay(n, 2, "1");
    }
};
