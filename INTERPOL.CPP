#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<iomanip.h>
#include<process.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
int gd=DETECT,gm,i;
class database
{
	char nm[30];
	char dob[30];
	char onm[100];
	char oqu[100];
	char hight[5],weight[5];
	char prede[100],succ[100];
	char cri[1000];
	char stat[20];
	char rewrd[50];
	char captr[500];
	char wanted[50],wantdsc[10];
	char escp[100];
public:
void input()
{
	clrscr();
	cout<<"\n\tEnter Name: ";
	gets(nm);
	cout<<"\n\tEnter deat of birth: ";
	gets(dob);
	cout<<"\n\tEnter other name:";
	gets(onm);
	cout<<"\n\tEnter occupations:";
	gets(oqu);
	cout<<"\n\tEnter height: ";
	gets(hight);
	cout<<"\n\tenter weight:";
	gets(weight);
	cout<<"\n\tEnter predecessor:";
	gets(prede);
	cout<<"\n\tEnter successor:";
	gets(succ);
	cout<<"\n\tEnter criminal charges:";
	gets(cri);
	cout<<"\n\tEnter criminal status:";
	gets(stat);
	cout<<"\n\tEnter reward amount:";
	gets(rewrd);
	cout<<"\n\tEnter capture status:";
	gets(captr);
	cout<<"\n\tEnter wanted by:";
	gets(wanted);
	cout<<"\n\tEnter wanted since:";
	gets(wantdsc);
	cout<<"\n\tEnter escape record:";
	gets(escp);
}
void display()
{
	cout<<"\n\t\t            Name:"<<nm;delay(50);
	cout<<"\n\t\t          Height:"<<hight;delay(50);
	cout<<"\n\t\t          Weight:"<<weight;delay(50);
	cout<<"\n\t\t   Deat of Birth:"<<dob;   delay(50);
	cout<<"\n\t\t      Other Name:"<<onm;   delay(50);
	cout<<"\n\t\t     Occupations:"<<oqu;   delay(50);
	cout<<"\n\t\t     Predecessor:"<<prede; delay(50);
	cout<<"\n\t\t       Successor:"<<succ;  delay(50);
	cout<<"\n\t\tCriminal Charges:"<<cri;   delay(50);
	cout<<"\n\t\t Criminal Status:"<<stat;  delay(50);
	cout<<"\n\t\t   Reward Amount:"<<rewrd; delay(50);
	cout<<"\n\t\t   Cpture Status:"<<captr; delay(50);
	cout<<"\n\t\t       Wanted by:"<<wanted;delay(50);
	cout<<"\n\t\t    Wanted Since:"<<wantdsc;delay(50);
	cout<<"\n\t\t   Escape Record:"<<escp;   delay(50);
	getch();
}
char* getnm()
{	return nm;
}
void report()
{
cout<<setw(20)<<nm<<setw(15)<<hight<<setw(15)<<weight<<endl;
}
};
void loading()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	setcolor(WHITE);
	outtextxy(260,220,"Loading Database....");
	setcolor(RED);
	line(250,240,300,240);
	line(230,245,280,245);
	line(250,240,230,245);
	line(300,240,280,245);
	delay(1000);
	setcolor(YELLOW);
	line(320,240,370,240);
	line(300,245,350,245);
	line(320,240,300,245);
	line(370,240,350,245);
	delay(1000);
	setcolor(GREEN);
	line(390,240,440,240);
	line(370,245,420,245);
	line(390,240,370,245);
	line(440,240,420,245);
	delay(1000);
}
void delet()
{
	int gd=DETECT,gm,k;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	setcolor(RED);
	outtextxy(240,242,"Deleting record.....");
	delay(500);
	for(k=0;k<200;k++)
	{
		line(220+k,260,220+k,270);
		delay(50);
	}
	delay(1000);
}
void storeinfo()
{
	clrscr();
	ofstream file("Indian interpole.dat",ios::binary|ios::app);
	database d;
	int i,n;
	cout<<"\n\tEnter criminal Record.........";
	d.input();
	file.write((char*)&d,sizeof(d));
	file.close();
}
void displayinfo()
{
	clrscr();
	ifstream file("Indian interpole.dat",ios::binary);
	database d;
	cout<<"\n\t\t\t---------------";
	cout<<"\n\t\t\t|CRIMINAL LIST|";
	cout<<"\n\t\t\t---------------\n";
	cout<<"\n==========================================================================\n";
	cout<<setw(20)<<"Name"<<setw(15)<<"Height"<<setw(15)<<"Weight"<<endl;
	while(file.read((char*)&d,sizeof(d)))
{
	d.report();
}
	file.close();
}
void searchinfo()
{

	ifstream file("Indian interpole.dat",ios::binary);
	database d;
	char nmm[40];
	int f=0;
	cout<<"\n\tEnter Criminal name whose detail you want to search..................";
	gets(nmm);
	while(file.read((char*)&d,sizeof(d)))
{
	if(strcmpi(d.getnm(),nmm)==0)
{
	clrscr();
	loading();
	closegraph();
	clrscr();
	int i;
	char in[]={"DETAILS ABOUT THE CRIMINAL U R LOOKING FOR"};
	cout<<"\n\t\t";
	for(i=0;i<43;i++)
	{
		cout<<in[i];
		delay(50);
	}
	cout<<"\n";
	d.display();
	f=1;
}
}
	if(f==0)
{
	cout<<"\n\tRecord not found.........";
}
	getch();
	file.close();
}
void deleteinfo()
{
	clrscr();
	ifstream file("Indian interpole.dat",ios::binary|ios::app);
	database d; char ch;
	int f=0;
	char nmm[40];
	ofstream file1("temp.dat",ios::binary|ios::app);
	cout<<"\n\tEnter name of criminal to be deleted........";
	gets(nmm);
	if(nmm[0]==' ')
{
	cout<<"Plese enter any data";
}
	else
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	setcolor(RED);
	rectangle(150,140,480,280);
	rectangle(150,140,480,170);
	outtextxy(185,155,"!!!!!!!!!!!ATTENTION!!!!!!!!!!!!");
	outtextxy(180,190,"Do you realy want to delete this");
	outtextxy(180,204,"record?????");
	outtextxy(185,252,"Yes");
	outtextxy(430,252,"No");
	rectangle(180,245,215,265);
	rectangle(420,245,455,265);
	for(int l=0;l<18;l++)
	{
		cout<<"\n";
	}
	cout<<"\t\t\tEnter your choice (Y/N)......";
	cin>>ch;
}
	if(ch=='y'||ch=='Y')
{
	while(file.read((char*)&d,sizeof(d)))
{
	if(strcmpi(d.getnm(),nmm)!=0)
	{
	file1.write((char*)&d,sizeof(d));
	}
	else
	f=1;
}
	file.close();
	file1.close();
	if(f==1)
{
	clrscr();
	delet();
	clrscr();
	closegraph();
	remove("Indian interpole.dat");
	rename("temp.dat","Indian interpole.dat");
	cout<<"\n\n\n\n\n\n\n\n\t\t\tRecord deleted........";
}
	if(f==0)
{
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\t\t\tRecord not found.......";
	remove("tamp.dat");
}
}
getch();
}
void modifyinfo()
{
	clrscr();
	fstream file("Indian interpole.dat",ios::binary|ios::in|ios::out);
	database d;
	char nmm[40];
	int pos=-1;
	cout<<"\n\n\n\tEnter criminal name to be modified...............";
	gets(nmm);
	while(file.read((char*)&d,sizeof(d)))
{
	if(strcmpi(d.getnm(),nmm)==0)
{
	pos=file.tellg()-sizeof(d);
	break;
}
}
	if(pos>=0)
{
	file.seekp(pos);
	cout<<"Enter new data......";
	d.input();
	file.write((char*)&d,sizeof(d));
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\tModified successfully.......";
}
	else
	cout<<"Record not found";
	getch();
	file.close();
}

