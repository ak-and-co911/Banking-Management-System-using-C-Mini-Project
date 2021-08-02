//Encrypted using bitwise XOR
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
char *m[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

typedef struct
{
    int day,year;
    char da_y[4];
    char month[4];
    int mon;
}date;
typedef struct
{
    int hour,min,sec;
}times;

void time_date(times * t,date * d)
{
    time_t epoch;
    time(&epoch);
    //printf("%s", asctime(gmtime(&epoch)));
    char s[27];
    strcpy(s,asctime(gmtime(&epoch)));
    FILE *ptr=fopen("time.txt","w+");
    fputs(s,ptr);
    rewind(ptr);
    fscanf(ptr,"%s %s %d %d:%d:%d %d",d->da_y,d->month,&d->day,&t->hour,&t->min,&t->sec,&d->year);
    if((t->min+=30)>=60)
        {t->hour+=1;
        t->min=t->min-60;
        }
    if((t->hour+=5)>=24)
        {
            t->hour=t->hour-24;
        }
    for(int i=0;i<12;i++)
    {
        if(strcmp(m[i],d->month)==0)
        d->mon=i+1;
    }
    printf("%s %d %d %d:%d:%d %d",d->da_y,d->mon,d->day,t->hour,t->min,t->sec,d->year);
    fclose(ptr);
    system("del time.txt");
    
}
typedef struct ac_holder{

    char name[60];
    int acc_no;
    int age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    int amt;
    char upi[70];
    date d;
    times t;
    date dob;
    date deposit;
    date withdraw;

    }ac;
ac add,upd,check,transaction;
int main_exit;
void menu();
void close();
void en_num(int *a)
{
    *a=*(a)^200^100^400^500;
}
void de_num(int *a)
{
    *a=*(a)^200^100^400^500;
}
void en_str(char * c)
{
    for(int i=0;i<strlen(c);i++)
    {
        c[i]=c[i]^233;
    }
}
void de_str(char * c)
{
    for(int i=0;i<strlen(c);i++)
    {
        c[i]=c[i]^233;
    }
}

void encrypt(ac * e)
{
    en_str(e->name);
    en_num(&e->acc_no);
    en_num(&e->age);
    en_str(e->address);
    en_str(e->citizenship);
    //double phone;
    //not encrypting ph no binary operations are not possible with double
    en_str(e->acc_type);
    en_num(&e->amt);
    en_str(e->upi);
    en_num(&e->dob.day);
    en_num(&e->dob.mon);
    en_num(&e->dob.year);
    en_num(&e->d.year);
    en_num(&e->d.mon);
    en_num(&e->d.day);
    en_str(e->d.month);
    en_num(&e->t.hour);
    en_num(&e->t.min);
    en_num(&e->t.sec);
}
void decrypt(ac * e)
{
    de_str(e->name);
    de_num(&e->acc_no);
    de_num(&e->age);
    de_str(e->address);
    de_str(e->citizenship);
    //double phone;
    //not encrypting ph no binary operations are not possible with double
    de_str(e->acc_type);
    de_num(&e->amt);
    de_str(e->upi);

    de_num(&e->dob.day);
    de_num(&e->dob.mon);
    de_num(&e->dob.year);
    de_num(&e->d.year);
    de_num(&e->d.mon);
    de_num(&e->d.day);
    de_str(e->d.month);
    de_num(&e->t.hour);
    de_num(&e->t.min);
    de_num(&e->t.sec);
}

void upis(const char *a,char *b)
{
    strcat(b,a);
    strcat(b,"@quickpay");
}
void fordelay(float j)
{   time_t start,current;
    time(&start);
    do{time(&current);}
    while(difftime(current,start)<j);
}

void new_acc()

{
    int flag;
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    while(1)
    {
    flag=0;
    system("cls");
    system("color 60");
    printf("\t\t\t==== ADD RECORD  ====\n\n");
    printf("Please enter the details without spaces between test fields\n");
    //printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    //scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number: ");
    scanf("%d",&add.acc_no);
    rewind(ptr);
    while(fscanf(ptr,"%d %s %s %d/%d/%d %d %s %s %lf %d %s %d:%d:%d %s %d:%d:%d\n",&check.acc_no,check.name,check.upi,&check.dob.day,&check.dob.mon,&check.dob.year,&check.age,check.address,check.citizenship,&check.phone,&check.amt,check.acc_type,&check.d.day,&check.d.mon,&check.d.year,check.d.da_y,&check.t.hour,&check.t.min,&check.t.sec)!=EOF)
    {
        //printf("%d\n",check.acc_no);
        //printf("%lf,<%s>,%s,%d/%d/%d,%d,<%s>,%s,%.lf,%.lf,%s,%d:%d:%d,%s,%d:%d:%d\n",check.acc_no,check.name,check.upi,check.dob.day,check.dob.mon,check.dob.year,check.age,check.address,check.citizenship,check.phone,check.amt,check.acc_type,check.d.day,check.d.mon,check.d.year,check.d.da_y,check.t.hour,check.t.min,check.t.sec);
        decrypt(&check);
        if (check.acc_no==add.acc_no )
            {
            printf("The given account number already exists!\nPlease re-enter the account number\nLoading");
            //printf("%d\n",check.acc_no);
            for(int de=0;de<5;de++)
            {fordelay(0.5);printf(". ");}printf("\n");
            flag=1;
            break;
            }
    }
    if(flag==0)break;
    }
    printf("\nEnter your name(NO SPACES use underscore'_'): ");
    scanf(" %s",add.name);
    strcpy(add.upi,"");
    upis(add.name,add.upi);
    printf("\nEnter your date of birth(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&add.dob.mon,&add.dob.day,&add.dob.year);
    while(1)
    {
    printf("\nEnter your age: ");
    scanf("%d",&add.age);
    if(add.age<0 || add.age>200)
        printf("Enter a valid age!\n");
    else break;
    }
    printf("\nEnter your address(NO SPACES use commas): ");
    scanf(" %s",add.address);
    printf("\nEnter your citizenship: ");
    scanf(" %s",add.citizenship);
    while(1)
    {
    printf("\nEnter your phone number: ");
    scanf("%lf",&add.phone);
    if(add.phone<1000000000 || add.phone>9999999999)
        printf("Invalid phone number!");
    else break;
    }
    printf("\nEnter the amount to deposit:$");
    scanf("%d",&add.amt);
    while(1)
    {
    flag=0;
    int choice;
    printf("\nType of account:\n\t#[1]-->Saving\n\t#[2]-->Current\n\n\tEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:strcpy(add.acc_type,"Saving"); break;
        case 2:strcpy(add.acc_type,"Current"); break;
        default: printf("Please enter a valid option");flag=1;
    }
    if(flag==0)break;
    }
    time_date(&add.t,&add.d);
    encrypt(&add);
    fprintf(ptr,"%d %s %s %d/%d/%d %d %s %s %.lf %d %s %d:%d:%d %s %d:%d:%d\n",add.acc_no,add.name,add.upi,add.dob.day,add.dob.mon,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.amt,add.acc_type,add.d.day,add.d.mon,add.d.year,add.d.da_y,add.t.hour,add.t.min,add.t.sec);

    fclose(ptr);
    printf("\nAccount created successfully!");
    while(1)
   {printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            {close();
            break;}
    else
        {
            printf("\nInvalid!\a");
        }
   }
}

void details()
{
    system("cls");
    system("color 60");
    int flag=0;
    while(1)
    {
    printf("\nEnter your account number: ");
    int c;
    scanf("%d",&c);
    FILE *p1=fopen("record.dat","r");
    while(fscanf(p1,"%d %s %s %d/%d/%d %d %s %s %lf %d %s %d:%d:%d %s %d:%d:%d\n",&check.acc_no,check.name,check.upi,&check.dob.day,&check.dob.mon,&check.dob.year,&check.age,check.address,check.citizenship,&check.phone,&check.amt,check.acc_type,&check.d.day,&check.d.mon,&check.d.year,check.d.da_y,&check.t.hour,&check.t.min,&check.t.sec)!=EOF)
    {
        //printf("%d\n",check.acc_no);
        //printf("%lf,<%s>,%s,%d/%d/%d,%d,<%s>,%s,%.lf,%.lf,%s,%d:%d:%d,%s,%d:%d:%d\n",check.acc_no,check.name,check.upi,check.dob.day,check.dob.mon,check.dob.year,check.age,check.address,check.citizenship,check.phone,check.amt,check.acc_type,check.d.day,check.d.mon,check.d.year,check.d.da_y,check.t.hour,check.t.min,check.t.sec);
        decrypt(&check);
        if (check.acc_no==c)
            {
            flag=1;
            break;
            }
    }
    fclose(p1);
    if(flag==0)
    {
        printf("The account number doesn't exists!\n");
        
        while(1)
    {printf("\n\n\n\t\tEnter 1 to retry and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if(main_exit==0)
            close();
    else if(main_exit==1)
            break;
    else
        {
            printf("\nInvalid!\a");
        }
   }

        printf("Please re-enter the account number\nLoading");
            //printf("%d\n",check.acc_no);
            for(int de=0;de<5;de++)
            {fordelay(0.1);printf(". ");}printf("\n");
    }
    else if(flag==1)break;
    }
    printf("\n%s Account\n",check.acc_type);
    printf("\nAccount number %d",check.acc_no);
    printf("\nUsername: %s",check.name);
    printf("\nupi ID: %s",check.upi);
    printf("\nDate of birth(mm/dd/yyyy): ");
    printf("%d/%d/%d",check.dob.mon,check.dob.day,check.dob.year);
    printf("\nAge: %d",check.age);
    printf("\nAddress : %s",check.address);
    printf("\nCitizenship:  %s",check.citizenship);
    printf("\nPhone number: %.lf",check.phone);
    printf("\nBalance: %d",check.amt);

    while(1)
   {printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
        }
   }
   

}
void deposit()
{

    int num,amt;
    char upi1[70];
    int flag=0;
    while(1)
    {
    flag=0;
    system("cls");
    system("color 60");
    printf("\n\n\n\t\t\tWelcome to the UPI payments interface\n\t\t\tBy:quickpay\n\n");
    printf("\nEnter your account number: ");
    scanf("%d",&num);
    printf("\nEnter your upi id (username@quickpay): ");
    scanf("%s",upi1);
    printf("\nEnter the amount: ");
    scanf("%d",&amt);
    
    FILE *p1=fopen("record.dat","r");
    FILE *p2=fopen("new.dat","a+");
    while(fscanf(p1,"%d %s %s %d/%d/%d %d %s %s %lf %d %s %d:%d:%d %s %d:%d:%d\n",&check.acc_no,check.name,check.upi,&check.dob.day,&check.dob.mon,&check.dob.year,&check.age,check.address,check.citizenship,&check.phone,&check.amt,check.acc_type,&check.d.day,&check.d.mon,&check.d.year,check.d.da_y,&check.t.hour,&check.t.min,&check.t.sec)!=EOF)
    {
        decrypt(&check);
        if ((check.acc_no==num) && (strcmp(check.upi,upi1)==0))
            {
            flag+=1;
            check.amt=(check.amt)+amt;
            num=check.amt;
            encrypt(&check);
            fprintf(p2,"%d %s %s %d/%d/%d %d %s %s %.lf %d %s %d:%d:%d %s %d:%d:%d\n",check.acc_no,check.name,check.upi,check.dob.day,check.dob.mon,check.dob.year,check.age,check.address,check.citizenship,check.phone,check.amt,check.acc_type,check.d.day,check.d.mon,check.d.year,check.d.da_y,check.t.hour,check.t.min,check.t.sec);
            }
        else
            {
            encrypt(&check);
            fprintf(p2,"%d %s %s %d/%d/%d %d %s %s %.lf %d %s %d:%d:%d %s %d:%d:%d\n",check.acc_no,check.name,check.upi,check.dob.day,check.dob.mon,check.dob.year,check.age,check.address,check.citizenship,check.phone,check.amt,check.acc_type,check.d.day,check.d.mon,check.d.year,check.d.da_y,check.t.hour,check.t.min,check.t.sec);
            }
    }
    fclose(p1);
    fclose(p2);

    if(flag==1)
    {
        system("del record.dat");
        system("ren new.dat record.dat");
        printf("\n\nMoney added successful\n");
        printf("Remaining balance: %d\n",num);
        break;
    }
    else
    {
        system("del new.dat");
        printf("\nThe details you have entered are incorrect!\n");
        
    }
     while(1)
    {printf("\n\n\n\t\tEnter 1 to retry and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if(main_exit==0)
            {
                close();
            }
    else if(main_exit==1)
            break;
    else
        {
            printf("\nInvalid!\a");
        }
   }

    }
    while(1)
   {printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
        }
   }


}
void upi_pay()
{
    int num,amt;
    char upi1[70];
    char upi2[70];
    int flag=0;
    while(1)
    {
    flag=0;
    system("cls");
    system("color 60");
    printf("\n\n\n\t\t\tWelcome to the UPI payments interface\n\t\t\t\t\tBy:quickpay\n\n");
    printf("\nEnter your account number: ");
    scanf("%d",&num);
    printf("\nEnter your upi id (username@quickpay): ");
    scanf("%s",upi1);
    printf("\nSend to upi id: ");
    scanf(" %s",upi2);
    printf("\nEnter the amount: ");
    scanf("%d",&amt);
    
    FILE *p1=fopen("record.dat","r");
    FILE *p2=fopen("new.dat","a+");
    while(fscanf(p1,"%d %s %s %d/%d/%d %d %s %s %lf %d %s %d:%d:%d %s %d:%d:%d\n",&check.acc_no,check.name,check.upi,&check.dob.day,&check.dob.mon,&check.dob.year,&check.age,check.address,check.citizenship,&check.phone,&check.amt,check.acc_type,&check.d.day,&check.d.mon,&check.d.year,check.d.da_y,&check.t.hour,&check.t.min,&check.t.sec)!=EOF)
    {
        decrypt(&check);
        if ((check.acc_no==num) && (strcmp(check.upi,upi1)==0))
            {
            if(check.acc_no<amt)
            {printf("\nInsufficient balance!\n");flag==3;break;}
            flag+=1;
            check.amt=(check.amt)-amt;
            num=check.amt;
            encrypt(&check);
            fprintf(p2,"%d %s %s %d/%d/%d %d %s %s %.lf %d %s %d:%d:%d %s %d:%d:%d\n",check.acc_no,check.name,check.upi,check.dob.day,check.dob.mon,check.dob.year,check.age,check.address,check.citizenship,check.phone,check.amt,check.acc_type,check.d.day,check.d.mon,check.d.year,check.d.da_y,check.t.hour,check.t.min,check.t.sec);
            }
        else if (strcmp(check.upi,upi2)==0)
            {
            flag+=1;
            check.amt=(check.amt)+amt;
            encrypt(&check);
            fprintf(p2,"%d %s %s %d/%d/%d %d %s %s %.lf %d %s %d:%d:%d %s %d:%d:%d\n",check.acc_no,check.name,check.upi,check.dob.day,check.dob.mon,check.dob.year,check.age,check.address,check.citizenship,check.phone,check.amt,check.acc_type,check.d.day,check.d.mon,check.d.year,check.d.da_y,check.t.hour,check.t.min,check.t.sec);
            }
        else
            {
            encrypt(&check);
            fprintf(p2,"%d %s %s %d/%d/%d %d %s %s %.lf %d %s %d:%d:%d %s %d:%d:%d\n",check.acc_no,check.name,check.upi,check.dob.day,check.dob.mon,check.dob.year,check.age,check.address,check.citizenship,check.phone,check.amt,check.acc_type,check.d.day,check.d.mon,check.d.year,check.d.da_y,check.t.hour,check.t.min,check.t.sec);
            }
    }
    fclose(p1);
    fclose(p2);

    if(flag==2)
    {
        system("del record.dat");
        system("ren new.dat record.dat");
        printf("\n\nMoney transfer successful\n");
        printf("Remaining balance: %d\n",num);
        break;
    }
    else if(flag==3)
        {system("del new.dat");break;}
    else
    {
        system("del new.dat");
        printf("\nThe details you have entered are incorrect!\n");
        
    }
     while(1)
    {printf("\n\n\n\t\tEnter 1 to retry and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if(main_exit==0)
            {
                close();
            }
    else if(main_exit==1)
            break;
    else
        {
            printf("\nInvalid!\a");
        }
   }

    }
    while(1)
   {printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
        }
   }

    

}
void del_acc()
{
      int num;
    int flag=0;
    while(1)
    {
    flag=0;
    system("cls");
    system("color 60");
    printf("\n\n\n\t\t\t***Delete Account***\n\n");
    printf("\nEnter your account number: ");
    scanf("%d",&num);
    
    FILE *p1=fopen("record.dat","r");
    FILE *p2=fopen("new.dat","a+");
    while(fscanf(p1,"%d %s %s %d/%d/%d %d %s %s %lf %d %s %d:%d:%d %s %d:%d:%d\n",&check.acc_no,check.name,check.upi,&check.dob.day,&check.dob.mon,&check.dob.year,&check.age,check.address,check.citizenship,&check.phone,&check.amt,check.acc_type,&check.d.day,&check.d.mon,&check.d.year,check.d.da_y,&check.t.hour,&check.t.min,&check.t.sec)!=EOF)
    {
        decrypt(&check);
        if (check.acc_no!=num)
            {encrypt(&check);
            fprintf(p2,"%d %s %s %d/%d/%d %d %s %s %.lf %d %s %d:%d:%d %s %d:%d:%d\n",check.acc_no,check.name,check.upi,check.dob.day,check.dob.mon,check.dob.year,check.age,check.address,check.citizenship,check.phone,check.amt,check.acc_type,check.d.day,check.d.mon,check.d.year,check.d.da_y,check.t.hour,check.t.min,check.t.sec);
            }
        else
            flag+=1;
    }
    fclose(p1);
    fclose(p2);
    if(flag==0)
    {printf("\nPlease enter a valid account number\n");
    system("del new.dat");
     while(1)
    {printf("\n\n\n\t\tEnter 1 to retry and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if(main_exit==0)
                close();
    else if(main_exit==1)
            break;
    else
            printf("\nInvalid!\a");
    }
    }
    else if(flag==1)
        {
            printf("\nThank you for being part of out bank =)\n");
            system("del record.dat");
            system("ren new.dat record.dat");
            printf("\nAccount deleted successfully!\n");
            break;
        }

   }

    while(1)
   {printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
            printf("\nInvalid!\a");
   }

}

void menu()
{   int choice;
    system("cls");
    system("color b0");
    printf("\n\n\t\t\t       BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t[1] Create a new account\n\t\t[2] Deposit\n\t\t[3] Account details\n\t\t[4] UPI Pay\n\t\t[5] Delete Account\n\t\t[6] Exit\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:deposit();
        break;
        case 3:details();
        break;
        case 4:upi_pay();
        break;
        case 5:del_acc();
        break;
        case 6:close();
        break;
    }
}

void close(void)
{
    system("color 80");
    printf("\n\n\n\nTHANK YOU FOR USING OUR SERVICE");
    exit(1);
}


