// Console_Intersection_Two_Arrays_II.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // solution 0-0 (keven, using HASH TABLE to solve)
        {
            vector<int> res;
            vector<int> bigger_num;
            vector<int> smaller_num;
            if (nums1.size() > nums2.size()){
                bigger_num = nums1;
                smaller_num = nums2;
            }
            else{
                bigger_num = nums2;
                smaller_num = nums1;
            }
            
            multiset<int> base_data(bigger_num.begin(), bigger_num.end());
            for (size_t i = 0; i < smaller_num.size(); i++)
            {
                auto found_iter = base_data.find(smaller_num[i]);
                if ( found_iter != base_data.end())
                {
                    res.push_back(smaller_num[i]);
                    base_data.erase(found_iter);
                }
                
            }
            return res;
        }
    }
};



int main()
{
    std::cout << "Hello LeetCode - Intersection of Two Arrays II, DataStructure & Algorithm(HASH TABLE, Binary Search, Two Pointers)!\n";
    cout << "https://leetcode.com/problems/intersection-of-two-arrays-ii/" << endl << endl;
    // cout << "solution: a. https://zxi.mytechroad.com/blog/tree/leetcode-116-populating-next-right-pointers-in-each-node/" << endl;
    // cout << "          b. https://home.gamer.com.tw/artwork.php?sn=5537707" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: num1 = [1,2,2,1], num2 = [2,2]\n");
    printf("expected result: output = [2,2]\n");
    {
        vector<int> num1{1,2,2,1};
        vector<int> num2{2,2};
        
        Solution solution;
        auto result = solution.intersect(num1,num2);
        if (result.size())
        {
            printf("result is:\n");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,",result[i]);
            }
            printf("\n");
            
        }else{
            printf("result is NULL\n");
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: num1 = [4,9,5], num2 = [9,4,9,8,4]\n");
    printf("expected result: output = [4,9]\n");
    {
        vector<int> num1{4,9,5};
        vector<int> num2{9,4,9,8,4};
        
        Solution solution;
        auto result = solution.intersect(num1,num2);
        if (result.size())
        {
            printf("result is:\n");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,",result[i]);
            }
            printf("\n");
            
        }else{
            printf("result is NULL\n");
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: num1 = [1,2], num2 = [1,1]\n");
    printf("expected result: output = [1]\n");
    {
        vector<int> num1{1,2};
        vector<int> num2{1,1};
        
        Solution solution;
        auto result = solution.intersect(num1,num2);
        if (result.size())
        {
            printf("result is:\n");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,",result[i]);
            }
            printf("\n");
            
        }else{
            printf("result is NULL\n");
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: num1 = [2,1], num2 = [1,2]\n");
    printf("expected result: output = [1,2]\n");
    {
        vector<int> num1{2,1};
        vector<int> num2{1,2};
        
        Solution solution;
        auto result = solution.intersect(num1,num2);
        if (result.size())
        {
            printf("result is:\n");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,",result[i]);
            }
            printf("\n");
            
        }else{
            printf("result is NULL\n");
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: num1 = [1,2,2,1], num2 = [1,1]\n");
    printf("expected result: output = [1,1]\n");
    {
        vector<int> num1{1,2,2,1};
        vector<int> num2{1,1};
        
        Solution solution;
        auto result = solution.intersect(num1,num2);
        if (result.size())
        {
            printf("result is:\n");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,",result[i]);
            }
            printf("\n");
            
        }else{
            printf("result is NULL\n");
        }
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
