#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=/opt/devkitpro")
endif

TARGET      := nds-cia3dsx-converter
BUILD       := build
SOURCES     := source
DATA        :=
INCLUDES    := include
GRAPHICS    :=

ARCH        := -march=armv6k -mtune=mpcore -mfloat-abi=hard

INCLUDE     := $(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir))
CFLAGS      := -g -Wall -O2 -mword-relocations -ffunction-sections $(ARCH) $(INCLUDE)
CFLAGS      += -D__3DS__

CXXFLAGS    := $(CFLAGS) -fno-rtti -fno-exceptions
ASFLAGS     := -g $(ARCH)
LDFLAGS     := -specs=3dsx.specs -g $(ARCH) -Wl,-Map,$(notdir $*.map)

LIBS        := -lctru

#---------------------------------------------------------------------------------
include $(DEVKITPRO)/3ds_rules
#---------------------------------------------------------------------------------
