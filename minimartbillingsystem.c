MiniMartBillingSystem.C
Who has access

System properties
Type
C
Size
9 KB
Storage used
9 KB
Location
Compuer Project
Owner
me
Modified
Mar 14, 2019 by me
Opened
10:03 PM by me
Created
Mar 14, 2019 with Google Drive Web
Add a description
Viewers can download
#include<stdio.h>
#include<conio.h>
void admin();
void cashier();
struct employee{
	char name[100];
	int age;
	char gender;
	char pass[50];
	};
struct item{
	char name[50];
	int price;
	char ino[20];
	};
struct bill{
	char name[50];
	int quan;
	int amount;
	float damount;
	};

void main(){
int choice;
clrscr();
printf("\t\tKhwopa Mini Mart Service\n");
printf("\t\t         Bhaktapur\n");
printf("---------------------------------------------------------\n");
printf("\t\t\tMAIN MENU\n");
printf("1.Admin \n2.Cashier\n3.Exit\n");
printf("Please Select Your Oprion(1-3)\n");
scanf("%d",&choice);
switch(choice){  //choice for switching admin and cashier
case 1:
	admin();
	break;
case 2:
	cashier();
	break;
default:
printf("\n\nExiting...");

}
getch();
}



void admin(){
	struct employee emp,e;
	struct item i1,i2;
	FILE *fp,*fp1;
	char item_name[25];
	int dec=1;
	int choice;int c=0;
	int data_found=0,record_no=0;
	label:
	clrscr();
	printf("\t\tKhwopa Mini Mart Service\n");
	printf("\t\t         Bhaktapur\n");
	printf("---------------------------------------------------------\n");
	printf("\t\t\tADMIN MENU\n");

	printf("1.Items Data\n2.Employee data\n");
	printf("Please Select Your Choice: ");
	scanf("%d",&choice);
	switch(choice){ //switching for option123
	case 1:
			label1:
			clrscr();
			printf("\t\tKhwopa Mini Mart Service\n");
			printf("\t\t         Bhaktapur\n");
			printf("---------------------------------------------------------\n");
			printf("\t\t\tITEM MENU\n");
			printf("\n1.Entry Of item \n2.Detail Of item\n3.Modification Of item");
			printf("Please Enter your choice: ");
			scanf("%d",&c);
			switch(c){
				case 1:
				clrscr();
				fp1=fopen("item.txt","wb");
				if(fp1==NULL){
				printf("file cannot be opened.");
				exit();}
				printf("\t\tKhwopa Mini Mart Service\n");
				printf("\t\t         Bhaktapur\n");
				printf("---------------------------------------------------------\n");
				printf("\t\t\tENTRY OF ITEM MENU\n");
				while(dec){
				printf("Name: ");
				scanf("%s",i1.name);
				fflush(stdin);
				printf("price: ");
				scanf("%d",&i1.price);
				printf("item code: ");
				fflush(stdin);
				scanf("%s",i1.ino);
				fwrite(&i1,sizeof(i1),1,fp1);
				printf("Do yo want to continue..1/0");
				fflush(stdin);
				scanf("%d",&dec);
				}

				fclose(fp1);
				printf("\n\n\n\tPRESS ANY KEY...");
				getch();
				goto label1;


			case 2:
				clrscr();
				printf("\t\tKhwopa Mini Mart Service\n");
				printf("\t\t         Bhaktapur\n");
				printf("---------------------------------------------------------\n");
				printf("\t\t\tITEM DETAILS\n");
				if((fp1=fopen("item.txt","r+b"))==NULL){
				printf("cannot");
				exit();
				}
				printf("Name\tPrice\tCode");
				printf("\n---------------------------------------------------------\n");
				while(fread(&i2,sizeof(i2),1,fp1)==1){
				printf("%s\t%d\t%s\n",i2.name,i2.price,i2.ino);
				}
				fclose(fp1);
				printf("\n\n\n\tPress Any Key!!!");
				getch();
				goto label1;

			case 3:
			clrscr();
			printf("\t\tKhwopa Mini Mart Service\n");
			printf("\t\t         Bhaktapur\n");
			printf("---------------------------------------------------------\n");
			printf("\t\t\tMODIFICATION MENU\n");
			fp1=fopen("item.txt","r+b");
			if(fp1==NULL){
			printf("cannot create a file");
			exit();
			}
			printf("Enter The Name Of Item To Modify: ");
			fflush(stdin);
			gets(item_name);
			rewind(fp1);
			data_found=0;
			record_no=0;
			while(fread(&i1,sizeof(i1),1,fp1)==1){
				if(strcmp(i1.name,item_name)==0){
					data_found=1;
					printf("The old record is:\n");
					printf("Name\tPrice\tCode");
					printf("\n-----------------------------\n");
					printf("%s\t%d\t%s",i1.name,i1.price,i1.ino);
					printf("\n Enter new name, price and code: ");
					fflush(stdin);
					gets(i1.name);
					fflush(stdin);
					scanf("%d",&i1.price);
					printf("enter code: ");
					fflush(stdin);
					gets(i1.ino);
					fseek(fp1,sizeof(i1)*(record_no),SEEK_SET);
					if(fwrite(&i1,sizeof(i1),1,fp1)==1){
						printf("\nThe record is modified!!\n");
						goto label1;
					}
				}
			record_no++;
			}
			if(data_found==0){
			printf("\nData not found");
			}
			fclose(fp1);
			break;

			default:
				clrscr();
				printf("Invalid Input");
		}
		break;
	case 2:
			clrscr();
			printf("\t\tKhwopa Mini Mart Service\n");
			printf("\t\t         Bhaktapur\n");
			printf("---------------------------------------------------------\n");
			printf("\t\t\tEMPLOYEE MENU\n");
			printf("1.Entry of Employee\n2.Detail of Employee\n");
			printf("Please Enter Your Choice No: ");
			scanf("%d",&c);
			switch(c){ //nested switching for employeers
				case 1:
				clrscr();
				printf("\t\tKhwopa Mini Mart Service\n");
				printf("\t\t         Bhaktapur\n");
				printf("---------------------------------------------------------\n");
				printf("\t\t\tEMPLOYEE ENTRY MENU\n");
				printf("PLEASE ENTER DETAILS\n");
				fp=fopen("employee.txt","ab");
				if(fp==NULL){
				printf("file cannot be opened.");
				exit();}

				while(dec){
					printf("Name: ");
					scanf("%s",emp.name);
					fflush(stdin);
					printf("Age: ");
					scanf("%d",&emp.age);
					printf("Gender: ");
					fflush(stdin);
					scanf("%c",&emp.gender);
					fflush(stdin);
					printf("Password: ");
					scanf("%s",emp.pass);
					fwrite(&emp,sizeof(emp),1,fp);
					printf("Do yo want to continue..1/0");
					scanf("%d",&dec);
				}

				fclose(fp);
				printf("\n\n\n\tPRESS ANY KEY...");
				getch();
				goto label;


	case 2:
       clrscr();
       printf("\t\tKhwopa Mini Mart Service\n");
       printf("\t\t         Bhaktapur\n");
	printf("---------------------------------------------------------\n");
	printf("\t\t\tEMPLOYEE DETAILS\n");
       if((fp=fopen("employee.txt","rb"))==NULL){
       exit();
       }
       printf("Name\tAge\tGender\n");
       printf("----------------------------------\n");
       while(fread(&e,sizeof(e),1,fp)==1){
	printf("%s\t%d\t%c\n",e.name,e.age,e.gender);
       }
       fclose(fp);
       printf("\n\n\n\n\tPRESS ANY KEY");
       getch();
       goto label;

       default:
       printf("Invalid Input !!!");
       }
       printf("\n\n\n\tPRESS ANY KEY");
       getch();
       goto label;


default:
	clrscr();
	printf("\t\tKhwopa Mini Mart Service\n");
	printf("\t\t         Bhaktapur\n");
	printf("---------------------------------------------------------\n");
	printf("\nInvalid Input\nIts logging out.");

}
}


