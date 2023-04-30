#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class room;
room* r[30];
int n=0;
class person;

//void administrator();
//void customer();
//class -1
//room
class room
{
public:
    int roomno;
    int status;
    int rent;
    room():status() {}
    //Function 1 for
    //isroom function
    int isroom(int rr)
    {
        {
            for(int i=0; i<n; i++)
            {
                if (r[i]->roomno==rr)
                {
                    return 0;
                }
            }
            return 1;
        }
    }

    // function -2 for room information
    //getroom info function
    void getroomno()
    {
en:
        cout<<"enter room no:";
        cin>>roomno;
        cout<<"enter rent:";
        cin>>rent;
        int f=isroom(roomno);
        if(f==0)
        {
            cout<<"room is already present";
            goto en;
        }
    }

    // function 3 for putdata
    void putdata()
    {
        cout<<"   "<<roomno;
        if(status==0)
            cout<<"            vacant";
        else
            cout<<"            occupaied";
    }

    // function 4 for room status check
    int is_vacant(room* r)
    {
        if(r->status==0)return 1;
        else return 0;
    }

    // function 5 for vacants room details
    void vacateRoom(int rno)
    {
        int i;
        for(i=0; i<n; i++)
        {
            if(this->roomno==rno)
                this->status=0;
        }
    }


    virtual void getroominfo()=0;
    virtual void show()=0;

    //function 6 for get rent
    void getrent()
    {
        cin>>rent;
    }
};


// class 2
class viproom:public room
{
    string rmtype;
    string rmsize;
    room *re;
public:

    //constructor
    viproom()
    {
        rmtype="comfortable/ac";
        rmsize="big";
    }

    //functon 1 for getroom information
    void getroominfo()
    {
        room::getroomno();
    }

    //function 2 for show room information
    void show()
    {
        room::putdata();
        cout<<"             "<<rent<<"            "<<rmsize<<"             "<<rmtype<<endl;
    }

};

// class 3
class norrom:public room
{
private:
    string rmtype;
    string rmsize;
    room *re;
public:
    //constructor
    norrom()
    {
        rmtype="non_ac";
        rmsize="small";
    }
    //function 1 for get room information
    void getroominfo()
    {
        room::getroomno();

    }
    //function 2 for show details
    void show()
    {
        room::putdata();
        cout<<"             "<<rent<<"             "<<rmsize<<"             "<<rmtype;
    }

};
//
//// class 4 for dish
//class Dish
//{
//    string disname;
//    string distype;
//public:
//    int price;
//    //constructor
//    Dish() {}
//    Dish(string dish_name, float price, string dish_type)
//    {
//        this->disname = dish_name;
//        this->price = price;
//        this->distype = dish_type;
//    }
//    // function 1 for get dish
//    void get_dish()
//    {
//        cout<<disname<<"-"<<price<<"\n";
//    }
//    // function 2 for get_dish_name
//    string get_dish_name()
//    {
//        return disname;
//    }
//};

//// class 6
//class Restaurant
//{
//    int cost;
//public:
//    //constructor
//    Restaurant()
//    {
//        cost=00;
//    }
//    //map
//    map<string,vector<Dish>>dishes;
//    // function -1 for resmenu
//    void resmenu()
//    {
//        system("cls");
//        cout<<"\n*******menu*******";
//        for(auto itr: dishes)
//        {
//            cout << itr.first << ":\n";
//            for (int i = 0; i < itr.first.size(); i++) cout << "-";
//            cout << "\n";
//            for (auto it : itr.second) it.get_dish();
//            cout << "\n";
//        }
//    }
//
//    //function for dish time
//    void add_dish_ctime(string type, string name, float price)
//    {
//        Dish temp(name, price, type);
//        dishes[type].push_back(temp);
//    }
//    void order_food();
//    friend int total_bill(Restaurant);
//};
//// function for oder food
//void Restaurant::order_food()
//{
//    resmenu();
//    string d,ty;
//    int y;
//    cout<<"enter the names of food you want to order\n0 for exit\n";
//    while(d!="0")
//    {
//        cin>>ty;
//        cout<<"which one:";
//        cin>>d;
//        cout<<"quantity\n";
//        cin>>y;
//        auto itr=dishes[ty].begin();
//        for(; itr != dishes[ty].end(); itr++)
//
//            if(d==itr->get_dish_name())
//                break;
//        if (itr ==dishes[ty].end())
//            cout << "\nno item";
//        else
//            cost=y*itr->price+cost;
//    }
//}
//


//class 7 for room management
class roomManagement:protected viproom,protected norrom
{
public:
    void searchRoom(int);
    void modifyroom(int);
    void displayRoom();
    void addroom();
    void available_room();
    void typeroom();
};

