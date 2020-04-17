#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_FILENAME 256

void ProDirectory(char *);
void examineFile(char *, struct dirent * );
void SwapV(struct myFile *, struct myFile *);
void bSort(struct myFile arr[], int ) ;
void PrintArr(struct myFile arr[], int ) ;
void main(int , char *argv[]);

struct myFile
{
unsigned long long size;
char * name;
};

struct myFile fileList[7000];
int d = 0;
void ProDirectory(char *dirName) {
int charsRead;
     DIR *dir;
struct dirent *dirEntry;
char fileName[MAX_FILENAME];
     dir=opendir(dirName);
    
while( 1 ) {
dirEntry = readdir(dir);
if ( dirEntry == NULL )
break;
if ( strcmp(dirEntry->d_name, ".") != 0 &&
strcmp( dirEntry->d_name, "..") != 0) {
sprintf( fileName, "%s/%s", dirName,
                        dirEntry->d_name );
examineFile( fileName, dirEntry );
}
}
closedir(dir);
}
void examineFile(char *fileName, struct dirent *dirEntry ) {/*Process a myFile/Directory */
mode_t type;
int Value;
struct stat statBuf;
Value = lstat(fileName, &statBuf);
return;
}
type = statBuf.st_mode; /* Mode of myFile */
if ( S_ISDIR( type ) ) /* Directory */
ProDirectory( fileName );
else if(S_ISREG(type))
{
char *path = realpath(fileName, NULL);
fileList[d].size = (unsigned long long)statBuf.st_size;
fileList[d].name = path;
d++;
}
}
/*function will swap the x,y value*/
void SwapV(struct myFile *xpoint, struct myFile *ypoint)
{
    struct myFile temp = *xpoint;
    *xpoint = *ypoint;
    *ypoint = temp;
}

void bSort(struct myFile arr[], int n)
{
   for (int i = 0; i < n-1; i++)
       // Last elements i are already set into the place
       for (int j = 0; j < n-i-1; j++)
           if (arr[j].size > arr[j+1].size)
              SwapV(&arr[j], &arr[j+1]);
}
 
/*  Function will print an array */
void PrintArr(struct myFile arr[], int size)
{
    for (int i=0; i < size; i++)
        printf("%llu\t%s\n", arr[i].size, arr[i].name);
}

void main(int argc, char *argv[])
{
    char * folder = argv[1];
ProDirectory(folder);
bSort(fileList, d);
    PrintArr(fileList, d);
}
