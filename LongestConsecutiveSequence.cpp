/*
 *Author:Alvin
 *Title LongestConsecutiveSequence
 */
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string.h>
using namespace std;

class Solution{
	public:
		int visited[100000];
		int longestConsecutive(vector<int> &num){
			unordered_map<int, int> indexMap;
			memset(visited, 0, sizeof(visited));
			for(int i = 0; i < num.size(); ++i){
				indexMap[num[i]] = i;
			}
			int max = 0;
			for(int i = 0; i < num.size(); ++i){
				if(!visited[i]){
					int desc = num[i] -1;
					int asc = num[i] + 1;
					int count = 0;
					unordered_map<int, int>::iterator it;
					while(1){
						it = indexMap.find(desc);

						if(it != indexMap.end()){
							visited[it->second] = 1;
						}else{
							break;
						}
						--desc;
						++count;
					}
					while(1){
						it = indexMap.find(asc);
						if(it != indexMap.end()){
							visited[it->second] = 1;
						}else{
							break;
						}
						++asc;
						++count;

					}
					if(count > max){
						max = count;
					}
				}
			}


			return max + 1;

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
