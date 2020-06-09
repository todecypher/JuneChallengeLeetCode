class Solution {
public:
    bool isSubsequence(string s, string t) {
        int _first = 0 ; 
        
        for(int i =0 ; i<t.length();i++){
            if(_first ==s.length()) return 1;
            if(t[i] == s[_first]) _first++;
        }
        
        return(_first ==s.length());
    }
};