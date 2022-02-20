CXX      = x86_64-w64-mingw32-g++-posix
CXXFLAGS = -std=c++17 -O2
LDFLAGS  = -s

all: dropper

dropper:
	$(CXX) main.cpp $(CXXFLAGS) $(LDFLAGS) -o $@.exe
