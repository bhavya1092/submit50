#include<stdio.h>

void triangle(int n)                                                          {
  if (n>1 && n<23)                                                            {
    for (int i=2; i < (n+2); i++)                                             {
      for (int j=0; j < (n+1-i); j++)                                         {
        printf(" ")                                                           ;
                                                                              }
      for (int j=1; j <= i; j++)                                              {
        printf("#")                                                           ;
                                                                              }
      printf("\n")                                                            ;
                                                                              }
                                                                              }
                                                                              }

int main()                                                                    {
  int height                                                                  ;
  do                                                                          {
    printf("Height: ")                                                        ;
    scanf("%d", &height)                                                      ;
  } while(height>1 && height<24)                                              ;
  triangle(height)                                                            ;
  return 0   