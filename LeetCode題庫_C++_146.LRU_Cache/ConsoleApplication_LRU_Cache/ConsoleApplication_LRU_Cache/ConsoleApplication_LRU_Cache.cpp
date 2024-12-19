// ConsoleApplication_LRU_Cache.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

class LRUCache {
private:
    // solution 0 (keven, best, refer https://haogroot.com/2021/01/31/lc-146-lru-cache_leetcode/)
    unordered_map<int, int> key_value_unmap;                  // store the data for key & value 
    unordered_map<int, list<int>::iterator> key_iter_unmap;   // store the data for key & stored-list iterator (the newer one would be in the beginning)
    list<int> key_list;                                       // store the data for key

    int _get(int key){
        int res = -1;
        if (key_value_unmap.count(key))
            res = key_value_unmap[key];
        else
            return res;

        // update the sequence of key&value
        key_list.erase(key_iter_unmap[key]);
        // key_iter_unmap.erase(key);
        key_list.insert(key_list.begin(), key);   // the newer one would be in the beginning
        // key_iter_unmap.insert(pair<int, list<int>::iterator>(key, key_list.begin()));   // record the storage position within the list container for new key 
        key_iter_unmap[key] = key_list.begin();

        return res;
    }

    void _put(int key, int value){
        if (key_value_unmap.count(key))
        {
            // KEY is exist
            // update the value
            key_value_unmap[key] = value;

            // update the sequence of key&value
            key_list.erase(key_iter_unmap[key]);
            // key_iter_unmap.erase(key);
            key_list.insert(key_list.begin(), key);   // the newer one would be in the beginning
            // key_iter_unmap.insert(pair<int, list<int>::iterator>(key, key_list.begin()));   // record the storage position within the list container for new key 
            key_iter_unmap[key] = key_list.begin();

        }else{
            // KEY is NOT exist
            if (key_value_unmap.size() >= max_cap)
            {
                // storage is FULL

                // remove the older key
                auto older_key = key_list.back();
                key_value_unmap.erase(older_key);

                // update the sequence of key&value
                key_list.pop_back();
                key_iter_unmap.erase(older_key);
            }

            // insert the new key
            key_value_unmap[key] = value;
            // key_value_unmap.insert(pair<int,int>(key, value));

            // update the sequence of key&value
            key_list.insert(key_list.begin(), key);   // the newer one would be in the beginning
            key_iter_unmap.insert(pair<int, list<int>::iterator>(key, key_list.begin()));   // record the storage position within the list container for new key 
        }
    }

public:

    // solution 1(keven, using map to store data with counter)
    int cmd_idx = 0;
    map<int, pair<int,int>> data_idx_keyvalue_map;   // main record appearance idx and data for each key&value (to order to data sequence)
    unordered_map<int, int> data_key_idx_unmap;         // record data for each key & appearance idx
    unordered_map<int, int> data_key_value_unmap;       // record data for each key & value
    int max_cap = 0;

    LRUCache(int capacity) {
        max_cap = capacity;
    }
    
    int get(int key) {
        int res = -1;

        // solution 0 (keven, best, refer https://haogroot.com/2021/01/31/lc-146-lru-cache_leetcode/)
        {
            return _get(key);
        }

        // // solution 1
        // {
        //     if (data_key_value_unmap.count(key))
        //         res = data_key_value_unmap[key];
        //     else
        //         return res;
            
        //     // update the order of key
        //     auto origin_idx = data_key_idx_unmap[key];
        //     data_key_idx_unmap.erase(key);
        //     data_idx_keyvalue_map.erase(origin_idx);

        //     cmd_idx++;
        //     data_idx_keyvalue_map.insert(pair<int, pair<int, int>>(cmd_idx, pair<int, int>(key, res)));
        //     data_key_idx_unmap.insert(pair<int,int>(key, cmd_idx));

        //     return res;
        // }
    }
    
