/*
 *Author: Alvin
 *Title: Best time to Buy and Sell Stock
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		int maxProfit(vector<int> &prices){
			if(prices.size() < 2){
				return 0;
			}
			int current_profit = 0;
			int max_profit = 0;
			for(int i = 1; i < prices.size(); ++i){
				if(prices[i] > prices[i - 1] || current_profit + prices[i] - prices[i - 1] >= 0){
					current_profit += prices[i] - prices[i - 1];
					if(current_profit > max_profit){
						max_profit = current_profit;
					}
				}else{
					current_profit = 0;
				}
			}
			return max_profit;

		}
};

int main(){
	int n, input;
	vector<int> vec;
	cin>>n;
	for(int i = 0; i < n; ++i){
		cin>>input;
		vec.push_back(input);
	}
	Solution solution;
	cout<<solution.maxProfit(vec)<<endl;
	return 0;
}
