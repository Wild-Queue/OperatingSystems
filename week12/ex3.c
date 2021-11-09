#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//c = 46
//a = 30
//p = 25

//p = 25
//e = 18

//p = 25
//f = 33
//l = 38

static const char *const evval[5] = {
	"RELEASED",
	"PRESSED",
	"REPEATED"
};
int main (void)
{	
	printf ("Enter some of shortcuts to see the messege. Available shortcuts: \n P + E \n C + A + P \n P + F + L\n");
	const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	struct input_event ev;
	ssize_t n;
	int fd;
	
	fd = open(dev, O_RDONLY);
	if (fd == -1){
		fprintf(stderr, "Cannot open %s: %s, \n", dev, strerror(errno));
		return EXIT_FAILURE;
	}
	
	int Ptime=0, Etime = 0, Ctime= 0, Atime = 0, Ftime = 0, Ltime = 0;
	while (1) {
		n = read(fd, &ev, sizeof ev);
		if ((int )ev.code == 46){ // c
			Ctime = (int)ev.time.tv_sec;
		}
		
		if ((int )ev.code == 30){ // A
			Atime = (int)ev.time.tv_sec;
		}
		
		if ((int )ev.code == 33){ // F
			Ftime = (int)ev.time.tv_sec;
		}
		
		if ((int )ev.code == 25){ // P
			Ptime = (int)ev.time.tv_sec;
			if (Ctime == Atime && Atime == Ptime){
				printf(" Get some cappuccino!\n");
				Ptime=0, Etime = 0, Ctime= 0, Atime = 0, Ftime = 0, Ltime = 0;
			}
		}
		if ((int )ev.code == 18 ){ // E
			Etime = (int)ev.time.tv_sec;
			if (Ptime == Etime){
				printf(" I passed the Exam!\n");
				Ptime=0, Etime = 0, Ctime= 0, Atime = 0, Ftime = 0, Ltime = 0;
			}
		}
		
		if ((int )ev.code == 38){ //L
			Ltime = (int)ev.time.tv_sec;
			if (Ptime == Ftime && Ftime == Ltime) {
				printf(" Please, put full points for the lab :)\n");
				Ptime=0, Etime = 0, Ctime= 0, Atime = 0, Ftime = 0, Ltime = 0;
			}
		}
	}
	fflush(stdout);
	fprintf(stderr, "%s.\n", strerror(errno));
	return EXIT_FAILURE;
  return 0;
}
