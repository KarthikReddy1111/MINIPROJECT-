#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
typedef struct //USED FOR THE LOGIN
{
    char username[30];
    char password[30];
}log;
struct person
{
    char name[35];
    char address[50];
     char father_name[35];
     char nick_name[30];
    char mble_no[10];
    char gender[8];
    char mail[100];
    char aadhar_no[20];

    }; //USED FOR THE ADDING OF THE DETAILS
int choice;
int o;
char aname[30]="admin"; //THIS IS THE DEFAULT PASSWORD
void main_menu(char** userDetails);
void login_menu();
void menu3();
void menu4();
void n_user_menu();
void user_login_menu();
void admin_menu();
char admin_pass[10]="Admin123";
char pass[10];
void got();//main usecase part starting
void start();
void back();
void addrecord(char** userDetails);
void listrecord(char** userDetails);
void modify_the_contacts(char** userDetails);
void deleterecord(char** userDetails);
void searchrecord(char** userDetails);
void view_users();

int main()
{
	system("COLOR F1");//THIS IS FOR THE WHITE COLOR
	printf("process is starting");
	login_menu(); // CALLING THE LOGIN PAGE
	return 0;
}
void login_menu()
{
    int choice;
    system("cls");
    printf("\n\n\t\t\t HOME\t\t\n\n");

    printf("\n\n\t\t\t CHOOSE AN OPTION(1/2/3):\t\t\t\n\n");

    printf("\t\t\t\n\n %c%c%c 1.NEW USER\t\t\n\n",176,176,176);

    printf("\t\t\t\n\n %c%c%c 2.LOGIN \t\t\n\n",176,176,176);

    printf("\t\t\t\n\n %c%c%c 3.ADMIN\t\t\n\n",176,176,176);

    printf("Enter : ");

    scanf("%d",&choice);
    switch(choice)
    {
        case 1:n_user_menu();
               break;
        case 2:/*3
            3asuser_login_menu();*/menu3();
               break;
        case 3:admin_menu();
			   break;
//		case 4:login_menu();
//			   break;
		default:
                system("cls");
                printf("\nEnter 1 to 3 only");
                printf("\n Enter your key");
                getch();
//	 main_menu();

    }
}

