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
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructTree(grid, 0, grid.size()-1, 0, grid.size()-1);
    }
    Node* constructTree(vector<vector<int>>& grid, int lowx, int highx, int lowy, int highy) {
        Node* rnode = new Node(0,0,nullptr,nullptr,nullptr,nullptr);
        int value = grid[lowx][lowy];
        rnode->isLeaf = true;
        rnode->val = value;
        for (int x = lowx; x <= highx; x++) {
            for (int y = lowy; y <= highy; y++) {
                if (value != grid[x][y]) {
                    rnode->isLeaf = false;
                    break;
                }                
            }
            if (!rnode->isLeaf)
                break;
        }
        if (!rnode->isLeaf && lowx != highx) {
            rnode->topLeft = constructTree(grid, lowx, (lowx + highx)/2, lowy, (lowy + highy)/2);
            rnode->topRight = constructTree(grid, lowx, (lowx + highx)/2, (lowy + highy)/2 + 1, highy);
            rnode->bottomLeft = constructTree(grid, (lowx + highx)/2 + 1, highx, lowy, (lowy + highy)/2);
            rnode->bottomRight = constructTree(grid, (lowx + highx)/2 + 1, highx, (lowy + highy)/2 + 1, highy);
        }
        return rnode;
    }
};
