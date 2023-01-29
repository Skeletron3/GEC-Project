#include <unistd.h>

int main() {
	return execl("/bin/clear", "clear", NULL);
}