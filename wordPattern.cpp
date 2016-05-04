class Solution {
private:
    void split(string str, vector<string> &strArr){
        if(str.empty()) return;
        int i = 0, j = 0;
        while(i < str.size()){
            j = i;
            while(i < str.size() && str[i] != ' ') i++;
            strArr.push_back(str.substr(j, i++ - j));
        }
    }
public:
    bool wordPattern(string pattern, string str) {
        if(str.empty() || pattern.empty()) return false;
            
        vector<string> strArr;
        split(str, strArr);
        
        if(strArr.size() != pattern.size()) return false;
        
        string patArr[26] = {""};
        unordered_set<string> set;
        for(int i = 0; i < pattern.size(); i++){
            if(patArr[pattern[i] - 'a'] == ""){
                if(set.find(strArr[i]) == set.end()){
                    patArr[pattern[i] - 'a'] = strArr[i];
                    set.insert(strArr[i]);
                }
                else
                    return false;
            }
            else{
                if(patArr[pattern[i] - 'a'] != strArr[i])
                    return false;
            }
        }
        
        return true;
    }
};
