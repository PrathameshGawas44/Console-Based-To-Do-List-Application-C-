#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
class to_do_list
{
   public:
   string dolist, priority;
   int date, month, year;
   void addlist();
   void show();
};

void to_do_list::addlist()
{
    char ch;
    dolist="-";
    cout<<"\n Add a New Task : ";
    cin.ignore();
    getline(cin,dolist);
    cout<<"\n Does this task has Deadline ?(y for yes) : ";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        cout<<"\n Add date : ";
        cin>>date;
        cout<<"\n Add month : ";
        cin>>month;
        cout<<"\n Add year : ";
        cin>>year;
    }
    else
    {
        date=99;
        month=99;
        year=9999;
    }
    int num;
    cout<<"\n Does this task has any Priority ?(y for yes) : ";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        cout<<"\n Enter choice\n 1.low\n 2.medium\n 3.high\n\n";
        cin>>num;
        switch(num)
        {
            case 1:
            priority="low";
            break;
            case 2:
            priority="medium";
            break;
            case 3:
            priority="high";
            break;
            default:
            priority="low";
            break;
        }
    }
    else
    priority="low";
}

void to_do_list::show()
{
   cout<<" Task : "<<dolist;
   if(date==99)
     cout<<"\t\tDeadline : No Deadline";
   else
     cout<<"\t\tDeadline : "<<setfill('0')<<setw(2)<<date<<"/"<<setfill('0')<<setw(2)<<month<<"/"<<setfill('0')<<setw(4)<<year;
   cout<<"\t\tPriority : "<<priority;
   cout<<"\n\n";
}

class reminder: public to_do_list
{
   public:
       string notes;
   void note()
   {
       cout<<"\n Enter any note you want to add for above task : \n\n ";
       cin.ignore();
       getline(cin,notes);
   }
   void rem()
   {
      cout<<"\n\n Just a reminder : "<<dolist;
   }
   void suggest(int i)
   {
      cout<<"\n "<<i+1<<". "<<dolist;
   }
   void display()
   {
       cout<<"\n Task : "<<dolist;
       cout<<"\t\tNotes : "<<notes;
   }
};

int main()
{
    reminder T[100];
    fstream file;
    file.open("task.dat" ,ios::in|ios::binary);
    int a,ch,c=-1,C=0;
    file.seekg(0);
    try{
    if (file.is_open())
    {
        file.read((char*)&c,sizeof(c));
    for(int i=0;i<=c;i++)
    {
        file.read((char *)&T[i],sizeof(T[i]));
    }
    }
    else
        throw 10;
    file.close();
    }
    catch(...)
    {
        cout<<"\n\033[31m Error in opening file Tasks cannot be loaded \033[0m"<<endl<<endl;
    }

    while(1)
    {
        a=0;
        cout<<"\033[32m";
        for(int i=0;i<50;i++)
        cout<<"-";
        cout<<"\n\n";
        cout<<"\033[36m";
        cout<<" Enter Your Choice \n 1.Add Task\n 2.Show Task\n 3.Delete Task\n 4.Sort task\n 5.Suggestion\n 6.Show additional notes of Task\n 7.Delete All Tasks\n 8.Exit\n\n";
        cin>>ch;
        switch(ch)
        {
           case 1:
           char choice;
           T[++c].addlist();
           cout<<"\n Do you want to add any additional notes to the task (y for yes) : ";
           cin>>choice;
           if(choice=='y'||choice=='Y')
           T[c].note();
           else
           T[c].notes=" - ";
           break;

           case 2:
           if(c==-1)
            cout<<"\n\033[33m No tasks present \033[0m";
           else
           {
           cout<<endl;
           for(int i=0;i<=c;i++)
           T[i].show();
           }
           break;

           case 3:
           if(c==-1)
           { cout<<"\n\033[33m No tasks present to delete \033[0m"; a=1;}
           else
           {
           cout<<endl;
           for(int i=0;i<=c;i++)
           {
           cout<<" "<<i+1<<". ";
           T[i].show();
           }
           cout<<" which Task to delete from above list : ";
           cin>>a;
           if(a>c+1)
           {
           cout<<"\n only "<<c+1<<" is there ";
           a=1;
           }
           else
           {
           cout<<"\n "<<T[a-1].dolist<<" deleted successfully \n";
           T[a-1]=T[c];
           c--;
           a=0;
           }
           }

           case 4:
           if(a==0)
           {
               if(c==-1)
               cout<<"\n\033[33m No tasks present to sort \033[0m";
           else
           {
           for(int i=0;i<c;i++)
           {
              for(int j=0;j<c;j++)
              {
                 if(T[j].year>T[j+1].year)
                 {
                 reminder temp;
                 temp=T[j];
                 T[j]=T[j+1];
                 T[j+1]=temp;
                 }
                 else if(T[j].year==T[j+1].year&&T[j].month>T[j+1].month)
                 {
                 reminder temp;
                 temp=T[j];
                 T[j]=T[j+1];
                 T[j+1]=temp;
                 }
                 else if(T[j].month==T[j+1].month&&T[j].date>T[j+1].date)
                 {
                 reminder temp;
                 temp=T[j];
                 T[j]=T[j+1];
                 T[j+1]=temp;
                 }
                 else if(T[j].date==T[j+1].date&&T[j+1].priority=="high"&&T[j].priority!="high")
                 {
                 reminder temp;
                 temp=T[j];
                 T[j]=T[j+1];
                 T[j+1]=temp;
                 }
                 else if(T[j].date==T[j+1].date&&T[j+1].priority=="medium"&&T[j].priority=="low")
                 {
                 reminder temp;
                 temp=T[j];
                 T[j]=T[j+1];
                 T[j+1]=temp;
                 }
              }
           }
           cout<<"\n\n Tasks Sorted by Deadline \n";
           }
           }
            break;

           case 5:
           if(c==-1)
            cout<<"\n\033[33m No tasks present to Suggest \033[0m";
           else
           {
           for(int i=0;i<=c&&i<3;i++)
           { T[i].suggest(i); }
           }
           break;

           case 6:
           if(c==-1)
            cout<<"\n\033[33m No tasks present \033[0m ";
           else
           {
           cout<<endl;
           for(int i=0;i<=c;i++)
           T[i].display();
           }
           break;

           case 7:
           if(c==-1)
            cout<<"\n\033[33m No tasks present to delete \033[0m";
           else
           {
           c=-1;
           cout<<"\n All tasks Deleted successfully ";
           }
           break;

           case 8:
            file.open("task.dat" ,ios::out|ios::binary);
            try{
               if (file.is_open())
                {
                file.write((char*)&c,sizeof(c));
            for(int i=0;i<=c;i++)
            {
                file.write((char *)&T[i],sizeof(T[i]));
            }
                }
                else
                    throw 2.0;
                file.close();
            }
            catch(...)
            {
                cout<<"\n\033[31m Error in Opening file Tasks cannot be saved \033[0m"<<endl<<endl;
            }
           cout<<"\n\033[35m Exiting Program . . . \033[0m";
           getch();
           return 0;

           default:
           cout<<"\n\033[31m Wrong Choice \033[0m";

        }
        cout<<"\n\n";
        cout<<"\033[32m";
        for(int i=0;i<50;i++)
        cout<<"-";
        if(c!=-1)
        T[C].rem();
        cout<<"\n\n";
    }
}
