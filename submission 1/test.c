#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
Other include statements may be needed !
*/

int main()   { 


char path[50];
printf("Please enter your path\n");
scanf("%s",path);
char name[50];
printf("Please enter the directory name\n");

scanf("%s",name);

char pa[50];
strcpy(pa,path);
strcat(pa,"/");

strcat(pa,name);



// char * directoryName = argv[1];  /* Directory name to be created */

struct stat st = {0};


if (stat(pa, &st) == -1) {
    mkdir(pa, 0700);
}
else
{   int a;
	char final[300];
	for( a = 1; a < 20; a++){
	char s[200] ;
	char *str = pa;
    char buf[30];
    sprintf(buf,"%d",a);
    strcpy(final,pa);
    strcat(final,buf);
    printf("%s",final);

      if (stat(final, &st) == -1) {
	  
	   mkdir(final, 0700);
	   break;
	}
	}
}


	/*
		Rest of implementation goes here
	*/
	
}