void cashier(){
	struct employee emp,e;
	struct item i1,i2;
	FILE *fp,*fp1,*c;
	char ename[50],pa[20];
	char icode[50];

	int n=0,n1=0,nn;
	long q,amount;
	double dis,d,damount,total=0;
	l1:
	clrscr();
	printf("\t\tKhwopa Mini Mart Service\n");
	printf("\t\t         Bhaktapur\n");
	printf("---------------------------------------------------------\n");
	printf("\t\t\tCASHIER LOGIN PANEL\n");
	if((fp=fopen("employee.txt","rb"))==NULL){
       exit();
       }
       printf("\n\nUsername: ");
				fflush(stdin);
				gets(ename);
				printf("Password: ");
				fflush(stdin);
				gets(pa);
				fflush(stdin);
				rewind(fp1);

       while(fread(&e,sizeof(e),1,fp)==1){
	if(strcmp(e.name,ename)==0){
		clrscr();
		printf("\t\tKhwopa Mini Mart Service\n");
		printf("\t\t         Bhaktapur\n");
		printf("---------------------------------------------------------\n");
		printf("\t\t\tCASHIER LOGIN PANEL\n");
		if(strcmp(e.pass,pa)==0){
		printf("\n\nLogin Successful!!\n\n\nWelcome %s!!",e.name);
		printf("\n\n\n\tPress Any Key");
		n++;
		getch();
		goto l2;
		}
	}
       }
       if(n==0){
       printf("\nLogin Unsuccessful....\nTry again");
       printf("\n\n\n\tPRESS ANY KEY");
       getch();
       goto l1;
       }
       l2:
       clrscr();
       printf("**********Billing Site**********");
       printf("\n\t\tlogined as %s!!!\n",ename);
       while(nn){
       printf("\n\nEnter icode:" );
       fflush(stdin);
       gets(icode);
       if((fp1=fopen("item.txt","r+b"))==NULL){
		printf("cannot");
		exit();
		}
		while(fread(&i2,sizeof(i2),1,fp1)==1){
			if((strcmp(i2.ino,icode)==0)){
			     printf("Enter quantity: ");
			     fflush(stdin);
			     scanf("%ld",&q);
			     printf("discount% : ");
			     fflush(stdin);
			     scanf("%lf",&d);
			     amount=i2.price*q;
			     dis=(d/100)*amount;
			     damount=amount-dis;
			     total+=damount;
			     printf("\namount=%ld\ndamount=%.2lf\n%lf",amount,damount,total);
			     c=fopen("bill.txt","w");
				if(c==NULL){
				printf("cannot create a file");}
			     fprintf(c,"%s%d%ld%.2lf",i2.name,i2.price,amount,damount);
			     n1++;
			}
		}
       printf("\nDo yo want to add more: ");
       fflush(stdin);
       scanf("%d",&nn);
       }
		fclose(c);
		fclose(fp1);


       if(n1==0){
       printf("\n\nInvalid Input...\nPlease Enter Again!!!");
       printf("\n\n\n\tPRESS ANY KEY !!!");
       getch();
       goto l2;
       }
       fclose(fp);



}