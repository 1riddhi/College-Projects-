#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<time.h>
//20BCE166_20BCE177_20BCE231
//STUDENT RECORD MANAGEMENT SYSTEM
struct node
{
    char roll[100];
    char name[100];
    char password[50];
    char dp[100];
    int sem;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    struct node *next;
} *head = NULL, *temp, *save, *new;
void insert()
{
    new = (struct node *)malloc(sizeof(struct node));
    new->next = NULL;
    printf("Enter roll number\n");
    fflush(stdin);
    char roll[50];
    gets(roll);
    save=head;
    while(save!=NULL&& strcmp(save->roll,roll)!=0)
    save=save->next;
    if(save!=NULL)
    {
        printf("----------Roll number already exist !!----------\n");
        return;
     }
     strcpy(new->roll,roll);
    printf("Enter name and surname\n");
    fflush(stdin);
    gets(new->name);
    printf("Enter password\n");
    char arr[50];
    char ch;
    int i=0;
    do{
        arr[i]=getch();
        if(arr[i]!='\r')
        printf("*");
        i++;
    }
    while(arr[i-1]!='\r');
    arr[i-1]='\0';
    strcpy(new->password,arr);
    printf("\n");
    fflush(stdin);
    printf("Enter department\n");
    fflush(stdin);
    gets(new->dp);
    printf("Enter semester number\n");
    scanf("%d", &new->sem);
    printf("Enter marks of course-1  out of 100\n");
    scanf("%d", &new->m1);
    printf("Enter marks of course-2  out of 100  \n");
    scanf("%d", &new->m2);
    printf("Enter marks of course-3  out of 100\n");
    scanf("%d", &new->m3);
    printf("Enter marks of course-4 out of 100\n");
    scanf("%d", &new->m4);
    printf("Enter marks of course-5 out of 100\n");
    scanf("%d", &new->m5);
    if (head == NULL)
    {
        temp = head = new;
    }
    else
    {
        temp->next = new;
        temp = new;
    }
    FILE *fp;
     char name[300];
     sprintf(name,"%s.%s",new->roll,"text");

    fp=fopen(name,"w");
     fprintf(fp,"%s%s\n","Enter roll number-",new->roll);
   fprintf(fp,"%s%s\n","Enter name and surname-",new->name);
   fprintf(fp,"%s%s\n","Enter department-",new->dp);
   fprintf(fp,"%s%d\n","Enter semester number-",new->sem);
   fprintf(fp,"%s%d\n","Enter marks of course-1-",new->m1);
   fprintf(fp,"%s%d\n","Enter marks of course-2-",new->m2);

   fprintf(fp,"%s%d\n","Enter marks of course-3-",new->m3);

   fprintf(fp,"%s%d\n","Enter marks of course-4-",new->m4);

   fprintf(fp,"%s%d\n","Enter marks of course-5-",new->m5);

    fclose(fp);

}
void display()
{
    save = head;
    while (save != NULL)
    {
        printf("----------------------------------\n");
        printf("%s\n", save->roll);
        printf("%s\n", save->name);
        printf("%s\n", save->dp);
        printf("%d\n", save->sem);
        printf("%d\n", save->m1);
        printf("%d\n", save->m2);
        printf("%d\n", save->m3);
        printf("%d\n", save->m4);
        printf("%d\n", save->m5);
        save = save->next;
    }
}
void search()
{
    printf("Enter roll number of studet whose record you want to search\n");
    fflush(stdin);
    char c[50];
    gets(c);
    save = head;
    while (save != NULL)
    {
        if (strcmp(save->roll,c)==0)
        {
            printf("------------record found---------\n");
            printf("%s\n", save->roll);
            printf("%s\n", save->name);
            printf("%s\n", save->dp);
            printf("%d\n", save->sem);
            printf("%d\n", save->m1);
            printf("%d\n", save->m2);
            printf("%d\n", save->m3);
            printf("%d\n", save->m4);
            printf("%d\n", save->m5);
            return ;
        }
        save=save->next;
    }
    printf("----------record does not exist-----------\n");
}
void delete ()
{
     printf("Enter roll number of student whose record you want to delete\n");
    fflush(stdin);
    char c[50];
    gets(c);
        if(head==NULL || ((strcmp(head->roll,c)!=0) && head->next==NULL))
        {
            printf("-----------Record does not exist so can't delete------------\n");
            return;
        }
        else if((strcmp(head->roll,c)==0))
        {
            char name[300];
            sprintf(name,"%s.%s",c,"text");
            if(remove(name)==0)
            printf("----------Record deleted Successfully-----------\n");
            head=head->next;
            return;
        }


    save = head;
    while ((strcmp(save->next->roll,c)!=0))
    {
        save=save->next;
    }
    if(save==NULL || save->next==NULL)
    printf("-----------Record does not exist so can't delete------------\n");
    else
    {
        struct node  * t=save->next;
        save->next=t->next;
        char name[300];
         sprintf(name,"%s.%s",c,"text");
         remove(name);
        printf("----------Record deleted Successfully-----------\n");
    }



}
void change_password()
{
    printf("Enter roll number\n");
    fflush(stdin);
    char c[50];
    gets(c);
    save=head;
    while(save!=NULL && strcmp(save->roll,c)!=0 )
    save=save->next;
    if(save==NULL)
    {
        printf("--------------roll number does not exist----------\n");
        return;
    }
    printf("Enter password\n");
    char arr[50];
    char ch;
    int i=0;
    do{
        arr[i]=getch();
        if(arr[i]!='\r')
        printf("*");
        i++;
    }
    while(arr[i-1]!='\r');
    arr[i-1]='\0';
     strcpy(new->password,arr);
    printf("\n----------password successfully changed-------\n");
    return;

}
void modify()
{
    printf("Enter roll number of studet whose record you want to modify\n");
    fflush(stdin);
    char c[50];
    gets(c);
    save=head;
    while(save!=NULL && strcmp(save->roll,c)!=0 )
    save=save->next;
    if(save==NULL)
    {
        printf("-----------roll number does not exist---------\n");
        return;
    }
     printf("If you want to modify record then enter password\n");
    fflush(stdin);
     char arr[50];
    char ch;
    int i=0;
    do{
        arr[i]=getch();
        if(arr[i]!='\r')
        printf("*");
        i++;
    }
    while(arr[i-1]!='\r');
    arr[i-1]='\0';
    printf("\n");
    if(strcmp(save->password,arr)!=0)
    {
         printf("-----------wrong password----------\n");
         printf("Do you want to change password ? Enter 1 to change it else enter 0\n");
         int choice;
         scanf("%d", &choice);
         if(choice==1)
         {
             change_password();
         }
         else if(choice==0)
         return;
         else {
             printf("----------Incorrect choice----------\n");
             return;
         }
    }
    new=save;
    printf("Enter name and surname\n");
    fflush(stdin);
    gets(new->name);
    printf("Enter department\n");
    fflush(stdin);
    gets(new->dp);
    printf("Enter semester number\n");
    scanf("%d", &new->sem);
    printf("Enter marks of course-1 \n");
    scanf("%d", &new->m1);
    printf("Enter marks of course-2 \n");
    scanf("%d", &new->m2);
    printf("Enter marks of course-3 \n");
    scanf("%d", &new->m3);
    printf("Enter marks of course-4 \n");
    scanf("%d", &new->m4);
    printf("Enter marks of course-5 \n");
    scanf("%d", &new->m5);
     FILE *fp;
    char name[300];
     sprintf(name,"%s.%s",new->roll,"text");

    fp=fopen(name,"w");
     fprintf(fp,"%s%s\n","Enter roll number-",new->roll);
   fprintf(fp,"%s%s\n","Enter name and surname-",new->name);
   fprintf(fp,"%s%s\n","Enter department-",new->dp);
   fprintf(fp,"%s%d\n","Enter semester number-",new->sem);
   fprintf(fp,"%s%d\n","Enter marks of course-1-",new->m1);
   fprintf(fp,"%s%d\n","Enter marks of course-2-",new->m2);

   fprintf(fp,"%s%d\n","Enter marks of course-3-",new->m3);

   fprintf(fp,"%s%d\n","Enter marks of course-4-",new->m4);

   fprintf(fp,"%s%d\n","Enter marks of course-5-",new->m5);



    fclose(fp);


}
void display_result()
{
      printf("----------------Enter your Roll number-----------\n");
      fflush(stdin);
    char c[50];
    gets(c);
    save =head;
    while(save!=NULL && strcmp(save->roll,c)!=0)
    save=save->next;
    if(save==NULL)
    {
        printf("-------------roll number does not exist-------------\n");
        return;
    }
    int aa,bb,cc,dd,ee;
    aa=save->m1;
    bb=save->m2;
    cc=save->m3;
    dd=save->m4;
    ee=save->m5;
    int total;
    total=aa+bb+cc+dd+ee;
    double f=total/5.00;
    printf("|-------------------Result---------------|\n",save->roll);
    if(f>90 && f<=100)
    {   printf("-------CONGRATULATIONS!! PASSED---------\n");
       printf("Roll Number : %s\n",save->roll);
        printf("Name : %s\n",save->name);
        printf("percentage : %lf\n",f);
        printf("Grade : A++\n");
    }
    else if(f>80 && f<=90)
    {   printf("-------CONGRATULATIONS!! PASSED---------\n");
       printf("Roll Number : %s\n",save->roll);
        printf("Name : %s\n",save->name);
        printf("percentage : %lf\n",f);
        printf("Grade : A\n");
    }
    else if(f>70 && f<=80)
    {    printf("-------CONGRATULATIONS!! PASSED---------\n");
       printf("Roll Number : %s\n",save->roll);
        printf("Name : %s\n",save->name);
        printf("percentage : %lf\n",f);
        printf("Grade : B++\n");
    }
    else if(f>60 && f<=70)
    {   printf("-------CONGRATULATIONS!! PASSED---------\n");
       printf("Roll Number : %s\n",save->roll);
        printf("Name : %s\n",save->name);
        printf("percentage : %lf\n",f);
        printf("Grade : B\n");
    }
    else if(f>50 && f<=60)
    {    printf("-------CONGRATULATIONS!! PASSED---------\n");
       printf("Roll Number : %s\n",save->roll);
        printf("Name : %s\n",save->name);
        printf("percentage : %lf\n",f);
        printf("Grade : C++\n");
    }
    else if(f>40 && f<=50)
    {    printf("-------CONGRATULATIONS!! PASSED---------\n");
       printf("Roll Number : %s\n",save->roll);
        printf("Name : %s\n",save->name);
        printf("percentage : %lf\n",f);
        printf("Grade : C\n");
    }
    else if(f<=40)
    {
        printf("--------your score is below 40----------\n");
           printf("Roll Number : %s\n",save->roll);
        printf("Name : %s\n",save->name);
        printf("------------------FAILED----------------\n");
    }
    else
    {
        printf("%lf\n",f);
    }
   printf("------------------------------------------\n");
}
int main()
{
    printf("|----------------Student Record Management System-------------|\n");
    while (1)
    {
    time_t t;   // not a primitive datatype
    time(&t);
    printf("(date and time): %s\n", ctime(&t));
        printf("1.Insert new record\n");
        printf("2.Search record\n");
        printf("3.Delete record\n");
        printf("4.Display record\n");
        printf("5.Modify record\n");
        printf("6.change password\n");
        printf("7.Display result\n");
        printf("8.Exit\n");
        printf("~~~~~ENTER YOUR CHOICE~~~~~\n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            delete ();
            break;
        case 4:
            display();
            break;
        case 5:
            modify();
            break;
        case 6:
            change_password();
            break;
        case 7:
             display_result();
            break;
        case 8:
            return 0;
        default:
            printf("------------Incorrect choice!! Enter correct choice---------\n");
        }
    }
}
