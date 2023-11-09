
#include "problem1.h"


int main(int argc, char* argv[])
{
  
  double lin1[1];
  double * lin1_p = lin1;
  
  linspace(lin1_p, 1, 10, 1);
  linspace(lin1_p, 10, -10, 1);
  linspace(lin1_p, -10, 10, 1);
  
  double lin7[7];
  double * lin7_p = lin7;
  
  linspace(lin7_p, -7, 10, 7);
  linspace(lin7_p, -5, 5, 7);
  linspace(lin7_p, 10, 10, 7);
  
  double lin2[2];
  double * lin2_p = lin2;
  
  linspace(lin2_p, -7, 10, 2);
  linspace(lin2_p, -5, 5, 2);
  linspace(lin2_p, 10, 10, 2);
  
  double lin11[11];
  double * lin11_p = lin11;
  
  linspace(lin11_p, 10, 20, 11);
  
  return(0);
}

