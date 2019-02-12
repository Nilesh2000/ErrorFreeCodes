# include <stdio.h>
# include <string.h>
# include <ctype.h>
int main()
{
  char s[100];
  int Upper=0, Lower=0;
  gets(s);
   for(int i=0;s[i]!='\0';i++)
    {
      if(isupper(s[i]))
       Upper++;
      else
       Lower++;
    }
   if(Upper>Lower)
    printf("%s\n", strupr(s));
   else
    printf("%s\n", strlwr(s));
  return 0;
}
