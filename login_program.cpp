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
#include <Windows.h>
#include<conio.h>

// initialize standard cpp
using namespace std;

// functions
void login();
void reg();
void username_input();
void email_input();
void phone_input();
void ID_input();
void password_input();

// variables
string email,id,password,phone,username,str,temp="temp.txt";
fstream data;





// main function
int main() {
    system("CLS");
    int choose;
    cout<<"           Hello :)           \n"
    <<"please select what you want either\n"
    <<"1- Login                          \n"
    <<"2- Register                       \n"
    <<">> ";
    cin>>choose;
    cin.ignore();

    switch (choose)
    {
/*
        case 1:
            login();
            break;
*/
        case 2:
            reg();
            break;

        default:
            cout<<"\ninvalid input please try again :)";
            sleep(2);
            break;
    }

}



void reg(){
    system("CLS");
    cout<<"     welcome in registeration center       \n";
    username_input();
    email_input();
//  password_input();
    phone_input();
    ID_input();
    cout<<"\nCON. successful registration";
}

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
    data<<endl<<username<<endl;
    data.close();
}

void email_input(){
    start2:
    data.close();
    cout<<"\nenter your email without spaces: ";
    getline(cin,email,'\n');

    regex filter("[\\S]+@{1}(-){0}(\\w+(-)*\\.*)+");

    if(regex_match(email,filter)!=1){cout<<"wrong format please try again.."; goto start2;}

    if(email.find('@')>64){cout<<"local part must be 64 or less than charcters please try again.."; goto start2;}
    
    for(int i=0; i<email.size(); i++){
        if(email[i]=='.' && email[i+1]=='.')
        {cout<<"wrong format you can't use period '.' two times in raw please try again.."; goto start2;}
    }

    if(email[email.size()-1]=='-'){cout<<"domain cant end with - please try again.."; goto start2;}

    data.open(temp,ios::in);

    while (!data.eof()){
		getline(data,str);
        if(str==email)
        {
            cout<<"email is exist please try again..";
            goto start2;
        }
    }
    data.close();

    data.open(temp,ios::app);
    data<<email<<endl;
    data.close();
    

}

void phone_input(){
    start3:
    regex filter("(01){1}(1|2|5|0){1}\\d{8}");
    data.close();
    cout<<"\nenter your phone number without spaces: ";
    getline(cin,phone);

    if(regex_match(phone,filter)!=1){cout<<"wrong format please try again.."; goto start3;}

    data.open(temp,ios::app);
    data<<phone<<endl;
    data.close();
}

void ID_input(){
    start3:
    regex filter("(_){0}[a-zA-Z]+\\s*(_)?[a-zA-Z]+");
    data.close();
    cout<<"\nenter your ID : ";
    getline(cin,id);

    if(regex_match(id,filter)!=1){cout<<"wrong format please try again.."; goto start3;}

    data.open(temp,ios::app);
    data<<id<<endl;
    data.close();
}

//void password_input();