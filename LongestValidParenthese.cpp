#include<iostream>
#include<string>
#include<string.h>
#include<stack>
using namespace std;
class Solution{
	public:

		int length[100000];
		int longestValidParenthese(string s){
			memset(length, 0, sizeof(length));
			//find the first that is '('
			for(int i = 0; i < s.size(); ++i){
				if('(' == s.at(i)){
					length[i] = 0;
				}else{
					for(int j = i - 1; j >= 0; --j){
						if(s.at(j) == '(' && length[j] == 0){
							length[j] = 1;
							length[i] = 1;
							break;
						}
					}
				}
			}
			return countSeparete(s.size());
		}

	private:
		int countSeparete(int len){
			int maxLength = 0, currentLength = 0;
			for(int i = 0; i < len; ++i){
				if(length[i] == 1){
					++currentLength;
					if(currentLength > maxLength){
						maxLength = currentLength;
					}
				}else{
					currentLength = 0;
				}
			}
			return maxLength;
		}
};

int main(){
	string str;
	Solution s;
	cin>>str;
	cout<<s.longestValidParenthese(str)<<endl;
	return 0;

}
