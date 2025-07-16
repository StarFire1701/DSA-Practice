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
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int left=0;
        int right=0;
        int maxlen=0;
        int maxfreq=0;
        int hasharr[26]={0};
        while(right<n){
            hasharr[s[right]-'A']++;
            maxfreq=max(maxfreq,hasharr[s[right]-'A']);
            while((right-left+1)-maxfreq > k){
                hasharr[s[left]-'A']--;
                maxfreq=0;
                for(int i=0;i<26;i++){
                    maxfreq=max(maxfreq,hasharr[i]);
                }
                left=left+1;
            }
            int changes =  (right-left+1) - maxfreq;
            if(changes<=k){
                maxlen=max(maxlen,(right-left+1));
            }
            right++;
        }
        return maxlen;
    }
};


//Optimal Solution

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int left=0;
        int right=0;
        int maxlen=0;
        int maxfreq=0;
        int hasharr[26]={0};
        while(right<n){
            hasharr[s[right]-'A']++;
            maxfreq=max(maxfreq,hasharr[s[right]-'A']);
            while((right-left+1)-maxfreq > k){
                hasharr[s[left]-'A']--;
                // maxfreq=0;
                // for(int i=0;i<26;i++){
                //     maxfreq=max(maxfreq,hasharr[i]);
                // }
                left=left+1;
            }
            int changes =  (right-left+1) - maxfreq;
            if(changes<=k){
                maxlen=max(maxlen,(right-left+1));
            }
            right++;
        }
        return maxlen;
    }
};

// Most Optimal Solution

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int left=0;
        int right=0;
        int maxlen=0;
        int maxfreq=0;
        int hasharr[26]={0};
        while(right<n){
            hasharr[s[right]-'A']++;
            maxfreq=max(maxfreq,hasharr[s[right]-'A']);
            if((right-left+1)-maxfreq > k){
                hasharr[s[left]-'A']--;
                // maxfreq=0;
                // for(int i=0;i<26;i++){
                //     maxfreq=max(maxfreq,hasharr[i]);
                // }
                left=left+1;
            }
            int changes =  (right-left+1) - maxfreq;
            if(changes<=k){
                maxlen=max(maxlen,(right-left+1));
            }
            right++;
        }
        return maxlen;
    }
};