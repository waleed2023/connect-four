LIBRARIES = -lm
TEST_LIBRARIES = 

CC := gcc -I. -Wall -pedantic
MAIN_BINARIES = $(basename $(wildcard 4.c gles_*.c))
TEST_BINARIES = $(basename $(wildcard *[Tt]est.c))
HEADERS = $(wildcard *.h)
OBJECTS = $(addsuffix .o, $(basename $(filter-out $(wildcard 4.c *[Tt]est.c gles_*.c), $(wildcard *.c))))
ASAN = ASAN_OPTIONS=print_legend=0:print_stats=0

.PRECIOUS: %.o
.SUFFIXES:
.PHONY: all sanitize debug release compile test checkstyle clean

all: sanitize test checkstyle

# sanitize is a personal compiler argument to detect problems that I don't see otherwise
# very useful to see overflows, use after free and other memory related issues
# keep in mind that it will make you're program around x2 slower
sanitize: CC += -g -fsanitize=address -fsanitize=undefined
sanitize: clean compile

# debug compiles with -g argment to debug with gdb or valgrind
debug: CC += -g
debug: clean compile

release: CC += -O3
release: clean compile

compile: $(MAIN_BINARIES) $(TEST_BINARIES)

test: $(TEST_BINARIES)
	for T in $(TEST_BINARIES); do $(ASAN) ./$$T; echo "$$T returned $$?"; done

checkstyle:
	python3 ./cpplint.py --repository=. --filter=-runtime/int,-readability/casting,-runtime/threadsafe_fn,-build/include_subdir,-build/include_what_you_use,-runtime/printf *.h *.c

clean:
	rm -f *.o
	rm -f $(MAIN_BINARIES)
	rm -f $(TEST_BINARIES)
	rm -f save

gles_%.o : gles_%.c $(HEADERS)
	$(CC) -std=c11 -c $<

gles_%: gles_%.o $(OBJECTS)
	$(CC) $^ -lGLESv1_CM -lglfw -o $@ $(LIBRARIES)

%ain: %ain.o $(OBJECTS)
	$(CC) -std=c11 -o $@ $^ $(LIBRARIES)

4: 4.o $(OBJECTS)
	$(CC) -std=c11 -o $@ $^ $(LIBRARIES)

%est: %est.o $(OBJECTS)
	$(CC) -std=c11 -o $@ $^ $(LIBRARIES) $(TEST_LIBRARIES)

%.o: %.c $(HEADERS)
	$(CC) -std=c11 -c $<
