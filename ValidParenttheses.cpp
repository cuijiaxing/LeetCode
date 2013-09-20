/*
 *Author:Alvin
 *Title:Valid Parentheses
 */
#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution{
	private:
		static const int ARRAY_LENGTH = 3;
		char validLeftChar[ARRAY_LENGTH];
		char validRightChar[ARRAY_LENGTH];
		int findIndex(char c){
			for(int i = 0; i < ARRAY_LENGTH; ++i){
				if(validRightChar[i] == c){
					return i;
				}
			}
		}
	public:
		Solution(){
			validLeftChar[0] = '(';
		        validLeftChar[1] = '{';
		       	validLeftChar[2] = '[';

			validRightChar[0] = ')';
		       	validRightChar[1] = '}';
		       	validRightChar[2] = ']';
		}
		bool isValid(string s){
			stack<char> sta;
			for(int i = 0; i < s.length(); ++i){
				if(sta.empty()){
					sta.push(s.at(i));
				}else{
					int j = 0;
					for(j = 0; j < ARRAY_LENGTH; ++j){
						if(s.at(i) == validLeftChar[j]){
							sta.push(s.at(i));
							break;
						}
					}
					if(j == ARRAY_LENGTH){
						int index = findIndex(s.at(i));
						if(sta.top() == validLeftChar[index]){
							sta.pop();
						}else{
							return false;
						}
					}
				}

			}
			if(sta.empty()){
				return true;
			}else{
				return false;
			}

		}
};

int main(){
	string s;
	Solution solution;
	cin>>s;
	cout<<solution.isValid(s)<<endl;
	return 0;
}