void menu3()
{
    system("cls");
    printf("\t\t\t\n\nCHOOSE AN OPTION(1/2):\t\t\t\n\n");
    
    printf("\t\t\n%c%c%c Login\t\t\n",177,177,177);
    
    printf("\t\t\n%c%c%c go back\t\t\n",177,177,177);
    int ch;
    
    printf("Enter : ");
    
    fflush(stdin);
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:fflush(stdin);
        user_login_menu();
        break;
        case 2:login_menu();
    }
}
void n_user_menu()
{
    system("cls");
    int value=1;
    char name[50], pass[50];
    log a;

    printf("\t\t\n\nUSER REGISTER");

    printf("\t\t\n\nEnter User_Id :\t\t\n ");

    printf("\t\t\n\nEnter Password :\t\t\n");

    fflush(stdin);
    gets(a.username);
    char ch;
    int i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            break;
        }
        a.password[i]=ch;
        printf("*");
        i++;
    }
	a.password[i] = '\0';
    FILE *fp;
	fp = fopen("n_user_Login.txt", "a");
	fprintf(fp, "%s %s.\n", a.username, a.password);
	fclose(fp);
	printf("\t\t\t\n\nUSER REGISTERED SUCCESSFULLY");
    Sleep(2000);
    fflush(stdin);
    login_menu();
}
void user_login_menu()
{
	char** userDetails;
	userDetails = (char**)malloc(2 * sizeof(char *));
	for (int i = 0; i < 2; i++) {
		userDetails[i] = (char*)malloc(30 * sizeof(char));
	}
    system("cls");

	// menu3(); // CONFORMING USER TO LOGIN OR GO BACK
     printf("\t\t\t\n\nUSER LOG_IN\t\t\t\n\n");
     log a;

     printf("\t\t\nEnter User_Id :\t\t ");
	 gets(a.username);

     printf("\t\t\nEnter Password : \t\t");

     fflush(stdin);

     char ch;
     int i=0;
     while(1)
    {
        ch=getch();
        if(ch==13)
        {
            break;
        }
        a.password[i]=ch;
        printf("*");
        i++;
    }
	a.password[i] = '\0';
    FILE *fp;
    log b;
    int k=0;
	char totalLine[100];
	fp = fopen("n_user_Login.txt", "r");
	while (fgets(totalLine, sizeof(totalLine), fp)) {
		char* token;
		char p[50];
		int i = 0;
		token = strtok(totalLine, " ");
		if (strcmp(token, a.username) == 0) {
			token = strtok(NULL, " ");
			while (*token != '.') {
				p[i] = *token;
				i += 1;
				token++;
			}
			p[i] = '\0';
			if (strcmp(p, a.password) == 0) {
				printf("User identified");
				fflush(stdin);
				Sleep(1000);
				if(k==0)
				{
					strcpy(userDetails[0], a.username);
					strcpy(userDetails[1], a.password);
					main_menu(userDetails);
					fclose(fp);
					return;
				}
			}
		}
	}

    printf("\t\t\t\n\nUser unidentified");

    printf("Enter1 to re-try or 2 to goback");
    int ch1;

    printf("Enter : ");

    fflush(stdin);
    scanf("%d",&ch1);
    if(ch1==1)
    {
        login_menu();
    }
    else
    {
        menu3();
    }
}
void main_menu(char** userDetails)
{
	printf(" LETS START WITH CONTACTZ MANAGEMENT OPENING MAIN MENU");
	  system("cls");
printf("\t\t*WELCOME TO Contactz_Management");

printf("\n\n\t\t\t  HOME_MENU\t\t\n\n");
printf("\t 1.Add New contact  \t 2.List contacts   \t 3.Delete contact \n\t 4.Modify_the_contact \t 5.Search the contact\t 6.Exit to Home");
printf("\n\n");

switch(getch())
{
    case '1': addrecord(userDetails);
    break;
   case '2': listrecord(userDetails);
    break;
    case '3': deleterecord(userDetails);
    break;
    case '4': modify_the_contacts(userDetails);
    break;
    case '5': searchrecord(userDetails);
    break;
    case '6': exit(0);
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();

main_menu(userDetails);  //AGAIN CALLING THE MAIN main_menu
}
}
void addrecord(char** userDetails)
{
		char fileName[30];
		strcpy(fileName, userDetails[0]);
		strcat(fileName, ".txt");
        system("cls");
        FILE *fp;
        struct person p;
        fp = fopen(fileName, "a");
        printf("\n Enter name: ");
        got(p.name);
        printf("\nEnter the address: ");
        got(p.address);
        printf("\nEnter father name: ");
        got(p.father_name);
        printf("\nEnter nick name: ");
        got(p.nick_name);
        printf("\nEnter phone no.:");
        scanf("%s", p.mble_no);
		if ((strlen(p.mble_no)) == 10) {
			for (int i = 0; i < 10; i++) {
				if ((p.mble_no[i] >= 48) && (p.mble_no[i] <= 57)) {
					//No implementation
				}
				else {
					printf("Enter only numbers from 0 - 9\n");
					Sleep(3000);
					main_menu(userDetails);
				}
			}
		}
		else {
			printf("Mobile number must have only 10 digits");
			Sleep(3000);
			main_menu(userDetails);
		}
        printf("Enter gender:");
        got(p.gender);
        printf("\nEnter e-mail:");
        got(p.mail);
        printf("\n Enter Aadhar no:");
        got(p.aadhar_no);
		
        fprintf(fp, "Name: %s\n", p.name); 
		fprintf(fp, "Address: %s\n", p.address); 
		fprintf(fp, "Father name: %s\n", p.father_name); 
		fprintf(fp, "Nick name: %s\n", p.nick_name); 
		fprintf(fp, "Mobile number: %s\n", p.mble_no); 
		fprintf(fp, "Gender: %s\n", p.gender); 
		fprintf(fp, "Email address: %s\n", p.mail); 
		fprintf(fp, "Aadhar number: %s\n", p.aadhar_no); 

		fflush(stdin);
        printf("\n Record saved");

		fclose(fp);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    main_menu(userDetails);
}
void listrecord(char** userDetails)
{
	char fileName[30];
	strcpy(fileName, userDetails[0]);
	strcat(fileName, ".txt");
    system("cls");
    
	FILE *fp;
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("You have to save the contacts first\n");
		return;
	}
	
	char totalLine[100];
	while (fgets(totalLine, sizeof(totalLine), fp)) {
		puts(totalLine);
	}
	fclose(fp);
	Sleep(5000);
	 printf("\n Enter any key");
	 getch();
		system("cls");
	main_menu(userDetails);
}
void searchrecord(char** userDetails)
{
    struct person p;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);

}
printf("\nEnter name of person to search\n");
got(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\naddress:%s\nFather name:%s\nnick name:%s\nMobile no:%ld\ngender:%s\nE-mail:%s\nCitision no:%s",p.name,p.address,p.father_name,p.nick_name,p.mble_no,p.gender,p.mail,p.aadhar_no);
    }
        else
        printf("file not found");

}
 fclose(f);
  printf("\n Enter any key");

	 getch();
    system("cls");
