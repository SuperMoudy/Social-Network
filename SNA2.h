#ifndef SNA_H_
#define SNA_H_
/*----------------------------------------------------*/
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include <fstream>
#include<iomanip>
#include <string.h>
#include "sysfiles.h"

using namespace std;


class Post
{
public:
	char mail[70]  ;
	char text[1000];
	int likes  ;
	int id     ;
};



class Friend
{
public:
	Friend(){}
	char Name [50];
	char Mail [70];
	Friend(char* name,char* mail){
		strcpy_s(Mail,mail);
		strcpy_s(Name,name);
		}
};



class Request
{
public:
	Request(){}
	char mail[70]  ;
	char name[50]  ;
	char text[70] ="would like to be your friend" ;

	Request(char*Mail,char*Name){
		strcpy_s(mail,Mail);
		strcpy_s(name,Name);
	}
};



/*----------------------------------------------------*/
class User
{
public:

	string Name    ;

	string Mail    ;

	string Password;

	int    Age     ;

	vector<Post>Posts     ;

	vector<Friend>Friends ;

	vector<Request>Requests;

//public:
	//User(string,string,string,int);
	User();
	~User();
	void Like_Post(int id,char * mail)       ;

	void Mutual_Friends()          ;          // i think it should be added to the System class

	void Add_Friend(char* mail,char*name)   ;

	void Accept_Friend(char* mail,char*name);

	void Search(string name);          // i think it should be added to the System class

	void Post_Text(string);

	void Delete_Profile();          //assuming he is o his profile page

	void View_User_Profile(string mail); //hamdy

	void Edit_User_Profile(); //hamdy

	void Update_User_Profile(); //new by hamdy

	//void Browse_User_Friends(string mail); //We should pass a user to get his friends not an e-mail

	void Browse_User_Friends(string mail); // we pass a user and import his friends //hamdy

	void Login(string mail, string password);   //hamdy

	void Register(string name, string mail, string password, int age); //hamdy

	//setters
	void set_name(string name);

	void set_age(int age);

	void set_mail(string mail);

	void set_password(string password);

	// getters just in case
	string get_name();

	string get_mail();

	string get_password();

	int get_age();

	string get_post();

	string get_friends();

	string get_requests();
/*utilities to deal with files */

	void Load(string KeyWord , string mail)  ;
	void Load_Post(char* mail=NULL,vector<Post>*vec=NULL);
	void Load_Friends(char* mail=NULL,vector<Friend>*vec=NULL);
	void Load_Requests(char* mail=NULL) ;
	void Save(string KeyWord , string mail)  ;
	void Save_Post(char* mail=NULL,vector<Post>*vec=NULL);
	void Save_Friends(char* mail=NULL,vector<Friend>*vec=NULL);
	void Save_Requests(char* mail=NULL) ;

};




#endif /* SNA_H_ */

