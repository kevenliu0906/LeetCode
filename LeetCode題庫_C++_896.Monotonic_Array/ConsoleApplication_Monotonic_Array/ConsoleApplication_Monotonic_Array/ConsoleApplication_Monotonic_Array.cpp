// ConsoleApplication_Monotonic_Array.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    stack<int> monotonic_st;
    bool check_monotonic(vector<int> &nums){
        //------- 1st. check with increasing order
        stack<int> zero_st;
        monotonic_st.swap(zero_st);
        vector<int> inc_vec(nums.size());
        bool inc_fg = true;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (!monotonic_st.empty() && monotonic_st.top() < nums[i] )
            {
                inc_fg = false;
                monotonic_st.pop();
                break;
            }

            inc_vec[i] = monotonic_st.empty() ? -1 : monotonic_st.top();
            monotonic_st.push(nums[i]);
        }

        if (inc_fg)
        {
            // given array is monotonic increasing
            return true;
        }

        //------- 2nd. check with decreasing order
        monotonic_st.swap(zero_st);
        vector<int> dec_vec(nums.size());
        bool dec_fg = true;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (!monotonic_st.empty() && monotonic_st.top() > nums[i] )
            {
                dec_fg = false;
                monotonic_st.pop();
                break;
            }

            dec_vec[i] = monotonic_st.empty() ? -1 : monotonic_st.top();
            monotonic_st.push(nums[i]);
        }

        if (dec_fg)
        {
            // given array is monotonic decreasing
            return true;
        }

        return false;
    }

public:
    bool isMonotonic(vector<int>& nums) {
        // solution 1 (keven, using monotonic stack to solve it)
        {
            return check_monotonic(nums);
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Monotonic Array, DataStructure(Monotonic Stack)!\n";
    cout << "https://leetcode.com/problems/monotonic-array/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [1,2,2,3]\n");
    printf("expected result: output = true\n");
    {
        vector<int> nums{1,2,2,3};

        Solution solution;
        auto res = solution.isMonotonic(nums);
        printf("nums:\n");
        for (size_t i = 0; i < nums.size(); i++)
        {
            printf("%d,", nums[i]);
        }
        printf("\n");
        printf("res is %d, true(%d). false(%d)\n", res, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [6,5,4,4]\n");
    printf("expected result: output = true\n");
    {
        vector<int> nums{6,5,4,4};

        Solution solution;
        auto res = solution.isMonotonic(nums);
        printf("nums:\n");
        for (size_t i = 0; i < nums.size(); i++)
        {
            printf("%d,", nums[i]);
        }
        printf("\n");
        printf("res is %d, true(%d). false(%d)\n", res, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [1,3,2]\n");
    printf("expected result: output = true\n");
    {
        vector<int> nums{1,3,2};

        Solution solution;
        auto res = solution.isMonotonic(nums);
        printf("nums:\n");
        for (size_t i = 0; i < nums.size(); i++)
        {
            printf("%d,", nums[i]);
        }
        printf("\n");
        printf("res is %d, true(%d). false(%d)\n", res, true, false);
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
