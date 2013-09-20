#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
		int longestConsecutive(vector<int> &num){
			if(num.size() == 1){
				return 1;
			}
			int max_length = 0;
			int current_length = 0;
			sort(num.begin(), num.end());
			for(int i = 1; i < num.size(); ++i){
				if(num[i] == num[i - 1] + 1){
					++current_length;
					if(current_length > max_length){
						max_length = current_length;
					}
				}else{
					if(num[i] != num[i - 1])
						current_length = 0;
				}
			}
			return max_length + 1;
			return 0;
		}
};

int main(){
	vector<int> vec;
	int n, input;
	cin>>n;
	for(int i = 0; i < n; ++i){
		cin>>input;
		vec.push_back(input);
	}
	Solution solution;
	cout<<solution.longestConsecutive(vec)<<endl;
	return 0;
}
