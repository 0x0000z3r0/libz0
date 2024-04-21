EXE=libz0.so

SRCDIR=src
INCDIR=inc
BLDDIR=bld

CFLAGS=-Wall -Wextra -fsanitize=leak,address,undefined

SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)%.c, $(BLDDIR)%.o, $(SRCS))

all: $(OBJS)
	mkdir -p $(BLDDIR)
	$(CC) $(OBJS) -shared -o $(BLDDIR)/$(EXE)

$(BLDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -I$(INCDIR) $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm $(OBJS)
