// filename ******** fixed.h ************** 
// possible header file for Lab 1 Spring 2017
// feel free to change the specific syntax of your system
//Cooper Carnahan
//9/5/2017

#include <stdint.h>
#include "ST7735.h"

/****************ST7735_sDecOut3***************
 converts fixed point number to LCD
 format signed 32-bit with resolution 0.001
 range -9.999 to +9.999
 Inputs:  signed 32-bit integer part of fixed-point number
 Outputs: none
 send exactly 6 characters to the LCD 
Parameter LCD display
 12345    " *.***"
  2345    " 2.345"  
 -8100    "-8.100"
  -102    "-0.102" 
    31    " 0.031" 
-12345    " *.***"
 */ 
 
void ST7735_sDecOut3(int32_t n){
	char output_string[]=" *.***\n";
	int test;
	if((n<=9999 && n>=-9999)){
		if(n>-1) output_string[0]=' ';
		else output_string[0]='-';
	for(int i=5;i>0;i--){ //goes from the back of the fixed-point number to the front
		if(i!=2){
			test=abs(n%10);
			output_string[i]=(char)(test+48); //converts number to ASCII
			n/=10;
		}
		else output_string[i]='.';
	 }
  }
	ST7735_OutString(output_string);
		return;
}
/**************ST7735_uBinOut8***************
 unsigned 32-bit binary fixed-point with a resolution of 1/256. 
 The full-scale range is from 0 to 999.99. 
 If the integer part is larger than 256000, it signifies an error. 
 The ST7735_uBinOut8 function takes an unsigned 32-bit integer part 
 of the binary fixed-point number and outputs the fixed-point value on the LCD
 Inputs:  unsigned 32-bit integer part of binary fixed-point number
 Outputs: none
 send exactly 6 characters to the LCD 
Parameter LCD display
     0	  "  0.00"
     2	  "  0.01"
    64	  "  0.25"
   100	  "  0.39"
   500	  "  1.95"
   512	  "  2.00"
  5000	  " 19.53"
 30000	  "117.19"
255997	  "999.99"
256000	  "***.**"
*/
void ST7735_uBinOut8(uint32_t n); 

/**************ST7735_XYplotInit***************
 Specify the X and Y axes for an x-y scatter plot
 Draw the title and clear the plot area
 Inputs:  title  ASCII string to label the plot, null-termination
          minX   smallest X data value allowed, resolution= 0.001
          maxX   largest X data value allowed, resolution= 0.001
          minY   smallest Y data value allowed, resolution= 0.001 
          maxY   largest Y data value allowed, resolution= 0.001
 Outputs: none
 assumes minX < maxX, and miny < maxY
*/
int Y_Range;
int X_Range;
int max_X;
int min_X;
int max_Y;
int min_Y;

void ST7735_XYplotInit(char *title, int32_t minX, int32_t maxX, int32_t minY, int32_t maxY){
	Y_Range=maxY-minY;
	X_Range=maxX-minX;
	max_X=maxX;
	min_X=minX;
	max_Y=maxY;
	min_Y=minY;
	ST7735_SetCursor(0,0);
	ST7735_FillScreen(ST7735_BLACK);
	ST7735_OutString(title);
	ST7735_OutChar('\n');
	ST7735_FillRect(0, 32, 128, 128, ST7735_Color565(228,228,228));
	//ST7735_FillRect(minX, minY, (maxX-minX), (maxY-minY), ST7735_WHITE);
}
/**************ST7735_XYplot***************
 Plot an array of (x,y) data
 Inputs:  num    number of data points in the two arrays
          bufX   array of 32-bit fixed-point data, resolution= 0.001
          bufY   array of 32-bit fixed-point data, resolution= 0.001
 Outputs: none
 assumes ST7735_XYplotInit has been previously called
 neglect any points outside the minX maxY minY maxY bounds
*/
void ST7735_XYplot(uint32_t num, int32_t bufX[], int32_t bufY[]);



