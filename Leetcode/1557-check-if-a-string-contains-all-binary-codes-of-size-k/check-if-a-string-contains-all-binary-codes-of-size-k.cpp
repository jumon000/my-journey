class Solution {
public:
    bool hasAllCodes(string s, int k) {

        unordered_set<int> st;

        for (int i = 0; i < (1 << k); i++)
            st.insert(i);

        int hash = 0;
        int base = 1 << (k - 1);

        for (int i = 0; i < s.size(); i++) {

            if (i >= k)
                hash -= (s[i - k] - '0') * base;

            hash = (hash << 1) + (s[i] - '0');

            if (i >= k - 1) {
                st.erase(hash);

                if (st.empty())
                    return true;
            }
        }

        return false;
    }
};