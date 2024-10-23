// ConsoleApp_Trim_a_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    void DeleteTree(TreeNode *del_tn){
        if (del_tn == NULL) return;
        
        DeleteTree(del_tn->left);
        DeleteTree(del_tn->right);

        delete del_tn;
        del_tn = NULL;
    }

    TreeNode*& trimBST_withDeletion(TreeNode*& root, int &L, int &H){
        if (root == NULL) return root;
        
        // val is out of range(smaller), return the right subtree
        if (root->val < L){
            auto &target = trimBST_withDeletion(root->right, L, H);
            DeleteTree(root->left);
            delete root;
            root = NULL;
            return target;
        }

        // val is out of range(bigger), return the left subtree
        if (root->val > H){
            auto &target = trimBST_withDeletion(root->left, L, H);
            DeleteTree(root->right);
            delete root;
            root = NULL;
            return target;
        }
        
        // val is in [low, high], recursively trim left/right subtrees
        root->left = trimBST_withDeletion(root->left, L, H);
        root->right = trimBST_withDeletion(root->right, L, H);

        return root;
    }
    
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // solution 0 (reference others: https://zxi.mytechroad.com/blog/leetcode/leetcode-669-trim-a-binary-search-tree/)
        {
            // return trimBST_del(root, low, high);
            // return trimBST_withDeletion(root, low, high);
        }

        // solution 1 (keven, reference others: https://zxi.mytechroad.com/blog/leetcode/leetcode-669-trim-a-binary-search-tree/)
        {
            if (root == NULL) return NULL;
            
            // STEP1: judge if root meet in range
            {
                // val is out of range(smaller), return the right subtree
                if (root->val < low)
                    return trimBST(root->right, low, high);

                // val is out of range(bigger), return the left subtree
                if (root->val > high)
                    return trimBST(root->left, low, high);
            }
            
            // STEP2: judge if root child meet in the range
            {
                // val is in [low, high], recursively trim left/right subtrees
                root->left = trimBST(root->left, low, high);
                root->right = trimBST(root->right, low, high);
            }

            return root;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Trim a Binary Search Tree, Algorithm(Depth-First Search, Binary Search Tree)!\n";
    cout << "https://leetcode.com/problems/trim-a-binary-search-tree/" << endl;
    cout << "solution: https://zxi.mytechroad.com/blog/leetcode/leetcode-669-trim-a-binary-search-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,0,2], low = 1, high = 2\n");
    printf("expected result: output = [1,null,2]\n");
    {
        
        TreeNode *tn0 = new TreeNode(0, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn0, tn2);
        TreeNode *root = tn1;
        int low = 1;
        int high = 2;
        
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        Solution solution;
        auto res = solution.trimBST(root, low, high);

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
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3\n");
    printf("expected result: output = [3,2,null,1]\n");
    {
        
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn1, NULL);
        TreeNode *tn0 = new TreeNode(0, NULL, tn2);
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn0, tn4);
        TreeNode *root = tn3;
        int low = 1;
        int high = 3;
        
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        Solution solution;
        auto res = solution.trimBST(root, low, high);

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
