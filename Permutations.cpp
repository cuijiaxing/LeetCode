/*
 *author:alvin
 *title:permutations
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
	public:
	    vector<vector<int> > permute(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > resultVec;
		sort(num.begin(), num.end());
		do{
			resultVec.push_back(num);
		}while(next_permutation(num.begin(), num.end()));
		return resultVec;
	    }
};

int main(){
	Solution solution;
	int n;
	cin>>n;
	vector<int> inputVec;
	for(int i = 1; i <= n; ++i){
		inputVec.push_back(i);
	}
	cout<<solution.permute(inputVec).size();
	return 0;
}
