class Solution {
public:
    bool isVowel(char c){
        return  (c == 'a' || c == 'A') ? 1 : (c == 'e' || c == 'E') ? 1 : 
                (c == 'i' || c == 'I') ? 1 : (c == 'o' || c == 'O') ? 1 : 
                (c == 'u' || c == 'U') ? 1 : 0;
    }
    
    string reverseVowels(string s) {
        if(s.size() < 2)
            return s;
        std::deque<char> stack;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i]))
                stack.push_back(s[i]);
        }
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                s[i] = stack.back();
                stack.pop_back();
            }
        }
        return s;
    }
};
