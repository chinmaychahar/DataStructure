#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct ListNode
{
	int data;
	ListNode* prev;
	ListNode* next;
};
void pushBack(struct ListNode** head,int data)
{
	ListNode* newNode=(ListNode*)malloc(sizeof(ListNode));
	newNode->data=data;
	if(*head==NULL)
	{
		*head=newNode;
		(*head)->next=*head;
		(*head)->prev=*head;
	}
	else
	{
		newNode->prev=(*head)->prev;
		newNode->next=*head;
		(*head)->prev->next=newNode;
		(*head)->prev=newNode;
	}
}
void pushFront(struct ListNode** head,int data)
{
	pushBack(head,data);
	*head=(*head)->prev;
}
int popBack(ListNode** head)
{
	int data;
	if(*head==NULL)
	{
		cout<<"Queue is empty"<<endl;
		exit(0);
	}
	else if((*head)->prev==*head)
	{
		free(*head);
		data=(*head)->data;
		*head=NULL;
	}
	else
	{
		ListNode* newTail=(*head)->prev->prev;
		data=(*head)->prev->data;
		newTail->next=*head;
		free((*head)->prev);
		(*head)->prev=newTail;
	}
	return data;
}
int popFront(ListNode** head)
{
	int data;
	*head=(*head)->next;
	data=popBack(head);
	return data;
}
int main()
{
	ListNode* head=NULL;
	pushBack(&head,10);
	pushBack(&head,20);
	pushBack(&head,30);
	pushBack(&head,40);
	pushFront(&head,50);
	pushFront(&head,60);
	cout<<popFront(&head)<<endl;
	cout<<popFront(&head)<<endl;
	cout<<popBack(&head)<<endl;
}
