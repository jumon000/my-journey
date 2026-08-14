class Solution {
    struct Node {
        char prefChar, suffChar;
        int prefLen, suffLen, maxLen;

        Node() {
            prefChar = suffChar = '#';
            prefLen = suffLen = maxLen = 0;
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node left, Node right, int leftSize, int rightSize) {
        Node res;

        res.prefChar = left.prefChar;
        res.suffChar = right.suffChar;

        res.prefLen = left.prefLen;
        if (left.prefLen == leftSize &&
            left.prefChar == right.prefChar) {
            res.prefLen = left.prefLen + right.prefLen;
        }

        res.suffLen = right.suffLen;
        if (right.suffLen == rightSize &&
            left.suffChar == right.suffChar) {
            res.suffLen = right.suffLen + left.suffLen;
        }

        res.maxLen = max(left.maxLen, right.maxLen);

        if (left.suffChar == right.prefChar) {
            res.maxLen = max(
                res.maxLen,
                left.suffLen + right.prefLen
            );
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node].prefChar = s[l];
            seg[node].suffChar = s[l];
            seg[node].prefLen = 1;
            seg[node].suffLen = 1;
            seg[node].maxLen = 1;
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        seg[node] = merge(
            seg[2 * node],
            seg[2 * node + 1],
            mid - l + 1,
            r - mid
        );
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            s[idx] = c;

            seg[node].prefChar = c;
            seg[node].suffChar = c;
            seg[node].prefLen = 1;
            seg[node].suffLen = 1;
            seg[node].maxLen = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, r, idx, c);

        seg[node] = merge(
            seg[2 * node],
            seg[2 * node + 1],
            mid - l + 1,
            r - mid
        );
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();
        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(seg[1].maxLen);
        }

        return ans;
    }
};