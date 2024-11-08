// Console_Average_of_Levels_in_BT.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
private:
    vector<double> avg_levels(TreeNode *root){

        vector<double> res;
        queue<TreeNode*> tmp_tn_que;
        queue<TreeNode*> cur_tn_que;

        tmp_tn_que.push(root);
        while (tmp_tn_que.size())
        {
            cur_tn_que.swap(tmp_tn_que);

            double cur_total_sum = 0;
            double cur_avg = 0;
            int cur_tn_count = cur_tn_que.size();

            while (cur_tn_que.size())
            {
                auto cur_tn = cur_tn_que.front();

                // calc cur-level total sum HERE
                cur_total_sum += cur_tn->val;

                if (cur_tn->left){
                    tmp_tn_que.push(cur_tn->left);
                }
                if (cur_tn->right){
                    tmp_tn_que.push(cur_tn->right);
                }

                cur_tn_que.pop();
            }

            cur_avg = cur_total_sum / cur_tn_count;
            res.push_back(cur_avg);
            
        }
        
        return res;
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // solution 1 (keven, using BFS to solve)
        {
            return avg_levels(root);
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Average of Levels in BinaryTree, Algorithm(Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/average-of-levels-in-binary-tree/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [3,9,20,null,null,15,7]\n");
    printf("expected result: output = [3.00000,14.50000,11.00000]\n");
    printf("Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5,\n");
    printf("             and on level 2 is 11.\n");
    printf("             Hence return [3, 14.5, 11].\n");
    {
        TreeNode *tn15 = new TreeNode(15);
        TreeNode *tn7 = new TreeNode(7);
        TreeNode *tn20 = new TreeNode(20, tn15, tn7);
        TreeNode *tn9 = new TreeNode(9);
        TreeNode *tn3 = new TreeNode(3, tn9, tn20);
        TreeNode *root = tn3;

        Solution solution;
        auto res = solution.averageOfLevels(root);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%f,", res[i]);
        }
        printf("\n");
        

        delete tn15;
        delete tn7;
        delete tn20;
        delete tn9;
        delete tn3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [3,9,20,15,7]\n");
    printf("expected result: output = [3.00000,14.50000,11.00000]\n");
    {
        TreeNode *tn15 = new TreeNode(15);
        TreeNode *tn7 = new TreeNode(7);
        TreeNode *tn9 = new TreeNode(9, tn15, tn7);
        TreeNode *tn20 = new TreeNode(20);
        TreeNode *tn3 = new TreeNode(3, tn9, tn20);
        TreeNode *root = tn3;

        Solution solution;
        auto res = solution.averageOfLevels(root);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%f,", res[i]);
        }
        printf("\n");
        

        delete tn15;
        delete tn7;
        delete tn9;
        delete tn20;
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
