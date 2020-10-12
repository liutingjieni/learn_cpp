/*************************************************************************
	> File Name: traver_tree.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月09日 星期五 15时42分36秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traver(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    
    TreeNode* traver(vector<int>::iterator prebegin, vector<int>::iterator preend, vector<int>::iterator inbegin, vector<int>::iterator inend) {
        if (inend == inbegin) return NULL;
        auto t = new TreeNode(*prebegin);
        auto root = find(inbegin,inend,*prebegin);
        t->left = traver(prebegin + 1, prebegin + (root - inbegin ) + 1, inbegin, root);
        t->right = traver(prebegin + (root - inbegin) + 1, preend, root + 1, inend);
        return t;
    }
};

int main()
{
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};
    Solution s;
    s.buildTree(pre, in);
}
