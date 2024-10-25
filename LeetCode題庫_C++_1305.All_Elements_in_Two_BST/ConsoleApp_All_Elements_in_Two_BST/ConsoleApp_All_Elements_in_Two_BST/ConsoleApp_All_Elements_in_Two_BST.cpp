// ConsoleApp_All_Elements_in_Two_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
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
    vector<int> root1_vec;
    vector<int> root2_vec;
    void DFS_Inorder(TreeNode *root, vector<int> &root_vec){
        
        if (root == NULL) return;
        
        stack<TreeNode*> tn_stack;
        auto tmp_root = root;

        while (tmp_root || tn_stack.size())
        {      
            while (tmp_root)
            {
                tn_stack.push(tmp_root);
                tmp_root = tmp_root->left;
            }
            
            tmp_root = tn_stack.top();
            tn_stack.pop();
            
            root_vec.push_back(tmp_root->val);

            tmp_root = tmp_root->right;
        }
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // solution 1 (keven, use DFS(In-order) to solve)
        {
            vector<int> root1_vec;
            vector<int> root2_vec;

            DFS_Inorder(root1, root1_vec);
            DFS_Inorder(root2, root2_vec);

            // printf("root1: inoder >>> \n");
            // for (size_t i = 0; i < root1_vec.size(); i++)
            // {
            //     printf("%d,", root1_vec[i]);
            // }
            // printf("\n");

            // printf("root2: inoder >>> \n");
            // for (size_t i = 0; i < root2_vec.size(); i++)
            // {
            //     printf("%d,", root2_vec[i]);
            // }
            // printf("\n");

            vector<int> res_vec;
            int root1_idx = 0;
            int root2_idx = 0;

            // insert the min element within root1_vec & root2_vec
            while (root1_idx < root1_vec.size() && root2_idx < root2_vec.size())
            {
                if (root1_vec[root1_idx] < root2_vec[root2_idx]){
                    res_vec.push_back(root1_vec[root1_idx]);
                    root1_idx++;
                }else{
                    res_vec.push_back(root2_vec[root2_idx]);
                    root2_idx++;
                }
            }

            // insert the rest of root1_vec
            while (root1_idx < root1_vec.size())
            {
                res_vec.push_back(root1_vec[root1_idx]);
                root1_idx++;
            }

            // insert the rest of root2_vec
            while (root2_idx < root2_vec.size())
            {
                res_vec.push_back(root2_vec[root2_idx]);
                root2_idx++;
            }

            return res_vec;
        }
    }
};


int main()
{
    std::cout << "Hello LeetCode - All Elements in Two Binary Search Trees, DataStructure and Algorithm(Binary Search Tree, Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/all-elements-in-two-binary-search-trees/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root1 = [2,1,4], root2 = [1,0,3]\n");
    printf("expected result: output = [0,1,1,2,3,4]\n");
    {
        
        TreeNode *tn1_1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn4_1 = new TreeNode(4, NULL, NULL);
        TreeNode *tn2_1 = new TreeNode(2, tn1_1, tn4_1);
        TreeNode *root1 = tn2_1;
        TreeNode *tn0_2 = new TreeNode(0, NULL, NULL);
        TreeNode *tn3_2 = new TreeNode(3, NULL, NULL);
        TreeNode *tn1_2 = new TreeNode(1, tn0_2, tn3_2);
        TreeNode *root2 = tn1_2;
        
        
        printf("------ In-order Traverse (START)------\n");
        printf("root1 >>> ");
        In_order_Traverse(root1);
        printf("\n");
        printf("root2 >>> ");
        In_order_Traverse(root2);
        printf("\n------ In-order Traverse (END)------\n");

        Solution solution;
        auto res = solution.getAllElements(root1, root2);

        printf("res size is :%d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");
        
        
        if (tn1_1)
            delete tn1_1;
        if (tn4_1)
            delete tn4_1;
        if (tn2_1)
            delete tn2_1;
        if (tn0_2)
            delete tn0_2;
        if (tn3_2)
            delete tn3_2;
        if (tn1_2)
            delete tn1_2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root1 = [1,null,8], root2 = [8,1]\n");
    printf("expected result: output = [1,1,8,8]\n");
    {
        
        TreeNode *tn8_1 = new TreeNode(8, NULL, NULL);
        TreeNode *tn1_1 = new TreeNode(1, NULL, tn8_1);
        TreeNode *root1 = tn1_1;
        
        TreeNode *tn1_2 = new TreeNode(1, NULL, NULL);
        TreeNode *tn8_2 = new TreeNode(8, tn1_2, NULL);
        TreeNode *root2 = tn8_2;
        
        
        printf("------ In-order Traverse (START)------\n");
        printf("root1 >>> ");
        In_order_Traverse(root1);
        printf("\n");
        printf("root2 >>> ");
        In_order_Traverse(root2);
        printf("\n------ In-order Traverse (END)------\n");

        Solution solution;
        auto res = solution.getAllElements(root1, root2);

        printf("res size is :%d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");
        
        
        if (tn1_1)
            delete tn1_1;
        if (tn8_1)
            delete tn8_1;
        
        if (tn1_2)
            delete tn1_2;
        if (tn8_2)
            delete tn8_2;
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
