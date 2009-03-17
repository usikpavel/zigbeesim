#
# OMNeT++/OMNEST Makefile for dip_802.15.4
#
# This file was generated with the command:
#  opp_makemake -f --deep -I/home/bernard/apps/mobility-fw2.0p3-o4/core/basicModules -I/home/bernard/apps/mobility-fw2.0p3-o4/core/utils -I/home/bernard/apps/mobility-fw2.0p3-o4/contrib/messages -I/home/bernard/apps/mobility-fw2.0p3-o4/contrib/utils -I/home/bernard/apps/mobility-fw2.0p3-o4/core/channelControl -I/home/bernard/apps/mobility-fw2.0p3-o4/contrib/applLayer -I/home/bernard/apps/mobility-fw2.0p3-o4/core/blackboard -I/home/bernard/apps/mobility-fw2.0p3-o4/contrib/nic/macLayer -I/home/bernard/apps/mobility-fw2.0p3-o4/contrib/nic/phyLayer -I/home/bernard/apps/mobility-fw2.0p3-o4/contrib/netwLayer -I/home/bernard/apps/mobility-fw2.0p3-o4/core/basicMessages -I/home/bernard/apps/mobility-fw2.0p3-o4/contrib/nic/radios -L/home/bernard/apps/mobility-fw2.0p3-o4/out/$(CONFIGNAME)/core -L/home/bernard/apps/mobility-fw2.0p3-o4/out/$(CONFIGNAME)/contrib -lmfcore -lmfcontrib -KRTN_PROJ=/home/bernard/apps/mobility-fw2.0p3-o4
#

# Name of target to be created (-o option)
TARGET = dip_802.15.4$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I$(RTN_PROJ)/core/basicModules \
    -I$(RTN_PROJ)/core/utils \
    -I$(RTN_PROJ)/contrib/messages \
    -I$(RTN_PROJ)/contrib/utils \
    -I$(RTN_PROJ)/core/channelControl \
    -I$(RTN_PROJ)/contrib/applLayer \
    -I$(RTN_PROJ)/core/blackboard \
    -I$(RTN_PROJ)/contrib/nic/macLayer \
    -I$(RTN_PROJ)/contrib/nic/phyLayer \
    -I$(RTN_PROJ)/contrib/netwLayer \
    -I$(RTN_PROJ)/core/basicMessages \
    -I$(RTN_PROJ)/contrib/nic/radios \
    -I.

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L$(RTN_PROJ)/out/$(CONFIGNAME)/core -L$(RTN_PROJ)/out/$(CONFIGNAME)/contrib  -lmfcore -lmfcontrib
LIBS += -Wl,-rpath,`abspath $(RTN_PROJ)/out/$(CONFIGNAME)/core` -Wl,-rpath,`abspath $(RTN_PROJ)/out/$(CONFIGNAME)/contrib`

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
RTN_PROJ=/home/bernard/apps/mobility-fw2.0p3-o4

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
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/utils/HostMove.h \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	PhyPib.h \
	BBItems.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	Messages_m.h \
	$(RTN_PROJ)/core/utils/FWMath.h \
	Plme.h
$O/Mcps.o: Mcps.cc \
	typedef.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	Mcps.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/utils/HostMove.h \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	MacPib.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	BBItems.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	Messages_m.h \
	$(RTN_PROJ)/core/utils/FWMath.h
$O/Mlme.o: Mlme.cc \
	typedef.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	Mlme.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/utils/HostMove.h \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	MacPib.h \
	BBItems.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	Messages_m.h \
	$(RTN_PROJ)/core/utils/FWMath.h
$O/PhyPib.o: PhyPib.cc \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	typedef.h \
	PhyPib.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	BBItems.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	Messages_m.h \
	$(RTN_PROJ)/core/utils/FWMath.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/utils/HostMove.h
$O/SnrEval802154.o: SnrEval802154.cc \
	$(RTN_PROJ)/core/basicModules/BasicSnrEval.h \
	$(RTN_PROJ)/core/utils/ActiveChannel.h \
	$(RTN_PROJ)/contrib/utils/Bitrate.h \
	$(RTN_PROJ)/core/utils/NicControlType.h \
	$(RTN_PROJ)/contrib/nic/phyLayer/SnrEval.h \
	$(RTN_PROJ)/contrib/utils/RSSI.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	SnrEval802154.h \
	$(RTN_PROJ)/contrib/utils/MediumIndication.h \
	$(RTN_PROJ)/core/channelControl/ChannelAccess.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/channelControl/NicEntry.h \
	$(RTN_PROJ)/core/utils/HostMove.h \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	$(RTN_PROJ)/contrib/utils/RadioState.h \
	$(RTN_PROJ)/core/channelControl/ChannelControl.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/utils/FWMath.h
