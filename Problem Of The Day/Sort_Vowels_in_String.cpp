class Solution {
public:
    string sortVowels(string s) {
        auto isVowel = [&](char c){
            static const string v = "aeiouAEIOU";
            return v.find(c) != string::npos;
        };
        vector<char> vs;
        for (char c : s) {
            if (isVowel(c)) vs.push_back(c);
        }
        sort(vs.begin(), vs.end());
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (isVowel(s[j])) {
                s[j] = vs[i++];
            }
        }
        return s;
    }
};