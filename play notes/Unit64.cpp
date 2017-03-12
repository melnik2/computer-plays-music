#include <vcl.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <ctime.h>
#include <fstream.h>
#include <conio.h> 
#include <windows.h>
#include <locale.h>
#include <MMSystem.h>
//#include <cctype>
#include <sstream>


using namespace std;
func1 (int numid);


int cn1,cn2;
char pen1;
int m;
float n1;
FILE *fp1,*fp2;
string filen;
int q1,q2;

int main(int argc, char *argv[]) {

printf("Google+ http://plus.google.com/107022365509369805155\temail: haxi@mail.ru\n\n");

do{

printf("input file.txt\n");

getline(cin,filen);
AnsiString FileName1=GetCurrentDir()+"\\note\\"+filen.c_str()+".txt";
fp1=fopen(FileName1.c_str(),"r");
//fp1=fopen("t0.txt","r");
if((fp1)!=NULL) {
printf("File - OK \n\n\n");
  }
  else {
printf("File - BAD \n");
  }
while((pen1=fgetc(fp1))!= EOF) {
cn1++;
if(pen1=='\t')cn2++;
}
fclose(fp1);
delete [] fp1;

int x1=0;
int y1=0;
char ** arrstr1 = new char * [cn2];
for (int i=0; i<cn2; i++)arrstr1[i]=new char [4];

for (int i=0; i<cn2; i++){
for (int j=0; j<3; j++){
arrstr1[i][j]=NULL;
}
}

fp2=fopen(FileName1.c_str(),"r");
//fp2=fopen("t0.txt","r");
while((pen1=fgetc(fp2))!= EOF) {
if(pen1!='\t')arrstr1[x1][y1]=pen1,y1++;
else x1++,y1=0;
}
fclose(fp2);
delete [] fp2;

filen.clear();


/* sformirovannai matrix char
for(int i=0; i<cn2; i++){
cout<<arrstr1[i]<<" ";
}
*/

int num1,num2;
int * arrnum = new int [cn2];
stringstream cs;

for(int i=0; i<cn2; i++){
for(int j=0; j<3; j++){
num1 = static_cast<int>(arrstr1[i][j]);
cs<<num1;
}
cs>>num2;
arrnum[i]=num2;
cs.clear();
}

/* sformirovannai matrix identificaci (int) kajdogo char
for(int i=0; i<cn2; i++){
cout<<arrnum[i]<<endl;
}
*/

int* arrnm1 = new int[cn2];
float* arrnm2 = new float[cn2];
float* arrnm3 = new float[cn2];

for(int i=0; i<cn2; i++){
func1(arrnum[i]);
arrnm1[i]=m;
arrnm2[i]=n1;
}


/* sformirovannai matrix nomera fila
for(int i=0; i<cn2; i++){
cout<<arrnm1[i]<<" "<<arrnm2[i]<<endl;
}
*/

float n2;

for(int i=0; i<cn2; i++){
n1=arrnm2[i];
if(n2>n1)arrnm3[i]=(n2-n1)*(-1);
else arrnm3[i]=n1-n2;
if(!(float)n2){
arrnm3[i-1]=100;
if(arrnm2[i-2]>n1)arrnm3[i]=(arrnm2[i-2]-n1)*(-1);
else arrnm3[i]=n1-arrnm2[i-2];
}
n2=n1;
}
arrnm3[0]=0;


x1=1;
for(int i=0; i<cn2; i++){
if(x1>10)cout<<endl<<endl,x1=1;
printf("%s\t",arrstr1[i]);
x1++;
}
//delete [] arrstr1;


/* sformirovannai matrix posicia not dla intervala
int x3=1;
cout<<endl<<endl<<endl;
for(int i=0; i<cn2; i++){
if (x3>10)cout<<endl<<endl, x3=1;
cout<<arrnm2[i]<<"\t";
x3++;
}
cout<<endl<<endl;
*/

/* sformirovannai matrix Interval not */
int x4=1;
cout<<endl<<endl<<endl<<"----------------------------------"<<endl<<endl;
for(int i=0; i<cn2; i++){
if (x4>10)cout<<endl<<endl, x4=1;
if (arrnm3[i]!=100)cout<<arrnm3[i]<<"\t";
else cout<<"X\t";
x4++;
}

cout<<endl<<endl<<"==================================="<<endl<<endl;

    char* mk1 = new char[10];
    char* mk2 = new char[6];
    mk1=".\\snd\\";
    mk2=".wav";
    int n4;
    char buf[16]="";
    char mc4[4];

    char ** arrstr2 = new char * [cn2];
    for (int i=0; i<cn2+1; i++){
    arrstr2[i]=new char [16];
    }

for(int i=0; i<cn2; i++){
     n4=arrnm1[i];
     itoa(n4,mc4,10);
     strcpy(buf,mk1);
     strcat(buf,mc4);
     strcat(buf,mk2);

for(int j=0; j<16; j++){
     arrstr2[i][j]=buf[j];
     }
}
delete [] arrnm1;
delete [] arrnm2;
delete [] arrnm3;
delete [] mk1;
delete [] mk2;
delete [] buf;
delete [] mc4;

/* sformirovannai matrix nazvania muzfilov
for(int i=0; i<cn2; i++){
cout<<arrstr2[i]<<endl;
}
*/

int x2;
if(cn2<11)cn2--;
do{

x1=0;
x2=2;
printf("\n1 ");
for(int i=0; i<cn2; i++){
if(x1>=10)printf("\r\t\t\t\t\t\t\r"),printf("%d ",x2),x2++,x1=0;
x1++;
printf("%s ",arrstr1[i]);
PlaySound(TEXT(arrstr2[i]),NULL,0);
}

printf(" Reapet-1or0 ");
scanf("%d",&q1);
} while (q1==1);

delete [] arrstr2;
delete [] arrstr1;

printf("Other melody-1or0 ");
scanf("%d",&q2);

cn1=0;
cn2=0;

cin.sync();
 //system("cls");

} while (q2==1);

 //system("PAUSE");
 return 0;
}



