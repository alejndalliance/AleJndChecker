CXX = clang++
CXXFLAGS = -O3 -std=c++11 -Wextra -Wformat-security -fstack-protector-all -Wstack-protector -fPIE -ftrapv -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now -Wl,--strip-all
LDFLAGS = -lcrypto -lcurl -ljsoncpp -ldl
LIBS =
INCS = -I./include
PROG = checker
SRCS = $(wildcard *.cpp)
SUBDIRS = all clean

all:
	@$(CXX) $(SRCS) $(CXXFLAGS) -o $(PROG) $(INCS) $(LDFLAGS)

.PHONY: $(SUBDIRS)

clean:
	@rm -f *.o $(PROG)
