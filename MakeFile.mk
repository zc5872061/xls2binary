DEBUG_CFLAGS	:= -Wall -Wno-format -g -DDEBUG
TINYXMLLIBS 	:= -Ltinyxml -ltinyxml
INCS	:= -Iinclude
CXXFLAGS	:=${TINYXMLLIBS} ${INCS}


#write:write.o msg.pb.o tinyxml.o tinystr.o tconf.pb.o
#	g++   write.o msg.pb.o tconf.pb.o tinystr.o tinyxml.o tinyxmlparser.cpp tinyxmlerror.cpp -o bin/write `pkg-config --cflags --libs protobuf`
write:write.o msg.pb.o tconf.pb.o DataManager.o
	g++   write.o msg.pb.o tconf.pb.o DataManager.o  -o bin/write ${DEBUG_CFLAGS} ${CXXFLAGS} `pkg-config --cflags --libs protobuf`
clean:  
	rm -f bin/write reader  *.o  log  
clean_protoFile:
	rm -f msg.*.cc msg.*.h tconf.*.h tconf.*.cc
proto_msg:  
	protoc --cpp_out=. msg.proto
	protoc --cpp_out=. tconf.proto  


#tconf.pb.o:tconf.pb.cc tconf.pb.h
#	g++ -c ${DEBUG_CFLAGS} tconf.pb.cc `pkg-config --cflags --libs protobuf`
msg.pb.o:msg.pb.cc msg.pb.h
	g++ -c msg.pb.cc ${DEBUG_CFLAGS} ${CXXFLAGS} `pkg-config --cflags --libs protobuf`
#tinyxml.o:tinyxml.cpp tinyxml.h tinystr.h
#	g++ -c ${DEBUG_CFLAGS} tinyxml.cpp 
#tinystr.o:tinystr.cpp tinystr.h
#	g++ -c ${DEBUG_CFLAGS} tinystr.cpp 
write.o:write.cc 
	g++ -c write.cc ${DEBUG_CFLAGS} ${CXXFLAGS} `pkg-config --cflags --libs protobuf` 
DataManager.o:DataManager.cpp DataManager.h
	g++ -c DataManager.cpp ${DEBUG_CFLAGS} ${CXXFLAGS}