void roomManagement::typeroom()
{
    viproom* vv;
    norrom* nr;
    cout<<"what you want to scerch.\n1.vip room or 2. normal room\n";
    int j,c1=0,c2=0;
    cin>>j;
    if(j==2)
    {
        for(int i=0; i<n; i++)
        {
            if(nr=dynamic_cast<norrom*>(r[i]))
            {
                c2++;
                r[i]->show();
            }

        }
    }
    else if(j==1)
    {
        for(int i=0; i<n; i++)
        {
            if(vv=dynamic_cast<viproom*>(r[i]))
            {
                c1++;
                r[i]->show();
            }

        }
    }
    if(c1==0 && j==1)
        cout<<"there are no vip room\n";
    else
        cout<<"there is no normal room\n";
    getch();

}
void roomManagement::available_room()
{
    bool flag=false;
    for(int i=0; i<n; i++)
    {
        if(r[i]->status==0)
        {
            r[i]->show();
            flag = true;
        }
    }
    if(flag==false)
        cout<<"There is no available room.\n";
    getch();
}


void roomManagement::addroom()
{
    char ch;
    int option ;
    do
    {

        cout<<"1.VIP ROOM\n2.AFFORTABLE ROOM\n3.Back\nenter your option: ";
        cin>>option;
        if(option==1)
        {
            r[n]=new viproom;
            r[n]->getroominfo();
            n++;
        }
        else if(option==2)
        {
            r[n]=new norrom;
            r[n]->getroominfo();
            n++;
        }
        else if(option==3)
            break;
        else
        {
            cout<<"enter correct choice\n";
            goto l;
        }

l:
        cout<<"do you want to continue:(y or n)\n";
        cin>>ch;

    }
    while(ch=='y');
    // getch();
}


void roomManagement::displayRoom()
{
    cout<<"show all room:\n";
    cout<<"\n\n +---------+------------------+-----------------+-------------+------------+";
    cout<<"\n | Room No.|    status        |      rent   |   Room size  |    room type    ";
    cout<<"\n +---------+------------------+-----------------+--------------+-------------+\n";

    for(int i=0; i<n; i++)
    {
        r[i]->show();
        cout<<endl;
    }
    getch();
}


void roomManagement::searchRoom(int rr)
{
    for(int i=0; i<n; i++)
    {
        if(r[i]->roomno==rr)
        {
            cout<<"show all room:\n";
            cout<<"\n\n +---------+------------------+-----------------+-------------+------------+";
            cout<<"\n | Room No.|    status        |      rent   |   Room size  |    room type    ";
            cout<<"\n +---------+------------------+-----------------+--------------+-------------+\n";
            r[i]->show();
            cout<<endl;
        }
        else
        {
            cout<<"There is no data for the Room\n";
        }
    }
    getch();
}


void roomManagement::modifyroom(int rr)
{
    char ch;
    for(int i=0; i<n; i++)
    {
        if(r[i]->roomno==rr)
        {
            cout<<"which type room you want to convert....\nPRESS v FOR VIP\nPRESS any FOR AFFORTABLE ROOM\n";
            cin>>ch;
            if(ch=='v')
                r[i]=new viproom;

            else
                r[i]=new norrom;
            r[i]->roomno=rr;
            r[i]->getrent();
        }
    }
    getch();
}

/// class for person details
class person
{
    string name;
    string add;
    string phone;
    int day;
    static int idno;
    string checkInTime;
    int status;
    int rn;
    int bill;
public:

    person()
    {
        time_t c=time(0);
        string dt = ctime(&c);
        this->name=" ";
        this->add =" ";
        //this->custid =" ";
        this->phone = " ";
        this->checkInTime = dt;
        status=0;
    }
    void searchCustomer();
    void check_out();
    void edit();
    void food();
    void checkin();
    friend int total_bill(Restaurant);
};

