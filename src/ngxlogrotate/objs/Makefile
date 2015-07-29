
CC =		cc
CFLAGS = -pipe  -O -W -Wall -Wpointer-arith -Wno-unused-parameter -Werror -g
LINK = $(CC)

CORE_DEPS =  \
	src/ngxlogrotate.h \
	src/nlr_file.h \
	src/nlr_date.h

CORE_INCS = -I src \
	-I objs


objs/ngxlogrotate:	objs/src/ngxlogrotate.o \
	objs/src/nlr_file.o \
	objs/src/nlr_date.o
	$(LINK) -o objs/ngxlogrotate \
	objs/src/ngxlogrotate.o \
	objs/src/nlr_file.o \
	objs/src/nlr_date.o
	



objs/src/ngxlogrotate.o:	$(CORE_DEPS) \
	src/ngxlogrotate.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-o objs/src/ngxlogrotate.o \
		src/ngxlogrotate.c


objs/src/nlr_file.o:	$(CORE_DEPS) \
	src/nlr_file.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-o objs/src/nlr_file.o \
		src/nlr_file.c


objs/src/nlr_date.o:	$(CORE_DEPS) \
	src/nlr_date.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-o objs/src/nlr_date.o \
		src/nlr_date.c

