// Console_Constru_BT_from_In_Post.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>

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
    TreeNode *buildSubTree(vector<int> &inorder, vector<int> &postorder){
        if (postorder.size() == 0)
        {
            return NULL;
        }

        if (inorder.size() == 0)
        {
            return NULL;
        }
        
        int cur_val = postorder[postorder.size()-1];
        auto cur_iter = find(inorder.begin(), inorder.end(), cur_val);
        if (cur_iter == inorder.end())
        {
            return NULL;
        }

        TreeNode *root = new TreeNode;
        root->val = cur_val;
        postorder.erase(postorder.end()-1);

        vector<int> left_inorder_vec(inorder.begin(), cur_iter);
        vector<int> right_inorder_vec(cur_iter+1, inorder.end());

        root->right =  buildSubTree(right_inorder_vec, postorder);
        root->left = buildSubTree(left_inorder_vec, postorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildSubTree(inorder, postorder);
    }
};

int main()
{
    std::cout << "Hello LeetCode - Construct Binary Tree From Inorder and Postorder Traversal, Structure and Algorithm(Divide and Conquer, Binary Tree, Hash Table)!\n";
    cout << "https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]\n");
    printf("expected result: output = [3,9,20,null,null,15,7]\n");
    {
        TreeNode *tn15 = new TreeNode(15, NULL, NULL);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn20 = new TreeNode(20, tn15, tn7);
        TreeNode *tn9 = new TreeNode(9, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn9, tn20);
        TreeNode *root = tn3;

        vector<int> inorder = {9,3,15,20,7};
        vector<int> postorder = {9,15,7,20,3};
        
        Solution solution;
        auto res = solution.buildTree(inorder, postorder);
        dbg_BT_node(res);
        
        
        delete tn15;
        delete tn7;
        delete tn20;
        delete tn9;
        delete tn3;
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
