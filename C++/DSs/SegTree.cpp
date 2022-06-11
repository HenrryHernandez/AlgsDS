//left child = 2i + 1;
//right child = 2i + 2
//parent = (i - 1) / 2

struct SegTree {
    int N;
    vector<int> tree;
    vector<int> input;
    
    SegTree(vector<int> input) {
        N = input.size() * 4;
        this->input = input;
        tree.resize(N);
    }
    
    void buildMinTree(vector<int>& input, int l, int r, int pos) {
        if(l == r) {
            tree[pos] = input[l];
            return;
        }
        
        int mid = (l + r) / 2;
        
        buildMinTree(input, l, mid, pos * 2 + 1);
        buildMinTree(input, mid + 1, r, pos * 2 + 2);
        tree[pos] = min(tree[pos * 2 + 1], tree[pos * 2 + 2]);
    }
    
    void buildMaxTree(vector<int>& input, int l, int r, int pos) {
        if(l == r) {
            tree[pos] = input[l];
            return;
        }
        
        int mid = (l + r) / 2;
        
        buildMaxTree(input, l, mid, pos * 2 + 1);
        buildMaxTree(input, mid + 1, r, pos * 2 + 2);
        tree[pos] = max(tree[pos * 2 + 1], tree[pos * 2 + 2]);
    }
    
    void buildSumTree(vector<int>& input, int l, int r, int pos) {
        if(l == r) {
            tree[pos] = input[l];
            return;
        }
        
        int mid = (l + r) / 2;
        
        buildSumTree(input, l, mid, pos * 2 + 1);
        buildSumTree(input, mid + 1, r, pos * 2 + 2);
        tree[pos] = tree[pos * 2 + 1] + tree[pos * 2 + 2];
    }
    
    int getSum(int l, int r, int lr, int rr, int pos) {
        if(l >= lr && r <= rr) return tree[pos];
        else if(l > rr || r < lr) return 0;
        
        int mid = (l + r) / 2;
        
        int left = getSum(l, mid, lr, mid, pos * 2 + 1);
        int right = getSum(mid + 1, r, mid + 1, rr, pos * 2 + 2);
        
        return left + right;
    }
    
    int getRangeSum(int lr, int rr) {
        assert(lr >= 0 && rr < input.size());
        return getSum(0,input.size()-1,lr,rr,0);
    }
    
    void printTree() {
        for(int node : tree) cout << node << " ";
        cout << endl;
    }
};

int main() {
    vector<int> input = {-1,0,3,6};    
    
    SegTree segTree = SegTree(input);
    segTree.buildSumTree(input, 0, 3, 0);
    segTree.printTree();
    cout << segTree.getRangeSum(0, 3);
    
}
