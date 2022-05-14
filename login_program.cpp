// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: login_program.cpp
// Program Description: login gate program
// Last Modification Date: 27/4/2022
// Author1 and ID and Group: Ahmed Mohamed Taha - 20210033 - Group A - S8
// Author2 and ID and Group: Doaa Mahdy Mohamed - 20210128 - Group A - S8
// Author3 and ID and Group: Omar Ayman Saad    - 20210261 - Group A - S8
// Teaching Assistant: Abdulrahman Abdulmonem
// Purpose: training on regex and struct

// libraries
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <array>
#include <unistd.h>
#include<conio.h>

// initialize standard cpp
using namespace std;

// functions
void login();
void reg();
void username_input();
void email_input();
void phone_input();
void password_input();
void change_pass();
void password_input_stars(string& s);
string decrypt(string s);

// variables
string email,id,password,password2,phone,username,str,temp="temp.txt",new_pass;
string user_login , pass_login , s1 , s2;
fstream data;

bool regi=false;



// main function
int main() {
    system("CLS");
    int choose;
    cout<<"           Hello :)              \n"
    <<"please select what you want either   \n"
    <<"1- Register                          \n"
    <<"2- Login                             \n"
    <<"3- Change password                   \n"
    <<">> ";
    cin>>choose;
    cin.ignore();

    switch (choose)
    {

        case 1:
            reg();
            main();
            break;

        case 2:
            login();
            main();
            break;

        case 3:
            change_pass();
            main();
            break;

        default:
            cout<<"\ninvalid input please try again :)";
            sleep(2);
            break;
    }

}

//-----------------------------------------------------------------------------
void reg(){
    regi=true;
    system("CLS");
    cout<<"     welcome in registeration center       \n";
    email_input();
    username_input();
    password_input();
    phone_input();
    cout<<"\nCON. successful registration";
    regi=false;
}
//-----------------------------------------------------------------------------

void username_input(){
    start:
    data.close();
    cout<<"\nenter your username without spaces: ";

    getline(cin,username,'\n');

    data.open(temp,ios::in);

    for(int i=0; i<username.size(); i++){
        if(isspace(username[i])){
            cout<< "please enter the username without spaces";
            goto start;
        }
    }

    while (!data.eof()){
		getline(data,str);
        if(str==username)
        {
            cout<<"username is exist please try again";
            goto start;
        }
    }

    for(int i=0; i<username.size(); i++){
        if(isspace(username[i])){
            cout<< "please enter the username without spaces";
            goto start;
        }
    }
    data.close();

    data.open(temp,ios::app);
    data<<username<<endl;
    data.close();
}
//-----------------------------------------------------------------------------
void email_input(){
    start2:
    data.close();
    cout<<"\nenter your email without spaces: ";
    getline(cin,email,'\n');

    // email format checking
    regex filter("[\\S]+@{1}(-){0}(\\w+(-)*\\.*)+");

    if(regex_match(email,filter)!=1){cout<<"wrong format please try again.."; goto start2;}

    if(email.find('@')>64){cout<<"local part must be 64 or less than charcters please try again.."; goto start2;}

    for(int i=0; i<email.size(); i++){
        if(email[i]=='.' && email[i+1]=='.')
        {cout<<"wrong format you can't use period '.' two times in raw please try again.."; goto start2;}
    }

    if(email[email.size()-1]=='-'){cout<<"domain cant end with - please try again.."; goto start2;}

    data.open(temp,ios::in);

    // check if email is exist in data
    while (!data.eof()){
		getline(data,str);
        if(str==email)
        {
            cout<<"email is exist please try again..";
            goto start2;
        }
    }
    // store email
    data.close();

    data.open(temp,ios::app);
    data<<endl << email<<endl;
    data.close();


}
//-----------------------------------------------------------------------------
void phone_input(){
    start3:

    // phone format checking
    regex filter("(01){1}(1|2|5|0){1}\\d{8}");
    data.close();
    cout<<"\n\nenter your phone number without spaces: ";
    getline(cin,phone);

    if(regex_match(phone,filter)!=1){cout<<"wrong format please try again.."; goto start3;}

    // phone store in data files
    data.close();
    data.open(temp,ios::app);
    data<<phone<<endl;
    data.close();
}

