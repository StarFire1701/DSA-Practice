class Solution {
public:
    bool static comparision(vector<int>&interval1,vector<int>&interval2){
        return interval1[1] < interval2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comparision);
        int count=1;
        int lastintervalendtime=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=lastintervalendtime){
                count+=1;
                lastintervalendtime=intervals[i][1];
            }
        }
        return n-count;
        }
    };
