class Solution {
public:
    static bool comparator(pair<long long,long long>p1,pair<long long,long long>p2){
        double r1=(double)p1.first/p1.second;
        double r2=(double)p2.first/p2.second;
        return r1>r2;
    }
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
        long long n=val.size();
        vector<pair<long long,long long>>temp;
        for(long long i = 0;i<n;i++){
            temp.push_back({val[i],wt[i]});
        }

        sort(temp.begin(),temp.end(),comparator);
        double profit=0;
        long long i=0;
        while(capacity>0 && i<n){
            if(temp[i].second <= capacity){
                profit+=temp[i].first;
                capacity-=temp[i].second;
                i++;
            } else{
                profit+=((double)((temp[i].first)/(temp[i].second)) * capacity);
                break;
            }
        }
        return profit;
    }

};