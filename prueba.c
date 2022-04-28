#include <unistd.h>

int main()
{

	execlp("/bin/ls", "ls", "-l", NULL);
}
