#include<iostream.h>
#include<process.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<graphics.h>

#define ENTER 13
#define SPACE 32
#define BKSP 8
#define ESC 27
#define TAB 9
#define MAX_INPUT_LEN 80

typedef char option[15];
const int ROW =10,COL =10;

int scan; //to hold the special characters for moving the prompt
int ascii;
//***********************************
// TO Display main menu
//***********************************
option a[] = {
	      "Admin Login",
	      "Manager Login",
	      "Staff Login",
	      "Customer Login",
	      "Exit"};
// admin menu
option b[]={
	      "Manage Manager",
	      "Manage Staff",
	      "Manage Cinema",
	      "Manage Movie",
	      "Manage Client",
	      "Exit"};
//manager menu
option c[]={
	      "Manage Staff",
	      "Manage Movie",
	      "Manage Client",
	      "Exit"};
//staff menu

option d[]={
	    "Manage Client",
	    "Exit"};
// customer menu
option e[]={
	     "Modify Pass",
	     "History",
	     "Book Movie",
	     "Exit"};
option f[]={
	"LOGIN",
	"REGISTER",
	"EXIT"};
option g[]={
	"ADD",
	"REMOVE",
	"VIEW",
	"MODIFY",
	"SEARCH",
	"BACK"};
option h[]={
	"VIEW",
	"REMOVE",
	"MODIFY",
	"SEARCH",
	"BACK"};
	
//**********************************************************************
//			       class for menus
//*********************************************************************
class main_menu{
	int i,done;
	public:
	       char menu();
	       void control_menu();
};

//**************************************************************************
//			class for admin
//**************************************************************************

class admin{
	int i,done;
	public:
	char admin_menu();
	void control_menu();
	char manage_managers();
	void manager_control();
	char manage_staffs();
	void staff_control();
	char manage_cinemas();
	void cinema_control();
	char manage_movies();
	void movie_control();
};
class manager_details{
	public:
	void add_manager();
	void remove_manager();
	void view_manager();
	void modify_manager();
	void search_manager();
};
class staff_details{
	public:
	void add_staff();
	void remove_staff();
	void view_staff();
	void modify_staff();
	void search_staff();
};
class cinema_details{
	public:
	void add_cinema();
	void remove_cinema();
	void view_cinema();
	void modify_cinema();
	void search_cinema();
};
class movie_details{
	public:
	void add_movie();
	void remove_movie();
	void view_movie();
	void modify_movie();
	void search_movie();
};
class customer_details{
	public:
	void add_customer();
	void remove_customer();
	void view_customer();
	void modify_customer();
	void search_customer();
};
class book: public cinema_details, public movie_details, public customer_details{
	public:
	void booking();
}B;

struct details_customer
{
	char userid[20],password[20];
}P;

struct details
{
	int no_of_staff,no_of_audi;
	float rating;
	char name[20],userid[20],pass[20],position[20],phnum[20],cinema[20];
	char supervisor[20],address[20],manager[20];
	char date[20],cast[20],director[20],time1[20],time2[20];
}M,S,C,D;

struct ticket_booking
{
	char name[20],phnum[20],cinema[20],movie[20],date[20],time[20];
	int price,ticket;
}TB;

//**************************************************************************
//			class for manager
//**************************************************************************

class manager{
	int i,done;
	public:
		char manager_menu();
		void control_menu();
		void manage_staff();
		void manage_movie();
		char detail_menu();
		void detail_control();
		char manage_customer();
};

//***************************************************************************
//			class for staffs
//***************************************************************************
class staff{
	int i,done;
	public:
		char staff_menu();
		void control_menu();
		char manage_customer();
		void control_menu2();
};

//**************************************************************************
//			class for customers
//**************************************************************************

class customer{
	int i,done;
	public:

		char customer_menu();
		void control_menu();
		void history();
		void modify_password();

};
class login{
	int i,done;
	public:
		void admin_opening();
		void admin_register();
		void admin_login();
		void manager_login();
		void staff_login();
		char login_option();
		void customer_login();
		void customer_register();
		void customer_control_menu();
};

//**************************************************************************
//			class for graphics drawing
//**************************************************************************

class shape{
      public:
	    void normalvideo(int x,int y,char *str);
		void reversevideo(int x,int y,char *str);
		void line_hor(int,int,int,char);
	    void line_ver(int,int,int,char);
	    void box(int x1,int y1,int x2,int y2);
};
//**************************************************************************
void shape::normalvideo(int x,int y,char *str){
	 gotoxy(x,y);
	 printf("=> %s",str);
	 
}


void shape::reversevideo(int x,int y,char *str){
	 gotoxy(x,y);
	 printf(">> %s",str);
	
}

void shape::box(int x1,int y1,int x2,int y2)
{
     for(int col=x1;col<x2 ;col++)
     {
      gotoxy(col,y1);
      printf("%c",196);
      gotoxy(col,y2);
      printf("%c",196);
      }

     for(int row=y1;row<y2;row++)
     {
      gotoxy(x1,row);
      printf("%c",179);
      gotoxy(x2,row);
      printf("%c",179);
      }
     gotoxy(x1,y1);
     printf("%c",218);
     gotoxy(x1,y2);
     printf("%c",192);
     gotoxy(x2,y1);
     printf("%c",191);
     gotoxy(x2,y2);
     printf("%c",217);
}

void shape::line_hor(int column1,int column2,int row, char c)
{
	for(column1;column1 <= column2;column1++){
		gotoxy(column1,row);
		cout<< c;
	}
}

void shape::line_ver(int row1,int row2, int column,char c)
{
	for(row1 ; row1 <= row2 ; row1++){
		gotoxy(column,row1);
		cout<<c;
	}
}


char main_menu :: menu(){
  clrscr();
  cleardevice();
  //setbkcolor(CYAN);
  shape s;
  s.box(20,6,65,20);
  s.box(18,4,67,22);
  gotoxy(36,5);
  printf("L O G I N");
  for(int i=1;i<5;i++)
  s.normalvideo(32,i+10,a[i]);
  s.reversevideo(32,10,a[0]);
  i=done=0;
  _setcursortype(_NOCURSOR);
   do{
   int key =getch();
   switch(key)
   {
   case 00:
	  key = getch();
	  switch(key)
	  {
	  case 72:
	      s.normalvideo(32,i+10,a[i]);
	      i--;
	      if(i==-1)
	      i=4;
	      s.reversevideo(32,i+10,a[i]);
	      break;
	  case 80:
	      s.normalvideo(32,i+10,a[i]);
	      i++;
	      if(i==5)
	      i=0;
	      s.reversevideo(32,i+10,a[i]);
	      break;
	  }
	  break;

   case 13:
	  done = 1;
	  break;
   }
   }
   while(!done);
   _setcursortype(_NOCURSOR);
   return(i+49);
}

void main_menu::control_menu()
{
    admin a;
    login l;
    manager ma;
    staff st;
    customer cu;
	shape s;
    char choice;
    do
    {
     choice = menu();
     clrscr();
	 cleardevice();
     switch(choice){
       case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		l.admin_opening(); //admin menu
		break;
	case '2':
		  _setcursortype(_NORMALCURSOR);
		  l.manager_login(); //manager menu
		  break;
	case '3':
		 _setcursortype(_NORMALCURSOR);
		 l.staff_login(); //staff menu
		 break;
	case '4':
		 _setcursortype(_NORMALCURSOR);
		 l.customer_control_menu(); //customer menu
		 break;
	case '5': exit(0);
     }
    } while(choice != 6);
}

void login::admin_opening(){
	login l;
	clrscr();
	cleardevice();
	ifstream myfile;

	myfile.open("security.bin",ios::binary);
	if(myfile){

		cout<<"login";
		l.admin_login();
	}
       else{
		cout<<"register";
		l.admin_register();

	}
       myfile.close();
}

void login::admin_login(){

	clrscr();
	cleardevice();
	admin a;
	login l;
	shape s;
	char id[20],pass[20],userid[20],password[20];
	s.box(20,6,65,20);
	s.box(18,4,67,22);
	gotoxy(30,5);
	printf("A D M I N - L O G I N");
	s.box(30,8,60,10);
	gotoxy(32,9);
	cout<<"Username: " ;
	s.box(30,12,60,14);
	gotoxy(32,13);
	cout<<"Password: ";
	gotoxy(42,9);
	cin>>id;
	gotoxy(42,13);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			pass[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				pass[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			pass[i]=ch;
			i++;
			cout<<"*";
		}
	}
	ifstream fin;
	fin.open("security.bin",ios::in||ios::binary);
	while(fin>>userid>>password){
		if(strcmp(id,userid)==0 && strcmp(pass,password)==0){
			gotoxy(30,16);
			cout<<"L O G I N - S U C C E S S F U L!!";
			getch();
			a.control_menu();
		}
		else{
			gotoxy(32,16);
			cout<<"Error!! please try again ";
			getch();
			l.admin_login();
		}
	}
	fin.close();
}
void login::admin_register(){
	login l;
	shape s;
	clrscr();
	cleardevice();
	char id[20],pass[20],password[20],userid[20];
	s.box(20,6,65,20);
	s.box(18,4,67,22);
	gotoxy(30,5);
	printf("A D M I N - R E G I S T E R");
	//gotoxy(30,8);
	s.box(30,8,60,10);
	gotoxy(32,9);
	cout<<"Enter the Username: ";
	s.box(30,12,60,14);
	gotoxy(32,13);
	cout<<"Enter the Password: ";
	gotoxy(52,9);
	cin>>userid;
	gotoxy(52,13);
		int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			password[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				password[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			password[i]=ch;
			i++;
			cout<<"*";
		}
	}
	//cin>>password;
	ofstream fout;
	fout.open("security.bin",ios::app||ios::binary);
	fout<<userid<<" "<<password<<endl;
	gotoxy(30,16);
	cout<<"REGISTRATION-SUCCESSFULL !!";
	gotoxy(30,17);
	cout<<"Redirectring to Login Page !!";
	getch();
	fout.close();
	l.admin_login();
}

char admin::admin_menu(){
  clrscr();
  cleardevice();
  shape s;
  s.box(20,6,65,20);
  s.box(18,4,67,22);
  gotoxy(34,5);
  printf("A D M I N - M E N U");
  for(int i=1;i<6;i++)
  s.normalvideo(32,i+10,b[i]);
  s.reversevideo(32,10,b[0]);
  i=done=0;
  _setcursortype(_NOCURSOR);
   do{
   int key =getch();
   switch(key)
   {
   case 00:
	  key = getch();
	  switch(key)
	  {
	  case 72:
	      s.normalvideo(32,i+10,b[i]);
	      i--;
	      if(i==-1)
	      i=5;
	      s.reversevideo(32,i+10,b[i]);
	      break;
	  case 80:
	      s.normalvideo(32,i+10,b[i]);
	      i++;
	      if(i==6)
	      i=0;
	      s.reversevideo(32,i+10,b[i]);
	      break;
	  }
	  break;

   case 13:
	  done = 1;
   }
   }
   while(!done);
   _setcursortype(_NOCURSOR);
   return(i+49);

}

void admin::control_menu()
{
	staff st;
    admin a;
	shape s;
    char choice;
    do
    {
     choice = a.admin_menu();
     clrscr();
	 cleardevice();
     switch(choice){

	case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		a.manager_control(); 
		break;

	case '2':
		  _setcursortype(_NORMALCURSOR);
		  a.staff_control(); 
		  break;

	case '3':
		 _setcursortype(_NORMALCURSOR);
		 a.cinema_control(); 
		 break;

	case '4':
		 _setcursortype(_NORMALCURSOR);
		 a.movie_control(); 
		 break;

	case '5':
		_setcursortype(_NORMALCURSOR);
		 st.control_menu2();
		 break;

	case '6': return;
     }
    } while(choice != 7);
}
/*****************************************************************
			functions for class admin
*/////////////////////////////////////////////////////////////////
char admin::manage_managers(){
  clrscr();
  cleardevice();
  shape s;
  s.box(20,6,65,20);
  s.box(18,4,67,22);
  gotoxy(34,5);
  printf("M A N A G E - M A N A G E R");
  for(int i=1;i<6;i++)
  s.normalvideo(32,i+10,g[i]);
  s.reversevideo(32,10,g[0]);
  i=done=0;
  _setcursortype(_NOCURSOR);
   do{
   int key =getch();
   switch(key)
   {
   case 00:
	  key = getch();
	  switch(key)
	  {
	  case 72:
	      s.normalvideo(32,i+10,g[i]);
	      i--;
	      if(i==-1)
	      i=5;
	      s.reversevideo(32,i+10,g[i]);
	      break;
	  case 80:
	      s.normalvideo(32,i+10,g[i]);
	      i++;
	      if(i==6)
	      i=0;
	      s.reversevideo(32,i+10,g[i]);
	      break;
	  }
	  break;

   case 13:
	  done = 1;
   }
   }
   while(!done);
   _setcursortype(_NOCURSOR);
   return(i+49);
}

