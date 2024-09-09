// ConsoleApplication_Symmetric_Tree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
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
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        // solution 1 (keven, force directly)
        {
            // judgement first (just only for root parent)
            {
                if ( (root->left != NULL) && (root->right == NULL) ){
                    return false;
                }
                if ( (root->left == NULL) && (root->right != NULL) ){
                    return false;
                }
                if ( (root->left != NULL) && (root->right != NULL) ){
                    if (root->left->val != root->right->val){
                        return false;
                    }
                }
            }
            vector<TreeNode*> tmp_tn_vec;
            tmp_tn_vec.push_back(root);

            while (tmp_tn_vec.size())
            {           
                // STEP1: judgement if symmetric 
                for (size_t i = 0; i < tmp_tn_vec.size()/2; i++)
                {
                    auto totalSize = tmp_tn_vec.size();
                    auto left_tn = tmp_tn_vec[i];
                    auto right_tn = tmp_tn_vec[totalSize-i-1];
                    // for left-node -> left child
                    {
                        if ( (left_tn->left != NULL) && (right_tn->right == NULL) ){
                            return false;
                        }
                        if ( (left_tn->left == NULL) && (right_tn->right != NULL) ){
                            return false;
                        }
                        if ( (left_tn->left != NULL) && (right_tn->right != NULL) ){
                            if (left_tn->left->val != right_tn->right->val){
                                return false;
                            }
                        }
                    }
                    // for left-node -> right child
                    {
                        if ( (left_tn->right != NULL) && (right_tn->left == NULL) ){
                            return false;
                        }
                        if ( (left_tn->right == NULL) && (right_tn->left != NULL) ){
                            return false;
                        }

                        if ( (left_tn->right != NULL) && (right_tn->left != NULL) ){
                            if (left_tn->right->val != right_tn->left->val){
                                return false;
                            }
                        }
                    }
                }
                
                // STEP2: update the tmp_tn_vec for next iteration
                vector<TreeNode*> cur_tn_vec(tmp_tn_vec);
                tmp_tn_vec.clear();
                int tn_idx = 0;
                while (tn_idx < cur_tn_vec.size())
                {
                    auto cur_tn = cur_tn_vec[tn_idx];
                    
                    if (cur_tn->left){
                        tmp_tn_vec.push_back(cur_tn->left);
                    }
                    if (cur_tn->right){
                        tmp_tn_vec.push_back(cur_tn->right);
                    }

                    tn_idx++;
                }

                // STEP3: judgement if the tmp_tn_vec is odd, if so, return directly because it's not symmetric
                if (tmp_tn_vec.size() == 1 || tmp_tn_vec.size()%2){
                    return false;   // only has odd children(no matter left-child or right-child)
                }
            }

            return true;
        } 
    }
};

int main()
{
    std::cout << "Hello LeetCode - Symmetric Tree, Algorithm(Binary Tree)!\n";
    cout << "https://leetcode.com/problems/symmetric-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,2,2,3,4,4,3]\n");
    printf("expected result: output = true\n");
    {
        TreeNode *TN3_1 = new TreeNode(3, NULL, NULL);
        TreeNode *TN4_1 = new TreeNode(4, NULL, NULL);
        TreeNode *TN2_1 = new TreeNode(2, TN3_1, TN4_1);
        TreeNode *TN4_2 = new TreeNode(4, NULL, NULL);
        TreeNode *TN3_2 = new TreeNode(3, NULL, NULL);
        TreeNode *TN2_2 = new TreeNode(2, TN4_2, TN3_2);
        TreeNode *TN1_1 = new TreeNode(1, TN2_1, TN2_2);
        TreeNode *root = TN1_1;
        
        Solution solution;
        auto res = solution.isSymmetric(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete TN1_1;
        delete TN2_1;
        delete TN2_2;
        delete TN3_1;
        delete TN3_2;
        delete TN4_1;
        delete TN4_2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [1,2,2,null,3,null,3]\n");
    printf("expected result: output = false\n");
    {
        TreeNode *TN3_1 = new TreeNode(3, NULL, NULL);
        TreeNode *TN2_1 = new TreeNode(2, NULL, TN3_1);
        TreeNode *TN3_2 = new TreeNode(3, NULL, NULL);
        TreeNode *TN2_2 = new TreeNode(2, NULL, TN3_2);
        TreeNode *TN1_1 = new TreeNode(1, TN2_1, TN2_2);
        TreeNode *root = TN1_1;
        
        Solution solution;
        auto res = solution.isSymmetric(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete TN1_1;
        delete TN2_1;
        delete TN2_2;
        delete TN3_1;
        delete TN3_2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [1,2,3]\n");
    printf("expected result: output = false\n");
    {
        TreeNode *TN2_1 = new TreeNode(2, NULL, NULL);
        TreeNode *TN3_1 = new TreeNode(3, NULL, NULL);
        TreeNode *TN1_1 = new TreeNode(1, TN2_1, TN3_1);
        TreeNode *root = TN1_1;
        
        Solution solution;
        auto res = solution.isSymmetric(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete TN1_1;
        delete TN2_1;
        delete TN3_1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: root = [7,-64,-64,-6,-90,-90,-6,88,-44,68,-65,-76,68,-44,88]\n");
    printf("expected result: output = false\n");
    {
        TreeNode *TN2_1 = new TreeNode(2, NULL, NULL);
        TreeNode *TN3_1 = new TreeNode(3, NULL, NULL);
        TreeNode *TN1_1 = new TreeNode(1, TN2_1, TN3_1);
        TreeNode *root = TN1_1;
        
        Solution solution;
        auto res = solution.isSymmetric(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete TN1_1;
        delete TN2_1;
        delete TN3_1;
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
