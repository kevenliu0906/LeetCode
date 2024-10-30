// Console_Serialize_Deserialize_BT.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

 
class Codec {
private:
    
    void DFS_preorder(TreeNode *root, string &preorder){
        if (root == NULL){
            preorder.append("#,");
            return;
        }
        
        preorder.append(/*to_string(root->val).append(",")*/to_string(root->val)+",");

        DFS_preorder(root->left, preorder);
        DFS_preorder(root->right, preorder);
    }
    
    TreeNode *decode(string &data, int &offset){
        TreeNode* res = NULL;
        auto val_pos = data.find(",", offset);
        if (val_pos != string::npos)
        {
            string tn_val;
            int tmp_start = offset;
            while (tmp_start != val_pos)
            {
                tn_val += data[tmp_start];
                tmp_start++;
            }
            // printf("tn_val:%s\n", tn_val.c_str());
            
            if (tn_val == "#")
            {
                // represent null 
                offset = val_pos;  // prepare for next search
                // data.erase(0, val_pos + 1);   // do not use erase to increase time
                // printf("tn_val_ch:%c, others data:%s\n", *tn_val_ch, data.c_str());    
                return NULL;
            }

            int cur_val = atoi(tn_val.c_str());         // use atoi is better than stoi in performance speed
            offset = val_pos;  // prepare for next search
            // data.erase(0, val_pos + 1);   // do not use erase to increase time
            // printf("cur_val:%d, others data:%s\n", cur_val, data.c_str());

            res = new TreeNode(cur_val);
            offset++;
            res->left = decode(data, offset);
            offset++;
            res->right = decode(data, offset);
        }

        return res;
    }

public:
    // reference others: https://hackmd.io/@Rance/Hk12HoqEB?type=view
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string preorder_str;

        DFS_preorder(root, preorder_str);
        
        return preorder_str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        int start_offset = 0;
        return decode(data, start_offset);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    std::cout << "Hello LeetCode - Serialize and Deserialize Binary Tree, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/serialize-and-deserialize-binary-tree/" << endl;
    cout << "solution:" << "https://hackmd.io/@Rance/Hk12HoqEB?type=view" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,2,3,null,null,4,5]\n");
    printf("expected result: output = [1,2,3,null,null,4,5]\n");
    {
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn5 = new TreeNode(5, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn4, tn5);
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *root = tn1;
        
        dbg_BT_node(root);

        Codec ser, deser;
        auto res_str = ser.serialize(root);
        printf("serialize:%s\n", res_str.c_str());

        auto res_bt = deser.deserialize(res_str);
        dbg_BT_node(res_bt);
        
        if (tn4)
            delete tn4;
        if (tn5)
            delete tn5;
        if (tn3)
            delete tn3;
        if (tn2)
            delete tn2;
        if (tn1)
            delete tn1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = []\n");
    printf("expected result: output = []\n");
    {
        TreeNode *root = NULL;
        
        dbg_BT_node(root);

        Codec ser, deser;
        auto res_str = ser.serialize(root);
        printf("serialize:%s\n", res_str.c_str());

        auto res_bt = deser.deserialize(res_str);
        dbg_BT_node(res_bt);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [1,-2,3,null,null,4,-5]\n");
    printf("expected result: output = [1,-2,3,null,null,4,5]\n");
    {
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn5 = new TreeNode(-5, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn4, tn5);
        TreeNode *tn2 = new TreeNode(-2, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *root = tn1;
        
        dbg_BT_node(root);

        Codec ser, deser;
        auto res_str = ser.serialize(root);
        printf("serialize:%s\n", res_str.c_str());

        auto res_bt = deser.deserialize(res_str);
        dbg_BT_node(res_bt);
        
        if (tn4)
            delete tn4;
        if (tn5)
            delete tn5;
        if (tn3)
            delete tn3;
        if (tn2)
            delete tn2;
        if (tn1)
            delete tn1;
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
