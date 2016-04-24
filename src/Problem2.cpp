/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};
int is_BST(struct node*root)
{
	if (root == NULL)
		return NULL;
	struct node*temp = NULL;
	if (root)
	{
		if (is_BST(root->left)!=1)
		{
			return 0;
		}
		if (temp != NULL&&root->data <= temp->data)
			return 0;
		temp = root;
		return is_BST(root->right);
	}
	return 1;
}
int nodeCountDLL(struct node_dll*head)
{
	struct node_dll *temp = head;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp -> next;
	}
	return count;
}
int nodeCountBST(struct node*root)
{
	struct node*temp = root;
	int c1 = 0, c2 = 0;
	if (root == NULL)
		return 0;
	else
	{
		c1 = nodeCountBST(root->left);
		c2 = nodeCountBST(root->right);
		return 1+(c1 + c2);
	}
}
int node_sum_DLL(struct node_dll*head)
{
	struct node_dll*temp = head;
	int sum = 0;
	while (temp != NULL)
	{
		sum = sum + temp->data;
		temp = temp->next;
	}
	return sum;
}
int node_sum_BST(struct node*root)
{
	int sum = 0, leftsum, rightsum;
	if (root == NULL)
	{
		sum = 0;
		return sum;
	}
	else
	{
		leftsum = node_sum_BST(root->left);
		rightsum = node_sum_BST(root->right);
		sum = root->data + leftsum + rightsum;
		return sum;
	}
}
int is_identical(struct node_dll *head, struct node *root){
	struct node_dll*dlltemp = head;
	int dll_count = (nodeCountDLL(head));
	int bst_count = (nodeCountBST(root));
	int dll_sum = (node_sum_DLL(head));
	int bst_sum = (node_sum_BST(root));
	if (head==NULL||root==NULL)
	return -1;
	if (is_BST(root)==1)
	{
		if ((dll_count == bst_count) && (dll_sum == bst_sum))
			return 1;
		else
			return 0;
	}
	else
		return 0;
}