class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int k = 2; k <= n; k++) {
            string next = "";
            int count = 1;
            for (int i = 1; i <= (int)result.size(); i++) {
                if (i < result.size() && result[i] == result[i-1]) {
                    count++;
                } else {
                    next += to_string(count) + result[i-1];
                    count = 1;
                }
            }
            result = next;
        }
        
        return result;
    }
};
