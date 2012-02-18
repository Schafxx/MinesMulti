#############################################################################
# Makefile for building: MinesMulti
# Generated by qmake (2.01a) (Qt 4.7.4) on: Sa. Feb 18 19:42:01 2012
# Project:  MinesMulti.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile MinesMulti.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ChatClient.cpp \
		ChatServer.cpp \
		Feld.cpp \
		GameClient.cpp \
		GameServer.cpp \
		main.cpp \
		MinesMulti.cpp moc_Feld.cpp \
		moc_MinesMulti.cpp
OBJECTS       = ChatClient.o \
		ChatServer.o \
		Feld.o \
		GameClient.o \
		GameServer.o \
		main.o \
		MinesMulti.o \
		moc_Feld.o \
		moc_MinesMulti.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		MinesMulti.pro
QMAKE_TARGET  = MinesMulti
DESTDIR       = 
TARGET        = MinesMulti

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_MinesMulti.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: MinesMulti.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtNetwork.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile MinesMulti.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtNetwork.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile MinesMulti.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/MinesMulti1.0.0 || $(MKDIR) .tmp/MinesMulti1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/MinesMulti1.0.0/ && $(COPY_FILE) --parents ChatClient.h ChatServer.h Feld.h GameClient.h GameServer.h MinesMulti.h .tmp/MinesMulti1.0.0/ && $(COPY_FILE) --parents ChatClient.cpp ChatServer.cpp Feld.cpp GameClient.cpp GameServer.cpp main.cpp MinesMulti.cpp .tmp/MinesMulti1.0.0/ && $(COPY_FILE) --parents MinesMulti.ui .tmp/MinesMulti1.0.0/ && (cd `dirname .tmp/MinesMulti1.0.0` && $(TAR) MinesMulti1.0.0.tar MinesMulti1.0.0 && $(COMPRESS) MinesMulti1.0.0.tar) && $(MOVE) `dirname .tmp/MinesMulti1.0.0`/MinesMulti1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/MinesMulti1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_Feld.cpp moc_MinesMulti.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_Feld.cpp moc_MinesMulti.cpp
moc_Feld.cpp: Feld.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Feld.h -o moc_Feld.cpp

moc_MinesMulti.cpp: ui_MinesMulti.h \
		ChatServer.h \
		ChatClient.h \
		GameServer.h \
		GameClient.h \
		Feld.h \
		MinesMulti.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) MinesMulti.h -o moc_MinesMulti.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_MinesMulti.h
compiler_uic_clean:
	-$(DEL_FILE) ui_MinesMulti.h
ui_MinesMulti.h: MinesMulti.ui
	/usr/bin/uic-qt4 MinesMulti.ui -o ui_MinesMulti.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

ChatClient.o: ChatClient.cpp ChatClient.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ChatClient.o ChatClient.cpp

ChatServer.o: ChatServer.cpp ChatServer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ChatServer.o ChatServer.cpp

Feld.o: Feld.cpp Feld.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Feld.o Feld.cpp

GameClient.o: GameClient.cpp GameClient.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GameClient.o GameClient.cpp

GameServer.o: GameServer.cpp GameServer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GameServer.o GameServer.cpp

main.o: main.cpp MinesMulti.h \
		ui_MinesMulti.h \
		ChatServer.h \
		ChatClient.h \
		GameServer.h \
		GameClient.h \
		Feld.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

MinesMulti.o: MinesMulti.cpp MinesMulti.h \
		ui_MinesMulti.h \
		ChatServer.h \
		ChatClient.h \
		GameServer.h \
		GameClient.h \
		Feld.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MinesMulti.o MinesMulti.cpp

moc_Feld.o: moc_Feld.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Feld.o moc_Feld.cpp

moc_MinesMulti.o: moc_MinesMulti.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MinesMulti.o moc_MinesMulti.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

