//Elliot Belin
// Assignment #9.
//using structs

#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;

struct names{
       string fname[20];
       char mname[20];
       string lname[20];
       };
       
struct grades{
       float G1[20];
       float G2[20];
       float G3[20];
       float G4[20];
       float midterm[20];
       float final[20];
       };
       
struct letters{
       string lettergrade[20];
       };
  
  
names nameslist;
grades gradeslist;
letters letterslist; 
       
ofstream outfile("C:\\workarea\\ebresults9ec.txt",ios::out);


void gradefunction(int glimit, string grade[])
{
for(int x=0; x<glimit; x++)
      grade[x]=' ';
      
      for(int x=0; x<8; x++)
      if(x==0)
      grade[x]="A+";
      else if(x==1)
      grade[x]="A ";
      else if(x==2)
      grade[x]="B+";
      else if(x==3)
      grade[x]="B ";
      else if(x==4)
      grade[x]="C+";
      else if(x==5)
      grade[x]="C ";
      else if(x==6)
      grade[x]="D ";
      else
      grade[x]="F ";
          
}


void chartprint(int limit, char chart[][8])
{
    outfile<<"Grade Distribution Chart"<< endl<<endl;
    for(int y=limit-1; y>0; y--)
    {
    outfile<<setw(2)<<y<<"|";
    for(int x=0; x<8; x++)
    outfile<< setw(3)<<chart[y][x]<<" ";
    outfile<< endl;
    }
    outfile<<"  +--------------------------------"<<endl;
    
const int glimit=8;
string grade[glimit]; 

    gradefunction(glimit, grade);
    outfile<<"   ";
    for(int x=0; x<glimit; x++)
    {
     
     outfile<<setw(4)<<grade[x];
    }
    outfile<<endl;
   
}  


void printingfunction(int limit, names, grades, float average1[], letters, int index1[], string nlength[])
{

outfile<<"Name"<<setw(24)<<"Quiz1"<<setw(8)<<"Quiz2"<<setw(8)<<"Quiz3"<<setw(8)<<"Quiz4"<<setw(10)<<"Midterm"<<setw(9)<<"Final"
        <<setw(11)<<"Average"<<setw(8)<<"Grade"<<endl;
outfile<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
     for(int x=0; x<limit; x++)
     {
     outfile<<setw(20)<<left<<nlength[index1[x]]<<right<< setw(8)<<gradeslist.G1[index1[x]]<<setw(8)<<gradeslist.G2[index1[x]]<<setw(8)<<gradeslist.G3[index1[x]]<<setw(8)
            <<gradeslist.G4[index1[x]]<<setw(9)<< gradeslist.midterm[index1[x]]<<setw(9)<<gradeslist.final[index1[x]]<<setw(10)<< average1[index1[x]]<<setw(8)
            << letterslist.lettergrade[index1[x]]<<endl;
     }
}


void average(int limit,  grades, float average1[])
{
     for(int x=0; x<limit; x++)
     {
     average1[x]=((gradeslist.G1[x]+ gradeslist.G2[x] + gradeslist.G3[x] + gradeslist.G4[x])/4.0*0.5)+ (gradeslist.final[x]*0.25)+(gradeslist.midterm[x]*0.25);
     }

}

void letteraverage(int limit, float average1[],  letters)
{     
     for(int x=0; x<limit; x++) 
     if((100>=average1[x])&&(average1[x]>=95))
     letterslist.lettergrade[x]="A+";
     else if((95>average1[x])&&(average1[x]>=90))
     letterslist.lettergrade[x]="A ";
     else if((90>average1[x])&&(average1[x]>=85))
     letterslist.lettergrade[x]="B+";
     else if((85>average1[x])&&(average1[x]>=80))
     letterslist.lettergrade[x]="B ";
     else if((80>average1[x])&&(average1[x]>=75))
     letterslist.lettergrade[x]="C+";
     else if((75>average1[x])&&(average1[x]>=70))
     letterslist.lettergrade[x]="C ";
     else if((70>average1[x])&&(average1[x]>=60))
     letterslist.lettergrade[x]="D ";
     else
     letterslist.lettergrade[x] ="F ";
     
}   

void indexfunction(int limit, int index1[], int index2[], int index3[])
{
    for(int x=0; x<limit; x++)
    {
    index1[x]=x;    
    index2[x]=x;
    index3[x]=x;
    }
}
void ascendingindex(int limit, float average1[],int index1[], int index2[], int index3[])
{
const int limit2=limit;
int x =0;

int hold=0;
    indexfunction(limit, index1, index2, index3);
    
    for(int x=0; x<limit-1; x++)
    for(int y=x; y<limit; y++)
    if(average1[index2[x]]>average1[index2[y]]) 
    {
     hold=index2[x];
     index2[x]=index2[y];
     index2[y]=hold;
    }
    for(int x=0; x<limit; x++)
    index1[x]=index2[x];
}


