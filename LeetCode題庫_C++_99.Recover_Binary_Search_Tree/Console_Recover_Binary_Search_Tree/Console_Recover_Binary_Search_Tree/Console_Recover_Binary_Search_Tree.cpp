// Console_Recover_Binary_Search_Tree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <queue>
#include <stack>

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
        printf("\n---------------------------------\n");
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
    TreeNode *pre_tn = NULL;
    TreeNode *first_fail_tn = NULL;
    TreeNode *second_fail_tn = NULL;
    void Inorder_with_found_fail(TreeNode *root){
        if (root == NULL)
        {
            return;
        }
        
        Inorder_with_found_fail(root->left);
        // printf("%d,", root->val);
        if (pre_tn && pre_tn->val > root->val)
        {
            if (first_fail_tn == NULL){
                // 1st meet descend case
                first_fail_tn = pre_tn;
                second_fail_tn = root;
            }else{
                // 2nd meet descend case
                second_fail_tn = root;
            }
        }
        
        pre_tn = root;
        Inorder_with_found_fail(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // solution 1 (keven, reference others: https://leetcode.wang/leetcode-99-Recover-Binary-Search-Tree.html solutin2)
        {
            // STEP1: In-order traversal
            Inorder_with_found_fail(root);
            // if (first_fail_tn){
            //     printf("first_fail_tn->val:%d\n", first_fail_tn->val);
            // }
            // if (second_fail_tn){
            //     printf("second_fail_tn->val:%d\n", second_fail_tn->val);
            // }

            // STEP2: swap failure node
            auto tmp_val = first_fail_tn->val;
            first_fail_tn->val = second_fail_tn->val;
            second_fail_tn->val = tmp_val;

        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Recover Binary Search Tree, DataStructure and Algorithm(Binary Search Tree, DFS)!\n";
    cout << "https://leetcode.com/problems/recover-binary-search-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,3,null,null,2]\n");
    printf("expected result: output = [3,1,null,null,2]\n");
    {
        
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, tn2);
        TreeNode *tn1 = new TreeNode(1, tn3, NULL);
        TreeNode *root = tn1;
        
        Solution solution;
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");
        dbg_BT_node(root);

        solution.recoverTree(root);

        dbg_BT_node(root);
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");
        
        delete tn2;
        delete tn3;
        delete tn1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [3,1,4,null,null,2]\n");
    printf("expected result: output = [2,1,4,null,null,3]\n");
    {
        
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn4 = new TreeNode(4, tn2, NULL);
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn1, tn4);
        TreeNode *root = tn3;
        
        Solution solution;
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");
        dbg_BT_node(root);

        solution.recoverTree(root);

        dbg_BT_node(root);
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");
        
        delete tn2;
        delete tn4;
        delete tn1;
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
