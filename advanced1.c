#include<stdio.h>
#include<stdlib.h>
#include<time.h>
float timedifference_msec(struct timeval t0, struct timeval t1)
{
	return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
void main()
{
	struct timeval t0;
	struct timeval t1;
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head=NULL, *pos=NULL, *tail=NULL;
	int ch;
	while(1)
	{
		printf("\n1.INSERT \n2.DISPLAY \n3.COUNT \n4.SEARCH \n5.EXIT");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				float elapsed;
				int limit,c=0;
				printf("Enter limit");
				scanf("%d",&limit);
				gettimeofday(&t0,NULL);
				for(c=0;c<limit;c++)
				{
					if(head==NULL)
					{
						head=(struct node*)malloc(sizeof(struct node));
						head->data=rand()%100;
						pos=head;
						tail=head;
					}
					else
					{
						tail->next=(struct node*)malloc(sizeof(struct node));
						tail = tail->next;
						tail->data=rand()%100;
					}
				}
				printf("Element Inserted");
				gettimeofday(&t1,NULL);
				elapsed = timedifference_msec(t0, t1);
				printf("Code executed in %f milliseconds.\n", elapsed);
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
				printf("Number of elements= %d \n",c);
				break;
			}
			case 4:
			{
				int c;
				float elapsed;
				printf("Enter element to search");
				scanf("%d",&c);
				pos=head;
				gettimeofday(&t0,NULL);
				while(pos!=NULL)
				{
					if(pos->data == c)
					{
						printf("Element present \n");
						printf("%d",pos->data);
						printf("\n");
					}
					pos=pos->next;
				}
				gettimeofday(&t1,NULL);
				elapsed = timedifference_msec(t0, t1);
				printf("Code executed in %f milliseconds.\n", elapsed);
				break;
			}
			case 5:
			{
				printf("\nExiting");
				exit(0);
			}
		}
	}
}
















