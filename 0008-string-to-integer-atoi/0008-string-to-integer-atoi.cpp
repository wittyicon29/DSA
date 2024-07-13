class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int i = 0, sign = 1, max_int = INT_MAX, min_int = INT_MIN;

        if(s.length() == 0) {
            return 0;
        }

        while(i < s.length() && s[i] == ' ') {
            i++;
        }

        if(i < s.length() && (s[i] == '-' || s[i] == '+')) {
            if(s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            if(result > max_int / 10 || (result == max_int / 10 && digit > max_int % 10)) {
                return (sign == 1) ? max_int : min_int;
            }
            result = result * 10 + digit;
            i++;
        }
        return result * sign;
    }
};