main_menu(userDetails);
}

void deleterecord(char** userDetails)
{
	char fileName[30];
	strcpy(fileName, userDetails[0]);
	strcat(fileName, ".txt");
    system("cls");
	
	FILE *fp;
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Contacts are to be added first\n");
		Sleep(5000);
		main_menu(userDetails);
	}
	fclose(fp);
	remove(fileName);
 printf("\n Enter any key");

	 getch();
    system("cls");
main_menu(userDetails);
}

void modify_the_contacts(char** userDetails)
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO Modify_the_contacts:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\n Enter name:");
                    got(s.name);
                    printf("\nEnter the address:");
                    got(s.address);
                    printf("\nEnter father name:");
                    got(s.father_name);
                    printf("\nEnter nick name:");
                    got(s.nick_name);
                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mble_no);
                    printf("\nEnter gender:");
                    got(s.gender);
                    printf("\nEnter e-mail:");
                    got(s.mail);
                    printf("\nEnter Aadhar__ no\n");
                    got(s.aadhar_no);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n your data id modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(f);
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");
	main_menu(userDetails);

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
void admin_menu()
{
	printf("\t\t\t\n\nlaunching admin.....\t\t\n");
	printf("\t\t\nENTER YOUR ADMIN PASSWORD: \t\t");
	scanf("%s", pass);
	//printf("%s is password",pass);
	if(strcmp(pass,admin_pass)==0)
	{
		printf("\t\t\nADMIN LOGGED IN SUCESSFULLY\t\t\n");
		printf("\t\t\n1.REGISTER NEW USER:\t\t\n");
		printf("\t\t\n2.VIEW USERS AND THEIR PASSWORDS\t\t\n");
		printf("\t\t\n3.LOGIN AS USER:\t\t\n");
		//printf("\t\t\n4.Go Back");
		printf("\t\t\nENTER YOUR COMMAND:\t\t\n");
		scanf("%d",&o);
		switch(o)
		{
			case 1:
				n_user_menu();
				break;
			case 2: view_users();
					break;
			case 3:login_menu();
			break;
			default:
			printf("enter numbers 1 to 3 only:");
		}

	}
	else
	{
		printf("NOT A REGISTERED ADMIN");
	}
}
void view_users()
{
	FILE *fp;
	fp = fopen("n_user_Login.txt", "r");
	char totalLine[100];
	while (fgets(totalLine, sizeof(totalLine), fp)) {
		printf("\n\n");
		char* token, p[50];
		int i = 0;
		token = strtok(totalLine, " ");
		printf("Username: %s\n", token);
		token = strtok(NULL, " ");
		while (*token != '.') {
			p[i] = *token;
			i += 1;
			token++;
		}
		p[i] = '\0';
		printf("Password: %s", p);
	}
	fclose(fp);
	Sleep(5000);
	admin_menu();
}