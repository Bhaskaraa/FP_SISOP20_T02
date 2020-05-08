#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"


int main (int argc, char *argv[]){
	int fd;
	struct stat st;
	if((fd = open(argv[1], 0)) < 0){
   		printf(2, "tidak dapat membuka direktori %s\n", argv[1]);
   		exit();
  	}
  	if(fstat(fd, &st) < 0){
    		printf(2, "tidak dapat menampilkan %s\n", argv[1]);
    		close(fd);
    		exit();
  	}
	if(argc < 1){
        printf(1, "Argumen tidak teridentifikasi\n");
        exit();
    	}
	if(st.type == 2){
	printf(1, "tidak dapat menghapus\n",argv[1]);
	exit();
	}
	else {
		if(unlink(argv[1]) < 0){
			printf(1,"tidak dapat menghapus direktori karena tidak kosong\n",argv[1]);
			exit();		
		}
		else{
			unlink(argv[1]);
			exit();
		}		
	}
   
}