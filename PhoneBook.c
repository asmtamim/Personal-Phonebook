#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int total_num,i,j;
char str;
struct book
{
    char name[1000][20];
    char number[1000][20];
    char adress[1000][30];
};
struct book tec;
void menu();
void searc();
void add();
void list();
void delet();
void change();
void personal();

int main()
{
    system("color 5f");
    int a,x,b=1;
    FILE *fp_name,*fp_number,*fp_pass,*fp_password,*fp_flag;
    char *filename1="name.txt";
    char *filename2="number.txt";
    char *filename3="pass.txt";
    char *filename4="password.txt";
    char *filename5="flag.txt";
    fp_name=fopen(filename1,"a");
    fp_number=fopen(filename2,"a");
    fp_pass=fopen(filename3,"r");
    fp_flag=fopen(filename5,"r");
    fscanf(fp_flag,"%d",&x);
    fclose(fp_flag);
    if(x==0)
    {
        fp_password=fopen(filename4,"w");
        printf("\n\n\tThis is a Personal PhoneBook Manager.\n");
        printf("\n\n\tFeatures : \n");
        printf("\n\n\t* You can save, delete, search of the numbers. Also can see the contact list from saved numbers.");
        printf("\n\n\n\tSpecial features : \n");
        printf("\n\n\t1. There is a feature named personal where you can save personal number which you don't \n\n\twant to share with anybody.");
        printf("\n\n\tYou must put a * sign before the first letter of a personal name.\n");
        printf("\n\n\t2. Nobody can delete a contact without user's password permission.");
        printf("\n\n\n\tNecessary steps : \n");
        printf("\n\n\t* Make 2 text file named flag.txt and pass.txt with the source file and put 0 in both file, then save them.\n");
        printf("\n\n\tfor security check, Enter a password : ");
        char ah[100];
        scanf("%s",&ah);
        fprintf(fp_password,"%s\n",ah);
        fp_flag=fopen("flag.txt","w");
        fprintf(fp_flag,"1\n");
        fclose(fp_password);

    }
    fclose(fp_flag);
    fscanf(fp_pass,"%d",&a);
    total_num=a;
    fclose(fp_name);
    fclose(fp_number);
    fclose(fp_pass);

    menu();

    return 0;
}
void menu()
{
    int n;
    system("cls");
    printf("\n\n\t\t\t<<<<< WELCOME TO PHONEBOOK MANAGER >>>>>");
    printf("\n\n\t\t\t\t\tMENU\t\t\t\n\n");
    printf("\tPress 1 : Add a contact.\t\tPress 2 : Search a contact.\n\n");
    printf("\tPress 3 : List.\t\t\t\tPress 4 : Delete a contact.\n\n");
    printf("\tPress 5 : Change password.\t\t\Press 6 : Personal Contacts.");
    printf("\n\n\tPress 7 : Exit.\n\n");
    printf("\n\n                                Enter your choice : ");
    scanf("%d%c",&n,&str);
    if(n==3)list();
    else if(n==4)delet();
    else if(n==1)
    {
        add();
    }
    else if(n==6)personal();
    else if(n==2)searc();
    else if(n==5)change();

    else if(n==7)
    {
        return;
    }

}
void add()
{
    system("cls");
    FILE *fp_name,*fp_number,*fp_pass;
    struct book tec;
    int a;
    fp_name=fopen("name.txt","a");
    fp_pass=fopen("pass.txt","r");
    fp_number=fopen("number.txt","a");
    printf("\n\n\tPut a * sign before the first letter to add it to the Personal : ");
    fscanf(fp_pass,"%d",&total_num);
    printf("\n\n\t  %d : \n\t  Enter Name: ",total_num+1);
    gets(tec.name[total_num]);
    fprintf(fp_name,"%s\n",tec.name[total_num]);
    printf("\n\t  Enter Number: ");
    scanf("%s%c",&tec.number[total_num],&str);
    fprintf(fp_number,"%s\n",tec.number[total_num]);
    total_num++;
    printf("\n\n\t\tDo you want to add another one? \n\n");

    printf("\t\t Press\n\t\t 1 : YES\n");
    printf("\t\t 2 : NO\n\t\t");
    printf("\n                        Enter your choice : ");
    fclose(fp_name);
    fclose(fp_number);
    fclose(fp_pass);
    fp_pass=fopen("pass.txt","w");
    fprintf(fp_pass,"%d\n",total_num);

    scanf("%d%c",&a,&str);
    if(a==1)add();
    if(a==2)menu();


}
void searc()
{
    struct book tec;
    FILE *fp_name,*fp_number,*fp_pass;
    system("cls");
    fp_pass=fopen("pass.txt","r");
    fscanf(fp_pass,"%d",&total_num);
    fp_name=fopen("name.txt","r");
    fp_number=fopen("number.txt","r");
    for(i=0; i<total_num; i++)
    {
        fscanf(fp_name,"%s",&tec.name[i]);
        fscanf(fp_number,"%s",&tec.number[i]);
    }
    printf("\n\n\t\tSearch by name: ");
    char ch[100];

    int ara[total_num];
    gets(ch);
    int x=-1;
    int flag=0;
    int length=strlen(ch);
    for(i=0; i<total_num; i++)
    {
        int sum=0;
        int k=-1;
        int length2=strlen(tec.name[i]);
        for(j=0; j<length; j++)
        {
            int z=k+1;
            for(k=z; k<length2; k++)
            {
                if(ch[j]==tec.name[i][k])
                {
                    if(tec.name[i][0]!='*')
                    {
                        sum=sum+1;
                        flag=1;
                        break;
                    }
                }
            }
        }
        ara[i]=sum;
    }
    if(flag==1)
    {
        x=ara[0];
        for(i=0; i<total_num; i++)
        {
            if(ara[i]>x)
            {
                x=ara[i];
            }
        }
        for(i=0; i<total_num; i++)
        {
            if(x==ara[i])
            {
                printf("\n\t\t%s : %s\n",tec.name[i],tec.number[i]);
            }
        }
    }
    else
    {
        printf("\n\t\tNot found...\n");
    }
    fclose(fp_name);
    fclose(fp_number);
    fp_pass=fopen("pass.txt","w");
    fprintf(fp_pass,"%d\n",total_num);
    fclose(fp_pass);
    printf("\n\t\tPress any key : ");
    scanf("%c",&str);
    menu();
}
void list()
{
    system("cls");
    struct book tec;
    FILE *fp_name,*fp_number,*fp_pass;
    fp_name=fopen("name.txt","r");
    fp_number=fopen("number.txt","r");
    printf("\n\n\t\tLIST : \n\n");
    for(i=0; i<total_num; i++)
    {
        fscanf(fp_name,"%s",&tec.name[i]);
        fscanf(fp_number,"%s",&tec.number[i]);
    }
    for(i=0; i<total_num; i++)
    {
        if(tec.name[i][0]=='*')continue;

        printf("\t\t%s %s\n\n",tec.name[i],tec.number[i]);
    }
    fclose(fp_name);
    fclose(fp_number);
    fp_pass=fopen("pass.txt","w");
    fprintf(fp_pass,"%d\n",total_num);
    fclose(fp_pass);
    printf("\n\t\t\t\tPress any key : ");
    scanf("%c",&str);
    menu();

}
void delet()
{

    struct book tec;
    FILE *fp_name,*fp_number,*fp_pass,*fp_password;
    system("cls");
    char ch[100],ah[100];
    printf("\n\n\t\tEnter your password : ");
    scanf("%s",&ch);
    fp_password=fopen("password.txt","r");
    fscanf(fp_password,"%s",&ah);
    fclose(fp_password);
    if(strcmp(ch,ah)==0)
    {
        fp_pass=fopen("pass.txt","r");
        fscanf(fp_pass,"%d",&total_num);
        fp_name=fopen("name.txt","r");
        fp_number=fopen("number.txt","r");
        for(i=0; i<total_num; i++)
        {
            fscanf(fp_name,"%s",&tec.name[i]);
            fscanf(fp_number,"%s",&tec.number[i]);
        }
        char ch[100];
        int a,b,x,y;
        printf("\n\n\t\tDelete : ");
        scanf("%s",&ch);
        for(i=0; i<total_num; i++)
        {
            if(strcmp(ch,tec.name[i])==0)
            {
                b=i;
            }
        }
        total_num=total_num-1;
        for(i=b; i<total_num; i++)
        {
            strcpy(tec.name[i],tec.name[i+1]);
            strcpy(tec.number[i],tec.number[i+1]);
        }
        fclose(fp_name);
        fclose(fp_number);
        fclose(fp_pass);
        fp_name=fopen("name.txt","w");
        fp_pass=fopen("pass.txt","w");
        fp_number=fopen("number.txt","w");
        for(i=0; i<total_num; i++)
        {
            fprintf(fp_name,"%s\n",tec.name[i]);
            fprintf(fp_number,"%s\n",tec.number[i]);
        }
        fprintf(fp_pass,"%d\n",total_num);
        fclose(fp_name);
        fclose(fp_number);
        fclose(fp_pass);
        printf("\n\t\tContact successfully deleted!");
    }
    else
    {
        printf("\n\t\tPassword incorrect...");
    }
    printf("\n\n\t\tPress any key : ");
    scanf("%c%c",&str,&str);
    menu();

}
void change()
{
    FILE *fp_password;
    char ah[100],ch[100],bh[100];
    system("cls");
    printf("\n\n\t\tEnter old password : ");
    scanf("%s",&ch);
    fp_password=fopen("password.txt","r");
    fscanf(fp_password,"%s",&ah);
    fclose(fp_password);

    if(strcmp(ch,ah)==0)
    {
        printf("\n\t\tEnter new password : ");
        scanf("%s",&bh);
        fp_password=fopen("password.txt","w");
        fprintf(fp_password,"%s",bh);
        fclose(fp_password);
        printf("\n\n\t\tPassword successfully changed!");

    }
    else
    {
        printf("\n\n\t\t\nPassword incorrect...\n");
    }
    printf("\n\t\t\t\tPress any key : ");
    scanf("%c%c",&str,&str);
    menu();

}
void personal()
{
    FILE *fp_password;
    char ah[100],ch[100],bh[100];
    system("cls");
    printf("\n\n\t\tEnter your password : ");
    scanf("%s",&ch);
    fp_password=fopen("password.txt","r");
    fscanf(fp_password,"%s",&ah);
    fclose(fp_password);

    if(strcmp(ch,ah)==0)
    {
        system("cls");
        struct book tec;
        FILE *fp_name,*fp_number,*fp_pass;
        fp_name=fopen("name.txt","r");
        fp_number=fopen("number.txt","r");
        printf("\n\n\t\tPersonal number List : \n\n");
        for(i=0; i<total_num; i++)
        {
            fscanf(fp_name,"%s",&tec.name[i]);
            fscanf(fp_number,"%s",&tec.number[i]);
        }
        for(i=0; i<total_num; i++)
        {
            if(tec.name[i][0]!='*')continue;

            printf("\t\t%s %s\n\n",tec.name[i],tec.number[i]);
        }
        fclose(fp_name);
        fclose(fp_number);
        fp_pass=fopen("pass.txt","w");
        fprintf(fp_pass,"%d\n",total_num);
        fclose(fp_pass);
    }
    else
    {
        printf("\n\n\t\tPassword incorrect...\n\n");
    }
    printf("\n\t\tPress any key : ");
    scanf("%c%c",&str,&str);
    menu();

}
