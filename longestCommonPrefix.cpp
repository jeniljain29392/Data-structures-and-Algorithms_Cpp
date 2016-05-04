class Solution {
private:
    string commonPrefix(string str1, string str2){
        string res;
        int i = 0;
        while(i < str1.size() && i < str2.size()){
            if(str1[i] == str2[i]) res += str1[i++];
            else break;
        }
        return res;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0) return res;
        if(strs.size() == 1) return strs[0];
        res = commonPrefix(strs[0], strs[1]);
        for(int i = 2; i < strs.size(); i++){
            if(res != "") res = commonPrefix(strs[i], res);
            else return "";
        }
        return res;
    }
};
