/*
 * You are given an array prices where prices[i] is the price of
 * a given stock on the ith day.
 * 
 * You want to maximize your profit by choosing a single day to
 * buy one stock and choosing a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction.
 * If you cannot achieve any profit, return 0. 
 * 
 * Example 1:
 * 
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6),
 * profit = 6-1 = 5. Note that buying on day 2 and selling on day 1 is
 * not allowed because you must buy before you sell.
 * 
 * Example 2:
 * 
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit = 0.
 */

#include <cassert>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
        int maxProfit(vector<int>& prices) {
                int lowest_price = INT_MAX;
                int max_profit = 0;
                for (int i = 0, sz = prices.size(); i < sz; ++i) {
                        if (prices[i] < lowest_price)
                                lowest_price = prices[i];
                        else if (max_profit < prices[i] - lowest_price)
                                max_profit = prices[i] - lowest_price;
                }
                return max_profit;
        }
};

int main() {
        vector<int> prices1 = { 1, 2, 3, 4, 1 };
        vector<int> prices2 = { 3, 2, 1 };

        Solution solution;
        assert(solution.maxProfit(prices1) == 3);
        assert(solution.maxProfit(prices2) == 0);
        return 0;
}