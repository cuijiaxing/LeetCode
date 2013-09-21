/*
 *Author:alvin
 *Title:Balanced Binary Tree
 */
#include<iostream>
#include<math.h>
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
	public:
		bool isBalanced(TreeNode* root){
			if(nodeDepth(root) >= 0){
				return true;
			}else{
				return false;
			}
		}

		int nodeDepth(TreeNode* node){
			if(node == NULL){
				return 0;
			}
			int depthLeft = nodeDepth(node->left);
			int depthRight = nodeDepth(node->right);
			if(depthLeft < 0 || depthRight < 0){
				return -1;
			}
			if(isEqualDepth(depthLeft, depthRight)){
				return max_two(depthLeft, depthRight) + 1;
			}else{
				return -1;
			}
		}

	private:
		bool isEqualDepth(int left, int right){
			int diff = left - right;
			if(diff == 0 || diff == -1 || diff == 1){
				return true;
			}else{
				return false;
			}
		}
		int max_two(int x, int y){
			if(x < y){
				return y;
			}else{
				return x;
			}
		}


};
