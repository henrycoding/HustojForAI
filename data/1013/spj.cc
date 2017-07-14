#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *args[])
{
  FILE *f_in=fopen(args[1],"r");
  FILE *f_out=fopen(args[2],"r"); 
  FILE *f_user=fopen(args[3],"r"); 
  int ret=0;
  double a,b,c;
  while(fscanf(f_in,"%lf%lf",&a,&b)==2) {
    fscanf(f_user,"%lf",&c);
    if(abs(c-a*b)>0.1)
    { ret = 1; }//Wrong Answer
  }
  fclose(f_in);
  fclose(f_out);
  fclose(f_user);
  return ret;
}