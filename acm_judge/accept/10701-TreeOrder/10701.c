#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64

struct node{
	char label;
	struct node *lc, *rc;
};

struct node *newNode(char label){
	struct node *e;
	e = (struct node *) malloc(sizeof(struct node));
	e->label = label;
	e->lc = NULL;
	e->rc = NULL;
	return e;
}

struct node *buildTree(short nNode, char preorder[], char inorder[]){
	struct node *root, *lchild, *rchild;
	short nLeftTree, nRightTree;
	char rootLabel;
	char *leftPreorder, *leftinorder, *rightPreorder, *rightinorder;

	if(nNode == 0){
		return NULL;
	}
	if(nNode == 1){
		if(isalpha(preorder[0])) return newNode(preorder[0]);
		else if (isalpha(inorder[0])) return newNode(inorder[0]);
		else{
			printf("recursion error\n");
			return NULL;
		}
	}
	
	rootLabel = preorder[0];
	root = newNode(preorder[0]);
	rightinorder = strchr(inorder, rootLabel);
	*rightinorder = '\0';
	rightinorder += 1;
	leftinorder = inorder;
	
	nRightTree = strlen(rightinorder);
	nLeftTree = strlen(leftinorder);
	
	leftPreorder = strndup(preorder + 1, nLeftTree);
	rightPreorder = strdup(preorder + 1 + nLeftTree);
	
	lchild = buildTree(nLeftTree, leftPreorder, leftinorder);
	rchild = buildTree(nRightTree, rightPreorder, rightinorder);

	free(leftPreorder);
	free(rightPreorder);
	
	root->lc = lchild;
	root->rc = rchild;
	return root;
}

void postorder(struct node *root){
	if(root == NULL){
		printf("null root!\n");
		return ;
	}
	if(root->lc != NULL){
		postorder(root->lc);
	}
	if(root->rc != NULL){
		postorder(root->rc);
	}
	printf("%c", root->label);
	free(root);
}



int main(){
	short nTest, nNode;
	scanf("%hd",&nTest);
	char preorder[MAX], inorder[MAX];
	struct node *root;
	
	while(nTest >= 1){
		nTest--;
		scanf("%hd %s %s", &nNode, preorder, inorder);
		root = buildTree(nNode, preorder, inorder);
		postorder(root);
		printf("\n");
	}
	return 0;
}