void person::checkin()
{
    int m,flag=0,p;
    ofstream fout;
    cout<<"enter room no: ";
    cin>>p;

    for(int i=0; i<n; i++)
    {
        if(r[i]->roomno==p &&r[i]->status==0)
        {
            cout<<"this room is available";
            m=i;
            flag=1;
            r[i]->status=1;//bill=r[i]->rent;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"this room is not available\n";
    }
    else
    {
        bill=r[m]->rent;
        cout<<"\nenter name: ";
        cin>>name;
        string uname=name+".txt";
        fout.open(uname.c_str());
        {
            int ds;
            cout<<"enter discout: ";
            cin>>ds;
            bill=(r[m]->rent*(100-ds))/100;
        }

        time_t now=time(0);
        string dt = ctime(&now);
        this->checkInTime = dt;
        rn=p;
        cout<<" Address: ";
        cin>>add;
        cout<<" Phone Number: ";
        cin>>phone;
        cout<<" Number of Days: ";
        cin>>day;
        bill=bill*day;
        status=1;
        fout<<name<<endl<<rn<<endl<<add<<endl<<phone<<endl<<day<<endl<<status;
        //fout.write((char*)this, sizeof(this));
        cout<<"\n Room has been booked.";
    }

    cout<<"press any key to continue\n";
    getch();
    fout.close();
}

int total_bill(Restaurant p)
{
    return (p.cost);
}
void person:: food()
{
    string ana;
    cout<<"enter your name";
    cin>>ana;
    ifstream fu(ana+".dat",ios::app | ios::out |ios::in | ios::binary);
    if(!fu.is_open()&& fu.fail()||status==0)
        cout<<"no customer in this name";
    else
    {
        Restaurant a;
        a.order_food();

        bill=total_bill( a)+bill;
    }

}
void person::edit()
{

}


void person::searchCustomer()
{
    string ana,usern,uu;
    cout<<"Enter name: ";
    cin>>ana;
    uu=ana+".txt";
    ifstream filei;
    filei.open(uu.c_str());
    if(!filei.is_open() && filei.fail())
    {
        cout<<"no customer found\n";
        filei.close();
    }
    else
    {
        getline(filei,usern);
        if(usern==ana)
        {
            cout<<"\n Customer Details";
            cout<<"\n ----------------";
            filei>>name>>rn>>add>>phone>>day>>bill>>checkInTime;
            cout<<"\n Name: "<<name;
            cout<<"\n Room Number: "<<rn;
            cout<<"\n Address: "<<add;
            cout<<"\n Phone Number: "<<phone;
            cout<<"\n Staying for "<<day<<" days.";
            cout<<"\n Total cost: "<<bill;
            cout<<"\ncheck in time"<<checkInTime;
        }

    }
    getch();
    filei.close();
}


void person::check_out()
{
    char u[20],cc;
    int y;
    string ana,usern,uu;
    cout<<"enter name: ";
    cin>>ana;
    uu=ana+".txt";
    ifstream filei(uu);
    if(!filei.is_open() && filei.fail())
    {
        cout<<"no customer found\n";
        filei.close();
    }
    else
    {
        while(filei)
        {
            filei.get(cc);
            cout<<cc;

        } //y=(int)rn;
    }

    cout<<"enter room no:";
    cin>>y;
    for(int i=0; i<n; i++)
    {
        if(r[i]->roomno==y)
        {
            r[i]->status=0;
        }
    }
    cout<<"enter this name again:";
    cin>>u;
    remove( u);
    cout<<"checkout successfully";
    getch();
}

void menu()
{
    cout<<"1.manage room\n2.search by room no\n3.available room\n4.search by category\n5.About customer\n6.Main Menu\n";
}
void manageRoom();
void aboutCustomer();



//register funtion
void registr()
{
    string reguser, regpass;
    system("cls");
    cout << "Enter the username :";
    cin >> reguser;
    cout << "Enter the password :";
    cin >> regpass;
    ofstream reg("database.txt", ios::app);
    reg << reguser << ' ' << regpass << endl;
    cout << "Registration is successfull\n";
    getch();
    administrator();
}


//login function

void login()
{
    int exist=0;
    string user, pass, u, p;
    system("cls");
    cout << "Enter the username :";
    cin >> user;
    cout << "Enter the password :";
    cin >> pass;

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)
        {
            exist = 1;
        }
    }
    input.close();
    if (exist == 1)
    {
        cout << "Hello " << user << "\n We're glad that you're here \n";
        customer();
        return ;
    }
    else
    {
        cout << "Sorry,login error. \n";
        cin.get();
        cin.get();
        return ;
    }
}

//forgot function
void forgot()
{

    system("cls");
    cout << "1.search your account by username ";
    cout << "\n2.Search your account by password";
    cout << "\n3.Main menu";
    cout << "\nEnter your choice :";
    int ch;
    cin>>ch;
    switch (ch)
    {
    case 1:
    {
        int ex = 0;
        string searchuser, su, sp;
        ifstream searchu("database.txt");
        cout << "Enter your remembered username :";
        cin >> searchuser;

        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                ex = 1;
                break;
            }
        }
        searchu.close();
        if (ex == 1)
        {
            cout << "Hurray : account found !\n";
            cout << "Your password is " << sp<<endl;
            getch();
            administrator() ;

        }
        else
        {
            cout << "Sorry, Your account is not found \n";
            getch();
            forgot() ;
        }
        break;
    }

    case 2:
    {
        int exi = 0;
        string searchpass, su2, sp2;
        ifstream searchp("database.txt");
        cout << "Enter the remembered password :";
        cin >> searchpass;

        while(searchp>>su2>>sp2)
        {
            if(sp2==searchpass)
            {
                exi =1 ;
            }
        }
        searchp.close();
        if(exi==1)
        {
            cout<<"Hurray ! the account found \n";
            cout<<"Your Username is :"<<su2<<endl;
            cout<<"Your password is :"<<sp2<<endl;
            getch();
            administrator() ;
        }
        else
        {
            cout << "Sorry, Your account is not found \n";
            getch();
            forgot() ;

        }
        break;
    }

    case 3:
        return ;
        break;
    default :
    {
        cout<<"Your have a wrong choice. Press a key to try again.";
        cin.get();
        cin.get();
        forgot();
    }

    }
}






