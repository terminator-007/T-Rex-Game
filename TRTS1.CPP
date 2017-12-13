
#include<fstream.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>

int lb=225,ub;  //lower and upper bound for trex jumping up

int lb1,ub1;        //lower and upper bound for cactus

int lb2,ub2;        //lower and upper bound for trex jumping down

int t1,t2,t3,t4,flag=0,ran,sc=0;  //to check if the coordinates overlap


class trex

{   public:

     int l,t,r,b, u,v,w,z, l1,t1,r1,b1, i,j;

  trex()
  {
   u=199;l=199;l1=199;
   v=217;t=217;t1=217;
   w=199;r=199;r1=199;
   z=239;b=239;b1=239;
  }

  void tail();
  void body();
  void head();
  void legs();
  void cactus();
  void jumpup();
  void jumpdown();
  void cacmove();
  void road();
  //int rndm();

}din,cac;


struct scorehistory
{
 int score;

}hs;

  void draw(trex t,int color);

  void cacd(trex t,int color);

/*
  int trex::rndm()
{ randomize();
   ran=random(7-2)+1;
   return ran;  }
*/


//Draws trex's tail in terms of (l, t, r, b)

  void trex::tail()

{   bar(u,v,w,z);
    for(l=u+1,t=v+3,r=w+3,b=z+1;l<u+6;l++,t++,r++,b++)
     bar(l,t,r,b);
}


//Draws trex's body

  void trex::body()

{  for(l=u+6,t=v+7,r=w+21,b=z+5;l<u+13;l+=2,t-=2,r+=2,b-=2)
    bar(l,t,r,b);
}

//Draws trex's head

  void trex::head()

{ l=u+14,t=v-7;r=w+29,b=z-21;

  bar(l,t,r,b);
   bar(l+1,t-5,r+7,b-3);
    bar(l+3,t-7,r+5,b-3);
     bar(l+3,t+8,r+7,b+2);
}


//Draws trex's legs

  void trex::legs()

{ l=u+13,t=v+30;r=w+14,b=z+16;

  bar(l,t-2,r,b);
   bar(l+9,t-5,r+9,b);
    bar(l,t+7,r+2,b);
     bar(l+9,t+7,r+11,b);
}


//The grey road

  void trex::road()

{ setfillstyle(1,8);
   bar(0,256,640,258);
}


//Cactus in terms of different variables(l1, t1, r1, b1)

  void trex::cactus()

{
    bar(l1+121,t1-15,r1+124,b1+16);
   bar(l1+124,t1+11,r1+134,b1-7);
    bar(l1+121,t1+23,r1+111,b1+5);
     bar(l1+131,t1-6,r1+134,b1-7);
      bar(l1+111,t1+3,r1+114,b1+5);
}


//Trex jumps up, Calls the trex combined draw function

  void trex::jumpup()
{
  //Assigning left,top,right,bottom(u,v,w,z)


    din.u=50;
    din.w=50;

   for(i=lb;i>ub;i--)
{   din.z=i+14;
    din.v=i-8;

    draw(din,15);
    delay(ran);
    draw(din,0);

    cac.l1=lb1;
    cac.r1=lb1;

    lb1-=1;
    ub1-=1;

    cacd(cac,10);
    cacd(cac,0);
    cacd(cac,10);
    cacd(cac,0);


    if (cac.l1 <= -20 && cac.l1 > -60)
     {
	if (din.z >= cac.t1)
       {
		flag=1;
       }
	else
       {
		flag=0; sc++;
       }
     }

}
   draw(din,15);

   lb=lb-19;
   ub=ub-20;
}


//Trex jumps down, Calls the trex combined draw function

  void trex::jumpdown()
{
  //Starting from the top position where jump up left off


   lb2=din.v;

  for(i=din.v;i<ub2;i++)
{
   din.v=i-4;
   din.z=i+18;

   setfillstyle(1,15);

   draw(din,15);
   delay(ran);
   draw(din,0);

   cac.l1=lb1;
   cac.r1=lb1;

   lb1-=1;
   ub1-=1;

   cacd(cac,10);
   cacd(cac,0);
   cacd(cac,10);
   cacd(cac,0);


   if (cac.l1 <= -20 && cac.l1 > -60)
    {
	if (din.z >= cac.t1)
       {
		flag=1;
       }
	else
       {
		flag=0; sc++;
       }
    }
}

   draw(din,15);

   lb2+=21;
   ub2+=20;
}


//Cactus moves right to left, Calls the cactus draw function

  void trex::cacmove()
{
  //lb1,ub1 declared in main


  for(i=lb1;i>=ub1;--i)
{
   cac.l1=i;
   cac.r1=i;

   cacd(cac,10);
   delay(ran);
   cacd(cac,0);

}
   cacd(cac,10);

   lb1-=20;
   ub1-=20;

   if (cac.l1 <= -20 && cac.l1 > -40)
  {
	flag=1;
  }
}


