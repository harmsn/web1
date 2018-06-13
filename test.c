#include<stdio.h>
#include<stdlib.h>
struct Record
{
	int info;
	struct Record *left;
	struct Record *right;
};
struct Stack
{
   struct Record *sroot;
   struct Stack *nextAdd;
};
struct Record *root=NULL;
struct Stack *stack=NULL;
void addNode(int);
void inOrderTraversal(void);
main()
{
	  int number;
	  while(1)
	  {
		 printf("\n\tEnter no : ");
		 scanf("%d",&number);
		 if(number==-1)
		 {
			 break;
		 }
		 addNode(number);
	  }
	  printf("\n\t***********************\n\t");
	  inOrderTraversal();
}
void addNode(int tmp)
{
	 struct Record *node,*pointer=root;
	node = (struct Record*)malloc(sizeof(struct Record));
	 if(pointer==NULL)
	 {
		 root=node;
		 node->info=tmp;
		 node->right=NULL;
		 node->left=NULL;
		 return;
	 }
	 while(1)
	 {
		if(pointer->info>tmp)
		{
		   if(pointer->left!=NULL)
		   {
			   pointer = pointer->left;
		   }
		   else
		   {
			   pointer->left = node;
			   node->info=tmp;
			   node->right=NULL;
			   node->left=NULL;
			   return;
		   }
		}
		else if(pointer->info<tmp)
		{
		   if(pointer->right!=NULL)
		   {
			   pointer = pointer->right;
		   }
		   else
		   {
			   pointer->right = node;
			   node->info=tmp;
			   node->right=NULL;
			   node->left=NULL;
			   return;
		   }
		}
	 }
}
void inOrderTraversal()
{
	 struct Record *pointer=root;
	 struct Stack *node,*fnode;
	 printf("\n\n");
	 while(pointer!=NULL)
	 {
		 if(pointer->left!=NULL)
		 {
			 node=(struct Stack*)malloc(sizeof(struct Stack));
			 node->sroot=pointer;
			 node->nextAdd = stack==NULL?NULL:stack;
			 stack=node;
			 pointer=pointer->left;
		 }
		 else if(pointer->right==NULL)
		 {
			 printf(" %d",pointer->info);
			 if(stack==NULL)return;
			 else
			 {
				while((stack->sroot)->right==NULL)
				{
					printf(" %d",(stack->sroot)->info);
					if(stack->nextAdd==NULL)
					{
						return;
					}
					else
					{
						fnode=stack->nextAdd;
						free(stack);
						stack=fnode;
					}
				}
				printf(" %d",(stack->sroot)->info);
				pointer=(stack->sroot)->right;
				fnode=stack->nextAdd;
				free(stack);
				stack=fnode;
			 }
		 }
		 else
		 {
			  printf(" %d",pointer->info);
			  pointer = pointer->right;
		 }
	 }
}


