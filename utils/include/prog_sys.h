#include <unistd.h>   /* sleep */
#include <signal.h>   /* signal */
#include <unistd.h>   /* sleep, alarm, fork */
#include <sys/wait.h> /* wait */
#include <sys/types.h> /* open */
#include <sys/stat.h> /* open */
#include <sys/mman.h>
#include <fcntl.h> /* O_WRONLY, O_RDONLY */
#include <pthread.h> /* pthread_t, pthread_create */