void admin::manager_control(){
    manager_details D1;
	shape s;
    char choice;
    do
    {
     choice = manage_managers();
     clrscr();
	 cleardevice();
     switch(choice){

	case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		D1.add_manager();
		break;

	case '2':
		  _setcursortype(_NORMALCURSOR);
		  D1.remove_manager();
		  break;

	case '3':
		 _setcursortype(_NORMALCURSOR);
		 D1.view_manager();
		 break;

	case '4':
		 _setcursortype(_NORMALCURSOR);
		 D1.modify_manager();
		 break;

	case '5':
		_setcursortype(_NORMALCURSOR);
		 D1.search_manager();
		 break;

	case '6': return;
     }
    } while(choice != 7);
}
//************************************************************************
void manager_details::add_manager(){
	l1:
	ofstream fout;
	ifstream fin;
	shape s;
	clrscr();
	cleardevice();
	gotoxy(25,2);
	cout<<"F O R M - F O R - M A N A G E R"<<endl;
	s.box(5,3,70,5);
	gotoxy(20,4);
	cout<<"Name: ";
	s.box(5,6,70,8);
	gotoxy(20,7);
	cout<<"Userid: ";
	s.box(5,9,70,11);
	gotoxy(20,10);
	cout<<"Password: ";
	s.box(5,12,70,14);
	gotoxy(20,13);
	cout<<"Position: ";
	s.box(5,15,70,17);
	gotoxy(20,16);
	cout<<"Cinema: ";
	s.box(5,18,70,20);
	gotoxy(20,19);
	cout<<"Phone Number: ";
	gotoxy(27,4);
	char Name[20];
	cin>>Name;
	//cin.getline(M.name,20);
	cin.ignore();
	gotoxy(28,7);
	char user_ID[20];
	cin>>user_ID;
	fin.open("AddManager.bin",ios::in|ios::binary);
	fin.read((char*)&M,sizeof(M));
	while(fin)
	{
		if(strcmp(user_ID,M.userid)==0)
		{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"ID-ALREADY-EXIST !! ENTER NEW ID . . . ";
			getch();
			goto l1;
		}
		fin.read((char*)&M,sizeof(M));
	}
	fin.close();
	
	strcpy(M.name,Name);
	strcpy(M.userid,user_ID);
	cin.ignore();
	gotoxy(30,10);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			M.pass[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				M.pass[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			M.pass[i]=ch;
			i++;
			cout<<"*";
		}
	}
	gotoxy(30,13);
	cin>>M.position;
	cin.ignore();
	gotoxy(29,16);
	cin>>M.cinema;
	cin.ignore();
	gotoxy(34,19);
	cin>>M.phnum;
	if(strlen(M.phnum)!=10)
	{
		s.box(5,23,70,25);
		gotoxy(15,24);
		cout<<"Invalid-Phone-Number-Entered! Try Again . . .";
		getch();
		goto l1;
	}
	cin.ignore();
	fout.open("AddManager.bin",ios::app|ios::binary);
	fout.write((char*)&M,sizeof(M));
	s.box(5,23,70,25);
	gotoxy(15,24);
	cout<<"R E C O R D S - A D D E D - S U C C E S S F U L L Y !!!"<<endl;
	fout.close();
	getch();
}

void manager_details::view_manager(){
	ifstream fin;
	shape s;
	fin.open("AddManager.bin",ios::in|ios::binary);
	fin.read((char*)&M,sizeof(M));
	if(!fin) {
		cout<<endl;
        cout<<"No Records Found!"<<endl;
	getch();
   }
   else{

	s.box(1,2,80,25);
	s.line_hor(2,79,3,196);
	s.line_ver(4,23,29,179);
	s.line_ver(4,23,46,179);
	s.line_ver(4,23,56,179);
	s.line_ver(4,23,68,179);
	gotoxy(25,2);
	cout<<" M A N A G E R - R E C O R D S ";
	//int x=1,y=5;
	//gotoxy(0,12);
	//cout<<"NAME\tUSERID\tPOSITION\tCINEMA\tPHONENUMBER"<<endl;
	gotoxy(3,4);
	cout<<"NAME";
	gotoxy(31,4);
	cout<<"USERID";
	gotoxy(48,4);
	cout<<"POSITION";
	gotoxy(58,4);
	cout<<"CINEMA";
	gotoxy(70,4);
	cout<<"PHONE.NO";
	s.line_hor(2,79,5,196);
	int y=6;
	while(fin)
	{
		gotoxy(3,y);
		cout<<M.name;
		gotoxy(31,y);
		cout<<M.userid;
		gotoxy(48,y);
		cout<<M.position;
		gotoxy(58,y);
		cout<<M.cinema;
		gotoxy(70,y);
		cout<<M.phnum<<endl;
		fin.read((char*)&M,sizeof(M));
		y++;
		s.line_hor(2,79,y,196);
		y++;

	}
	}
	//cout<<endl;
	//gotoxy(20,24);
	//out<<"Press any key to go back . . . ";
	fin.close();
	getch();
}

void manager_details::remove_manager(){
	clrscr();
	cleardevice();
	shape s;
	ofstream fout;
	fout.open("NewManager.bin",ios::out|ios::binary);
	char id[20];
	ifstream fin;
	s.box(1,1,80,8);
	gotoxy(20,2);
	cout<<"Enter the Manager Id to Remove: ";
	s.line_hor(2,79,3,196);
	gotoxy(52,2);
	cin>>id;
	fin.open("AddManager.bin",ios::in|ios::binary);
	fin.read((char*)&M,sizeof(M));
	while(!fin.eof())
	{
		if(strcmp(id,M.userid)==0)
		{
		s.line_ver(4,7,29,179);
		s.line_ver(4,7,46,179);
		s.line_ver(4,7,56,179);
		s.line_ver(4,7,68,179);
		gotoxy(3,5);
		cout<<"NAME";
		gotoxy(31,5);
		cout<<"USERID";
		gotoxy(48,5);
		cout<<"POSITION";
		gotoxy(58,5);
		cout<<"CINEMA";
		gotoxy(70,5);
		cout<<"PHONE.NO";
		s.line_hor(2,79,6,196);
		gotoxy(2,7);
		cout<<M.name;
		gotoxy(31,7);
		cout<<M.userid;
		gotoxy(48,7);
		cout<<M.position;
		gotoxy(58,7);
		cout<<M.cinema;
		gotoxy(70,7);
		cout<<M.phnum;
		char ch;
		s.box(10,11,70,13);
		gotoxy(17,12);
	
		cout<<"Are you sure You want to Delete this record?(Y/N): ";
		gotoxy(20,52);
		ch=getch();
		if(ch=='Y'||ch=='y'){
			//s.box(5,23,70,25);
			gotoxy(12,12);
			cout<<"R E C O R D - R E M O V E D - S U C C E S S F U L L Y !!!";
		}
		else
		{
			return;
		}
		getch();
		}
		else{
			fout.write((char*)&M,sizeof(M));
		}
		fin.read((char*)&M,sizeof(M));
	}
	fout.close();
	fin.close();
	remove("AddManager.bin");
	rename("NewManager.bin","AddManager.bin");
	getch();
}

void manager_details::modify_manager(){
	l1:
	clrscr();
	cleardevice();
	shape s;
	ofstream fout;
	fout.open("NewManager.bin",ios::out|ios::binary);
	char id[20];
	ifstream fin;
	s.box(1,1,80,19);
	gotoxy(20,2);
	cout<<"Enter the Manager Id to Edit: ";
	s.line_hor(2,79,3,196);
	gotoxy(50,2);
	cin>>id;
	fin.open("AddManager.bin",ios::in|ios::binary);
	fin.read((char*)&M,sizeof(M));
	while(!fin.eof())
	{
		if(strcmp(id,M.userid)==0)
		{
			
		gotoxy(25,4);
		cout<<"PREVIOUS RECORDS";
		s.line_hor(2,79,5,196);
		s.line_ver(6,10,29,179);
		s.line_ver(6,10,46,179);
		s.line_ver(6,10,56,179);
		s.line_ver(6,10,68,179);
		gotoxy(3,7);
		cout<<"NAME";
		gotoxy(31,7);
		cout<<"USERID";
		gotoxy(48,7);
		cout<<"POSITION";
		gotoxy(58,7);
		cout<<"CINEMA";
		gotoxy(70,7);
		cout<<"PHONE.NO";
		s.line_hor(2,79,8,196);
		gotoxy(2,9);
		cout<<M.name;
		gotoxy(31,9);
		cout<<M.userid;
		gotoxy(48,9);
		cout<<M.position;
		gotoxy(58,9);
		cout<<M.cinema;
		gotoxy(70,9);
		cout<<M.phnum;
		s.line_hor(2,79,11,196);
			//s.box(20,13,50,15);
			
			gotoxy(25,12);
			cout<<"NEW RECORDS";
			s.line_hor(2,79,13,196);
			s.line_ver(14,18,28,179);
			s.line_ver(14,18,46,179);
			s.line_ver(14,18,56,179);
			s.line_ver(14,18,68,179);
			gotoxy(3,15);
			cout<<"NAME";
			gotoxy(31,15);
			cout<<"USERID";
			gotoxy(48,15);
			cout<<"POSITION";
			gotoxy(58,15);
			cout<<"CINEMA";
			gotoxy(70,15);
			cout<<"PHONE.NO"<<endl;
			s.line_hor(2,79,16,196);
			//s.line_hor(2,79,19,196);
			gotoxy(3,17);
			cin>>M.name;
			gotoxy(31,17);
			cin>>M.userid;
			gotoxy(48,17);
			cin>>M.position;
			gotoxy(58,17);
			cin>>M.cinema;
			gotoxy(70,17);
			cin>>M.phnum;
			if(strlen(M.phnum)!=10)
		{
			s.box(10,22,70,24);
			gotoxy(12,23);
			cout<<"Invalid-Phone-Number-Entered! Try Again . . .";
			getch();
			goto l1;
		}
			
			s.box(10,22,70,24);
			gotoxy(12,23);
			cout<<"R E C O R D - U P D A T E D - S U C C E S S F U L L Y !!!";
			fout.write((char*)&M,sizeof(M));
		}
		else{
			fout.write((char*)&M,sizeof(M));
		}
		fin.read((char*)&M,sizeof(M));
	}
	fout.close();
	fin.close();
	remove("AddManager.bin");
	rename("NewManager.bin","AddManager.bin");
	getch();
}

void manager_details::search_manager(){
	clrscr();
	cleardevice();
	shape s;
	char id[20];
	ifstream fin;
	label1:
	s.box(5,1,70,3);
	gotoxy(25,2);
	cout<<"Enter the Manager Id to Search: ";
	cin>>id;
	fin.open("AddManager.bin",ios::in|ios::binary);
	fin.read((char*)&M,sizeof(M));
	while(!fin.eof())
	{
		if(strcmp(id,M.userid)==0)
		{
			s.box(5,5,70,22);
			s.box(20,6,60,8);
			gotoxy(25,7);
			cout<<"NAME: "<<M.name;
			s.box(20,9,60,11);
			gotoxy(25,10);
			cout<<"USER ID: "<<M.userid;
			s.box(20,12,60,14);
			gotoxy(25,13);
			cout<<"POSITION: "<<M.position;
			s.box(20,15,60,17);
			gotoxy(25,16);
			cout<<"CINEMA: "<<M.cinema;
			s.box(20,18,60,20);
			gotoxy(25,19);
			cout<<"PHONE NUMBER: "<<M.phnum;
		}
		fin.read((char*)&M,sizeof(M));
	}
	fin.close();
	getch();

}
//************************************************************************

char admin::manage_staffs(){
   clrscr();
   cleardevice();
   shape s;
  s.box(20,6,65,20);
  s.box(18,4,67,22);
  gotoxy(34,5);
  printf("M A N A G E - S T A F F");
  for(int i=1;i<6;i++)
  s.normalvideo(32,i+10,g[i]);
  s.reversevideo(32,10,g[0]);
  i=done=0;
  _setcursortype(_NOCURSOR);
   do{
   int key =getch();
   switch(key)
   {
   case 00:
	  key = getch();
	  switch(key)
	  {
	  case 72:
	      s.normalvideo(32,i+10,g[i]);
	      i--;
	      if(i==-1)
	      i=5;
	      s.reversevideo(32,i+10,g[i]);
	      break;
	  case 80:
	      s.normalvideo(32,i+10,g[i]);
	      i++;
	      if(i==6)
	      i=0;
	      s.reversevideo(32,i+10,g[i]);
	      break;
	  }
	  break;

   case 13:
	  done = 1;
   }
   }
   while(!done);
   _setcursortype(_NOCURSOR);
   return(i+49);
}

void admin::staff_control(){
    staff_details D2;
    shape s;
	char choice;
    do
    {
     choice = manage_staffs();
     clrscr();
	 cleardevice();
     switch(choice){

	case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		D2.add_staff(); 
		break;

	case '2':
		  _setcursortype(_NORMALCURSOR);
		  D2.remove_staff(); 
		  break;

	case '3':
		 _setcursortype(_NORMALCURSOR);
		 D2.view_staff(); 
		 break;

	case '4':
		 _setcursortype(_NORMALCURSOR);
		 D2.modify_staff(); 
		 break;

	case '5':
		_setcursortype(_NORMALCURSOR);
		 D2.search_staff(); 
		 break;

	case '6': return;
     }
    } while(choice != 7);
}

//************************************************************************
void staff_details::add_staff(){
	l1:
	ifstream fin;
	ofstream fout;
//	ifstream inf;
	shape s;
	clrscr();
	cleardevice();
	gotoxy(30,2);
	cout<<"F O R M - F O R - S T A F F"<<endl;
	s.box(5,3,70,5);
	gotoxy(20,4);
	cout<<"Name: ";
	s.box(5,6,70,8);
	gotoxy(20,7);
	cout<<"Userid: ";
	s.box(5,9,70,11);
	gotoxy(20,10);
	cout<<"Password: ";
	s.box(5,12,70,14);
	gotoxy(20,13);
	cout<<"Supervisor: ";
	s.box(5,15,70,17);
	gotoxy(20,16);
	cout<<"Phone Number: ";
	gotoxy(27,4);
	char Name[20];
	cin>>Name;
	cin.ignore();
	gotoxy(28,7);
	char user_ID[20];
	cin>>user_ID;
	fin.open("AddStaff.bin",ios::in|ios::binary);
	fin.read((char*)&S,sizeof(S));
	while(fin)
	{
		if(strcmp(user_ID,S.userid)==0)
		{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"ID-ALREADY-EXIST !! ENTER NEW ID . . . ";
			getch();
			goto l1;
		}
		fin.read((char*)&S,sizeof(S));
	}
	fin.close();
	strcpy(S.userid,user_ID);
	strcpy(S.name,Name);
	cin.ignore();
	gotoxy(30,10);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			S.pass[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				S.pass[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			S.pass[i]=ch;
			i++;
			cout<<"*";
		}
	}
	
	gotoxy(32,13);
	char manager[20];
	cin>>manager;
	ifstream inf;
	inf.open("AddManager.bin",ios::in|ios::binary);
	inf.read((char*)&M,sizeof(M));
	while(inf)
	{
		if(strcmp(manager,M.name)==0)
		{
			goto u1;
		}
		inf.read((char*)&M,sizeof(M));
	}
	if(strcmp(manager,M.name)!=0)
		{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"ID-DOESN'T-EXIST !! ENTER VALID MANAGER ID . . . ";
			getch();
			goto l1;
		}
		
	u1:
	inf.close();
	
	strcpy(S.supervisor,manager);

	cin.ignore();
	gotoxy(34,16);
	cin>>S.phnum;
	if(strlen(S.phnum)!=10)
	{
		s.box(5,23,70,25);
		gotoxy(15,24);
		cout<<"Invalid-Phone-Number-Entered! Try Again . . .";
		getch();
		goto l1;
	}
	cin.ignore();
	fout.open("AddStaff.bin",ios::app|ios::binary);
	fout.write((char*)&S,sizeof(S));
	s.box(5,23,70,25);
	gotoxy(15,24);
	cout<<"R E C O R D S - A D D E D - S U C C E S S F U L L Y !!!"<<endl;
	fout.close();
	getch();
}

