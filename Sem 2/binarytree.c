#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node-> data =data;
	node-> left = NULL;
	node-> right = NULL;
	return(node);

}

void printPreorder(struct node* node)
{
	if(node == NULL)
	return;
	printf("%d ",node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}
void printInorder(struct node* node)
{
	if(node  == NULL)
	return;
	printInorder(node->left);
	printf("%d ",node->data);
	printInorder(node->right);
}
void printPostorder(struct node* node)
{
	if(node == NULL)
	return;
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d ",node->data);
}

int main()
{
	int n,ch,a[7],loop=1;
	for(int i=0;i<7;i++)
	{
		printf("\nEnter %d element:",i);
		scanf("%d",&a[i]);
	}
	struct node *root = newNode(a[0]);
	root->left = newNode(a[1]);
	root->right = newNode(a[2]);
	root->left->left=newNode(a[3]);
	root->left->right=newNode(a[4]);
	root->right->left=newNode(a[5]);
	root->right->right=newNode(a[6]);
while(loop==1)
{
    printf("\n 1)preorder traversal 2)Inorder traversal 3)Postorder traversal 4)exit");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printPreorder(root);
		break;
		case 2:
		printInorder(root);
		break;
		case 3:
		printPostorder(root);
		break;
		case 4:
        loop=0;
        break;
		default:
		printf("enter the correct value");
	}
}
	return 0;
}
