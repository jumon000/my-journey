class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> t1;
        for (int num : nums) {
            t1.insert(num);
        }
        unordered_set<int> t2;
        for (int num : nums) {
            for (int XOR : t1) {
                t2.insert(num ^ XOR);
            }
        }
        unordered_set<int> t3;
        for (int num : nums) {
            for (int XOR : t2) {
                t3.insert(num ^ XOR);
            }
        }
        return t3.size();
    }
};