void descendingindex(int limit, float average1[], int index1[], int index2[], int index3[])
{
const int limit2=limit;
int hold=0;
    indexfunction(limit, index1, index2, index3);
    
    for(int x=0; x<limit-1; x++)
    for(int y=x; y<limit; y++)
    if(average1[index3[x]]<average1[index3[y]]) 
    {
     hold=index3[x];
     index3[x] = index3[y];
     index3[y] = hold;
    }
    for(int x=0; x<limit; x++)
    index1[x]=index3[x];
}

void chartfunction(int limit, float average1[], char chart[20][8])
{
     for(int y=1; y<limit; y++)
     for(int x=0; x<8; x++)
     chart[y][x]=' ';
      
int y=1;
    for(int x=0; x<limit; x++)
    if((100>=average1[x])&&(average1[x]>=95))
    if(chart[y][0]==' ')
      {
       chart[y][0]='x';
       y=0;
      }
    else
      {
       x--;
       y++;
      }
    else if((95>average1[x])&&(average1[x]>=90))
    if(chart[y][1]==' ')
      {
       chart[y][1]='x';
       y=0;
      }
    else
      {
       x--;
       y++;
      }
    else if((90>average1[x])&&(average1[x]>=85))
    if(chart[y][2]==' ')
      {
       chart[y][2]='x';
       y=0;
      }
    else
      {
       x--;
       y++;
      }
    else if((85>average1[x])&&(average1[x]>=80))
    if(chart[y][3]==' ')
      {
       chart[y][3]='x';
       y=0;
      }
    else
      {
       x--;
       y++;
      }
    else if((80>average1[x])&&(average1[x]>=75))
    if(chart[y][4]==' ')
      {
       chart[y][4]='x';
       y=0;
      }
    else
      {
       x--;
       y++;
      }
    else if((75>average1[x])&&(average1[x]>=70))
    if(chart[y][5]==' ')
      {
       chart[y][5]='x';
       y=0;
      }
    else
      {
       x--;
       y++;
      }
    else if((70>average1[x])&&(average1[x]>=60))
    if(chart[y][6]==' ')
       {
       chart[y][6]='x';
       y=0;
      }
    else
      {
       x--;
       y++;
      }
    else if(60>average1[x])
    if(chart[y][7]==' ')
      {
       chart[y][7]='x';
       y=0;
      }
    else
      {
       x--;
       y++;
      }
}

int main()
{
    


const int limit=20;
int x =0;

string nlength[limit];
int index1[limit]={0}, index2[limit]={0}, index3[limit]={0};


    ifstream infile("C:\\workarea\\stuctsInfile.txt",ios::in);
    
    if(!infile){
    cerr <<"File could not be opened"<< endl;
    getch();
    exit(1);
    }
    
    cout<<setiosflags(ios::left);
float average1[limit]={0};
    
    while(infile>> nameslist.fname[x]>>nameslist.mname[x]>>nameslist.lname[x]>> gradeslist.G1[x]>> gradeslist.G2[x]>> gradeslist.G3[x]>>gradeslist.G4[x] >> gradeslist.midterm[x]>>gradeslist.final[x])
    {
     nlength[x]=nameslist.fname[x]+ " " + nameslist.mname[x] + " " + nameslist.lname[x]; 
    x++;
    }

    average(limit,gradeslist, average1);
    
   
    letteraverage(limit, average1,letterslist);
    cout<<"Student Names"<<endl;
    cout<<"-------------"<<endl;
    
   for(int x=0; x<limit; x++)
   cout<<setw(20)<< nlength[x] <<" has been processed."<< endl;
    
   cout<<endl;
    outfile<<setiosflags(ios::fixed)<< setiosflags(ios::showpoint)<< setprecision(2);
   
    outfile<< endl << endl; 
    outfile<<"Student Records printed in the original order via printing function."<< endl<<endl;
    indexfunction(limit, index1, index2, index3);
    printingfunction(limit, nameslist,gradeslist, average1, letterslist,index1, nlength);
    

    outfile<< endl<<endl;
    outfile<<"Student Records printed with an index in ascending order via printing function."<< endl<<endl;
    ascendingindex(limit, average1, index1, index2, index3);
    printingfunction(limit, nameslist,gradeslist, average1, letterslist,index1, nlength);
    
    
    outfile<< endl << endl;
    outfile<<"Student Records printed with an index in descending order via printing function."<< endl<<endl;
    descendingindex(limit, average1, index1, index2, index3);
    printingfunction(limit, nameslist, gradeslist, average1, letterslist, index1, nlength); 
    
    outfile<< endl<< endl;
    
char chart[limit][8];  
const int glimit=8;
string grade[glimit];

     chartfunction(limit, average1, chart);
      chartprint( limit,  chart);
     
    getch();
}
