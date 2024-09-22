// Console_Second_MinNode_in_BT.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <queue>
#include <set>

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
public:
    int findSecondMinimumValue(TreeNode* root) {
        // solution 1 (keven, using hash table to solve)
        {
            set<int> DataBase_nodeval_set;
            queue<TreeNode*> tmp_tn_que;
            queue<TreeNode*> cur_tn_que;
            // bool Found = false;
            int res = -1;

            tmp_tn_que.push(root);
            while (tmp_tn_que.size())
            {
                cur_tn_que.swap(tmp_tn_que);
                while (cur_tn_que.size())
                {
                    auto cur_tn = cur_tn_que.front();
                    if (DataBase_nodeval_set.count(cur_tn->val) == 0)
                    {
                        // printf("cur_tn->val:%d\n", cur_tn->val);
                        DataBase_nodeval_set.insert(cur_tn->val);
                        // printf("DataBase size is %d\n", DataBase_nodeval_set.size());
                    }
                    
                    if (cur_tn->left){
                        tmp_tn_que.push(cur_tn->left);
                    }
                    if (cur_tn->right){
                        tmp_tn_que.push(cur_tn->right);
                    }
                    
                    cur_tn_que.pop();
                }
                
            }

            auto First_Min_element = DataBase_nodeval_set.begin();
            if (DataBase_nodeval_set.size() < 2)
            {
                return res;
            }

            // move to second minimum element
            First_Min_element++;
            
            res = *(First_Min_element);
            
            return res;
        }  
    }
};



int main()
{
    std::cout << "Hello LeetCode - Second Minimum Node in Binary Tree, Algorithm(Binary Tree, Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [2,2,5,null,null,5,7]\n");
    printf("expected result: output = 5\n");
    {
        TreeNode *tn5_1 = new TreeNode(5);
        TreeNode *tn7_1 = new TreeNode(7);
        TreeNode *tn5_2 = new TreeNode(5, tn5_1, tn7_1);
        TreeNode *tn2_1 = new TreeNode(2);
        TreeNode *tn2_2 = new TreeNode(2, tn2_1, tn5_2);
        TreeNode *root = tn2_2;

        
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.findSecondMinimumValue(root);
        printf("res is %d\n", res);
        
        
        delete tn5_1;
        delete tn7_1;
        delete tn5_2;
        delete tn2_1;
        delete tn2_2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [2,2,2]\n");
    printf("expected result: output = -1\n");
    {
        TreeNode *tn2_1 = new TreeNode(2);
        TreeNode *tn2_2 = new TreeNode(2);
        TreeNode *tn2_3 = new TreeNode(2, tn2_1, tn2_2);
        TreeNode *root = tn2_3;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.findSecondMinimumValue(root);
        printf("res is %d\n", res);
        
        delete tn2_1;
        delete tn2_2;
        delete tn2_3;
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
