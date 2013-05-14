################################################################################
#	MODULE		:	Makefile
################################################################################
TARGET_EXE=magicls
CPP_SOURCES=main.cpp
TARGET_TYPE=exe

include ../build/tools_env.mk
include ../build/wxwidgets_env.mk

CFLAGS+=$(WX_CFLAGS) -DNDEBUG=1
LDFLAGS+=$(WX_LDFLAGS)

INCLUDES=-I ../libwxmagic
EXTERN_LIBS=../libwxmagic/libwxMagic.a

include ../build/buildsys.mk

../libwxmagic/libwxMagic.a:
	make -C ../libwxmagic

cleanall: clean
	make -C ../libwxmagic clean

# DO NOT DELETE

$(OBJ_DIR)/main.o: ../libwxmagic/wxMagic.h
