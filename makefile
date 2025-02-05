CC=gcc
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: append append_v2 copy dir lseek seek_io stdio_buf truncate write_bytes open read

append: append.c
append_v2: append_v2.c
copy: copy.c
dir: dir.c
lseek: lseek.c
seek_io: seek_io.c
stdio_buf: stdio_buf.c
truncate: truncate.c
write_bytes: write_bytes.c
open: open.c
read: read.c
write: write.c

clean:
	rm -f append
	rm -f append_v2
	rm -f copy
	rm -f dir
	rm -f lseek
	rm -f seek_io
	rm -f stdio_buf
	rm -f truncate
	rm -f write_bytes
	rm -f open
	rm -f read
	rm -f *.txt
	rm -f write

create:
	touch append.c
	touch append_v2.c
	touch copy.c
	touch dir.c
	touch lseek.c
	touch seek_io.c
	touch stdio_buf.c
	touch truncate.c
	touch write_bytes.c
	touch open.c
	touch read.c
	touch write.c
