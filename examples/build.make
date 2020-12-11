.POSIX:
.DEFAULT:
.PHONY: clean
.SUFFIXES: .cpp .o

CXX = c++
CXXFLAGS = -g -O2 -fstack-protector-strong
LDFLAGS = -flto -Wl,--as-needed
LIBS = -lpthread
RM = rm -f

.cpp.o:
	$(CXX) -c -std=c++11 -fpie $(CXXFLAGS) -o $@ $< -I ../include
.o:
	$(CXX) -pie $(LDFLAGS) -o $@ $? $(LIBS)

all: chatserver/chatserver chatserver/chatserver_mt

chatserver/chatserver: chatserver/chatserver.o
	$(CXX) $(LDFLAGS) -o $@ $?

chatserver/chatserver_mt: chatserver/chatserver_mt.o

clean:
	$(RM) chatserver/chatserver chatserver/chatserver_mt chatserver/*.o