void staff_details::view_staff(){
	shape s;
	ifstream fin;
	fin.open("AddStaff.bin",ios::in|ios::binary);
	fin.read((char*)&S,sizeof(S));
	if(!fin) {
		cout<<endl;
	cout<<"No Records Found!"<<endl;
	getch();
   }
   else{
	s.box(1,2,80,25);
	s.line_hor(2,79,3,196);
	s.line_ver(4,23,29,179);
	s.line_ver(4,23,46,179);
	s.line_ver(4,23,68,179);
	gotoxy(20,2);
	cout<<" S T A F F - R E C O R D S ";
	gotoxy(3,5);
	cout<<"NAME";
	gotoxy(31,5);
	cout<<"USERID";
	gotoxy(48,5);
	cout<<"SUPERVISOR";
	gotoxy(70,5);
	cout<<"PHONE.NO"<<endl;
	s.line_hor(2,79,6,196);
	int y=7;
	while(fin)
	{
		gotoxy(3,y);
		cout<<S.name;
		gotoxy(31,y);
		cout<<S.userid;
		gotoxy(48,y);
		cout<<S.supervisor;
		gotoxy(70,y);
		cout<<S.phnum<<endl;
		fin.read((char*)&S,sizeof(S));
		y++;
		s.line_hor(2,79,y,196);
		y++;
	}
	}
	fin.close();
	getch();
	
}

void staff_details::remove_staff(){
	clrscr();
	cleardevice();
	shape s;
	ofstream fout;
	fout.open("NewStaff.bin",ios::out|ios::binary);
	char id[20];
	ifstream fin;
	s.box(1,1,80,8);
	gotoxy(20,2);
	cout<<"Enter the Staff Id to Remove: ";
	s.line_hor(2,79,3,196);
	gotoxy(52,2);
	cin>>id;
	fin.open("AddStaff.bin",ios::in|ios::binary);
	fin.read((char*)&S,sizeof(S));
	while(!fin.eof())
	{
		if(strcmp(id,S.userid)==0)
		{
		//s.box(5,5,70,20);
		s.line_ver(4,7,29,179);
		s.line_ver(4,7,46,179);
		//s.line_ver(4,7,56,179);
		s.line_ver(4,7,68,179);
		gotoxy(3,5);
		cout<<"NAME";
		gotoxy(31,5);
		cout<<"USERID";
		gotoxy(48,5);
		cout<<"SUPERVISOR";
		gotoxy(70,5);
		cout<<"PHONE.NO";
		s.line_hor(2,79,6,196);
		gotoxy(3,7);
		cout<<S.name;
		gotoxy(31,7);
		cout<<S.userid;
		gotoxy(48,7);
		cout<<S.supervisor;
		gotoxy(70,7);
		cout<<S.phnum;
	
		char ch;
		s.box(10,11,70,13);
		gotoxy(17,12);
	
		cout<<"Are you sure You want to Delete this record?(Y/N): ";
		gotoxy(20,52);
		ch=getch();
		if(ch=='Y'||ch=='y'){
			//s.box(5,23,70,25);
			gotoxy(12,12);
			cout<<"R E C O R D - R E M O V E D - S U C C E S S F U L L Y !!!";
		}
		else
		{
			return;
		}
		getch();
		}
		else{
			fout.write((char*)&S,sizeof(S));
		}
		fin.read((char*)&S,sizeof(S));
	}
	fout.close();
	fin.close();
	remove("AddStaff.bin");
	rename("NewStaff.bin","AddStaff.bin");
	getch();
}

void staff_details::modify_staff(){
	l1:
	clrscr();
	cleardevice();
	ofstream fout;
//	ifstream inf;
	shape s;
	fout.open("NewStaff.bin",ios::out|ios::binary);
	char id[20];
	ifstream fin;
	s.box(1,1,80,19);
	gotoxy(20,2);
	cout<<"Enter the Staff Id to Edit: ";
	s.line_hor(2,79,3,196);
	gotoxy(50,2);
	cin>>id;
	fin.open("AddStaff.bin",ios::in|ios::binary);
	fin.read((char*)&S,sizeof(S));
	while(!fin.eof())
	{
		if(strcmp(id,S.userid)==0)
		{
		
		gotoxy(25,4);
		cout<<"PREVIOUS RECORDS";
		s.line_hor(2,79,5,196);
		s.line_ver(6,10,29,179);
		s.line_ver(6,10,46,179);
		
		s.line_ver(6,10,68,179);
		gotoxy(3,7);
		cout<<"NAME";
		gotoxy(31,7);
		cout<<"USERID";
		gotoxy(48,7);
		cout<<"SUPERVISOR";
		gotoxy(70,7);
		cout<<"PHONE.NO";
		s.line_hor(2,79,8,196);
		gotoxy(3,9);
		cout<<S.name;
		gotoxy(31,9);
		cout<<S.userid;
		gotoxy(48,9);
		cout<<S.supervisor;
		gotoxy(70,9);
		cout<<S.phnum;
		s.line_hor(2,79,11,196);
		

			//s.box(20,13,50,15);
			gotoxy(25,12);
			cout<<"NEW RECORDS";
			s.line_hor(2,79,13,196);
			s.line_ver(14,18,28,179);
			s.line_ver(14,18,46,179);
			
			s.line_ver(14,18,68,179);
			gotoxy(3,15);
			cout<<"NAME";
			gotoxy(31,15);
			cout<<"USERID";
			gotoxy(48,15);
			cout<<"SUPERVISOR";
			gotoxy(70,15);
			cout<<"PHONE.NO";
			s.line_hor(2,79,16,196);
			gotoxy(3,17);
			cin>>S.name;
			gotoxy(31,17);
			cin>>S.userid;
			
			gotoxy(48,17);
			char manager[20];
			cin>>manager;
			ifstream inf;
			inf.open("AddManager.bin",ios::in|ios::binary);
			inf.read((char*)&M,sizeof(M));
		while(inf)
	{
		if(strcmp(manager,M.name)==0)
		{
			goto u1;
		}
		inf.read((char*)&M,sizeof(M));
	}
	if(strcmp(manager,M.name)!=0)
		{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"ID-DOESN'T-EXIST !! ENTER VALID MANAGER ID . . . ";
			getch();
			goto l1;
		}
		
	u1:
	inf.close();
	strcpy(S.supervisor,manager);

	
			gotoxy(70,17);
			cin>>S.phnum;
			if(strlen(S.phnum)!=10)
			{
			s.box(10,22,70,24);
			gotoxy(12,23);
			cout<<"Invalid-Phone-Number-Entered! Try Again . . .";
			getch();
			goto l1;
			}
				
			s.box(10,22,70,24);
			gotoxy(12,23);
			cout<<"R E C O R D - U P D A T E D - S U C C E S S F U L L Y !!!";
			fout.write((char*)&S,sizeof(S));
		}
		else{
			fout.write((char*)&S,sizeof(S));
		}
		fin.read((char*)&S,sizeof(S));
	}
	fout.close();
	fin.close();
	remove("AddStaff.bin");
	rename("NewStaff.bin","AddStaff.bin");
	getch();
}

void staff_details::search_staff(){
	clrscr();
	cleardevice();
	shape s;
	char id[20];
	ifstream fin;
	label1:
	s.box(5,1,70,3);
	gotoxy(25,2);
	cout<<"Enter the Staff Id to Search: ";
	cin>>id;
	fin.open("AddStaff.bin",ios::in|ios::binary);
	fin.read((char*)&S,sizeof(S));
	while(!fin.eof())
	{
		if(strcmp(id,S.userid)==0)
		{
			s.box(5,5,70,20);
			s.box(20,6,60,8);
			gotoxy(25,7);
			cout<<"NAME: "<<S.name;
			s.box(20,9,60,11);
			gotoxy(25,10);
			cout<<"USER ID: "<<S.userid;
			s.box(20,12,60,14);
			gotoxy(25,13);
			cout<<"SUPERVISOR: "<<S.supervisor;
			s.box(20,15,60,17);
			gotoxy(25,16);
			cout<<"PHONE NUMBER: "<<S.phnum;
		}
		fin.read((char*)&S,sizeof(S));
	}
	fin.close();
	getch();
}
//************************************************************************


char admin::manage_cinemas(){
  clrscr();
  cleardevice();
  shape s;
  s.box(20,6,65,20);
  s.box(18,4,67,22);
  gotoxy(34,5);
  printf("M A N A G E - C I N E M A");
  for(int i=1;i<6;i++)
  s.normalvideo(32,i+10,g[i]);
  s.reversevideo(32,10,g[0]);
  i=done=0;
  _setcursortype(_NOCURSOR);
   do{
   int key =getch();
   switch(key)
   {
   case 00:
	  key = getch();
	  switch(key)
	  {
	  case 72:
	      s.normalvideo(32,i+10,g[i]);
	      i--;
	      if(i==-1)
	      i=5;
	      s.reversevideo(32,i+10,g[i]);
	      break;
	  case 80:
	      s.normalvideo(32,i+10,g[i]);
	      i++;
	      if(i==6)
	      i=0;
	      s.reversevideo(32,i+10,g[i]);
	      break;
	  }
	  break;

   case 13:
	  done = 1;
   }
   }
   while(!done);
   _setcursortype(_NOCURSOR);
   return(i+49);
}

void admin::cinema_control(){
    cinema_details D3;
    shape s;
	char choice;
    do
    {
     choice = manage_cinemas();
     clrscr();
	 cleardevice();
     switch(choice){

	case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		D3.add_cinema();
		break;

	case '2':
		  _setcursortype(_NORMALCURSOR);
		  D3.remove_cinema();
		  break;

	case '3':
		 _setcursortype(_NORMALCURSOR);
		 D3.view_cinema();
		 break;

	case '4':
		 _setcursortype(_NORMALCURSOR);
		 D3.modify_cinema();
		 break;

	case '5':
		_setcursortype(_NORMALCURSOR);
		 D3.search_cinema();
		 break;

	case '6': return;
     }
    } while(choice != 7);
}


//************************************************************************
void cinema_details::add_cinema(){
	l1:
	ofstream fout;
	ifstream fin;
	//ifstream inf;
	shape s;
	clrscr();
	cleardevice();
	gotoxy(25,2);
	printf(" F O R M - F O R - C I N E M A");
	s.box(5,3,70,5);
	gotoxy(20,4);
	cout<<"Name: ";
	s.box(5,6,70,8);
	gotoxy(20,7);
	cout<<"Address: ";
	s.box(5,9,70,11);
	gotoxy(20,10);
	cout<<"Manager: ";
	s.box(5,12,70,14);
	gotoxy(20,13);
	cout<<"No_Of_Staff: ";
	s.box(5,15,70,17);
	gotoxy(20,16);
	cout<<"Phone Number: ";
	
	gotoxy(27,4);
	char Name[20];
	cin>>Name;
	fin.open("AddCinema.bin",ios::in|ios::binary);
	fin.read((char*)&C,sizeof(C));
	while(fin)
	{
		if(strcmp(Name,C.name)==0)
		{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"NAME-ALREADY-EXIST !! ENTER VALID NAME . . . ";
			getch();
			goto l1;
		}
		fin.read((char*)&C,sizeof(C));
	}
	fin.close();
	
	strcpy(C.name,Name);
	cin.ignore();
	gotoxy(29,7);
	cin>>C.address;
	cin.ignore();
	
	gotoxy(29,10);
	char Manager[20];
	cin>>Manager;
	ifstream inf;
	inf.open("AddManager.bin",ios::in|ios::binary);
	inf.read((char*)&M,sizeof(M));
	while(inf)
	{
		if(strcmp(Manager,M.name)==0)
		{
			goto u1;
		}
		inf.read((char*)&M,sizeof(M));
	}
	if(strcmp(Manager,M.name)!=0)
		{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"ID-DOESN'T-EXIST !! ENTER VALID MANAGER ID . . . ";
			getch();
			goto l1;
		}	
		
	u1:	
	inf.close();
	strcpy(C.manager,Manager);

	
	gotoxy(33,13);
	cin>>C.no_of_staff;
	cin.ignore();
	gotoxy(34,16);
	cin>>C.phnum;
	if(strlen(C.phnum)!=10)
	{
		s.box(5,23,70,25);
		gotoxy(15,24);
		cout<<"Invalid-Phone-Number-Entered! Try Again . . .";
		getch();
		goto l1;
	}
	cin.ignore();
	fout.open("AddCinema.bin",ios::app|ios::binary);
	fout.write((char*)&C,sizeof(C));
	s.box(5,23,70,25);
	gotoxy(15,24);
	cout<<"R E C O R D S - A D D E D - S U C C E S S F U L L Y !!!"<<endl;
	fout.close();
	getch();
}

void cinema_details::view_cinema(){
	shape s;
	ifstream fin;
	fin.open("AddCinema.bin",ios::in|ios::binary);
	fin.read((char*)&C,sizeof(C));
	if(!fin) {
		cout<<endl;
        cout<<"No Records Found!"<<endl;
        getch();
   }
   else{
	s.box(1,2,80,25);
	s.line_hor(2,79,3,196);
	s.line_ver(4,23,29,179);
	s.line_ver(4,23,41,179);
	s.line_ver(4,23,58,179);
	s.line_ver(4,23,68,179);
	gotoxy(25,2);
	printf(" C I N E M A - R E C O R D S ");

	gotoxy(3,4);
	cout<<"NAME";
	gotoxy(31,4);
	cout<<"ADDRESS";
	gotoxy(43,4);
	cout<<"MANAGER";
	gotoxy(60,4);
	cout<<"no_staff";
	gotoxy(70,4);
	cout<<"PH_NUM";
	s.line_hor(2,79,5,196);
	int y=6;
	while(fin)
	{
		gotoxy(3,y);
		cout<<C.name;
		gotoxy(31,y);
		cout<<C.address;
		gotoxy(43,y);
		cout<<C.manager;
		gotoxy(60,y);
		cout<<C.no_of_staff;
		gotoxy(70,y);
		cout<<C.phnum<<endl;
		fin.read((char*)&C,sizeof(C));
		y++;
		s.line_hor(2,79,y,196);
		y++;

	}
	}

	fin.close();
	getch();
}

