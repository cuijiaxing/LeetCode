/*
 *Author: Alvin
 *Title:Best Time to Buy and Sell Stock II
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
			int last_price = prices[0];
			int max_price = 0;
			int profit = 0;
			bool shouldAdd = false;
			for(int i = 1;i < prices.size(); ++i){
				if(prices[i] > prices[i - 1]){
					max_price = prices[i];
					if(i == prices.size() - 1){
						shouldAdd = true;
					}
				}else{
					if(max_price > last_price){
						profit += max_price - last_price;
					}
					last_price = prices[i];
					max_price = prices[i];
				}
			}
			if(shouldAdd && max_price > last_price){
				profit += max_price - last_price;
			}
			return profit;
		}
};

int main(){
	int n, input;
	cin>>n;
	vector<int> vec;
	for(int i = 0;i < n; ++i){
		cin>>input;
		vec.push_back(input);
	}
	Solution solution;
	cout<<solution.maxProfit(vec)<<endl;
	return 0;
}
