#include <stdio.h>
#include <string.h>
main() {
  char str1[]="Though worlds of wanwood leafmeal lie";
  char str2[]="wanwood";
  char str3[]="wanwooD";
  char str4[]="wanwood";
  char *str;
  int icmp;
  printf("strlen(str1)=%d, str1='%s'\n",strlen(str1),str1);
  /* Add line here */
icmp=strcmp(str2,str3); 
  printf("str2='%s' str3='%s' strcmp(str2,str3)=%d\n",str2,str3,icmp);
  /* Add line here */
icmp=strcmp(str2,str4); 
  printf("str2='%s' str4='%s' strcmp(str2,str4)=%d\n",str2,str4,icmp);
  /* Add line here */
str=strstr(str1,str2); 
  printf("str1='%s' str2='%s' strstr(str1,str2)='%s'\n",str1,str2,str);
  /* Add line here */
str=strstr(str1,str3); 
  printf("str1='%s' str3='%s' strstr(str1,str3)='%s'\n",str1,str3,str);
}
    
    
