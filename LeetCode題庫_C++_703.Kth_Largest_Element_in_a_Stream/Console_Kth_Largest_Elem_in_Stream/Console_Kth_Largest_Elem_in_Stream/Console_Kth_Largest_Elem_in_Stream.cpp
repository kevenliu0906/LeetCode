// Console_Kth_Largest_Elem_in_Stream.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class KthLargest {
private:
    multiset<int> nums_multiset;
    int targetCount = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        targetCount = k;
        multiset<int> tmp_set(nums.begin(), nums.end());
        nums_multiset.swap(tmp_set);

        // reduce the database to save time
        while (nums_multiset.size() > targetCount)
        {
            nums_multiset.erase(nums_multiset.begin());
        }
    }
    
    int add(int val) {
        int res = 0;
        nums_multiset.insert(val);
        // reduce the database to save time
        if (nums_multiset.size() > targetCount)
        {
            nums_multiset.erase(nums_multiset.begin());
        }

        // the first element in nums_set is the correct value
        return *nums_multiset.begin();
        

        // // printf("******* dbg cur nums_set *********\n");
        // auto single_set = nums_multiset.rbegin();
        // // printf(">>> reverse-order\n");
        // int matchIdx = 1;
        // while (single_set != nums_multiset.rend())
        // {
        //     // printf("%d,", *single_set);
        //     if (matchIdx == targetCount)
        //     {
        //         res = *single_set;
        //         return res;
        //     }
        //     single_set++;
        //     matchIdx++;
        // }
        // // printf("\n");
        // // printf(">>> in-order\n");
        // // for (auto single_set : nums_multiset)
        // // {
        // //     printf("%d,", single_set);
        // // }
        // // printf("\n**********************************\n");
        
        return 0;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
    std::cout << "Hello LeetCode - Kth Largest Element in a Stream, Algorithm(Binary Search Tree)!\n";
    cout << "https://leetcode.com/problems/kth-largest-element-in-a-stream/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: Input = [\"KthLargest\",\"add\",\"add\",\"add\",\"add\",\"add\"]\n");
    printf("               [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]\n");
    printf("expected result: output = [null, 4, 5, 5, 8, 8]\n");
    {
        int k = 3;
        vector<int> nums{4, 5, 8, 2};
        KthLargest* obj = new KthLargest(k, nums);
        int val = 3;
        int param_1 = obj->add(val);
        printf("after add val:%d, param_1:%d\n", val, param_1);
        val = 5;
        param_1 = obj->add(val);
        printf("after add val:%d, param_1:%d\n", val, param_1);
        val = 10;
        param_1 = obj->add(val);
        printf("after add val:%d, param_1:%d\n", val, param_1);
        val = 9;
        param_1 = obj->add(val);
        printf("after add val:%d, param_1:%d\n", val, param_1);
        val = 4;
        param_1 = obj->add(val);
        printf("after add val:%d, param_1:%d\n", val, param_1);
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
