/*
 *Author:alvin
 *Title:Search a 2D Matrix
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		bool searchMatrix(vector<vector<int> > &matrix, int target){
			for(int i = 0; i < matrix.size(); ++i){
				if(target >= matrix[i][0] && target <= matrix[i][matrix[i].size() - 1]){
					int result = binarySearch(matrix[i], 0, matrix[i].size() - 1, target);
					if(result < 0){
						return false;
					}else{
						return true;
					}
				}
			}
			return false;
		}
	private:
		int binarySearch(vector<int> &matrix, int start, int end, int target){
			while(start <= end){
				int mid = start + end;
				if(matrix[mid] == target){
					return mid;
				}else{
					if(matrix[mid] < target){
						start = mid + 1;
					}else{
						end = mid - 1;
					}
				}
			}
			return -1;
		}
};

int main(){
	int n, m;
	cin>>n>>m;
	vector<vector<int> > vec;
	int input;
	int target;
	for(int i = 0; i < n; ++i){
		vector<int> inputVec;
		for(int j = 0; j < m; ++j){
			cin>>input;
			inputVec.push_back(input);
		}
		vec.push_back(inputVec);
	}
	cin>>target;
	Solution solution;
	cout<<solution.searchMatrix(vec, target)<<endl;
	return 0;
}
