// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: text_editor.cpp
// Program Description: text editor program
// Last Modification Date: 27/4/2022
// Author1 and ID and Group: Ahmed Mohamed Taha - 20210033 - Group A - S8
// Author2 and ID and Group: Doaa Mahdy Mohamed - 20210128 - Group A - S8
// Author3 and ID and Group: Omar Ayman Saad    - 20210261 - Group A - S8
// Teaching Assistant: Abdulrahman Abdulmonem
// Purpose: training on struct and reading or writing files

// libraries
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
#include<vector>
#include<cctype>


// initialize standard cpp
using namespace std;

// static variables
fstream dataFile,data1;
string fileName,Ndata="data.txt";
bool change=false;

// functions
void OpenFile();
void duplicate();
void f1_append();
void f2_readFile();
void f3_empty();
void f4_encrypt();
void f5_decrypt();
void f6_merge_files();
void f7_count_totalWords();
void f8_count_chars();
void f9_count_lines();
string f10_search_word();
void f11_count_words();
void f12_upper_case();
void f13_lower_case();
void f14_first_upper();
void f15_save();

//the other help functions
void menu();
string lower(string& str);

// main function
int main(){
    int choose;
    system("CLS");
    OpenFile();
    while(choose!=16){
        cin.clear();
        system("CLS");
        cout<<"\n      *************** Main menu ***************        \n"
            <<"1.  Add new text to the end of the file                   \n"
            <<"2.  Display the content of the file                       \n"
            <<"3.  Empty the file                                        \n"
            <<"4.  Encrypt the file content                              \n"
            <<"5.  Decrypt the file content                              \n"
            <<"6.  Merge another file                                    \n"
            <<"7.  Count the number of words in the file                 \n"
            <<"8.  Count the number of characters in the file            \n"
            <<"9.  Count the number of lines in the file                 \n"
            <<"10. Search for a word in the file                        \n"
            <<"11. Count the number of times a word exists in the file  \n"
            <<"12. Turn the file content to upper case                  \n"
            <<"13. Turn the file content to lower case                  \n"
            <<"14. Turn file content to 1st caps                        \n"
            <<"15. Save                                                 \n"
            <<"16. Exit                                                 \n"
            <<"\n choose the operation that you want (enter number between 1,16): ";  cin>>choose;

            switch(choose){

                case 1:
                    f1_append();
                    break;

                case 2:
                    f2_readFile();
                    break;

                case 3:
                    f3_empty();
                    break;

                case 4:
                    f4_encrypt();
                    break;

                case 5:
                    f5_decrypt();
                    break;

                case 6:
                    f6_merge_files();
                    menu();
                    break;

                case 7:
                    f7_count_totalWords();
                    menu();
                    break;

                case 8:
                    f8_count_chars();
                    menu();

                case 9:
                    f9_count_lines();
                    menu();

                case 10 :

                    cout<<f10_search_word()<<endl;
                    menu();
                    break;

                case 11:
                    f11_count_words();
                    menu();
                    break;
                
                case 12:
                    f12_upper_case();
                    break;
                
                case 13:
                    f13_lower_case();
                    break;
                
                case 14:
                    f14_first_upper();
                    break;

                case 15:
                    f15_save();
                    break;

                case 16:
                    break;

                default:
                    cout<<"wrong input please try again...";
                    sleep(3);

            }

    }
    dataFile.close();
    f3_empty();
    data1.close();
}
//-----------------------------------------------------------------------------
void OpenFile(){
    cout << "Please enter a file name: ";  getline(cin,fileName, '\n');

    if(fileName.find(".txt")==-1) {fileName+=".txt";}

	dataFile.open(fileName, ios::in);
    data1.open(Ndata,ios::out | ios::app | ios::in);

	if (dataFile.fail()){
        dataFile.open(fileName,ios::out | ios::app | ios::in);
		cout << "\nThis is a new file. I created it for you :)" << endl;
        cout << "\nplease wait opening file..." << endl;
        sleep(3);
    }
    else {
        cout << "\nThis file already exists" << endl;
        cout << "\nplease wait opening file..." << endl;
        sleep(3);
    }
    dataFile.close();
}
//-----------------------------------------------------------------------------
void duplicate(){
    string s;
    dataFile.close();
    dataFile.open(fileName,ios::out | ios::app | ios::in);

    data1.close();
    data1.open(Ndata,ios::out | ios::app | ios::in);

    while (!dataFile.eof()){
        getline(dataFile,s);
		data1 << s << '\n';
    }
    data1.close();
    dataFile.close();
}
//-----------------------------------------------------------------------------
void f1_append(){
    change = true;

    string s;
    system("CLS");

    duplicate();
    data1.open(Ndata,ios::out | ios::app | ios::in);
    cout<<"\ntype what you want and when you end press enter and CTRL+Z and enter again to back to main menu\n\n";
    do
    {   getline(cin,s,'\n');
        data1<<s<<'\n';
    }while(!cin.eof());
}
//-----------------------------------------------------------------------------
void f2_readFile(){
    system("CLS");
    int p;

    dataFile.open(fileName,ios::in);
    while (!dataFile.eof()){
		 cout << (char)dataFile.get();
    }
    do{
    cout<<"\n\nif you want back to main menu enter 1: "; cin>>p;
    }while(p!=1);

    dataFile.close();
}
//-----------------------------------------------------------------------------
void f3_empty(){
    change = true;
    system("CLS");
    data1.close();

    data1.open(Ndata, ios::out | ios::trunc);
    data1.close();
    cout<<"\n\nDone :)";
    sleep(3);
}
//-----------------------------------------------------------------------------
void f4_encrypt(){
    string s;
    int endl=0;
    if(!change){
        change = true;
        system("CLS");

        data1.close();
        data1.open(Ndata,ios::out);

        dataFile.close();
        dataFile.open(fileName,ios::in);

      while (!dataFile.eof()) {
        getline(dataFile,s);
          
        for(int i=0; i<s.size(); i++){ s[i]+=1; }
            
<<<<<<< HEAD
		data << s << '\n';
=======
		data1 << s << '\n';
>>>>>>> e51fd3277b759fc838ffe0625708be7937c76f54
	  }

        cout<<"\n\nDone :)";
        sleep(3);
    }
    else{
        cout<<"please save first...";
        sleep(4);
        }
}
//-----------------------------------------------------------------------------
void f5_decrypt(){
    char c;
    string s;
    if(!change){
        change = true;
        system("CLS");

        data1.close();
        data1.open(Ndata,ios::out | ios::app | ios::in);

        dataFile.close();
        dataFile.open(fileName,ios::out | ios::app | ios::in);

        while (!dataFile.eof()){
          getline(dataFile,s);
          for(int i=0; i<s.size(); i++){ s[i]-=1; }
		data1 << s << "\n";
        }

        cout<<"\n\nDone :)";
        sleep(3);
    }
    else{
        cout<<"please save first...";
        sleep(4);
        }
}
//-----------------------------------------------------------------------------
void f6_merge_files (){
 string fileName2 , text;
 cout<<"\nenter another file: ";
 cin.clear();
 cin.ignore();
 getline(cin , fileName2);

 ifstream ifile (fileName2+".txt" , ios::in);
 dataFile.close();
 dataFile.open(fileName,ios::out | ios::app | ios::in);



 if(!ifile.is_open())
    cout<<"\nInvalid file name."<<endl;

 else
 {
   dataFile <<endl <<ifile.rdbuf();
   dataFile.close();
   ifile.close();
   cout<<"\nthe merge process has been completed successfully :)"<<endl;
 }

}
//-----------------------------------------------------------------------------
void f7_count_totalWords(){
    string s;
    int sum = 0 ;
    string word;
    vector<string>words;

    dataFile.close();
    dataFile.open(fileName,ios::out | ios::app | ios::in);
    data1.close();
    data1.open(Ndata,ios::out | ios::app | ios::in);


    while(dataFile>>word)
        words.push_back(word);

    for(string word : words)
        sum++;



    cout<<"\nthe number of words is: "<<sum<<endl;
}
//-----------------------------------------------------------------------------
void f8_count_chars(){
    int sum =0 ;
    string text ;

    dataFile.close();
    dataFile.open(fileName,ios::out | ios::app | ios::in);
    data1.close();
    data1.open(Ndata,ios::out | ios::app | ios::in);



   while(getline(dataFile , text)){

      for(int i = 0 ; i <text.length() ; i++)
          sum++;

 }
  cout<<"\nthe number of characters in the file is: "<<sum<<endl;
}

