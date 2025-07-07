class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
    
    }
    
    int next(int price) {
        int ans=1;
    
            while(!st.empty() && st.top().second<=price){
                ans+=st.top().first;
                st.pop();
            }
            st.push({ans,price});
        return ans;
    }
};

