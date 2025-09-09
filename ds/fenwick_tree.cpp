 
class FenwickTree { // indices 1-based
public:

    FenwickTree(int size) : size(size) {
        tree.resize(size + 1, 0);
    }

    // Update the value at index `index` by `value`.
    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    // Get the prefix sum up to and including index `index`.
    int query(int index) const {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    // Get the sum of elements in the range [left, right].
    int rangeQuery(int left, int right) const {
        return query(right) - query(left - 1);
    }

    // Find the index with a given cumulative frequency.
    // This method assumes that all updates are positive and is mainly used for
    // problems like finding the k-th smallest element.
    // first index has cumulativeFrequency greater than val
    int find(int cumulativeFrequency) const {
        int index = 0, bitMask = 1;
        while (bitMask <= size) bitMask <<= 1;
        for (int k = bitMask >> 1; k > 0; k >>= 1) {
            int nextIndex = index + k;
            if (nextIndex <= size && cumulativeFrequency >= tree[nextIndex]) {
                cumulativeFrequency -= tree[nextIndex];
                index = nextIndex;
            }
        }
        return index+1; 
    }

private:
    std::vector<int> tree;
    int size;
};