//One function to draw all the body parts and to change colour between black and while

  void draw(trex t, int color)
{
   setfillstyle(1,color);
   t.tail();
   t.head();
   t.body();
   t.legs();
   t.road();

}



//Function to draw the cactus and to change colour between black and green


  void cacd(trex t, int color)

{  setfillstyle(1,color);
   t.cactus();
}

 void box()
{
   setfillstyle(1,1);
bar(0,0,10,480);
bar(0,0,640,10);
bar(630,0,640,480);
bar(0,470,640,480);       }

  void main()
{
   clrscr();
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

   int i,j,r,clr,rcc=0,temp;
   char ch,csc[50],chs[50];
   fstream f("score.dat",ios::app|ios::binary);

   lb=225;  ub=205;
   lb1=640; ub1=620; ub2=144;


    box();
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    setcolor(RED);
    outtextxy(160,220,"TREX RUNNER");
    delay(1000);
    getch();
    cleardevice();


    box();
    setcolor(12);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    outtextxy(155,70,"INSTRUCTIONS");
    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(25,160,"Save the Trex from the cactus.");
    outtextxy(25,200,"Press space to jump.");
    outtextxy(25,240,"Click 'esc' to exit.");
    outtextxy(25,280,"Score is calculated based on how long");
    outtextxy(25,320,"the Trex survives.");
    outtextxy(25,360,"Press any key to start.");
    outtextxy(150,400, "Enjoy the game!");
    delay(1000);
    getch();
    cleardevice();


    box();
    setcolor(6);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    outtextxy(185,200,"LOADING...");
    setcolor(15);
    rectangle(40,299,600,336);


    for(i=41;i<599;i+=2)

{    clr=random(15-1)+1;
     setcolor(clr);
     delay(10);
     rectangle(i,300,i+1,335);                 //game loading bar
     i++;
}

    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    delay(1000);
    cleardevice();

    box();
    setcolor(5);
    outtextxy(200,240,"Get Ready");
    delay(1000);
    cleardevice();

    box();
    setcolor(5);
    outtextxy(300,240,"3");
    delay(1000);
    cleardevice();

    box();
    setcolor(CYAN);
    outtextxy(300,240,"2");             //startup
    delay(1000);
    cleardevice();
    box();

    setcolor(GREEN);
    outtextxy(300,240,"1");
    delay(1000);
    cleardevice();
    box();

    setcolor(13);
    outtextxy(297,240,"GO");
    delay(1000);
    closegraph();




   initgraph(&gd, &gm, "C:\\TurboC3\\bgi");



 din.u=50;
 din.w=50;
 din.v=217;
 din.z=239;

 din.road();


draw(din,15);

while (ch!=27)
{
   flag=0;lb1=640; ub1=620;

while(flag==0 && ch!=27)
{ randomize();
  ran=random(6-2)+1;

  if (lb1 < -40)
  {
   lb1=640; ub1=620; ub2=144;
  }

if(kbhit())

{
  ch=getch();

 if (ch == 32)
 {
   lb=225;  ub=205; ub2=144;

   for(i=0;i<5;i++)
   {
    din.jumpup();
    draw(din,15);
   }

   for(i=0;i<5;i++)
   {
    din.jumpdown();
    draw(din,15);
   }

 }

  if (ch == 27)
  {
    break;
  }


}
  else
  {
    draw(din,15);
    cac.cacmove();
  }

//cout << int(ch);

} //while loop 2

    setcolor(2);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,6);
    outtextxy(220,90,"GAMEOVER!");


    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    setcolor(14);
    outtextxy(155,0,"Press a key to start playing again or Esc to quit");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(6);
    outtextxy(155,60,"SCORE");
    gotoxy(190,120);
    itoa(sc,csc,10);
    setcolor(11);
    outtextxy(390,60,csc);
    hs.score=sc;

    f.write((char*)&hs,sizeof(hs));


    ch=getch();
    delay(10);
    if(ch==27)
    {
     break;
    }

    sc=0;
    cleardevice();



} //while loop 1


f.close();

//cout << "Out of loops";
i=0; rcc=0;

f.open("score.dat",ios::in|ios::binary);

while(f.read((char*)&hs,sizeof(hs)))
{
	rcc++;
}

f.close();

int *scar;

scar = new int[rcc];

f.open("score.dat",ios::in|ios::binary);

i=0;

while(f.read((char*)&hs,sizeof(hs)))
{

	scar[i++]=hs.score;
}


//cout << "Records:" << int(rcc);

for(i=0;i<rcc;i++)
{
	for(j=0;j<rcc-i-1;j++)
	{
		if(scar[j]<scar[j+1])
		{
			temp=scar[j];
			scar[j]=scar[j+1];
			scar[j+1]=temp;
		}
	}
}


f.close();




//cout <<'\t'<<'\t'<<'\t'<<'\t'<< scar[0];

settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(6);
    outtextxy(155,30,"HIGHEST SCORE");
    gotoxy(155,110);
    itoa(scar[0],chs,10);
    setcolor(11);
    outtextxy(390,30,chs);

getch();

}