//simple student dtabase management system
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
void addstudent();
void studentrecord();
void searchstudent();
void delete();
 struct student{
     char first_name[20];
     char last_name[20];
     int roll_no;
     char standard[20];
     char village[20];
     float percentage;

 };
 void main()
 {


     int choice,result;
     while(choice!=6){
         printf("\t\t\t===== student  database management system=====\n");
         printf("\t\t\t==============================================\n");
         printf("\t\t\t 1.add student record\n");
         printf("\t\t\t 2.student record\n");
         printf("\t\t\t 3.search student\n");
         printf("\t\t\t 4.delete record \n");
         printf("\t\t\t 5.exit\n");
         printf("\t\t\t");
         scanf("%d",&choice);
          switch (choice)
          {
          case 1: /* constant-expression */
            system("cls");
             addstudent();
             getch();
             system("cls");
              break;
        case 2:
             system("cls");
             studentrecord();
             printf("\t\t\t press any key to exit");
             system("cls");
             break;
        case 3:
        system("cls");
        searchstudent();
        printf("\t\t\t press any key to exit");
        getch();
        system("cls");
        break;
         case 4:
         system("cls");
         delete();

         printf("\t\t\t press any key to exit \n");
         system("cls");
         break;

           case 5: /* constant-expression */
             printf("\t\t\t thanks for using this software \n");
             exit(0);
             getch();
             system("cls");
              break;


         default:
           printf(" \t\t\t enter any valid no");
            printf("\n \t\t\t press any key to continue \n");
           getch();
           system("cls");
           break;



          }
     }
 }
 void addstudent()  // this function is used to store the student record 
 {
     char another;
     FILE *fp;
     struct student info;
     do
     {
       system("cls");
      /* code */

      printf("\t\t\t ===== add student information ========\n\n\n");
      fp=fopen("student_info.dat","a");
      printf("\t\t\t enter first name   :  ");
      scanf("%s",&info.first_name);
       printf("\t\t\t enter last name   :  ");
      scanf("%s",&info.last_name);
       printf("\t\t\t enter roll no     :  ");
      scanf("%d",&info.roll_no);
       printf("\t\t\t enter class       :  ");
      scanf("%s",&info.standard);
       printf("\t\t\t enter village     :  ");
      scanf("%s",&info.village);
       printf("\t\t\t enter percentage  :  ");
      scanf("%f",&info.percentage);
      printf("\t\t\t ----------------------------------------\n");
      if (fp==NULL)

      {
          fprintf(stderr,"\t\t\t cant't open file");

      }else
      {
          printf("\t\t\t record stored successfully \n");

      }
      fwrite(&info,sizeof(struct student),1,fp);
      fclose(fp);
      printf("\t\t\t do you want to add another record (y/n)");
      scanf("\t\t\t %s",&another);

     } while (another=='y'|| another=='Y');

 }
void studentrecord()  // ths function is used to know how many record are saved in the database 
 {

     FILE *fp;
     struct student info;
     fp=fopen("student_info.dat","r");
     printf("\t\t\t=-============ student record=============\n");
     if(fp==NULL){
fprintf(stderr,"\t\t\t file cant't open\n");
     }
     else
     {
         printf("\t\t\t============== record ==================\n");
         printf("\t\t\t---------------------------------------\n");


     }

     while(fread(&info,sizeof(struct student),1,fp))
        {
     printf("\t\t\t student name    : %s ",info.first_name);
     printf("%s\n",info.last_name);
     printf("\t\t\t roll no         :  %d\n",info.roll_no);
     printf("\t\t\t class           :  %s\n",info.standard);
     printf("\t\t\t village         :  %s\n",info.village);
     printf("\t\t\t percentage      :  %f\n",info.percentage);
     printf("\t\t\t=================================================\n");
     }
     fclose(fp);
     getch();
 }
 void searchstudent() // this function is used to search any student record 
 {
FILE *fp;
struct student info;
int roll_no,found=0;
fp=fopen("student_info.dat","r");
printf("\t\t\t==== search student====\n\n\n");
printf("\t\t\t enter the roll no :  ");
scanf("%d",&roll_no);
while (fread(&info,sizeof(struct student),1,fp))
{


if (info.roll_no==roll_no){
found=1;
 printf("\t\t\t student name        : %s",info.first_name);
     printf("%s\n",info.last_name);
     printf("\t\t\t roll no         :  %d\n",info.roll_no);
     printf("\t\t\t class           :  %s\n",info.standard);
     printf("\t\t\t village         :  %s\n",info.village);
     printf("\t\t\t percentage      :  %f\n",info.percentage);
     printf("\t\t\t=================================================\n");
     }
}
     if(!found){
         printf("\t\t\t record not found\n");

     }
     fclose(fp);
     getch();
 }// this function is used to delete any student record
delete()
{
    struct student info;
    FILE *fp,*fp1;
	int roll_no,found=0;
	printf("\t\t\t enter roll no to delete  :");
	scanf("%d",&roll_no);
	fp=fopen("student_info.dat", "rb");

	while (fread(&info,sizeof(struct student),1,fp)) {
		if (found!=roll_no) {
			printf("\t\t\t A record with requested roll no found and deleted.\n\n");

		} else {
			fwrite(&info, sizeof(struct student), 1, fp1);
		}

		found++;
	}
	if (! found) {
		printf("\t\t\t No record(s) found with the requested roll no: %s\n\n", roll_no);
	}

	fclose(fp);
	fclose(fp1);

	remove("student_info.dat");
	rename("tmp.bin", "student_info.dat");

getch();

}


