EXE=libz0

SRCDIR=src
INCDIR=inc
BLDDIR=bld
TESTDIR=test
MODDIR=mod

CFLAGS=-Wall -Wextra -fsanitize=leak,address,undefined

SRCS=$(wildcard $(SRCDIR)/*.c)
HDRS=$(wildcard $(INCDIR)/*.h)
OBJS=$(patsubst $(SRCDIR)%.c, $(BLDDIR)%.o, $(SRCS))

.PHONY:lib
lib: $(OBJS) $(HDRS)
	mkdir -p $(BLDDIR)
	$(CC) $(OBJS) -shared -o $(BLDDIR)/$(EXE).so
	ar rcs $(BLDDIR)/$(EXE).a $(OBJS)

ifeq ($(Z0_DEBUG), y)
$(BLDDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h
	$(CC) -I$(INCDIR) $(CFLAGS) -fPIC -c $< -o $@
else
$(BLDDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h
	$(CC) -I$(INCDIR) -fPIC -c $< -o $@
endif

TESTSRCS=$(wildcard $(TESTDIR)/*.test.c)
TESTOBJS=$(patsubst $(TESTDIR)%.test.c, $(BLDDIR)%.test.o, $(TESTSRCS))

.PHONY:stub
stub: $(TESTDIR)/z0_stub.c $(TESTOBJS) lib
	$(CC) $(TESTOBJS) $< $(CFLAGS) -L$(BLDDIR) -l:$(EXE).a -o $(BLDDIR)/$@

$(BLDDIR)/%.test.o: $(TESTDIR)/%.test.c $(INCDIR)/%.h
	$(CC) -I$(INCDIR) $(CFLAGS) -c $< -o $@

MODSRCS=$(wildcard $(MODDIR)/*.c)
MODOBJS=$(patsubst $(MODDIR)%.c, $(BLDDIR)%.o, $(MODSRCS))

.PHONY:mod
mod:
	cp $(MODDIR)/z0_kmod.ko $(BLDDIR)/
	objcopy --add-section z0_mod=$(BLDDIR)/z0_kmod.ko --set-section-flags z0_mod=code,readonly $(BLDDIR)/z0_mod.o $(BLDDIR)/z0_mod.o

clean:
	rm -rf bld
	mkdir -p $(BLDDIR)
