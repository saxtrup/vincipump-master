TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = vincipump
# vincipump.dbd will be created and installed
DBD += vincipump.dbd

# vincipump.dbd will be made up from these files:
vincipump_DBD += base.dbd

# Include dbd files from all support applications:
#vincipump_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#vincipump_LIBS += xxx

# vincipump_registerRecordDeviceDriver.cpp derives from vincipump.dbd
vincipump_SRCS += vincipump_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
vincipump_SRCS_DEFAULT += vincipumpMain.cpp
vincipump_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#vincipump_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
vincipump_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