//-----------------------------------------------------------------------------

void f9_count_lines(){
int line = 0;
string text;


    dataFile.close();
    dataFile.open(fileName,ios::out | ios::app | ios::in);
    data1.close();
    data1.open(Ndata,ios::out | ios::app | ios::in);


    while (getline(dataFile ,text)){
       line++;
 }

    cout<<"\nthe number of lines is: "<<line<<endl;

}

//-----------------------------------------------------------------------------
string f10_search_word(){
    string keyWord , s , word;
    vector<string>words;
    cout<<"\nenter the word to search for: ";
    cin>>keyWord;


    dataFile.close();
    dataFile.open(fileName,ios::out | ios::app | ios::in);
    data1.close();
    data1.open(Ndata,ios::out | ios::app | ios::in);



    while(dataFile>>word)
        words.push_back(word);


    for(string x : words){
        if(lower(x) == lower(keyWord ))
            return "\nword was found in the file :)";
    }

     return "\nword was not found in the file :(";

}

//-----------------------------------------------------------------------------

void f11_count_words( ){
    int sum =0 ;
    string keyWord ,word ;
    vector<string>words;
    cout<<"\nenter the word to search for: ";
    cin>>keyWord;

    dataFile.close();
    dataFile.open(fileName,ios::out | ios::app | ios::in);
    data1.close();
    data1.open(Ndata,ios::out | ios::app | ios::in);


    while(dataFile>>word)
        words.push_back(word);

    for(string x : words){
        if(lower(x) == lower(keyWord ))
            sum++;
    }

cout<<"\nthe number of times ("<<keyWord<<")occured in the file: "<<sum<<endl;

}

