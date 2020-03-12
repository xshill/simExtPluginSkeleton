COPPELIA_HOME=/home/user/Coppelia
COPPELIA_SRC=$(COPPELIA_HOME)/programming/common
COPPELIA_FILES=$(COPPELIA_SRC)/simLib.cpp $(COPPELIA_SRC)/scriptFunctionData.cpp $(COPPELIA_SRC)/scriptFunctionDataItem.cpp # $(COPPELIA_SRC)/stack/stackObject.cpp $(COPPELIA_SRC)/stack/stackMap.cpp $(COPPELIA_SRC)/stack/stackArray.cpp $(COPPELIA_SRC)/stack/stackString.cpp $(COPPELIA_SRC)/stack/stackNumber.cpp $(COPPELIA_SRC)/stack/stackNull.cpp $(COPPELIA_SRC)/stack/stackBool.cpp
COPPELIA_INCLUDES=-I$(COPPELIA_HOME)/programming/include/ -I$(COPPELIA_HOME)/programming/include/stack

PLUGIN_NAME=OpenCV
PLUGIN_LIB=libsimExt$(PLUGIN_NAME).so
PLUGIN_FILES=simExt$(PLUGIN_NAME).cpp functions.cpp

$(PLUGIN_LIB): $(PLUGIN_FILES)
	g++ -shared -fPIC -o $(PLUGIN_LIB) $(PLUGIN_FILES) $(COPPELIA_FILES) $(COPPELIA_INCLUDES) -lopencv_core -lopencv_highgui -lopencv_imgcodecs

install: $(PLUGIN_LIB)
	cp $(PLUGIN_LIB) $(COPPELIA_HOME)/