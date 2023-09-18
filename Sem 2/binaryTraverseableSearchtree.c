#include <stdio.h>
#include <stdlib.h>
//#define NOMINMAX
//#include <windows.h>
struct tnode 
{
    int data;
    struct tnode *left;
    struct tnode *right;
};
 
typedef struct tnode TreeNode;
 
TreeNode *newNode(int data)
{
    TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
    node->data = data;
    node->left = 0;
    node->right = 0;
     
    return node;
}
TreeNode *insertTree(TreeNode *node, int data)
{
    if (!node)
        return newNode(data);
 
    else
    {
        if (data <= node->data)
            node->left = insertTree(node->left, data);
 
        else 
            node->right = insertTree(node->right, data);
    }
 
    return  node;
}
 
 
 
TreeNode *createTree()
{
    TreeNode * pr = insertTree(0, 4);
    insertTree(pr, 1);
    insertTree(pr, 2);
    insertTree(pr, 3);
    insertTree(pr, 5);
    insertTree(pr, 6);
 
    return pr;
}
 
void printPreorder(TreeNode *node)
{
    if (node)
    {
        printf("preorder = %d\n", node->data);
        printPreorder(node->left);
        printPreorder(node->right);
    }
}
 
void printPostorder(TreeNode *node)
{
    if (node)
    {
        printPostorder(node->left);
        printPostorder(node->right);
        printf("postorder = %d\n", node->data);
    }
}

void printInorder(TreeNode *node)
{
    if (node)
    {
        printInorder(node->left);
        printf("inorder = %d\n", node->data);
        printInorder(node->right);
    }
}
 
int size(TreeNode *node)
{
    if (node)
        return 1 + size(node->left) + size(node->right);
 
    else
        return 0;
}
 
int depth(TreeNode *node)
{
    if (node)
    {
        int ld = depth(node->left);
        int rd = depth(node->right);
 
        if (ld > rd)
            return ld + 1;
        else
            return rd + 1;
    }
    else
        return 0;
}
 
int minVal(TreeNode *node)
{
    if (node)
    {
        while(node->left)
            node = node->left;
 
        return node->data;
    }
    else
        return 0;
}
 
int maxVal(TreeNode *node)
{
    if(node)
    {
        while(node->right)
            node = node->right;
 
        return node->data;
    }
    else
        return 0;
}
int main()
{
	int ch,loop=1;
	struct tnode *root = createTree();
	{
		while(loop==1)
		{
		    printf("\n 1)preorder traversal 2)Inorder traversal 3)Postorder traversal 4)Other details of tree 5)exit");
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
				printf("Size = %d\n",size(root));
				printf("depth = %d\n",depth(root));
				printf("minVal = %d\n",minVal(root));
				printf("maxVal = %d\n",maxVal(root));
				break;
				case 5:
		        loop=0;
		        break;
				default:
				printf("enter the correct value");
			}
		}
	}
	return 0;
}