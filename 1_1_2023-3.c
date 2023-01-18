#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
FILE *f;
int choice = 0;
struct todolist{
	char notes[2000];
	int value;
	char date[30];
}yes[20];

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
    fprintf(f, "%d/%d/%d#%d#", day,month,year,value);
    int j = 0;
    for(int j = 0; yon!=2; j++){
            printf("Do you want to add?\n1.Yes\n2.No\n");
            puts("========================");
            scanf("%d",&yon);getchar();
            if(yon==2){
                fprintf(f, "\n");
                continue;
            }
            else{
            system("cls");
            system("cls");
            printf("[Add your toDoList]\n");
            }
            printf("What hour[1-24]?\n"); scanf("%d", &hour);getchar();
            printf("What minute?\n"); scanf("%d", &minute);getchar();
            printf("Whats the activity?\n");scanf("%[^\n]", act);getchar();
            printf("\n%d",j);

        if(minute<10 && j==0){
            fprintf(f, "%d:0%d %s", hour,minute,act);
            continue;
        }
        else if(minute<10 && j!=0){
            fprintf(f, ",%d:0%d %s", hour,minute,act);
            continue;
        }
        else if(minute>10 && j==0){
            fprintf(f, "%d:%d %s", hour,minute,act);
            continue;
        }
        else if(minute>10 && j!=0){
            fprintf(f, ",%d:%d %s", hour,minute,act);
            continue;
        }
    }
    fclose(f);
    fflush(f);
}
void seenotes(){
    system("cls");
    
    int batas = 0;
    int batastemp;
	char c; int i,choice;
	char todo[100];
	f = fopen("notes.txt" , "r+");
	if(f == NULL){
		printf("there is nothing on notes");
	}
	else{
		for(int i = 0; !feof(f); i++){
            fscanf(f, "%[^#]#%d#%[^\n]\n", yes[i].date, &yes[i].value, yes[i].notes);
            batas++;
            		}
	}
    fclose(f);
	//sort
	printf("SEE NOTES\n===========\n1. All Notes\n2. Search a specific date\n3. Delete a note\n4. Update a note\n");
    puts("\n========================\n");
    printf("Choose :");
	scanf("%d", &choice);getchar();
	switch(choice){
        case 1:{
            printf("1.Ascending\n2.Descending\nChoose: ");
            scanf("%d", &choice);
            if(choice==1){
                printf("[Sorted by most recent items you add]\n");
                for(int i = 0; yes[i].value!=NULL; i++){
                    char *buffer;
                    buffer = strtok(yes[i].notes, ",");
                    printf("\t\t\t\t[%s]\n", yes[i].date,yes[i].notes);
                    puts("\t\t\t\t=============");
                    while(buffer!=NULL){
                        printf("\t\t\t\t|%s|\n", buffer);
                        buffer = strtok(NULL, ",");
                    }
                    puts("\t\t\t\t=============\n\n\n\n");
                }

            }
            else if(choice==2){
                printf("[Sorted by most earliest items you add]\n");
                for(batas;batas>=0;batas--){
                    char *buffer;
                    buffer = strtok(yes[batas].notes, ",");
                    printf("\t\t\t\t[%s]\n", yes[batas].date);
                    puts("\t\t\t\t=============");
                    while(buffer!=NULL){
                        printf("\t\t\t\t|%s|\n", buffer);
                        buffer = strtok(NULL, ",");
                    }
                    puts("\t\t\t\t=============\n\n\n\n");
                }
                }
                break;
            }
        case 2:{
            int tahun, bulan, hari;
            printf("enter the year: ");scanf("%d", &tahun);
            printf("enter the month: ");scanf("%d", &bulan);
            printf("enter the day: ");scanf("%d", &hari);
            int key = tahun*100 + bulan*30 + hari;

            int flag = 0;
            for(int i = 0; i<batas; i++){
                if(yes[i].value == key){
                    flag = 1;
                    printf("\t\t\t\t[%s]\n", yes[i].date);
                    puts("\t\t\t\t=============");
                    char *buffer = strtok(yes[i].notes, ",");
                    while(buffer!=NULL){
                        printf("\t\t\t\t|%s|\n", buffer);
                        buffer = strtok(NULL, ",");
                    }
                    puts("\t\t\t\t=============\n\n\n\n");
                }
            }

            if(flag == 0){
                printf("The Inquired date does not exist..");
            }
        break;
        }
        case 3:{
            int del;
            system("cls");
            for(int i = 0; i<batas; i++){
                printf("\t\t\t\t%d.[%s]\n", i+1,yes[i].date);
                char *buffer, tempbuf[1000];
                strcpy(tempbuf, yes[i].notes);
                buffer = strtok(tempbuf, ",");
                puts("\t\t\t\t=============");
                while(buffer!=NULL){
                    printf("\t\t\t\t|%s|\n", buffer);
                    buffer = strtok(NULL, ",");
                }
                puts("\t\t\t\t=============\n\n\n\n");
            }
            printf("\n\n\nChoose a note to delete: ");
            scanf("%d", &del);getchar();
            f = fopen("notes.txt", "w");
            for(int i = 0; i<batas; i++){
                if(i==del-1){
                    continue;
                }
                fprintf(f, "%s#%d#%s\n", yes[i].date, yes[i].value, yes[i].notes);
            }
            printf("\n[Succesfully deleted Day %d]\n",del);
            fclose(f);
            fflush(f);
        break;
        }
        case 4:{
            for(int i = 0; i<batas; i++){
                printf("\t\t\t\t%d.[%s]\n", i+1,yes[i].date);
                char *buffer, tempbuf[1000];
                strcpy(tempbuf, yes[i].notes);
                buffer = strtok(tempbuf, ",");
                puts("\t\t\t\t=============");
                while(buffer!=NULL){
                    printf("\t\t\t\t|%s|\n", buffer);
                    buffer = strtok(NULL, ",");
                }
                puts("\t\t\t\t=============\n");
            }
            int upd;
            printf("Choose the date's note you wish to edit\nChoose: ");
            scanf("%d", &upd);getchar();
            int ove;
            printf("1. Overwrite\n2. Add\nChoose: ");
            scanf("%d", &ove);getchar();
            char buffer[1000] = " ";
            int coz = 0;
            if(ove==1){
                int jam, menit;
                char buffertemp[1000];
                char nota[100];
                int l = 0;
                do{
                printf("1. Add\n2. Stop\nChoose: ");
                scanf("%d", &coz);getchar();
                if(coz == 2)return;
                l++;
                printf("What hour?"); scanf("%d", &jam);
                printf("What minute?"); scanf("%d", & menit);getchar();
                printf("What activities"); scanf("%s", nota);getchar();
                if(menit<10 && l == 0){
                sprintf(buffertemp,"%d:0%d %s",jam,menit,nota);
                strcat(buffer, buffertemp);
                continue;
                }
                else if(menit<10 && l != 0){
                sprintf(buffertemp,",%d:0%d %s",jam,menit,nota);
                strcat(buffer, buffertemp);
                continue;
                }
                else if(menit>10 && l == 0){
                sprintf(buffertemp,"%d:%d %s",jam,menit,nota);
                strcat(buffer, buffertemp);
                continue;
                }
                else if(menit>10 && l != 0){
                sprintf(buffertemp,",%d:%d %s",jam,menit,nota);
                strcat(buffer, buffertemp);
                continue;
                }
            }while(coz!=2);
            puts("\t\t\t\t=============\n");
            printf("|%s|", buffer);
            strcpy(yes[upd-1].notes, buffer);
            f = fopen("notes.txt", "w");
            puts("\t\t\t\t=============");
            for(int i = 0; yes[i].value!=NULL; i++){
                fprintf("%s#%d#%s\n", yes[i].date, yes[i].value, yes[i].notes);
            }
            puts("\t\t\t\t=============\n");
            fclose(f);
            }
        break;
        }

        default:
            break;
        }
	}
    void keluar(){
        int x,y;
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
    }

int main()
{
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
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
    printf("\t\t\t\t\t%s", asctime(ptr));
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
		    keluar();
			break;
    	}
    }
    return 0;
}