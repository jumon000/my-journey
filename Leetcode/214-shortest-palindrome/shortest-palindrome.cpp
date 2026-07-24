

class Solution {
public:
    string shortestPalindrome(string s) {
        const long long MOD = 1000000007;
        const long long BASE = 131;

        long long forwardHash = 0;
        long long reverseHash = 0;
        long long power = 1;

        int longest = 0;

        for (int i = 0; i < s.size(); i++) {
            int val = s[i];

            forwardHash = (forwardHash * BASE + val) % MOD;

            reverseHash = (reverseHash + val * power) % MOD;

            if (forwardHash == reverseHash) {
                longest = i + 1;
            }

            power = (power * BASE) % MOD;
        }

        string suffix = s.substr(longest);

        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }
};