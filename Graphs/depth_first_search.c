// implementing depth first search in graphs
// Author: Kumar Jatin
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define maxNode 8
struct node
{
	int vertex;
	struct node *next;
};
struct node *list[maxNode];
void addNode(int,int);
int visited[maxNode]={0};
void DFS(int);
int main()
{
	int i;
	for(i=0;i<maxNode;i++)
	{
		list[i]=NULL;
	}
/*
		graph used is given by:

			  	0
		               / \
			      /   \
			     /     \
			    1       2
		           / \	   / \
		          /   \   /   \
		         3     4 5     6
		          \    | |    /
		           \   | |   /
                            \  | |  /
                             \ | | /
                              \| |/
		 		7
*/
	addNode(0,1);
	addNode(0,2);
	addNode(1,0);
	addNode(1,3);
	addNode(1,4);
	addNode(2,0);
	addNode(2,5);
	addNode(2,6);
	addNode(3,1);
	addNode(3,7);
	addNode(4,1);
	addNode(4,7);
	addNode(5,2);
	addNode(5,7);
	addNode(6,2);
	addNode(6,7);
	addNode(7,3);
	addNode(7,4);
	addNode(7,5);
	addNode(7,6);
	printf("DFS order:");
	DFS(0);
	printf("\n");
}
void addNode(int s,int d)
{
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->vertex=d;
	ptr->next=NULL;
	if(list[s]==NULL)
	{
		list[s]=ptr;
	}
	else
	{
		temp=list[s];
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=ptr;
	}
}
void DFS(int v)
{	
	
	struct node *temp;
	visited[v]=1;
	printf("%d\t",v);
	temp=list[v];
	int w;
	while(temp)
	{	
		w=temp->vertex;
		if(visited[w]==0)
		{
			DFS(w);
		}
		temp=temp->next;
	}
}
