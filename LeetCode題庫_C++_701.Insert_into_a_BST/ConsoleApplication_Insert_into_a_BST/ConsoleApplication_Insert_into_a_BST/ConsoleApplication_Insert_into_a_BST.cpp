// ConsoleApplication_Insert_into_a_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>
#include <vector>

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
    TreeNode *pre = NULL;
    void BFS_insertNew(TreeNode *root, int val){
        if (root == NULL)
        {
            TreeNode *ins = new TreeNode(val, NULL, NULL);
            if (pre)
            {
                if (val > pre->val){
                    pre->right = ins;
                }
                else{
                    pre->left = ins;
                }
            }
            return;
        }

        pre = root;
        
        if (val > root->val){
            BFS_insertNew(root->right, val);
        }else{
            BFS_insertNew(root->left, val);
        }
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // solution 1 (keven, using recursive to solve)
        {
            if (root == NULL)
            {
                TreeNode *new_tn = new TreeNode(val, NULL, NULL);
                root = new_tn;
                return root;
            }
            
            // STEP1: traverse all node by BFS
            TreeNode *tmp_root = root;
            BFS_insertNew(tmp_root, val);
        }

        return root;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Insert into a Binary Search Tree, DataStructure and Algorithm(Binary Search Tree, Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/insert-into-a-binary-search-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [4,2,7,1,3], val = 5\n");
    printf("expected result: output = [4,2,7,1,3,5]\n");
    {
        
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn1, tn3);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn4 = new TreeNode(4, tn2, tn7);
        TreeNode *root = tn4;
        int val = 5;
        
        Solution solution;
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        auto res = solution.insertIntoBST(root, val);

        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(res);
        printf("\n------ In-order Traverse (END)------\n");
        
        delete tn1;
        delete tn3;
        delete tn2;
        delete tn7;
        delete tn4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [], val = 2\n");
    printf("expected result: output = [2]\n");
    {
        TreeNode *root = NULL;
        int val = 2;
        
        Solution solution;
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        auto res = solution.insertIntoBST(root, val);

        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(res);
        printf("\n------ In-order Traverse (END)------\n");
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [40,20,60,10,30,50,70], val = 25\n");
    printf("expected result: output = [40,20,60,10,30,50,70,null,null,25]\n");
    {
        
        TreeNode *tn10 = new TreeNode(10, NULL, NULL);
        TreeNode *tn30 = new TreeNode(30, NULL, NULL);
        TreeNode *tn20 = new TreeNode(20, tn10, tn30);
        TreeNode *tn50 = new TreeNode(50, NULL, NULL);
        TreeNode *tn70 = new TreeNode(70, NULL, NULL);
        TreeNode *tn60 = new TreeNode(60, tn50, tn70);
        TreeNode *tn40 = new TreeNode(40, tn20, tn60);
        TreeNode *root = tn40;
        int val = 25;
        
        Solution solution;
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        auto res = solution.insertIntoBST(root, val);

        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(res);
        printf("\n------ In-order Traverse (END)------\n");
        
        delete tn10;
        delete tn30;
        delete tn20;
        delete tn50;
        delete tn70;
        delete tn60;
        delete tn40;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5\n");
    printf("expected result: output = [4,2,7,1,3,5]\n");
    {
        
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn1, tn3);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn4 = new TreeNode(4, tn2, tn7);
        TreeNode *root = tn4;
        int val = 5;
        
        Solution solution;
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        auto res = solution.insertIntoBST(root, val);

        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(res);
        printf("\n------ In-order Traverse (END)------\n");
        
        delete tn1;
        delete tn3;
        delete tn2;
        delete tn7;
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
