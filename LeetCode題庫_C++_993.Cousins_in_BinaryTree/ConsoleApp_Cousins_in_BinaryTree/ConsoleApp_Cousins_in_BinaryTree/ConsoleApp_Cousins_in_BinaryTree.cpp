// ConsoleApp_Cousins_in_BinaryTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
 
class Solution {
private:
    bool BFS_BT(TreeNode* root, int &x, int &y){
        
        if (root == NULL) return false;
        
        queue<TreeNode*> tmp_tn_que;
        queue<TreeNode*> cur_tn_que;

        tmp_tn_que.push(root);
        while (tmp_tn_que.size())
        {
            cur_tn_que.swap(tmp_tn_que);
            bool Exist_x_fg = false;
            bool Exist_y_fg = false;
            while (cur_tn_que.size())
            {
                bool same_parent_x_exist_fg = false;
                bool same_parent_y_exist_fg = false;

                auto cur_tn = cur_tn_que.front();
                
                if (cur_tn->left){
                    if (cur_tn->left->val == x){
                        same_parent_x_exist_fg = true;
                        Exist_x_fg = true;
                    }
                    if (cur_tn->left->val == y){
                        same_parent_y_exist_fg = true;
                        Exist_y_fg = true;
                    }
                    
                    tmp_tn_que.push(cur_tn->left);
                }
                if (cur_tn->right){
                    if (cur_tn->right->val == x){
                        same_parent_x_exist_fg = true;
                        Exist_x_fg = true;
                    }
                    if (cur_tn->right->val == y){
                        same_parent_y_exist_fg = true;
                        Exist_y_fg = true;
                    }

                    tmp_tn_que.push(cur_tn->right);
                }

                if (same_parent_x_exist_fg && same_parent_y_exist_fg)
                {
                    return false;   // must different parent, so this is not matched required
                }
                

                cur_tn_que.pop();
            }
            

            if (Exist_x_fg && Exist_y_fg){
                return true;   
            }
        }

        return false;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        // solution 1 (using BFS to solve it)
        {
            return BFS_BT(root, x, y);
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Cousins in BinaryTree, Algorithm(Depth-First Search, Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/cousins-in-binary-tree/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,2,3,4], x = 4, y = 3\n");
    printf("expected result: output = false\n");
    {
        
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn4, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *root = tn1;
        int x = 4;
        int y = 3;
        
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        Solution solution;
        auto res = solution.isCousins(root, x, y);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        if (tn1)
            delete tn1;
        if (tn2)
            delete tn2;
        if (tn3)
            delete tn3;
        if (tn4)
            delete tn4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [1,2,3,null,4,null,5], x = 5, y = 4\n");
    printf("expected result: output = true\n");
    {
        
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, NULL, tn4);
        TreeNode *tn5 = new TreeNode(5, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, tn5);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *root = tn1;
        int x = 5;
        int y = 4;
        
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        Solution solution;
        auto res = solution.isCousins(root, x, y);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
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
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [1,2,3,null,4], x = 2, y = 3\n");
    printf("expected result: output = false\n");
    {
        
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, NULL, tn4);
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *root = tn1;
        int x = 2;
        int y = 3;
        
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        Solution solution;
        auto res = solution.isCousins(root, x, y);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        if (tn1)
            delete tn1;
        if (tn2)
            delete tn2;
        if (tn3)
            delete tn3;
        if (tn4)
            delete tn4;
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