func1 (int numid){
switch (numid){
case 4500:   //-
m=0;
n1=0;
break;
case 101480: //e0
m=10;
n1=1;
break;
case 102480: //f0
m=15;
n1=2;
break;
case 3510248://#f0
m=18;
n1=2.5;
break;
case 103480: //g0
m=20;
n1=3;
break;
case 3510348://#g0
m=23;
n1=3.5;
break;
case 97480:  //a0
m=25;
n1=4;
break;
case 98480:  //b0
m=28;
n1=4.5;
break;
case 104480: //h1
m=30;
n1=5;
break;
case 99490:  //c1
m=35;
n1=6;
break;
case 359949: //#c1
m=38;
n1=6.5;
break;
case 100490: //d1
m=40;
n1=7;
break;
case 3510049://#d1
m=43;
n1=7.5;
break;
case 101490: //e1
m=45;
n1=8;
break;
case 102490: //f1
m=50;
n1=9;
break;
case 3510249://#f1
m=53;
n1=9.5;
break;
case 103490: //g1
m=55;
n1=10;
break;
case 3510349://#g1
m=58;
n1=10.5;
break;
case 97490:  //a1
m=60;
n1=11;
break;
case 98490:  //b1
m=63;
n1=11.5;
break;
case 104490: //h1
m=65;
n1=12;
break;
case 99500:  //c2
m=70;
n1=13;
break;
case 359950: //#c2
m=73;
n1=13.5;
break;
case 100500: //d2
m=75;
n1=14;
break;
case 3510050://#d2
m=78;
n1=14.5;
break;
case 101500: //e2
m=80;
n1=15;
break;
case 102500: //f2
m=85;
n1=16;
break;
case 3510250://#f2
m=88;
n1=16.5;
break;
case 103500: //g2
m=90;
n1=17;
break;
case 3510350://#g2
m=93;
n1=17.5;
break;
case 97500:  //a2
m=95;
n1=18;
break;
case 98500:  //b2
m=98;
n1=18.5;
break;
case 104500: //h2
m=100;
n1=19;
break;
case 69480:  //E0
m=10;
n1=1;
break;
case 70480:  //F0
m=15;
n1=2;
break;
case 357048: //#F0
m=18;
n1=2.5;
break;
case 71480:  //G0
m=20;
n1=3;
break;
case 357148: //#G0
m=23;
n1=3.5;
break;
case 65480:  //A0
m=25;
n1=4;
break;
case 66480:  //B0
m=28;
n1=4.5;
break;
case 72480:  //H0
m=30;
n1=5;
break;
case 67490:  //C1
m=35;
n1=6;
break;
case 356749: //#C1
m=38;
n1=6.5;
break;
case 68490:  //D1
m=40;
n1=7;
break;
case 356849: //#D1
m=43;
n1=7.5;
break;
case 69490:  //E1
m=45;
n1=8;
break;
case 70490:  //F1
m=50;
n1=9;
break;
case 357049: //#F1
m=53;
n1=9.5;
break;
case 71490:  //G1
m=55;
n1=10;
break;
case 357149: //#G1
m=58;
n1=10.5;
break;
case 65490:  //A1
m=60;
n1=11;
break;
case 66490:  //B1
m=63;
n1=11.5;
break;
case 72490:  //H1
m=65;
n1=12;
break;
case 67500:  //C2
m=70;
n1=13;
break;
case 356750: //#C2
m=73;
n1=13.5;
break;
case 68500:  //D2
m=75;
n1=14;
break;
case 356850: //#D2
m=78;
n1=14.5;
break;
case 69500:  //E2
m=80;
n1=15;
break;
case 70500:  //F2
m=85;
n1=16;
break;
case 357050: //#F2
m=88;
n1=16.5;
break;
case 71500:  //G2
m=90;
n1=17;
break;
case 357150: //#G2
m=93;
n1=17.5;
break;
case 65500:  //A2
m=95;
n1=18;
break;
case 66500:  //B2
m=98;
n1=18.5;
break;
case 72500:  //H2
m=100;
n1=19;
break;
default:
break;
}
 return m,n1;
 }

