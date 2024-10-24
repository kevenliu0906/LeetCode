// Console_Constr_BST_From_Preorder.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

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
    TreeNode *res = NULL;
    vector<int> m_preorder;
    vector<int> m_inorder;
    map<int,int> m_num_idx_map;   // key: number, value: number index on m_inorder

    TreeNode* bst_construct_preorder(int leftIdx, int rightIdx){
        
        if (m_preorder.size() == 0) return NULL;
        
        if (rightIdx < leftIdx) return NULL;
        
        TreeNode *new_tn = new TreeNode(m_preorder[0]);
        m_preorder.erase(m_preorder.begin());

        new_tn->left = bst_construct_preorder(leftIdx, m_num_idx_map[new_tn->val] - 1);
        new_tn->right = bst_construct_preorder(m_num_idx_map[new_tn->val] + 1, rightIdx);

        return new_tn;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // solution 1 (keven, recursive solve it)
        {
            m_preorder = preorder;
            m_inorder = preorder;
            sort(m_inorder.begin(), m_inorder.end());
            for (size_t i = 0; i < m_inorder.size(); i++)
            {
                m_num_idx_map.insert(pair<int,int>(m_inorder[i], i));
            }
            
            res = bst_construct_preorder(0, m_inorder.size()-1);

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Construct BST From Preorder Traversal, DataStructure(Binary Search Tree)!\n";
    cout << "https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: preorder = [8,5,1,7,10,12]\n");
    printf("expected result: output = [8,5,10,1,7,null,12]\n");
    {
        vector<int> preorder{8,5,1,7,10,12};

        Solution solution;
        auto res = solution.bstFromPreorder(preorder);

        printf("res is >>>>> \n");
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(res);
        printf("\n------ In-order Traverse (END)------\n");
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: preorder = [1,3]\n");
    printf("expected result: output = [1,null,3]\n");
    {
        vector<int> preorder{1,3};

        Solution solution;
        auto res = solution.bstFromPreorder(preorder);

        printf("res is >>>>> \n");
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(res);
        printf("\n------ In-order Traverse (END)------\n");
        
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
