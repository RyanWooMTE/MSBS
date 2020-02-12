classdef(Enumeration) ActuatorStatus < Simulink.IntEnumType
  enumeration      
    UNLOCK_POS(0)
    LOCK_POS(1)
    UNDETERMINED(2)
  end

  methods (Static = true)
    function retVal = getDefaultValue()
      retVal = ActuatorStatus.UNDETERMINED;
    end

    function retVal = getDescription()
      retVal = 'This defines the enumerated type for actuator status';
    end

    function retVal = addClassNameToEnumNames()
      % ADDCLASSNAMETOENUMNAMES  Specify if class name is added
      %   as a prefix to enumerated names in the generated code.
      %   By default we do not add the prefix.
      retVal = false;
    end
    
    function retVal = getHeaderFile()
        retVal = '';
    end
  end
end