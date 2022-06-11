#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
class student{
char name[20];
int adm_no;
int cls;
int no_b;
public:
void get(){
cout<<"Enter student name :";
cin>>name;
cout<<"Enter admission number :";
cin>>adm_no;
cout<<"Enter class of student :";
cin>>cls;
cout<<"Enter number of books :";
cin>>no_b;
}
void show(){
    cout<<"Name :"<<name<<"\n admission no :"<<adm_no<<"\n class:"<<cls<<"\n No of books issued :"<<no_b<<endl;
}
void write(){
    ofstream outfile;
    outfile.open("student.txt",ios::app);
    get();
    outfile.write(reinterpret_cast<char *>(this),sizeof(*this));
}
void read(){
    ifstream infile;
    infile.open("student.txt",ios::in);
    if(!infile){
        cout<<"Error in opening file..";
        return ;
    }
    cout<<"**** Data from file ****"<<endl;
    while(!infile.eof()){
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this)) > 0)
        show();
    }
    infile.close();
}
void search(){
    int n;
    ifstream infile;
    infile.open("student.txt",ios::in);
     if(!infile){
        cout<<"Error in opening file..";
        return ;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"There are"<<count<<"record in the file";
    cout<<"Enter Record Number to search:";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this),sizeof(*this));
    show();
}
void edit(){
    int n;
    fstream iofile;
    iofile.open("student.txt",ios::in);
    if(!iofile){
        cout<<"Error in opening file..";
        return ;
    }
    iofile.seekg(0,ios::end);
    int count=iofile.tellg()/sizeof(*this);
    cout<<"There are"<<count<<"record in the file";
    cout<<"Enter Record Number to search:";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this),sizeof(*this));
    cout<<"Record "<<n<<"has following data"<<endl;
    show();
    iofile.close();
    iofile.open("student.txt",ios::out|ios::in);
    iofile.seekp((n-1)*sizeof(*this));
    cout<<"Enter data to modify"<<endl;
    get();
    iofile.write(reinterpret_cast<char*>(this),sizeof(*this));
}
void dlt(){
    int n;
    ifstream infile;
    infile.open("student.txt",ios::in);
    if(!infile){
        cout<<"Error in opening file..";
        return ;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"There are"<<count<<"record in the file";
    cout<<"Enter Record Number to search:";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("tmpfile.txt",ios::out|ios::binary);
    infile.seekg(0);  
    for(int i=0;i<count;i++){
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
        continue;
        tmpfile.write(reinterpret_cast<char*>(this),sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("student.txt");
    rename("tmpfile.txt","student.txt");
}
};
class book{
int b_no;
char au_name[20];
char title[30];
char domain[20];
int edition;
int no_copy;
};
int main(){
student s;
int n;
ofstream file;
ifstream file1;
while(1){
cout<<"Enter 1 to add student , 2 to add book , 3  to read student file , 4 to read book file and anything else to exit"<<endl;
cin>>n;
switch(n){
case 1:
s.write();
break;
case 2:
break;
case 3:
s.read();
break;
case 4:
break;
default : exit(0);
}}
return 0;
}