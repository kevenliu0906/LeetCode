// ConsoleApp_Number_of_Recent_Calls.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class RecentCounter {
private:
    vector<int> storage_data_que;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if (storage_data_que.size())
        {
            // STEP1: check if any stored data is out of range, 
            //        if YES, remove it at first.

            int check_idx = 0;
            while (check_idx < storage_data_que.size())
            {
                if (storage_data_que[check_idx] < (t-3000))
                {
                    storage_data_que.erase(storage_data_que.begin() + check_idx);
                    continue;
                }else{
                    break;
                }
                
                check_idx++;
            }
            
        }

        // STEP2: push the data into queue to stored
        storage_data_que.push_back(t);
        
        return storage_data_que.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main()
{
    std::cout << "Hello LeetCode - Number of Recent Calls, DataStructure(Queue)!\n";
    cout << "https://leetcode.com/problems/number-of-recent-calls/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input = [\"RecentCounter\", \"ping\", \"ping\", \"ping\", \"ping\"]\n");
    printf("        [[], [1], [100], [3001], [3002]]\n");
    printf("expected result: output = [null, 1, 2, 3, 3]\n");
    {
        
        RecentCounter *recentCounter = new RecentCounter();
        auto res = recentCounter->ping(1);     // requests = [1], range is [-2999,1], return 1
        printf("after ping(1), res:%d\n", res);

        res = recentCounter->ping(100);   // requests = [1, 100], range is [-2900,100], return 2
        printf("after ping(100), res:%d\n", res);

        res = recentCounter->ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
        printf("after ping(3001), res:%d\n", res);

        res = recentCounter->ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
        printf("after ping(3002), res:%d\n", res);

        delete recentCounter;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input = [\"RecentCounter\", \"ping\", \"ping\", \"ping\", \"ping\", \"ping\"]\n");
    printf("        [[], [1], [100], [3000], [3001], [3002]]\n");
    printf("expected result: output = [null, 1, 2, 3, 4, 4]\n");
    {
        
        RecentCounter *recentCounter = new RecentCounter();
        auto res = recentCounter->ping(1);     // requests = [1], range is [-2999,1], return 1
        printf("after ping(1), res:%d\n", res);

        res = recentCounter->ping(100);   // requests = [1, 100], range is [-2900,100], return 2
        printf("after ping(100), res:%d\n", res);

        res = recentCounter->ping(3000);  // requests = [1, 100, 3000], range is [0,3000], return 3
        printf("after ping(3001), res:%d\n", res);

        res = recentCounter->ping(3001);  // requests = [1, 100, 3000, 3001], range is [1,3001], return 4
        printf("after ping(3001), res:%d\n", res);

        res = recentCounter->ping(3002);  // requests = [1, 100, 3000, 3001, 3002], range is [2,3002], return 4
        printf("after ping(3002), res:%d\n", res);

        delete recentCounter;
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
