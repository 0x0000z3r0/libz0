EXE=libz0

SRCDIR=src
INCDIR=inc
BLDDIR=bld

CFLAGS=-Wall -Wextra -fsanitize=leak,address,undefined

SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)%.c, $(BLDDIR)%.o, $(SRCS))

all: $(OBJS)
	mkdir -p $(BLDDIR)
	$(CC) $(OBJS) -shared -o $(BLDDIR)/$(EXE).so
	ar rcs $(BLDDIR)/$(EXE).a $(OBJS)

ifeq ($(Z0_DEBUG), y)
$(BLDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -I$(INCDIR) $(CFLAGS) -fPIC -c $< -o $@
else
$(BLDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -I$(INCDIR) -fPIC -c $< -o $@
endif

clean:
	rm $(OBJS)
