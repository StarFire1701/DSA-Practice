// Brute Force
class Solution{
    public:

    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
      //  your code goes here
      
        int maxcnt=0;
        int n=Arrival.size();
        for(int i=0;i<n;i++){
              int cnt=1;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(Arrival[j]<=Departure[i] && Arrival[i]<=Departure[j]){
                    cnt+=1;
                }
            }
            maxcnt=max(maxcnt,cnt);
        }
        return maxcnt;

        
    }
};

//Better Solution


class Solution{
    public:
    bool static comparator(pair<int, char> p1, pair<int, char> p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
     return p1.second > p2.second;  // 'D' before 'A' if same time
}

    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here
      

        int n=Arrival.size();
        vector<pair<int,char>>res;
        for(int i=0;i<n;i++){
            res.push_back({Arrival[i],'A'});
        }
        for(int i=0;i<n;i++){
            res.push_back({Departure[i],'D'});
        }

        sort(res.begin(),res.end(),comparator);
        int cnt=0;
        int maxcnt=0;
        n=res.size();
        for(int i=0;i<n;i++){
             if(res[i].second=='A'){
                cnt+=1;
            }
            else  if(res[i].second=='D'){
                cnt-=1;
            }
            maxcnt=max(maxcnt,cnt);
        }
        return maxcnt;


    }
};


//Optimal Solution

class Solution{
public:

    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
         int n=Arrival.size();
        sort(Arrival.begin(),Arrival.end());
        sort(Departure.begin(),Departure.end());
        int i=0;
        int j=0;
        int cnt=0;
        int maxplatform=0;
        while(i<n){
            if(Arrival[i]<Departure[j]){
                cnt+=1;
                i++;
            } else if(Departure[j]<Arrival[i]){
                cnt-=1;
                j++;
            }
            maxplatform=max(maxplatform,cnt);
        }
        return maxplatform;



    }
};


       