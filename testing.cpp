#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct User{
	char username[100];
	char pass[100];
	User *next;
}*head , *tail , *curr;


struct friendData{
	char Friend[100];
	friendData *next;
}*top , *bot;

User *createUser(const char* username , const char* pass){
	User *newUser = (User*) malloc(sizeof(User));
	strcpy(newUser->username, username);
	strcpy(newUser->pass, pass);
	newUser->next = NULL;
	return newUser;
}

void addRegis(const char* username , const char* pass){
	User *temp = createUser(username , pass);
	if(!head){
		head = tail = temp;
	}
	else{
		tail->next = temp;
		tail = temp;
	}
}

friendData *createFriend(const char* Friend){
	friendData *newFriend = (friendData*) malloc(sizeof(friendData));
	strcpy(newFriend->Friend, Friend);
	newFriend->next = NULL;
	return newFriend;
}

void addFriend(const char* Friend){
	friendData *temp = createFriend(Friend);
	if(!top){
		top = bot = temp;
	}
	else{
		bot->next = temp;
		bot = temp;
	}
}

int loginCheck(const char* username , const char* pass){
	User *temp = head;
	int cek;
	while(temp){
		if(strcmp( temp->username , username) == 0){
			if(strcmp( temp->pass , pass) == 0){
				cek = 1;
				return 1;
			}
		}
		else{
			cek = 0;
			temp = temp->next;
		}
	}
	if(cek == 0) return 0;
}

void mainMenu(){
	int count=1;
	User *temp = head;
	printf("Oo=====================================oO\n");
	printf("\t\tSTUDY NETWORK\n");
	printf("Oo=====================================oO\n");
	printf("No.	Username\n");
	while(temp){
		printf("%d	%s\n" ,count , temp->username );
		count++;
		temp = temp->next;
	}
	printf("-----------------------------------------\n");
	printf("[1] Register\n");
	printf("[2] Login\n");
	printf("[3] Exit\n");
	printf("-----------------------------------------\n");
	printf("Press 0 and enter to abort an operation\n");
	printf("-----------------------------------------\n");
	printf(">> ");
}

void loginList(const char* username , int cek){
	int count = 1;  
		User *temp1 = head;
		char nama[100];
		if(cek == 1){
			printf("[All User]\n");
			printf("No.	Username\n");
			while(temp1){
				if(strcmp(temp1->username , username)!=0){
					printf("%d	%s\n" ,count , temp1->username );
					count++;
				}
				temp1 = temp1->next;
			}
			printf("Which user do you want to add?\n");
			printf(">> "); scanf(" %[^\n]" , nama);
			addFriend(nama);
			printf("-- Your request has been sent to %s --\n" , nama);
			printf("Press enter to continue!");
			getchar();
			printf("\n");
		}
		if(cek == 2) printf("Belum dibuat\n");
		if(cek == 3) printf("Belum dibuat\n");
		if(cek == 4) printf("Belum dibuat\n");
		if(cek == 5) printf("Belum dibuat\n");
		if(cek == 6) printf("Logout\n");
	}

int loginMenu(const char* username){
	int  t, count = 1;
	friendData *temp = top;
	int hours, minutes, seconds, day, month, year;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    hours = local->tm_hour;         
    minutes = local->tm_min;
    seconds = local->tm_sec;
    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;
	printf("Oo=====================================oO\n");
	printf("Welcome, %s\n" , username);
	printf("Oo=====================================oO\n");
	printf("Logged in: %s", ctime(&now));
	printf("-----------------------------------------\n\n");
	printf("[All Friends of %s]\n" , username);
	printf("No. Username\n");
		while(temp){
			printf("%d	%s\n" ,count , temp->Friend );
			count++;
			temp = temp->next;
		}
	printf("-----------------------------------------\n");
	printf("\t\t>>MENU<<\n");
	printf("-----------------------------------------\n");
	printf("[1] Add Friend\n");
	printf("[2] Remove Friend\n");
	printf("[3] View Inbox\n");
	printf("[4] View Sent Request\n");
	printf("[5] Add, Edit, Announce, Delete Note\n");
	printf("[6] Log out\n");
	printf("-----------------------------------------\n");
	printf(">> "); scanf("%d" , &t);
	return t;
}


//void regis(){
//	scanf("^[\n]",user->nama)
//}

int main(){
	int t=1;
	mainMenu();
	char username[100] , pass[100];
 	for( ; t!=0 ; ){
	scanf("%d" , &t);
		if(t==1){
			printf("Please type in your username [lowercase || 1..24]:");scanf(" %[^\n]" , username);
			printf("Please type in your username [lowercase || 1..24]:");scanf(" %[^\n]" , pass);
			addRegis(username , pass);
			printf("\n");
			printf("--- Registration Successfull ---\n");
			printf("Press enter to continue!\n\n");
			getchar();
			mainMenu();
		}
		else if(t==2){
			printf("Username: ");scanf(" %[^\n]" , username);
			printf("Password: ");scanf(" %[^\n]" , pass);
			printf("\n");
			if(loginCheck(username , pass) == 1){
				printf("--- Login Successfull ---\n");
				printf("Press enter to continue!");
				getchar();
				printf("\n");
				int cek=1;
				while(cek != 6){
				cek = loginMenu(username);
					if(cek!=6){
						loginList(username , cek);
					}
					if(cek == 6){
						mainMenu();
					}
				}
			}
			else{
				printf("--- Login Failed ---\n");
				printf("Press enter to continue!");
				getchar();
				getchar();
				printf("\n");
				mainMenu();
			}
		}
		else if(t==3)
			break;
			memset(username , 0 , sizeof(username));
			memset(pass , 0 , sizeof(pass));
		}
}