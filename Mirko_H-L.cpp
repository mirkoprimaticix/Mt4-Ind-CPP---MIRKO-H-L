#property copyright "Copyright © 2019, Mirko Primatici."

#property indicator_chart_window
#property indicator_buffers 2
#property indicator_color1 DarkBlue
#property indicator_color2 DarkBlue

extern int       Range_n=20; //Customizable 


double HiBuffer[],LoBuffer[];

int init()
  {
   SetIndexBuffer(0,HiBuffer);
   SetIndexStyle(0,DRAW_LINE,2,1);
   SetIndexLabel(0, "Highest(" + DoubleToStr(Range_n,0)+")");

   SetIndexBuffer(1,LoBuffer);
   SetIndexStyle(1,DRAW_LINE,2,1);
   SetIndexLabel(1, "Lowest(" + DoubleToStr(Range_n,0)+")");
  

   return(0);
  }

int deinit()
  {

  
  }

int start()
  {
   
   return(0);
  }
