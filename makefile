include ../comm.mk

PWD=$(shell pwd)

#local paths
OBJPATH = $(PWD)/obj

SRCPATH = $(PWD)/src

INCPATH = -I$(PWD)/inc

RELEASE_PATH=$(PWD)/release

#FILES = main.cpp add_int.cpp add_float.c sub_float.cpp sub_int.c
FILES = SocketCli.cpp

#output
BINS = main

LIBS = 
#LogReceive.so

# objs
OBJS := $(FILES:%.cpp=%.o)
OBJS := $(OBJS:%.c=%.o)
OBJSWITHPATH := $(addprefix $(OBJPATH)/,$(OBJS))

CPPWITHPATH := $(addprefix $(SRCPATH)/,$(FILES))

BINSOBJ:=$(addsuffix .o,$(BIN))
#BINSOBJ:=$(addprefix $(OBJPATH)/,$(BINSOBJ)) 
#LIBSOBJ:=$(addsuffix)

#global paths and libs
GLIBINC:=
GLIBLINK:= 

.PHONY: dircheck all clean pub
all:dircheck $(BINS) $(LIBS)

dircheck:
	$(shell mkdir $(OBJPATH)) 
	$(shell mkdir $(RELEASE_PATH)) 
	@echo "dir check done"

$(BINS) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJSWITHPATH) $(GLIBLINK) -o $(RELEASE_PATH)/$@ 
#	echo "$(CC) $(CXXFLAGS) $(OBJSWITHPATH) $(GLIBLINK) -o $(RELEASE_PATH)/$@ " \


$(OBJS):%.o:$(SRCPATH)/%.cpp
	$(CC) -c $< $(GLIBINC) $(INCPATH) -o $(OBJPATH)/$@ 
#	echo "$(CC) $(SRCPATH)/$< $(GLIBINC) $(INCPATH) -c $(OBJPATH)/$@ "\
	



$(LIB) : 
 
clean:
	-rm -f $(RELEASE_PATH)/* $(OBJPATH)/* \
	echo "clean done"

pub:

