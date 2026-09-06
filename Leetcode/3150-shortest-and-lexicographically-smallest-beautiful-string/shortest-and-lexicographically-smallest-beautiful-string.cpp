class Solution {
public:
    using ll = long long;

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                pos.push_back(i);
        }

        if ((int)pos.size() < k)
            return "";

        int len = INT_MAX;

        for (int i = 0; i + k - 1 < (int)pos.size(); i++) {
            int curLen = pos[i + k - 1] - pos[i] + 1;
            len = min(len, curLen);
        }

        const ll MOD = 1'000'000'007LL;
        const ll BASE = 911382323LL;

        vector<ll> h(n + 1, 0);
        vector<ll> power(n + 1, 1);

        for (int i = 0; i < n; i++) {
            int val = s[i] - '0' + 1;
            h[i + 1] = (h[i] * BASE + val) % MOD;
            power[i + 1] = (power[i] * BASE) % MOD;
        }

        auto getHash = [&](int l, int r) -> ll {
            return (h[r] -
                    h[l] * power[r - l] % MOD +
                    MOD) % MOD;
        };

        auto isSmaller = [&](int a, int b) -> bool {
            int lo = 0, hi = len;

            while (lo < hi) {
                int mid = lo + (hi - lo + 1) / 2;

                if (getHash(a, a + mid) ==
                    getHash(b, b + mid)) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }

            int lcp = lo;

            if (lcp == len)
                return false;

            return s[a + lcp] < s[b + lcp];
        };

        int ones = 0;

        for (int i = 0; i < len; i++) {
            if (s[i] == '1')
                ones++;
        }

        int best = -1;

        for (int left = 0; left + len <= n; left++) {
            if (ones == k) {
                if (best == -1)
                    best = left;
                else if (isSmaller(left, best))
                    best = left;
            }

            if (left + len < n) {
                if (s[left] == '1')
                    ones--;

                if (s[left + len] == '1')
                    ones++;
            }
        }

        return s.substr(best, len);
    }
};