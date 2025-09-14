#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to mask vowels into '*'
    string maskVowels(const string &word) {
        string res = word;
        for (char &c : res) {
            if (isVowel(c)) c = '*';
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactSet(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitiveMap;
        unordered_map<string, string> vowelMap;

        for (string w : wordlist) {
            string lowerW = toLower(w);

            if (caseInsensitiveMap.find(lowerW) == caseInsensitiveMap.end())
                caseInsensitiveMap[lowerW] = w;

            string masked = maskVowels(lowerW);
            if (vowelMap.find(masked) == vowelMap.end())
                vowelMap[masked] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exactSet.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lowerQ = toLower(q);
            if (caseInsensitiveMap.find(lowerQ) != caseInsensitiveMap.end()) {
                ans.push_back(caseInsensitiveMap[lowerQ]);
                continue;
            }

            string maskedQ = maskVowels(lowerQ);
            if (vowelMap.find(maskedQ) != vowelMap.end()) {
                ans.push_back(vowelMap[maskedQ]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }

private:
    static bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    static string toLower(const string &s) {
        string res = s;
        for (char &c : res) c = tolower(c);
        return res;
    }
};
