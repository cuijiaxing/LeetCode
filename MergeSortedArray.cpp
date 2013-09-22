/*
 *author:alvin
 *title:Merge sorted array
 */
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
	if(n == 0){
		return ;
	}
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	memcpy(A + m, B, sizeof(int) * n);
	std::sort(A, A + m + n);
    }
};

int main(){

	int A[] = {1, 2, 3};
	int B[] = {2 ,5, 6};
	Solution solution;
	solution.merge(A, 3, B, 3);
	return 0;
}
