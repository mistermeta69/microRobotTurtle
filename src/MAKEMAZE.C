/*create a maze file*/
#include <stdio.h>
#include <dos.h>
#include <fcntl.h>
#include <sys\stat.h>
#define MAZESIZE 16
char maze[MAZESIZE][MAZESIZE+1];  /*our universe, bounded by a frame*/
void main()
    {
    int fp,i,j;
    char str[3];

    for (i=0;i<MAZESIZE;i++)
        {
        for (j=0;j<MAZESIZE;j++)
            if (i==0 || i==MAZESIZE-1 || j==0 || j==MAZESIZE-1)
               maze[i][j]='O';
            else
               maze[i][j]=' ';
        maze[i][MAZESIZE]='\n';
        }
    maze[MAZESIZE-1][MAZESIZE/2]='P';
    maze[MAZESIZE/2][MAZESIZE/2]=0x080;

    _fmode=O_TEXT;
    fp=creat("MAZE2",S_IWRITE|S_IREAD);
    if (fp==-1)
       printf("error opening file\n");

    write(fp,maze,MAZESIZE*(MAZESIZE+1));

    i=1; j=1;
    sprintf(str,"%2u\n",i);
    write(fp,str,strlen(str));
    sprintf(str,"%2u\n",j);
    write(fp,str,strlen(str));

    i=+1; j=+0;         /*x and y directions text mode*/
    sprintf(str,"%2u\n",i);
    write(fp,str,strlen(str));
    sprintf(str,"%2u\n",j);
    write(fp,str,strlen(str));
    close(fp);
    }