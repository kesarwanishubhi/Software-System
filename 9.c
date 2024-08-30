#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	struct stat FileStat;
	int fd=open("Hands-on List 1.pdf",O_RDONLY);
	if(fd==-1)
	{
		perror("Open ");
	}
	fstat(fd, &FileStat);
	printf("The information for the given file is: ");
	printf("-------------------------------------\n");
	printf("The inode number is %ld \n ",FileStat.st_ino);
	printf("Number of hard links is %ld \n ", FileStat.st_nlink);
	printf("Uid is %c \n", FileStat.st_uid);
	printf("gid is %c \n", FileStat.st_gid);
	printf("Total file size is %ld \n", FileStat.st_size);
	printf("Optimal block size of I/O is %ld \n", FileStat.st_blksize);
	return 0;
}