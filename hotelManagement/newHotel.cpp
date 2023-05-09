#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include <windows.h>
using namespace std;
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void manageRoom();
void ProjectName();

class administrator
{
public:
    void adminMenu()
    {
        // ofstream reg("username&password.txt", ios::app);
        // ofstream reg("username&password.txt");
        system("cls");

        ProjectName();
        gotoxy(50, 8);
        cout << "|                                          |";
        gotoxy(50, 9);
        // cout << "+------------------------------------------+";
        cout << "| 1.Login                                  |" << endl;
        gotoxy(50, 10);
        cout << "|                                          |";
        gotoxy(50, 11);
        cout << "| 2.Forgot                                 |" << endl;
        gotoxy(50, 12);
        cout << "|                                          |";
        gotoxy(50, 13);
        cout << "| 3.Main Menu                              |" << endl;
        gotoxy(50, 14);
        cout << "|------------------------------------------|";
        gotoxy(50, 15);
        cout << "  Please enter your choice : ";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            forgot();
            break;
        case 3:
            return;
        default:
        {
            cout << "Your have a wrong choice. Press a key to try again.";
            getch();
            adminMenu();
        }
        }
    }

    void login()
    {
        int exist=0;
        string user, pass, u, p;
        system("cls");
        cout << "Enter the username :";
        cin >> user;
        cout << "Enter the password :";
        cin >> pass;
        ifstream input("username&password.txt");
        while (input >> u >> p)
        {
            if (u == user && p == pass)
            {
                exist = 1;
            }
        }
        // input.close();
        if (exist == 1)
        {
            // cout << "Hello " << user << "\n We're glad that you're here \n";
            // getch();
            manageRoom();
            // main();
            // adminMenu();
        }
        else
        {
            cout << "Sorry,login error. ";
            getch();
            adminMenu();
        }
    }

    void forgot()
    {
        int ch;
        system("cls");
        cout << "1.Search your account by username ";
        cout << "\n2.Search your account by password";
        cout << "\n3.Back";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int ex = 0;
            string searchuser, su, sp;
            ifstream searchu("username&password.txt");
            cout << "Enter your remembered username: ";
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
                cout << "Your password is " << sp << endl;
                getch();
                adminMenu();
            }
            else
            {
                cout << "Sorry, Your account is not found. \n";
                getch();
                adminMenu();
            }
            break;
        }

        case 2:
        {
            int exi = 0;
            string searchpass, su2, sp2;
            ifstream searchp("username&password.txt");
            cout << "Enter the remembered password: ";
            cin >> searchpass;

            while (searchp >> su2 >> sp2)
            {
                if (sp2 == searchpass)
                {
                    exi = 1;
                }
            }
            searchp.close();
            if (exi == 1)
            {
                cout << "Hurray ! the account found \n";
                cout << "Your Username is: " << su2 << endl;
                cout << "Your password is: " << sp2 << endl;
                getch();
                adminMenu();
            }
            else
            {
                cout << "Sorry, Your account is not found. \n";
                getch();
                adminMenu();
            }
            break;
        }
        case 3:
        {
            adminMenu();
            break;
        }
        default:
        {
            cout << "Your have a wrong choice. Press a key to try again.";
            getch();
            forgot();
        }
        }
    }
};

