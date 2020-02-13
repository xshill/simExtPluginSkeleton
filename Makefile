COPPELIA_HOME=/home/user/Coppelia
COPPELIA_SRC=$(COPPELIA_HOME)/programming/common
COPPELIA_FILES=$(COPPELIA_SRC)/simLib.cpp # $(COPPELIA_SRC)/stack/stackObject.cpp $(COPPELIA_SRC)/stack/stackMap.cpp $(COPPELIA_SRC)/stack/stackArray.cpp $(COPPELIA_SRC)/stack/stackString.cpp $(COPPELIA_SRC)/stack/stackNumber.cpp $(COPPELIA_SRC)/stack/stackNull.cpp $(COPPELIA_SRC)/stack/stackBool.cpp
COPPELIA_INCLUDES=-I$(COPPELIA_HOME)/programming/include/ -I$(COPPELIA_HOME)/programming/include/stack

libsimExtPluginSkeleton.so: simExtPluginSkeleton.cpp
	g++ -shared -fPIC -o libsimExtPluginSkeleton.so simExtPluginSkeleton.cpp $(COPPELIA_FILES) $(COPPELIA_INCLUDES)

install: libsimExtPluginSkeleton.so
	cp libsimExtPluginSkeleton.so $(COPPELIA_HOME)/