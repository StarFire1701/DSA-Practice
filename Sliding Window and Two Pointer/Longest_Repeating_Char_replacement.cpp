// Brute Force

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++){
            int hasharr[26]={0};
            int maxfreq=0;
            for(int j=i;j<n;j++){
                hasharr[s[j]-'A']++;
                maxfreq=max(maxfreq,hasharr[s[j]-'A']);
                int changes=(j-i+1)-maxfreq;
                if(changes<=k){
                    maxlen=max(maxlen,(j-i+1));
                }
                  }
        }

        return maxlen;
    }
};


// Better Solution