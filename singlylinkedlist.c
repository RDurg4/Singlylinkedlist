#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head=NULL, *pos=NULL, *tail=NULL;
	int ch,e;
	while(1)
	{
		printf("\n1.INSERT \n2.DISPLAY \n3.COUNT \n4.SEARCH \n5.DELETE \n6.EXIT");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("\nEnter data");
				scanf("%d",&e);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->data=e;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail = tail->next;
					tail->data=e;
				}
				break;
			}
			case 2:
			{
				pos=head;
				printf("Elements are");
				while(pos!=NULL)
				{
					printf("\t %d",pos->data);
					pos = pos->next;
				}
				break;
			}
			case 3:
			{
				pos=head;
				int c=0;
				while(pos!=NULL)
				{
					c=c+1;
					pos = pos->next;
				}
				printf("Number of elements= %d",c);
				break;
			}
			case 4:
			{
				int c;
				printf("Enter element to search");
				scanf("%d",&c);
				pos=head;
				while(pos!=NULL)
				{
					if(pos->data == c)
					{
						printf("Element %d is present",pos->data);
					}
					pos=pos->next;
				}
				break;
			}
			case 5:
			{
				struct node *temp =head;
				printf("Enter position of data to be deleted");
				scanf("%d",&e);
				if(e==0)
				{
					head=head->next;
					temp->next=NULL;
					free(temp);
				}
				else
				{
					for(int i=0;i<e-1;i++)
					{
						temp=temp->next;
						struct node *del=temp->next;
						temp->next=temp->next->next;
						del->next=NULL;
						free(del);
					}
				}
				printf("Element from given position is deleted")
				break;
			}
			case 6:
			{
				printf("\nExiting");
				exit(0);
			}
		}
	}
}
















