// ConsoleApplication_Trapping_Rain_Water.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // solution 1 (keven, refer https://hackmd.io/@meyr543/rkjS-x6wY)
        {
            int cur_max = -1;
            vector<int> FwdMax_vec(height.size());
            vector<int> BwdMax_vec(height.size());
            vector<int> res_vec(height.size());     // 
            int res = 0;

            // calc backward max for current height
            cur_max = -1;
            for (int i = 0; i < height.size(); i++)
            {
                cur_max = max(cur_max, height[i]);
                BwdMax_vec[i] = cur_max;
            }
            
            // calc forward max for current height
            cur_max = -1;
            for (int i = height.size()-1; i >= 0; i--)
            {
                cur_max = max(cur_max, height[i]);
                FwdMax_vec[i] = cur_max;
            }
            
            for (size_t i = 0; i < height.size(); i++)
            {
                res += min(BwdMax_vec[i], FwdMax_vec[i]) - height[i];
            }

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Trapping Rain Water (Algorithm, Monotonic Stack)!\n";
    cout << "https://leetcode.com/problems/trapping-rain-water/" << endl;
    cout << "solution: https://hackmd.io/@meyr543/rkjS-x6wY" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: height=[0,1,0,2,1,0,1,3,2,1,2,1]\n");
    printf("expected result: output = 6\n");
    {
        
        vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
        Solution solution;
        auto res = solution.trap(height);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: height=[4,2,0,3,2,5]\n");
    printf("expected result: output = 9\n");
    {
        
        vector<int> height{4,2,0,3,2,5};
        Solution solution;
        auto res = solution.trap(height);
        printf("res is %d\n", res);
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
