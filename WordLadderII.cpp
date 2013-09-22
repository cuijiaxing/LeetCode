/*
 *Author:alvin
 *Title:Word Ladder II
 */

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<unordered_set>
#include<string.h>
#include<algorithm>
using namespace std;

class Solution{
	public:
		int length;
		vector<int> matrix[3000];
		int visited[3000];
		int dis[3000];
		int element_num;
		vector<string> strVec;
		Solution(){
			length = 0 ;
			memset(visited, 0, sizeof(visited));
			memset(dis, 0, sizeof(dis));
		}
		vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict){
			//initialize variable
			length = start.size();
			memset(visited, 0, sizeof(visited));
			memset(dis, 0, sizeof(dis));
			strVec.clear();

			element_num = dict.size() + 2;
			strVec.push_back(start);
			for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it){
					strVec.push_back(*it);
			}
			strVec.push_back(end);

			//construct adjacent table
			for(int i = 0; i < strVec.size(); ++i){
				for(int j = i + 1; j < strVec.size(); ++j){
					if(i != j){
						if(calculateDiff(strVec[i], strVec[j], length)){
							matrix[j].push_back(i);
							matrix[i].push_back(j);
						}
					}
				}
			}
			
			
			int minimum = dijkstraPath(0, strVec.size() - 1);//calculate minimum path
			if(minimum == 0){
				vector<vector<string>> trivialVector;
				vector<string> trivialStrVector;
				trivialVector.push_back(trivialStrVector);
				return trivialVector;
			}
			vector<vector<int> > resultVec_g;
			vector<int> initVec;
			initVec.push_back(strVec.size() - 1);
			resultVec_g.push_back(initVec);
			findResult(resultVec_g, 0, minimum - 1);
			vector<vector<string> > resultVec_s;
			for(int i = 0; i < resultVec_g.size(); ++i){
				vector<string> sVec;
				for(int j = resultVec_g[i].size() -1 ; j >= 0; --j){
					sVec.push_back(strVec[resultVec_g[i][j]]);
				}
				resultVec_s.push_back(sVec);
			}
			return resultVec_s;
		}

	private:

		int nodeConnected(int index, int des){
			for(int i = 0; i < matrix[index].size(); ++i){
				if(matrix[index][i] == des){
					return i;
				}
			}
			return -1;
		}
		int calculateDiff(string src, string input, int len){
			int count = 0;
			for(int i = 0; i < len; ++i){
				if(src[i] != input[i]){
					++count;
					if(count > 1){
						return 0;
					}
				}
			}
			if(count == 1){
				return 1;
			}else{//count == 0
				return 0;
			}
		}
		
		int dijkstraPath(int start, int end){
			visited[start] == 1;
			int minValue = 0xFFFFFF;
			int minIndex = -1;
			
			for(int i = 0; i < matrix[start].size(); ++i){
				dis[matrix[start][i]] = 1;
			}

			for(int i = 0; i < element_num; ++i){
				minValue = 0xFFFFFF;
				for(int j = 0; j < element_num; ++j){
					if(!visited[j] && dis[j] && minValue > dis[j]){
						minValue = dis[j];
						minIndex = j;
					}
				}
				visited[minIndex] = 1;
				for(int j = 0; j < matrix[minIndex].size(); ++j){
					int index = matrix[minIndex][j];
					if(!visited[index] && (dis[index] > dis[minIndex] + 1 || dis[index] == 0)){
						dis[index] = dis[minIndex] + 1;
					}
				}
			}
			return dis[strVec.size() - 1];;
		}

		void duplicateVector(vector<vector<int> > &totalVec, vector<int> &src, vector<int> &increment){
			for(int i = 0; i < increment.size(); ++i){
				vector<int> temp = src;
				temp.push_back(increment[i]);
				totalVec.push_back(temp);
			}
		}

		void findResult(vector<vector<int> > &startVec, int end, int minimum){
			if(minimum == 0){
				for(int i = 0; i < startVec.size(); ++i){
					startVec[i].push_back(end);
				}
				return;
			}
			vector<vector<int> > tempStartVec = startVec;
			startVec.clear();
			for(int i = 0; i < tempStartVec.size(); ++i){
				int prevIndex = tempStartVec[i][tempStartVec[i].size() - 1];
				vector<int> tempIndexVec;
				for(int j = 0; j < matrix[prevIndex].size(); ++j){
					if(dis[matrix[prevIndex][j]] == minimum){
						tempIndexVec.push_back(matrix[prevIndex][j]);
					}
				}
				duplicateVector(startVec, tempStartVec[i], tempIndexVec);
			}
			findResult(startVec, end, minimum - 1);
		}
};

int main(){
	string startStr, endStr;
	int dictSize;
	string inputStr;
	cin>>startStr>>endStr;
	cin>>dictSize;
	unordered_set<string> dict;
	for(int i = 0; i < dictSize; ++i){
		cin>>inputStr;
		dict.insert(inputStr);
	}

	Solution solution;
	vector<vector<string> > vec = solution.findLadders(startStr, endStr, dict);
	for(int i = 0; i < vec.size(); ++i){
		for(int j = 0; j < vec[i].size(); ++j){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}















