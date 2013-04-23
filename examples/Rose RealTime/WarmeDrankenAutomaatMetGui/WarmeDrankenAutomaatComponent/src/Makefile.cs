RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = "C:/Documents and Settings/esgr/My Documents/rosert/2009-2010/WarmeDrankenAutomaatMetGui20100510/WarmeDrankenAutomaatMetGui/WarmeDrankenAutomaat.rtmdl"
COMPONENT = "Component View::WarmeDrankenAutomaatComponent"
RTGEN_FLAGS = -codesync -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/WarmeDrankenAutomaatComponent.dep>
CODESYNC_TARGETS = $(WarmeDrankenAutomaatComponent_SYSTARGET_CS)
RTCODESYNC_TARGET = $(CODESYNC_TARGETS)

RTcodesync : $(RTCODESYNC_TARGET)

.PRECIOUS : $(CODESYNC_TARGETS)

$(WarmeDrankenAutomaatComponent_SYSTARGET_CS) : $(WarmeDrankenAutomaatComponent_SYSDEPS_CS)
	$(RTGEN) $(RTGEN_FLAGS) -system

