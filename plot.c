/* Plot data points to screen    */
/* A very simple demonstration of*/ 
/* the conio.o library.          */
/* Jan Klingel, 06/2026          */

#include <stdio.h>
#include <conio.h>

/* The next two lines are only   */
/* necessary for getScreenSize() */
#define SCREEN 0xffed
#define PLOT   0xfff0

#define CROSS 123
#define HBAR  96
#define VBAR  125

struct Scr {
  int xMax;
  int yMax;
};

/* drawCross() - draw a centered */
/* cross on the screen. This is  */
/* the x and y axis.             */ 
int drawCross(s) 
struct Scr *s;
{
  gotoxy(0,s->yMax/2);
  int i;
  for(i=0;i<s->xMax;i++)
    printf("%c", HBAR);

  for(i=0;i<s->yMax;i++) {
    gotoxy(s->xMax/2,i);
    printf("%c", VBAR);
  }

  gotoxy(s->xMax/2,s->yMax/2);
  printf("%c", CROSS);
  return(0);
}

/* getScreenSize() - get the size*/
/* of the screen. Should be 40x25*/
int getScreenSize(s) 
struct Scr *s;
{
  char a, x, y;
  sys (SCREEN, &a, &x, &y);
  s->xMax = (int) x;
  s->yMax = (int) y;
  return(0);
}

int main(void) {
  clrscr();
  framecolor(DGRAY);
  background(BLACK);
  textcolor(GREEN);
  setlowercase();

  struct Scr s;
  getScreenSize(&s);

  /* Hand the address of the     */
  /* struct over to the function */
  drawCross(&s);

  gotoxy(0,0);
  printf("f(x) = x*x/2");
  int x, y;
  for(x=-10;x<11;x++) {
    y=x*x/2;
    if(y<s.yMax/2) {
      gotoxy(x+s.xMax/2,s.yMax/2-y);
      printf("*");
    }
  }

  gotoxy(0,0);
  char exitP = getchar();

  return(0);
} 
