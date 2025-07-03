// Brute Force

class Solution {
public:
    vector<int>find_pse(vector<int>&heights,int n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
            }
            return ans;
    }

     vector<int>find_nse(vector<int>&heights,int n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
            }
            return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
       int n=heights.size();
       vector<int>pse=find_pse(heights,n);
       vector<int>nse=find_nse(heights,n);
       int larea=0;
       for(int i=0;i<n;i++){
        int area = heights[i]*(nse[i]-pse[i]-1);
        larea=max(area,larea);
       } 
       return larea;
    }


};
// Optimal Solution

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==0){
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[i]<heights[st.top()]){
                int top=st.top();
                st.pop();
                int pse=st.empty()?-1:st.top();
                int area=heights[top]*(i-pse-1);
                ans=max(area,ans);
        }
        st.push(i);
    }
    while(!st.empty()){
        int top = st.top();
        st.pop();
        int pse=st.empty()?-1:st.top();
        int area=heights[top]*(n-pse-1);
        ans=max(area,ans);
    }
    return ans;
    }
    
};
// This has been modified according to the required functions