#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
using namespace std;

// Global Variable
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
// Global Variable End

class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            //getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "dbms_project", 0, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            //getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};

void admin_login();
void enter_donor_data();
void enter_receiver_data();
void enter_blood_group_data();
void enter_doctor_data();
void remove_doctor_data();
void user_view();
void view_donor();
void view_receiver();
void view_doctor();
void view_bg();
void edit_items();
void edit_donor();
void edit_receiver();
void edit_doctor();
void edit_bg();
void find_items();
void find_donors();
void find_receivers();
void find_doctors();
void find_bg();

int main()
{
    // Initial Load

    system("cls");
    system("Title Blood Donation Management System");

    // Initial Load End

    // Call Methods
    db_response::ConnectionFunction();
    // Call Methods End

    // Variables
    int ch;
    char d;

    cout<<"\n Welcome to Blood Donation Management System"<<endl;
    cout<<"\n 1.Login as Admin"<<endl;
    cout<<"\n 2.View as user"<<endl;
    cout<<"\n 3.Exit"<<endl;
    cout<<"\n Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
            admin_login();
            break;
        case 2:
            user_view();
            break;
        case 3:
            cout<<"\n Are you sure you want to exit y/n: ";
            cin>>d;

            if(d=='y'||d=='Y')
            {
                system("cls");
                cout<<"Your exit process is successful"<<endl;
                exit(0);
            }

            else
                cout<<"\n enter your option carefully"<<endl;

            break;
        default:
            cout<<"\n !! Wrong option"<<endl;
            cout<<"\n Enter the options between 1-3 only"<<endl;
            break;
    }

return 0;
}

void admin_login()
{

    system("cls");
     cout<<"This is admin mode \n\n";
    int ch;
    cout<<"\n 1. Enter donor table data\n"<<endl;
    cout<<"\n 2.Enter receiver table data\n"<<endl;
    cout<<"\n 3.Enter blood group table data\n"<<endl;
    cout<<"\n 4.Enter doctor table data\n"<<endl;
    cout<<"\n 5.Remove doctor table data\n"<<endl;
    cout<<"\n 6.Edit any item\n"<<endl;
    cout<<"\n 7.Find Items \n"<<endl;
    cout<<"\n 8.Exit admin mode"<<endl;
    cout<<"\n Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
                enter_donor_data();
                break;
        case 2:
                enter_receiver_data();
                break;
        case 3:
                enter_blood_group_data();
                break;
        case 4:
                enter_doctor_data();
                break;
        case 5:
                remove_doctor_data();
                break;
        case 6:
                edit_items();
                break;
        case 7:
                find_items();
                break;
        case 8:
                system("cls");
                main();
                break;
        default:
                cout<<"\n !!Wrong choice"<<endl;
                cout<<"\n !!Enter from 1-5 only"<<endl;
                admin_login();
                break;
    }
}

void enter_donor_data()
{
    system("cls");
    char ch;
    string name="";
    string address="";
    string contact="";
    int blood_group_id;
    int doctor_id;
    int qty;

    cout<<"\n Enter the donor details"<<endl;

    cin.ignore(1,'\n');
    cout<<"\n Enter the donor name: ";
    getline(cin,name);
    cout<<"\n Enter the donor address: ";
    getline(cin,address);
    cout<<"\n Enter the donor 10 digit contact: ";
    getline(cin,contact);

    cout<<"\n Enter the blood group id: ";
    cin>>blood_group_id;
    cout<<"\n Enter the doctor id: ";
    cin>>doctor_id;
    cout<<"\n Enter the quantity of blood donated(in mL): ";
    cin>>qty;

    stringstream streambg_id,streamd_id,streamqty;
    string sbg_id,sd_id,sqty;

    streambg_id << blood_group_id;
    streambg_id >> sbg_id;

    streamd_id << doctor_id;
    streamd_id >> sd_id;

    streamqty << qty;
    streamqty >> sqty;


    string insert_query = "insert into donor_tb(name,address,contact,blood_group_id,doctor_id,qty) values('"+name+"','"+address+"','"+contact+"','"+sbg_id+"','"+sd_id+"','"+sqty+"')";

    const char* q= insert_query.c_str();
    qstate= mysql_query(conn,q);

    if(!qstate)
        cout<<"\n Data added in table";
    else
        cout<<"\n execution error "<<mysql_errno(conn)<<endl;


    cout<<"\n Do you want to add more donor details y/n: "<<endl;
    cin>>ch;

    if(ch=='y'||ch=='Y')
        enter_donor_data();
    else
    {
        cout<<"\n Exiting the page!";
        admin_login();
    }
}