class roomManagement
{
public:
    string roomNo, bedNum, ac, rent, status;
    void addRoom()
    {
        // cout<<"Add Room"<<endl;
        // getch();
        system("cls");
        cout << "1.Vip Room" << endl;
        cout << "2.Normal Room" << endl;
        cout << "3.Back" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            // cout<<"VIP"<<endl;
            // getch();
            ofstream vip("viproom.txt", ios::app);
            cout << "Please enter room no." << endl;
            cin >> roomNo;
            cout << "Please enter number of bed." << endl;
            cin >> bedNum;
            cout << "Please enter Ac or Non-Ac." << endl;
            cin >> ac;
            cout << "Please enter rent." << endl;
            cin >> rent;
            // cout<<"Please enter status"<<endl;
            // cin>>status;
            status = "0";
            vip << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
            // while(cin>>roomNo>>bedNum>>ac>>rent>>status)
            // {
            //     vip<<roomNo<<" "<<bedNum<<" "<<ac<<" "<<rent<<" "<<status<<endl;
            // }
        }
        else if (choice == 2)
        {
            ofstream vip("normalroom.txt", ios::app);
            // string roomNo,bedNum,ac,rent,status;
            cout << "Please enter room no" << endl;
            cin >> roomNo;
            cout << "Please enter number of bed" << endl;
            cin >> bedNum;
            cout << "Please enter Ac or Non-Ac" << endl;
            cin >> ac;
            cout << "Please enter rent" << endl;
            cin >> rent;
            // cout<<"Please enter status"<<endl;
            // cin>>status;
            status = "0";
            vip << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
        }
        else if (choice == 3)
        {
            return;
        }
        else
        {
            cout << "Your have a wrong choice. Press a key to try again." << endl;
            getch();
            addRoom();
        }
    }
    void displayAllRoom()
    {
        system("cls");
        cout << "1.Vip Room" << endl;
        cout << "2.Normal Room" << endl;
        cout << "3.Back" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            ifstream vip("viproom.txt", ios::app);
            cout << "Show all Vip room:\n";
            cout << "\n+---------+---------------+--------------+------------+-----------------+";
            cout << "\n| Room No.| Number of bed | Ac or Non Ac |    Rent    |       Status    |";
            cout << "\n+---------+---------------+--------------+------------+-----------------+\n";
            while (vip >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (status == "0")
                    cout << "   " << roomNo << "\t         " << bedNum << "\t        " << ac << "\t      " << rent << "\t     "
                         << "Available" << endl;
                else
                    cout << "   " << roomNo << "\t         " << bedNum << "\t        " << ac << "\t      " << rent << "\t     "
                         << "Booked" << endl;
            }
        }
        else if (choice == 2)
        {
            ifstream normal("normalroom.txt", ios::app);
            cout << "Show all Vip room:\n";
            cout << "\n+---------+---------------+--------------+------------+-----------------+";
            cout << "\n| Room No.| Number of Bed | Ac or Non Ac |    Rent    |       Status    |";
            cout << "\n+---------+---------------+--------------+------------+-----------------+\n";
            while (normal >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (status == "0")
                    cout << "   " << roomNo << "\t         " << bedNum << "\t        " << ac << "\t      " << rent << "\t     "
                         << "Available" << endl;
                else
                    cout << "   " << roomNo << "\t         " << bedNum << "\t        " << ac << "\t      " << rent << "\t     "
                         << "Booked" << endl;
            }
        }
        else
        {
            return;
        }
        getch();
    }

    void displayAvailableRoom()
    {
        system("cls");
        cout << "1.Vip Room" << endl;
        cout << "2.Normal Room" << endl;
        cout << "3.Back" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            ifstream vip("viproom.txt", ios::app);
            cout << "show all vip available room:\n";
            cout << "\n+---------+---------------+--------------+------------+-----------------+";
            cout << "\n| Room No.| Number of bed | Ac or Non Ac |    Rent    |       Status    |";
            cout << "\n+---------+---------------+--------------+------------+-----------------+\n";
            while (vip >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (status == "0")
                    cout << "   " << roomNo << "\t         " << bedNum << "\t        " << ac << "\t      " << rent << "\t     "
                         << "Available" << endl;
            }
        }
        else if (choice == 2)
        {
            ifstream normal("normalroom.txt", ios::app);
            cout << "show all normal available room:\n";
            cout << "\n+---------+---------------+--------------+------------+-----------------+";
            cout << "\n| Room No.| Number of bed | Ac or Non Ac |    Rent    |       Status    |";
            cout << "\n+---------+---------------+--------------+------------+-----------------+\n";
            while (normal >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (status == "0")
                    cout << "   " << roomNo << "\t         " << bedNum << "\t        " << ac << "\t      " << rent << "\t     "
                         << "Available" << endl;
            }
        }
        else
        {
            return;
        }
        getch();
    }

    void copyvip()
    {

        ifstream viptemp("viptemp.txt", ios::app);
        ofstream viproom("viproom.txt", ios::out);
        while (viptemp >> roomNo >> bedNum >> ac >> rent >> status)
        {
            viproom << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
        }
    }

    void copynormal()
    {

        ifstream normaltemp("normaltemp.txt", ios::app);
        ofstream normalroom("normalroom.txt", ios::out);
        while (normaltemp >> roomNo >> bedNum >> ac >> rent >> status)
        {
            normalroom << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
        }
    }

    void modifyRoom()
    {
        system("cls");
        cout << "1.Vip Room" << endl;
        cout << "2.Normal Room" << endl;
        cout << "3.Back" << endl;
        int choice;
        cin >> choice;
        string rmNo;
        cout << "Enter room no: ";
        cin >> rmNo;
        if (choice == 1)
        {
            // read mood
            fstream vip;
            vip.open("viproom.txt", ios::in);
            // write mood
            fstream viptemp;
            viptemp.open("viptemp.txt", ios::out);

            while (vip >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {

                    cout << "Please enter Number of bed" << endl;
                    cin >> bedNum;
                    cout << "Please enter Ac or Non-Ac" << endl;
                    cin >> ac;
                    cout << "Please enter Rent" << endl;
                    cin >> rent;
                    cout << "Please enter status" << endl;
                    cin >> status;
                    // status = "0";
                    viptemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
                else
                {
                    viptemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
            }
            copyvip();
            // vip.close();
            // viptemp.close();
        }

        else if (choice == 2)
        {
            // read mood
            fstream normal;
            normal.open("normalroom.txt", ios::in);
            // write mood
            fstream normaltemp;
            normaltemp.open("normaltemp.txt", ios::out);

            while (normal >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {

                    cout << "Please enter Number of bed" << endl;
                    cin >> bedNum;
                    cout << "Please enter Ac or Non-Ac" << endl;
                    cin >> ac;
                    cout << "Please enter Rent" << endl;
                    cin >> rent;
                    cout << "Please enter status" << endl;
                    cin >> status;
                    // status = "0";
                    normaltemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
                else
                {
                    normaltemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
            }
            copynormal();
            // vip.close();
            // viptemp.close();
        }
        else
        {
            return;
        }

        getch();
    }

    string findRent(string rmNo, int type)
    {
        if (type == 1)
        {
            // read mood
            fstream vip;
            vip.open("viproom.txt", ios::in);
            while (vip >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {
                    return rent;
                }
            }
        }

        else
        {
            // read mood
            fstream normal;
            normal.open("normalroom.txt", ios::in);
            while (normal >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {
                    return rent;
                }
            }
        }
        return "0";
    }
    void changeStatus(string rmNo, int type, string stat)
    {
        if (type == 1)
        {
            // read mood
            fstream vip;
            vip.open("viproom.txt", ios::in);
            // write mood
            fstream viptemp;
            viptemp.open("viptemp.txt", ios::out);

            while (vip >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {

                    status = stat;
                    viptemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
                else
                {
                    viptemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
            }
            copyvip();
        }

        else
        {
            // read mood
            fstream normal;
            normal.open("normalroom.txt", ios::in);
            // write mood
            fstream normaltemp;
            normaltemp.open("normaltemp.txt", ios::out);

            while (normal >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {
                    status = stat;
                    normaltemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
                else
                {
                    normaltemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
            }
            copynormal();
        }
    }
    // return 1 for available
    // return 0 for not available
    // return -1 for not found
    int checkStatus(string rmNo, int type)
    {
        if (type == 1)
        {
            // read mood
            fstream vip;
            vip.open("viproom.txt", ios::in);

            while (vip >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {

                    if (status == "0")
                        return 0;
                    else
                        return 1;
                }
            }
            return 1;
        }

        else
        {
            // read mood
            fstream normal;
            normal.open("normalroom.txt", ios::in);

            while (normal >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {

                    if (status == "0")
                        return 0;
                    else
                        return 1;
                }
            }
            return 1;
        }
    }
    void checkIn()
    {
        system("cls");
        cout << "1.Vip Room" << endl;
        cout << "2.Normal Room" << endl;
        cout << "3.Back" << endl;
        cout << "Enter your Choice: ";
        int choice;
        cin >> choice;
        if (choice == 3)
            return;

        string rm;
        cout << "Room No: ";
        cin >> rm;

        string name, vill, post, ps, dist, phn, days;
        if (checkStatus(rm, choice) == 1)
            cout << "This room is not available" << endl;
        // else if(checkStatus(rm,choice)==-1)

        else if (choice == 1)
        {
            string tk = findRent(rm, 1);
            cout << "Amount to be paid: " << tk << endl;
            cout << "Name: ";
            getchar();
            getline(cin, name);

            cout << "Village: ";
            getline(cin, vill);

            cout << "P.O: ";
            getline(cin, post);

            cout << "P.S: ";
            getline(cin, ps);

            cout << "Dist.: ";
            getline(cin, dist);

            cout << "Mobile: ";
            getline(cin, phn);

            // cout << "Number of days:";
            // getline(cin, days);

            time_t now = time(0);
            string dt = ctime(&now);

            string uname = name + ".txt";
            ofstream fout;
            fout.open(uname.c_str());
            fout << "Room No: " << rm << endl;
            fout << "Room Type: VIP" << endl;
            fout << "Name: " << name << endl;
            fout << "Village: " << vill << endl;
            fout << "Post.: " << post << endl;
            fout << "P.S: " << ps << endl;
            fout << "Dist.: " << dist << endl;
            fout << "Mobile: " << phn << endl;
            // fout << "Number of days: " << days << endl;
            fout << "Check In: " << dt << endl;

            changeStatus(rm, 1, "1");
            cout << "Check In Successful." << endl;
            getch();
            system("cls");
            cout << "Do you want to purchase food ?" << endl;
            cout << "1.Yes" << endl;
            cout << "2.No" << endl;
            cout << "Enter your choice: " << endl;
            int option;
            cin >> option;
            if (option == 1)
                purchaseFood();

            // getch();
        }
        else if (choice == 2)
        {
            string tk = findRent(rm, 2);
            cout << "Amount to be paid : " << tk << endl;
            cout << "Name:";
            getchar();
            getline(cin, name);

            cout << "Village:";
            getline(cin, vill);

            cout << "P.O:";
            getline(cin, post);

            cout << "P.S:";
            getline(cin, ps);

            cout << "Dist.:";
            getline(cin, dist);

            cout << "Mobile:";
            getline(cin, phn);

            // cout << "Number of days:";
            // getline(cin, days);

            time_t now = time(0);
            string dt = ctime(&now);

            string uname = name + ".txt";
            ofstream fout;
            fout.open(uname.c_str());
            fout << "Room No: " << rm << endl;
            fout << "Room Type: Normal" << endl;
            fout << "Name: " << name << endl;
            fout << "Village: " << vill << endl;
            fout << "Post.: " << post << endl;
            fout << "P.S: " << ps << endl;
            fout << "Dist.: " << dist << endl;
            fout << "Mobile: " << phn << endl;
            // fout << "Number of days: " << days << endl;
            fout << "Check In: " << dt << endl;
            cout << "Check In Successful." << endl;
            changeStatus(rm, 2, "1");

            getch();
            system("cls");
            cout << "Do you want to purchase food ?" << endl;
            cout << "1.Yes" << endl;
            cout << "2.No" << endl;
            cout << "Enter your choice:" << endl;
            int option;
            cin >> option;
            if (option == 1)
                purchaseFood();

            // getch();
        }
        // else if(choice == 3)
        //     customermenu();
        else
        {
            cout << "Your have a wrong choice. Press a key to try again.";
            // getch();
            // checkIn();
        }

        getch();
        // return ;
    }
    void checkout()
    {
        system("cls");
        string name;
        getchar();
        cout << "Please Enter your Name:";
        getline(cin, name);

        // cout<<name<<endl;
        // ifstream vip("viproom.txt", ios::app);
        string uname = name + ".txt";
        ifstream CustomerDetails(uname, ios::in);
        string line;
        int i = 0;

        while (getline(CustomerDetails, line))
        {
            // if(i>0)
            cout << line << endl;
            // i++;
        }
        cout << "Please Enter your Room No to confirm check out:";
        string rmN;
        cin >> rmN;
        cout << "Please Enter admin secret code to confirm check out:";
        int roomtype;
        cin >> roomtype;

        changeStatus(rmN, roomtype, "0");

        cout << "Check Out Successful." << endl;
        getch();
        // return ;
    }

    void purchaseFood()
    {
        system("cls");
        cout << "1.Bread Omelette + Banana + Water -100Tk" << endl;
        cout << "2.Chicken Biriyani + Water -150TK" << endl;
        cout << "3.Beef Khicuri + Water - 250Tk" << endl;
        int option;
        cout << "Please enter your choice." << endl;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            cout << "Amount to be paid - 100Tk" << endl;
            cout << "Press 'paid' to continue" << endl;
            string s;
            cin >> s;
            if (s == "paid")
                cout << "Thanks for your purchasing food." << endl;
            else
                cout << "Something went wrong." << endl;
            getch();
            break;
        }
        case 2:
        {
            cout << "Amount to be paid - 150Tk" << endl;
            cout << "Press 'paid' to continue" << endl;
            string s;
            cin >> s;
            if (s == "paid")
                cout << "Thanks for your purchasing food" << endl;
            else
                cout << "Something went wrong" << endl;
            getch();
            break;
        }
        case 3:
        {
            cout << "Amount to be paid - 250Tk" << endl;
            cout << "Press 'paid' to continue" << endl;
            string s;
            cin >> s;
            if (s == "paid")
                cout << "Thanks for your purchasing food" << endl;
            else
                cout << "Something went wrong" << endl;
            getch();
            break;
        }
        default:
        {
            cout << "Your have a wrong choice. Press a key to try again.";
            getch();
            purchaseFood();
            break;
        }
        }
    }
};

class customer : public roomManagement
{
public:
    void customermenu()
    {
        system("cls");
        gotoxy(50, 4);
        cout << "1.Available Room" << endl;
        gotoxy(50, 6);
        cout << "2.Check In" << endl;
        gotoxy(50, 8);
        cout << "3.Check Out" << endl;
        gotoxy(50, 10);
        cout << "4.Purchase Food" << endl;
        gotoxy(50, 12);
        cout << "5.Main Menu" << endl;
        gotoxy(50, 14);
        cout << "Please enter your choice : ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            // cout<<"Available Room";
            displayAvailableRoom();
            getch();
            customermenu();
        case 2:
            // cout << "Check In" << endl;
            checkIn();
            // getch();
            break;
        case 3:
            // cout << "Check out" << endl;
            // getch();
            checkout();
            break;
        case 4:
            // cout<<"Purchase food"<<endl;
            purchaseFood();
            // getch();
            break;
        case 5:
            return;
        default:
            cout << "Your have a wrong choice. Press a key to try again.";
            getch();
            customermenu();
        }
        // cout << "Customers" << endl;
        // getch();
        // return;
    }
};

void mainMenu()
{
    ProjectName();
    gotoxy(50, 8);
    cout << "|                                          |";
    gotoxy(50, 9);
    // cout << "+------------------------------------------+";
    cout << "| 1.Administrator                          |" << endl;
    gotoxy(50, 10);
    cout << "|                                          |";
    gotoxy(50, 11);
    cout << "| 2.Customer                               |" << endl;
    gotoxy(50, 12);
    cout << "|                                          |";
    gotoxy(50, 13);
    cout << "| 3.End the program                        |" << endl;
    gotoxy(50, 14);
    cout << "|------------------------------------------|";
}

void ProjectName()
{
    gotoxy(50, 5);
    cout << "+------------------------------------------+";
    gotoxy(50, 6);
    cout << "|         HOTEL MANAGEMENT PROJECT         |";
    gotoxy(50, 7);
    cout << "|------------------------------------------|";
}
int main()
{

    ProjectName();
    // gotoxy(50,7);
    // cout << "|                                          |"<<endl;
    gotoxy(50, 8);
    cout << "| Developed By:                            |" << endl;
    gotoxy(50, 9);
    cout << "| Nazibur Rahman(IT-21017)                 |\n";
    gotoxy(50, 10);
    cout << "| Mahmudul Hasan(IT-21019)                 |\n";
    gotoxy(50, 11);
    cout << "|------------------------------------------|";
    gotoxy(50, 12);
    cout << "| Submitted To:                            |" << endl;
    gotoxy(50, 13);
    cout << "| S.M. Shamim                              |" << endl;
    gotoxy(50, 14);
    cout << "| Assistant Professor                      |";
    gotoxy(50, 15);
    cout << "| ICT,MBSTU                                |";
    gotoxy(50, 16);
    cout << "|------------------------------------------|";
    gotoxy(50, 17);
    cout << "| Press any key to enter the main program. |\n";
    gotoxy(50, 18);
    cout << "  ";
    getch();
    // gotoxy(50,19);
    // cout << "+------------------------------------------+";

    // Object creation
    administrator admin;
    customer custom;

    // roomManagement ob;
    // ob.modifyRoom();

    // Main Menu
    int choice;
    do
    {
        system("cls");
        mainMenu();
        gotoxy(50, 15);
        cout << "  Please enter you choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            admin.adminMenu();
            break;
        case 2:
            custom.customermenu();
            break;
        case 3:
            return 0;
        default:
            cout << "Your have a wrong choice. Press a key to try again.";
            getch();
            // break;
        }
    } while (choice != 3);
}

void manageRoom()
{
    roomManagement rm;

    int option;
    do
    {
        system("cls");
        cout << "1.Add room\n2.Display all room\n3.Modify room\n4.Back to main menu\nEnter your option:";
        cin >> option;
        switch (option)
        {
        case 1:
            rm.addRoom();
            break;
        case 2:
            rm.displayAllRoom();
            break;
        case 3:
        {
            rm.modifyRoom();
            break;
        }
        case 4:
            break;
        default:
            cout << "\nPlease enter correct option\n";
            break;
        }
    } while (option != 4);
}