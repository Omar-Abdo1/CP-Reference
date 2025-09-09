class SegmentTree {
public:
    SegmentTree(const std::vector<int>& data) { // data must be one based
        n = data.size() - 1; // Since data is one-based, data.size() - 1 gives the correct n
        tree.resize(2 * n + 1); // Adjust size to accommodate one-based indexing
        build(data);
    }

    void update(int pos, int value) {
        pos += n; // Convert to one-based in the tree
        tree[pos] = value;
        while (pos > 1) {
            pos /= 2;
            tree[pos] = std::max(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    int query(int left, int right) {
        left += n; // Convert to one-based in the tree
        right += n; // Convert to one-based in the tree and keep inclusive
        int res = INT_MIN;
        while (left <= right) {
            if (left % 2 == 1) {
                res = std::max(res, tree[left]);
                left++;
            }
            if (right % 2 == 0) {
                res = std::max(res, tree[right]);
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return res;
    }

private:
    int n;
    std::vector<int> tree;

    void build(const std::vector<int>& data) {
        for (int i = 1; i <= n; ++i) {
            tree[n + i] = data[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = std::max(tree[2 * i], tree[2 * i + 1]);
        }
    }
};
