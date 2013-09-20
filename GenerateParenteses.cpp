/*
 *Author:alvin
 *Title:Generate Parenteses
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
	vector<string> emptyVec;//always empty
	public:
		Solution(){
			emptyVec.push_back("");
		}
		vector<string> generateParenthesis(int n){
			return generate(n);
		}
	private:
		vector<string>  generate(int interval){
			if(interval == 0){
				return emptyVec;
			}
			vector<string> vec;
			for(int i = 0; i < interval; ++i){
				vector<string> tempLeft = generate(i);
				vector<string> tempRight;
				if(interval - i - 1 >= 0){
			       		tempRight = generate(interval - i - 1);
				}
				for(int j = 0; j < tempLeft.size(); ++j){
					for(int k = 0; k < tempRight.size(); ++k){
						vec.push_back("(" + tempLeft[j] + ")" + tempRight[k]);
					}
				}		
			}
			return vec;
		}


};

int main(){
	int n;
	cin>>n;
	Solution solution;
	vector<string> vec = solution.generateParenthesis(n);
	for(int i = 0; i < vec.size(); ++i){
		cout<<vec[i]<<"\t";
	}
	cout<<endl;
	return 0;
}
