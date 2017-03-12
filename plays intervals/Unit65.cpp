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
#include <sstream>
#include <math.h>

using namespace std;
func1 (int numid);
func2 (int numit);

int cn1,cn2;
char pen1;
FILE *fp1,*fp2;
string filen;
int m;
float n1;
string xtr1;

int main(int argc, char *argv[]) {

printf("Google+ http://plus.google.com/107022365509369805155\temail: haxi@mail.ru\n\n");

int q3;

do{

printf("input file.txt\n");

scanf("%s",filen);
AnsiString FileName1=GetCurrentDir()+"\\note\\"+filen.c_str()+".txt";
fp1=fopen(FileName1.c_str(),"r");
  
if((fp1)!=NULL) {
printf("File - OK \n\n");
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

char* mt1= new char[cn1+1];
int x1=0;


fp2=fopen(FileName1.c_str(),"r");

while((pen1=fgetc(fp2))!= EOF) {
mt1[x1]=pen1;
x1++;
}
x1=0;
fclose(fp2);
delete [] fp2;

filen.clear();

float* arr1 = new float[cn2+1];
string st1,st3;
st3="";

for(int i=0; i<cn1; i++){
if(mt1[i]!='\t' && mt1[i]!='\n'){
st1=mt1[i];
if (st1==",")st1=".";
if (st1=="X")st1="100";
st3=st3+st1;
}
else{
arr1[x1]=atof(st3.c_str());
cout<<arr1[x1]<<"\t";
x1++;
st3="";
}
st1="";
}

int q1;

do{
printf("\n\nfirst note: ");

char ch1[]="";
scanf("%s",ch1);

int num1,num2;
stringstream cs;

for(int i=0; i<3; i++){
num1 = static_cast<int>(ch1[i]);
cs<<num1;
}
cs>>num2;
cs.clear();

delete [] ch1;

func2(num2);


float* arr2 = new float[cn2+1];
arr2[0]=n1;
for(int i=1; i<cn2; i++){
if(arr1[i]!=100)arr2[i]=arr2[i-1]+arr1[i];
else arr2[i]=0,arr2[i+1]=arr2[i-1]+arr1[i+1],i++;
}
printf("\n");

int* arrnm1 = new int[cn2];

for(int i=0; i<cn2; i++){
func1(arr2[i]*10);
arrnm1[i]=m;
cout<<xtr1<<"\t";
}

delete [] arr2;

printf("\n\n");

    char* mk1 = new char[10];
    char* mk2 = new char[6];
    mk1=".\\snd\\";
    mk2=".wav";
    int n4;
    char buf[16];
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

int q2;

do{

for(int i=0; i<cn2; i++){
PlaySound(TEXT(arrstr2[i]),NULL,0);
}

printf("Reapet-1or0 ");
scanf("%d",&q2);
}while (q2==1);

delete [] arrstr2;

printf("Select note-1or0 ");
scanf("%d",&q1);
}while (q1==1);

delete [] arr1;
cn1=0;
cn2=0;

cin.sync();

printf("Select melody-1or0 ");
scanf("%d",&q3);
}while (q3==1);

 return 0;
}


func1 (int numid){    //float*10
switch (numid){
case 0: //-
m=0;
xtr1="X";
break;
case 10: //e0
m=10;
xtr1="e0";
break;
case 20: //f0
m=15;
xtr1="f0";
break;
case 25://#f0
m=18;
xtr1="#f0";
break;
case 30: //g0
m=20;
xtr1="g0";
break;
case 35://#g0
m=23;
xtr1="#g0";
break;
case 40:  //a0
m=25;
xtr1="a0";
break;
case 45:  //b0
m=28;
xtr1="b0";
break;
case 50: //h0
m=30;
xtr1="h0";
break;
case 60:  //c1
m=35;
xtr1="c1";
break;
case 65: //#c1
m=38;
xtr1="#c1";
break;
case 70: //d1
m=40;
xtr1="d1";
break;
case 75://#d1
m=43;
xtr1="#d1";
break;
case 80: //e1
m=45;
xtr1="e1";
break;
case 90: //f1
m=50;
xtr1="f1";
break;
case 95://#f1
m=53;
xtr1="#f1";
break;
case 100: //g1
m=55;
xtr1="g1";
break;
case 105://#g1
m=58;
xtr1="#g1";
break;
case 110:  //a1
m=60;
xtr1="a1";
break;
case 115:  //b1
m=63;
xtr1="b1";
break;
case 120: //h1
m=65;
xtr1="h1";
break;
case 130:  //c2
m=70;
xtr1="c2";
break;
case 135: //#c2
m=73;
xtr1="#c2";
break;
case 140: //d2
m=75;
xtr1="d2";
break;
case 145://#d2
m=78;
xtr1="#d2";
break;
case 150: //e2
m=80;
xtr1="e2";
break;
case 160: //f2
m=85;
xtr1="f2";
break;
case 165://#f2
m=88;
xtr1="#f2";
break;
case 170: //g2
m=90;
xtr1="g2";
break;
case 175://#g2
m=93;
xtr1="#g2";
break;
case 180:  //a2
m=95;
xtr1="a2";
break;
case 185:  //b2
m=98;
xtr1="b2";
break;
case 190: //h2
m=100;
xtr1="h2";
break;

default:
break;
}
 }

 func2 (int numit){
switch (numit){
case 4500:   //X
n1=0;
break;
case 101480: //e0
n1=1;
break;
case 102480: //f0
n1=2;
break;
case 3510248://#f0
n1=2.5;
break;
case 103480: //g0
n1=3;
break;
case 3510348://#g0
n1=3.5;
break;
case 97480:  //a0
n1=4;
break;
case 98480:  //b0
n1=4.5;
break;
case 104480: //h1
n1=5;
break;
case 99490:  //c1
n1=6;
break;
case 359949: //#c1
n1=6.5;
break;
case 100490: //d1
n1=7;
break;
case 3510049://#d1
n1=7.5;
break;
case 101490: //e1
n1=8;
break;
case 102490: //f1
n1=9;
break;
case 3510249://#f1
n1=9.5;
break;
case 103490: //g1
n1=10;
break;
case 3510349://#g1
n1=10.5;
break;
case 97490:  //a1
n1=11;
break;
case 98490:  //b1
n1=11.5;
break;
case 104490: //h1
n1=12;
break;
case 99500:  //c2
n1=13;
break;
case 359950: //#c2
n1=13.5;
break;
case 100500: //d2
n1=14;
break;
case 3510050://#d2
n1=14.5;
break;
case 101500: //e2
n1=15;
break;
case 102500: //f2
n1=16;
break;
case 3510250://#f2
n1=16.5;
break;
case 103500: //g2
n1=17;
break;
case 3510350://#g2
n1=17.5;
break;
case 97500:  //a2
n1=18;
break;
case 98500:  //b2
n1=18.5;
break;
case 104500: //h2
n1=19;
break;

default:
break;
}
 }
