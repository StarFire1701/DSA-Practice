//Brute Force
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int left[n];
        int right[n];
        right[n-1]=1;
        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            } else{
                left[i]=1;
            }
        }
    
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            } else{
                right[i]=1;
            }
        }
        int sum=0
        for(int i=0;i<n;i++){
            sum+=max(left[i],right[i]);
        }
        return sum;
    }
};

//Better Solution
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int left[n];
        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            } else{
                left[i]=1;
            }
        }
        int right=1;
        int sum=max(1,left[n-1]);
        for(int i=n-2;i>=0;i--){
            int current;
            if(ratings[i]>ratings[i+1]){
                current=right+1;
            } else{
                current=1;
            }
            sum+=max(left[i],current);
            right=current;
        }
        return sum;
    }
};

// Optimal Solution
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int totalCandies = 1;  // first child gets 1
        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up;
                down = 0;
                totalCandies += 1 + up;
            } else if (ratings[i] == ratings[i - 1]) {
                up = down = peak = 0;
                totalCandies += 1;
            } else {  // ratings[i] < ratings[i - 1]
                up = 0;
                down++;
                totalCandies += down;
                if (down > peak) {
                    totalCandies += 1;
                }
            }
        }

        return totalCandies;
    }
};


