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
   int    i,                        // Bar Index
          Counted_bars;             // Number of counted bars
//--------------------------------------------------------------------
   Counted_bars=IndicatorCounted(); // Number of counted bars
      
   if(Bars<Range_n) return(0);
   i=Bars-Range_n;
   
   while(i>=0)                      // Loop for uncounted bars
   {
      
      int iHi=iHighest(NULL,0,MODE_HIGH,Range_n,i);        //Highest bar in n bars
      double xHig=iHigh(NULL,0,iHi);                  //Value of highest in n bars
      HiBuffer[i]=xHig;
     
      int iLo=iLowest(NULL,0,MODE_LOW,Range_n,i);          //Lowest bar in n bars
      double xLo=iLow(NULL,0,iLo);                    //Value of lowest in n bars
      LoBuffer[i]=xLo;     
    
     
      i--;
   }

   return(0);
  }
