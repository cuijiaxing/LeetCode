/*
 *Author:alvin
 *Title: Maximum Depth of Binary Tree
 */
#include<iostream>
#include<queue>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
	public:
		int maxDepth(TreeNode* root){
			if(root == NULL){
				return 0;
			}
			return bfs(root);
		}

	private:

		int bfs(TreeNode* root){
			queue<TreeNode*> q;
			int depth = 0;
			TreeNode* flagNode = NULL;
			q.push(root);
			q.push(flagNode);
			TreeNode* tempNode = NULL;
			while(!q.empty()){
				tempNode = q.front();
				q.pop();
				if(tempNode == NULL ){
					++depth;
					if(!q.empty()){
						q.push(flagNode);
					}
				}else{
					if(tempNode->left != NULL){
						q.push(tempNode->left);
					}
					if(tempNode->right != NULL){
						q.push(tempNode->right);
					}
				}
			}
			return depth;
		}
};

