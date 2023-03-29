#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;
int main()
{
    int a,i=0;
    string text, old, password1, password2 , pass, name, password0, age, user,word, word1;
    string creds[2], cp[2];
    cout<<"      Security System  "<<endl;

    cout<<"                               "<<endl<<endl;
    cout<<"_______________________________"<<endl;
    cout<<"|       1. Register            |"<<endl;
    cout<<"|       2. Login               |"<<endl;
    cout<<"|       3. Change Password     |"<<endl;
    cout<<"|_______4. End Program_________|"<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter your choice:- ";
        cin>>a;
        switch(a)
        {
        case 1:
            {
                cout<<"___________________________"<<endl<<endl;
                cout<<"|-----------Register-------"<<endl;
                cout<<"|__________________________"<<endl<<endl;
                cout<<"Please enter username:- ";
                cin>>name;
                cout<<"Please enter the password:- ";
                cin>>password0;
                cout<<"Please enter your age:- ";
                cin>>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open())
                {
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Registration successfull"<<endl;
                }
                break;
            }



        case 2:{

         i=0;
         cout<<"                        "<<endl<<endl;
         cout<<"________________________"<<endl;
         cout<<"---------Login----------|"<<endl;
         cout<<"|_______________________|"<<endl<<endl;



        break;
        }
        }
    }

}
