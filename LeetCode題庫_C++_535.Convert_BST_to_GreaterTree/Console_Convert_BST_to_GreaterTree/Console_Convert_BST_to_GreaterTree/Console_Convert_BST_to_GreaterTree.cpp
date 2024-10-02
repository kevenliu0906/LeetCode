// Console_Convert_BST_to_GreaterTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
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
private:
    int last_root_value = 0;
    void right_root_left_traversal(TreeNode *root){
        if (root == NULL)
        {
            return;
        }
        
        right_root_left_traversal(root->right);
        last_root_value += root->val;
        root->val = last_root_value;
        // printf("cur_val:%d\n", root->val);
        right_root_left_traversal(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        last_root_value = 0;
        right_root_left_traversal(root);
        return root;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Convert BST to Greater Tree, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/convert-bst-to-greater-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: roots = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n");
    printf("expected result: output = [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]\n");
    {
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, NULL, tn3);
        TreeNode *tn0 = new TreeNode(0, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn0, tn2);

        TreeNode *tn8 = new TreeNode(8, NULL, NULL);
        TreeNode *tn7 = new TreeNode(7, NULL, tn8);
        TreeNode *tn5 = new TreeNode(5, NULL, NULL);
        TreeNode *tn6 = new TreeNode(6, tn5, tn7);
        TreeNode *tn4 = new TreeNode(4, tn1, tn6);

        TreeNode *roots = tn4;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.convertBST(roots);
        dbg_BT_node(result);
        
        delete tn3;
        delete tn2;
        delete tn0;
        delete tn1;
        delete tn8;
        delete tn7;
        delete tn5;
        delete tn6;
        delete tn4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: roots = [0,null,1]\n");
    printf("expected result: output = [1,null,1]\n");
    {
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn0 = new TreeNode(0, NULL, tn1);
        TreeNode *roots = tn0;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.convertBST(roots);
        dbg_BT_node(result);
        
        delete tn0;
        delete tn1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: roots = [1]\n");
    printf("expected result: output = [1]\n");
    {
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *roots = tn1;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.convertBST(roots);
        dbg_BT_node(result);
        
        delete tn1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: roots = []\n");
    printf("expected result: output = []\n");
    {
        TreeNode *roots = NULL;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.convertBST(roots);
        dbg_BT_node(result);
        
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
