// ConsoleApplication_Balance_a_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    vector<TreeNode*> Inorder_vec;
    void DFS_Inorder(TreeNode *root){

        if (root == NULL) return;

        DFS_Inorder(root->left);
        Inorder_vec.push_back(root);
        DFS_Inorder(root->right);
    }

    TreeNode* found_tn(int left, int right){
        
        if (right < left) return NULL;

        int mid = left + (right - left) / 2;
        // printf("mid:%d, L:%d, R:%d\n", mid, left, right);

        TreeNode* &root = Inorder_vec[mid];
        root->left = NULL;   // reset
        root->right = NULL;  // reset

        root->left = found_tn(left, mid - 1);
        root->right = found_tn(mid + 1, right);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        // solution 1 (keven, using "in-order" traversal & "divide and conquer" to solve)
        {
            DFS_Inorder(root);

            TreeNode *res = found_tn(0, Inorder_vec.size() - 1);

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Balance a Binary Search Tree!\n";
    cout << "https://leetcode.com/problems/all-elements-in-two-binary-search-trees/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root1 = [1,null,2,null,3,null,4]\n");
    printf("expected result: output = [2,1,3,null,null,null,4]\n");
    {
        
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, tn4);
        TreeNode *tn2 = new TreeNode(2, NULL, tn3);
        TreeNode *tn1 = new TreeNode(1, NULL, tn2);
        TreeNode *root = tn1;
        
        
        printf("------ In-order Traverse (START)------\n");
        printf("root >>> ");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");
        dbg_BT_node(root);

        Solution solution;
        auto res = solution.balanceBST(root);

        dbg_BT_node(res);
        printf("------ In-order Traverse (START)------\n");
        printf("res >>> ");
        In_order_Traverse(res);
        printf("\n------ In-order Traverse (END)------\n");
        
        
        if (tn4)
            delete tn4;
        if (tn3)
            delete tn3;
        if (tn2)
            delete tn2;
        if (tn1)
            delete tn1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root1 = [2,1,3]\n");
    printf("expected result: output = [2,1,3]\n");
    {
        
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn1, tn3);
        TreeNode *root = tn2;
        
        
        printf("------ In-order Traverse (START)------\n");
        printf("root >>> ");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");
        dbg_BT_node(root);

        Solution solution;
        auto res = solution.balanceBST(root);

        dbg_BT_node(res);
        printf("------ In-order Traverse (START)------\n");
        printf("res >>> ");
        In_order_Traverse(res);
        printf("\n------ In-order Traverse (END)------\n");
        
        if (tn3)
            delete tn3;
        if (tn2)
            delete tn2;
        if (tn1)
            delete tn1;
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
