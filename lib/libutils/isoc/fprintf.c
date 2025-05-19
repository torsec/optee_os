#include <stdio.h>
#include <printk.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int fprintf(FILE *stream, int flag, const char *format, ...)
{
	char buffer[MAX_BUFFER_SIZE];
	int length=0;

	va_list args;
	va_start(args, format);

	length = vsnprintf(buffer, MAX_BUFFER_SIZE, format, args);

	va_end(args);

	if(length < 0){
		return -1;
	}

	if(length > MAX_BUFFER_SIZE){
		return -1;
	}

	int written = fwrite(buffer, 1, length, stream);
	if(written != length){
		return -1;
	}

	return length;
}
