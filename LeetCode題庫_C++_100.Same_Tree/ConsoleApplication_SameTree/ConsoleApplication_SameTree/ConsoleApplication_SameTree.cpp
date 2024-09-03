// ConsoleApplication_SameTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
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
 
class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // solution 1 (Keven, using queue to solve)
        {
            queue<TreeNode*> p_queue_num;
            queue<TreeNode*> q_queue_num;

            if (p == NULL && q == NULL){
                return true;
            }
            
            
            // STEP1: compare cur_node of TreeNode
            if (p!=NULL){
                p_queue_num.push(p);
            }
            if (q!=NULL){
                q_queue_num.push(q);
            }
            if (p_queue_num.size() != q_queue_num.size()){
                return false;
            }
            if (p_queue_num.front()->val != q_queue_num.front()->val){
                return false;
            }
            
            // STEP2: compare cur_left_node of TreeNode
            if (!isSameTree(p->left, q->left)){
                return false;
            }

            // STEP3: compare cur_right_node of TreeNode
            if (!isSameTree(p->right, q->right)){
                return false;
            }

            return true;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Same Tree, Algorithm(Tree, Binary Tree, Depth-First Search, Breath-First Search)!\n";
    cout << "https://leetcode.com/problems/same-tree" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: p=[1,2,3], q=[1,2,3]\n");
    printf("expected result: output = true\n");
    {
        TreeNode *p_tn_2 = new TreeNode(2, NULL, NULL);
        TreeNode *p_tn_3 = new TreeNode(3, NULL, NULL);
        TreeNode *p_tn_1 = new TreeNode(1, p_tn_2, p_tn_3);
        TreeNode *p = p_tn_1;

        TreeNode *q_tn_2 = new TreeNode(2, NULL, NULL);
        TreeNode *q_tn_3 = new TreeNode(3, NULL, NULL);
        TreeNode *q_tn_1 = new TreeNode(1, q_tn_2, q_tn_3);
        TreeNode *q = q_tn_1;
        
        Solution solution;
        auto res = solution.isSameTree(p, q);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete p_tn_1;
        delete p_tn_2;
        delete p_tn_3;
        delete q_tn_1;
        delete q_tn_2;
        delete q_tn_3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: p=[1,2], q=[1,null,2]\n");
    printf("expected result: output = false\n");
    {
        TreeNode *p_tn_2 = new TreeNode(2, NULL, NULL);
        TreeNode *p_tn_1 = new TreeNode(1, p_tn_2, NULL);
        TreeNode *p = p_tn_1;

        TreeNode *q_tn_2 = new TreeNode(2, NULL, NULL);
        TreeNode *q_tn_1 = new TreeNode(1, NULL, q_tn_2);
        TreeNode *q = q_tn_1;
        
        Solution solution;
        auto res = solution.isSameTree(p, q);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete p_tn_1;
        delete p_tn_2;
        delete q_tn_1;
        delete q_tn_2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: p=[1,2,1], q=[1,1,2]\n");
    printf("expected result: output = false\n");
    {
        TreeNode *p_tn_2 = new TreeNode(2, NULL, NULL);
        TreeNode *p_tn_1 = new TreeNode(1, NULL, NULL);
        TreeNode *p_tn_1_1 = new TreeNode(1, p_tn_2, p_tn_1);
        TreeNode *p = p_tn_1_1;

        TreeNode *q_tn_2 = new TreeNode(2, NULL, NULL);
        TreeNode *q_tn_1 = new TreeNode(1, NULL, NULL);
        TreeNode *q_tn_1_1 = new TreeNode(1, q_tn_1, q_tn_2);
        TreeNode *q = q_tn_1_1;
        
        Solution solution;
        auto res = solution.isSameTree(p, q);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete p_tn_1;
        delete p_tn_2;
        delete p_tn_1_1;
        delete q_tn_1;
        delete q_tn_2;
        delete q_tn_1_1;
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