void cinema_details::remove_cinema(){
	clrscr();
	cleardevice();
	shape s;
	ofstream fout;
	fout.open("NewCinema.bin",ios::out|ios::binary);
	char id[20];
	ifstream fin;
	s.box(1,1,80,8);
	gotoxy(20,2);
	cout<<"Enter the Cinema Name to Remove: ";
	s.line_hor(2,79,3,196);
	gotoxy(53,2);
	cin>>id;
	fin.open("AddCinema.bin",ios::in|ios::binary);
	fin.read((char*)&C,sizeof(C));
	while(!fin.eof())
	{
		if(strcmp(id,C.name)==0)
		{
		s.line_ver(4,7,29,179);
		s.line_ver(4,7,40,179);
		s.line_ver(4,7,60,179);
		s.line_ver(4,7,68,179);
		gotoxy(3,5);
		cout<<"NAME";
		gotoxy(30,5);
		cout<<"ADDRESS";
		gotoxy(42,5);
		cout<<"MANAGER";
		gotoxy(62,5);
		cout<<"STAFF";
		gotoxy(70,5);
		cout<<"Contact";
		s.line_hor(2,79,6,196);
		gotoxy(3,7);
		cout<<C.name;
		gotoxy(30,7);
		cout<<C.address;
		gotoxy(42,7);
		cout<<C.manager;
		gotoxy(62,7);
		cout<<C.no_of_staff;
		gotoxy(70,7);
		cout<<C.phnum;

		char ch;
		s.box(10,11,70,13);
		gotoxy(17,12);
	
		cout<<"Are you sure You want to Delete this record?(Y/N): ";
		gotoxy(20,52);
		ch=getch();
		if(ch=='Y'||ch=='y'){
			//s.box(5,23,70,25);
			gotoxy(12,12);
			cout<<"R E C O R D - R E M O V E D - S U C C E S S F U L L Y !!!";
		}
		else
		{
			return;
		}
		getch();
		}
		else{
			fout.write((char*)&C,sizeof(C));
		}
		fin.read((char*)&C,sizeof(C));
	}
	fout.close();
	fin.close();
	remove("AddCinema.bin");
	rename("NewCinema.bin","AddCinema.bin");
	getch();
}

void cinema_details::modify_cinema(){
	l1:
	clrscr();
	cleardevice();
	shape s;
	ofstream fout;
	ifstream fin;
//	ifstream inf;
	fout.open("NewCinema.bin",ios::out|ios::binary);
	char id[20];
	s.box(1,1,80,19);
	gotoxy(20,2);
	cout<<"Enter the Cinema Name to Edit: ";
	s.line_hor(2,79,3,196);
	gotoxy(51,2);
	cin>>id;
	fin.open("AddCinema.bin",ios::in|ios::binary);
	fin.read((char*)&C,sizeof(C));
	while(!fin.eof())
	{
		if(strcmp(id,C.name)==0)
		{

		gotoxy(25,4);
		cout<<"PREVIOUS RECORDS";
		s.line_hor(2,79,5,196);
		s.line_ver(6,10,29,179);
		s.line_ver(6,10,40,179);
		s.line_ver(6,10,60,179);
		s.line_ver(6,10,68,179);
		gotoxy(3,7);
		cout<<"NAME";
		gotoxy(30,7);
		cout<<"ADDRESS";
		gotoxy(42,7);
		cout<<"MANAGER";
		gotoxy(62,7);
		cout<<"STAFF";
		gotoxy(70,7);
		cout<<"Contact";
		s.line_hor(2,79,8,196);
		gotoxy(3,9);
		cout<<C.name;
		gotoxy(30,9);
		cout<<C.address;
		gotoxy(42,9);
		cout<<C.manager;
		gotoxy(62,9);
		cout<<C.no_of_staff;
		gotoxy(70,9);
		cout<<C.phnum;
		s.line_hor(2,79,11,196);

			gotoxy(25,12);
			cout<<"NEW RECORDS";
			s.line_hor(2,79,13,196);
			s.line_ver(14,18,28,179);
			s.line_ver(14,18,40,179);
			s.line_ver(14,18,60,179);
			s.line_ver(14,18,68,179);
		
		gotoxy(3,15);
		cout<<"NAME";
		gotoxy(30,15);
		cout<<"ADDRESS";
		gotoxy(42,15);
		cout<<"MANAGER";
		gotoxy(62,15);
		cout<<"STAFF";
		gotoxy(70,15);
		cout<<"Contact";
		s.line_hor(2,79,16,196);
		gotoxy(3,17);
		cin>>C.name;
		gotoxy(30,17);
		cin>>C.address;
		
		gotoxy(42,17);
		char Manager[20];
		cin>>Manager;
		ifstream inf;
		inf.open("AddManager.bin",ios::in|ios::binary);
		inf.read((char*)&M,sizeof(M));
		while(inf)
		{
		if(strcmp(Manager,M.name)==0)
			{
			goto u1;
			}
		inf.read((char*)&M,sizeof(M));
		}
	if(strcmp(Manager,M.name)!=0)
		{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"ID-DOESN'T-EXIST !! ENTER VALID MANAGER ID . . . ";
			getch();
			goto l1;
		}
		
	u1:		
	inf.close();
	strcpy(C.manager,Manager);
	

		gotoxy(62,17);
		cin>>C.no_of_staff;
		gotoxy(70,17);
		cin>>C.phnum;
		if(strlen(C.phnum)!=10)
		{
			s.box(10,22,70,24);
			gotoxy(12,23);
			cout<<"Invalid-Phone-Number-Entered! Try Again . . .";
			getch();
			goto l1;
		}
			
			s.box(10,22,70,24);
			gotoxy(12,23);
			cout<<"R E C O R D - U P D A T E D - S U C C E S S F U L L Y !!!";
			fout.write((char*)&C,sizeof(C));
		}
		else{
			fout.write((char*)&C,sizeof(C));
		}
		fin.read((char*)&C,sizeof(C));
	}
	fout.close();
	fin.close();
	remove("AddCinema.bin");
	rename("NewCinema.bin","AddCinema.bin");
	getch();
}

void cinema_details::search_cinema(){
	clrscr();
	cleardevice();
	char id[20];
	shape s;
	ifstream fin;
	label1:
	s.box(5,1,70,3);
	gotoxy(25,2);
	cout<<"Enter the Cinema Name to Search: ";
	cin>>id;
	fin.open("AddCinema.bin",ios::in|ios::binary);
	fin.read((char*)&C,sizeof(C));
	while(!fin.eof())
	{
		if(strcmp(id,C.name)==0)
		{
			s.box(5,5,70,25);
			s.box(20,6,60,8);
			gotoxy(25,7);
			cout<<"NAME: "<<C.name;
			s.box(20,9,60,11);
			gotoxy(25,10);
			cout<<"ADDRESS: "<<C.address;
			s.box(20,12,60,14);
			gotoxy(25,13);
			cout<<"MANAGER: "<<C.manager;
			s.box(20,15,60,17);
			gotoxy(25,16);
			cout<<"NO_OF_STAFF: "<<C.no_of_staff;
			s.box(20,18,60,20);
			gotoxy(25,19);
			cout<<"NO_OF_AUDI: "<<"1";
			s.box(20,21,60,23);
			gotoxy(25,22);
			cout<<"PHONE NUMBER: "<<C.phnum;
		}
		fin.read((char*)&C,sizeof(C));
	}
	fin.close();
	getch();
}
//************************************************************************

char admin::manage_movies(){
	clrscr();
	cleardevice();
	shape s;
  	s.box(20,6,65,20);
  	s.box(18,4,67,22);
  	gotoxy(34,5);
  	printf("M A N A G E - M O V I E");
  	for(int i=1;i<6;i++)
  	s.normalvideo(32,i+10,g[i]);
  	s.reversevideo(32,10,g[0]);
  	i=done=0;
  	_setcursortype(_NOCURSOR);
   do{
   		int key =getch();
   switch(key)
   {
   		case 00:
	  			key = getch();
	  		switch(key)
	  				{
	  					case 72:
	      						s.normalvideo(32,i+10,g[i]);
	     						 i--;
	      						if(i==-1)
	      						i=5;
	      						s.reversevideo(32,i+10,g[i]);
	      						break;
	  					case 80:
	      						s.normalvideo(32,i+10,g[i]);
	      						i++;
	     						if(i==6)
	      						i=0;
	      						s.reversevideo(32,i+10,g[i]);
	      						break;
	  				}
	  		break;

   		case 13:
	  			done = 1;
   				}
   		}
   	while(!done);
  	_setcursortype(_NOCURSOR);
   	return(i+49);
}
void admin::movie_control(){
    movie_details D4;
	shape s;
    char choice;
    do
    {
     choice = manage_movies();
     clrscr();
	 cleardevice();
     switch(choice){

	case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		D4.add_movie();
		break;

	case '2':
		  _setcursortype(_NORMALCURSOR);
		  D4.remove_movie();
		  break;

	case '3':
		 _setcursortype(_NORMALCURSOR);
		 D4.view_movie();
		 break;

	case '4':
		 _setcursortype(_NORMALCURSOR);
		 D4.modify_movie();
		 break;

	case '5':
		_setcursortype(_NORMALCURSOR);
		 D4.search_movie();
		 break;

	case '6': return;
     }
    } while(choice != 7);
}

//************************************************************************
void movie_details::add_movie(){
	l1:
	ofstream fout;
	ifstream fin;
	shape s;
	clrscr();
	cleardevice();
	gotoxy(25,2);
	cout<<"F O R M - F O R - M O V I E"<<endl;
	s.box(5,3,70,5);
	gotoxy(20,4);
	cout<<"Name: ";
	s.box(5,6,70,8);
	gotoxy(20,7);
	cout<<"Release_Date(Y/M/D): ";
	gotoxy(46,7);
	cout<<"/";
	gotoxy(49,7);
	cout<<"/";
	s.box(5,9,70,11);
	gotoxy(20,10);
	cout<<"Director: ";
	s.box(5,12,70,14);
	gotoxy(20,13);
	cout<<"Time_Of_Show(1st/2nd): ";
	gotoxy(52,13);
	cout<<"|";
	gotoxy(26,4);
	char Name[20];
	cin>>Name;
	fin.open("AddMovie.bin",ios::in|ios::binary);
	fin.read((char*)&D,sizeof(D));
	while(fin)
	{
		if(strcmp(Name,D.name)==0)
		{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"NAME-ALREADY-EXIST !! ENTER VALID NAME . . . ";
			getch();
			goto l1;
		}
		fin.read((char*)&D,sizeof(D));
	}
	fin.close();
	
	strcpy(D.name,Name);
	cin.ignore();
	char Date[20],year[5],month[5],day[5];
	gotoxy(42,7);
	cin>>year;
			if(strlen(year)!=4)
			{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"INVALID-DATE-FORMAT-ENTERED !! TRY AGAIN . . .";
			getch();
			goto l1;
			}
			gotoxy(47,7);
			cin>>month;
			if(strlen(month)!=2)
			{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"INVALID-DATE-FORMAT-ENTERED !! TRY AGAIN . . .";
			getch();
			goto l1;
			}
			gotoxy(50,7);
			cin>>day;
			if(strlen(day)!=2)
			{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"INVALID-DATE-FORMAT-ENTERED !! TRY AGAIN . . .";
			getch();
			goto l1;
			}
			strcpy(Date,year);
			strcat(Date,"/");
			strcat(Date,month);
			strcat(Date,"/");
			strcat(Date,day);
			strcpy(D.date,Date);
	cin.ignore();
	gotoxy(31,10);
	cin>>D.director;
	cin.ignore();
	gotoxy(44,13);
	cin>>D.time1;
	cin.ignore();
	gotoxy(55,13);
	cin>>D.time2;
	cin.ignore();
	
	fout.open("AddMovie.bin",ios::app|ios::binary);
	fout.write((char*)&D,sizeof(D));
	s.box(5,23,70,25);
	gotoxy(15,24);
	cout<<"R E C O R D S - A D D E D - S U C C E S S F U L L Y !!!"<<endl;
	fout.close();
	getch();
}

void movie_details::view_movie(){
	shape s;
	ifstream fin;
	fin.open("AddMovie.bin",ios::in|ios::binary);
	fin.read((char*)&D,sizeof(D));
	if(!fin) {
		cout<<endl;
        cout<<"No Records Found!"<<endl;
        getch();
   }
   else{
	s.box(1,2,80,25);
	s.line_hor(2,79,3,196);
	s.line_ver(4,23,29,179);
	s.line_ver(4,23,43,179);
	s.line_ver(4,23,61,179);
	gotoxy(25,2);
	printf(" M O V I E - R E C O R D S ");

	gotoxy(3,4);
	cout<<"NAME";
	gotoxy(32,4);
	cout<<"RELEASE";
	gotoxy(45,4);
	cout<<"DIRECTOR";
	gotoxy(63,4);
	cout<<"TIME ";
	s.line_hor(2,79,5,196);
	int y=6;
	while(fin)
	{
		gotoxy(3,y);
		cout<<D.name;
		gotoxy(32,y);
		cout<<D.date;
		gotoxy(45,y);
		cout<<D.director;
		gotoxy(63,y);
		cout<<D.time1<<"|"<<D.time2;
		fin.read((char*)&D,sizeof(D));
		y++;
		s.line_hor(2,79,y,196);
		y++;

	}
	}
	fin.close();
	getch();
}

void movie_details::remove_movie(){
	clrscr();
	cleardevice();
	shape s;
	ofstream fout;
	fout.open("NewMovie.bin",ios::out|ios::binary);
	char id[20];
	ifstream fin;
	s.box(1,1,80,8);
	gotoxy(20,2);
	cout<<"Enter the Movie Name to Remove: ";
	s.line_hor(2,79,3,196);
	gotoxy(52,2);
	cin>>id;
	fin.open("AddMovie.bin",ios::in|ios::binary);
	fin.read((char*)&D,sizeof(D));
	while(!fin.eof())
	{
		if(strcmp(id,D.name)==0)
		{
		s.line_ver(4,7,29,179);
		s.line_ver(4,7,43,179);
		s.line_ver(4,7,61,179);
		gotoxy(3,4);
		cout<<"NAME";
		gotoxy(32,5);
		cout<<"RELEASE";
		gotoxy(45,5);
		cout<<"DIRECTOR";
		gotoxy(63,5);
		cout<<"TIME ";
		s.line_hor(2,79,6,196);
		gotoxy(3,7);
		cout<<D.name;
		gotoxy(32,7);
		cout<<D.date;
		gotoxy(45,7);
		cout<<D.director;
		gotoxy(63,7);
		cout<<D.time1<<"|"<<D.time2;
		
		
		char ch;
		s.box(10,11,70,13);
		gotoxy(17,12);
		cout<<"Are you sure You want to Delete this record?(Y/N): ";
		gotoxy(20,52);
		ch=getch();
		if(ch=='Y'||ch=='y'){
			//s.box(5,23,70,25);
			gotoxy(12,12);
			cout<<"R E C O R D - R E M O V E D - S U C C E S S F U L L Y !!!";
		}
		else
		{
			return;
		}
		getch();
		}
		else{
			fout.write((char*)&D,sizeof(D));
		}
		fin.read((char*)&D,sizeof(D));
	}
	fout.close();
	fin.close();
	remove("AddMovie.bin");
	rename("NewMovie.bin","AddMovie.bin");
	getch();
}

