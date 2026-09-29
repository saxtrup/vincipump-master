# ---

require vincipump

epicsEnvSet("IP_ADDRESS", "192.168.1.101:502")
epicsEnvSet(SYSTEM, "SE-SEE:")
epicsEnvSet(DEVICE, "SE-VINP-001:")
epicsEnvSet(LOCATION, "E03.110; $(IP_ADDRESS)")


iocshLoad("$(vincipump_DIR)/vincipump.iocsh","P=$(SYSTEM), R=$(DEVICE)")
