// ConsoleApp_Merge_Two_BinaryTrees.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
 
class Solution {
private:
    TreeNode* DFS(TreeNode *root1, TreeNode *root2){
        if (root1 == NULL && root2 == NULL)
        {
            return NULL;
        }
        
        auto cur_root_1_val = 0;
        TreeNode *cur_root_1_left = NULL;
        TreeNode *cur_root_1_right = NULL;
        auto cur_root_2_val = 0;
        TreeNode *cur_root_2_left = NULL;
        TreeNode *cur_root_2_right = NULL;

        if (root1)
        {
            cur_root_1_val = root1->val;
            cur_root_1_left = root1->left;
            cur_root_1_right = root1->right;
        }
        if (root2)
        {
            cur_root_2_val = root2->val;
            cur_root_2_left = root2->left;
            cur_root_2_right = root2->right;
        }
        
        TreeNode *cur_root = new TreeNode(cur_root_1_val + cur_root_2_val);
        
        cur_root->left = DFS(cur_root_1_left, cur_root_2_left);
        cur_root->right = DFS(cur_root_1_right, cur_root_2_right);

        return cur_root;
    }
    
public:
    

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // solution 0 (keven, using DFS to solve)
        {
            return DFS(root1, root2);
        }
    }
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

int main()
{
    std::cout << "Hello LeetCode - Merge Two BinaryTrees, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/merge-two-binary-trees/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]\n");
    printf("expected result: output = [3,4,5,5,4,null,7]\n");
    {
        TreeNode *tn5 = new TreeNode(5, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn5, NULL);
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn3, tn2);
        TreeNode *root1 = tn1;

        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn1_1 = new TreeNode(1, NULL, tn4);
        TreeNode *tn3_1 = new TreeNode(3, NULL, tn7);
        TreeNode *tn2_1 = new TreeNode(2, tn1_1, tn3_1);
        TreeNode *root2 = tn2_1;
        
        Solution solution;
        dbg_BT_node(root1);
        dbg_BT_node(root2);
        auto result = solution.mergeTrees(root1, root2);
        dbg_BT_node(result);
        
        delete tn1;
        delete tn2;
        delete tn3;
        delete tn5;

        delete tn4;
        delete tn7;
        delete tn1_1;
        delete tn3_1;
        delete tn2_1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root1 = [1], root2 = [1,2]\n");
    printf("expected result: output = [2,2]\n");
    {
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *root1 = tn1;

        TreeNode *tn2_1 = new TreeNode(2, NULL, NULL);
        TreeNode *tn1_1 = new TreeNode(1, tn2_1, NULL);
        TreeNode *root2 = tn1_1;
        
        Solution solution;
        dbg_BT_node(root1);
        dbg_BT_node(root2);
        auto result = solution.mergeTrees(root1, root2);
        dbg_BT_node(result);
        
        delete tn1;

        delete tn1_1;
        delete tn2_1;
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
