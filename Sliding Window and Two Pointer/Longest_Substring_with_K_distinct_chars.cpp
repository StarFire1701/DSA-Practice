//Brute Force

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int n=s.length();
        int maxlen=0;
        map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp.clear();
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                if(mpp.size()>k){
                    break;
                }
                maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};


//Better Solution
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int n=s.length();
        int left=0;
        int right=0;
        int maxlen=0;
        map<char,int>mpp;
        while(right<n){
            mpp[s[right]]++;
            while(mpp.size()>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            if(mpp.size()<=k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }


        return maxlen;

    }
};


//Optimal Solution

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int n=s.length();
        int left=0;
        int right=0;
        int maxlen=0;
        map<char,int>mpp;
        while(right<n){
            mpp[s[right]]++;
            if(mpp.size()>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            if(mpp.size()<=k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }


        return maxlen;

    }
};