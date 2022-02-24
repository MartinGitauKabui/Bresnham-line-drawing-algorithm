
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
class pixel
{
	protected:
		int xco,yco,color;

	public:
		pixel(){
		xco=0;yco=0;color=15;
	    }
		void drawcircle(int xc,int yc,int x,int y,int color){
	    putpixel(x+xc,y+yc,color);
	    putpixel(-x+xc,y+yc,color);
	    putpixel(x+xc,-y+yc,color);
	    putpixel(-x+xc,-y+yc,color);
	    putpixel(y+xc,x+yc,color);
	    putpixel(-y+xc,x+yc,color);
	    putpixel(y+xc,-x+yc,color);
	    putpixel(-y+xc,-x+yc,color);
	    }
};

class draw_circle: public pixel
{
	protected:
		int R;
	public:
		draw_circle(){
			R=0;
		}
		void drawBresen(int xc,int yc, int R);
};
void draw_circle::drawBresen(int xc,int yc,int R)
{
	for(int r=R;r>=0;r=r-20)
	{
		int x=0,y=r,p;
        p=3-2*R;
        while(x<=y)
        {
            pixel::drawcircle(xc,yc,x,y,color);
            if(p<0)
		    {

	            p=p+4*x+6;
	            x+=1;
            }
           else
            {
	            p=p+4*(x-y)+10;
	            y-=1;
	            x+=1;
            }
        delay(30);
        }

		color--;


    }
}


int main()
{
   clrscr();
   int gd=DETECT;
   int gm;
   int xc,yc,R;
   initgraph(&gd,&gm,"C:\\turboC3\\bgi");
   draw_circle Dc;
   cout<<"Enter radius: "<<endl;
   cin>>R;
   cout<<"Enter center: "<<endl;
   cin>>xc>>yc;
   Dc.drawBresen(xc,yc,R);
   getch();
   closegraph();
   return 0;
}