//Customer funtion

void customer()
{
    int option;
    int roomNo;
    person p;
    system("cls");
    Restaurant res;
    roomManagement rm;
    do
    {

        system ("cls");
        menu();
        cout<<"enter your option: ";
        cin>>option;
        switch(option)
        {
        case 1:
            manageRoom();
            break;
        case 2:
            cout<<"enter room no you want to secrch:";
            cin>>roomNo;
            rm.searchRoom(roomNo);
            break;
        case 3:
            rm.available_room();
            break;
        case 4:
            //scerch only for normal or vip room
            rm.typeroom();
            break;
        case 5:
            aboutCustomer();
            break;
        case 6:
            return ;
        case 7:
            res.resmenu();
            getch();
            break;
        default :
            cout<<"enter write choice\n";
            break;
        }

    }
    while (option!=6);
    getch();
}


int main()
{


//    cout<<"      \n\t\t\t--------------------------------";
//    cout<<"      \n\t\t\t| HOTEL MANAGEMENT PROJECT      |";
//    cout<<"      \n\t\t\t--------------------------------";
//    cout<<"      \n\n\t\t\t Developed By:   Nazibur Rahman(IT-21017)\n";
//    cout<<"      \t\t\t\t\t Mahmudul Hasan(IT-21019)\t\t\t\t\t   ";
//    cout<<"      \n\n\t\t\t submitted to :  S.M. Shamim";
//    cout<<"      \n\t\t\t\t\t Assistant Professor  ";
//    cout<<"      \n\t\t\t\t\t ICT,MBSTU  ";
//    cout<<"      \n\n\n\n\n\n\n\t\t\tPress any key to enter the main program!!\n";
//    getch();


    system("cls");
    cout<<"1.Administrator"<<endl;
    cout<<"2.Customer"<<endl;
    int choice;
    cout<<"Please enter you choice :"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        administrator();
        break;
    case 2:
        customer();
        break;
    default :
        cout<<"Sorry wrong choice selected"<<endl;
        break;

    }




}
//
////Administrator function
//void administrator()
//{
//    system("cls");
//    int choice;
//    cout << " ********Login******\n";
//    cout << "1.Login";
//    cout << "\n2.register";
//    cout << "\n3.Forgot Credentials";
//    cout << "\nEnter your choice:";
//    cin >> choice;
//    switch (choice)
//    {
//    case 1:
//        login();
//        break;
//    case 2:
//        registr();
//        break;
//    case 3:
//        forgot();
//        break;
//    case 4:
//        cout << "Thanks for using the login page\n";
//        break;
//    default:
//        cout << "Sorry,Wrong choice selected\n";
//        return;
//    }
//}
//




void manageRoom()
{
    roomManagement rm;

    int option;

    do
    {
        system("cls");
        cout<<"1.add room\n2.display all room\n3.modify room\n4.back to main manu\nenter your option:";
        cin >> option;
        switch (option)
        {
        case 1:
            rm.addroom();
            break;
        case 2:
            rm.displayRoom();
            break;
        case 3:
            int roomNo;
            cout<<"enter room no:";
            cin>>roomNo;
            rm.modifyroom(roomNo);
            break;
        case 4:
            break;
        default:
            cout << "\nPlease Enter correct option\n";
            break;
        }
    }
    while (option != 4);
}







void aboutCustomer()
{
    person p;
    int j;
    do
    {
        system("cls");
        cout<<"1.check in\n2.check out\n3.search customer\n4.edit customer record\n5.back main page\n";
        cin>>j;
        switch(j)
        {
        case 1:
            p.checkin();
            break;
        case 2:
            p.check_out();
            break;
        case 3:
            p.searchCustomer();
            break;
        case 4:
            p.edit();
            break;
        case 5:
            break;
        default:
            cout<<"wrong choice\n";
            break;
        }
    }
    while(j!=5);
}
