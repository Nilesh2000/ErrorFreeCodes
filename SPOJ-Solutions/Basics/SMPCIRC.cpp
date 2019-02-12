//Header Files
# include <iostream>
# include <math.h>

using namespace std;

int distanceSquare(int x1, int x2, int y1, int y2) //Function To Return The Distance Between The Centers Of The Two Circles
{
	int _X = x2-x1;
	int _Y = y2-y1;
	return  _X*_X + _Y*_Y ;
}

int diffSquare(int x, int y) //Function To Return The Value Of (r2-r1)^2 
{
	return (y-x) * (y-x) ;
}

int main() //Main Function
{
	int t, x1, x2, y1, y2, r1, r2;
        cin >>t; //Input Number Of Test Cases
	 while(t--)
     	 {
	  cin >>x1 >>y1 >>r1; //Input X Cordinate, Y Coordinate Of The Center And Radius Of The First Circle
	  cin >>x2 >>y2 >>r2; //Input X Cordinate, Y Coordinate Of The Center And Radius Of The Second Circle
		 
	   if(distanceSquare(x1,x2,y1,y2)<=diffSquare(r2,r1))
            {
	      if( distanceSquare(x1,x2,y1,y2)==diffSquare(r2,r1) )
		 cout <<"E" <<endl; //Print 'E' If Circle 1 Is Internally Tangent To Circle 2 Or Vice-Versa
	      else
         	cout <<"I" <<endl; //Print 'I' If Circle 1 Is Inside Circle 2
	    }
	  else
	   cout <<"O" <<endl; //Print 'O' For All Other Cases
	}
       return 0;
}
//Source
//https://github.com/varmas/SPOJ--C-Python--Java--etc..-/blob/master/15709/SMPCIRC.c