void enter_receiver_data()
{
    system("cls");
     char ch;
    int receiver_id;
    string name="";
    string address="";
    string contact="";
    int blood_group_id;
    int doctor_id;
    int qty;

    cout<<"\n Enter the receiver details"<<endl;

    cin.ignore(1,'\n');
    cout<<"\n Enter the receiver name: ";
    getline(cin,name);
    cout<<"\n Enter the receiver address: ";
    getline(cin,address);
    cout<<"\n Enter the receiver 10-digit contact: ";
    getline(cin,contact);

    cout<<"\n Enter the blood group id: ";
    cin>>blood_group_id;
    cout<<"\n Enter the doctor id: ";
    cin>>doctor_id;
    cout<<"\n Enter the quantity of blood received(in mL): ";
    cin>>qty;

    stringstream streambg_id,streamd_id,streamqty;
    string sbg_id,sd_id,sqty;

    streambg_id << blood_group_id;
    streambg_id >> sbg_id;

    streamd_id << doctor_id;
    streamd_id >> sd_id;

    streamqty << qty;
    streamqty >> sqty;

    string insert_query = "insert into receiver_tb(name,address,contact,blood_group_id,doctor_id,qty) values('"+name+"','"+address+"','"+contact+"','"+sbg_id+"','"+sd_id+"','"+sqty+"')";

    const char* q= insert_query.c_str();
    qstate= mysql_query(conn,q);

    if(!qstate)
        cout<<"\n Data added in table";
    else
        cout<<"\n execution error "<<mysql_errno(conn)<<endl;


    cout<<"\n Do you want to add more receiver details y/n: "<<endl;
    cin>>ch;

    if(ch=='y'||ch=='Y')
        enter_receiver_data();
    else
    {
        cout<<"\n Exiting the page"<<endl;
        admin_login();
    }
}

void enter_blood_group_data()
{
    system("cls");
    char ch;

    string blood_group_name="";
    int qty;

    cout<<"\n Enter the blood group details"<<endl;

    cin.ignore(1,'\n');
    cout<<"\n Enter the blood group name: ";
    getline(cin,blood_group_name);

    cout<<"\n Enter the amount of blood of particular blood group present(in mL): ";
    cin>>qty;

    stringstream streamqty;
    string sqty;

    streamqty << qty;
    streamqty >> sqty;

    string insert_query="insert into blood_group_tb(blood_group_name,qty) values('"+blood_group_name+"','"+sqty+"')";
    const char* q = insert_query.c_str();

    qstate=mysql_query(conn,q);

    if(!qstate)
        cout<<"\n Data added in the table"<<endl;
    else
        cout<<"\n execution error "<<mysql_errno(conn)<<endl;

    cout<<"\n Do you want to add more details y/n: ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        enter_blood_group_data();
    else
    {
        cout<<"\n Exiting the page!!";
        admin_login();
    }
}

void enter_doctor_data()
{
    system("cls");
    char ch;

    string name="";
    string address="";
    string contact="";

    cout<<"\n Enter the doctor details"<<endl;

    cin.ignore(1,'\n');
    cout<<"\n Enter the name of the doctor: ";
    getline(cin,name);
    cout<<"\n Enter the address: ";
    getline(cin,address);
    cout<<"\n Enter the 10-digit contact-no.  of doctor: ";
    getline(cin,contact);


    string insert_query= "insert into doctor_tb(name,address,contact) values ('"+name+"','"+address+"','"+contact+"')";
    const char* q = insert_query.c_str();

    qstate = mysql_query(conn, q);

    if (!qstate)
        cout << "Data added in table" << endl;
    else
        cout <<"Execution error" << mysql_errno(conn) << endl;

    cout<<"\n Do you want to add more details y/n:";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        enter_doctor_data();
    else
        {
            cout<<"\n Exiting the page!!";
            admin_login();
        }
}

