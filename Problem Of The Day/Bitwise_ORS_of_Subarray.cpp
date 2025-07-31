//Brute Force
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        set<int>ans;
        for(int i=0;i<n;i++){
            int orr=0;
            for(int j=i;j<n;j++){
                orr=orr|arr[j];
                ans.insert(orr);
            }
        }
        return ans.size();
    }
};

// Optimal Solution

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
       unordered_set<int>curr;
       unordered_set<int>ans;
       for(int num:arr){
        unordered_set<int>next;
        next.insert(num);
        for(int val:curr){
            next.insert(val|num);
        }
        curr=next;
        for(auto it:curr){
            ans.insert(it);
        }
       }
       return ans.size();

    }
};