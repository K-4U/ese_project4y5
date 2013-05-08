RTS_HOME = C:/Program Files (x86)/Rational/Rose RealTime/C++/TargetRTS
# How to handle possible spaces in RTS_HOME for GNU make
RTempty =
RTspace = $(RTempty) $(RTempty)
RTS_MKHOME = $(subst $(RTspace),\$(RTspace),$(RTS_HOME))
include $(RTS_MKHOME)/codegen/rtgen.mk
MODEL = "C:/Users/Maarten/Documents/Rose RealTime/Serial.rtmdl"
COMPONENT = "Component View::Program"
RTGEN_FLAGS = -codesync -model $(MODEL) -component $(COMPONENT) -spacedeps bs
include RTSystem/Program.dep
CODESYNC_TARGETS = $(Program_SYSTARGET_CS)
RTCODESYNC_TARGET = $(CODESYNC_TARGETS)

RTcodesync : $(RTCODESYNC_TARGET)

.PRECIOUS : $(CODESYNC_TARGETS)

$(Program_SYSTARGET_CS) : $(Program_SYSDEPS_CS)
	$(RTGEN) $(RTGEN_FLAGS) -system

