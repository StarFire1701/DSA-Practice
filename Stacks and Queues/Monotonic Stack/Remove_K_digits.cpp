class Solution {
public:
    string removeKdigits(string num, int k) {
       int n=num.size();
       stack<char>st;
       for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && st.top() > num[i]){
            st.pop();
            k=k-1;
        }
        st.push(num[i]);
       }
       while(k>0){
        st.pop();
        k=k-1;
       } 
       if(st.empty()) return "0";
       string res="";
       while(!st.empty()){
        res+=st.top();
        st.pop();
        }
        // To remove the front zeroes
        
        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        if(res.size()==0) return "0";
        reverse(res.begin(),res.end());
        return res;
       
    }
};