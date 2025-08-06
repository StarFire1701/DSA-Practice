class Solution {
public:
struct SegmentTree {
    int n;                      // number of baskets
    vector<int> tree;           // segment tree array

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);  // allocate space for segment tree
    }

    // Build tree from basket capacities
    void build(vector<int> &baskets, int node, int start, int end) {
        if (start == end) { // Leaf node → single basket
            tree[node] = baskets[start];
            return;
        }
        int mid = (start + end) / 2;
        build(baskets, node * 2, start, mid);           // left child
        build(baskets, node * 2 + 1, mid + 1, end);     // right child
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // store max in range
    }

    // Find leftmost basket index with capacity >= fruitSize
    int findBasket(int node, int start, int end, int fruitSize) {
        // If no basket in this segment can fit the fruit
        if (tree[node] < fruitSize) return -1;

        // If this segment is just one basket (leaf)
        if (start == end) return start;

        int mid = (start + end) / 2;

        // Search in left child first (to get smallest index)
        if (tree[node * 2] >= fruitSize) {
            return findBasket(node * 2, start, mid, fruitSize);
        } else {
            return findBasket(node * 2 + 1, mid + 1, end, fruitSize);
        }
    }

    // Mark a basket as used (capacity = 0)
    void updateBasket(int node, int start, int end, int basketIndex, int newCapacity) {
        if (start == end) { // reached the basket
            tree[node] = newCapacity;
            return;
        }
        int mid = (start + end) / 2;
        if (basketIndex <= mid) {
            updateBasket(node * 2, start, mid, basketIndex, newCapacity);
        } else {
            updateBasket(node * 2 + 1, mid + 1, end, basketIndex, newCapacity);
        }
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // update parent
    }
};
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
    SegmentTree st(n);
    st.build(baskets, 1, 0, n - 1);

    int unplacedCount = 0;

    for (int fruitSize : fruits) {
        int basketIndex = st.findBasket(1, 0, n - 1, fruitSize);
        if (basketIndex == -1) {
            unplacedCount++; // no basket can hold this fruit
        } else {
            st.updateBasket(1, 0, n - 1, basketIndex, 0); // mark basket as used
        }
    }
    return unplacedCount;
    }
};