//-----------------------------------------------------------------------------
void f12_upper_case(){
    string s;
    if(!change){
        change = true;
        system("CLS");

        data1.close();
        data1.open(Ndata,ios::out);

        dataFile.close();
        dataFile.open(fileName,ios::in);
        while (!dataFile.eof()){
          getline(dataFile,s);
          for(int i=0; i<s.size(); i++){s[i]= toupper (s[i]); }
		data1 << s << "\n";
        }

        cout<<"\n\nDone :)";
        sleep(3);
    }
    else{
        cout<<"please save first...";
        sleep(4);

}
}

//-----------------------------------------------------------------------------

void f13_lower_case(){
    string s;
    if(!change){
        change = true;
        system("CLS");

        data1.close();
        data1.open(Ndata,ios::out);

        dataFile.close();
        dataFile.open(fileName,ios::in);
        while (!dataFile.eof()){
          getline(dataFile,s);
          for(int i=0; i<s.size(); i++){s[i]= tolower (s[i]); }
		data1 << s << "\n";
        }

        cout<<"\n\nDone :)";
        sleep(3);
    }
    else{
        cout<<"please save first...";
        sleep(4);

}
}

//-----------------------------------------------------------------------------

void f14_first_upper(){
    string s;
    if(!change){
        change = true;
        system("CLS");

        data1.close();
        data1.open(Ndata,ios::out);

        dataFile.close();
        dataFile.open(fileName,ios::in);
        while (!dataFile.eof()){
          getline(dataFile,s);
          s[0]=toupper (s[0]);
          for(int i=1; i<s.size(); i++){
              if(s[i]==' ') {s[i+1]= toupper (s[i+1]); i++; }
              else {s[i]= tolower (s[i]); }
              }
		data1 << s << "\n";
        }

        cout<<"\n\nDone :)";
        sleep(3);
    }
    else{
        cout<<"please save first...";
        sleep(4);

}
}

//-----------------------------------------------------------------------------

void menu(){
string s;

cout<<"\npress CTRL+Z and enter  to go back to main menu\n\n";
    do
    {   getline(cin,s,'\n');
    }
    while(!cin.eof());

}

//-----------------------------------------------------------------------------

void f15_save(){
    start:
    string s;
    char choose;
    system("CLS");
    if(!change){
        system("CLS");
        cout<<"You didn't made a change to save :(";
        sleep(4);
    }

    else{
        cout<<"save in the same file ? (y/n): "; cin>>choose;
        if(choose=='Y' || choose=='y'){
            k1:

            dataFile.close();
            dataFile.open(fileName,ios::out);

            data1.close();
            data1.open(Ndata,ios::in);

      while (!data1.eof()) {
        string s;
        getline(data1,s);
		dataFile << s << '\n';
	  }

            dataFile.close();
            data1.close();

        }

        else if(choose=='N' || choose=='n'){
            cin.ignore();
            OpenFile();
            goto k1;
        }

        else{cout<<"wrong input please try again"; goto start; sleep(3);}
    }
    f3_empty();
    change=false;
}

string lower(string& str){
for(int i =0 ;i <str.length() ; i++)
    str[i] = tolower(str[i]);

return str;
}
