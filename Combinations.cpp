/*
 *Author:Alvin
 *Title:Combinations
 */
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution{
	public:
		vector<vector<int> > combine(int n, int k){
			vector<vector<int> > se =  generate(1, n, k);
			for(int i = 0; i < se.size(); ++i){
				sort(se[i].begin(), se[i].end());
			}
			return se;
		}

		vector<vector<int> > generate(int begin, int end, int num){
			if(num == 0 || end - begin + 1 < num){
				vector<vector<int> > ve;
				vector<int> v;
				ve.push_back(v);
				return ve;
			}
			if(end - begin + 1 == num){
				vector<vector<int> > vec;
				vector<int> linearVec;
				for(int i = begin; i <= end; ++i){
					linearVec.push_back(i);
				}
				vec.push_back(linearVec);
				return vec;
			}else{
				vector<vector<int> > currentVec;
				vector<vector<int> > tempVec = generate(begin + 1, end, num - 1);
				for(int i = 0; i < tempVec.size(); ++i){
					tempVec[i].push_back(begin);
					currentVec.push_back(tempVec[i]);
				}
				tempVec = generate(begin + 1, end, num);
				for(int i = 0; i < tempVec.size(); ++i){
					currentVec.push_back(tempVec[i]);
				}
				return currentVec;
			}
		}
};

int main(){
	int n, k;
	cin>>n>>k;
	Solution solution;
	vector<vector<int> > vec = solution.combine(n, k);
	for(int i = 0; i < vec.size(); ++i){
		for(int j = 0; j < vec[i].size(); ++j){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
