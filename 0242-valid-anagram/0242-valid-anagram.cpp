// solve with map
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char, int> count_s;
        unordered_map<char, int> count_t;
        for (int i = 0; i < s.size(); i++) {
            count_s[s[i]]++;
            count_s[t[i]]--;
            count_t[s[i]]=0;
        }
        if(count_s==count_t)
            return true;

        return false;
        
    }
};
// --------------------
// solve with sorting
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};*/