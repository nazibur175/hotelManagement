#include<iostream>
#include<fstream>
using namespace std;
class shoping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void listt();
        void receipt();
};
void shopping::menu()
{
    m:
    int choice ;
    string email;
    string password;

    cout<<"\t\t\t\t_______________________________\n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t     Supermarket Main Menu     \n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t_______________________________\n";
    cout<<"\t\t\t\t| 1)Administrator |\n";
    cout<<"\t\t\t\t|                 |\n";
    cout<<"\t\t\t\t| 2)Buyer         |\n";
    cout<<"\t\t\t\t|                 |\n";
    cout<<"\t\t\t\t| 3)Exit          |\n";
    cout<<"\t\t\t\t|                 |\n";
    cout<<"\n\t\t\tPlease Select!";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter Email  \n";
        cin>>email;
        cout<<"\t\t\t Enter Password  \n";
        cin>>password;

        if(email=="nazibur175@gmail.com" && password="nazibur175")
        {
            administrator();
        }
        else
            cout<<"Invalid email/password\n";
    case 2:
        {
            buyer();
        }
    case 3:
        {
            exit(0);
        }
    default:
        {
            cout<<"Please select from the given options\n";

        }
    }
    goto m;
}
void shopping::administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|____1)Add the product_____|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____2)Modify the product__|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____3)Delete the product__|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____4)Back to main menu __|";
    cout<<"\n\t\t\t|                          |";

    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break'
    case 4:
        menu();
        break;
    default :
        cout<<"Invalid Choice!";
    }
    goto m;
}

void shopping::buyer()
{
    m:
    int choice;
    cout<<"\t\t\t   Buyer   \n";
    cout<<"\t\t\t_____________\n";
    cout<<"\t\t\t               \n";
    cout<<"\t\t\t 1)Buy Product \n";
    cout<<"\t\t\t               \n";
    cout<<"\t\t\t 2)Go back     \n";
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;

    default :
        cout<<"Invalid Choice!";
    }
    goto m;

}

void shopping::add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;


    cout<<"\n\n\t\t\t   Add new product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product  ";
    cin>>pname;
    cout<<"\n\n\t Price of the product  ";
    cin>>price;
    cout<<"\n\n\t Discount of the product  ";
    cin>>dis;

    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::in);
        data<<" "<<pcode<<" "<<pname<<" "<<dis>>"\n";
        data.close();
    }
    else
    {

        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
                token++;
            data>>c>>n>>p>>d;
        }
    }

}
