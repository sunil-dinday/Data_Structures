/*
Program to simulate keyboard keys in editor
*/
#include<bits/stdc++.h>
using namespace std;

class doublelist{
public:
	doublelist *next,*prev;
	char ch;
	doublelist()
	{
		next=prev=NULL;
	}
};
doublelist *root; //root is the pointer which points to first character of the text

doublelist *curr;//curr points to the current position of the cursor


int upper;//upper if a flag which is used to check caps lock

//function to insert a character at the current position of the cursor
void insert(char character)
{
	doublelist *temp=new doublelist();
	//if caps lock is on 
	if(upper==1)
		(*temp).ch=toupper(character);
		else
	(*temp).ch=character;
	

		//if curr->next is NULL thats mean cursor is at the last position
	 if(curr->next==NULL)
	{
		curr->next=temp;
		temp->prev=curr;
		curr=temp;
	}
	else
	{
		doublelist *tt;
		tt=curr->next;
		curr->next=temp;
		temp->prev=curr;
		temp->next=tt;
		tt->prev=temp;
		curr=temp;
	}
}
void deleter()
{	//if curr==root thats means there is no character in the editor
	if(curr==root)
		return;
	doublelist *temp;


	if(curr->next==NULL)
	{
		curr=curr->prev;
		curr->next=NULL;
	}
	else
	{
		temp=curr->next;
		curr=curr->prev;
		curr->next=temp;
		temp->prev=curr;
	}
}
void print()
{	//because root->next point to first chaaracter and root point to 
	root=root->next;

	while(root!=NULL)
	{
		cout<<(*root).ch;
		root=root->next;
	}
}
void goup()
{
	int len=0;
	doublelist *temp,*tt;
	temp=curr;
	//first calcualte number of character in this line from first character to
	//the current position of the cursor
	while((*temp).ch!='\n')
	{
		temp=temp->prev;
		len++;
	}
	//if temp->prev is NULL thats means we are at the first line
	if(temp->prev==NULL)
		return ;
	int len2=0;
	temp=temp->prev;
	tt=temp;
	//calculate total length of the previous line
;	while((*temp).ch!='\n')
	{
		temp=temp->prev;
		len2++;
	}
	//if true thats means previous line have less character as compare to curr 
	// line so points c the cursor to the end of previous line
	if(len2<=len)
	{
		curr=tt;
		return ;
	}
	len2=1;
	temp=temp->next;
	//this piece of the position the cursor at the correct position
	while(len2!=len&&(*temp).ch!='\n')
	{
		temp=temp->next;
		len2++;
	}
	curr=temp;

}
void godown()
{
	int len=0;
	doublelist *temp,*tt;
	temp=curr;
	while((*temp).ch!='\n')
	{
		temp=temp->prev;
		len++;
	}
	
	int len2=0;
	temp=temp->next;
	tt=temp
;	while((*temp).ch!='\n')
	{
		temp=temp->next;
		
	}
	if(temp->next==NULL)
	{
		return ;
	}
	len2=1;
	temp=temp->next;
	while(len2!=len&&(*temp).ch!='\n')
	{
		temp=temp->next;
		len2++;
	}
	if((*temp).ch=='\n')
		temp=temp->prev;
	curr=temp;

}
int main()
{
	curr=NULL;
	upper=0;
	string s="asdf1#@qwe^23";
	root=new doublelist();
	curr=root;
	(*root).ch='\n';
	for(int i=0;i<s.length();i++)
	{
		switch(s[i])
		{
			case '/':
			deleter();
			break;
			case '@':
			if(upper==1)
				upper=0;
			else
				upper=1;
			break;
			case '^':
			goup();
			break;
			case '?':
			godown();
			break;
			default:
			if(s[i]=='#')
				s[i]='\n';
			insert(s[i]);

		};
	}
	print();
	cout<<"\n";
	return 0;
}