void remove_doctor_data()
{
    system("cls");
    char ch;
    int docid,index=0;
    string docarray[25];
    bool Has_exception,In_dataBase;
    system("cls");
    cout<<"Removing doctor data from the database\n\n"<<endl;

    // extracting all the doctor_id's present in database in an array

      qstate= mysql_query(conn,"select doctor_id from doctor_tb");
        if(!qstate)
        {
             res = mysql_store_result(conn);
            cout << "Doctor_ID\n " << endl;
            while ((row = mysql_fetch_row(res)))
            {
                cout << row[0] << endl;
                docarray[index] = row[0];
                index++;
            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }



    try
    {
        cout<<"\n Enter the doctor id for deletion:  "<<endl;
        cin>>docid;
        cout<<endl;
    }
    catch(exception e)
    {
        cout<<"\n Enter a valid number"<<endl;
        Has_exception=true;

        cout<<"\n Exiting this page!! \n"<<endl;
        admin_login();
    }

    if(Has_exception==false)
    {
        stringstream doctorid;
        string d_id;

        doctorid << docid;
        doctorid >> d_id;

        for(int i=0;i<index;i++)
        {
            if(d_id==docarray[i])
                In_dataBase=true;
            else
                In_dataBase=false;
        }

        if(In_dataBase==false)
        {
            cout<<"\n Item not present in doctor table\n Exiting the page "<<endl;
            admin_login();
        }
        else
        {
            string query= "delete from doctor_tb where doctor_id = '"+d_id+"'";
            const char* q = query.c_str();
            qstate=mysql_query(conn,q);

            if(!qstate)
                cout<<"\n Deleted from Database"<<endl;
            else
                cout<<"Query execution failure "<<mysql_errno(conn)<<endl;
        }
    }

    cout<<"\n Want to perform more deletion operations y/n: ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        remove_doctor_data();
    else
    {
        cout<<"\nExiting Page!!"<<endl;
        admin_login();
    }
}
void edit_items()
{
    system("cls");

    int ch;
    cout<<"\n 1.Edit from donor table"<<endl;
    cout<<"\n 2.Edit from receiver table"<<endl;
    cout<<"\n 3.Edit from blood group table"<<endl;
    cout<<"\n 4.Edit from doctor table"<<endl;
    cout<<"\n 5.Exit "<<endl;

    cout<<" Choose the table to edit \t Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
                edit_donor();
                break;
        case 2:
                edit_receiver();
                break;
        case 3:
                edit_bg();
                break;
        case 4:
                edit_doctor();
                break;
        case 5:
                admin_login();
                break;
        default:
                cout<<"\n Wrong choice!!"<<endl;
                cout<<"\n Enter options only from 1-5"<<endl;
    }
}


