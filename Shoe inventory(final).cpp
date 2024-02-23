#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct size
{
	int pairs[80];
};

struct stock
{
	int stylenum;
	float price;
	struct size inv;
}*inventory;

void Zero(struct stock *x);
int main()
{
	char ans;
	int choice;
	int p,o,a,b,x,i;
	x=1;i=0;
	inventory=(struct stock*)malloc(sizeof(struct stock));
	menu:
	printf("\tMenu Program\t\n1. Add new record\n2. Display record\n3. Change the price of the stock item\n4. Change the number on hand\n5. Exit");
	printf("\nAnswer: ");
	scanf("%d%*c",&choice);
	switch(choice)
	{
		case 1:
			{
				if(x==1)
				goto skip1;
				inventory=(struct stock*)realloc(inventory,x*sizeof(struct stock));
				skip1:
					Zero((inventory+i));
					printf("Enter style number (0-50): ");
					scanf("%d%*c",&(inventory+i)->stylenum);
					if(p<0 || p>50)
					{
						printf("Invalid style number. Try again.\n");
						goto skip1;
					}
					printf("Enter the  price: ");
					scanf("%f",&(inventory+i)->price);
					sz:
					printf("Choose a size (3-14): ");
					scanf("%d%*c",&p);
					if(p<3 || p>14)
					{
						printf("Invalid size. Try again\n");
						goto sz;
					}
					printf("How many pairs do you want? ");
					scanf("%d%*c",&(inventory+i)->inv.pairs[p-3]);
					exit:
					printf("Would you like to enter more size (y/n)? ");
					scanf("%c%*c",&ans);
					if(ans=='y')
					{
						goto sz;
					}
					else if(ans=='n')
					{
						x++;
						i++;
						goto menu;	
					}
					else
					{
						printf("Invalid answer. try again.\n");
						goto exit;
					}
			}
		case 2:
			{
				for(a=0;a<x-1;a++)
				{
					printf("Stock no. %d\n",a+1);
					printf("Style no. %d\n",(inventory+a)->stylenum);
					printf("Price: %.2f\n",(inventory+a)->price);
					printf("Available Sizes:\n");
					for(b=0;b<12;b++)
					{
						if((inventory+a)->inv.pairs[b]!=0)
						{
							printf("Size %d - %d pairs\n",b+3,(inventory+a)->inv.pairs[b]);
						}
					}
				}
				goto menu;
			}
		case 3:
			{
				again2:
				printf("(1) Stock Number\n(2) Style Number\n");
				printf("Please choose between the  two selection: ");
				scanf("%d%*c",&p);
				if(p==1)
				{
					printf("Enter Stock Number: ");
					scanf("%d%*c",&p);
					if(p<x)
					{
						printf("Please Enter new price for Stock no. %d\n",p);
						printf("Current Price: %.2f\n",(inventory+(p-1))->price);
						nprice:
						printf("New Price: ");
						scanf("%f%*c",&(inventory+(p-1))->price);
						again3:
						printf("Are you sure (y/n)? ");
						scanf("%c%*c",&ans);
						if(ans=='y')
						{
							goto menu;
						}
						else if(ans=='n')
						{
							goto nprice;	
						}
						else
						{
							printf("Invalid answer. try again.\n");
							goto again3;
						}
					}
				}
				else if(p==2)
				{
					printf("Enter Style Number: ");
					scanf("%d%*c",&p);
					for(a=0;a<x-1;a++)
					{
						if(p==((inventory+a)->stylenum))
						{
							printf("Please Enter new price for Stock no. %d\n",a+1);
							printf("Current Price: %.2f\n",(inventory+a)->price);
							nprice2:
							printf("New Price: ");
							scanf("%f%*c",&(inventory+a)->price);
							again4:
							printf("Are you sure (y/n)? ");
							scanf("%c%*c",&ans);
							if(ans=='y')
							{
								goto menu;
							}
							else if(ans=='n')
							{
								goto nprice2;	
							}
							else
							{
								printf("Invalid answer. try again.\n");
								goto again4;
							}
						}
					}
				}
				else
				{
					printf("Invalid number. try again.\n");
					goto again2;
				}
				goto menu;
			}
		case 4:
			{
				again5:
				printf("(1) Stock Number\n(2) Style Number\n");
				printf("Please choose between the two selection: ");
				scanf("%d%*c",&p);
				if(p==1)
				{
					printf("Enter Stock Number: ");
					scanf("%d%*c",&p);
					if(p<x)
					{
						again6:
						printf("Enter size for Stock no. %d (3-14): ",p);
						scanf("%d%*c",&o);
						if(o<3 || o>14)
						{
							printf("Invalid Size. try again.\n");
							goto again6;
						}
						printf("Current Quantity: %d\n",(inventory+(p-1))->inv.pairs[o-3]);
						nquan:
						printf("New Quantity: ");
						scanf("%d%*c",&(inventory+(p-1))->inv.pairs[o-3]);
						again7:
						printf("Are you sure (y/n)? ");
						scanf("%c%*c",&ans);
						if(ans=='y')
						{
							goto menu;
						}
						else if(ans=='n')
						{
							goto nquan;	
						}
						else
						{
							printf("Invalid answer. try again.\n");
							goto again7;
						}
					}
				}
				if(p==2)
				{
					printf("Enter Style Number: ");
					scanf("%d%*c",&p);
					for(a=0;a<x-1;a++)
					{
						if(p==((inventory+a)->stylenum))
						{
							again8:
							printf("Enter size for Stock no. %d (3-14): ",a+1);
							scanf("%d%*c",&o);
							if(o<3 || o>14)
							{
								printf("Invalid Size. try again.\n");
								goto again8;
							}
							printf("Current Quantity: %d\n",(inventory+a)->inv.pairs[o-3]);
							nquan2:
							printf("New Quantity: ");
							scanf("%d%*c",&(inventory+a)->inv.pairs[o-3]);
							again9:
							printf("Are you sure (y/n)? ");
							scanf("%c%*c",&ans);
							if(ans=='y')
							{
								goto menu;
							}
							else if(ans=='n')
							{
								goto nquan2;	
							}
							else
							{
								printf("Invalid answer. try again.\n");
								goto again9;
							}
						}
					}
				}
			}
		case 5:
			printf("Are you sure (y/n)? ");
			scanf("%c%*c",&ans);
				if(ans=='y')
					{
						return 0;;
					}
					else
					{
						goto menu;	
						}
			break;
	}
}

void Zero(struct stock *x)
{
	int i;
	for(i=0;i<80;i++)
	{
		x->inv.pairs[i]=0;
	}
}
