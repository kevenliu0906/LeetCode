// Console_FindDistance_Bet_Two_Array.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findInsertPos(int a1, vector<int> arr2)
    {
        sort(arr2.begin(), arr2.end());

        int left = 0;
        int right = arr2.size()-1;

        while(left<=right){
            int mid = left + (right-left)/2;
            if (a1 == arr2[mid]){
                // return mid;
            }
            if (a1 > arr2[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left;

    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        // solution 2 (keven, force solution)
        {
            int matchCount = 0;
            for (size_t i = 0; i < arr1.size(); i++)
            {
                bool Match = true;
                for (size_t j = 0; j < arr2.size(); j++)
                {
                    auto dis = arr1[i] - arr2[j];
                    if (abs(dis)<=d)
                    {
                        Match = false;
                        break;
                    }
                    
                }
                if (Match)
                {
                    matchCount++;
                }
            }
            return matchCount;
        }
        
        // solution 1 (keven)
        {
            int result = 0;
            
            for (size_t i = 0; i < arr1.size(); i++)
            {
                auto currentNum = arr1[i];
                auto currentNum_insertPos = findInsertPos(currentNum, arr2);
                // printf("currentNum:%d, currentNum_insertPos:%d\n", currentNum, currentNum_insertPos);
                auto increaseIndex = currentNum_insertPos + 1;
                auto decreaseIndex = currentNum_insertPos - 1;
                bool match = true;
                vector<int> tmparr2{ arr2 };
                tmparr2.insert(tmparr2.begin() + currentNum_insertPos, currentNum);
                while (increaseIndex < tmparr2.size())
                {
                    // printf("tmparr2[%d]:%d, currentNum:%d, dis:%d\n", increaseIndex, tmparr2[increaseIndex], currentNum, abs(tmparr2[increaseIndex] - currentNum));
                    if (abs(tmparr2[increaseIndex] - currentNum) <= d)
                    {
                        match = false;
                        break;
                    }else   
                        break;
                    increaseIndex++;
                }
                if( !match )
                    continue;

                while (decreaseIndex >= 0)
                {
                    // printf("tmparr2[%d]:%d, currentNum:%d, dis:%d\n", decreaseIndex, tmparr2[decreaseIndex], currentNum, abs(currentNum - tmparr2[decreaseIndex]));
                    if (abs(currentNum - tmparr2[decreaseIndex]) <= d)
                    {
                        match = false;
                        break;;
                    }
                    decreaseIndex--;
                }  
                if( !match )
                    continue; 
                if(match)
                    result++;
            }
            
            // printf("result:%d\n", result);
            return result;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Find Distance between Two Arrays, Algorithm(Binary Search, Two Pointer)!\n";
    cout << "https://leetcode.com/problems/find-the-distance-value-between-two-arrays/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: arr1 = [4,5,8], arr2 = [10,9,1,8], d=2\n");
    printf("expected result: output = 2\n");
    {
        vector<int> arr1{4,5,8};
        vector<int> arr2{10,9,1,8};
        int d = 2;
         
        Solution solution;
        auto result = solution.findTheDistanceValue(arr1, arr2, d);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d=3\n");
    printf("expected result: output = 2\n");
    {
        vector<int> arr1{1,4,2,3};
        vector<int> arr2{-4,-3,6,10,20,30};
        int d = 3;
         
        Solution solution;
        auto result = solution.findTheDistanceValue(arr1, arr2, d);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d=6\n");
    printf("expected result: output = 1\n");
    {
        vector<int> arr1{2,1,100,3};
        vector<int> arr2{-5,-2,10,-3,7};
        int d = 6;
         
        Solution solution;
        auto result = solution.findTheDistanceValue(arr1, arr2, d);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: arr1 = [-803,715,-224,909,121,-296,872,807,715,407,94,-8,572,90,-520,-867,485,-918,-827,-728,-653,-659,865,102,-564,-452,554,-320,229,36,722,-478,-247,-307,-304,-767,-404,-519,776,933,236,596,954,464]\n");
    printf("input: arr2 = [817,1,-723,187,128,577,-787,-344,-920,-168,-851,-222,773,614,-699,696,-744,-302,-766,259,203,601,896,-226,-844,168,126,-542,159,-833,950,-454,-253,824,-395,155,94,894,-766,-63,836,-433,-780,611,-907,695,-395,-975,256,373,-971,-813,-154,-765,691,812,617,-919,-616,-510,608,201,-138,-669,-764,-77,-658,394,-506,-675,523,730,-790,-109,865,975,-226,651,987,111,862,675,-398,126,-482,457,-24,-356,-795,-575,335,-350,-919,-945,-979,611]\n");
    printf("input: d=37\n");
    printf("expected result: output = 0\n");
    {
        vector<int> arr1{-803,715,-224,909,121,-296,872,807,715,407,94,-8,572,90,-520,-867,485,-918,-827,-728,-653,-659,865,102,-564,-452,554,-320,229,36,722,-478,-247,-307,-304,-767,-404,-519,776,933,236,596,954,464};
        vector<int> arr2{817,1,-723,187,128,577,-787,-344,-920,-168,-851,-222,773,614,-699,696,-744,-302,-766,259,203,601,896,-226,-844,168,126,-542,159,-833,950,-454,-253,824,-395,155,94,894,-766,-63,836,-433,-780,611,-907,695,-395,-975,256,373,-971,-813,-154,-765,691,812,617,-919,-616,-510,608,201,-138,-669,-764,-77,-658,394,-506,-675,523,730,-790,-109,865,975,-226,651,987,111,862,675,-398,126,-482,457,-24,-356,-795,-575,335,-350,-919,-945,-979,611};
        int d = 37;
         
        Solution solution;
        auto result = solution.findTheDistanceValue(arr1, arr2, d);
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
