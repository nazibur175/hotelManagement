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

        system("cls");

        ProjectName();
        gotoxy(50, 8);
        cout << "|                                          |";
        gotoxy(50, 9);
        // cout << "+------------------------------------------+";
        cout << "| 1. Login                                 |" << endl;
        gotoxy(50, 10);
        cout << "|                                          |";
        gotoxy(50, 11);
        cout << "| 2. Forgot                                |" << endl;
        gotoxy(50, 12);
        cout << "|                                          |";
        gotoxy(50, 13);
        cout << "| 3. Main Menu                             |" << endl;
        gotoxy(50, 14);
        cout << "+------------------------------------------+";
        gotoxy(50, 15);
        cout << "=> Please enter your choice : ";

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
        int exist = 0;
        string user, pass, u, p;
        system("cls");
        ProjectName();
        gotoxy(50, 9);
        cout << "=>  Enter the username: ";
        cin >> user;
        gotoxy(50, 11);

        cout << "=>  Enter the password: ";
        char c;
        while((c=getch()) !=13){
            if(c==8){
                pass.pop_back();
                cout<<"\b \b";
            }
            else{
                pass.push_back(c);
                cout<<"*";
            }
        }
        cout<<endl;

        if(pass=="123456")
            exist=1;


        // cin >> pass;
        // ifstream input("username&password.txt");
        // while (input >> u >> p)
        // {
            // cout<<pass<<endl;
            // if (u == user && p == pass)
            // {
            //     exist = 1;
            // }
        // }
        // exist =1;
        if (exist == 1)
        {
            manageRoom();
        }
        else
        {
            gotoxy(50, 13);
            cout << "  Sorry,login error. ";
            getch();
            adminMenu();
        }
    }

    void forgot()
    {
        int ch;

        system("cls");
        ProjectName();
        gotoxy(50, 8);
        cout << "|                                          |";
        gotoxy(50, 9);
        cout << "| 1. Search your account by username       |";
        gotoxy(50, 10);
        cout << "|                                          |";
        gotoxy(50, 11);
        cout << "| 2. Search your account by password       |";
        gotoxy(50, 12);
        cout << "|                                          |";
        gotoxy(50, 13);
        cout << "| 3. Back                                  |";
        gotoxy(50, 14);
        cout << "+------------------------------------------+";
        gotoxy(50, 15);
        cout << "=> Please enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int ex = 0;
            string searchuser, su, sp;
            ifstream searchu("username&password.txt");

            system("cls");
            ProjectName();
            gotoxy(50, 9);
            cout << "|  Enter the remembered username: ";

            // cout << "Enter your remembered username: ";
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

                system("cls");
                ProjectName();
                gotoxy(50, 8);
                cout << "|                                          |";
                gotoxy(50, 9);
                cout << "|  Hurray ! the account found              |";
                gotoxy(50, 10);
                cout << "|                                          |";

                gotoxy(50, 11);
                cout << "|                                          |";
                gotoxy(50, 12);
                cout << "|  Your password is: " << sp << endl;
                gotoxy(50, 13);
                cout << "|                                          |";
                gotoxy(50, 14);
                cout << "+------------------------------------------+";

                getch();
                adminMenu();
            }
            else
            {
                gotoxy(50, 11);
                cout << "|  Sorry, Your account is not found. \n";
                // cout << "Sorry, Your account is not found. \n";
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
            system("cls");
            ProjectName();
            gotoxy(50, 9);
            cout << "|  Enter the remembered password: ";
            // cout << "Enter the remembered password: ";
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

                system("cls");
                ProjectName();
                gotoxy(50, 8);
                cout << "|                                          |";
                gotoxy(50, 9);
                cout << "|  Hurray ! the account found              |";
                gotoxy(50, 10);
                cout << "|                                          |";
                gotoxy(50, 11);
                cout << "|  Your Username is: " << su2 << endl;
                gotoxy(50, 12);
                cout << "|                                          |";
                gotoxy(50, 13);
                cout << "|  Your password is: " << sp2 << endl;
                gotoxy(50, 14);
                cout << "|------------------------------------------|";

                getch();
                adminMenu();
            }
            else
            {
                gotoxy(50, 11);
                cout << "|  Sorry, Your account  not found. \n";
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
    void CustomerDetails()
    {
        system("cls");
        ProjectName();
        gotoxy(50, 8);
        cout << "|                                          |";
        gotoxy(50, 9);
        cout << "| 1. Find individual customer              |" << endl;
        gotoxy(50, 10);
        cout << "|                                          |";
        gotoxy(50, 11);
        cout << "| 2. Show all customer                     |" << endl;
        gotoxy(50, 12);
        cout << "|                                          |";
        gotoxy(50, 13);
        cout << "| 3. Back                                  |" << endl;
        gotoxy(50, 14);
        cout << "+------------------------------------------+";
        gotoxy(50, 15);
        cout << "=> Please enter your choice: ";
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
        {
            // cout<<"Individual"<<endl;
            system("cls");
            getchar();
            string uname;
            ProjectName();
            gotoxy(50, 9);
            cout << "=> Please enter name: ";
            getline(cin, uname);
            ifstream CustomerDetails(uname + ".txt", ios::in);
            string line;
            // int i = 0;
            if (CustomerDetails)
            {
                system("cls");
                ProjectName();
                int x = 8;
                gotoxy(50, x);
                cout << "|";
                gotoxy(50 + 43, x);
                cout << "|";
                while (getline(CustomerDetails, line))
                {
                    gotoxy(50, x += 1);
                    cout << "| " << line << endl;
                    gotoxy(50 + 43, x);
                    cout << "|";
                }

                uname = uname + "vau.txt";
                ifstream Customervau(uname, ios::in);
                if (Customervau)
                {
                    gotoxy(50, x += 1);
                    cout << "+------------------------------------------+";
                    gotoxy(50, x += 1);
                    cout << "| Payment history" << endl;
                    gotoxy(50 + 43, x);
                    cout << "|";

                    while (getline(Customervau, line))
                    {
                        gotoxy(50, x += 1);
                        cout << "| " << line << endl;
                        gotoxy(50 + 43, x);
                        cout << "|";
                    }
                }
                gotoxy(50, x += 1);
                cout << "+------------------------------------------+";
                gotoxy(50, x += 1);
            }
            else
            {
                gotoxy(50, 11);
                cout << "=> No data available.";
                // CustomerDetails();
            }

            getch();
            break;
        }
        case 2:
        {
            system("cls");
            ProjectName();
            ifstream CustomerDetails("AllCustomerInfo.txt", ios::in);
            string line;
            gotoxy(50, 9);
            cout << "All Customer: ";
            gotoxy(50, 10);
            cout << "-------------" << endl;
            int x = 9;
            while (getline(CustomerDetails, line))
            {
                if (line != "")
                {
                    gotoxy(50, x += 2);
                    cout << "=> " << line << endl;
                }
            }
            gotoxy(50, x += 1);
            getch();
            break;
        }
        case 3:
        {
            // return;
            manageRoom();
            break;
        }

        default:
            break;
        }
        manageRoom();
    }
    void vipOrNormal()
    {
        system("cls");
        ProjectName();
        gotoxy(50, 8);
        cout << "|                                          |";
        gotoxy(50, 9);
        cout << "| 1. Vip room                              |" << endl;
        gotoxy(50, 10);
        cout << "|                                          |";
        gotoxy(50, 11);
        cout << "| 2. Normal room                           |" << endl;
        gotoxy(50, 12);
        cout << "|                                          |";
        gotoxy(50, 13);
        cout << "| 3. Back                                  |" << endl;
        gotoxy(50, 14);
        cout << "+------------------------------------------+";
        gotoxy(50, 15);
        cout << "=>Please enter your choice: ";
    }
    void getRoomInfo()
    {
        system("cls");
        ProjectName();
        gotoxy(50, 9);
        cout << "=> Please enter room no: ";
        cin >> roomNo;
        gotoxy(50, 11);
        cout << "=> Please enter number of bed: ";
        cin >> bedNum;
        gotoxy(50, 13);
        cout << "=> Please enter Ac or Non-Ac: ";
        cin >> ac;
        gotoxy(50, 15);
        cout << "=> Please enter rent: ";
        cin >> rent;

        gotoxy(50, 17);
        cout << "=> Please enter status: ";
        cin >> status;

        // status = "0";
    }
    void addRoom()
    {
        vipOrNormal();
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            ofstream vip("viproom.txt", ios::app);
            getRoomInfo();
            vip << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
            gotoxy(50, 19);
            cout << "=> New room added successful.";
            getch();
        }
        else if (choice == 2)
        {
            ofstream vip("normalroom.txt", ios::app);
            // string roomNo,bedNum,ac,rent,status;
            getRoomInfo();
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
    void tableMenu()
    {
        gotoxy(35, 8);
        cout << "+---------+---------------+--------------+------------+-----------------+";
        gotoxy(35, 9);
        cout << "| Room No.| Number of Bed | Ac or Non Ac |    Rent    |       Status    |";
        gotoxy(35, 10);
        cout << "+---------+---------------+--------------+------------+-----------------+";
    }
    void showAllRoomInfo(string fName)
    {
        ifstream vip(fName, ios::app);
        int x = 10;
        while (vip >> roomNo >> bedNum >> ac >> rent >> status)
        {
            gotoxy(35, x += 1);
            if (status == "0")
                cout << "   " << roomNo << "\t    " << bedNum << "\t        " << ac << "\t      " << rent << "\t     "
                     << "Available" << endl;
            else
                cout << "   " << roomNo << "\t    " << bedNum << "\t        " << ac << "\t      " << rent << "\t     "
                     << "Booked" << endl;
        }
        gotoxy(35, x + 1);
    }

    void showAllAvailableRoomInfo(string fName)
    {
        ifstream vip(fName, ios::app);
        int x = 10;
        while (vip >> roomNo >> bedNum >> ac >> rent >> status)
        {

            if (status == "0")
            {
                gotoxy(35, x += 1);
                cout << "   " << roomNo << "\t    " << bedNum << "\t        " << ac << "\t      " << rent << "\t     "
                     << "Available" << endl;
            }
        }
        gotoxy(35, x + 1);
    }

    void displayAllRoom()
    {
        vipOrNormal();
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            system("cls");
            ProjectName();
            tableMenu();
            showAllRoomInfo("viproom.txt");
        }
        else if (choice == 2)
        {
            system("cls");
            ProjectName();
            tableMenu();
            showAllRoomInfo("normalroom.txt");
        }
        else
        {
            return;
        }
        getch();
    }

    void displayAvailableRoom()
    {
        vipOrNormal();
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            system("cls");
            ProjectName();
            tableMenu();
            showAllAvailableRoomInfo("viproom.txt");
        }
        else if (choice == 2)
        {
            system("cls");
            ProjectName();
            tableMenu();
            showAllAvailableRoomInfo("normalroom.txt");
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
    void getModifyInfo()
    {
        gotoxy(50, 11);
        cout << "=> Please enter Number of bed: ";
        cin >> bedNum;
        gotoxy(50, 13);
        cout << "=> Please enter Ac or Non-Ac: ";
        cin >> ac;
        gotoxy(50, 15);
        cout << "=> Please enter Rent: ";
        cin >> rent;
        gotoxy(50, 17);
        cout << "=> Please enter status: ";
        cin >> status;
        gotoxy(50, 19);
        cout << "=> Modify successful.";
        // status = "0";
    }
    void modifyRoom()
    {
        vipOrNormal();
        int choice;
        cin >> choice;
        system("cls");
        ProjectName();
        gotoxy(50, 9);
        string rmNo;
        if (choice == 1)
        {
            // read mood
            fstream vip;
            vip.open("viproom.txt", ios::in);
            // write mood
            fstream viptemp;
            viptemp.open("viptemp.txt", ios::out);

            cout << "=> Please enter room no: ";
            cin >> rmNo;
            while (vip >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {
                    getModifyInfo();
                    viptemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
                else
                {
                    viptemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
            }
            copyvip();
        }

        else if (choice == 2)
        {
            // read mood
            fstream normal;
            normal.open("normalroom.txt", ios::in);
            // write mood
            fstream normaltemp;
            normaltemp.open("normaltemp.txt", ios::out);

            cout << "=> Please enter room no: ";
            cin >> rmNo;
            while (normal >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {
                    getModifyInfo();
                    normaltemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
                else
                {
                    normaltemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
            }
            copynormal();
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
    string name, vill, post, ps, dist, phn, days;
    void addCustomerDetails()
    {
        getchar();
        gotoxy(50, 11);
        cout << "=> Name: ";
        getline(cin, name);

        gotoxy(50, 12);
        cout << "=> Village: ";
        getline(cin, vill);

        gotoxy(50, 13);
        cout << "=> P.O: ";
        getline(cin, post);

        gotoxy(50, 14);
        cout << "=> P.S: ";
        getline(cin, ps);

        gotoxy(50, 15);
        cout << "=> Dist.: ";
        getline(cin, dist);

        gotoxy(50, 16);
        cout << "=> Mobile: ";
        getline(cin, phn);

        gotoxy(50, 17);
        cout << "=> Number of days: ";
        getline(cin, days);
    }
    void checkIn()
    {
        vipOrNormal();
        int choice;
        cin >> choice;
        if (choice == 3)
            return;
        system("cls");
        ProjectName();
        string rm;
        gotoxy(50, 9);
        cout << "=> Room No: ";
        cin >> rm;

        if (checkStatus(rm, choice) == 1)
        {
            gotoxy(50, 11);
            cout << "=> This room is not available!";
        }
        // else if(checkStatus(rm,choice)==-1)

        else if (choice == 1)
        {
            string tk = findRent(rm, 1);
            gotoxy(50, 10);
            cout << "=> Room rent per day: " << tk << endl;
            addCustomerDetails();

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
            fout << "Number of days: " << days << endl;
            fout << "Check In: " << dt << endl;

            string vauname = name + "vau.txt";
            ofstream vauout;
            vauout.open(vauname.c_str());
            int totalRent = stoi(tk) * stoi(days);
            gotoxy(50, 18);
            cout << "=> Total amount to be paid: " << totalRent;
            gotoxy(50, 19);
            cout << "=> Press 'paid' to continue: ";
            string s;
            cin >> s;
            if (s == "paid")
            {
                changeStatus(rm, 1, "1");
                gotoxy(50, 20);
                cout << "=> Check In Successful.";
                string ss = tk + " X " + days + " = " + to_string(totalRent);
                vauout << "Room rent: " << ss << endl;
                // Customer info added
                fstream vip("AllCustomerInfo.txt", ios::app);
                string s;
                bool flag = false;
                while (vip >> s)
                {
                    if (s == name)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag == false)
                    vip << name << endl;

                getch();
                system("cls");
                ProjectName();
                gotoxy(50, 9);
                cout << "=> Do you want to purchase food ?" << endl;

                gotoxy(50, 11);
                cout << " 1. Yes";
                gotoxy(50, 12);
                cout << " 2. No";

                gotoxy(50, 14);
                cout << "=> Enter your choice: ";
                int option;
                cin >> option;
                if (option == 1)
                    purchaseFood();
            }
            // cout << "Thanks for your purchasing food." << endl;
            else
            {
                gotoxy(50, 20);
                cout << "=> Something went wrong.";
            }
        }
        else if (choice == 2)
        {
            string tk = findRent(rm, 2);
            gotoxy(50, 10);
            cout << "=> Room rent per day: " << tk << endl;
            addCustomerDetails();

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
            fout << "Number of days: " << days << endl;
            fout << "Check In: " << dt << endl;

            // vauchar
            string vauname = name + "vau.txt";
            ofstream vauout;
            vauout.open(vauname.c_str());
            int totalRent = stoi(tk) * stoi(days);
            gotoxy(50, 18);
            cout << "=> Total amount to be paid: " << totalRent;
            gotoxy(50, 19);
            cout << "=> Press 'paid' to continue: ";
            string s;
            cin >> s;
            if (s == "paid")
            {
                changeStatus(rm, 2, "1");
                gotoxy(50, 20);
                cout << "=> Check In Successful.";
                string ss = tk + " X " + days + " = " + to_string(totalRent);
                vauout << "Room rent: " << ss << endl;
                // Customer info added
                ofstream vip("AllCustomerInfo.txt", ios::app);
                vip << name << endl;

                getch();
                system("cls");
                ProjectName();
                gotoxy(50, 9);
                cout << "=> Do you want to purchase food ?" << endl;

                gotoxy(50, 11);
                cout << " 1. Yes";
                gotoxy(50, 12);
                cout << " 2. No";

                gotoxy(50, 14);
                cout << "=> Enter your choice: ";
                int option;
                cin >> option;
                if (option == 1)
                    purchaseFood();
            }
            else
            {
                gotoxy(50, 20);
                cout << "=> Something went wrong.";
            }
        }
        else
        {
            cout << "=> Your have a wrong choice.";
        }
        getch();
    }
    void checkout()
    {
        system("cls");
        getchar();
        string name;
        ProjectName();
        gotoxy(50, 9);
        cout << "=> Please enter name: ";
        getline(cin, name);
        ifstream CustomerDetails(name + ".txt", ios::in);
        string line;
        int i = 0;
        if (CustomerDetails)
        {
            system("cls");
            ProjectName();
            int x = 8;
            gotoxy(50, x);
            cout << "|";
            gotoxy(50 + 43, x);
            cout << "|";
            while (getline(CustomerDetails, line))
            {
                gotoxy(50, x += 1);
                cout << "| " << line;
                gotoxy(50 + 43, x);
                cout << "|";
            }

            name = name + "vau.txt";
            ifstream Customervau(name, ios::in);
            if (Customervau)
            {
                gotoxy(50, x += 1);
                cout << "+------------------------------------------+";
                gotoxy(50, x += 1);
                cout << "| Payment history";
                gotoxy(50 + 43, x);
                cout << "|";
                while (getline(Customervau, line))
                {
                    gotoxy(50, x += 1);
                    cout << "| " << line;
                    gotoxy(50 + 43, x);
                    cout << "|";
                }
            }
            gotoxy(50, x += 1);
            cout << "+------------------------------------------+";
            gotoxy(50, x += 1);
            cout << "=> Enter your room no to confirm check out: ";
            string rmN;
            cin >> rmN;

            system("cls");
            getchar();
            // string name;
            ProjectName();
            x=9;
            gotoxy(50, x++);

            // gotoxy(50, x += 1);
            cout << "=> Enter admin secret code to confirm check out: ";
            // Admin secret code
            // Vip room =1
            // Normal room =0
            int roomtype;
            cin >> roomtype;

            changeStatus(rmN, roomtype, "0");
            gotoxy(50, x += 1);
            cout << "=> Check Out Successful.";
            // remove(s1);
            // remove(name + ".txt");
            getch();
            return;
        }
        else
        {
            gotoxy(50, 11);
            cout << "=> No data available.";
            getch();
            // CustomerDetails();
        }

        // system("cls");
        // getchar();
        // gotoxy(50, 9);
        // cout << "=> Please enter your name: ";
        // char s1[20];
        // scanf("%[^\n]%*c", &s1);
        // string unamev = s1;
        // strcat(s1, ".txt");

        // // ifstream vip("viproom.txt", ios::app);
        // // string uname = name + ".txt";
        // // fstream CustomerDetails;
        // string uname = s1;
        // ifstream CustomerDetails(uname, ios::in);

        // string line;
        // int i = 0;
        // int x = 9;
        // while (getline(CustomerDetails, line))
        // {
        //     // if(i>0)
        //     gotoxy(50, x += 1);
        //     cout << line << endl;
        //     // i++;
        // }
        // cout << "Payment history" << endl;

        // unamev = unamev + "vau.txt";

        // ifstream Customervau(unamev, ios::in);
        // while (getline(Customervau, line))
        // {
        //     // if(i>0)
        //     cout << line << endl;
        //     // i++;
        // }
        // cout << endl;

        // cout << "=> Please Enter your Room No to confirm check out: ";
        // string rmN;
        // cin >> rmN;
        // cout << "=> Please Enter admin secret code to confirm check out: ";
        // int roomtype;
        // cin >> roomtype;

        // changeStatus(rmN, roomtype, "0");

        // cout << "=> Check Out Successful." << endl;
        // remove(s1);
        // // remove(s2);
        // getch();
        // // return ;
    }

    void purchaseFood()
    {
        system("cls");
        ProjectName();
        gotoxy(50, 9);
        cout << "=> Please enter your name: ";
        string nam;
        cin >> nam;
        nam = nam + "vau.txt";
        fstream vau;
        fstream vauin;
        vau.open(nam, ios::in);
        if (!vau)
        {
            gotoxy(50, 11);
            cout << "=> External customer are not able to buy food.";
            getch();
            return;
        }
        vau.close();

        vauin.open(nam, ios::app);
        system("cls");
        ProjectName();
        gotoxy(50, 9);
        cout << "1. Bread Omelette + Banana + Water -100Tk";
        gotoxy(50, 10);
        cout << "2. Chicken Biriyani + Water -150TK";
        gotoxy(50, 11);
        cout << "3. Beef Khicuri + Water - 250Tk";
        int option;
        gotoxy(50, 12);
        cout << "=> Please enter your choice: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            gotoxy(50, 13);
            cout << "=> Amount to be paid - 100Tk";
            gotoxy(50, 14);
            cout << "=> Press 'paid' to continue: ";
            string s;
            cin >> s;
            if (s == "paid")
            {
                vauin << "Bread Omelette + Banana + Water -100Tk" << endl;
                gotoxy(50, 15);
                cout << "=> Thanks for your purchasing food.";
            }
            else
            {
                gotoxy(50, 15);
                cout << "Something went wrong." << endl;
            }
            getch();
            break;
        }
        case 2:
        {
            gotoxy(50, 13);
            cout << "=> Amount to be paid - 150Tk";
            gotoxy(50, 14);
            cout << "=> Press 'paid' to continue: ";
            string s;
            cin >> s;
            if (s == "paid")
            {
                vauin << "Chicken Biriyani + Water -150TK" << endl;
                gotoxy(50, 15);
                cout << "=> Thanks for your purchasing food.";
            }
            else
            {
                gotoxy(50, 15);
                cout << "Something went wrong." << endl;
            }
            getch();
            break;
        }
        case 3:
        {
            gotoxy(50, 13);
            cout << "=> Amount to be paid - 250Tk";
            gotoxy(50, 14);
            cout << "=> Press 'paid' to continue: ";
            string s;
            cin >> s;
            if (s == "paid")
            {
                vauin << "Beef Khicuri + Water - 250Tk" << endl;
                gotoxy(50, 15);
                cout << "=> Thanks for your purchasing food.";
            }
            else
            {
                gotoxy(50, 15);
                cout << "Something went wrong." << endl;
            }
            getch();
            break;
        }
        default:
        {
            gotoxy(50, 13);
            cout << "=> Your have a wrong choice. Press a key to try again.";
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

        ProjectName();
        gotoxy(50, 8);
        cout << "|                                          |";
        gotoxy(50, 9);
        cout << "| 1. Available room                        |";
        gotoxy(50, 10);
        cout << "|                                          |";
        gotoxy(50, 11);
        cout << "| 2. Check in                              |";
        gotoxy(50, 12);
        cout << "|                                          |";
        gotoxy(50, 13);
        cout << "| 3. Check out                             |";
        gotoxy(50, 14);
        cout << "|                                          |";
        gotoxy(50, 15);
        cout << "| 4. Purchase food                         |";
        gotoxy(50, 16);
        cout << "|                                          |";
        gotoxy(50, 17);
        cout << "| 5. Main menu                             |";
        gotoxy(50, 18);
        cout << "+------------------------------------------+";
        gotoxy(50, 19);
        cout << "=> Please enter your choice: ";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            displayAvailableRoom();
            getch();
            customermenu();
        case 2:
            checkIn();
            break;
        case 3:
            checkout();
            break;
        case 4:
            purchaseFood();
            break;
        case 5:
            return;
        default:
            cout << "Your have a wrong choice. Press a key to try again.";
            getch();
            customermenu();
        }
    }
};

void mainMenu()
{
    ProjectName();
    gotoxy(50, 8);
    cout << "|                                          |";
    gotoxy(50, 9);
    // cout << "+------------------------------------------+";
    cout << "| 1. Administrator                         |" << endl;
    gotoxy(50, 10);
    cout << "|                                          |";
    gotoxy(50, 11);
    cout << "| 2. Customer                              |" << endl;
    gotoxy(50, 12);
    cout << "|                                          |";
    gotoxy(50, 13);
    cout << "| 3. End the program                       |" << endl;
    gotoxy(50, 14);
    cout << "+------------------------------------------+";
}

void ProjectName()
{
    gotoxy(50, 5);
    cout << "+------------------------------------------+";
    gotoxy(50, 6);
    cout << "|         HOTEL MANAGEMENT SYSTEM          |";
    gotoxy(50, 7);
    cout << "+------------------------------------------+";
}
int main() 
{

    ProjectName();

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
    cout << "+------------------------------------------+";
    gotoxy(50, 17);
    cout << "=> Press any key to enter the main program. \n";
    gotoxy(50, 18);
    cout << "  ";
    getch();

    administrator admin;
    customer custom;

    int choice;
    do
    {
        system("cls");
        mainMenu();
        gotoxy(50, 15);
        cout << "=> Please enter you choice: ";
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

        ProjectName();
        gotoxy(50, 8);
        cout << "|                                          |";
        gotoxy(50, 9);
        cout << "| 1. Add room                              |";
        gotoxy(50, 10);
        cout << "|                                          |";
        gotoxy(50, 11);
        cout << "| 2. Display all room                      |";
        gotoxy(50, 12);
        cout << "|                                          |";
        gotoxy(50, 13);
        cout << "| 3. Modify room                           |";
        gotoxy(50, 14);
        cout << "|                                          |";
        gotoxy(50, 15);
        cout << "| 4. Customer details                      |";
        gotoxy(50, 16);
        cout << "|                                          |";
        gotoxy(50, 17);
        cout << "| 5. Back to main menu                     |";
        gotoxy(50, 18);
        cout << "+------------------------------------------+";
        gotoxy(50, 19);
        cout << "=>  Please enter your choice : ";

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
        {
            rm.CustomerDetails();
            break;
        }
        case 5:
            return;
            // break;
        default:
            cout << "\nPlease enter correct option.\n";
            break;
        }
    } while (option != 4);
}