$O/FFDAppLayer.o: FFDAppLayer.cc \
	typedef.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/utils/HostMove.h \
	FFDAppLayer.h \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	$(RTN_PROJ)/contrib/messages/ApplPkt_m.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	Messages_m.h \
	$(RTN_PROJ)/contrib/applLayer/BasicApplLayer.h \
	$(RTN_PROJ)/core/utils/FWMath.h
$O/Messages_m.o: Messages_m.cc \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	typedef.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	Messages_m.h \
	$(RTN_PROJ)/core/utils/FWMath.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/utils/HostMove.h
$O/Llc8022.o: Llc8022.cc \
	Llc8022.h
$O/Nlde.o: Nlde.cc \
	Nlde.h
$O/Sscs.o: Sscs.cc \
	Sscs.h
$O/RFDAppLayer.o: RFDAppLayer.cc \
	$(RTN_PROJ)/contrib/messages/ApplPkt_m.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	RFDAppLayer.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h
$O/Nlme.o: Nlme.cc \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	typedef.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	Messages_m.h \
	$(RTN_PROJ)/core/utils/FWMath.h \
	Nlme.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/utils/HostMove.h
$O/Mac802154.o: Mac802154.cc \
	$(RTN_PROJ)/core/utils/ActiveChannel.h \
	$(RTN_PROJ)/contrib/utils/Bitrate.h \
	Mac802154.h \
	$(RTN_PROJ)/core/utils/NicControlType.h \
	$(RTN_PROJ)/core/basicModules/BasicMacLayer.h \
	$(RTN_PROJ)/core/basicModules/BasicLayer.h \
	$(RTN_PROJ)/contrib/utils/RSSI.h \
	$(RTN_PROJ)/core/basicMessages/MacPkt_m.h \
	$(RTN_PROJ)/core/utils/SimpleAddress.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	$(RTN_PROJ)/contrib/nic/radios/SingleChannelRadio.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/contrib/utils/DroppedPacket.h \
	$(RTN_PROJ)/contrib/utils/RadioState.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/utils/FWMath.h
$O/Pd.o: Pd.cc \
	$(RTN_PROJ)/core/utils/MacControlInfo.h \
	typedef.h \
	$(RTN_PROJ)/core/utils/ActiveChannel.h \
	$(RTN_PROJ)/core/utils/CoreDebug.h \
	$(RTN_PROJ)/contrib/utils/Bitrate.h \
	$(RTN_PROJ)/core/utils/SimpleAddress.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	$(RTN_PROJ)/contrib/nic/radios/SingleChannelRadio.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/utils/HostMove.h \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	$(RTN_PROJ)/contrib/utils/RadioState.h \
	Pd.h \
	PhyPib.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	BBItems.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	Messages_m.h \
	$(RTN_PROJ)/core/utils/FWMath.h
$O/MacPib.o: MacPib.cc \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	typedef.h \
	MacPib.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	BBItems.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	Messages_m.h \
	$(RTN_PROJ)/core/utils/FWMath.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/utils/HostMove.h
$O/NwkPib.o: NwkPib.cc \
	NwkPib.h
$O/SnrDecider802154.o: SnrDecider802154.cc \
	$(RTN_PROJ)/core/basicMessages/AirFrame_m.h \
	SnrDecider802154.h \
	$(RTN_PROJ)/contrib/nic/phyLayer/SnrDecider.h \
	$(RTN_PROJ)/core/utils/SnrList.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/utils/Coord.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	$(RTN_PROJ)/core/utils/FWMath.h \
	$(RTN_PROJ)/core/basicModules/BasicDecider.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	$(RTN_PROJ)/core/utils/HostMove.h
$O/RFDNetLayer.o: RFDNetLayer.cc \
	$(RTN_PROJ)/core/utils/MacControlInfo.h \
	$(RTN_PROJ)/core/basicModules/BasicLayer.h \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/contrib/utils/NetwControlInfo.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	$(RTN_PROJ)/contrib/messages/NetwPkt_m.h \
	$(RTN_PROJ)/core/utils/SimpleAddress.h \
	RFDNetLayer.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	ZigBeeArp.h
$O/ZigBeeArp.o: ZigBeeArp.cc \
	$(RTN_PROJ)/core/blackboard/Blackboard.h \
	$(RTN_PROJ)/core/basicModules/BasicModule.h \
	$(RTN_PROJ)/core/utils/ModuleAccess.h \
	ZigBeeArp.h

