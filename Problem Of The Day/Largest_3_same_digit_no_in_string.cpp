class Solution {
public:
    string largestGoodInteger(string num) {
      string ans = "";
        int n = num.length();

        for (int i = 0; i + 2 < n; i++) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                string temp = string(3, num[i]); // repeat the digit 3 times
                if (ans == "" || temp > ans) {
                    ans = temp;
                }
            }
        }

        return ans;
    }
};