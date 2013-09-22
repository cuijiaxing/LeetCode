/*
 *author:alvin
 *title:power(x, n)
 */
#include<iostream>
#include<cmath>
using namespace std;
class Solution{
	public:
		double pow(double x, int n){
			return std::pow(x, n);
		}
};

int main(){
	Solution s;
	cout<<s.pow(8.88023, 3);
	return 0;
}