//-----------------------------------------------------------------------------
void password_input(){
new_pass="";
// display a message to the user of how the password should be
    start3:
    //system("CLS");
   cout<<"\n\nyour password should be:                           \n"
       <<"-at least 6 characters                                 \n"
       <<"-mixture of uppercase and lowercase letters            \n"
       <<"-inclusion of at least one special character,e.g.,!@#? \n"
       <<"-contain at least one number";


//take a password from the user for registration
   data.close();
   cout<<"\n\nEnter your password: ";
    password_input_stars(new_pass);
    
cout<<'\n'<<"only for tracing , your password is "<<new_pass<<endl;

// check if the password entered follow the rules of strong password

regex regexRule("(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[$_@!?,.])(?=.{6,})");
bool is_valid = regex_search(new_pass,regexRule);
if(!is_valid){cout<<"\n\nthe password entered not strong enough...";sleep(5);goto start3;}


// verifying password
cout<<"\n\nEnter your password again: ";
    string password2;
    password_input_stars(password2);

// check if the verified password equals the first password entered
if(new_pass != password2){cout<<"\nnot the same";sleep(5); goto start3;}


if(!regi){return;}

// store the password entered in an encrypted format by adding 1 to all characters
else{
    data.open(temp,ios::app);
    for(int i=0; i<new_pass.size(); i++){ new_pass[i]+=1; }

    data<< new_pass<< endl;
    data.close();
}
}

//-----------------------------------------------------------------------------
void login(){
    int t=0;
    bool found = false , login = false ;
    while(true){
        start_log:
        t++;
        bool found = false , login = false ;
        system("CLS");
        cout<<"please enter your username: ";
        cin>>user_login;
        cout<<"please enter your password: ";
        password_input_stars(pass_login);

        data.close();
        data.open(temp,ios::in);

        while (!data.eof())
        {
            getline(data,s1);
            if(s1==user_login){
                found = true;
                getline(data,s2);
                // password decrypt
                for (int i = 0; i<s2.size() ; i++)
                    s2[i]-= 1;
                
                if(pass_login==s2){
                    login = true;
                    break;
                }  
            }
        }
        if(t==3 && (!found || !login)){break;}
        if(!found){
            cout<<"\nusername doesn't exist, please try again..." ;
            sleep(5);
            goto start_log ;
        }
        if(!login){
            cout<<"\nwrong password , please try again..." ;
            sleep(5);
            goto start_log ;
        }
        if(login){
            cout<<"\nSuccessful login ,Welcome "<<user_login;
            sleep(5);
            return;
        }
    }

    cout<<"\nyou enterd wrong username or password for 3 times you are denied to login..";
    sleep(5);
    exit(0);
    
    
}

//-----------------------------------------------------------------------------
void change_pass(){
    system("CLS");
    string old_pass,new_pass1;

//  let user login first
    cout<<"Please login first...";
    sleep(5);
    login();

//  let user enter his old password
    pass_in:
    cout<<"\nPlease enter your old password: ";
    password_input_stars(old_pass);

//  check if the old password is correct
    if(old_pass!=pass_login){cout<<"\nwrong password please try again..."; goto pass_in;}

//  let user enter the new password
    password_input();
    for(int i=0; i<new_pass.size(); i++)
        new_pass[i]+=1;

//  store the old data of users with this updated password in the file
fstream data1;
data1.open("temp1.txt",ios::out);

data.close();
data.open(temp,ios::in);
string s;

while(!data.eof()){
    getline(data,s);

    if(s==user_login){ data1<< s << endl; 
        getline(data,s);
        data1<< new_pass << endl;
    }
    
    else{ data1<< s << endl; }
}
data1.close();
data.close();

remove("temp.txt");
rename("temp1.txt","temp.txt");

cout<<"\n\npassword changed ...";
sleep(5);
}

void password_input_stars(string& s){
    s="";
    int c = getch();
    while(c!= 13){
        if(c==8){
            cout<<"\b \b";
            s.pop_back();
                goto label;
        }
        else{
            s.push_back(c);
            cout<<char(c); usleep(200000); cout<<"\b \b"; cout<<"*";
            label:
            c=getch();

        }
    }
}