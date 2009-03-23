#
# OMNeT++/OMNEST Makefile for dip_802.15.4
#
# This file was generated with the command:
#  opp_makemake -f --deep -I../../mf-opp4/contrib/nic/macLayer -I../../mf-opp4/contrib/nic/radios -I../../mf-opp4/contrib/nic/phyLayer -I../../mf-opp4/core/basicMessages -I../../mf-opp4/contrib/messages -I../../mf-opp4/core/blackboard -I../../mf-opp4/contrib/netwLayer -I../../mf-opp4/core/basicModules -I../../mf-opp4/core/channelControl -I../../mf-opp4/core/utils -I../../mf-opp4/contrib/applLayer -I../../mf-opp4/contrib/utils -L../../mf-opp4/out/$(CONFIGNAME)/core -L../../mf-opp4/out/$(CONFIGNAME)/contrib -lmfcore -lmfcontrib -KMF_OPP4_PROJ=../../mf-opp4
#

# Name of target to be created (-o option)
TARGET = dip_802.15.4$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../mf-opp4/contrib/nic/macLayer \
    -I../../mf-opp4/contrib/nic/radios \
    -I../../mf-opp4/contrib/nic/phyLayer \
    -I../../mf-opp4/core/basicMessages \
    -I../../mf-opp4/contrib/messages \
    -I../../mf-opp4/core/blackboard \
    -I../../mf-opp4/contrib/netwLayer \
    -I../../mf-opp4/core/basicModules \
    -I../../mf-opp4/core/channelControl \
    -I../../mf-opp4/core/utils \
    -I../../mf-opp4/contrib/applLayer \
    -I../../mf-opp4/contrib/utils \
    -I.

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../mf-opp4/out/$(CONFIGNAME)/core -L../../mf-opp4/out/$(CONFIGNAME)/contrib  -lmfcore -lmfcontrib
LIBS += -Wl,-rpath,`abspath ../../mf-opp4/out/$(CONFIGNAME)/core` -Wl,-rpath,`abspath ../../mf-opp4/out/$(CONFIGNAME)/contrib`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/FFDAppLayer.o \
    $O/Llc8022.o \
    $O/Mac802154.o \
    $O/MacPib.o \
    $O/Mcps.o \
    $O/Mlme.o \
    $O/Nlde.o \
    $O/Nlme.o \
    $O/NwkPib.o \
    $O/Pd.o \
    $O/PhyPib.o \
    $O/Plme.o \
    $O/RFDAppLayer.o \
    $O/RFDNetLayer.o \
    $O/SnrDecider802154.o \
    $O/SnrEval802154.o \
    $O/Sscs.o \
    $O/ZigBeeArp.o \
    $O/Messages_m.o

# Message files
MSGFILES = \
    Messages.msg

# Other makefile variables (-K)
MF_OPP4_PROJ=../../mf-opp4

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET)

$(TARGET) : $O/$(TARGET)
	ln -s -f $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@mkdir -p $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY:

.SUFFIXES: .cc

