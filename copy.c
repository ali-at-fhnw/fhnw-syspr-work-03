#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024  // Puffergröße für das Kopieren

int main(int argc, char *argv[]) {

	// programm requires and only accepts two input argument
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return -1;
    }

    // open source file and get file descriptor
    int sourceFile = open(argv[1], O_RDONLY);
    if (sourceFile == -1) {
        perror("Error opening source file");
        return -1;
    } 

    //  open destination file, if existing, otherwise create it
    int destFile = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (destFile == -1) {
        perror("Error opening destination file");
        close(sourceFile);  // close soource, because it already is opened
        return -1;
    }

    // copy data content from source file to destination file
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    
    while ((bytesRead = read(sourceFile, buffer, BUFFER_SIZE)) > 0) {
        if (write(destFile, buffer, bytesRead) != bytesRead) {
            perror("Error writing to destination file");
            close(sourceFile);
            close(destFile);
            return -1;
        }
    }
    
    if (bytesRead == -1) {
        perror("Error reading source file");
    }

	char checkBuffer[BUFFER_SIZE];
	ssize_t checkBytes;
	while ((checkBytes = read(destFile, checkBuffer, BUFFER_SIZE)) > 0) {
    	if(write(STDOUT_FILENO, checkBuffer, checkBytes) != checkBytes) {
			perror("writing results from destination file to screen");
		}
	}	

	if (checkBytes == -1) {
    	perror("Error reading destination file");
	}

    // close source and destination files
	if (close(sourceFile) == -1)
    	perror("close source file");
    if (close(destFile) == -1)
        perror("close destination file");
    return 0;
}
