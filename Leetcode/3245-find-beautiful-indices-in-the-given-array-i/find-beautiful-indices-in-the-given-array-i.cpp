class Solution {
public:
    using ull = unsigned long long;
    const ull BASE = 26;

    vector<int> beautifulIndices(string s, string a, string b, int k) {

        vector<int> posA, posB;

        ull hashA = 0, hashB = 0;

        for (char c : a)
            hashA = hashA * BASE + c;

        for (char c : b)
            hashB = hashB * BASE + c;

        findOccurences(s, a, hashA, posA);

        findOccurences(s, b, hashB, posB);

        vector<int> ans;

        for (int i : posA) {

            auto it = lower_bound(posB.begin(), posB.end(), i);

            bool ok = false;

            if (it != posB.end() && abs(*it - i) <= k)
                ok = true;

            if (it != posB.begin()) {
                --it;
                if (abs(*it - i) <= k)
                    ok = true;
            }

            if (ok)
                ans.push_back(i);
        }

        return ans;
    }

    void findOccurences(string &s, string &pat, ull targetHash, vector<int> &pos) {

        int n = s.size();
        int m = pat.size();

        if (m > n)
            return;

        ull power = 1;

        for (int i = 1; i < m; i++)
            power *= BASE;

        ull hash = 0;

        for (int i = 0; i < n; i++) {

            hash = hash * BASE + s[i];

            if (i >= m)
                hash -= (ull)s[i - m] * power * BASE;

            if (i >= m - 1 && hash == targetHash) {

                if (s.substr(i - m + 1, m) == pat)
                    pos.push_back(i - m + 1);
            }
        }
    }
};