    void put(int key, int value) {
        // solution 0 (keven, best, refer https://haogroot.com/2021/01/31/lc-146-lru-cache_leetcode/)
        {
            return _put(key, value);
        }
        
        // // solution 1
        // {
        //     if (data_key_value_unmap.count(key)){
        //         // CASE: REPLACE THE OLDER KEY

        //         data_key_value_unmap[key] = value;

        //         // update the order of key
        //         auto origin_idx = data_key_idx_unmap[key];
        //         data_key_idx_unmap.erase(key);
        //         data_idx_keyvalue_map.erase(origin_idx);

        //         cmd_idx++;               
        //         data_key_idx_unmap.insert(pair<int,int>(key, cmd_idx));
        //         data_idx_keyvalue_map.insert(pair<int, pair<int, int>>(cmd_idx, pair<int, int>(key, value)));
        //     }
        //     else{
        //         if (data_key_value_unmap.size() < max_cap)
        //         {
        //             // CASE: ADD NEW KEY
        //             data_key_value_unmap.insert(pair<int, int>(key, value));

        //             // update the order of key
        //             cmd_idx++;
        //             data_key_idx_unmap.insert(pair<int,int>(key, cmd_idx));
        //             data_idx_keyvalue_map.insert(pair<int, pair<int, int>>(cmd_idx, pair<int, int>(key, value)));
        //         }else{
        //             // CASE: OVER-FLOW
        //             // Remove the older one key and add newer

        //             // remove the older one
        //             // auto older_idx = data_idx_keyvalue_map.begin()->first;
        //             auto older_idx_key = data_idx_keyvalue_map.begin()->second.first;
        //             // auto older_idx_value = data_idx_keyvalue_map.begin()->second.second;
        //             // printf("the older idx:%d, key:%d, value:%d would be removed\n", older_idx, older_idx_key, older_idx_value);

        //             data_idx_keyvalue_map.erase(data_idx_keyvalue_map.begin());
        //             data_key_idx_unmap.erase(older_idx_key);
        //             data_key_value_unmap.erase(older_idx_key);

        //             // insert the newer one
        //             cmd_idx++;
        //             data_key_idx_unmap.insert(pair<int,int>(key, cmd_idx));
        //             data_idx_keyvalue_map.insert(pair<int, pair<int, int>>(cmd_idx, pair<int, int>(key, value)));
        //             data_key_value_unmap.insert(pair<int, int>(key, value));
        //         }
        //     }
            
        //     return;
        // }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void dbg_map_in_cache(LRUCache *cache){

    printf("-------- dbg_cache -------\n");
    printf("data_key_value_unmap >>> \n");
    for (auto single_map: cache->data_key_value_unmap)
        printf("[%d,%d],", single_map.first, single_map.second);
    printf("\n");

    printf("data_key_idx_unmap >>> \n");
    for (auto single_map : cache->data_key_idx_unmap)
        printf("[key:%d,idx:%d],", single_map.first, single_map.second);
    printf("\n");
    
    printf("data_idx_keyvalue_map >>> \n");
    for (auto single_map : cache->data_idx_keyvalue_map)
        printf("[(idx:%d)key:%d,value:%d],", single_map.first, single_map.second.first, single_map.second.second);
    printf("\n");
    
    printf("---------------------------\n");
    
}

int main()
{
    std::cout << "Hello LeetCode - LRU Cache, DataStructure(Queue)!\n";
    cout << "https://leetcode.com/problems/lru-cache/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: [\"LRUCache\", \"put\", \"put\", \"get\", \"put\", \"get\", \"put\", \"get\", \"get\", \"get\"]\n");
    printf("       [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]\n");
    printf("expected output: [null, null, null, 1, null, -1, null, -1, 3, 4]\n");
    printf("Explanation >>> \n");
    {
        
        LRUCache *lRUCache = new LRUCache(2);
        int res = 0;

        lRUCache->put(1, 1); // cache is {1=1}
        printf("1st->put(1,1)\n");
        // dbg_map_in_cache(lRUCache);

        lRUCache->put(2, 2); // cache is {1=1, 2=2}
        printf("2nd->put(2,2)\n");
        // dbg_map_in_cache(lRUCache);

        res = lRUCache->get(1);    // return 1
        printf("3rd->get(1):%d\n", res);
        // dbg_map_in_cache(lRUCache);

        lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        printf("4th->put(3,3)\n");
        // dbg_map_in_cache(lRUCache);

        res = lRUCache->get(2);    // returns -1 (not found)
        printf("5th->get(2):%d\n", res);
        // dbg_map_in_cache(lRUCache);

        lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        printf("6th->put(4,4)\n");
        // dbg_map_in_cache(lRUCache);

        res = lRUCache->get(1);    // return -1 (not found)
        printf("7th->get(1):%d\n", res);
        // dbg_map_in_cache(lRUCache);

        res = lRUCache->get(3);    // return 3
        printf("8th->get(3):%d\n", res);
        // dbg_map_in_cache(lRUCache);

        res = lRUCache->get(4);    // return 4
        printf("9th->get(4):%d\n", res);
        // dbg_map_in_cache(lRUCache);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: [\"LRUCache\", \"put\", \"put\", \"put\", \"put\", \"get\", \"get\"]\n");
    printf("       [[2], [2,1], [1,1], [2,3], [4,1], [1], [2]]\n");
    printf("expected output: [null, null, null, null, null, -1, 3]\n");
    printf("Explanation >>> \n");
    {
        
        LRUCache *lRUCache = new LRUCache(2);
        int res = 0;

        lRUCache->put(2, 1); // cache is {2=1}
        printf("1st->put(2,1)\n");
        // dbg_map_in_cache(lRUCache);

        lRUCache->put(1, 1); // cache is {2=1, 1=1}
        printf("2nd->put(1,1)\n");
        // dbg_map_in_cache(lRUCache);

        lRUCache->put(2, 3); // LRU key was 2, evicts key 2, cache is {1=1, 2=3}
        printf("3rd->put(2,3)\n");
        // dbg_map_in_cache(lRUCache);

        lRUCache->put(4, 1); // LRU key was 1, evicts key 1, cache is {2=3, 4=1}
        printf("4th->put(4,1)\n");
        // dbg_map_in_cache(lRUCache);

        res = lRUCache->get(1);    // return -1 (not found)
        printf("5th->get(1):%d\n", res);
        // dbg_map_in_cache(lRUCache);

        res = lRUCache->get(2);    // return 3, cache is {4=1, 2=3}
        printf("6th->get(2):%d\n", res);
        // dbg_map_in_cache(lRUCache);
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
