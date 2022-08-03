#include <iostream>
#include<conio.h>
#include<fstream>

using namespace std;
class Contact{
private:
    char fname[50],lname[50],address[50],email[50];
    long long phone_number;
public:
    void creat_contact(){
    cout<<"Enter your first name: ";
    cin>>fname;

    cout<<"Enter your last name: ";
    cin>>lname;

    cout<<"Enter your address: ";
    cin>>address;

    cout<<"Enter your email: ";
    cin>>email;

    cout<<"Enter your phone number: ";
    cin>>phone_number;


    }


    void show_contact (){
    cout<<"Name: "<<fname<<" "<<lname<<endl;
    cout<<"Phone: "<<phone_number<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Email: "<<email<<endl;
    }



    void writ_on_file(){
    char ch;
    ofstream f1;
    f1.open("CMS.dat",ios::binary | ios::app);
    do {
     creat_contact();
     f1.write(reinterpret_cast<char*>(this),sizeof(*this));

     cout<<"do you have next data ?(y/n)";
     cin>>ch;

    }while(ch=='y');

    cout<<"contact has been sucessfully created...";
    f1.close();
    }



    void read_from_file(){
    ifstream f2;

    f2.open("CMS.dat",ios::binary);

    cout<<"\n------------------------------------------\n";
    cout<<"\t\tLIST OF CONTACTS";
    cout<<"\n------------------------------------------\n";

    while(!f2.eof()){
        if(f2.read(reinterpret_cast<char*>(this),sizeof(*this))){
            show_contact();
            cout<<"\n------------------------------------------\n";
        }

    }
    f2.close();
    }



    void search_on_file(){
    ifstream f3;

    long long phone;
    cout<<"\nENTER THE PHONE NUMBER: ";
    cin>>phone;

    f3.open("CMS.dat",ios::binary);
    while(!f3.eof()){
        if(f3.read(reinterpret_cast<char*>(this),sizeof(*this))){
            if(phone==phone_number){
                show_contact();
                return;
            }
        }

    }
    cout<<"\n\n No record found";
    f3.close();
}



   void delet_from_file(){
    long long ph;
    int flag=0;

      ofstream f4;
      ifstream f5;
      f5.open("CMS.dat",ios::binary);
      f4.open("temp.dat",ios::binary);

     cout<<"\nENTER THE PHONE NUMBER THAT YOU WANT TO DELETE: ";
     cin>>ph;

      while(!f5.eof()){
        if(f5.read(reinterpret_cast<char*>(this),sizeof(*this))){
            if(ph!=phone_number){
                f4.write(reinterpret_cast<char*>(this),sizeof(*this));
            }
            else flag=1;
        }
      }
      f5.close();
      f4.close();
      remove("CMS.dat");
      rename("temp.dat","CMS.dat");

      if(flag==1){
        cout<<"\t Contact Deleted..."<<endl;
      }
      else
        cout<<"\t Contract Not Found !!!"<<endl;

   }


   void Editcontcat(){
   long long ph;
   fstream f6;

   cout<<"\n\t\t EDIT CONTACT ";
   cout<<"\n------------------------------------------\n";
   cout<<"ENTER THE PHONE NUMBER THAT YOU WANT TO EDIT: ";

   cin>>ph;
   f6.open("CMS.dat",ios::binary| ios::in|ios::out);

   while(!f6.eof()){
    if(f6.read(reinterpret_cast<char*>(this),sizeof(*this))){
        if(ph==phone_number){
            cout<<"Enter New RECORD\n";
            creat_contact();
            int pos=-1*sizeof(*this);
            f6.seekp(pos,ios::cur);
            f6.write(reinterpret_cast<char*>(this),sizeof(*this));
            cout<<endl<<endl<<"\t Contact Successfully Updated...";
            return;
        }
    }
   }
cout<<"\n\n NO RECORD FOUND";
f6.close();
 }




  };

int main (){
   system("cls");
   system("Color 9");

     cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t < WELCOM TO THE CONTACT MANAGEMENT SYSTEM> ";

     getch();

     while(1){
        Contact c1;
        int choice;

        system("cls");
        system("Color 9");

        cout<<"\n\nMAIN MENU";
        cout<<"\n-------------------------------------------------\n";
        cout<<"1) Add A New Contact\n";
        cout<<"2) List All Contact\n";
        cout<<"3) Search For A Contact\n";
        cout<<"4) Delete A Contact\n";
        cout<<"5) Edit A Contact\n";
        cout<<"6) Exit ";
        cout<<"\n-------------------------------------------------\n";
        cout<<"Enter Your Choice: ";
        cin>>choice;

    switch(choice){

        case 1:
             system("cls");
            c1.writ_on_file();
            break;

        case 2:
             system("cls");
            c1.read_from_file();
            break;

        case 3:
             system("cls");
            c1.search_on_file();
            break;

        case 4:
             system("cls");
            c1.delet_from_file();
            break;

        case 5:
             system("cls");
            c1.Editcontcat();
            break;

        case 6:
             system("cls");
             cout<<"\n\n\n\n\n\t\t\t Thank You For Using Our Program";
             exit(6);
             break;

        default:
            continue;
        }
        int opt;
        cout<<"\n\n Enter The Choice 1 To Go To The Main Menu\t\t";
        cin>>opt;

        switch (opt){
        case 0 :
        system("cls");
             cout<<"\n\n\n\n\n\t\t\t Thank You For Using Our Program";
             exit(0);
             break;

        default:
            continue;


      }
     }

}