void edit_donor()
{
    system("cls");

    // Variables
    string name = "";
    string address = "";
    string contact = "";
    string bg_id = "";
    string doc_id = "";
    string quantity = "";

    string donors[100];
    char ch;
    int donorId;
    bool Has_exception = false,NotInDatabase = false;
    int index = 0;

    // s Variables
    string sid = "";
    string sname = "";
    string saddress = "";
    string scontact = "";
    string sbg_id = "";
    string sdoc_id = "";
    string squantity = "";
    // Variables End

    cout << "Edit Donors Menu" << endl << endl;

    qstate = mysql_query(conn, "select donor_id from donor_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "ID\n" << endl;
        while ((row = mysql_fetch_row(res)))
        {
            cout << row[0] << endl;
            donors[index] = row[0];
            index++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Donor ID: ";
        cin >> donorId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        Has_exception = true;
    }

    if (Has_exception == false)
    {
        stringstream streamid;
        string strid;
        streamid << donorId;
        streamid >> strid;

        for (int i = 0; i < index; i++)
        {
            if (strid != donors[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from donor_tb where donor_id = '"+strid+"'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                cout << endl;
                while ((row = mysql_fetch_row(res)))
                {
                    cout << "Donor ID: " << row[0] << "\nName: " << row[1] << "\nAddress: " << row[2] << "\nContact: " << row[3] << "\nBlood Group Id: " << row[4] << "\nDoctor ID: " << row[5] << "\nQuantity: " << row[6] << endl << endl;
                    sid = row[0];
                    sname = row[1];
                    saddress = row[2];
                    scontact = row[3];
                    sbg_id = row[4];
                    sdoc_id = row[5];
                    squantity = row[6];
                }
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            cin.ignore(1, '\n');
            cout << "Enter name (no to not change): ";
            getline(cin, name);
            if (name == "no")
            {
                name = sname;
            }
            cout << "Enter address (no to not change): ";
            getline(cin, address);
            if (address == "no")
            {
                address = saddress;
            }
            cout << "Enter contact (no to not change): ";
            getline(cin, contact);
            if (contact == "no")
            {
                contact = scontact;
            }
            cout << "Enter Blood Group Id (no to not change): ";
            getline(cin, bg_id);
            if (bg_id == "no")
            {
                bg_id = sbg_id;
            }
            cout << "Enter doctor ID (no to not change): ";
            cin >> doc_id;
            if (doc_id == "no")
            {
                doc_id = sdoc_id;
            }
            cout << "Enter Quantity (no to not change): ";
            cin >> quantity;
            if (quantity == "no")
            {
                quantity = squantity;
            }

            string update_query = "update donor_tb set name = '"+name+"', address = '"+address+"', contact = '"+contact+"', blood_group_id = '"+bg_id+"', doctor_id = '"+doc_id+"', qty = '"+quantity+"' where donor_id = '"+strid+"'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "Successfully Saved In Database." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    cout<<"\n Want to perform more edit operations y/n: ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        edit_items();
    else
    {
        cout<<"\nExiting Page!!"<<endl;
        admin_login();
    }
}

void edit_receiver()
{
    system("cls");

    // Variables
    string name = "";
    string address = "";
    string contact = "";
    string bg_id = "";
    string doc_id = "";
    string quantity = "";

    string receivers[100];
    char ch;
    int receiverId;
    bool Has_exception = false,NotInDatabase = false;
    int index = 0;

    // s Variables
    string sid = "";
    string sname = "";
    string saddress = "";
    string scontact = "";
    string sbg_id = "";
    string sdoc_id = "";
    string squantity = "";
    // Variables End

    cout << "Edit receivers Menu" << endl << endl;

    qstate = mysql_query(conn, "select receiver_id from receiver_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "ID\n" << endl;
        while ((row = mysql_fetch_row(res)))
        {
            cout << row[0] << endl;
            receivers[index] = row[0];
            index++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Receiver ID: ";
        cin >> receiverId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        Has_exception = true;
    }

    if (Has_exception == false)
    {
        stringstream streamid;
        string strid;
        streamid << receiverId;
        streamid >> strid;

        for (int i = 0; i < index; i++)
        {
            if (strid != receivers[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from receiver_tb where receiver_id = '"+strid+"'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                cout << endl;
                while ((row = mysql_fetch_row(res)))
                {
                    cout << "Receiver ID: " << row[0] << "\nName: " << row[1] << "\nAddress: " << row[2] << "\nContact: " << row[3] << "\nBlood Group Id: " << row[4] << "\nDoctor ID: " << row[5] << "\nQuantity: " << row[6] << endl << endl;
                    sid = row[0];
                    sname = row[1];
                    saddress = row[2];
                    scontact = row[3];
                    sbg_id = row[4];
                    sdoc_id = row[5];
                    squantity = row[6];
                }
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            cin.ignore(1, '\n');
            cout << "Enter name (no to not change): ";
            getline(cin, name);
            if (name == "no")
            {
                name = sname;
            }
            cout << "Enter address (no to not change): ";
            getline(cin, address);
            if (address == "no")
            {
                address = saddress;
            }
            cout << "Enter contact (no to not change): ";
            getline(cin, contact);
            if (contact == "no")
            {
                contact = scontact;
            }
            cout << "Enter Blood Group Id (no to not change): ";
            getline(cin, bg_id);
            if (bg_id == "no")
            {
                bg_id = sbg_id;
            }
            cout << "Enter doctor ID (no to not change): ";
            cin >> doc_id;
            if (doc_id == "no")
            {
                doc_id = sdoc_id;
            }
            cout << "Enter Quantity (no to not change): ";
            cin >> quantity;
            if (quantity == "no")
            {
                quantity = squantity;
            }

            string update_query = "update receiver_tb set name = '"+name+"', address = '"+address+"', contact = '"+contact+"', blood_group_id = '"+bg_id+"', doctor_id = '"+doc_id+"', qty = '"+quantity+"' where receiver_id = '"+strid+"'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "Successfully Saved In Database." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    cout<<"\n Want to perform more edit operations y/n: ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        edit_items();
    else
    {
        cout<<"\nExiting Page!!"<<endl;
        admin_login();
    }
}

void edit_doctor()
{
    system("cls");

    // Variables
    string name = "";
    string address = "";
    string contact = "";


    string doctors[100];
    char ch;
    int doctorId;
    bool Has_exception = false,NotInDatabase = false;
    int index = 0;

    // s Variables
    string sid = "";
    string sname = "";
    string saddress = "";
    string scontact = "";
    // Variables End

    cout << "Edit Doctor Menu" << endl << endl;

    qstate = mysql_query(conn, "select doctor_id from doctor_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "ID\n" << endl;
        while ((row = mysql_fetch_row(res)))
        {
            cout << row[0] << endl;
            doctors[index] = row[0];
            index++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Doctor ID: ";
        cin >> doctorId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        Has_exception = true;
    }

    if (Has_exception == false)
    {
        stringstream streamid;
        string strid;
        streamid << doctorId;
        streamid >> strid;

        for (int i = 0; i < index; i++)
        {
            if (strid != doctors[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from doctor_tb where doctor_id = '"+strid+"'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                cout << endl;
                while ((row = mysql_fetch_row(res)))
                {
                    cout << "Doctor ID: " << row[0] << "\nName: " << row[1] << "\nAddress: " << row[2] << "\nContact: " << row[3] << endl << endl;
                    sid = row[0];
                    sname = row[1];
                    saddress = row[2];
                    scontact = row[3];
                }
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            cin.ignore(1, '\n');
            cout << "Enter name (no to not change): ";
            getline(cin, name);
            if (name == "no")
            {
                name = sname;
            }
            cout << "Enter address (no to not change): ";
            getline(cin, address);
            if (address == "no")
            {
                address = saddress;
            }
            cout << "Enter contact (no to not change): ";
            getline(cin, contact);
            if (contact == "no")
            {
                contact = scontact;
            }

            string update_query = "update doctor_tb set name = '"+name+"', address = '"+address+"', contact = '"+contact+"' where doctor_id = '"+strid+"'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "Successfully Saved In Database." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    cout<<"\n Want to perform more edit operations y/n: ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        edit_items();
    else
    {
        cout<<"\nExiting Page!!"<<endl;
        admin_login();
    }
}

void edit_bg()
{
    system("cls");

    // Variables
    string name = "";
    string quantity = "";

    string bg[100];
    char ch;
    int bgId;
    bool Has_exception = false,NotInDatabase = false;
    int index = 0;

    // s Variables
    string sid = "";
    string sname = "";
    string squantity = "";
    // Variables End

    cout << "Edit Blood_Group Menu" << endl << endl;

    qstate = mysql_query(conn, "select blood_group_id from blood_group_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "ID\n" << endl;
        while ((row = mysql_fetch_row(res)))
        {
            cout << row[0] << endl;
            bg[index] = row[0];
            index++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Blood_Group ID: ";
        cin >> bgId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        Has_exception = true;
    }

    if (Has_exception == false)
    {
        stringstream streamid;
        string strid;
        streamid << bgId;
        streamid >> strid;

        for (int i = 0; i < index; i++)
        {
            if (strid != bg[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from blood_group_tb where blood_group_id = '"+strid+"'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                cout << endl;
                while ((row = mysql_fetch_row(res)))
                {
                    cout << "Blood Group ID: " << row[0] << "\nGroup Name: " << row[1] << "\nQuantity: " << row[2] << endl << endl;
                    sid = row[0];
                    sname = row[1];
                    squantity = row[2];
                }
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            cin.ignore(1, '\n');
            cout << "Enter blood group name (no to not change): ";
            getline(cin, name);
            if (name == "no")
            {
                name = sname;
            }
            cout << "Enter Quantity (no to not change): ";
            cin >> quantity;
            if (quantity == "no")
            {
                quantity = squantity;
            }

            string update_query = "update blood_group_tb set blood_group_name = '"+name+"', qty = '"+quantity+"' where blood_group_id = '"+strid+"'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "Successfully Saved In Database." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    cout<<"\n Want to perform more edit operations y/n: ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        edit_donor();
    else
    {
        cout<<"\nExiting Page!!"<<endl;
        admin_login();
    }

}

void user_view()
{
    system("cls");
    cout<<"\t\t This is user mode \n\n"<<endl;

    int ch;
    char choice;
    cout<<"\n 1.View donor data "<<endl;
    cout<<"\n 2.View receiver data"<<endl;
    cout<<"\n 3.View doctor table data"<<endl;
    cout<<"\n 4.View blood_group table data"<<endl;
    cout<<"\n 5.View filtered data"<<endl;
    cout<<"\n 6.Exit user mode"<<endl;
    cout<<"\n Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
                view_donor();
                break;
        case 2:
                view_receiver();
                break;
        case 3:
                view_doctor();
                break;
        case 4:
                view_bg();
                break;
        case 5:
                find_items();
                break;
        case 6:
                system("cls");
                main();
                break;
        default:
                cout<<"\n !!!Invalid entry "<<endl;
                cout<<"\n Enter option only from 1-5"<<endl;
                user_view();
                break;
    }
    cout<<"\n Want to view more data y/n: ";
    cin>>choice;

    if(choice=='y'||choice=='Y')
        user_view();
    else
    {
        cout<<"\nExiting Page!!"<<endl;
        main();
    }
}

void view_donor()
{
    char ch;
    system("cls");
    cout<<"\n Following is the donor data"<<endl;

    qstate = mysql_query(conn, "select * from donor_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "Donor_id : " << row[0] << "\nName : " << row[1] << "\nAddress  : " << row[2] << "\nContact : " << row[3] << "\nBlood_Group ID : " << row[4] << "\nDoctor id: " << row[5] <<"\n Qty of Blood Donated(in ml): "<<row[6]<<endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    cout<<"\n want to view more data? y/n: ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        user_view();
    else
    {
        cout<<"\nExiting Page!!"<<endl;
        main();
    }

}

void view_receiver()
{
    system("cls");
    char ch;
    cout<<"\n Following is the receiver data"<<endl;

    qstate = mysql_query(conn, "select * from receiver_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "Receiver_id : " << row[0] << "\nName : " << row[1] << "\nAddress  : " << row[2] << "\nContact : " << row[3] << "\nBlood_Group ID : " << row[4] << "\nDoctor id: " << row[5] <<"\n Qty of Blood Received(in ml): "<<row[6]<<endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    cout<<"\n want to view more data? y /n: ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        user_view();
    else
    {
        cout<<"\nExiting Page!!"<<endl;
        main();
    }
}

void view_doctor()
{
    system("cls");
    char ch;
    cout<<"\n Following is the doctor data"<<endl;

    qstate = mysql_query(conn, "select * from doctor_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "Doctor_id : " << row[0] << "\nName : " << row[1] << "\nAddress : " << row[2] << "\nContact  : " << row[3]<<endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
     cout<<"\n want to view more data? y /n: ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        user_view();
    else
    {
        cout<<"\nExiting Page!!"<<endl;
        main();
    }
}

void view_bg()
{
    system("cls");
    char ch;
    cout<<"\n Following is the blood group table data"<<endl;

    qstate = mysql_query(conn, "select * from blood_group_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "Blood_Group_id : " << row[0] << "\nBlood_Group Name : " << row[1] << "\nQuantity : " << row[2]  << endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

     cout<<"\n want to view more data? y /n: ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        user_view();
    else
    {
        cout<<"\nExiting Page!!"<<endl;
        main();
    }

}

void find_items()
{
    system("cls");
    int ch;
    char choice;
    cout<<"\n 1.Find from donors table\n";
    cout<<"\n 2.Find from receivers table\n";
    cout<<"\n 3.Find from blood group table\n";
    cout<<"\n 4.Find from doctors table\n";
    cout<<"\n 5.Exit from the page \n";

    cout<<"Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
                find_donors();
                break;
        case 2:
                find_receivers();
                break;
        case 3:
                find_bg();
                break;
        case 4:
                find_doctors();
                break;
        case 5:
                cout<<"\n ! exiting the page...."<<endl;
                admin_login();
                break;
    }

    cout<<"\n Want to find more data y/n: ";
    cin>>choice;
        if(choice=='y')
        {
            find_items();
        }
        else
        {
            cout<<"\n Exiting page!!"<<endl;
            admin_login();
        }

}
void find_donors()
{
    system("cls");

    int ch;
    string input;
    char choice;

        cout<<"\n Donors menu \n\n"<<endl;
        cin.ignore(1,'\n');

        cout<<"\n1.By donor_id \n2.By name \n3.By address \n4.By contact \n5.By Blood_group_id \n6.By Doctor ID \n7.By quantity"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                {

                        cin.ignore(1,'\n');
                        cout << "Enter donor_id: ";
                        getline(cin, input);
                        string findbydonid_query = "select * from donor_tb where donor_id like '"+input+"%'";
                        const char* q = findbydonid_query.c_str();
                        qstate = mysql_query(conn, q);
                        break;
                }

            case 2:
                    {
                        cin.ignore(1,'\n');
                       cout << "Enter Name: ";
                        getline(cin, input);
                        string findbyname_query = "select * from donor_tb where name like '"+input+"%'";
                        const char* q1 = findbyname_query.c_str();
                        qstate = mysql_query(conn, q1);
                        break;
                    }

            case 3:
                    {
                        cin.ignore(1,'\n');
                        cout<<"\n Enter address: ";
                        getline(cin,input);
                        string findbyadd_query="select * from donor_tb where address like '"+input+"%'";
                        const char* q2 = findbyadd_query.c_str();
                        qstate = mysql_query(conn, q2);
                        break;
                    }

            case 4:
                {
                        cin.ignore(1,'\n');
                        cout<<"\n Enter contact: ";
                        getline(cin,input);
                        string findbycontact_query="select * from donor_tb where contact like '"+input+"%'";
                        const char* q3 = findbycontact_query.c_str();
                        qstate = mysql_query(conn, q3);
                        break;
                }

            case 5:
                {
                        cin.ignore(1,'\n');
                        cout<<"\n Enter blood_group_id: ";
                        getline(cin,input);
                        string findbybgid_query="select * from donor_tb where blood_group_id like '"+input+"%'";
                        const char* q4 = findbybgid_query.c_str();
                        qstate = mysql_query(conn, q4);
                        break;
                }
            case 6:
                {
                        cin.ignore(1,'\n');
                        cout<<"\n Enter doctor_id: ";
                        getline(cin,input);
                        string findbydid_query="select * from donor_tb where doctor_id like '"+input+"%'";
                        const char* q5 = findbydid_query.c_str();
                        qstate = mysql_query(conn, q5);
                        break;
                }
            case 7:
                {
                        cin.ignore(1,'\n');
                        cout<<"\n Enter quantity: ";
                        getline(cin,input);
                        string findbyqty_query="select * from donor_tb where qty like '"+input+"%'";
                        const char* q6 = findbyqty_query.c_str();
                        qstate = mysql_query(conn, q6);
                        break;
                }
            default:
                        cout<<"\n Enter the correct option ";
                        break;
        }
                 cout << endl;
    if (ch == 1 || ch == 2 || ch == 3 || ch == 4||ch==5||ch==6||ch==7)
    {
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
                cout << "Donor_ID: " << row[0] << "\nName: " << row[1] << "\nAddress: " << row[2] << "\nContact:" <<row[3]<<"\n Blood_Group ID: "<<row[4]<<"\n Doctor_ID: "<<row[5]<<"\n Quantity Donated: "<<row[6]<< endl << endl;
            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    cout<<"\n Want to find more donor data y/n: ";
    cin>>choice;
        if(choice=='y')
        {
            find_donors();
        }
        else
        {
            cout<<"\n Exiting page!!"<<endl;
            find_items();
        }

}

void find_receivers()
{
    system("cls");

    int ch;
    string input;
    char choice;

        cout<<"\n receivers menu \n\n"<<endl;
        cin.ignore(1,'\n');

        cout<<"\n1.By receiver_id \n2.By Name \n3.By address \n4.By contact \n5.By Blood_group_id \n6.By Doctor ID \n7.By quantity"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                {
                        cin.ignore(1,'\n');
                        cout << "Enter receiver_id: ";
                        getline(cin, input);
                        string findbyrid_query = "select * from receiver_tb where receiver_id like '"+input+"%'";
                        const char* q = findbyrid_query.c_str();
                        qstate = mysql_query(conn, q);
                        break;
                }
            case 2:
                {
                        cin.ignore(1,'\n');
                        cout << "Enter Name: ";
                        getline(cin, input);
                        string findbyname_query = "select * from receiver_tb where name like '"+input+"%'";
                        const char* q1 = findbyname_query.c_str();
                        qstate = mysql_query(conn, q1);
                        break;

                }

            case 3:
                {
                        cin.ignore(1,'\n');
                        cout<<"\n Enter address: ";
                        getline(cin,input);
                        string findbyadd_query="select * from receiver_tb where address like '"+input+"%'";
                        const char* q2 = findbyadd_query.c_str();
                        qstate = mysql_query(conn, q2);
                        break;
                }
            case 4:
                {
                        cin.ignore(1,'\n');
                        cout<<"\n Enter contact: ";
                        getline(cin,input);
                        string findbycon_query="select * from receiver_tb where contact like '"+input+"%'";
                        const char* q3 = findbycon_query.c_str();
                        qstate = mysql_query(conn, q3);
                        break;
                }


            case 5:
                {
                        cin.ignore(1,'\n');
                        cout<<"\n Enter blood_group_id: ";
                        getline(cin,input);
                        string findbybgid_query="select * from receiver_tb where blood_group_id like '"+input+"%'";
                        const char* q4 = findbybgid_query.c_str();
                        qstate = mysql_query(conn, q4);
                        break;
                }

            case 6:
                {
                        cin.ignore(1,'\n');
                        cout<<"\n Enter doctor_id: ";
                        getline(cin,input);
                        string findbydid_query="select * from receiver_tb where doctor_id like '"+input+"%'";
                        const char* q5 = findbydid_query.c_str();
                        qstate = mysql_query(conn, q5);
                        break;
                }
            case 7:
                {
                        cin.ignore(1,'\n');
                        cout<<"\n Enter quantity: ";
                        getline(cin,input);
                        string findbyqty_query="select * from receiver_tb where qty like '"+input+"%'";
                        const char* q6 = findbyqty_query.c_str();
                        qstate = mysql_query(conn, q6);
                        break;

                }
            default:
                        cout<<"\n Enter the correct option ";
                        break;
        }
             cout << endl;
    if (ch == 1 || ch == 2 || ch == 3 || ch == 4||ch==5||ch==6||ch==7)
    {
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
                cout << "Receiver_ID: " << row[0] << "\nName: " << row[1] << "\nAddress: " << row[2] << "\nContact:" <<row[3]<<"\n Blood_Group ID: "<<row[4]<<"\n Doctor_ID: "<<row[5]<<"\n Quantity Donated: "<<row[6]<< endl << endl;
            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    cout<<"\n Want to find more receiver data y/n: ";
    cin>>choice;
        if(choice=='y')
        {
            find_receivers();
        }
        else
        {
            cout<<"\n Exiting page!!"<<endl;
            find_items();
        }
}

void find_bg()
{
    system("cls");

    int ch;
    string input;
    char choice;

    cin.ignore(1,'\n');

    cout<<"\n Blood Group Menu\n\n";
    cout<<"\n 1.By Blood_group ID \n2.By Blood group name \n3.By quantity"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
            {
                    cin.ignore(1,'\n');
                 cout << "Enter Blood group ID: ";
                    getline(cin, input);
                    string findbybgid_query = "select * from blood_group_tb where blood_group_id like '"+input+"%'";
                    const char* q = findbybgid_query.c_str();
                    qstate = mysql_query(conn, q);
                    break;

            }
        case 2:
            {
                cin.ignore(1,'\n');
                cout << "Enter Name: ";
                    getline(cin, input);
                    string findbyname_query = "select * from blood_group_tb where blood_group_name like '"+input+"%'";
                    const char* q1 = findbyname_query.c_str();
                    qstate = mysql_query(conn, q1);
                    break;
            }
        case 3:
            {
                cin.ignore(1,'\n');
                cout << "Enter Quantity: ";
                    getline(cin, input);
                    string findbyqty_query = "select * from blood_group_tb where qty like '"+input+"%'";
                    const char* q2 = findbyqty_query.c_str();
                    qstate = mysql_query(conn, q2);
                    break;

            }
        default:
                    cout<<"\n !!!Wrong option!!"<<endl;
                    cout<<"\n Enter only from 1-3"<<endl;
                    break;
    }

         cout << endl;
    if (ch == 1 || ch == 2 || ch == 3 )
    {
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
                cout << "Blood_Group_ID: " << row[0] << "\nGroup Name: " << row[1] << "\nQuantity: " << row[2] << endl << endl;
            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    cout<<"\n Want to find more blood_group data y/n: ";
    cin>>choice;
        if(choice=='y')
        {
            find_bg();
        }
        else
        {
            cout<<"\n Exiting page!!"<<endl;
            find_items();
        }
}

void find_doctors()
{
    system("cls");

    int ch;
    string input;
    char choice;

        cin.ignore(1,'\n');
        cout<<"\n Doctors menu \n\n"<<endl;

        cout<<"\n1.By doctor_id \n2.By Name \n3.By address \n4.By contact "<<endl;
        cout<<"\n Enter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                {
                         cin.ignore(1,'\n');
                        cout << "Enter doctor_id: ";
                        getline(cin, input);
                        string findbydid_query = "select * from doctor_tb where doctor_id like '"+input+"%'";
                        const char* q = findbydid_query.c_str();
                        qstate = mysql_query(conn, q);
                        break;
                }
            case 2:
                {
                         cin.ignore(1,'\n');
                        cout << "Enter Name: ";
                        getline(cin, input);
                        string findbyname_query = "select * from doctor_tb where name like '"+input+"%'";
                        const char* q1 = findbyname_query.c_str();
                        qstate = mysql_query(conn, q1);
                        break;
                }
            case 3:
                {
                         cin.ignore(1,'\n');
                    cout<<"\n Enter address: ";
                        getline(cin,input);
                        string findbyadd_query="select * from doctor_tb where address like '"+input+"%'";
                        const char* q2 = findbyadd_query.c_str();
                        qstate = mysql_query(conn, q2);
                        break;
                }
            case 4:
                {
                     cin.ignore(1,'\n');
                    cout<<"\n Enter contact: ";
                        getline(cin,input);
                        string findbycon_query="select * from doctor_tb where contact like '"+input+"%'";
                        const char* q3 = findbycon_query.c_str();
                        qstate = mysql_query(conn, q3);
                        break;
                }
            default:
                        cout<<"\n Enter the correct option ";
                        break;
        }

         cout << endl;
    if (ch == 1 || ch == 2 || ch == 3 || ch == 4)
    {
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
                cout << "Doctor_ID: " << row[0] << "\nName: " << row[1] << "\nAddress: " << row[2] <<"\n Contact: "<<row[3]<< endl << endl;
            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    cout<<"\n Want to find more doctor data y/n: ";
    cin>>choice;
        if(choice=='y')
        {
            find_doctors();
        }
        else
        {
            cout<<"\n Exiting page!!"<<endl;
            find_items();
        }
}



