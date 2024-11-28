// ConsoleApplication_Online_Stock_Span.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
private:
    typedef struct{
        int cur_price;
        int cur_price_span_count;
    }_price_span;

    stack<_price_span> monotonic_st;

    int next_monotonic(int price){
        
        int span_count = 0;        
        while (!monotonic_st.empty() && price >= monotonic_st.top().cur_price)
        {
            // current input price is bigger than last-input price
            // printf("price:%d, top().price:%d, top().span:%d, final_span_count:%d\n", price, monotonic_st.top().cur_price, monotonic_st.top().cur_price_span_count, span_count);
            span_count += monotonic_st.top().cur_price_span_count;
            monotonic_st.pop();
        }
        
        _price_span price_span;
        price_span.cur_price = price;

        price_span.cur_price_span_count = (span_count > 0) ? span_count + 1 : 1;  // must including itself, so need +1

        monotonic_st.push(price_span);

        return price_span.cur_price_span_count;
    }

public: 

    // for solution 0-0
    stack<pair<int, int>> num_meetcount_stack;   //key: num  value: the total-element-count of "smaller or equal" in front of num

    // for solution 0-1
    vector<int> num_vec;
    int last_res;

    // for solution 1
    stack<int> num_stack;   

    
    StockSpanner() {
        last_res = 0;
    }
    
    int next(int price) {

        // solution 0 (keven, best solution, use monotonic stack to solve)
        {
            return next_monotonic(price);
        }

        // solution 0-0 (best, reference others and use stack to solve)
        {
            int res = 0;
            if (num_meetcount_stack.size())
            {
                while (num_meetcount_stack.top().first <= price)
                {
                    res += num_meetcount_stack.top().second;  // the counts of top means in front of num, there will be a counts of "smaller or equal" elements exist
                    num_meetcount_stack.pop();

                    if (num_meetcount_stack.size() == 0)
                    {
                        break;
                    }
                }
            }
            
            res+=1;
            num_meetcount_stack.push(pair<int,int>(price, res));

            return res;
        }

        // solution 1 (keven, using array to solve)
        {
            int res = 0;
            if (num_vec.size() == 0)
            {
                num_vec.push_back(price);
                res = 1;
                last_res = res;
                return res;         // itselve
            }
            
            // add performance
            if (price == num_vec[num_vec.size() - 1])
            {
                num_vec.push_back(price);
                last_res++;
                res = last_res;
                return res;
            }
            
            for (int i = num_vec.size() - 1; i >= 0; i--)
            {
                // printf("on-stock[%d]:%d, price:%d\n", i, num_vec[i], price);
                if (num_vec[i] > price)   // the stock value is bigger than current price
                {
                    break;
                }

                res++;
            }
            
            // printf("after search, current res:%d\n", res);
            res += 1;    // add itselve
            last_res = res;
            // printf("final res:%d\n", res);
            num_vec.push_back(price);

            return res;
        }

        // solution 1 (keven, Time Limit Exceed, using stack to solve)
        {
            stack<int> tmp_num_stack;
            int res = 0;
            while (num_stack.size())
            {
                auto top_num = num_stack.top();
                if (price < top_num)
                {
                    // means no consective-price exist from now price
                    break;
                }
                else
                {
                    res++;
                    tmp_num_stack.push(top_num);
                }
                
                num_stack.pop();
            }
            
            // restore the num_stack
            while (tmp_num_stack.size())
            {
                num_stack.push(tmp_num_stack.top());
                tmp_num_stack.pop();
            }
            
            res += 1;    // including itself
            num_stack.push(price);

            return res;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main()
{
    std::cout << "Hello LeetCode - Online Stock Span, DataStructure(stock)!\n";
    cout << "https://leetcode.com/problems/online-stock-span/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: [\"StockSpanner\", \"next\", \"next\", \"next\", \"next\", \"next\", \"next\", \"next\"], [[], [100], [80], [60], [70], [60], [75], [85]]\n");
    printf("expected result: output = [null, 1, 1, 1, 2, 1, 4, 6]\n");
    printf("StockSpanner stockSpanner = new StockSpanner();\n");
    printf("stockSpanner.next(100); // return 1\n");
    printf("stockSpanner.next(80);  // return 1\n");
    printf("stockSpanner.next(60);  // return 1\n");
    printf("stockSpanner.next(70);  // return 2\n");
    printf("stockSpanner.next(60);  // return 1\n");
    printf("stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.\n");
    printf("stockSpanner.next(85);  // return 6\n");
    {
        StockSpanner stockSpanner;
        int res = 0;

        res = stockSpanner.next(100);
        printf("next 100, res:%d\n", res);
        res = stockSpanner.next(80);
        printf("next 80, res:%d\n", res);
        res = stockSpanner.next(60);
        printf("next 60, res:%d\n", res);
        res = stockSpanner.next(70);
        printf("next 70, res:%d\n", res);
        res = stockSpanner.next(60);
        printf("next 60, res:%d\n", res);
        res = stockSpanner.next(75);
        printf("next 75, res:%d\n", res);
        res = stockSpanner.next(85);
        printf("next 85, res:%d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: [\"StockSpanner\", \"next\", \"next\", \"next\", \"next\", \"next\"], [[], [7], [2], [1], [2], [2]]\n");
    printf("expected result: output = [null, 1, 1, 1, 3, 4]\n");
    printf("StockSpanner stockSpanner = new StockSpanner();\n");
    printf("stockSpanner.next(7); // return 1\n");
    printf("stockSpanner.next(2);  // return 1\n");
    printf("stockSpanner.next(1);  // return 1\n");
    printf("stockSpanner.next(2);  // return 3\n");
    printf("stockSpanner.next(2);  // return 4\n");
    {
        StockSpanner stockSpanner;
        int res = 0;

        res = stockSpanner.next(7);
        printf("next 7, res:%d\n", res);
        res = stockSpanner.next(2);
        printf("next 2, res:%d\n", res);
        res = stockSpanner.next(1);
        printf("next 1, res:%d\n", res);
        res = stockSpanner.next(2);
        printf("next 2, res:%d\n", res);
        res = stockSpanner.next(2);
        printf("next 2, res:%d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: [\"StockSpanner\", \"next\", \"next\", \"next\", \"next\", \"next\", \"next\", \"next\"], [[], [7], [34], [1], [2], [8]\n");
    printf("expected result: output = [null, 1, 2, 1, 2, 3]\n");
    printf("StockSpanner stockSpanner = new StockSpanner();\n");
    printf("stockSpanner.next(7); // return 1\n");
    printf("stockSpanner.next(34);  // return 2\n");
    printf("stockSpanner.next(1);  // return 1\n");
    printf("stockSpanner.next(2);  // return 2\n");
    printf("stockSpanner.next(8);  // return 3\n");
    {
        StockSpanner stockSpanner;
        int res = 0;

        res = stockSpanner.next(7);
        printf("next 7, res:%d\n", res);
        
        res = stockSpanner.next(34);
        printf("next 34, res:%d\n", res);

        res = stockSpanner.next(1);
        printf("next 1, res:%d\n", res);

        res = stockSpanner.next(2);
        printf("next 2, res:%d\n", res);

        res = stockSpanner.next(8);
        printf("next 8, res:%d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: [\"StockSpanner\",\"next\",\"next\",\"next\",\"next\",\"next\",\"next\",\"next\"], [[],[10],[5],[4],[6],[5],[5],[6]\n");
    printf("expected result: output = [null,1,1,1,3,1,2,6]\n");
    printf("StockSpanner stockSpanner = new StockSpanner();\n");
    printf("stockSpanner.next(10); // return 1\n");
    printf("stockSpanner.next(5);  // return 1\n");
    printf("stockSpanner.next(4);  // return 1\n");
    printf("stockSpanner.next(6);  // return 3\n");
    printf("stockSpanner.next(5);  // return 1\n");
    printf("stockSpanner.next(5);  // return 2\n");
    printf("stockSpanner.next(6);  // return 6\n");
    {
        StockSpanner stockSpanner;
        int res = 0;

        res = stockSpanner.next(10);
        printf("next 10, res:%d\n", res);
        
        res = stockSpanner.next(5);
        printf("next 5, res:%d\n", res);

        res = stockSpanner.next(4);
        printf("next 4, res:%d\n", res);

        res = stockSpanner.next(6);
        printf("next 6, res:%d\n", res);

        res = stockSpanner.next(5);
        printf("next 5, res:%d\n", res);

        res = stockSpanner.next(5);
        printf("next 5, res:%d\n", res);

        res = stockSpanner.next(6);
        printf("next 6, res:%d\n", res);
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
