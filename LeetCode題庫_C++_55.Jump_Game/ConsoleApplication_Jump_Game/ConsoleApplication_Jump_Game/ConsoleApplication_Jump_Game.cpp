// ConsoleApplication_Jump_Game.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        // solution 1 (keven, best use logic to judgement)
        {
            if (nums.size() == 1){
                // because start position is the same as last element position even if the element value is 0
                // the element is 0 represent does NOT need to move. 
                return true;
            }
            
            for(int i = 0; i < nums.size(); i++){
                if( nums[i] == 0 ){
                    int j = 1;
                    bool will_Stop = true;
                    while( (i - j) >= 0 ){
                        if( nums[ i - j ] > j ){
                            // means the element before 0-element could be jump over
                            will_Stop = false;
                            break;
                        }
                        if( i == nums.size() - 1 && nums[i-j] == j ){
                            // in order to pass the test case with nums[2, 0, 0]
                            will_Stop = false;
                            break;
                        }
                        j++;
                    }
                    if(will_Stop)
                        return false;
                    // if( (i-1 > 0) && nums[i-1] == 1  )
                }
            }
            return true;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Jump Game, Algorithm(Dynamic Programming)!\n";
    cout << "https://leetcode.com/problems/jump-game/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [2,3,1,1,4]\n");
    printf("expected result: output = true\n");
    {
        vector<int> nums{2,3,1,1,4};
         
        Solution solution;
        auto result = solution.canJump(nums);
        printf("result:%d, true:%d, false:%d\n", result, true, false);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [3,2,1,0,4]\n");
    printf("expected result: output = false\n");
    {
        vector<int> nums{3,2,1,0,4};
         
        Solution solution;
        auto result = solution.canJump(nums);
        printf("result:%d, true:%d, false:%d\n", result, true, false);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [0]\n");
    printf("expected result: output = true\n");
    {
        vector<int> nums{0};
         
        Solution solution;
        auto result = solution.canJump(nums);
        printf("result:%d, true:%d, false:%d\n", result, true, false);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: nums = [2, 0, 0]\n");
    printf("expected result: output = true\n");
    {
        vector<int> nums{2, 0, 0};
         
        Solution solution;
        auto result = solution.canJump(nums);
        printf("result:%d, true:%d, false:%d\n", result, true, false);
        
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
