#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> list, tree;
vector<int> parent, subtree_size;

void makeTree(int curNode, int p) {
    for (int node : list[curNode]) {
        if (node != p) {
            tree[curNode].push_back(node);
            parent[node] = curNode;
            makeTree(node, curNode);
        }
    }
}

void countSubtreeNodes(int curNode) {
    subtree_size[curNode] = 1;

    for (int node : tree[curNode]) {
        countSubtreeNodes(node);
        subtree_size[curNode] += subtree_size[node];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;

    parent.resize(n + 1);
    subtree_size.resize(n + 1);
    list.resize(n + 1);
    tree.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    makeTree(r, -1);
    countSubtreeNodes(r);

    while (q-- > 0) {
        int query;
        cin >> query;
        cout << subtree_size[query] << "\n";
    }

    return 0;
}
