#include<iostream>
#include<string>
using namespace std ;

class info //parent class
{
private:
    string name ;
    int phone_num ;
    int age ;
    string gender ;
    int id ;
public :
    info() //constructor and data initialization
    {
    name="sameh elisha";
    phone_num=012;
    age=19;
    gender="male";
    id=0;
    }
//Abstraction : is a process of providing only the essential details to the outside world and hiding the internal details
    virtual void start(void)=0;
 //function overriding If derived class defines same function as defined in its base class
virtual void display(int i)
    {
    cout<<"Patient information"<<endl;
    }
    string add_name()
    {
    cout<<"Enter name : ";
    cin.ignore(100, '\n');
    getline(cin, name);
     return name ;
    }

//encapsulation(The meaning of Encapsulation, is to make declare class variables as private. If you want others to read or modify the value of a private member, you can provide public get and set methods.)


 //encapsulation
 void set_phonenum(int x)
    {
        phone_num=x ;
    }
    int get_phonenum()
    {
        return phone_num;
    }
    int add_age()
    {
     cout<<"Enter age : ";
     cin>>age ;
     return age ;
    }
     string add_gender()
    {
     cout<<"Enter gender : " ;
     cin>>gender;
     return gender ;
    }
};

//inheritance : In C++, it is possible to inherit attributes and methods from one class to another
class patient : public info
{
string reservation[5]={"2pm to 2:30pm" ,"2:30pm to 3pm","3pm to 3:30pm","4pm to 4:30pm","4:30pm to 5pm"};
static int c;
public :
    struct database
    {
    string name ;
    int phone_num ;
    int age ;
    string gender ;
    int id ;
    string reserve ;
    };

    database patient[50];
    void add_patient()
    {   int x;
        patient[c].name = add_name();
        patient[c].age=add_age();
        cout<<"Enter Phone's number :";
        cin>>x;
        set_phonenum(x);
        patient[c].phone_num=get_phonenum();
        patient[c].gender=add_gender();
        patient[c].id=c;
        cout<<"ID :"<<c<<endl;
        c++;
            }


    void display() //function overloading : If we create two or more members having the same name but different in number or type of parameter
    {
    for(int j=0 ; j<c ;j++ )
       {
       display(j);
       cout<<"-----------------"<<endl;
       }
    }
    void edit_record()
    {
        int test,cho ;
        cout<<"Enter Id :";
        cin>>test;
        int range=0 ;

        for (int i = 0 ; i<=c ; i++)
        {
            if (test==patient[i].id)
            {   range++;
                cout<<"\n1-To edit Name .\n2-To edit age .\n3-To edit phone's number .\n4-To edit Gender .\nEnter Your choice:";
                cin>>cho;
            if(cho==1)
            {

                patient[i].name = add_name();
                cout<<"####Success####"<<endl;
            }
            else if (cho==2)
            {
                patient[i].age=add_age();
                cout<<"####Success####"<<endl;

            }
            else if (cho==3)
            { int x;
            cout<<"Enter Phone's number :";
            cin>>x;
            set_phonenum(x);
            patient[c].phone_num=get_phonenum();
                cout<<"####Success####"<<endl;
            }
            else if (cho==4)
            {
                patient[i].gender=add_gender();
                cout<<"####Success####"<<endl;
            }
            else
                cout<<"Wrong answer"<<endl;
            break;
            }
            if (range >0 )
            break;
            }
             if (range==0)
            {
                cout<<"ID Not Found";
            }
    }
    void select_reservation()
    {
        int test,cho ;
        cout<<"Enter Id :";
        cin>>test;
        int range=0 ;

        for (int i = 0 ; i<=c ; i++)
        {
            if (test==patient[i].id)
            {   range++;
                cout<<"Name :"<<patient[i].name<<endl;
                cout<<"Age :"<<patient[i].age<<endl;
                cout<<"Phone's number :"<<patient[c].phone_num<<endl;
                cout<<"Gender :"<< patient[i].gender<<endl;
                cout<<"Available appointments"<<endl;
                cout<<"1-  "<<reservation[0]<<endl;
                cout<<"2-  "<<reservation[1]<<endl;
                cout<<"3-  "<<reservation[2]<<endl;
                cout<<"4-  "<<reservation[3]<<endl;
                cout<<"5-  "<<reservation[4]<<endl;
                cin>>cho;
            if(cho==1)
            {
                patient[i].reserve=reservation[0];
                reservation[0]="NoT Avialble";
                cout<<"####Success####"<<endl;
            }
            else if (cho==2)
            {   reservation[1]="2:30pm to 3pm";
                patient[i].reserve=reservation[1];
                reservation[1]="NoT Avialble";
                cout<<"####Success####"<<endl;

            }
            else if (cho==3)
            {   reservation[2]="3pm to 3:30pm";
                patient[i].reserve=reservation[2];
                reservation[2]="NoT Avialble";
                cout<<"####Success####"<<endl;
            }
            else if (cho==4)
            {   reservation[3]="4pm to 4:30pm";
                patient[i].reserve=reservation[3];
                reservation[3]="NoT Avialble";
                cout<<"####Success####"<<endl;
            }
            else if (cho==5)
            {   reservation[4]="4:30pm to 5pm";
                patient[i].reserve=reservation[4];
                reservation[4]="NoT Avialble";
                cout<<"####Success####"<<endl;
            }
            else
                cout<<"Wrong answer"<<endl;
            break;
            }
            if (range >0 )
            break;

             if (range==0)
            {
                cout<<"ID Not Found";
            }

            }
        }

