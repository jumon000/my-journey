class Solution {
public:
    string smallestPalindrome(string s) {

        map<char, int> mp;

        for (char c : s)
            mp[c]++;

        string left = "";
        char mid = '\0';

        for (auto &[ch, freq] : mp) {
            left += string(freq / 2, ch);

            if (freq % 2)
                mid = ch;
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid == '\0')
            return left + right;

        return left + string(1, mid) + right;
    }
};