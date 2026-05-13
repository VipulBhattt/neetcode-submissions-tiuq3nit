/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node*
_bottomRight) { val = _val; isLeaf = _isLeaf; topLeft = _topLeft; topRight = _topRight; bottomLeft =
_bottomLeft; bottomRight = _bottomRight;
    }
};
*/

class Solution {
   public:
    Node* build(int r, int c, int size, vector<vector<int>>& grid) {
        Node* temp;
        int f = grid[r][c];
        bool sim = true;
        for (int i = r; i < r+size; i++) {
            for (int j = c; j < c+size; j++) {
                if (grid[i][j] != f) {
                    sim = false;
                    break;
                }
                if (sim == false) break;
            }
        }
        if (sim) {
            temp = new Node(f, 1);
        } else {
            Node* lt = build(r, c, size / 2, grid);
            Node* rt = build(r, c + size / 2, size / 2, grid);
            Node* lb = build(r + size / 2, c, size / 2, grid);
            Node* rb = build(r + size / 2, c + size / 2, size / 2, grid);
            temp = new Node(f, 0, lt, rt, lb, rb);
        }
        return temp;
    }
    Node* construct(vector<vector<int>>& grid) { return build(0, 0, grid[0].size(), grid); }
};