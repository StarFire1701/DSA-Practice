class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
         if (numerator == 0) return "0";
        
        string result;
        
        // Sign handling
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        
        // Convert to positive long long
        long long n = llabs(numerator);
        long long d = llabs(denominator);
        
        // Integer part
        result += to_string(n / d);
        long long remainder = n % d;
        if (remainder == 0) return result;
        
        result += ".";
        
        // Map to store remainder -> position in result
        unordered_map<long long, int> mp;
        
        while (remainder) {
            if (mp.find(remainder) != mp.end()) {
                // Insert '(' at the position and append ')'
                result.insert(mp[remainder], "(");
                result += ")";
                break;
            }
            
            mp[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }
        
        return result;
    }
};