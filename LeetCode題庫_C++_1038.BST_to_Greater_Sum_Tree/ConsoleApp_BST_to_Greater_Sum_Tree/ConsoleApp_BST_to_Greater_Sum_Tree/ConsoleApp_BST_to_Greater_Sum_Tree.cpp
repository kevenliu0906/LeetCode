// ConsoleApp_BST_to_Greater_Sum_Tree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>
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

void In_order_Traverse(TreeNode *root){
    // // use recursive to solve (PASS)
    // {
    //     if (root == NULL)
    //     {
    //         return;
    //     }
        
    //     In_order_Traverse(root->left);
    //     printf("%d,", root->val);
    //     In_order_Traverse(root->right);
    // }

    // use stack to solve (PASS)
    {
        stack<TreeNode*> store_tn_stack;
        TreeNode *cur_tn = root;
        
        vector<TreeNode*> res;
        while ( cur_tn || store_tn_stack.size())
        {
            // STEP1: traverse left-node first and store it
            while (cur_tn)
            {
                // if exist, push into stack
                store_tn_stack.push(cur_tn);
                cur_tn = cur_tn->left;
            }

            // STEP2: get current root value from last stored
            cur_tn = store_tn_stack.top();
            store_tn_stack.pop();
            res.push_back(cur_tn);

            // STEP3: traverse right-node secondly
            cur_tn = cur_tn->right;  
        }

        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]->val);
        }
           
    }
}
 
class Solution {
private:
    int pre_total_sum = 0;
    void DFS_Inorder_with_right_tn_first(TreeNode *root){
        
        if (root == NULL) return;
        
        DFS_Inorder_with_right_tn_first(root->right);
        // printf("%d,", root->val);
        pre_total_sum += root->val;
        root->val = pre_total_sum;
        DFS_Inorder_with_right_tn_first(root->left);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        DFS_Inorder_with_right_tn_first(root);
        // printf("\n");
        return root;    
    }
};

int main()
{
    std::cout << "Hello LeetCode - BST to Greater Sum Tree!\n";
    cout << "https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n");
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
        TreeNode *root = tn4;
        
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        dbg_BT_node(root);
        Solution solution;
        auto res = solution.bstToGst(root);

        dbg_BT_node(root);

        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(res);
        printf("\n------ In-order Traverse (END)------\n");
        
        if (tn0)
            delete tn0;
        if (tn1)
            delete tn1;
        if (tn2)
            delete tn2;
        if (tn3)
            delete tn3;
        if (tn4)
            delete tn4;
        if (tn5)
            delete tn5;
        if (tn6)
            delete tn6;
        if (tn7)
            delete tn7;
        if (tn8)
            delete tn8;
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
