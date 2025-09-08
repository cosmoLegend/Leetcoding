class Solution {
public:
    bool check(int num, long long num1, long long num2, vector<long long>& powers) {
        long long checker = num1 - num * num2;
        if (checker < 0) return false;

        int cnt = 0, j = 60;  
        long long temp = checker;

        while (temp > 0) {
            for (int i = j; i >= 0; i--) {
                if (powers[i] <= temp) {
                    temp -= powers[i];
                    cnt++;
                    j = i;
                    break;
                }
            }
        }

        return cnt <= num && num <= checker;
    }

    int makeTheIntegerZero(int num1, int num2) {
        vector<long long> powers(61, 1);
        for (int i = 1; i <= 60; i++) {
            powers[i] = 2LL * powers[i - 1];
        }

        for (int num = 1; num <= 1000; num++) { 
            if (check(num, num1, num2, powers)) return num;
        }

        return -1;
    }
};
