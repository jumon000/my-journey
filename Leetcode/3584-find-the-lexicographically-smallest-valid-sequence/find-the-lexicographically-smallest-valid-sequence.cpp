class Solution {
public:

    vector<vector<int>> pos;

    int getLast(int c, int limit) {

        auto &v = pos[c];

        auto it = lower_bound(v.begin(), v.end(), limit);

        if (it == v.begin())
            return -1;

        --it;
        return *it;
    }

    int getLastDifferent(int c, int limit) {

        int ans = -1;

        for (int x = 0; x < 26; x++) {

            if (x == c)
                continue;

            int idx = getLast(x, limit);

            ans = max(ans, idx);
        }

        return ans;
    }

    int getFirst(int c, int prev) {

        auto &v = pos[c];

        auto it = upper_bound(v.begin(), v.end(), prev);

        if (it == v.end())
            return -1;

        return *it;
    }

    int getFirstDifferent(int c, int prev) {

        int ans = INT_MAX;

        for (int x = 0; x < 26; x++) {

            if (x == c)
                continue;

            int idx = getFirst(x, prev);

            if (idx != -1)
                ans = min(ans, idx);
        }

        return ans == INT_MAX ? -1 : ans;
    }

public:

    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        pos.assign(26, {});

      

        for (int i = 0; i < n; i++) {
            pos[word1[i] - 'a'].push_back(i);
        }

       

        vector<int> suf0(m + 1, -1);
        vector<int> suf1(m + 1, -1);

        suf0[m] = n;
        suf1[m] = n;


        for (int j = m - 1; j >= 0; j--) {

            int c = word2[j] - 'a';

            suf0[j] = getLast(c, suf0[j + 1]);
        }


        for (int j = m - 1; j >= 0; j--) {

            int c = word2[j] - 'a';

            int exact = getLast(c, suf1[j + 1]);


            int mismatch =
                getLastDifferent(c, suf0[j + 1]);

            suf1[j] = max(exact, mismatch);
        }


        if (suf1[0] == -1)
            return {};


        vector<int> ans;

        int prev = -1;
        bool usedMismatch = false;

        for (int j = 0; j < m; j++) {

            int c = word2[j] - 'a';

            int best = INT_MAX;
            bool bestIsMismatch = false;

        

            int exact = getFirst(c, prev);

            if (exact != -1) {

                int limit;

                if (usedMismatch)
                    limit = suf0[j + 1];
                else
                    limit = suf1[j + 1];

                if (exact < limit) {

                    best = exact;
                    bestIsMismatch = false;
                }
            }


            if (!usedMismatch) {

                int mismatch = getFirstDifferent(c, prev);

                if (mismatch != -1) {

                    int limit = suf0[j + 1];

                    if (mismatch < limit) {

                        if (mismatch < best) {
                            best = mismatch;
                            bestIsMismatch = true;
                        }
                    }
                }
            }

            if (best == INT_MAX)
                return {};

            ans.push_back(best);

            prev = best;

            if (bestIsMismatch)
                usedMismatch = true;
        }

        return ans;
    }
};