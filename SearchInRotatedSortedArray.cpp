/*
 *Author:alvin
 *Title Search in Rotated Sorted Array in log(n)
 */ 
#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		int search(int A[], int n, int target){
			return binarySearch(A, 0, n - 1, target);
		}

		int binarySearch(int* array, int start, int end, int target){
			if(start + 1 == end || start == end){
				if(array[start] == target){
					return start;
				}else
				if(array[end] == target){
					return end;
				}
				else{
					return -1;
				}
			}
			int mid = (start + end) / 2;
			if(array[mid] == target){
				return mid;
			}else{
				if(array[mid] > array[start]){
					if(target >= array[start] && target < array[mid]){
						return binarySearch(array, start, mid - 1, target);
					}else{
						return binarySearch(array, mid + 1, end, target);
					}
				}else{
					if(target > array[mid] && target <= array[end]){
						return binarySearch(array, mid + 1, end, target);
					}else{
						return binarySearch(array, start, mid - 1, target);
					}
				}
			}

		}
};

int main(){
	Solution solution;
	int array[100000], n, target;
	cin>>n;
	for(int i = 0; i < n; ++i){
		cin>>array[i];
	}
	cin>>target;
	cout<<solution.search(array, n, target)<<endl;
	return 0;
}

