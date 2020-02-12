classdef EFIS_Pressure < Simulink.IntEnumType
  enumeration
    inHg(0)
    mmHg(1)
  end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = EFIS_Pressure.inHg;
    end
  end
end