$O/%.o: %.cc
	@mkdir -p $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f dip_802.15.4 dip_802.15.4.exe libdip_802.15.4.so libdip_802.15.4.a libdip_802.15.4.dll libdip_802.15.4.dylib
	-rm -f ./*_m.cc ./*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/Plme.o: Plme.cc \
	typedef.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	PhyPib.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	BBItems.h \
	Messages_m.h \
	Plme.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/Mcps.o: Mcps.cc \
	typedef.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	MacPib.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	BBItems.h \
	Messages_m.h \
	Mcps.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/Mlme.o: Mlme.cc \
	typedef.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	MacPib.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	BBItems.h \
	Messages_m.h \
	Mlme.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/PhyPib.o: PhyPib.cc \
	typedef.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	PhyPib.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	BBItems.h \
	Messages_m.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/SnrEval802154.o: SnrEval802154.cc \
	$(MF_OPP4_PROJ)/core/channelControl/ChannelAccess.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	SnrEval802154.h \
	$(MF_OPP4_PROJ)/core/utils/NicControlType.h \
	$(MF_OPP4_PROJ)/contrib/nic/phyLayer/SnrEval.h \
	$(MF_OPP4_PROJ)/core/utils/Coord.h \
	$(MF_OPP4_PROJ)/core/basicMessages/AirFrame_m.h \
	$(MF_OPP4_PROJ)/contrib/utils/MediumIndication.h \
	$(MF_OPP4_PROJ)/core/channelControl/ChannelControl.h \
	$(MF_OPP4_PROJ)/core/channelControl/NicEntry.h \
	$(MF_OPP4_PROJ)/core/utils/FWMath.h \
	$(MF_OPP4_PROJ)/core/utils/HostMove.h \
	$(MF_OPP4_PROJ)/core/utils/ActiveChannel.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicSnrEval.h \
	$(MF_OPP4_PROJ)/contrib/utils/RadioState.h \
	$(MF_OPP4_PROJ)/core/utils/SnrList.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	$(MF_OPP4_PROJ)/contrib/utils/RSSI.h \
	$(MF_OPP4_PROJ)/contrib/utils/Bitrate.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/FFDAppLayer.o: FFDAppLayer.cc \
	FFDAppLayer.h \
	typedef.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	$(MF_OPP4_PROJ)/contrib/messages/ApplPkt_m.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	$(MF_OPP4_PROJ)/contrib/applLayer/BasicApplLayer.h \
	Messages_m.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/Messages_m.o: Messages_m.cc \
	typedef.h \
	Messages_m.h
$O/Llc8022.o: Llc8022.cc \
	Llc8022.h
$O/Nlde.o: Nlde.cc \
	Nlde.h
$O/Sscs.o: Sscs.cc \
	Sscs.h
$O/RFDAppLayer.o: RFDAppLayer.cc \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	$(MF_OPP4_PROJ)/contrib/messages/ApplPkt_m.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	RFDAppLayer.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/Nlme.o: Nlme.cc \
	typedef.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	Messages_m.h \
	Nlme.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/Mac802154.o: Mac802154.cc \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	Mac802154.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicLayer.h \
	$(MF_OPP4_PROJ)/core/utils/NicControlType.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicMacLayer.h \
	$(MF_OPP4_PROJ)/core/basicMessages/MacPkt_m.h \
	$(MF_OPP4_PROJ)/contrib/utils/DroppedPacket.h \
	$(MF_OPP4_PROJ)/core/utils/FWMath.h \
	$(MF_OPP4_PROJ)/core/utils/ActiveChannel.h \
	$(MF_OPP4_PROJ)/core/utils/SimpleAddress.h \
	$(MF_OPP4_PROJ)/contrib/utils/RadioState.h \
	$(MF_OPP4_PROJ)/contrib/nic/radios/SingleChannelRadio.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	$(MF_OPP4_PROJ)/contrib/utils/RSSI.h \
	$(MF_OPP4_PROJ)/contrib/utils/Bitrate.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/Pd.o: Pd.cc \
	typedef.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	$(MF_OPP4_PROJ)/core/utils/Coord.h \
	$(MF_OPP4_PROJ)/core/utils/MacControlInfo.h \
	$(MF_OPP4_PROJ)/core/channelControl/NicEntry.h \
	$(MF_OPP4_PROJ)/core/channelControl/ChannelControl.h \
	$(MF_OPP4_PROJ)/core/utils/FWMath.h \
	Pd.h \
	$(MF_OPP4_PROJ)/core/utils/ActiveChannel.h \
	$(MF_OPP4_PROJ)/core/utils/SimpleAddress.h \
	$(MF_OPP4_PROJ)/contrib/utils/RadioState.h \
	$(MF_OPP4_PROJ)/core/utils/CoreDebug.h \
	$(MF_OPP4_PROJ)/contrib/nic/radios/SingleChannelRadio.h \
	PhyPib.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	BBItems.h \
	Messages_m.h \
	$(MF_OPP4_PROJ)/contrib/utils/Bitrate.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/MacPib.o: MacPib.cc \
	typedef.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	MacPib.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	BBItems.h \
	Messages_m.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/NwkPib.o: NwkPib.cc \
	NwkPib.h
$O/SnrDecider802154.o: SnrDecider802154.cc \
	SnrDecider802154.h \
	$(MF_OPP4_PROJ)/core/utils/FWMath.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicDecider.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	$(MF_OPP4_PROJ)/core/utils/HostMove.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	$(MF_OPP4_PROJ)/core/utils/SnrList.h \
	$(MF_OPP4_PROJ)/contrib/nic/phyLayer/SnrDecider.h \
	$(MF_OPP4_PROJ)/core/utils/Coord.h \
	$(MF_OPP4_PROJ)/core/basicMessages/AirFrame_m.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h
$O/RFDNetLayer.o: RFDNetLayer.cc \
	$(MF_OPP4_PROJ)/contrib/utils/NetwControlInfo.h \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	$(MF_OPP4_PROJ)/core/utils/SimpleAddress.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicLayer.h \
	$(MF_OPP4_PROJ)/contrib/messages/NetwPkt_m.h \
	RFDNetLayer.h \
	$(MF_OPP4_PROJ)/core/utils/MacControlInfo.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h \
	ZigBeeArp.h
$O/ZigBeeArp.o: ZigBeeArp.cc \
	$(MF_OPP4_PROJ)/core/utils/ModuleAccess.h \
	$(MF_OPP4_PROJ)/core/blackboard/Blackboard.h \
	$(MF_OPP4_PROJ)/core/basicModules/BasicModule.h \
	ZigBeeArp.h

