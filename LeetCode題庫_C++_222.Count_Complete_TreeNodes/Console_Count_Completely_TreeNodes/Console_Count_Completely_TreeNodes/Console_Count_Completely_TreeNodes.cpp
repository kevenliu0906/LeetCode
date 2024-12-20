﻿// Console_Count_Completely_TreeNodes.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;


// * Definition for a binary tree node.
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
    int Pow(int a, int b) {
        
        int result = 1;
        
        if (a == 1)
            return result;

        while (b > 0) {
            result = result * a;
            b--;
        }

        return result;
    }
    bool Check_Tree_Perfect(TreeNode *root, int &total_level_count){

        bool Perfect = false;
        int LeftLevelCount = 0;
        int RightLevelCount = 0;
        TreeNode *LeftLevel_ptr = NULL;
        TreeNode *RightLevel_ptr = NULL;

        // count the left side level 
        LeftLevel_ptr = root;
        while( LeftLevel_ptr != NULL ){
            LeftLevelCount++;
            LeftLevel_ptr = LeftLevel_ptr->left;
        }

        // count the right side level
        RightLevel_ptr = root;
        while( RightLevel_ptr != NULL ){
            RightLevelCount++;
            RightLevel_ptr = RightLevel_ptr->right;
        }

        // printf("root->val:%d, LeftLevelCount:%d, RightLevelCount:%d\n", root->val, LeftLevelCount, RightLevelCount);
        if( LeftLevelCount == RightLevelCount ){
            Perfect = true;
            total_level_count = LeftLevelCount;
        }

        return Perfect;
    }
    int countNodes(TreeNode* root) {
        
        int NodeCount = 0;
        if( root == NULL )
            return NodeCount;

        // solution 1(reference other viewpoint, best)
        // Reference: https://mocowcow.github.io/leetcode-222-count-complete-tree-nodes/
        {
            // check if the tree is perfect
            if( Check_Tree_Perfect(root, NodeCount) ){
                // printf("root->val:%d is perfect tree, NodeCount:%d, total_node_count:%d\n", root->val, NodeCount, Pow(2, NodeCount) - 1);
                return Pow(2, NodeCount) - 1;
            }
            else {
                return 1 + countNodes(root->left) + countNodes(root->right);
            }

        }

        // // solution 2 (keven, have bug)
        // {
        //     vector<TreeNode *> TreeNodes;
        //     TreeNodes.push_back(root);

        //     while(TreeNodes.size()){

        //         TreeNode* current_ptr = *(TreeNodes.begin());
                
        //         if( current_ptr->val ){
        //             // printf("current node val:%d\n", current_ptr->val);
        //             NodeCount++;
        //         }
        //         if( current_ptr->left ){
        //             TreeNodes.push_back(current_ptr->left);
        //         }
        //         if( current_ptr->right ){
        //             TreeNodes.push_back(current_ptr->right);
        //         }

        //         TreeNodes.erase(TreeNodes.begin());
        //     }


        //     return NodeCount;
        // }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Count Completely Tree Nodes, DataStructure (BinarySearch, Tree, Binary Tree)!\n";
    printf("LeetCode - 222. Count Completely Tree Nodes\n");
    cout << "https://leetcode.com/problems/count-complete-tree-nodes" << endl << endl;
    cout << "solution: https://mocowcow.github.io/leetcode-222-count-complete-tree-nodes/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1, 2, 3, 4, 5, 6]\n");
    printf("expected result: output = 6\n");
    {
        TreeNode *root = new TreeNode(1);
        TreeNode *lev_1 = new TreeNode(2);
        TreeNode *lev_2 = new TreeNode(3);
        root->left = lev_1;
        root->right = lev_2;
        TreeNode *lev_1_1 = new TreeNode(4);
        TreeNode *lev_1_2 = new TreeNode(5);
        lev_1->left = lev_1_1;
        lev_1->right = lev_1_2;
        TreeNode *lev_2_1 = new TreeNode(6);
        lev_2->left = lev_2_1;

       
        Solution solution;
        auto result = solution.countNodes(root);
        printf("result:%d\n", result);

        delete lev_1_2;
        delete lev_1_1;
        delete lev_1;
        delete lev_2;
        delete root;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = []\n");
    printf("expected result: output = 0\n");
    {
        TreeNode *root = NULL;
        
        Solution solution;
        auto result = solution.countNodes(root);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [1]\n");
    printf("expected result: output = 1\n");
    {
        TreeNode *root = new TreeNode(1);
        
        Solution solution;
        auto result = solution.countNodes(root);
        printf("result:%d\n", result);

        delete root;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    // printf("*****************************************************\n");
    // printf("************* testcase 4 ****************************\n");
    // printf("input: root = [6,2,5,2,0,6,0,9,4,9,8,6,2,3,6,6,4,7,3,0,9,2,2,5,0,6,8,4,1,3,9,4,3,9,0,1,6,2,7,0,1,7,3,9,8,9,6,1,9,9,3,7,2,2,9,5,2,2,3,9,9,0,8,7,5,7,2,4,1,4,4,5,8,6,8,0,4,4,7,9,2,1,8,9,0,0,3,0,0,3,5,6,4,5,2,8,6,5,7,8,8,8,7,3,2,6,5,7,8,3,5,8,6,8,8,8,8,6,0,9,5,6,9,3,0,0,9,6,8,0,0,9,1,9,6,1,9,9,1,9,1,4,6,3,1,5,7,7,0,4,3,5,7,3,0,4,1,3,1,2,2,8,7,6,1,7,5,9,7,3,2,6,1,2,9,0,7,1,4,1,9,9,2,5,9,0,3,3,7,1,0,2,4,0,5,5,5,1,2,2,3,2,0,2,1,1,3,8,9,9,7,5,3,2,4,2,3,9,8,4,7,5,4,6,6,9,6,4,8,2,1,5,0,0,6,9,7,3,2,0,3,5,7,8,5,8,3,6,3,7,2,9,9,7,8,4,4,1,0,0,5,0,8,8,7,7,6,8,5,9,7,6,7,2,2,7,0,6,4,2,6,4,9,5,5,3,1,4,6,7,6,6,3,8,2,0,1,4,0,3,2,5,0,4,8,0,8,9,4,4,7,4,2,4,7,6,8,1,9,3,4,1,2,0,7,9,7,1,5,3,1,7,6,3,4,0,5,7,7,1,2,4,0,3,1,8,3,9,8,7,5,6,3,5,2,2,9,4,3,3,9,2,2,7,3,9,8,9,5,5,5,1,5,6,6,9,0,4,9,5,5,6,7,5,3,0,1,6,7,3,3,8,9,4,2,7,0,9,6,4,5,4,9,4,0,9,5,5,9,4,3,4,5,9,2,7,9,6,1,7,0,5,8,4,8,6,3,0,1,6,7,1,1,7,7,0,0,1,8,9,0,9,0,6,3,2,9,6,4,4,7,3,8,8,4,7,5,5,9,7,1,7,9,8,0,5,9,9,5,8,2,0,2,4,0,0,8,5,5,9,4,4,6,1,4,9,5,6,7,6,0,9,3,5,1,0,0,5,3,9,7,0,9,1,7,0,7,2,6,6,8,2,8,4,1,9,2,8,0,5,0,8,6,4,1,4,9,6,6,9,0,3,3,5,9,5,4,5,4,5,4,8,1,6,0,6,9,6,0,7,6,8,3,6,3,0,2,5,6,9,1,2,9,8,6,0,1,9,2,4,7,3,2,8,8,1,8,3,5,9,9,7,2,3,7,4,2,1,9,4,5,9,3,5,3,5,1,7,4,2,1,6,6,8,3,8,2,7,1,8,1,0,1,8,3,2,2,7,1,9,4,0,4,8,8,5,6,7,1,3,4,2,6,4,7,1,3,8,7,5,5,6,8,1,0,4,7,5,9,1,4,5,8,7,6,3,5,3,3,2,7,3,3,6,9,3,9,9,2,0,1,9,5,5,9,6,7,7,9,6,2,0,2,6,5,6,7,7,0,8,3,9,6,5,8,1,6,1,7,4,0,3,3,2,3,8,9,1,7,4,5,5,5,9,4,8,0,5,1,8,3,8,8,8,0,2,2,8,1,9,5,4,5,4,3,8,4,8,5,7,0,9,3,6,9,0,0,7,8,8,0,6,2,1,4,2,2,1,2,9,7,1,3,5,3,3,2,3,8,4,6,6,3,4,1,2,6,6,4,7,2,4,7,5,4,8,0,4,5,1,2,6,6,9,9,9,2,2,2,7,3,8,6,9,6,6,7,3,3,8,9,3,2,5,4,4,5,0,8,0,7,1,6,1,4,7,7,2,5,6,5,4,5,1,6,1,2,6,7,2,7,3,2,5,9,0,5,8,0,2,7,6,9,9,5,7,1,9,6,1,8,7,1,9,3,1,4,4,1,2,2,8,3,8,6,8,6,9,3,5,9,9,1,3,3,1,7,0,1,8,8,2,8,5,3,0,8,4,2,2,7,7,9,2,0,6,4,0,6,3,0,4,2,6,8,0,0,2,6,4,1,6,4,7,0,5,7,0,1,8,2,5,2,1,6,8,8,4,6,2,9,7,5,0,3,4,7,5,2,9,4,2,6,0,3,4,6,3,9,0,4,3,4,0,1,8,6,5,8,2,4,5,6,1,8,9,4,8,0,7,6,9,1,1,9,3,0,6,4,4,7,6,9,6,6,5,6,9,8,8,3,4,9,2,6,9,9,0,5,3,5,2,2,4,4,5,5,0,7,1,2,9,8,0,5,4,5,2,5,5,8,8,0,9,4,4,7,0,7,4,0,5,4,9,8,5,7,4,2,1,7,0,3,7,3,2,6,6,2,5,6,0,9,9,6,2,2,3,8,6,7,0,6,7,2,8,4,0,9,4,3,3,5,3,5,8,5,9,5,0,6,1,8,7,0,0,3,2,0,0,4,6,4,7,5,9,0,5,6,5,2,5,6,6,5,4,6,6,4,7,3,5,7,2,5,4,1,5,8,7,3,2,0,2,6,4,4,8,4,5,3,9,9,3,7,7,8,4,5,7,0,9,0,5,4,3,7,3,8,4,7,2,3,3,3,7,6,1,6,0,7,5,1,5,6,9,0,6,8,7,4,4,7,6,6,9,6,6,1,9,7,3,0,4,0,1,0,7,6,0,2,7,5,7,1,1,6,0,9,4,7,1,2,3,0,8,0,1,9,7,1,8,5,0,0,5,1,4,4,7,5,1,3,3,4,3,9,6,7,5,9,7,0,0,3,5,9,1,7,5,4,1,8,3,0,6,4,6,9,7,6,0,9,9,8,9,9,6,0,6,4,3,8,1,0,3,1,3,8,3,4,4,8,4,7,9,2,6,5,4,5,1,2,1,6,8,0,0,4,9,2,3,6,8,8,0,4,1,4,7,4,8,4,2,3,3,4,6,8,8,4,7,6,0,6,0,5,9,0,4,6,8,7,1,8,6,4,2,5,5,9,9,3,3,6,0,3,4,8,7,1,7,6,9,9,8,6,8,1,7,6,3,3,3,3,1,2,7,9,0,2,0,7,2,9,9,6,1,4,5,0,4,1,8,9,0,4,4,1,0,3,7,7,4,2,9,7,1,9,2,1,6,3,2,2,8,4,5,5,5,8,6,0,6,6,4,3,3,2,6,4,0,2,9,4,4,8,6,2,5,8,7,7,2,0,4,0,6,9,3,3,0,1,4,5,7,9,1,7,0,1,7,9,1,9,6,1,7,3,4,7,7,1,1,0,6,5,5,0,5,7,8,4,4,5,9,2,3,9,0,1,3,6,3,7,0,1,9,7,9,0,9,9,1,5,0,8,9,7,0,1,9,0,4,6,6,5,3,7,9,4,2,1,4,4,9,0,4,2,9,8,3,5,7,5,5,0,0,7,9,8,8,8,0,2,8,0,8,3,1,3,0,3,8,4,3,1,7,6,1,8,9,9,9,4,3,9,0,4,1,5,9,8,7,3,6,8,0,9,3,1,0,0,7,7,4,7,6,8,0,7,7,2,0,8,6,1,6,4,9,7,2,7,2,3,3,0,6,2,1,2,2,3,3,5,1,6,5,4,8,1,3,6,1,9,7,1,9,3,6,8,1,2,7,4,5,9,1,5,1,4,7,1,2,3,7,8,6,3,0,5,2,3,1,5,8,2,1,5,6,4,6,6,2,8,7,7,4,6,0,8,1,3,0,6,3,8,8,2,5,5,9,4,6,7,5,4,1,8,4,4,3,5,6,8,4,4,0,8,7,0,2,2,2,3,5,9,4,5,3,5,3,4,8,0,9,9,4,4,7,9,9,0,2,2,3,2,2,1,8,9,8,2,8,3,5,3,6,4,4,8,4,4,6,4,8,8,3,7,1,5,2,6,6,3,8,8,1,5,2,4,6,1,3,5,1,4,6,0,9,2,1,0,6,2,5,2,7,1,2,8,2,5,3,9,0,7,7,8,5,1,6,3,8,2,7,0,9,8,5,9,4,5,7,5,1,5,3,6,2,5,5,8,8,5,2,9,7,9,3,2,8,4,8,9,9,0,4,3,3,4,5,5,6,6,1,4,0,8,7,3,0,7,1,6,9,3,8,6,1,3,2,4,5,2,4,2,9,8,2,2,9,0,7,8,7,0,5,1,9,8,8,0,6,0,9,1,1,4,2,6,1,8,1,2,4,1,6,1,5,8,3,6,8,5,5,3,6,9,8,9,4,0,1,5,4,0,7,5,9,6,8,3,9,6,3,3,9,8,3,6,1,3,3,0,8,4,9,2,6,7,1,7,4,4,4,7,9,3,4,7,1,8,7,7,0,1,9,2,1,5,3,3,8,1,3,4,0,3,1,7,9,6,2,0,0,1,4,5,9,9,0,1,3,0,3,3,3,7,0,3,0,9,4,2,8,2,5,0,4,5,3,7,4,0,9,6,7,7,6,1,2,0,4,4,0,6,1,8,2,3,4,6,3,6,0,3,8,5,8,2,8,9,9,9,1,4,4,6,5,0,2,9,7,5,7,0,1,7,6,7,3,8,0,5,6,9,3,4,2,9,6,8,3,2,5,8,6,1,3,1,3,3,6,7,5,7,9,2,3,5,2,0,3,2,9,1,7,4,6,3,6,7,1,1,9,9,3,4,4,8,5,8,8,6,6,7,7,1,2,4,5,6,3,7,6,8,6,0,9,6,4,6,5,9,7,1,9,0,9,8,8,1,1,0,9,8,9,9,2,2,2,5,9,8,3,7,5,8,0,2,0,2,5,9,4,6,6,0,4,3,8,3,2,3,9,9,6,3,6,8,7,6,6,3,3,2,1,5,0,2,0,1,8,1,7,5,4,2,5,6,8,5,6,2,1,6,4,2,3,3,5,9,5,9,3,2,4,1,6,5,9,2,2,2,9,1,6,6,6,7,2,8,3,8,5,4,3,3,4,6,5,5,5,8,7,0,0,0,2,9,8,7,5,4,6,6,4,1,1,7,9,1,8,5,8,0,1,8,2,0,1,1,6,3,4,9,8,9,5,0,7,0,6,5,3,7,7,1,3,0,4,2,8,3,1,6,6,1,7,5,9,7,9,6,2,1,7,2,3,3,5,6,2,0,0,6,0,3,4,6,6,3,7,4,6,8,7,9,0,6,2,4,6,1,8,7,0,5,9,8,4,4,9,8,8,4,3,1,2,3,0,3,7,1,3,3,4,6,4,8,0,4,7,5,0,9,2,9,5,7,8,7,2,2,6,6,6,0,6,0,4,5,4,8,6,7,0,4,0,5,1,3,1,9,2,3,0,4,0,9,6,3,9,5,1,6,9,7,5,3,8,0,4,9,8,4,6,5,7,1,3,2,1,7,9,4,3,1,1,4,2,4,0,4,2,2,7,0,6,4,7,6,1,6,1,4,3,6,9,7,2,2,1,1,2,6,8,1,6,5,1,9,4,5,4,2,1,9,6,4,8,4,8,2,0,6,7,4,0,6,5,7,8,9,0,5,4,8,9,0,7,4,9,4,9,6,7,5,3,1,4,6,7,3,3,9,9,8,3,8,8,4,3,6,5,9,2,3,6,6,5,8,0,8,2,1,5,3,1,3,8,5,5,8,2,8,6,1,3,5,4,1,0,6,5,3,6,4,6,0,1,2,9,0,9,8,0,5,8,7,4,4,1,5,1,0,9,3,3,9,8,7,2,3,5,0,9,4,2,6,3,8,4,6,9,6,8,6,0,8,3,9,1,5,8,9,4,0,1,6,5,0,7,6,1,8,6,0,3,7,7,1,5,1,6,5,5,1,1,5,2,4,3,2,2,5,2,7,0,0,3,8,1,7,6,3,5,3,5,3,4,7,3,9,1,4,0,0,6,7,0,6,1,7,1,4,6,4,6,8,3,4,9,4,6,9,4,1,0,2,3,6,9,0,2,2,3,9,9,9,8,4,9,4,5,5,2,6,6,4,4,1,8,8,0,3,0,1,3,6,6,2,2,6,6,0,4,1,5,3,4,1,3,9,6,7,1,4,9,0,4,5,6,5,2,1,4,2,4,5,1,0,0,6,3,0,1,2,0,9,5,9,6,9,3,5,4,9,0,5,0,4,5,7,9,5,5,4,3,1,1,5,0,4,8,2,7,8,0,9,9,5,7,0,9,4,1,1,4,5,4,5,2,0,7,9,2,5,1,1,1,2,4,2,5,0,7,0,2,5,6,4,0,8,5,4,4,6,7,5,2,1,0,9,0,7,1,5,7,8,6,2,5,2,6,9,3,6,9,4,4,7,6,7,9,4,9,7,0,9,7,5,2,4,3,8,1,5,6,5,2,7,4,1,2,4,7,8,4,6,5,7,2,2,6,0,4,7,1,6,0,3,8,7,7,4,4,8,7,8,7,6,6,3,0,2,7,2,6,8,1,2,4,1,4,3,5,1,0,8,5,8,8,3,3,8,0,6,2,8,9,6,3,2,9,6,0,9,6,9,8,4,1,1,6,3,0,3,0,0,7,5,1,5,6,8,5,5,8,9,5,0,6,0,3,9,3,6,5,5,5,9,0,6,7,1,0,5,9,1,0,1,8,8,5,8,5,8,8,1,4,4,9,3,5,7,4,7,3,5,6,2,2,8,9,1,6,5,5,0,1,8,2,5,1,8,1,8,7,4,1,5,4,3,3,3,3,1,4,6,5,1,7,9,2,0,0,7,9,2,4,3,1,9,3,7,1,6,7,9,8,3,6,7,6,0,7,3,8,6,0,2,5,6,4,4,2,8,4,4,0,5,2,5,5,6,9,3,1,7,9,2,1,4,7,9,4,7,1,9,8,0,9,8,6,4,2,9,4,5,6,9,4,9,3,1,7,6,7,8,5,4,1,6,7,2,9,4,5,7,1,0,1,7,2,0,6,5,8,7,2,7,6,7,8,3,9,0,2,7,9,8,7,3,8,8,7,0,1,1,4,1,3,8,6,6,2,6,3,8,0,9,7,8,0,2,8,4,6,3,8,2,3,9,4,3,9,9,0,2,5,2,8,0,2,0,0,0,1,8,1,3,1,0,0,2,9,5,9,5,6,7,9,1,2,5,7,1,8,8,3,9,8,1,5,2,0,5,3,1,3,3,2,2,6,7,0,9,0,9,4,5,8,1,1,9,5,9,7,9,9,3,1,2,9,4,2,5,5,6,2,9,9,8,0,2,5,1,3,9,2,1,9,4,6,7,0,4,4,5,0,2,2,8,7,7,0,0,8,5,4,0,1,2,5,6,6,0,2,2,5,8,6,8,8,9,4,7,8,2,4,2,5,8,2,0,5,0,1,0,7,6,5,7,3,8,1,7,8,0,0,5,5,2,8,4,0,2,2,3,5,2,4,4,5,9,3,4,9,8,1,6,7,3,1,3,0,0,6,8,4,8,7,1,2,6,4,2,2,4,9,8,4,1,4,6,8,8,1,4,4,0,5,3,3,1,9,9,4,0,9,9,4,7,7,0,5,4,9,5,9,5,6,1,2,5,4,1,2,8,3,3,0,5,9,2,3,0,6,4,0,5,8,4,0,6,3,6,9,9,8,9,5,2,4,0,2,4,9,8,6,0,4,3,8,1,8,5,4,6,8,1,4,7,4,2,3,0,6,9,2,3,4,7,1,3,6,2,0,5,7,9,9,6,6,6,1,3,6,3,9,8,8,2,3,6,7,4,1,3,6,0,1,1,5,9,6,0,0,8,7,6,9,9,4,8,7,4,4,7,8,9,4,9,8,1,9,7,9,5,5,6,7,3,6,9,1,2,2,5,8,0,5,4,1,5,5,5,1,2,0,8,1,0,2,6,8,0,6,0,1,3,7,2,0,7,9,9,3,1,8,9,9,1,1,9,3,4,1,5,9,3,4,7,0,2,7,7,5,4,6,6,3,3,4,0,1,5,8,3,3,1,1,5,5,1,6,4,3,8,0,3,3,0,7,0,7,9,4,2,3,3,4,3,7,0,9,7,2,8,9,6,3,3,3,7,9,7,7,3,0,2,5,7,6,9,4,0,2,3,3,4,1,1,5,9,1,0,9,5,4,7,6,5,7,1,9,3,3,5,8,8,1,7,2,0,6,7,3,3,5,1,8,3,1,9,2,8,0,5,5,1,6,0,4,7,5,7,0,6,5,1,8,1,4,3,1,0,1,1,7,5,3,7,1,1,1,2,9,2,0,9,9,1,3,5,3,0,6,4,2,1,8,2,4,6,3,3,6,0,8,8,4,2,3,4,7,6,6,8,4,7,0,9,2,9,1,7,9,8,0,7,4,5,6,7,5,2,6,5,4,9,3,9,0,6,8,4,6,8,3,5,9,4,6,2,3,7,4,2,0,6,5,1,4,3,7,4,4,5,7,0,5,8,0,9,3,0,5,3,5,4,8,1,8,6,7,4,6,7,6,4,8,8,2,1,4,6,0,1,7,2,4,0,0,1,0,7,1,8,2,0,2,6,6,9,3,2,9,3,4,1,6,1,9,2,1,4,3,8,7,8,6,2,4,5,3,3,7,6,0,5,0,7,7,1,1,4,5,4,3,5,5,2,6,8,1,9,3,1,8,5,5,4,8,6,8,2,4,4,3,5,4,1,4,9,4,8,9,2,0,1,0,7,4,4,4,8,5,7,9,2,6,7,9,3,7,5,3,4,7,2,2,3,0,0,3,0,1,3,4,3,8,6,4,3,2,2,8,0,0,5,2,7,3,9,7,5,6,5,1,5,9,5,3,8,5,1,2,0,9,9,0,6,7,6,2,3,6,9,1,2,7,2,7,2,8,5,9,9,3,8,1,8,1,9,4,4,9,5,2,8,5,3,9,4,2,9,4,5,3,3,5,6,6,3,2,1,8,2,5,5,3,0,0,5,7,2,2,6,8,1,5,8,6,1,8,4,2,1,4,6,0,5,2,3,9,2,5,5,9,2,4,5,3,1,5,5,5,9,3,3,1,5,5,7,9,9,9,0,9,7,1,3,6,6,4,5,1,3,8,7,9,3,0,9,8,4,1,8,1,9,2,3,3,6,0,5,6,6,6,6,6,8,7,3,0,9,5,0,1,9,9,8,8,3,3,2,4,5,5,6,8,3,1,5,6,8,5,6,0,4,3,4,5,6,2,6,0,3,1,8,0,8,0,7,4,3,9,7,0,5,4,4,4,2,5,5,8,9,9,0,5,3,5,2,8,0,4,3,9,9,6,6,7,9,1,8,7,4,2,4,7,1,5,2,9,3,6,4,9,2,2,0,3,2,9,4,9,2,5,1,4,9,8,1,8,4,1,2,1,7,0,6,2,6,1,0,5,2,0,2,1,5,3,5,6,1,5,9,3,7,7,1,4,3,2,2,8,2,1,4,6,8,1,8,2,5,1,5,9,6,3,7,2,0,0,1,4,3,3,2,1,1,8,8,8,6,3,9,1,9,5,8,8,6,3,8,5,8,9,8,9,0,0,1,5,5,3,1,6,6,8,0,4,1,3,0,3,0,9,2,9,1,7,6,2,1,4,2,2,1,7,5,9,2,8,8,2,7,2,1,9,5,8,1,4,7,2,0,6,5,0,3,3,2,3,9,5,7,6,3,0,4,7,1,0,3,7,4,5,5,8,7,4,7,7,3,5,9,0,5,2,3,2,8,1,8,5,9,7,1,0,2,5,7,1,3,8,2,9,9,5,0,1,2,4,6,3,3,5,7,7,4,4,8,1,8,6,8,1,0,3,4,9,0,0,7,1,1,1,5,4,2,9,3,1,6,0,3,5,0,9,9,7,4,7,9,6,7,6,2,5,2,8,3,3,0,6,0,4,4,3,2,2,5,8,0,0,3,6,6,5,8,0,1,8,2,0,8,3,4,4,2,6,5,4,6,1,4,5,1,6,5,3,9,5,0,7,1,8,4,0,2,5,0,1,9,0,2,3,4,7,9,8,7,5,7,6,6,6,1,5,6,1,2,2,1,0,3,6,6,5,0,9,6,8,7,0,1,5,6,0,7,8,3,0,3,3,8,1,3,7,8,0,4,5,5,0,6,8,2,3,6,9,7,9,0,6,6,3,9,9,0,4,9,6,7,5,1,8,4,9,3,5,3,4,1,5,0,4,6,9,6,1,3,5,6,4,5,2,2,3,5,9,7,1,0,4,0,6,3,9,7,8,0,4,2,3,6,2,2,4,8,9,7,6,2,8,4,7,9,4,8,6,4,0,1,8,3,5,1,2,7,0,4,0,1,6,1,3,0,9,2,1,1,8,9,8,6,7,2,7,9,7,6,9,7,7,5,0,7,7,4,0,4,1,3,1,1,5,0,8,1,7,2,4,7,2,4,0,5,7,6,7,8,6,6,0,6,5,5,2,5,1,4,0,6,4,4,6,0,0,1,9,8,0,0,5,8,2,6,7,8,0,5,0,4,7,3,3,9,0,7,2,6,9,3,0,0,9,3,7,7,1,0,3,1,0,2,1,3,8,0,0,8,2,8,1,5,6,5,0,4,5,5,7,9,9,4,7,1,5,9,6,2,6,5,8,3,5,5,2,5,6,8,5,6,2,0,6,3,0,3,1,5,7,7,3,8,0,5,3,7,6,9,4,3,9,5,2,8,9,5,2,0,6,5,2,6,7,9,8,3,4,4,0,9,9,8,2,9,9,6,9,0,5,6,9,0,2,7,1,7,5,8,5,6,5,3,5,6,7,6,5,1,3,6,8,3,2,8,4,6,1,9,4,9,1,3,5,8,2,8,9,7,3,7,0,9,7,0,6,2,4,3,6,8,4,1,0,7,7,7,8,2,1,7,4,1,7,5,5,4,1,9,1,5,3,3,8,5,6,0,6,1,1,1,3,6,2,3,0,0,6,0,8,2,6,5,6,2,7,9,0,5,0,7,1,0,6,2,9,7,4,1,9,7,7,7,3,5,5,7,8,8,4,8,6,8,8,3,4,2,9,6,0,6,8,7,5,6,4,7,5,9,6,2,4,7,8,4,1,5,4,3,2,7,6,8,0,4,6,2,4,3,5,8,8,8,3,7,7,6,4,3,7,7,8,6,6,1,8,8,5,0,9,4,5,9,3,6,9,2,7,5,2,0,0,7,0,8,6,1,1,6,5,5,5,0,3,4,6,8,4,3,9,5,7,8,2,1,9,9,7,1,6,1,5,0,6,8,0,4,4,7,8,9,2,3,6,1,6,1,6,6,1,0,9,6,2,4,7,1,6,4,5,0,9,0,2,3,3,1,3,1,4,3,0,2,6,0,7,2,0,6,7,4,3,2,1,0,8,6,9,5,6,8,0,3,1,1,0,2,0,4,9,3,6,8,0,9,6,3,9,4,6,3,9,1,7,0,3,9,0,6,0,1,2,9,8,8,2,4,3,4,0,9,0,3,5,0,7,0,9,4,7,5,6,8,8,2,2,2,8,8,8,6,2,0,2,5,6,8,8,8,2,5,1,7,6,1,7,8,3,1,2,3,4,6,3,1,0,9,5,1,2,0,0,9,5,2,2,1,7,1,5,8,1,1,5,5,2,5,4,5,1,2,6,0,6,8,0,5,7,0,8,6,2,7,4,4,0,4,0,6,8,4,9,8,2,3,4,3,2,4,3,2,8,8,6,0,9,3,2,9,2,9,1,8,9,8,8,3,7,2,9,5,5,0,1,1,6,0,2,5,3,7,9,9,7,2,9,5,0,0,0,8,9,8,7,1,0,8,8,9,6,4,9,2,5,0,9,8,2,6,0,5,9,8,4,9,7,6,5,2,1,3,2,2,9,5,3,2,2,7,8,7,8,3,4,3,6,2,7,1,4,2,4,4,4,6,5,4,6,8,5,0,3,2,6,6,1,7,4,0,6,9,7,4,2,0,4,3,9,5,7,8,4,8,3,4,1,2,4,4,7,4,2,1,6,6,8,9,0,2,2,2,3,5,2,7,5,8,5,8,0,5,3,0,8,3,7,5,7,9,0,7,2,3,3,1,5,1,4,4,3,4,2,4,0,3,7,5,8,6,4,9,7,8,6,6,0,2,4,6,8,8,6,8,3,8,0,7,5,4,0,5,7,8,6,6,2,6,5,2,5,3,6,5,8,4,8,7,3,7,1,5,5,4,6,0,2,8,3,2,7,4,0,8,5,8,9,0,3,9,1,2,4,4,4,5,1,3,7,6,0,3,9,2,7,0,4,0,5,6,2,7,9,0,5,2,3,9,8,2,6,6,3,8,2,9,6,3,2,3,4,6,4,3,3,4,5,3,3,1,8,7,3,5,7,7,9,0,1,2,0,5,8,8,0,9,2,4,5,1,0,7,1,4,6,9,1,8,7,6,6,9,9,1,8,8,5,3,3,9,8,9,1,9,1,0,1,3,7,9,1,9,7,8,6,9,0,4,5,0,4,5,6,7,9,0,6,3,0,8,2,5,3,0,1,9,3,7,6,0,8,4,9,5,9,4,8,3,4,0,9,2,2,0,6,8,1,6,1,4,0,9,0,4,6,7,4,8,0,3,4,1,7,0,0,1,5,1,8,9,4,4,2,6,8,4,4,2,1,0,4,3,8,5,9,8,3,6,7,1,5,8,8,4,5,9,7,7,0,8,3,0,9,7,1,8,7,6,0,6,3,5,6,6,1,7,2,9,5,9,1,3,6,0,7,0,1,9,8,2,7,8,3,2,1,9,5,9,8,7,1,4,3,0,1,0,4,7,6,7,0,9,3,9,1,7,9,0,3,8,0,5,2,2,2,3,9,2,3,3,6,2,8,4,8,5,5,7,4,2,6,2,3,5,1,4,6,8,2,0,0,2,9,8,3,5,9,8,1,2,2,1,5,1,7,1,8,9,9,3,8,7,0,8,9,9,6,7,6,9,5,8,6,5,4,6,1,8,0,1,0,4,7,0,9,7,9,3,5,8,8,1,4,6,9,2,9,4,6,0,3,1,5,0,1,2,4,1,2,6,6,6,8,6,4,9,9,3,2,4,2,1,1,6,0,3,0,2,8,1,0,4,7,1,3,3,0,4,4,9,1,4,0,6,3,4,9,8,7,0,2,5,9,1,0,2,7,5,2,2,0,5,9,5,4,4,3,6,6,4,5,7,3,3,6,3,5,5,6,3,0,9,1,3,2,3,9,7,4,7,4,6,5,5,4,1,4,7,2,8,0,8,2,7,6,8,2,9,2,6,0,0,6,0,0,8,5,8,6,0,9,2,3,1,0,9,6,9,0,0,4,5,4,7,9,3,8,8,5,9,9,0,9,9,6,0,6,5,6,4,1,1,6,3,8,3,6,6,5,9,3,2,5,1,4,1,5,9,3,3,2,8,7,4,1,2,9,4,1,0,4,7,5,2,7,5,9,5,4,4,7,7,7,7,0,3,1,4,1,7,5,1,8,9,8,0,5,8,2,1,9,4,4,7,9,9,8,4,2,8,2,0,0,7,7,2,0,4,0,5,5,7,7,9,5,9,3,0,5,7,3,1,9,5,3,1,8,4,8,3,1,0,7,3,6,7,6,2,3,5,1,1,7,0,6,8,6,1,6,9,7,7,5,5,5,5,1,8,9,9,9,2,0,4,9,1,2,2,5,8,9,7,6,9,9,5,1,1,8,6,7,9,0,2,7,6,9,9,9,0,0,3,8,2,3,6,8,4,8,5,7,0,7,0,6,1,2,1,9,6,0,7,7,9,9,8,7,9,1,7,4,4,5,9,6,5,8,1,7,3,0,9,0,7,9,9,9,6,4,2,8,3,1,4,5,6,2,7,1,1,5,4,4,3,1,5,7,8,2,4,0,8,0,8,6,6,4,2,5,5,3,4,7,7,2,6,8,4,5,0,3,9,3,9,6,0,4,5,8,5,3,0,0,5,4,6,8,6,0,8,1,9,2,5,5,7,4,7,6,4,6,5,0,1,1,7,3,3,5,6,7,4,3,4,3,8,0,6,9,0,7,0,3,2,4,9,7,0,1,0,8,4,8,8,5,5,4,3,9,8,0,3,9,0,9,1,5,2,6,1,0,6,5,6,9,2,5,7,6,2,4,6,6,0,9,1,3,7,9,0,4,1,5,8,7,9,6,3,3,7,0,5,7,0,5,5,4,7,4,2,0,4,3,2,2,4,4,7,4,5,1,2,5,8,1,6,7,7,7,3,8,5,8,6,5,2,0,6,1,0,1,0,6,6,8,2,8,2,1,1,4,0,9,8,5,5,7,3,3,9,7,3,3,0,4,9,7,0,3,7,7,1,9,8,3,7,6,1,2,3,3,9,7,6,6,5,0,4,2,2,7,9,3,2,4,8,6,5,3,7,4,2,7,6,8,0,9,3,5,2,3,4,5,8,6,4,7,7,7,9,1,9,5,3,7,1,0,8,3,8,2,5,9,4,9,8,4,7,6,8,9,3,7,4,6,8,9,1,5,4,0,4,2,4,2,1,6,6,2,9,0,2,0,8,8,3,4,1,1,3,8,6,0,9,6,8,8,8,4,9,9,9,9,5,8,5,6,7,3,2,3,7,0,3,3,0,3,7,8,2,0,4,7,0,1,5,1,5,4,0,3,0,2,1,4,7,4,0,3,2,6,3,8,4,3,4,8,1,5,3,3,2,8,8,6,5,3,4,5,3,0,3,7,1,5,3,6,0,9,9,6,9,6,9,9,5,0,7,7,4,1,8,9,3,0,2,8,2,9,4,6,1,0,4,4,7,0,4,0,4,6,6,7,2,0,3,4,5,9,6,5,5,5,4,9,0,1,0,2,7,4,0,4,3,1,7,4,3,9,6,8,8,2,7,4,2,1,3,6,7,0,4,6,1,9,0,5,0,9,8,7,5,3,3,2,7,1,7,7,5,7,4,7,6,2,9,9,0,4,0,9,4,2,5,5,3,0,6,2,1,9,9,9,6,4,1,4,5,2,8,8,7,7,9,4,5,4,0,5,5,9,4,8,6,2,8,9,6,1,7,4,5,2,4,5,0,2,5,6,5,0,8,5,2,8,0,4,7,7,8,1,9,0,4,8,8,5,1,3,5,6,3,8,6,6,5,7,3,1,0,0,2,0,6,9,0,6,2,3,8,6,3,8,1,4,5,1,1,3,6,0,9,1,2,0,4,9,2,1,2,5,9,0,7,5,1,9,5,8,9,9,0,9,6,4,2,2,4,0,4,9,5,7,5,2,4,1,5,0,8,9,1,7,8,6,0,7,3,9,1,2,4,1,3,3,5,1,9,1,5,4,6,8,0,3,1,8,2,2,2,1,2,4,6,0,8,2,5,2,4,0,3,2,0,8,4,7,3,6,1,3,3,8,0,3,5,9,9,9,7,3,9,1,2,7,0,4,7,2,2,1,5,2,5,4,6,2,9,6,5,4,3,1,3,0,5,1,1,8,0,6,3,4,3,8,5,6,6,6,9,1,7,4,3,2,4,6,4,3,8,9,6,4,2,7,7,0,5,5,2,7,6,1,6,8,0,1,7,6,4,6,5,4,1,9,5,7,6,3,9,6,3,8,6,2,9,7,5,9,9,1,7,8,7,0,5,8,2,0,4,8,9,3,2,8,8,7,5,5,1,1,2,0,1,7,5,3,5,8,2,6,8,8,3,8,4,3,3,1,8,3,8,9,4,3,2,9,4,3,9,3,0,6,5,5,2,7,1,6,7,7,7,6,0,4,6,7,1,0,7,7,5,6,3,0,1,4,2,4,0,7,0,3,3,2,7,6,7,2,7,8,8,1,1,9,1,3,5,7,8,6,9,7,1,0,8,6,7,2,4,5,2,2,4,3,7,4,9,3,5,9,1,6,8,6,7,2,4,3,4,3,4,9,5,0,0,5,4,7,6,3,5,5,8,0,8,4,0,2,8,2,2,0,8,5,1,9,3,5,8,8,6,5,1,8,6,6,6,7,5,2,3,4,2,3,1,9,9,5,8,0,6,5,1,6,8,6,7,7,1,2,3,1,6,4,4,5,1,0,7,8,4,4,6,5,9,6,1,9,0,3,4,4,7,7,5,0,7,7,7,4,4,8,7,8,0,8,7,5,1,5,2,4,9,9,6,3,9,7,6,4,2,3,2,3,2,4,6,2,3,4,7,7,8,4,7,9,3,6,9,8,0,9,9,3,6,8,5,2,1,3,5,5,4,8,3,0,5,2,3,0,7,3,9,8,1,4,0,5,5,3,4,8,1,6,0,2,0,4,7,8,8,5,9,8,3,8,4,5,4,1,6,6,5,1,3,4,4,5,9,4,9,8,2,7,6,4,0,0,7,9,1,9,1,6,2,6,0,4,0,4,4,9,7,0,2,5,4,3,2,3,1,8,7,8,5,8,8,2,1,5,5,2,3,8,6,2,4,3,5,4,0,2,3,1,7,6,9,2,2,9,1,1,3,7,7,4,8,4,3,4,0,2,9,6,8,6,7,8,2,2,9,6,6,2,9,5,4,4,1,7,4,7,3,3,3,1,9,5,7,8,6,7,4,4,3,0,6,2,7,4,0,4,9,1,9,6,8,8,3,2,4,5,6,3,4,0,8,1,0,8,7,8,7,4,1,9,5,1,0,3,5,4,5,7,5,1,2,7,9,0,8,4,1,1,5,4,9,8,2,8,7,2,3,1,0,1,7,6,3,9,2,0,6,2,2,3,8,3,4,8,2,8,6,0,0,2,0,2,4,2,7,1,5,5,7,5,3,5,8,1,8,7,2,8,5,3,4,7,5,9,5,3,1,9,3,8,5,4,0,5,8,2,6,1,3,0,6,3,4,1,9,6,7,5,0,8,5,1,4,5,9,6,1,8,1,5,3,0,8,7,1,3,9,4,7,8,9,0,2,8,8,9,4,6,5,5,3,0,5,7,3,0,7,8,9,6,0,1,1,9,1,4,8,5,2,2,9,1,2,2,1,3,3,6,7,3,7,7,9,8,1,1,1,0,7,0,8,6,2,7,1,4,2,8,7,7,3,1,7,8,8,2,7,8,4,7,4,5,8,0,1,6,4,0,4,2,2,0,3,0,9,7,4,0,6,8,3,7,1,4,4,8,4,0,3,0,9,4,0,1,2,7,7,8,8,7,0,2,4,0,2,2,3,5,5,1,4,5,9,7,1,7,5,3,1,2,9,6,3,3,2,0,5,4,5,1,0,7,0,6,4,3,2,6,7,2,5,4,4,2,7,5,3,3,3,7,4,8,3,3,7,9,1,3,0,3,3,9,4,2,5,8,9,4,6,1,5,4,8,9,1,1,0,9,0,1,5,4,1,5,2,6,9,5,1,6,4,2,7,8,6,2,7,9,8,9,1,1,2,7,8,1,8,7,1,8,7,3,4,4,8,9,0,6,6,5,2,9,8,8,4,0,3,2,9,7,4,5,0,9,4,2,0,9,2,7,6,8,4,8,9,3,0,9,5,0,4,3,6,9,0,2,8,5,8,3,1,6,2,1,8,4,1,7,5,6,0,6,6,9,7,3,0,5,3,3,8,4,6,9,4,3,5,6,2,2,7,2,5,2,4,9,5,4,2,0,1,4,5,0,9,7,1,0,6,0,6,8,3,4,6,2,1,3,8,9,9,6,6,8,8,7,7,1,5,3,9,5,9,0,9,6,8,2,7,1,1,9,9,9,9,9,1,0,3,0,5,5,1,1,8,3,4,0,4,1,0,1,8,2,4,8,9,9,2,3,8,2,0,7,5,3,6,1,1,6,8,2,6,1,1,3,9,3,6,5,8,3,7,4,9,9,8,8,2,7,6,1,0,5,4,8,9,2,0,3,8,7,7,3,2,6,1,6,4,6,4,4,0,1,1,8,9,1,0,4,3,1,1,3,2,1,2,3,3,0,7,5,9,2,5,3,6,9,1,2,1,1,9,2,9,6,9,8,3,2,9,4,0,8,8,5,7,1,7,8,1,5,3,1,5,0,5,7,1,0,5,1,0,3,5,8,8,7,8,7,5,1,9,6,3,1,5,6,2,3,8,1,1,7,9,5,6,6,2,2,1,9,2,8,2,3,0,2,9,6,8,7,0,2,3,1,7,9,5,3,7,1,3,2,6,4,4,7,0,5,9,1,5,8,2,0,8,7,2,1,7,5,7,0,7,2,6,6,5,2,2,8,9,1,5,2,7,9,0,6,7,5,9,2,4,2,8,2,8,2,1,2,3,6,1,8,4,7,9,4,1,4,3,8,3,9,0,4,3,3,8,5,6,3,2,3,7,8,8,6,9,3,7,3,2,2,2,7,8,2,3,6,3,0,3,7,0,9,8,9,1,2,4,9,3,8,5,1,8,1,6,4,2,4,3,5,7,3,5,8,7,9,8,2,1,5,7,0,9,0,7,3,7,8,9,6,9,9,7,9,6,8,6,4,5,6,1,8,8,4,1,7,9,4,0,8,8,5,3,8,4,6,5,8,3,4,1,6,0,4,5,4,6,0,2,2,1,7,1,3,6,1,0,3,5,0,7,8,7,4,1,1,9,4,3,8,5,0,0,8,9,8,9,5,1,8,2,0,2,4,8,0,2,5,5,1,3,9,4,8,9,2,8,6,9,7,2,4,5,2,7,2,5,3,3,3,9,1,1,0,5,2,9,5,4,7,9,4,8,6,7,1,4,0,3,4,4,7,7,5,2,7,1,9,0,8,1,3,4,9,6,7,9,2,2,3,8,9,5,7,3,4,7,7,4,0,5,0,3,5,0,7,1,1,0,9,0,1,8,1,1,0,4,8,8,7,4,8,8,5,5,8,1,2,8,3,3,5,4,8,5,0,7,6,9,4,9,0,8,1,1,0,0,1,8,7,6,6,2,1,3,0,4,2,6,1,5,8,4,9,8,1,0,8,1,9,9,5,6,6,7,4,1,6,5,9,8,3,4,1,6,8,4,7,0,6,2,7,9,0,1,7,5,7,0,5,5,8,0,4,4,3,9,7,4,7,4,3,3,0,3,2,3,5,5,6,5,0,5,2,0,9,0,2,2,1,1,5,8,6,5,1,0,7,6,3,2,4,0,3,9,1,8,6,9,5,7,1,1,0,7,2,7,6,9,0,1,7,6,3,0,5,3,2,6,0,9,2,2,8,4,6,0,3,7,0,4,8,0,6,3,0,8,9,9,4,5,5,7,9,9,8,5,6,9,1,5,6,6,1,7,4,1,3,2,9,0,9,4,2,3,8,3,9,7,4,2,8,1,4,6,5,3,7,1,1,6,1,1,9,5,6,6,7,9,6,5,6,4,2,8,2,3,4,0,7,1,1,2,9,6,4,5,6,4,8,4,1,2,6,1,8,6,5,4,7,4,9,7,8,5,9,4,9,2,5,2,7,2,0,6,4,7,0,5,3,4,3,8,6,0,7,1,2,4,0,9,8,5,4,2,0,9,3,7,7,1,2,3,2,7,3,9,6,1,8,9,2,4,2,1,6,3,3,6,4,0,4,5,6,2,7,1,2,1,3,6,5,2,6,0,9,0,4,3,7,0,1,4,3,9,0,4,9,0,7,3,4,3,7,1,0,3,3,8,2,5,4,2,4,1,0,6,5,7,7,5,3,0,7,1,7,5,6,0,0,2,7,4,0,4,7,1,4,6,7,2,1,6,6,0,2,0,4,3,5,8,2,2,8,6,9,8,9,0,3,4,9,0,7,4,3,4,0,9,8,8,3,3,6,6,7,7,9,5,3,2,1,9,7,3,9,3,9,9,4,2,8,6,1,7,3,1,0,4,7,6,3,2,6,4,6,8,6,8,2,9,2,2,1,0,2,9,2,6,9,2,0,5,9,5,7,5,4,8,4,7,2,5,0,3,9,8,2,7,5,6,7,6,5,6,1,7,8,8,0,8,3,5,4,8,6,2,1,6,6,1,5,7,2,2,1,6,5,6,2,0,9,1,1,6,4,1,8,9,0,0,7,3,3,8,4,8,3,2,9,4,4,0,2,2,6,2,6,2,7,5,4,9,4,7,4,8,2,0,0,7,0,8,6,3,3,0,9,7,2,5,6,7,0,4,2,4,6,3,4,4,2,2,6,7,3,1,7,9,4,5,6,7,5,3,7,3,7,9,8,4,5,8]\n");
    // printf("expected result: output = 1\n");
    // {
    //     TreeNode *root = new TreeNode(1);
        
    //     Solution solution;
    //     auto result = solution.countNodes(root);
    //     printf("result:%d\n", result);

    //     delete root;
    // }
    // printf("*****************************************************\n");

    // printf("\n\n");
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