void movie_details::modify_movie(){
	l1:
	clrscr();
	cleardevice();
	shape s;
	ofstream fout;
	fout.open("NewMovie.bin",ios::out|ios::binary);
	char id[20];
	ifstream fin;
	s.box(1,1,80,19);
	gotoxy(20,2);
	cout<<"Enter the Movie Name to Edit: ";
	s.line_hor(2,79,3,196);
	gotoxy(50,2);
	cin>>id;
	fin.open("AddMovie.bin",ios::in|ios::binary);
	fin.read((char*)&D,sizeof(D));
	while(!fin.eof())
	{
		if(strcmp(id,D.name)==0)
		{
		gotoxy(25,4);
		cout<<"PREVIOUS RECORDS";
		s.line_hor(2,79,5,196);
		s.line_ver(6,10,27,179);
		s.line_ver(6,10,43,179);
		s.line_ver(6,10,61,179);
		gotoxy(3,7);
		cout<<"NAME";
		gotoxy(29,7);
		cout<<"RELEASE(Y/M/D)";
		gotoxy(45,7);
		cout<<"DIRECTOR";
		gotoxy(63,7);
		cout<<"TIME";
		s.line_hor(2,79,16,196);
		gotoxy(3,9);
		cout<<D.name;
		gotoxy(29,9);
		cout<<D.date;
		gotoxy(45,9);
		cout<<D.director;
		gotoxy(63,9);
		cout<<D.time1<<"|"<<D.time2;

			gotoxy(25,12);
			cout<<"NEW RECORDS";
			s.line_hor(2,79,13,196);
			s.line_ver(14,18,27,179);
			s.line_ver(14,18,43,179);
			s.line_ver(14,18,61,179);
			gotoxy(3,15);
			cout<<"NAME";
			gotoxy(29,15);
			cout<<"RELEASE(Y/M/D)";
			gotoxy(33,17);
			cout<<"/";
			gotoxy(36,17);
			cout<<"/";
			gotoxy(45,15);
			cout<<"DIRECTOR";
			gotoxy(63,15);
			cout<<"TIME ";
			gotoxy(70,17);
			cout<<"|";
			s.line_hor(2,79,16,196);
			gotoxy(3,17);
			cin>>D.name;
			char Date[20],year[5],month[5],day[5];
			gotoxy(29,17);
			cin>>year;
			if(strlen(year)!=4)
			{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"INVALID-DATE-FORMAT-ENTERED !! TRY AGAIN . . .";
			getch();
			goto l1;
			}
			gotoxy(34,17);
			cin>>month;
			if(strlen(month)!=2)
			{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"INVALID-DATE-FORMAT-ENTERED !! TRY AGAIN . . .";
			getch();
			goto l1;
			}
			gotoxy(37,17);
			cin>>day;
			if(strlen(day)!=2)
			{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"INVALID-DATE-FORMAT-ENTERED !! TRY AGAIN . . .";
			getch();
			goto l1;
			}
			strcpy(Date,year);
			strcat(Date,"/");
			strcat(Date,month);
			strcat(Date,"/");
			strcat(Date,day);
			strcpy(D.date,Date);
			gotoxy(45,17);
			cin>>D.director;
			gotoxy(63,17);
			cin>>D.time1;
			gotoxy(72,17);
			cin>>D.time2;
			
			s.box(5,23,70,25);
			gotoxy(12,24);
			cout<<"R E C O R D - U P D A T E D - S U C C E S S F U L L Y !!!";
			fout.write((char*)&D,sizeof(D));
		}
		else{
			fout.write((char*)&D,sizeof(D));
		}
		fin.read((char*)&D,sizeof(D));
	}
	fout.close();
	fin.close();
	remove("AddMovie.bin");
	rename("NewMovie.bin","AddMovie.bin");
	getch();
}
void movie_details::search_movie(){
	clrscr();
	cleardevice();
	shape s;
	char id[20];
	ifstream fin;
	label1:
	s.box(5,1,70,3);
	gotoxy(25,2);
	cout<<"Enter the Movie Name to Search: ";
	cin>>id;
	fin.open("AddMovie.bin",ios::in|ios::binary);
	fin.read((char*)&D,sizeof(D));
	while(!fin.eof())
	{
		if(strcmp(id,D.name)==0)
		{
			s.box(5,5,70,25);
			s.box(20,6,60,8);
			gotoxy(25,7);
			cout<<"NAME: "<<D.name;
			s.box(20,9,60,11);
			gotoxy(25,10);
			cout<<"RELEASE_DATE: "<<D.date;
			s.box(20,12,60,14);
			gotoxy(25,13);
			cout<<"DIRECTOR: "<<D.director;
			s.box(20,15,60,17);
			gotoxy(25,16);
			cout<<"TIME_OF_SHOW: "<<D.time1<<" | "<<D.time2;
		}
		fin.read((char*)&D,sizeof(D));
	}
	fin.close();
	getch();
}
//************************************************************************

char manager::manager_menu(){
	clrscr();
	cleardevice();
	shape s;
	s.box(20,6,65,20);
	s.box(18,4,67,22);
	gotoxy(30,5);
	printf("M A N A G E R - M E N U");
	for(int i=1;i<4;i++)
	s.normalvideo(32,i+10,c[i]);
	s.reversevideo(32,10,c[0]);
	i=done=0;
	_setcursortype(_NOCURSOR);
	do{
		int key =getch();
		switch(key)
		{
			case 00:
			key = getch();
			switch(key)
		{
	case 72:
	      s.normalvideo(32,i+10,c[i]);
	      i--;
	      if(i==-1)
	      i=3;
	      s.reversevideo(32,i+10,c[i]);
	      break;
	case 80:
	      s.normalvideo(32,i+10,c[i]);
	      i++;
	      if(i==4)
	      i=0;
	      s.reversevideo(32,i+10,c[i]);
	      break;
	  }
	  break;

	case 13:
		done = 1;
	}
   }
	while(!done);
	_setcursortype(_NOCURSOR);
	return(i+49);
   }

void login::manager_login(){
	clrscr();
	cleardevice();
	shape s;
	manager ma;
	ifstream fin;
	admin a;
	login l;
	char id[20],password[20];
	s.box(20,6,65,20);
	s.box(18,4,67,22);
	gotoxy(30,5);
	printf("M A N A G E R - L O G I N");
	s.box(30,8,60,10);
	gotoxy(32,9);
	cout<<"Username: " ;
	s.box(30,12,60,14);
	gotoxy(32,13);
	cout<<"Password: ";
	gotoxy(42,9);
	cin>>id;
	gotoxy(42,13);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			password[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				password[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			password[i]=ch;
			i++;
			cout<<"*";
		}
	}
	fin.open("AddManager.bin",ios::in|ios::binary);
	fin.read((char*)&M,sizeof(M));
	if(!fin){
		gotoxy(30,16);
        cout<<"No Records Found !! ";
        getch();
        return;
   		}
	while(!fin.eof())
	{
		if(strcmp(id,M.userid)==0)
		{
			if(strcmp(password,M.pass)==0)
			{
			gotoxy(30,16);
			cout<<"L O G I N - S U C C E S S F U L!!";
			getch();
			ma.control_menu();
			}
			else
			{
			gotoxy(32,16);
			cout<<"Error!! please try again ";
			getch();
			l.manager_login();
			}
		}
		fin.read((char*)&M,sizeof(M));
	}
	fin.close();
	getch();
}

void manager::control_menu()
{
	admin a;
	staff st;
    shape s;
	char choice;
    do
    {
     choice = manager_menu();
     clrscr();
	 cleardevice();
     switch(choice){

	case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		a.staff_control();
		break;

	case '2':
		  _setcursortype(_NORMALCURSOR);
		 a.movie_control();
		  break;

	case '3':
		 _setcursortype(_NORMALCURSOR);
		 st.control_menu2();
		 break;

	case '4': return;
     }
    } while(choice != 5);
}
/*****************************************************************
			functions for class staff
*/////////////////////////////////////////////////////////////////
//****************************************************************

char staff::staff_menu(){
  clrscr();
  cleardevice();
  shape s;
  s.box(20,6,65,20);
  s.box(18,4,67,22);
  gotoxy(32,5);
  printf("S T A F F - M E N U");
  for(int i=1;i<3;i++)
  s.normalvideo(32,i+10,d[i]);
  s.reversevideo(32,10,d[0]);
  i=done=0;
  _setcursortype(_NOCURSOR);
   do{
   int key =getch();
   switch(key)
   {
   case 00:
	  key = getch();
	  switch(key)
	  {
	  case 72:
	      s.normalvideo(32,i+10,d[i]);
	      i--;
	      if(i==-1)
	      i=2;
	      s.reversevideo(32,i+10,d[i]);
	      break;
	  case 80:
	      s.normalvideo(32,i+10,d[i]);
	      i++;
	      if(i==3)
	      i=0;
	      s.reversevideo(32,i+10,d[i]);
	      break;
	  }
	  break;

   case 13:
	  done = 1;
   }
   }
   while(!done);
   _setcursortype(_NOCURSOR);
   return(i+49);
}

void login::staff_login(){
	clrscr();
	cleardevice();
	staff st;
	shape s;
	ifstream fin;
	admin a;
	login l;
	char id[20],password[20];
	s.box(20,6,65,20);
	s.box(18,4,67,22);
	gotoxy(30,5);
	printf("S T A F F - L O G I N");
	s.box(30,8,60,10);
	gotoxy(32,9);
	cout<<"Username: " ;
	s.box(30,12,60,14);
	gotoxy(32,13);
	cout<<"Password: ";
	gotoxy(42,9);
	cin>>id;
	gotoxy(42,13);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			password[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				password[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			password[i]=ch;
			i++;
			cout<<"*";
		}
	}
	fin.open("AddStaff.bin",ios::in|ios::binary);
	fin.read((char*)&S,sizeof(S));
	if(!fin){
		gotoxy(30,16);
        cout<<"No Records Found !! ";
        getch();
        return;
   		}
	while(!fin.eof())
	{
		if(strcmp(id,S.userid)==0)
		{
			if(strcmp(password,S.pass)==0)
			{
			gotoxy(30,16);
			cout<<"L O G I N - S U C C E S S F U L!!";
			getch();
			st.control_menu();
			}
			else
			{
			gotoxy(32,16);
			cout<<"Error!! please try again ";
			getch();
			l.staff_login();
			}
		}
		fin.read((char*)&S,sizeof(S));
	}
	fin.close();
	getch();
}

void staff::control_menu()
{
	staff st;
	shape s;
    char choice;
    do
    {
     choice = staff_menu();
     clrscr();
	 cleardevice();
     switch(choice){

	case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		st.control_menu2(); 
		break;

	case '2': return;
     }
    } while(choice != 3);
}
/*****************************************************************
			functions for class staff
*/////////////////////////////////////////////////////////////////
char staff::manage_customer()
{
	clrscr();
	cleardevice();
	shape s;
  s.box(20,6,65,20);
  s.box(18,4,67,22);
  gotoxy(34,5);
  printf("M A N A G E - C U S T O M E R");
  for(int i=1;i<5;i++)
  s.normalvideo(32,i+10,h[i]);
  s.reversevideo(32,10,h[0]);
  i=done=0;
  _setcursortype(_NOCURSOR);
   do{
   int key =getch();
   switch(key)
   {
   case 00:
	  key = getch();
	  switch(key)
	  {
	  case 72:
	      s.normalvideo(32,i+10,h[i]);
	      i--;
	      if(i==-1)
	      i=4;
	      s.reversevideo(32,i+10,h[i]);
	      break;
	  case 80:
	      s.normalvideo(32,i+10,h[i]);
	      i++;
	      if(i==5)
	      i=0;
	      s.reversevideo(32,i+10,h[i]);
	      break;
	  }
	  break;

   case 13:
	  done = 1;
   }
   }
   while(!done);
   _setcursortype(_NOCURSOR);
   return(i+49);
}

void staff::control_menu2(){
    customer_details C1;
    shape s;
	char choice;
    do
    {
     choice = manage_customer();
     clrscr();
	 cleardevice();
     switch(choice){

	case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		C1.view_customer();
		break;

	case '2':
		  _setcursortype(_NORMALCURSOR);
		  C1.remove_customer();
		  break;

	case '3':
		 _setcursortype(_NORMALCURSOR);
		 C1.modify_customer();
		 break;

	case '4':
		 _setcursortype(_NORMALCURSOR);
		 C1.search_customer();
		 break;

	case '5':
		return;
     }
    } while(choice != 6);
}


void customer_details::add_customer()
{
	l1:
	clrscr();
	cleardevice();
	shape s;
	ifstream fin;
	ofstream fout;
	s.box(20,6,65,20);
	s.box(18,4,67,22);
	gotoxy(30,5);
	printf("A D D - C U S T O M E R");
	//gotoxy(30,8);
	s.box(30,8,60,10);
	gotoxy(32,9);
	cout<<"Enter the Username: ";
	s.box(30,12,60,14);
	gotoxy(32,13);
	cout<<"Enter the Password: ";
	gotoxy(52,9);
	char user_ID[20];
	cin>>user_ID;
	fin.open("customer.bin",ios::in|ios::binary);
	fin.read((char*)&P,sizeof(P));
	while(fin)
	{
		if(strcmp(user_ID,P.userid)==0)
		{
			s.box(8,23,74,25);
			gotoxy(22,24);
			cout<<"ID-ALREADY-EXIST !! ENTER NEW ID . . . ";
			getch();
			goto l1;
		}
		fin.read((char*)&P,sizeof(P));
	}
	fin.close();
	
	strcpy(P.userid,user_ID);
	gotoxy(52,13);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			P.password[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				P.password[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			P.password[i]=ch;
			i++;
			cout<<"*";
		}
	}
	fout.open("customer.bin",ios::app|ios::binary);
	fout.write((char*)&P,sizeof(P));
	gotoxy(30,16);
	cout<<"RECORD - ADDED - SUCCESSFULLY!";
	fout.close();
	getch();
}

