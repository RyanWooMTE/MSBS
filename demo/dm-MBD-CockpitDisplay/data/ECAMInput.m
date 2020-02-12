classdef ECAMInput < Simulink.IntEnumType
  enumeration
    None(0)
    ENG(1)
    BLEED(2)
    PRESS(3)
    HYD(4)
    FUEL(5)
    APU(6)
  end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = ECAMInput.None;
    end
  end
end