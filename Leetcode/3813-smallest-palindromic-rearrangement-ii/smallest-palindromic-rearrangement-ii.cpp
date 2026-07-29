class Solution {
public:
    using ll = long long;

    string smallestPalindrome(string s, long long k) {

        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        vector<int> half(26, 0);

        string middle = "";

        int leftLength = 0;

        for (int i = 0; i < 26; i++) {

            if (freq[i] & 1)
                middle.push_back(char(i + 'a'));

            half[i] = freq[i] / 2;
            leftLength += half[i];
        }

        auto getWays = [&](const vector<int>& cnt, ll limit) {

            ll ways = 1;
            int total = 0;

            for (int f : cnt) {

                if (f == 0)
                    continue;

                int n = total + f;
                int r = min(f, n - f);

                ll comb = 1;

                for (int i = 1; i <= r; i++) {

                    comb = comb * (n - r + i) / i;

                    if (comb > limit) {
                        comb = limit + 1;
                        break;
                    }
                }

                if (ways > limit / comb)
                    return limit + 1;

                ways *= comb;

                if (ways > limit)
                    return limit + 1;

                total = n;
            }

            return ways;
        };

        if (getWays(half, k) < k)
            return "";

        string left = "";

        while ((int)left.size() < leftLength) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                ll ways = getWays(half, k);

                if (ways >= k) {

                    left.push_back(char(c + 'a'));
                    break;
                }

                k -= ways;

                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};