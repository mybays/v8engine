#include <v8.h>
using namespace v8;

int main(int argc, char *argv[])
{
	const char * test = v8::V8::GetVersion();
	printf("version:%s\n",test);
	return 0;
}
