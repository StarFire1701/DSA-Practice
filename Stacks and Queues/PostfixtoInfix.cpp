#include<bits/stdc++.h>
using namespace std;
int main(){
    string postfix = "ABC*DE/-FGH*+^+I-";
    string ans = postfix_to_infix(postfix);
    cout << ans;
}
string postfix_to_infix(string s){
    
    stack<string>st;
    int n= s.size();
    string top1;
    string top2;
    for(int i=0;i<n;i++){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        } else{
            top1 = st.top();
            st.pop();
            top2= st.top();
            st.pop();
            st.push("("+ top2 + s[i] + top1 + ")");  
        }
}
return st.top();

}