void customer_details::view_customer()
{
	shape s;
	ifstream fin;
	int count=0;
	fin.open("customer.bin",ios::in|ios::binary);
	fin.read((char*)&P,sizeof(P));
	if(!fin) {
		cout<<endl;
        cout<<"No Records Found!"<<endl;
        getch();
   }
   else{
	s.box(5,2,70,25);
	s.line_hor(6,69,4,196);
	//s.line_ver(5,23,10,179);
	s.line_ver(5,23,20,179);
	gotoxy(20,2);
	cout<<"C U S T O M E R - R E C O R D S : "<<endl;
	gotoxy(9,5);
	cout<<"S.N";
	gotoxy(25,5);
	cout<<"Customer Id";
	s.line_hor(5,69,6,196);
	int y=7,i=1,z=7;
	while(fin)
	{
		gotoxy(9,z);
		cout<<i;
		count=count+1;
		i++;
		gotoxy(25,y);
		cout<<P.userid;
		fin.read((char*)&P,sizeof(P));
		y++;
		z++;
		s.line_hor(6,69,y,196);
		y++;
		z++;
	}
	}
	cout<<endl<<endl;
	s.box(5,23,70,25);
	gotoxy(15,24);
	cout<<"Total No. Of Existing Customer is: "<<count;
	fin.close();
	getch();
}

void customer_details::remove_customer()
{
	clrscr();
	cleardevice();
	shape s;
	ofstream fout;
	fout.open("NewBooking.bin",ios::out|ios::binary);
	char id[20];
	ifstream fin;
	s.box(1,1,80,8);
	gotoxy(20,2);
	cout<<"Enter the Customer Id to Remove: ";
	s.line_hor(2,79,3,196);
	gotoxy(53,2);
	cin>>id;
	fin.open("Booking.bin",ios::in|ios::binary);
	fin.read((char*)&TB,sizeof(TB));
	while(!fin.eof())
	{
		if(strcmp(id,TB.name)==0)
		{
		s.line_ver(4,7,29,179);
		s.line_ver(4,7,46,179);
		s.line_ver(4,7,53,179);
		s.line_ver(4,7,68,179);
		gotoxy(3,5);
		cout<<"MOVIE NAME";
		gotoxy(31,5);
		cout<<"DATE OF SHOW";
		gotoxy(48,5);
		cout<<"TIME";
		gotoxy(55,5);
		cout<<"TOTAL TICKET";
		gotoxy(69,5);
		cout<<"TOTAL PRICE";
		s.line_hor(2,79,6,196);
		gotoxy(2,7);
		cout<<TB.movie;
		gotoxy(31,7);
		cout<<TB.date;
		gotoxy(48,7);
		cout<<TB.time;
		gotoxy(58,7);
		cout<<TB.ticket;
		gotoxy(70,7);
		cout<<TB.price;
		char ch;
		s.box(10,11,70,13);
		gotoxy(17,12);
	
		cout<<"Are you sure You want to Delete this record?(Y/N): ";
		gotoxy(20,52);
		ch=getch();
		if(ch=='Y'||ch=='y'){
			//s.box(5,23,70,25);
			gotoxy(12,12);
			cout<<"R E C O R D - R E M O V E D - S U C C E S S F U L L Y !!!";
		}
		else
		{
			return;
		}
		getch();
		}
		else{
			fout.write((char*)&TB,sizeof(TB));
		}
		fin.read((char*)&TB,sizeof(TB));
	}
	fout.close();
	fin.close();
	remove("Booking.bin");
	rename("NewBooking.bin","Booking.bin");
	getch();
	return;
}

void customer_details::modify_customer()
{
	
	return;
}

void customer_details::search_customer()
{
	clrscr();
	cleardevice();
	shape s;
	char id[20];
	ifstream fin;
	label1:
	s.box(5,1,70,3);
	gotoxy(25,2);
	cout<<"Enter the Customer Id to Search: ";
	cin>>id;
	fin.open("Booking.bin",ios::in|ios::binary);
	fin.read((char*)&TB,sizeof(TB));
	while(!fin.eof())
	{
		if(strcmp(id,TB.name)==0)
		{
			s.box(5,5,70,22);
			s.box(20,6,60,8);
			gotoxy(25,7);
			cout<<"MOVIE NAME: "<<TB.movie;
			s.box(20,9,60,11);
			gotoxy(25,10);
			cout<<"DATE OF SHOW: "<<TB.date;
			s.box(20,12,60,14);
			gotoxy(25,13);
			cout<<"TIME OF SHOW: "<<TB.time;
			s.box(20,15,60,17);
			gotoxy(25,16);
			cout<<"TOTAL TICKETS: "<<TB.ticket;
			s.box(20,18,60,20);
			gotoxy(25,19);
			cout<<"TOTAL PRICE: "<<TB.price;
		}
		fin.read((char*)&TB,sizeof(TB));
	}
	fin.close();
	getch();
	return;
}

//****************************************************************


char login::login_option(){
	clrscr();
	cleardevice();
	shape s;
  s.box(20,6,65,20);
  s.box(18,4,67,22);
  gotoxy(30,5);
  printf("L O G I N - O P T I O N ");
  for(int i=1;i<3;i++)
  s.normalvideo(32,i+10,f[i]);
  s.reversevideo(32,10,f[0]);
  i=done=0;
  _setcursortype(_NOCURSOR);
   do{
   int key =getch();
   switch(key)
   {
   case 00:
	  key = getch();
	  switch(key)
	  {
	  case 72:
	      s.normalvideo(32,i+10,f[i]);
	      i--;
	      if(i==-1)
	      i=2;
	      s.reversevideo(32,i+10,f[i]);
	      break;
	  case 80:
	      s.normalvideo(32,i+10,f[i]);
	      i++;
	      if(i==3)
	      i=0;
	      s.reversevideo(32,i+10,f[i]);
	      break;
	  }
	  break;

   case 13:
	  done = 1;
   }
   }
   while(!done);
   _setcursortype(_NOCURSOR);
   return(i+49);
}
void login::customer_control_menu(){
char ch;
shape s;
login l;
    do
    {
     ch = login_option();
     clrscr();
	 cleardevice();
     switch(ch){

	case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		l.customer_login(); //login customer
		break;

	case '2':
		  _setcursortype(_NORMALCURSOR);
		  l.customer_register(); //customer login();
		  break;

	case '3':
		return;

     }
    } while(ch != 4);

}

void login::customer_login(){
	clrscr();
	cleardevice();
	shape s;
	customer cu;
	login l;
	char id[20],pass[20];
	s.box(20,6,65,20);
	s.box(18,4,67,22);
	gotoxy(30,5);
	printf("C U S T O M E R - L O G I N");
	s.box(30,8,60,10);
	gotoxy(32,9);
	cout<<"Username: " ;
	s.box(30,12,60,14);
	gotoxy(32,13);
	cout<<"Password: ";
	gotoxy(42,9);
	cin>>id;
	gotoxy(42,13);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			pass[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				pass[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			pass[i]=ch;
			i++;
			cout<<"*";
		}
	}
	ifstream fin;
	fin.open("customer.bin",ios::in|ios::binary);
	fin.read((char*)&P,sizeof(P));
	if(!fin) {
		
		gotoxy(30,16);
        cout<<"No Records Found !! ";
        getch();
        return;
    }
	while(!fin.eof())
	{
		if(strcmp(id,P.userid)==0)
		{
			if(strcmp(pass,P.password)==0)
			{
			gotoxy(30,16);
			cout<<"L O G I N - S U C C E S S F U L!!";
			getch();
			cu.control_menu();
			}
			else
			{
			gotoxy(30,16);
			cout<<"Error!! please try again ";
			getch();
			l.customer_login();
			}
		}
		fin.read((char*)&P,sizeof(P));
	}
	fin.close();
}

void login::customer_register(){
	l1:
	clrscr();
	cleardevice();
	shape s;
	login l;
	ifstream fin;
	ofstream fout;
	//char password[20],userid[20];
	s.box(20,6,65,20);
	s.box(18,4,67,22);
	gotoxy(30,5);
	printf("C U S T O M E R - R E G I S T E R");
	//gotoxy(30,8);
	s.box(30,8,60,10);
	gotoxy(32,9);
	cout<<"Enter the Username: ";
	s.box(30,12,60,14);
	gotoxy(32,13);
	cout<<"Enter the Password: ";
	gotoxy(52,9);
	char user_ID[20];
	cin>>user_ID;
	fin.open("customer.bin",ios::in|ios::binary);
	fin.read((char*)&P,sizeof(P));
	while(fin)
	{
		if(strcmp(user_ID,P.userid)==0)
		{
			s.box(8,23,74,25);
			gotoxy(22,24);
			cout<<"ID-ALREADY-EXIST !! ENTER NEW ID . . . ";
			getch();
			goto l1;
		}
		fin.read((char*)&P,sizeof(P));
	}
	fin.close();
	
	strcpy(P.userid,user_ID);
	gotoxy(52,13);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			P.password[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				P.password[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			P.password[i]=ch;
			i++;
			cout<<"*";
		}
	}
	fout.open("customer.bin",ios::app|ios::binary);
	fout.write((char*)&P,sizeof(P));
	gotoxy(30,16);
	cout<<"Your Registration is Successfull!";
	gotoxy(30,17);
	cout<<"Redirectring to Login Page!!";
	getch();
	fout.close();
	l.customer_login();
}

char customer::customer_menu()
{
  clrscr();
  cleardevice();
  shape s;
  s.box(20,6,65,20);
  s.box(18,4,67,22);
  gotoxy(34,5);
  printf("C U S T O M E R - M E N U");
  for(int i=1;i<4;i++)
  s.normalvideo(32,i+10,e[i]);
  s.reversevideo(32,10,e[0]);
  i=done=0;
  _setcursortype(_NOCURSOR);
   do{
   int key =getch();
   switch(key)
   {
   case 00:
	  key = getch();
	  switch(key)
	  {
	  case 72:
	      s.normalvideo(32,i+10,e[i]);
	      i--;
	      if(i==-1)
	      i=3;
	      s.reversevideo(32,i+10,e[i]);
	      break;
	  case 80:
	      s.normalvideo(32,i+10,e[i]);
	      i++;
	      if(i==4)
	      i=0;
	      s.reversevideo(32,i+10,e[i]);
	      break;
	  }
	  break;

   case 13:
	  done = 1;
	  break;
   }
   }
   while(!done);
   _setcursortype(_NOCURSOR);
   return(i+49);
}

void customer::control_menu()
{
	book B;
    customer cu;
    shape s;
	char choice;
    do
    {
     choice = cu.customer_menu();
     clrscr();
	 cleardevice();
     switch(choice){

	case '1':
		_setcursortype(_NORMALCURSOR);
		s.box(3,1,75,24);
		s.box(4,2,73,23);
		gotoxy(10,10);
		cu.modify_password(); //admin menu
		break;

	case '2':
		  _setcursortype(_NORMALCURSOR);
		  cu.history(); //manager menu
		  break;

	case '3':
		 _setcursortype(_NORMALCURSOR);
		 B.booking(); //staff menu
		 break;

	case '4': return;
     }
    } while(choice != 5);
}
/*****************************************************************
			functions for class customers
*/////////////////////////////////////////////////////////////////
void customer::history(){
	clrscr();
    cleardevice();
	ifstream fin;
	shape s;
	fin.open("Booking.bin",ios::in|ios::binary);
	fin.read((char*)&TB,sizeof(TB));
	while(fin)
	{
		fin.read((char*)&TB,sizeof(TB));
	}
	s.box(20,6,65,20);
    s.box(18,4,67,22);
    gotoxy(25,5);
	cout<<"Your Details Are As Follows: ";
    gotoxy(25,7);
	cout<<"Customer Name: ";
    gotoxy(41,7);
    cout<<TB.name;
    s.line_hor(21,64,8,196);
    gotoxy(25,9);
	cout<<"Customer C.No: ";
    gotoxy(41,9);
    cout<<TB.phnum;
    s.line_hor(21,64,10,196);
    gotoxy(25,11);
	cout<<"Movie Name: ";
    gotoxy(41,11);
    cout<<TB.movie;
    s.line_hor(21,64,12,196);
	gotoxy(25,13);
    cout<<"Date Of Show: ";
    gotoxy(41,13);
    cout<<TB.date;
    s.line_hor(21,64,14,196);
    gotoxy(25,15);
	cout<<"Time Of Show: ";
    gotoxy(41,15);
    cout<<TB.time;
    s.line_hor(21,64,16,196);
    gotoxy(25,17);
	cout<<"Total Ticket: ";
    gotoxy(41,17);
    cout<<TB.ticket;
    s.line_hor(21,64,18,196);
    gotoxy(25,19);
	cout<<"Total Price: ";
    gotoxy(41,19);
    cout<<TB.price;
	getch();
	fin.close();
	getch();
	return;
	}

