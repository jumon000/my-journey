class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> div(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {

            for (int mul = d; mul <= mx; mul += d) {
                div[d] += freq[mul];
            }
        }

        vector<long long> exactgcd(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {

            exactgcd[d] = div[d] * (div[d] - 1) / 2;

            for (int mul = 2 * d; mul <= mx; mul += d) {
                exactgcd[d] -= exactgcd[mul];
            }
        }

        vector<long long> pref(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            pref[d] = pref[d - 1] + exactgcd[d];
        }

        vector<int> ans;

        for (long long k : queries) {

            int gcdValue =
                lower_bound(pref.begin() + 1, pref.end(), k + 1)
                - pref.begin();

            ans.push_back(gcdValue);
        }

        return ans;
    }
};