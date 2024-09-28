// Con_stru_BT_From_Pre_In_Tra.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dbg_BT_node(TreeNode *root)
{

    // print by BT traversal(level-ordered traversal)
    queue<TreeNode*> nums_queue;

    printf("------- FINAL RESULT(dbg) -------\n");

    if (root == NULL)
    {
        printf("tn is NULL\n");
        return;
    }
    
    nums_queue.push(root);
    while (nums_queue.size())
    {
        auto cur_tn = nums_queue.front();
        nums_queue.pop();
        if (cur_tn == NULL){
            printf("null,");
        }else{
            printf("%d,", cur_tn->val);
            if (cur_tn->left || cur_tn->right)
            {
                nums_queue.push(cur_tn->left);
                nums_queue.push(cur_tn->right);
            }          
        }
    }
    printf("\n---------------------------------\n");
}


class Solution {
public:
    void preorder_traversal(TreeNode *root){
        if (root == NULL)
        {
            return;
        }
        
        printf("%d,", root->val);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }

    void inorder_traversal(TreeNode *root){
        if (root == NULL)
        {
            return;
        }
        
        inorder_traversal(root->left);
        printf("%d,", root->val);
        inorder_traversal(root->right);
    }

    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder){
        
        if (preorder.size() == 0)
        {
            return NULL;
        }
        
        int cur_val = preorder[0];
        auto cur_found_iter = find(inorder.begin(), inorder.end(), cur_val);
        if (cur_found_iter == inorder.end())
        {
            return NULL;
        }

        TreeNode* root = new TreeNode();
        root->val = cur_val;
        preorder.erase(preorder.begin());
        
        vector<int> left_inorder(inorder.begin(), cur_found_iter);
        vector<int> right_inorder(cur_found_iter + 1, inorder.end());

        root->left = buildSubTree(preorder, left_inorder);
        root->right = buildSubTree(preorder, right_inorder);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // solution 1 (keven, using recursive to solve)
        // reference: https://hackmd.io/@Zero871015/LeetCode-105
        {
            return buildSubTree(preorder, inorder);
        }
    }
};


int main()
{
    std::cout << "Hello LeetCode - Construct Binary Tree From Pre-order and In-order Traversal, Algorithm and DataStructure(Binary Tree, stack)!\n";
    cout << "https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/" << endl << endl;
    cout << "solution: https://hackmd.io/@Zero871015/LeetCode-105" << endl << endl;
    

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]\n");
    printf("expected result: output = [3,9,20,null,null,15,7]\n");
    {
        vector<int> preorder{3,9,20,15,7};
        vector<int> inorder{9,3,15,20,7};
        
        Solution solution;
        auto res = solution.buildTree(preorder, inorder);
        dbg_BT_node(res);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: preorder = [1,2,4,5,7,8,9,3,6], inorder = [4,2,7,5,9,8,1,6,3]\n");
    printf("expected result: output = [1,2,3,4,5,6,null,7,8,9,null]\n");
    {
        vector<int> preorder{1,2,4,5,7,8,9,3,6};
        vector<int> inorder{4,2,7,5,9,8,1,6,3};
        
        Solution solution;
        auto res = solution.buildTree(preorder, inorder);
        dbg_BT_node(res);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