void customer::modify_password(){
	clrscr();
	cleardevice();
	shape s;
	login l;
	customer cu;
	char id[20],pass1[20],pass2[20],configpass[20];
	s.box(20,6,65,20);
	s.box(18,4,67,22);
	gotoxy(30,5);
	printf("CUSTOMER - CHANGE PASSWORD");
	s.box(30,8,60,10);
	gotoxy(32,9);
	cout<<"Username: " ;
	s.box(30,11,60,13);
	gotoxy(32,12);
	cout<<"Current Password: ";
	s.box(30,14,60,16);
	gotoxy(32,15);
	cout<<"New Password: ";
	s.box(30,17,60,19);
	gotoxy(32,18);
	cout<<"Configure Password: ";
	gotoxy(42,9);
	cin>>id;
	gotoxy(50,12);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			pass1[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				pass1[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			pass1[i]=ch;
			i++;
			cout<<"*";
		}
	}
	
	ofstream fout;
	ifstream fin;
	fout.open("new.bin",ios::out|ios::binary);
	fin.open("customer.bin",ios::in|ios::binary);
	fin.read((char*)&P,sizeof(P));
	while(!fin.eof())
	{
		if(strcmp(id,P.userid)==0)
		{
			if(strcmp(pass1,P.password)==0)
			{
				gotoxy(46,15);
				int i=0;
				char ch;
				while(1){
				ch=getch();
				if(ch==ENTER){
				pass2[i]='\0';
				break;
				}
				else if(ch==BKSP){
				if(i>0){
				i--;
				pass2[i]='\0';
				cout<<"\b \b";
				}
				}
				else if(ch==SPACE||ch==ESC||ch==TAB){
				continue;
				}
				else{
				pass2[i]=ch;
				i++;
				cout<<"*";
				}
				}
				
				gotoxy(52,18);
			    i=0;
				while(1){
				ch=getch();
				if(ch==ENTER){
				configpass[i]='\0';
				break;
				}
				else if(ch==BKSP){
				if(i>0){
				i--;
				configpass[i]='\0';
				cout<<"\b \b";
				}
				}
				else if(ch==SPACE||ch==ESC||ch==TAB){
				continue;
				}
				else{
				configpass[i]=ch;
				i++;
				cout<<"*";
				}
				}
				
				if(strcmp(pass2,configpass)==0)
				{
					gotoxy(30,23);
					cout<<"PASSWORD CHANGED SUCCESSFULLY !!";
					getch();
					strcpy(P.userid,id);
					strcpy(P.password,configpass);
					fout.write((char*)&P,sizeof(P));
					// goto label1;
				}
				else
				{
					gotoxy(30,23);
					cout<<"Error!! please try again ";
					getch();
					cu.modify_password();
				}
				
			}
			else
			{
			gotoxy(30,23);
			cout<<"Error!! please try again ";
			getch();
			cu.modify_password();
			}
		}
		else
		{
			fout.write((char*)&P,sizeof(P));
		}
		//label1:
		fin.read((char*)&P,sizeof(P));
	}
	
	fout.close();
	fin.close();
	remove("customer.bin");
	rename("new.bin","customer.bin");
}

void book::booking()
{
	l1:	
	clrscr();
	cleardevice();
	shape s;
	ofstream outfile;
    outfile.open("Booking.bin",ios::app|ios::binary);
	s.box(5,3,70,5);
	gotoxy(20,4);
	cout<<"Enter Valid Customer Id: ";
	gotoxy(45,4);
	cin>>TB.name;
	ifstream fin;
	fin.open("customer.bin",ios::in|ios::binary);
	fin.read((char*)&P,sizeof(P));
	while(fin)
	{
		if(strcmp(TB.name,P.userid)==0)
		{
			goto l0;
		}
		fin.read((char*)&P,sizeof(P));
	}
	if(strcmp(TB.name,P.userid)!=0)
		{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"ERROR!! INVALID ID PROVIDED, PLEASE TRY AGAIN . . . ";
			getch();
			goto l1;
		}
		
	l0:
	fin.close();
	s.box(5,6,70,8);
	gotoxy(20,7);
	cout<<"Enter Phone Number: ";
	gotoxy(40,7);
	cin>>TB.phnum;
	if(strlen(TB.phnum)!=10)
	{
		s.box(5,23,70,25);
		gotoxy(15,24);
		cout<<"ERROR!! INVALID PHONE NUMBER ENTERED, TRY AGAIIN . . .";
		getch();
		goto l1;
	}
	
	l2:
	clrscr();
	cleardevice();
	ifstream finn;
	s.box(20,6,65,20);
	s.box(18,4,67,22);
	finn.open("AddCinema.bin",ios::in|ios::binary);
	finn.read((char*)&C,sizeof(C));
	if(!finn) {
		s.box(5,23,70,25);
		gotoxy(15,24);
        cout<<"No Records Found!";
        getch();
        return;
    }
	gotoxy(25,5);
	cout<<"S.N";
	gotoxy(50,5);
	cout<<"CINEMA NAME";
	int y=7,i=1,count=0;
	while(finn)
	{
		gotoxy(25,y);
		cout<<i;
		count=count+1;
		i++;
		gotoxy(50,y);
		cout<<C.name;
		finn.read((char*)&C,sizeof(C));
		y++;
		s.line_hor(21,64,y,196);
        y++;
		
	}
	finn.close();
	s.box(5,23,70,25);
	gotoxy(15,24);
	cout<<"Enter Cinema Name You Want To Book: ";
	gotoxy(54,24);
	cin>>TB.cinema;
	
	ifstream ffin;
	ffin.open("AddCinema.bin",ios::in|ios::binary);
	ffin.read((char*)&C,sizeof(C));
	while(ffin)
	{
		if(strcmp(TB.cinema,C.name)==0)
		{
			goto l3;
			//return;
		}
		ffin.read((char*)&C,sizeof(C));
	}
	if(strcmp(TB.cinema,C.name)!=0)
	{
		s.box(5,23,70,25);
		gotoxy(15,24);
		cout<<"ERROR!! ENTER VALID CINEMA FROM ABOVE . . . ";
		getch();
		goto l2;
	}
	ffin.close();
	
	l3:
	clrscr();
	cleardevice();
	ifstream inf;
	inf.open("AddMovie.bin",ios::in|ios::binary);
	inf.read((char*)&D,sizeof(D));
    s.box(20,6,65,20);
	s.box(18,4,67,22);
	if(!inf) {
		s.box(5,23,70,25);
		gotoxy(15,24);
        cout<<"No Records Found!";
        getch();
        return;
    }
	gotoxy(25,5);
	cout<<"S.N";
	gotoxy(50,5);
	cout<<"Movie NAME";
	y=7,i=1,count=0;
	while(inf)
	{
		gotoxy(25,y);
		cout<<i;
		count=count+1;
		i++;
		gotoxy(50,y);
		cout<<D.name;
		inf.read((char*)&D,sizeof(D));
		y++;
        s.line_hor(21,64,y,196);
	y++;
	}
	inf.close();
	s.box(5,23,70,25);
	gotoxy(15,24);
	cout<<"Enter Movie Name You Want To Book: ";
    gotoxy(54,24);
	cin>>TB.movie;
	ifstream iin;
	iin.open("AddMovie.bin",ios::in|ios::binary);
	iin.read((char*)&D,sizeof(D));
	while(iin)
	{
		if(strcmp(TB.movie,D.name)==0)
		{
			goto l4;
		}
		iin.read((char*)&D,sizeof(D));
	}
	if(strcmp(TB.movie,D.name)!=0)
		{
			s.box(5,23,70,25);
			gotoxy(15,24);
			cout<<"ERROR!! ENTER VALID MOVIE FROM ABOVE . . . ";
			getch();
			goto l3;
		}
	iin.close();

	l4:
	clrscr();
	cleardevice();
	ifstream infile;
	infile.open("AddMovie.bin",ios::in|ios::binary);
	infile.read((char*)&D,sizeof(D));
    s.box(20,6,65,20);
	s.box(18,4,67,22);
	gotoxy(25,2);
	cout<<"Avalibale Date and time is: ";
	while(!infile.eof())
	{
		if(strcmp(TB.movie,D.name)==0)
		{
			cout<<D.date;
			strcpy(TB.date,D.date);
		}
		infile.read((char*)&D,sizeof(D));
	}
	infile.close();

	ifstream iff;
	iff.open("AddMovie.bin",ios::in|ios::binary);
	iff.read((char*)&D,sizeof(D));
    gotoxy(23,5);
	cout<<"S.N";
	gotoxy(40,5);
	cout<<"TIME 1";
    gotoxy(57,5);
    cout<<"TIME 2";
    y=7,i=1,count=0;
	while(!iff.eof())
	{
		if(strcmp(TB.movie,D.name)==0)
		{
        gotoxy(23,y);
		cout<<i;
		count=count+1;
		i++;
		gotoxy(40,y);
		cout<<D.time1;
		gotoxy(57,y);
		cout<<D.time2;
		//inf.read((char*)&D,sizeof(D));
		y++;
        s.line_hor(21,64,y,196);
	    y++;
			

            
		}
		iff.read((char*)&D,sizeof(D));
	}
	iff.close();
	s.box(5,23,70,25);
	gotoxy(15,24);
	cout<<"Enter appropriate time you want: ";
    gotoxy(54,24);
	cin>>TB.time;

	
	ifstream filein;
	filein.open("AddMovie.bin",ios::in|ios::binary);
	filein.read((char*)&D,sizeof(D));
	while(filein)
	{
		if(strcmp(TB.time,D.time1)==0||strcmp(TB.time,D.time2)==0)
		{
			goto l5;
		}
		filein.read((char*)&D,sizeof(D));
	}
	if(strcmp(TB.time,D.time1)!=0||strcmp(TB.time,D.time2)!=0)
	{
		s.box(5,23,70,25);
		gotoxy(15,24);
		cout<<"ERROR!! ENTER VALID TIME FROM ABOVE . . . ";
		getch();
		goto l4;
	}
	filein.close();
	

l5:
customer cu;
clrscr();
cleardevice();
char seat[20];
int w=23;
int total_price=0,total_ticket=0;
	//to book
	int x1=130,x2=186,y1=290,y2=325;
	settextstyle(2,0,5);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(x1-100,y1-280,x2+392,y2-280);
	floodfill(x1-100+1,y1-280+1,WHITE);
	outtextxy(x1-100,y1-280+14,"MOVIE NAME: ");
    outtextxy(x1-100+200,y1-280+14,"CINEMA NAME: ");
    outtextxy(x2+393-110,y1-280+14,"TIME OF SHOW:");
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(x1-100+1,y1-245+1,WHITE);
    rectangle(x1-100,y1-245,x2+392,y2-245);
    outtextxy(x1-100,y1-245+14,TB.movie);
    outtextxy(x1-100+200,y1-245+14,TB.cinema);
    outtextxy(x2+393-110,y1-245+14,TB.time);
    //column1
	
	setfillstyle(SOLID_FILL,CYAN);
    rectangle(x1-100,y1-175,x2-100,y2-175);
	floodfill(x1-100+1,y1-175+1,WHITE);
    rectangle(x1-100,y1-140,x2-100,y2-140);
	floodfill(x1-100+1,y1-140+1,WHITE);
    rectangle(x1-100,y1-105,x2-100,y2-105);
	floodfill(x1-100+1,y1-105+1,WHITE);
    rectangle(x1-100,y1-70,x2-100,y2-70);
	floodfill(x1-100+1,y1-70+1,WHITE);
    rectangle(x1-100,y1-35,x2-100,y2-35);
	floodfill(x1-100+1,y1-35+1,WHITE);

    //row5
	setfillstyle(SOLID_FILL,GREEN);
    rectangle(x1,y1-175,x2,y2-175);
	floodfill(x1+1,y1-175+1,WHITE);
    rectangle(x1+56,y1-175,x2+56,y2-175);
	floodfill(x1+56+1,y1-175+1,WHITE);
    rectangle(x1+112,y1-175,x2+112,y2-175);
	floodfill(x1+112+1,y1-175+1,WHITE);
    rectangle(x1+168,y1-175,x2+168,y2-175);
	floodfill(x1+168+1,y1-175+1,WHITE);
    rectangle(x1+224,y1-175,x2+224,y2-175);
	floodfill(x1+224+1,y1-175+1,WHITE);
    rectangle(x1+280,y1-175,x2+280,y2-175);
	floodfill(x1+280+1,y1-175+1,WHITE);
    rectangle(x1+336,y1-175,x2+336,y2-175);
	floodfill(x1+336+1,y1-175+1,WHITE);
    rectangle(x1+392,y1-175,x2+392,y2-175);
	floodfill(x1+392+1,y1-175+1,WHITE);
    //row4
    rectangle(x1,y1-140,x2,y2-140);
	floodfill(x1+1,y1-140+1,WHITE);
    rectangle(x1+56,y1-140,x2+56,y2-140);
	floodfill(x1+56+1,y1-140+1,WHITE);
    
	rectangle(x1+112,y1-140,x2+112,y2-140);
	floodfill(x1+112+1,y1-140+1,WHITE);
    rectangle(x1+168,y1-140,x2+168,y2-140);
	floodfill(x1+168+1,y1-140+1,WHITE);
    rectangle(x1+224,y1-140,x2+224,y2-140);
	floodfill(x1+224+1,y1-140+1,WHITE);
    rectangle(x1+280,y1-140,x2+280,y2-140);
	floodfill(x1+280+1,y1-140+1,WHITE);
    rectangle(x1+336,y1-140,x2+336,y2-140);
	floodfill(x1+336+1,y1-140+1,WHITE);
    rectangle(x1+392,y1-140,x2+392,y2-140);
	floodfill(x1+392+1,y1-140+1,WHITE);
    //row3
    rectangle(x1,y1-105,x2,y2-105);
	floodfill(x1+1,y1-105+1,WHITE);
    rectangle(x1+56,y1-105,x2+56,y2-105);
	floodfill(x1+56+1,y1-105+1,WHITE);
    rectangle(x1+112,y1-105,x2+112,y2-105);
	floodfill(x1+112+1,y1-105+1,WHITE);
    rectangle(x1+168,y1-105,x2+168,y2-105);
	floodfill(x1+168+1,y1-105+1,WHITE);
    rectangle(x1+224,y1-105,x2+224,y2-105);
	floodfill(x1+224+1,y1-105+1,WHITE);
    rectangle(x1+280,y1-105,x2+280,y2-105);
	floodfill(x1+280+1,y1-105+1,WHITE);
    rectangle(x1+336,y1-105,x2+336,y2-105);
	floodfill(x1+336+1,y1-105+1,WHITE);
    rectangle(x1+392,y1-105,x2+392,y2-105);
	floodfill(x1+392+1,y1-105+1,WHITE);
    //row2
    rectangle(x1,y1-70,x2,y2-70);
	floodfill(x1+1,y1-70+1,WHITE);
    rectangle(x1+56,y1-70,x2+56,y2-70);
	floodfill(x1+56+1,y1-70+1,WHITE);
    rectangle(x1+112,y1-70,x2+112,y2-70);
	floodfill(x1+112+1,y1-70+1,WHITE);
    rectangle(x1+168,y1-70,x2+168,y2-70);
	floodfill(x1+168+1,y1-70+1,WHITE);
    rectangle(x1+224,y1-70,x2+224,y2-70);
	floodfill(x1+224+1,y1-70+1,WHITE);
    rectangle(x1+280,y1-70,x2+280,y2-70);
	floodfill(x1+280+1,y1-70+1,WHITE);
    rectangle(x1+336,y1-70,x2+336,y2-70);
	floodfill(x1+336+1,y1-70+1,WHITE);
    rectangle(x1+392,y1-70,x2+392,y2-70);
	floodfill(x1+392+1,y1-70+1,WHITE);

    //row1
    rectangle(x1,y1-35,x2,y2-35);
	floodfill(x1+1,y1-35+1,WHITE);
    rectangle(x1+56,y1-35,x2+56,y2-35);
	floodfill(x1+56+1,y1-35+1,WHITE);
    rectangle(x1+112,y1-35,x2+112,y2-35);
	floodfill(x1+112+1,y1-35+1,WHITE);
    rectangle(x1+168,y1-35,x2+168,y2-35);
	floodfill(x1+168+1,y1-35+1,WHITE);
    rectangle(x1+224,y1-35,x2+224,y2-35);
	floodfill(x1+224+1,y1-35+1,WHITE);
    rectangle(x1+280,y1-35,x2+280,y2-35);
	floodfill(x1+280+1,y1-35+1,WHITE);
    rectangle(x1+336,y1-35,x2+336,y2-35);
	floodfill(x1+336+1,y1-35+1,WHITE);
    rectangle(x1+392,y1-35,x2+392,y2-35);
	floodfill(x1+392+1,y1-35+1,WHITE);
   
   //numbers
  
   settextstyle(2,0,5);
   outtextxy(x1-70-5,y1-35+8,"A");

   outtextxy(x1-70-5,y1-70+8,"B");
   outtextxy(x1-70-5,y1-105+8,"C");
   outtextxy(x1-70-5,y1-140+8,"D");
   outtextxy(x1-70-5,y1-175+8,"E");
   //row5
   outtextxy(x1+25,y1-175+8,"E1");
    e1:
   	if(strcmp(seat,"E1")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+1,y1-175+1,WHITE);
   		goto y;
	}
   outtextxy(x1+56+25,y1-175+8,"E2");
    e2:
   	if(strcmp(seat,"E2")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+56+1,y1-175+1,WHITE);
   		goto y;
	}
   outtextxy(x1+112+24,y1-175+8,"E3");
     e3:
   	if(strcmp(seat,"E3")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+112+1,y1-175+1,WHITE);
   		goto y;
	}
   outtextxy(x1+168+24,y1-175+8,"E4");
     e4:
   	if(strcmp(seat,"E4")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+168+1,y1-175+1,WHITE);
   		goto y;
	}
   outtextxy(x1+224+25,y1-175+8,"E5");
     e5:
   	if(strcmp(seat,"E5")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+224+1,y1-175+1,WHITE);
   		goto y;
	}
   outtextxy(x1+280+20,y1-175+8,"E6");
     e6:
   	if(strcmp(seat,"E6")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+280+1,y1-175+1,WHITE);
   		goto y;
	}
   outtextxy(x1+336+20,y1-175+8,"E7");
     e7:
   	if(strcmp(seat,"E7")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+336+1,y1-175+1,WHITE);
   		goto y;
	}
   outtextxy(x1+392+19,y1-175+8,"E8");
     e8:
   	if(strcmp(seat,"E8")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+392+1,y1-175+1,WHITE);
   		goto y;
	}
   //row 4
   outtextxy(x1+25,y1-140+8,"D1");
       d1:
   	if(strcmp(seat,"D1")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+1,y1-140+1,WHITE);
   		goto y;
	}
   outtextxy(x1+56+25,y1-140+8,"D2");
          d2:
   	if(strcmp(seat,"D2")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+56+1,y1-140+1,WHITE);
   		goto y;
	}
   outtextxy(x1+112+25,y1-140+8,"D3");
        d3:
   	if(strcmp(seat,"D3")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+112+1,y1-140+1,WHITE);
   		goto y;
	}
   outtextxy(x1+168+25,y1-140+8,"D4");
          d4:
   	if(strcmp(seat,"D4")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+168+1,y1-140+1,WHITE);
   		goto y;
	}
   outtextxy(x1+224+25,y1-140+8,"D5");
          d5:
   	if(strcmp(seat,"D1")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+224+1,y1-140+1,WHITE);
   		goto y;
	}
   outtextxy(x1+280+20,y1-140+8,"D6");
          d6:
   	if(strcmp(seat,"D1")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+280+1,y1-140+1,WHITE);
   		goto y;
	}
   outtextxy(x1+336+20,y1-140+8,"D7");
          d7:
   	if(strcmp(seat,"D7")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+336+1,y1-140+1,WHITE);
   		goto y;
	}
   outtextxy(x1+392+20,y1-140+8,"D8");
          d8:
   	if(strcmp(seat,"D8")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+392+1,y1-140+1,WHITE);
   		goto y;
	}
   //row 3
   outtextxy(x1+25,y1-105+8,"C1");
           c1:
   	if(strcmp(seat,"C1")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+1,y1-105+1,WHITE);
   		goto y;
	}
   outtextxy(x1+56+25,y1-105+8,"C2");
           c2:
   	if(strcmp(seat,"C2")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+56+1,y1-105+1,WHITE);
   		goto y;
	}
   outtextxy(x1+112+25,y1-105+8,"C3");
             c3:
   	if(strcmp(seat,"C3")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+112+1,y1-105+1,WHITE);
   		goto y;
	}
   outtextxy(x1+168+25,y1-105+8,"C4");
             c4:
   	if(strcmp(seat,"C4")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+168+1,y1-105+1,WHITE);
   		goto y;
	}
   outtextxy(x1+224+25,y1-105+8,"C5");
             c5:
   	if(strcmp(seat,"C5")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+224+1,y1-105+1,WHITE);
   		goto y;
	}
   outtextxy(x1+280+20,y1-105+8,"C6");
             c6:
   	if(strcmp(seat,"C6")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+280+1,y1-105+1,WHITE);
   		goto y;
	}
   outtextxy(x1+336+20,y1-105+8,"C7");
             c7:
   	if(strcmp(seat,"C7")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+336+1,y1-105+1,WHITE);
   		goto y;
	}
   outtextxy(x1+392+20,y1-105+8,"C8");
             c8:
   	if(strcmp(seat,"C8")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+392+1,y1-105+1,WHITE);
   		goto y;
	}
   //row 2
   outtextxy(x1+25,y1-70+8,"B1");
    b1:
   	if(strcmp(seat,"B1")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+1,y1-70+1,WHITE);
   		goto y;
	}
   outtextxy(x1+56+25,y1-70+8,"B2");
       b2:
   	if(strcmp(seat,"B2")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+56+1,y1-70+1,WHITE);
   		goto y;
	}
   outtextxy(x1+112+25,y1-70+8,"B3");
       b3:
   	if(strcmp(seat,"B3")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+112+1,y1-70+1,WHITE);
   		goto y;
	}
   outtextxy(x1+168+25,y1-70+8,"B4");
       b4:
   	if(strcmp(seat,"B4")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+168+1,y1-70+1,WHITE);
   		goto y;
	}
   outtextxy(x1+224+25,y1-70+8,"B5");
       b5:
   	if(strcmp(seat,"B5")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+224+1,y1-70+1,WHITE);
   		goto y;
	}
   outtextxy(x1+280+20,y1-70+8,"B6");
       b6:
   	if(strcmp(seat,"B6")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+280+1,y1-70+1,WHITE);
   		goto y;
	}
   outtextxy(x1+336+20,y1-70+8,"B7");
       b7:
   	if(strcmp(seat,"B7")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+336+1,y1-70+1,WHITE);
   		goto y;
	}
   outtextxy(x1+392+20,y1-70+8,"B8");
       b8:
   	if(strcmp(seat,"B8")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+392+1,y1-70+1,WHITE);
   		goto y;
	}
   //row 1
   outtextxy(x1+25,y1-35+8,"A1");
    a1:
   	if(strcmp(seat,"A1")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+1,y1-35+1,WHITE);
   		goto y;
	}
   outtextxy(x1+56+25,y1-35+8,"A2");
    a2:
   	if(strcmp(seat,"A2")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+56+1,y1-35+1,WHITE);
   		goto y;
	}
   outtextxy(x1+112+25,y1-35+8,"A3");
    a3:
   	if(strcmp(seat,"A3")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+112+1,y1-35+1,WHITE);
   		goto y;
	}
   outtextxy(x1+168+25,y1-35+8,"A4");
    a4:
   	if(strcmp(seat,"A4")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+168+1,y1-35+1,WHITE);
   		goto y;
	}
   outtextxy(x1+224+25,y1-35+8,"A5");
    a5:
   	if(strcmp(seat,"A5")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+224+1,y1-35+1,WHITE);
   		goto y;
	}
   outtextxy(x1+280+20,y1-35+8,"A6");
    a6:
   	if(strcmp(seat,"A6")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+280+1,y1-35+1,WHITE);
   		goto y;
	}
   outtextxy(x1+336+20,y1-35+8,"A7");
    a7:
   	if(strcmp(seat,"A7")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+336+1,y1-35+1,WHITE);
   		goto y;
	}
   outtextxy(x1+392+20,y1-35+8,"A8");
    a8:
   	if(strcmp(seat,"A8")==0)
   	{
   		setfillstyle(SOLID_FILL,RED);
		floodfill(x1+392+1,y1-35+1,WHITE);
   		goto y;
	}

    rectangle(x1-100,y1+20,x2+392,y2+15);
    outtextxy(x1+56+100,y1+20+8,"SCREEN SIDE");
    
    char ch,chh;

	x:
	gotoxy(20,w);
	cout<<"ENTER THE SEAT NUMBER TO TAKE : ";
	gotoxy(52,w);
    cin>>seat;
    w=w+3;
	// FOR E............................................................................
    if(strcmp(seat,"E1")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
    	goto e1;
	}
	else if(strcmp(seat,"E2")==0)
    {	
		total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto e2;
	}
	else if(strcmp(seat,"E3")==0)
    {
		total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto e3;
	}
	else if(strcmp(seat,"E4")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto e4;
	}
	else if(strcmp(seat,"E5")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto e5;
	}
	else if(strcmp(seat,"E6")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto e6;
	}
	else if(strcmp(seat,"E7")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto e7;
	}
	else if(strcmp(seat,"E8")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto e8;
	}
	// FOR D............................................................................
	else if(strcmp(seat,"D1")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto d1;
	}
	else if(strcmp(seat,"D2")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto d2;
	}		
	else if(strcmp(seat,"D3")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto d3;
	}		
	else if(strcmp(seat,"D4")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto d4;
	}		
	else if(strcmp(seat,"D5")==0)
    {
    	total_ticket=total_ticket+1;
		total_price=total_price+200;
		goto d5;
	}
	else if(strcmp(seat,"D6")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto d6;
	}
	else if(strcmp(seat,"D7")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto d7;
	}
	else if(strcmp(seat,"D8")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto d8;
	}
  // FOR C............................................................................
	else if(strcmp(seat,"C1")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto c1;
	}
	else if(strcmp(seat,"C2")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto c2;
	}		
	else if(strcmp(seat,"C3")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto c3;
	}		
	else if(strcmp(seat,"C4")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto c4;
	}
	else if(strcmp(seat,"C5")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto c5;
	}
	else if(strcmp(seat,"C6")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto c6;
	}
	else if(strcmp(seat,"C7")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto c7;
	}
	else if(strcmp(seat,"C8")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto c8;
	}