void exit()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	int x=460,y=350;
	int v2=0,num=0,n=0;
	while(1)
	{
		cleardevice();
		outtextxy(60,10,"THANK YOU FOR USING VIRTUAL INTERPOLE");
		outtextxy(65,25,"MADE BY:- JAY SHANKAR ");
		outtextxy(x,y,"loging out");
		setlinestyle(0,0,3);
		setcolor(BLUE);
		arc(x,y,270+v2,90+v2,20);
		if(num>=100)
		{
		       exit(0);
		}
		v2+=6+rand()%8;
		randomize();
		num=num+n;
		n=rand()%2;
		delay(30);
}
}
void menu()
{
	start:
	closegraph();
	clrscr();
	int gd=DETECT,gm,i,j,k,a;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	setcolor(LIGHTBLUE);
	for(i=0;i<10;i++)
	{
	rectangle(0+i,0+i,630+i,470+i);
	}
	setcolor(BLUE);
	for(j=0;j<3;j++)
	{
	line(10,100+j,50,100+j);
	line(51-j,103-j,100-j,70-j);
	line(97,67+j,200,67+j);
	line(97,137+j,200,137+j);
	line(51,103-j,97,140-j);
	line(200,67+j,240,100+j);
	line(200,137+j,240,100+j);
/*****************************************************************************/
	line(580,100+j,630,100+j);
	line(580,103-j,530,70-j);
	line(427,67+j,530,67+j);
	line(427,137+j,530,137+j);
	line(530,137+j,580,100+j);
	line(427,67+j,380,100+j);
	line(380,100+j,427,137+j);
/**************************************************************************/
		line(580,300+j,630,300+j);
		line(580,300+j,530,267+j);
		line(427,267+j,530,267+j);
		line(427,337+j,530,337+j);
		line(530,337+j,580,300+j);
		line(427,267+j,380,300+j);
		line(380,300+j,427,337+j);
/////////////////////////////////////////////////////////////////////////////
	line(10,400+j,230,400+j);
	line(410,400+j,630,400+j);
	line(230-j,403-j,270-j,370-j);
	line(267,367+j,370,367+j);
	line(267,437+j,370,437+j);
	line(230,403-j,267,440-j);
	line(370,367+j,410,400+j);
	line(410,403-j,370,440-j);
//////////////////////////////////////////////////////////////////////
	line(10,300+j,50,300+j);
	line(50,300+j,100,270+j);
	line(50,300+j,100,337+j);
	line(100,270+j,203,270+j);
	line(100,337+j,203,337+j);
	line(203,270+j,253,300+j);
	line(203,337+j,253,300+j);
///////////////////////////////////////////////////////////////////////
	setlinestyle(0,0,3);
	rectangle(150,200,450,230);
	}
	setcolor(WHITE);
	outtextxy(110,100,"1.ENTER");
	outtextxy(290,400,"5.EXIT");
	outtextxy(455,100,"2.DISPLAY");
	outtextxy(455,300,"4.MODIFY");
	outtextxy(110,300,"3.DELETE");
	gotoxy(25,14);
	cout<<"Enter your choice:  ";
	cin>>a;
closegraph();
	switch(a)
{
	case 1:
		storeinfo();
		break;
	case 2:
		displayinfo();
		searchinfo();
		break;
	case 3:
		deleteinfo();
		break;
	case 4:
		modifyinfo();
		break;
	case 5:
		exit();
		exit(0);
		break;
	default:
		cout<<"invalid choice";
}
goto start;
}
void flag()
{
int i;
for(i=1;i<=100;i++)
{
clrscr();
setcolor(LIGHTRED);
line(400-i,100,500-i,200); //long line 1
line(400-i,100,420-i,130); //short line 1
line(420-i,130,520-i,230); //long line 2
line(500-i,200,520-i,230); //short line 2
setcolor(WHITE);
line(225+i,155,120+i,260); //long line 3
line(225+i,155,210+i,180); //short line 3
line(210+i,180,109+i,281); //long line 4
line(120+i,260,109+i,281); //short line 4
setcolor(GREEN);
line(250,360-i,455,360-i); //long line 6
line(285,353-i,480,353-i); //long line 5
line(285,353-i,250,360-i); //short line 5
line(480,353-i,455,360-i); //short line 6
delay(20);
}
setcolor(GREEN);
outtextxy(280,290,"INDIAN INTERPOLE");
setcolor(BLUE);
circle(340,210,35);
line(340,210,375,210);
line(340,210,340,245);
line(305,210,340,210);
line(340,175,340,210);
line(340,210,365,235);
line(340,210,315,235);
line(365,185,340,210);
line(315,185,340,210);
line(340,210,373,224);
line(340,210,354,241);
line(340,210,327,241);
line(340,210,309,224);
line(308,198,340,210);
line(326,179,340,210);
line(354,178,340,210);
line(372,196,340,210);
}
void countdown()
{
	int a;
	a=10;
	//scanf("%",&a);
	while(a!=0)
{
	cout<<"\n\n\n\n\n\t\tYou you will be directed to main page within";
	printf("\n\n\n\n\t\t\t\t00:%d",a);
	a--;
	delay(1000);
	clrscr();
}
}
void main()
	{
		int m=0;
		for(m=0;m<5;m++)
		{
		clrscr();
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"C:\\turboc3\\BGI");
		int i;
		clrscr();
		flag();
		char st[50];
		setcolor(WHITE);
		int maxx=getmaxx();
		outtextxy(290,maxx-300,"ENTER PASSWORD");


		for(i=0;i<50;i++)
	{
		st[i]=getch();
		if(st[i]==13)
		break;
		else
		outtextxy(290+(i*10),maxx-280,"  *  ");
	}
		st[i]='\0';
		if(strcmpi(st,"10125")==0)
	{
		m=0;
		closegraph();
		menu();
	}
		if(m==2)
		{
			remove("Indian interpole.dat");
			closegraph();
			exit(0);
		}
		else
	{
		closegraph();
		countdown();
	}


closegraph();
}
}