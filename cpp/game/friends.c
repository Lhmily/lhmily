#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

int getrand()  
{  
	srand(time(NULL));  
	return rand()%3;  
}  

int win_lose(int choice)  
{  
	int rand = 0;  
	char *p[3] = {"SCISSORS", "STONE", "CLOTH"};  
	rand = getrand();  
	printf("\nThe system give the %s.\n",p[rand]);  
	rand++;  

	if(choice == rand)                          //even  
	{  
		printf("\nJoey:\tHei, How you doing? We call it even, all right?\n");  
		printf("\tAnd if you are Chandler M. Bing, of course you will say ok.\n");  
		return 0;  
	}  
	else if(rand==choice-1 || rand==choice+2)   //win  
	{  
		printf("\nMonica:\tOf course the winner is Me. I knew it, you such a loser,\n");  
		printf("\tyou can't win me ever!\n");  
		printf("Ross:\tIt can't be, I am Profess Geller and I am a doctor.\n");  
		printf("\tI can't lose, you must cheat me last time. \n");  
		return 1;  
	}  
	else                                        //lose  
	{  
		printf("\nRachel:\tOh my god! Oh my god! I can't believe this. Phoebe,\n");  
		printf("\tyou are my best friend, can we forget this?\n");  
		printf("Phoebe:\tOk, But it is when you say that you don't love Ross any more.\n");  
		return -1;  
	}  
}  

int main()  
{  
	int choice = 0;  
	int flag = 0;  
	int rot = 0;  
	char ch;  
	system("clear");  
	printf("***********************************************");  
	printf("\n\tLets play a game about <Friends>.\n");  
	printf("***********************************************");  
	printf("\nJanice:\tYou don't want to see me any more, right? \n\tSo just chose a number quickly:\n");  
	printf("\n1.SCISSORS\n2.STONE\n3.CLOTH\n");  
	do  
	{  
		printf("\nInput your choice:");  
		scanf("%d",&choice);  
		if(choice>0 && choice<4)   
		{  
			flag = win_lose(choice);  
			while((ch=getchar())!='\n' && ch!=EOF);  
			printf("\nGunther:I want to see Rachel");  
			if(flag == -1)  
				printf(" again");  
			printf(", so please replay it.(y/n)");  
		}  
		else  
		{  
			while((ch=getchar())!='\n' && ch!=EOF);  
			printf("\nMonica:\tWhat's the matter with you! What you need is just chose\n");  
			printf("\ta number from 1 to 3. So are you ready?(y/n)");  
		}  

		ch = getchar();  
	}  
	while(ch=='y' || ch=='Y' || ch=='\n');  

	printf("\nGoodbye！\n");  

	return 0;  
} 
