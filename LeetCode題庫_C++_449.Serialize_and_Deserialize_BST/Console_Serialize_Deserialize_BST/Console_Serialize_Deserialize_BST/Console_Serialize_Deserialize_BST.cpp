// Console_Serialize_Deserialize_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *_left, TreeNode *_right) : val(x), left(_left), right(_right) {}
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

unordered_map<TreeNode*, string> base_encode_unorderedmap;
unordered_map<string, TreeNode*> base_decode_unorderedmap;

class Codec {
public:



    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string res;
        auto found_iter = base_encode_unorderedmap.find(root);
        if (found_iter == base_encode_unorderedmap.end())
        {
            auto hash_fn = base_encode_unorderedmap.hash_function();
            auto value = hash_fn(root);
            res = to_string(value);
            base_encode_unorderedmap.insert(pair<TreeNode*, string>(root, res));
            base_decode_unorderedmap.insert(pair<string, TreeNode*>(res, root));
        }else{
            res = found_iter->second;
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode * res;
        auto found_iter = base_decode_unorderedmap.find(data);
        res = found_iter->second;
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

int main()
{
    std::cout << "Hello LeetCode - Serialize and Deserialize BST, Algorithm and DataStructure(Binary Search Tree, Tree, Depth-First Search, Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/serialize-and-deserialize-bst/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [2,1,3]\n");
    printf("expected result: output = [2,1,3]\n");
    {
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn1 = new TreeNode(1);
        TreeNode *tn2 = new TreeNode(2, tn1, tn3);
        TreeNode *root = tn2;
        
        dbg_BT_node(root);
        // Your Codec object will be instantiated and called as such:
        Codec* ser = new Codec();
        Codec* deser = new Codec();
        string tree = ser->serialize(root);
        printf("serialize:%s\n", tree.c_str());
        TreeNode* ans = deser->deserialize(tree);
        printf("deserialize:\n");
        dbg_BT_node(ans);
        
        
        delete tn3;
        delete tn1;
        delete tn2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [0,1,2,3,4,null,5,6,7,null,null,8,9]\n");
    printf("expected result: output = [0,1,2,3,4,null,5,6,7,null,null,8,9]\n");
    {
        TreeNode *tn6 = new TreeNode(6);
        TreeNode *tn7 = new TreeNode(7);
        TreeNode *tn3 = new TreeNode(3, tn6, tn7);
        TreeNode *tn4 = new TreeNode(4);
        TreeNode *tn8 = new TreeNode(8);
        TreeNode *tn9 = new TreeNode(9);
        TreeNode *tn5 = new TreeNode(5, tn8, tn9);
        TreeNode *tn1 = new TreeNode(1, tn3, tn4);
        TreeNode *tn2 = new TreeNode(2, NULL, tn5);
        TreeNode *tn0 = new TreeNode(0, tn1, tn2);
        TreeNode *root = tn0;
        
        dbg_BT_node(root);
        // Your Codec object will be instantiated and called as such:
        Codec* ser = new Codec();
        Codec* deser = new Codec();
        string tree = ser->serialize(root);
        printf("serialize:%s\n", tree.c_str());
        TreeNode* ans = deser->deserialize(tree);
        printf("deserialize:\n");
        dbg_BT_node(ans);
        
        delete tn6;
        delete tn7;
        delete tn3;
        delete tn4;
        delete tn8;
        delete tn9;
        delete tn5;
        delete tn1;
        delete tn2;
        delete tn0;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = []\n");
    printf("expected result: output = []\n");
    {
        TreeNode *root = NULL;
        
        dbg_BT_node(root);
        // Your Codec object will be instantiated and called as such:
        Codec* ser = new Codec();
        Codec* deser = new Codec();
        string tree = ser->serialize(root);
        printf("serialize:%s\n", tree.c_str());
        TreeNode* ans = deser->deserialize(tree);
        printf("deserialize:\n");
        dbg_BT_node(ans);
        
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
