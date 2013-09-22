/*
 *author:alvin
 *title:Sum root to leaf
 */

/**
 * Definition for binary tree
 */
#include<iostream>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int total;
	int sumNumbers(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		total = 0;
		sumThemUp(root, 0);
		return total;
	}

	void sumThemUp(TreeNode* start, int currentNum){
		if(start == NULL){
			total += currentNum;
		}else{
			currentNum = currentNum * 10 + start->val;
			if(start->left && start->right){
				sumThemUp(start->left, currentNum);
				sumThemUp(start->right, currentNum);
			}else{
				if(start->left){
					sumThemUp(start->left, currentNum);

				}else{
					sumThemUp(start->right, currentNum);
				}
			}
		}
	}

    
};
