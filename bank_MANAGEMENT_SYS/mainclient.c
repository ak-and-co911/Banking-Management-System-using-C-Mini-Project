#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include"main.h"
int main()
{
    int main_exit;
    char pass[10],password[10]="hehe";
    int i=0;
    system("cls");
    system("color 60");
    printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login ");
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s",pass);
  
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(1.0);
            printf(". ");
        }
        printf("\n");
                system("pause");
				system("cls");
                
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            while(1){
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                        break;
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();
                    break;
                    }
            else
                    {printf("\nInvalid!");
                    fordelay(1);
                    system("cls");
                    }
            }

        }
        return 0;
}