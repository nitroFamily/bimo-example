TARGET = exec/coder
SRCS = src/main.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
LIBS_PATH = -L/Users/Aleksandr/Documents/haskell/bimo_all/app_data/libs/itpp/itpp_rw/
LIBS_NAME = -litpp_rw
LIBS_HEADERS = -I/Users/Aleksandr/Documents/haskell/bimo_all/app_data/libs/itpp/itpp_rw/headers

all: $(TARGET)

${TARGET}: $(OBJS)
	g++ -o $(TARGET) $(OBJS) $(LIBS_PATH) $(LIBS_NAME)  -L/usr/local/Cellar/itpp/4.3.1/lib -litpp

.cpp.o:
	g++ -c $< -o $@ $(LIBS_HEADERS)  -I/usr/local/Cellar/itpp/4.3.1/include -DNDEBUG