// FOR B............................................................................
	else if(strcmp(seat,"B1")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto b1;
	}
	else if(strcmp(seat,"B2")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto b2;
	}		
	else if(strcmp(seat,"B3")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto b3;
	}		
	else if(strcmp(seat,"B4")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto b4;
	}
	else if(strcmp(seat,"B5")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto b5;
	}
	else if(strcmp(seat,"B6")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto b6;
	}
	else if(strcmp(seat,"B7")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto b7;
	}
	else if(strcmp(seat,"B8")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto b8;
	}


// FOR A............................................................................
	else if(strcmp(seat,"A1")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto a1;
	}
	else if(strcmp(seat,"A2")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto a2;
	}		
	else if(strcmp(seat,"A3")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto a3;
	}		
	else if(strcmp(seat,"A4")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto a4;
	}		
	else if(strcmp(seat,"A5")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto a5;
	}
	else if(strcmp(seat,"A6")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto a6;
	}
	else if(strcmp(seat,"A7")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto a7;
	}
	else if(strcmp(seat,"A8")==0)
    {
			total_ticket=total_ticket+1;
			total_price=total_price+200;
			goto a8;
	}

	else 
	{
		cout<<"ERROR! INVALID SEAT ENTERED. ";
		goto x;
	}
	
	y:
	gotoxy(20,50);
	cout<<"Do You Want To Add More Seat (Y/N)?: ";
	chh=getch();
	if(chh=='Y'||chh=='y')
	{
		goto x;
	}
	clrscr();
	cleardevice();
    s.box(20,6,65,20);
    s.box(18,4,67,22);
    gotoxy(25,5);
	cout<<"Your Details Are As Follows: ";
    gotoxy(25,7);
	cout<<"Customer Name: ";
    gotoxy(41,7);
    cout<<TB.name;
    s.line_hor(21,64,8,196);
    gotoxy(25,9);
	cout<<"Customer C.No: "; 
    gotoxy(41,9);
    cout<<TB.phnum;
    s.line_hor(21,64,10,196);
    gotoxy(25,11);
	cout<<"Movie Name: ";
    gotoxy(41,11);
    cout<<TB.movie;
    s.line_hor(21,64,12,196);
	gotoxy(25,13);
    cout<<"Date Of Show: ";
    gotoxy(41,13);
    cout<<TB.date;
    s.line_hor(21,64,14,196);
    gotoxy(25,15);
	cout<<"Time Of Show: ";
    gotoxy(41,15);
    cout<<TB.time;
    s.line_hor(21,64,16,196);
	TB.ticket=total_ticket;
    gotoxy(25,17);
	cout<<"Total Ticket: ";
    gotoxy(41,17);
    cout<<TB.ticket;
    s.line_hor(21,64,18,196);
	TB.price=total_price;
    gotoxy(25,19);
	cout<<"Total Price: ";
    gotoxy(41,19);
    cout<<TB.price;
	getch();
    outfile.write((char*)&TB,sizeof(TB));
    outfile.close();
    return;
	closegraph();
}

//**************************************************************************
int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
	settextstyle(0,0,2);
	outtextxy(230,100,"CINEMA HUB");
	getch();
	main_menu m;
	m.control_menu();
	return 0;
}
