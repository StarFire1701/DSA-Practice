class Solution{
    public:
    struct meetings{
        int start;
        int end;
        int pos;
    };
    bool static comparator(struct meetings m1,struct meetings m2){
        if (m1.end < m2.end) return true;
        else if (m1.end > m2.end) return false;
        return false;
    }
    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        int n=start.size();
        struct meetings[n];
        for(int i=0;i<n;i++){
            meetings[i].start=start[i];
            meetings[i].end=end[i];
            meetings[i].pos=i+1;
        }
        sort(meetings,meetings+n,comparator);
        int count=1;
        int  freetime=meetings[0].end;
        vector<int>ans;
        ans.push_back(meetings[0].pos);
        for(int i=1;i<n;i++){
            if(meetings[i].start > freetime){
                    count+=1;
                    ans.push_back(meetings[i].pos);
                    freetime=meetings[i].end;
            }       
             }
      return count;
    }
  
};