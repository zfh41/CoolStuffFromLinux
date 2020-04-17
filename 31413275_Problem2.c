
#include <stdio.h> // contains I/O operations

#include <unistd.h> // contains getopt() function

#include <stdlib.h>


int main(int argc, char *argv[])

{

char opt;

while((opt = getopt(argc, argv, "f:s:cdu")) != -1)

{

switch(opt)
{
case 'c':
case 'd':
case 'u':
printf("Option: %c\n", opt);
break;

case 'f':

printf("Ignore Fields: %d\n", atoi(optarg));

break;
case 's':

printf("Ignore Chars: %d\n", atoi(optarg));

break;
        
case '?':

printf("unknown option: %c\n", optopt);

break;

}

}

for(; optind < argc; optind++){

printf("Extraneous arguments: %s\n", argv[optind]);

}

  

return 0;

}

