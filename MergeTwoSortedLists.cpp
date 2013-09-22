/*
 *Author:alvin
 *Title: Merge Two Sorted Lists
 */
#include<malloc.h>
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};
class Solution{
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
			struct ListNode* prevNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			prevNode->next = NULL;
			struct ListNode* recordNode = prevNode;
			bool head = true;
			while(l1 != NULL && l2 != NULL){
				if(l1->val > l2->val){
					prevNode->next = l2;
					l2 = l2->next;
				}else{
					prevNode->next = l1;
					l1 = l1->next;
				}
				prevNode = prevNode->next;
			}
			while(l1 != NULL){
				prevNode->next = l1;
				prevNode = prevNode->next;
				l1 = l1->next;
			}
			while(l2 != NULL){
				prevNode->next = l2;
				prevNode = prevNode->next;
				l2 = l2->next;
			}
			return recordNode->next;
		}
};
