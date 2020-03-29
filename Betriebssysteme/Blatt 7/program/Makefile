BIN_LS = myls
INCDIR = ./include/
LIBDIR  = ./lib/
SRCDIR     = ./
CFLAGS     = -Wall -Werror -Wpedantic -g -I$(INCDIR)
LDFLAGS = 

all: $(OBJFILES) | $(BIN_LS)

$(BIN_LS): $(SRCDIR)/$(BIN_LS).o
	gcc -o $@ $^ $(LDFLAGS)


# object files
%.o: %.c
	gcc -c -o $@ $(CFLAGS) $^

.PHONY: clean
clean:
	$(RM) $(BIN_SIMPLE)
	$(RM) $(wildcard $(SRCDIR)*.o)
	$(RM) $(wildcard $(LIBDIR)*.o)
	$(RM) *.html