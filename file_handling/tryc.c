#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "try.h"
int main()
{
    system("cls");
    system("color 80");
	int main_exit;
    char pass[10],password[10]="code";
    int i=0;
    printf("\n\n\n\t\t\t\t Bank Management System\n\t\t\t\t\t User Login ");
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s",pass);
    
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(". ");
        }
        printf("\n");
                system("pause");
				system("cls");
                
            menu();
        }
    else
        {   printf("\n\nYikes Wrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
