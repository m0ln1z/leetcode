class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();

        auto isInteger = [&](int& i) {
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            int start = i;
            while (i < n && isdigit(s[i])) i++;
            return i > start; 
        };

       
        auto isDecimal = [&](int& i) {
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            bool hasDigits = false;

            int start = i;
            while (i < n && isdigit(s[i])) { i++; hasDigits = true; }

            if (i < n && s[i] == '.') {
                i++;
                while (i < n && isdigit(s[i])) { i++; hasDigits = true; }
            }
            return hasDigits;
        };

        int j = 0;
        if (!isDecimal(j)) return false;

        if (j < n && (s[j] == 'e' || s[j] == 'E')) {
            j++;
            if (!isInteger(j)) return false;
        }

        return j == n; 
    }
};
