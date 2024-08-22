// Console_Next_Greater_Element_II.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // solution 1 (keven, best, using stack to solve)
        {
            vector<int> result;
            stack<pair<int,int>> nogreaternums_index_value_stack;  // record the element of non-found next-greater value
                                                                   // key: the index of vector for current num
                                                                   // value: the value for current num
            int nums_size = nums.size();

            result.resize(nums_size, -1);
            
            if (nums.size() != 1){
                for (size_t j = 0; j < 2; j++)
                {
                    // set j = 2 is to double-check if any possible result exist in second round
                    for (size_t i = 0; i < nums_size; i++){                       
                        if (nogreaternums_index_value_stack.empty()){
                            nogreaternums_index_value_stack.push(pair<int,int>(i, nums[i]));
                        }
                        else{
                            while (nogreaternums_index_value_stack.size())
                            {
                                auto top = nogreaternums_index_value_stack.top();
                                if (nums[i] > top.second){
                                    // bingo ~~  fount it!!!
                                    result.at(top.first) = nums[i];
                                    nogreaternums_index_value_stack.pop();  // pop-out the old element
                                }
                                else{
                                    break;
                                }
                            }
                            nogreaternums_index_value_stack.push(pair<int,int>(i, nums[i]));   // push the current new element for next search
                        }
                    }
                    if (nogreaternums_index_value_stack.empty()){
                        // these is no num exist on the stock, so break the double-check loop
                        break;
                    }
                    
                }
            }

            return result;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Next Greater Element II, DataStructure(stack)!\n";
    cout << "https://leetcode.com/problems/next-greater-element-ii/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input nums = [1,2,1]\n");
    printf("expected result: output = [2,-1,2]\n");
    printf("Explanation: The first 1's next greater number is 2;\n");
    printf("The number 2 can't find next greater number.\n");
    printf("The second 1's next greater number needs to search circularly, which is also 2.\n");
    {
        vector<int> nums{1,2,1};

        Solution solution;
        auto result = solution.nextGreaterElements(nums);
        if (result.size())
        {
            printf("result:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input nums = [1,2,3,4,3]\n");
    printf("expected result: output = [2,3,4,-1,4]\n");
    {
        vector<int> nums{1,2,3,4,3};

        Solution solution;
        auto result = solution.nextGreaterElements(nums);
        if (result.size())
        {
            printf("result:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 (biggest element in the middle) ****************************\n");
    printf("input nums = [5,3,2,6,1]\n");
    printf("expected result: output = [6,6,6,-1,5]\n");
    {
        vector<int> nums{5,3,2,6,1};

        Solution solution;
        auto result = solution.nextGreaterElements(nums);
        if (result.size())
        {
            printf("result:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 (biggest element in the tail) ****************************\n");
    printf("input nums = [2,3,1,5,6]\n");
    printf("expected result: output = [3,5,5,6,-1]\n");
    {
        vector<int> nums{2,3,1,5,6};

        Solution solution;
        auto result = solution.nextGreaterElements(nums);
        if (result.size())
        {
            printf("result:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 (biggest element in the head) ****************************\n");
    printf("input nums = [8,3,2,6,1,5,3,8]\n");
    printf("expected result: output = [-1,6,6,8,5,8,8,-1]\n");
    {
        vector<int> nums{8,3,2,6,1,5,3,8};

        Solution solution;
        auto result = solution.nextGreaterElements(nums);
        if (result.size())
        {
            printf("result:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 (only 1 element) ****************************\n");
    printf("input nums = [8]\n");
    printf("expected result: output = [-1]\n");
    {
        vector<int> nums{8};

        Solution solution;
        auto result = solution.nextGreaterElements(nums);
        if (result.size())
        {
            printf("result:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 7 (all elements are decrease order ) ****************************\n");
    printf("input nums = [3,2,1]\n");
    printf("expected result: output = [-1,3,3]\n");
    {
        vector<int> nums{3,2,1};

        Solution solution;
        auto result = solution.nextGreaterElements(nums);
        if (result.size())
        {
            printf("result:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
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
