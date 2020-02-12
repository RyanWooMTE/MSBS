classdef (Hidden = true) ExtendedHardwareConfig < rtw.connectivity.ExtendedHardwareConfig
%EXTENDEDHARDWARECONFIG defines extended hardware characteristics 
%   This file is required for examplePilF28335 since the F28335 uses a 
%   16-bit char.
%
%   This file is NOT required for PIL implementations whose target
%   processor uses 8-bit char.
%
%   This is an undocumented class. Its methods and properties are likely to
%   change without warning from one release to the next.

% Copyright 2011 MathWorks, Inc.

    methods
        % constructor
        function this = ExtendedHardwareConfig
            error(nargchk(0, 0, nargin, 'struct'));            
        end

        % ISBYTEADDRESSABLE: Method to indicate whether the
        %                    target is byte addressable or not.
        %
        % byteAddressable = isByteAddressable
        %
        % byteAddressable: Boolean indicating whether the target is byte addressable
        % or not.
        function byteAddressable = isByteAddressable(this) %#ok<MANU>
            error(nargchk(1, 1, nargin, 'struct'));
            % default implementation
            byteAddressable = false;
        end

        % GETDATATYPEWORDORDER: Method to return the target word order for
        %                       multi-word Simulink datatypes.
        %
        % wordOrder = getDatatypeWordOrder(simulinkType, byteOrder)
        %
        % simulinkType: A Simulink datatype name.
        % byteOrder: The byte order of the target.
        %
        % wordOrder: The corresponding target word order - "LittleEndian" or "BigEndian"
        function wordOrder = getDatatypeWordOrder(this, ~, ~) %#ok<MANU>
            error(nargchk(3, 3, nargin, 'struct'));            
            % default implementation 
            wordOrder = 'LittleEndian';
        end

        % GETDATATYPESIZE: Method to return the target datatype size for
        %                  standard Simulink datatypes.
        %
        % size = getDatatypeSize(simulinkType)
        %
        % simulinkType: A Simulink datatype name.
        %
        % size: The corresponding target datatype size in 8-bit bytes
        function size = getDatatypeSize(this, simulinkType) %#ok<MANU>
            error(nargchk(2, 2, nargin, 'struct'));
            % define default datatype sizes
            switch simulinkType
                case 'double'
                   size = 4;
                case {'single' 'int32' 'uint32'}
                    size = 4;
                case {'int16' 'uint16'}
                    size = 2;
                case {'int8' 'uint8' 'boolean'}
                    size = 2;
                otherwise
                    rtw.pil.ProductInfo.error('pilverification', 'UnknownDataType', simulinkType);
            end                           
        end
    end
end
