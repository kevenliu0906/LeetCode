// ConsoleApplication_Array_Nesting.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int res = 0;
    vector<bool> nums_check_fg_vec;
    void DFS(vector<int> &nums, int idx){
        
        if (nums_check_fg_vec[idx])
        {
            return;
        }

        res++;
        
        nums_check_fg_vec[idx] = true;
        // printf("DFS >>>>> calling DFS, res:%d, idx:%d\n", res, idx);
        DFS(nums, nums[idx]);

    }
public:
    int arrayNesting(vector<int>& nums) {
        // solution 0 (refer others https://www.cnblogs.com/grandyang/p/6932727.html )
        {
            int n = nums.size(), res = INT_MIN;
            vector<bool> visited(n, false);
            for (int i = 0; i < n; ++i) {
                if (visited[nums[i]]) continue;
                int cnt = 0, j = i;
                while(cnt == 0 || j != i) {
                    visited[j] = true;
                    j = nums[j];
                    ++cnt;
                }
                res = max(res, cnt);
            }
            return res;
        }
        // solution 1 (keven, Time Limit Exceeded in testcase 861) 
        {
            int nums_size = nums.size();
            nums_check_fg_vec.resize(nums_size, false);
            vector<bool> tmp_check_fg_vec;
            tmp_check_fg_vec.resize(nums_size, false);
            int check_idx = 0;
            int max_call_DFS_count = 0;
            while (check_idx < nums_size)
            {
                res = 0; // reset
                // nums_check_fg_vec.clear();   // reset, this is not necessary because all elements in vector is unique
                // nums_check_fg_vec.resize(nums_size, false);  // reset
                // copy(tmp_check_fg_vec.begin(), tmp_check_fg_vec.end(), nums_check_fg_vec);
                

                DFS(nums, check_idx);
                max_call_DFS_count = max(max_call_DFS_count, res);
                // printf("check_idx:%d, res:%d, max_call_DFS_count:%d\n", check_idx, res, max_call_DFS_count);
                // printf("***********************************\n\n");

                
                check_idx++;
            }

            return max_call_DFS_count;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Array Nesting, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/array-nesting/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [5,4,0,3,1,6,2]\n");
    printf("expected result: output = 4\n");
    {
        vector<int> nums{5,4,0,3,1,6,2};
        
        Solution solution;
        auto result = solution.arrayNesting(nums);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [0,1,2]\n");
    printf("expected result: output = 1\n");
    {
        vector<int> nums{0,1,2};
        
        Solution solution;
        auto result = solution.arrayNesting(nums);
        printf("result:%d\n", result);
        
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
