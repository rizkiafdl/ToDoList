#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

FILE *f;
int choice = 0;
struct todolist{
	char notes[2048];
	int value;
	char date[30];
};

int menu(int rp,int ap){
	if (rp == ap){
  		printf("\t >>");
	  }
	else{
		printf("\t  ");
	}
}

void swap(int *a, int *b) {
  
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
	
	int step,i;
	for (step = 0; step < size - 1; step++) {
		int min_idx = step;
		for (i = step + 1; i < size; i++) {
			if (array[i] < array[min_idx])
		    min_idx = i;
		}
		swap(&array[min_idx], &array[step]);
	}
}

void addnotes(){
	
	f = fopen("notes.txt" , "a");
    int year, month, day, value, yon, hour, minute;
    char act[200];
    printf("What year?\n"); scanf("%d", &year);
	printf("What month?\n"); scanf("%d", &month);
	printf("What day?\n"); scanf("%d", &day);getchar();
    value = year*100 + month*30 + day;
    fprintf(f, "%d/%d/%d#%d#\n", day,month,year,value);
    do{
    	printf("%15s","Do you want to add?"
				"\n1. Yes\t2. No\n");
        scanf("%d", &yon);getchar();
        system("cls");
        switch(yon){
            case 1:
                printf("What hour[1-24]?\n"); scanf("%d", &hour);getchar();
	            printf("What minute?\n"); scanf("%d", &minute);getchar();
	            printf("Whats the activity?\n "); scanf("%[^\n]", act);getchar();
	            fprintf(f, "%d:%d#%s\n", hour,minute,act);
	            break;
            default:
			 	break;
	    }
   	}while(yon!=2);
    fclose(f);
}

void seenotes(){
	
	char c;
	char todo[100];
	f = fopen("notes.txt" , "r");
	if(f == NULL){
		printf("there is nothing on notes");
	}
	else{
		while(!feof(f)){
			fgets(todo,50,f);
			printf("%s",todo);
		}
	}
	fclose(f);
	printf("\n[O]Earliest [N]Latest");
	printf("\nBack to menu ? [press enter]");
    while (2){
    	if (kbhit) 
		{ 
			c=getch();
            if(c == 13)
			{
				break;
			}
			else if(c ==79 || c== 111)
			{
				
			}
			else if(c ==78 || c== 110)
			{
				printf("Latest:\n");
			}
        }
    }
    system("cls");
}

int main()
{	
	int key;
	int x;
	int p=1; 
	double y;
	
    while(p!=4){
    system("COLOR 70");
    puts("");
    printf("\n\n\t    ________ 	_________    _______     _________    \n"
		   "\t   |	    |  /   ___   \\  |       \\   /   ___   \\     \n"
		   "\t   |__    __|  |  |   |  |  |   __   \\  |  |   |  |     \n"
		   "\t      |  |     |  |   |  |  |  |  \\  |  |  |   |  |     \n"
		   "\t      |	 |     |  |   |  |  |  |__/  |  |  |   |  |     \n"
		   "\t      |	 |     |  |___|  |  |        /  |  |___|  |     \n"
		   "\t      |__|     \\_________/  |_______/   \\_________/     \n\n");
    menu(1,p);printf(" Add notes\n");
    menu(2,p);printf(" See notes\n");
    menu(3,p);printf(" Exit\n");
  	if (kbhit) { 
            key = getch();
            if(key == 119 && p!=1){
            	choice=0;
				system("cls");
				p--;
			}
			else if(key == 115 && p!=3){
				choice=0;
				system("cls");
				p++;
			}
			else if(key == 13 && p==1){
				choice=1;
			}
			else if(key == 13 && p==2){
				choice=2;
			}
			else if(key == 13 && p==3){
				choice=3;
			}
			else{
				system("cls");
			}
        }
    system("cls");
	switch(choice){
        case 1: 
			addnotes();
		    break;
		case 2: 	
			seenotes();
		    break;
        case 3: 
		    system("COLOR 70");
//			char text1[]= "\n\n \t\t\t Welcome Back To To-Do List App ";
			char text2[]= "\n\n \t\t\t Made by ";
			char text3[]= "\n\n \t\t\t Kelompok 1";
			char text4[]= "\n\n \t\t\t Heski Rulita Pratiwi - 2602119884";
			char text5[]= "\n\n \t\t\t Mokhammad Mulkie Al-Ghani - 2602128781";
			char text6[]= "\n\n \t\t\t Abdul Azis Hardy Al-Hakim - 2602128831";
			char text7[]= "\n\n \t\t\t Muhammad Rizki Afdolli - 2602139141";
			char text8[]= "\n\n \t\t\t Sessario Ammar Wibowo - 2602140433";
			char text9[]= "\n\n \t\t\t Aulia Yasmin - 2602145030\n";
			
			printf("\n\n");
//			for(x=0; text1[x]!=NULL; x++){
//				printf("%c",text1[x]);
//				for(y=0; y<=888888; y++){
//				}
//			}
			for(x=0; text2[x]!=NULL; x++){
				printf("%c",text2[x]);
				for(y=0; y<=777777; y++){
				}
			}
			for(x=0; text3[x]!=NULL; x++){
				printf("%c",text3[x]);
				for(y=0; y<=777777; y++){
				}
			}
			for(x=0; text4[x]!=NULL; x++){
				printf("%c",text4[x]);
				for(y=0; y<=777777; y++){
				}
			}
			for(x=0; text5[x]!=NULL; x++){
				printf("%c",text5[x]);
				for(y=0; y<=777777; y++){
				}
			}
			for(x=0; text6[x]!=NULL; x++){
				printf("%c",text6[x]);
				for(y=0; y<=777777; y++){
				}
			}
			for(x=0; text7[x]!=NULL; x++){
				printf("%c",text7[x]);
				for(y=0; y<=777777; y++){
				}
			}
			for(x=0; text8[x]!=NULL; x++){
				printf("%c",text8[x]);
				for(y=0; y<=777777; y++){
				}
			}
			for(x=0; text9[x]!=NULL; x++){
				printf("%c",text9[x]);
				for(y=0; y<=777777; y++){
				}
			}
			getch;
			exit(0);
			break;
    	}
    }
    return 0;
}