    void cancel_reservation()
    {
        int test,cho ;
        cout<<"Enter Id :";
        cin>>test;
        int range=0 ;

        for (int i = 0 ; i<=c ; i++)
        {
            if (test==patient[i].id)
            {
                range++;
                cout<<"Name :"<<patient[i].name<<endl;
                cout<<"Age :"<<patient[i].age<<endl;
                cout<<"Phone's number :"<<patient[c].phone_num<<endl;
                cout<<"Gender :"<< patient[i].gender<<endl;
                cout<<patient[i].reserve<<" has been canceled and made available to other patients ."<<endl;
                 if (patient[i].reserve=="2pm to 2:30pm")
                    {reservation[0]="2pm to 2:30pm";
                    patient[i].reserve="have been cancelled";}
                 if (patient[i].reserve=="3pm to 3:30pm")
                    {reservation[1]="3pm to 3:30pm";
                    patient[i].reserve="have been cancelled";}
                 if (patient[i].reserve=="3pm to 3:30pm")
                    {reservation[2]="3pm to 3:30pm";
                    patient[i].reserve="have been cancelled";}
                 if (patient[i].reserve=="4pm to 4:30pm")
                   {reservation[3]="4pm to 4:30pm";
                    patient[i].reserve="have been cancelled";}
                 if (patient[i].reserve=="4:30pm to 5pm")
                    {reservation[4]="4:30pm to 5pm";
                    patient[i].reserve="have been cancelled";}
                break;
           }

        }
    }

    void display(int i)
    { info::display(0); //function overriding :
        cout<<"Name :"<<patient[i].name<<endl;
        cout<<"Age :"<<patient[i].age<<endl;
        cout<<"Phone's number :"<<patient[i].phone_num<<endl;
        cout<<"Gender :"<< patient[i].gender<<endl;
        cout<<"Reservation :"<<patient[i].reserve<<endl;
    }
//////////
    void admin()
{   system("cls");
    int ch,i ;
    string backs;
    cout<<"1-To add Patient..."<<endl;
    cout<<"2-To reserve a slot with the doctor..."<<endl;
    cout<<"3-To edit patient record..."<<endl;
    cout<<"4-Cancel reservation..."<<endl;
    cout<<"5-Search patient's information..."<<endl;
    cout<<"6-Show all patients..."<<endl;
    cout<<"7-Back.............."<<endl;
    cout<<"0-Close the system..."<<endl;
    cin>>ch;
    if (ch==1)
    {system("cls");
    add_patient();
    cout<<"TO back Enter anything:";
    cin>>backs;
    }
    else if (ch==2)
    {system("cls");
    select_reservation();
    cout<<"TO back Enter anything:";
    cin>>backs;}
    else if (ch==3)
    {system("cls");
    edit_record();
    cout<<"TO back Enter anything:";
    cin>>backs;}
    else if (ch==4)
    {system("cls");
    cancel_reservation();
    cout<<"TO back Enter anything:";
    cin>>backs;}
    else if (ch==5)
    {system("cls");
    cout<<"Enter ID: "; cin>>i;
    display(i);
    cout<<"TO back Enter anything:";
    cin>>backs;}
    else if (ch==6)
    {
    display();
    cout<<"TO back Enter anything:";
    cin>>backs;
    }
    else if (ch==7)
    {
    system("cls");
    start();
    }
    else if (ch==0)
    exit(0);

}

    void user()
    { system("cls");
        int test , range=0;
        cout<<"Enter Id :";
        cin>>test;
        for (int i = 0 ; i<=c ; i++)
        {   if (range==1)
            break;

            if (test==patient[i].id)
            {   range++;
                display(i);
                break;
            }

        }
    }

 void start()
 {
      int y;
     cout<<"Clinic Management System"<<endl;
     cout<<"----------------------"<<endl;
     cout<<"Choose between admin mode or user mode "<<endl;
     cout<<"1-Admin mode..."<<endl;
     cout<<"2-User mode..."<<endl;
     cin>>y;
     if (y==1)
     {
         int pass =1234 , test2,test3;
         cout<<"Welcome to Admin mode //Default password 1234"<<endl;
         for (int k=0 ; k<3 ; k++)
         {
         cout<<"Enter password :"; cin>>test2;
         if (test2==1234)
         break;
         if (k>=2)
         exit(0);
         }
         cout<<"Welcome to Admin mode..."<<endl;
         for(;;)
         admin();
     }
     if(y==2)
     {
         int backk;
         user();
         cout<<"0-Back..."<<endl;
         cin>>backk;
         if (backk==0)
         start();
     }
 }

};
int patient::c=0;

int main ()
{
patient test;
//polymorphism : Polymorphism means "many forms", and it occurs when we have many //classes that are related to each other by inheritance.
//Simple Example :
info *ptr ;
ptr=&test;
ptr->start();
system("pause");
return  0;
}
