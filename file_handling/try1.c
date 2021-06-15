#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j;
int main_exit;
void menu();
void close();
struct date{
    int month,day,year;

    };
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    float amt;
    struct date dob;
    struct date deposit;

    }add,check;


void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void close(void)
{
	system("color 0A");
    printf("\n\n\n\n\t\t\t\t\tThank you for using our banking services\n\n\t\t\t\t\tBy: Akshay Devansh Sumukh Hima");
}

void new_acc()

{
    int choice;
    FILE *ptr;
    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t==== ADD RECORD  ====");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    //add auto date update feature
    scanf("%d/%d/%d",&check.deposit.month,&check.deposit.day,&check.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    //add date criteria
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    //add initial deposit criteria
    scanf("%f",&add.amt);
    

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.amt,check.deposit.month,check.deposit.day,check.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
/* work in progress decryption needed
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nOops that's Invalid!\a");
            goto view_list_invalid;
        }
}
*/



void menu(void)
{   int choice;
    system("cls");
    system("color 40");
    printf("\n\n\t\t\t\x24\x24\x24\x24\x24\x24 BANKING MANAGEMENT SYSTEM \x24\x24\x24\x24\x24\x24");
    printf("\n\n\n\t\t\t\xB2\xB1\xB2\xB1\xB2\xB1\xB2 WELCOME TO THE MAIN MENU \xB2\xB1\xB2\xB1\xB2\xB1\xB2");
    printf("\n\n\t\t[1] Create a new account\n\t\t[2] Update information of existing account\n\t\t[3] Transactions\n\t\t[4] Check the details of existing account\n\t\t[5] Remove existing account\n\t\t[6] Exit\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
		case 2:system("color 08");printf("coming soon...");
		break;
		case 3:system("color 08"); printf("1. Withdraw money(UPI)\n2. NEFT\n3. (debit+credit)\n4. Balance enquiry\n5. Register for UPI handler/change UPI password\nAdmin only\nALL THESE SERVICES ARE COMING SOON IN THE NEXT UPDATE SORRY FOR THE INCONVENIENCE");
		break;
		case 4:system("color 08");printf("haven't figured that out yet (┬┬﹏┬┬)");
		break;
		case 5:system("color 08");printf("I can't do that for now");
		break;
		case 6: close();
		break;
        //add other options later don't forget
    }



}



