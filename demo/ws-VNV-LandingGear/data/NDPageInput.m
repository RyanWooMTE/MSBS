classdef NDPageInput < Simulink.IntEnumType
  enumeration
    ILS(0)
    VOR(1)
    NAV(2)
    ARC(3)
    PLAN(4)
  end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = NDPageInput.ILS;
    end
  end
end