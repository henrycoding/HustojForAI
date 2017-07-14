#include <stdio.h>
#include <stdlib.h>

int main(){
  double a,b;
  while(scanf("%lf%lf",&a,&b)==2){
    printf("%f\n",a*b+0.005);
  }
  return 0;
}