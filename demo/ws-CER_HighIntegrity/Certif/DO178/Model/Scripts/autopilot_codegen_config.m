%---------------------------------------------------------------------------
%  MATLAB function for configuration set generated on 22-Nov-2011 22:14:29
%  MATLAB version: 7.13.0.564 (R2011b)
%---------------------------------------------------------------------------

function cs=autopilot_codegen_config()

cs = Simulink.ConfigSet;
 
% Original configuration set version: 1.11.1
if cs.versionCompare('1.11.1') < 0
    error('Simulink:MFileVersionViolation', 'The version of the target configuration set is older than the original configuration set.');
end
 
% Original environment character encoding: windows-1252
if ~strcmpi(get_param(0, 'CharacterEncoding'), 'windows-1252')
    warning('Simulink:EncodingUnMatched', 'The target character encoding (%s) is different from the original (%s).',  get_param(0, 'CharacterEncoding'), 'windows-1252');
end

% Do not change the order of the following commands. There are dependencies between the parameters.
cs.set_param('SystemTargetFile', 'ert.tlc');   % System target file
cs.set_param('GenerateComments', 'on');   % Include comments 
cs.set_param('SimulinkBlockComments', 'on');   % Simulink block / Stateflow object comments 
cs.set_param('ShowEliminatedStatement', 'on');   % Show eliminated blocks 
cs.set_param('ForceParamTrailComments', 'on');   % Verbose comments for SimulinkGlobal storage class 
cs.set_param('InsertBlockDesc', 'on');   % Simulink block descriptions 
cs.set_param('SimulinkDataObjDesc', 'on');   % Simulink data object descriptions 
cs.set_param('EnableCustomComments', 'off');   % Custom comments (MPT objects only) 
cs.set_param('SFDataObjDesc', 'off');   % Stateflow object descriptions 
cs.set_param('ReqsInCode', 'on');   % Requirements in block comments 
cs.set_param('IncludeHyperlinkInReport', 'on');   % Code-to-model 
cs.set_param('GenerateReport', 'on');   % Create code generation report 
cs.set_param('GenerateTraceInfo', 'on');   % Model-to-code 
cs.set_param('GenerateTraceReport', 'on');   % Eliminated / virtual blocks 
cs.set_param('GenerateTraceReportSl', 'on');   % Traceable Simulink blocks 
cs.set_param('GenerateTraceReportSf', 'on');   % Traceable Stateflow objects 
cs.set_param('GenerateTraceReportEml', 'on');   % Traceable MATLAB functions 
cs.set_param('LaunchReport', 'off');   % Launch report automatically 
cs.set_param('GenerateCodeMetricsReport', 'on');   % Static code metrics 
cs.set_param('MultiInstanceERTCode', 'on');   % Generate reusable code 
cs.set_param('OptimizeBlockIOStorage', 'on');   % Signal storage reuse 
cs.set_param('ExpressionFolding', 'on');   % Eliminate superfluous local variables (expression folding) 
cs.set_param('ParamNamingRule', 'None');   % Parameter naming 
cs.set_param('RTWCompilerOptimization', 'Off');   % Compiler optimization level 
cs.set_param('SignalNamingRule', 'None');   % Signal naming 
cs.set_param('UpdateModelReferenceTargets', 'IfOutOfDateOrStructuralChange');   % Rebuild 
cs.set_param('GenerateSampleERTMain', 'on');   % Generate an example main program 
cs.set_param('ProdHWDeviceType', 'Specified');   % Device type 
cs.set_param('EnableUserReplacementTypes', 'off');   % Replace data type names in the generated code 
cs.set_param('ERTMultiwordTypeDef', 'System defined');   % Multiword type definitions 
cs.set_param('EnableMemcpy', 'off');   % Use memcpy for vector assignment 
cs.set_param('GenerateMakefile', 'on');   % Generate makefile 
cs.set_param('GlobalDataDefinition', 'Auto');   % Data definition 
cs.set_param('GlobalDataReference', 'Auto');   % Data declaration 
cs.set_param('SaveFinalState', 'off');   % Final states 
cs.set_param('SignalLogging', 'off');   % Signal logging 
cs.set_param('TargetUnknown', 'off');   % Target unknown 
cs.set_param('DSMLogging', 'off');   % Data stores 
cs.set_param('LimitDataPoints', 'off');   % Limit data points to last 
cs.set_param('LoadExternalInput', 'off');   % Input 
cs.set_param('LoadInitialState', 'off');   % Initial state 
cs.set_param('ReturnWorkspaceOutputs', 'off');   % Save simulation output as single object 
cs.set_param('SaveOutput', 'off');   % Output 
cs.set_param('SaveState', 'off');   % States 
cs.set_param('SaveTime', 'off');   % Time 
cs.set_param('SupportNonInlinedSFcns', 'off');   % non-inlined S-functions 
cs.set_param('PurelyIntegerCode', 'off');   % floating-point numbers 
cs.set_param('SupportNonFinite', 'off');   % non-finite numbers 
cs.set_param('MatFileLogging', 'off');   % MAT-file logging 
cs.set_param('SuppressErrorStatus', 'on');   % Suppress error status in real-time model data structure 
cs.set_param('SupportContinuousTime', 'off');   % continuous time 
cs.set_param('IncludeMdlTerminateFcn', 'off');   % Terminate function required 
cs.set_param('GRTInterface', 'off');   % GRT compatible call interface 
cs.set_param('CombineOutputUpdateFcns', 'on');   % Single output/update function 
cs.set_param('ModelReferenceMinAlgLoopOccurrences', 'off');   % Minimize algebraic loop occurrences 
cs.set_param('PortableWordSizes', 'off');   % Enable portable word sizes 
cs.set_param('ProdEqTarget', 'on');   % None 
cs.set_param('SolverType', 'Fixed-step');   % Type 
cs.set_param('AutoInsertRateTranBlk', 'off');   % Automatically handle rate transition for data transfer 
cs.set_param('ExtMode', 'off');   % Interface 
 
% The following commands do not have dependencies.
cs.set_param('Description', '');  % Description
cs.set_param('Name', 'Autopilot_Config');  % Name

% Solver pane
cs.set_param('FixedStep', '1/40');   % Fixed-step size (fundamental sample time) 
cs.set_param('PositivePriorityOrder', 'off');   % Higher priority value indicates higher task priority 
cs.set_param('SampleTimeConstraint', 'Unconstrained');   % Periodic sample time constraint 
cs.set_param('Solver', 'FixedStepDiscrete');   % Solver 
cs.set_param('SolverMode', 'SingleTasking');   % Tasking mode for periodic sample times 
cs.set_param('StartTime', '0.0');   % Start time 
cs.set_param('StopTime', '60');   % Stop time	

% Data Import/Export pane
cs.set_param('Decimation', '1');   % Decimation 
cs.set_param('SaveFormat', 'StructureWithTime');   % Format 
cs.set_param('SignalLoggingName', 'logsout');   % Signal logging name 
cs.set_param('SignalLoggingSaveFormat', 'ModelDataLogs');   % Signal logging format 

% Optimization pane
cs.set_param('AccelVerboseBuild', 'off');   % Verbose accelerator builds 
cs.set_param('BlockReduction', 'on');   % Block reduction 
cs.set_param('BooleanDataType', 'on');   % Implement logic signals as Boolean data (vs. double) 
cs.set_param('ConditionallyExecuteInputs', 'on');   % Conditional input branch execution 
cs.set_param('EfficientFloat2IntCast', 'on');   % Remove code from floating-point to integer conversions that wraps out-of-range values 
cs.set_param('EfficientMapNaN2IntZero', 'off');   % Remove code from floating-point to integer conversions with saturation that maps NaN to zero 
cs.set_param('InitFltsAndDblsToZero', 'on');   % Use memset to initialize floats and doubles to 0.0 
cs.set_param('LifeSpan', 'inf');   % Application lifespan (days) 
cs.set_param('NoFixptDivByZeroProtection', 'off');   % Remove code that protects against division arithmetic exceptions 
cs.set_param('OptimizeModelRefInitCode', 'on');   % Optimize initialization code for model reference 
cs.set_param('SimCompilerOptimization', 'Off');   % Compiler optimization level 
cs.set_param('UseFloatMulNetSlope', 'off');   % Use floating-point multiplication to handle net slope corrections 
cs.set_param('UseIntDivNetSlope', 'on');   % Use integer division to handle net slopes that are reciprocals of integers 
cs.set_param('UseSpecifiedMinMax', 'off');   % Optimize using the specified minimum and maximum values 
cs.set_param('ZeroExternalMemoryAtStartup', 'off');   % Remove root level I/O zero initialization 
cs.set_param('ZeroInternalMemoryAtStartup', 'off');   % Remove internal data zero initialization 

% Optimization:Signals and Parameters pane
cs.set_param('BitfieldContainerType', 'uint_T');   % Bitfield declarator type specifier 
cs.set_param('BooleansAsBitfields', 'off');   % Pack Boolean data into bitfields 
cs.set_param('BufferReuse', 'on');   % Reuse block outputs 
cs.set_param('EnhancedBackFolding', 'on');   % Minimize data copies between local and global variables 
cs.set_param('InlineInvariantSignals', 'on');   % Inline invariant signals 
cs.set_param('InlineParams', 'on');   % Inline parameters 
cs.set_param('InlinedParameterPlacement', 'NonHierarchical');   % Parameter structure 
cs.set_param('LocalBlockOutputs', 'on');   % Enable local block outputs 
cs.set_param('MaxStackSize', 'inf');   % Maximum stack size (bytes) 
cs.set_param('PassReuseOutputArgsAs', 'Individual arguments');   % Pass reusable subsystem outputs as 
cs.set_param('RollThreshold', 5);   % Loop unrolling threshold 
cs.set_param('StrengthReduction', 'off');   % Simplify array indexing 

% Optimization:Stateflow pane
cs.set_param('DataBitsets', 'on');   % Use bitsets for storing Boolean data 
cs.set_param('StateBitsets', 'on');   % Use bitsets for storing state configuration 

% Diagnostics Solver pane
cs.set_param('AlgebraicLoopMsg', 'error');   % Algebraic loop 
cs.set_param('ArtificialAlgebraicLoopMsg', 'error');   % Minimize algebraic loop 
cs.set_param('BlockPriorityViolationMsg', 'error');   % Block priority violation 
cs.set_param('ConsistencyChecking', 'none');   % Solver data inconsistency 
cs.set_param('MaxConsecutiveZCsMsg', 'warning');   % Consecutive zero crossings violation 
cs.set_param('MinStepSizeMsg', 'warning');   % Min step size violation 
cs.set_param('ModelReferenceExtraNoncontSigs', 'none');   % Extraneous discrete derivative signals 
cs.set_param('SimStateInterfaceChecksumMismatchMsg', 'warning');   % SimState interface checksum mismatch 
cs.set_param('SimStateOlderReleaseMsg', 'error');   % SimState object from earlier release 
cs.set_param('SolverPrmCheckMsg', 'error');   % Automatic solver parameter selection 
cs.set_param('StateNameClashWarn', 'warning');   % State name clash 
cs.set_param('TimeAdjustmentMsg', 'none');   % Sample hit time adjusting 
cs.set_param('UnknownTsInhSupMsg', 'error');   % Unspecified inheritability of sample time 

% Diagnostics:Sample Time pane
cs.set_param('DiscreteInheritContinuousMsg', 'error');   % Discrete used as continuous 
cs.set_param('InheritedTsInSrcMsg', 'error');   % Source block specifies -1 sample time 
cs.set_param('MultiTaskCondExecSysMsg', 'error');   % Multitask conditionally executed subsystem 
cs.set_param('MultiTaskRateTransMsg', 'error');   % Multitask rate transition 
cs.set_param('SigSpecEnsureSampleTimeMsg', 'error');   % Enforce sample times specified by Signal Specification blocks 
cs.set_param('SingleTaskRateTransMsg', 'error');   % Single task rate transition 
cs.set_param('TasksWithSamePriorityMsg', 'error');   % Tasks with equal priority 

% Diagnostics:Data Validity pane
cs.set_param('ArrayBoundsChecking', 'none');   % Array bounds exceeded 
cs.set_param('AssertControl', 'DisableAll');   % Model Verification block enabling 
cs.set_param('CheckMatrixSingularityMsg', 'error');   % Division by singular matrix 
cs.set_param('CheckMatrixSingularityMsg', 'error');   % Division by singular matrix

cs.set_param('IntegerOverflowMsg', 'none');   % Detect overflow 
cs.set_param('MultiTaskDSMMsg', 'error');   % Multitask data store 
cs.set_param('ParameterDowncastMsg', 'error');   % Detect downcast 
cs.set_param('ParameterOverflowMsg', 'error');   % Detect overflow 
cs.set_param('ParameterPrecisionLossMsg', 'error');   % Detect precision loss 
cs.set_param('ParameterTunabilityLossMsg', 'error');   % Detect loss of tunability 
cs.set_param('ParameterUnderflowMsg', 'error');   % Detect underflow 
cs.set_param('RTPrefix', 'error');   % "rt" prefix for identifiers 
cs.set_param('ReadBeforeWriteMsg', 'EnableAllAsError');   % Detect read before write 
cs.set_param('SignalInfNanChecking', 'error');   % Inf or NaN block output 
cs.set_param('SignalRangeChecking', 'none');   % Simulation range checking 
cs.set_param('SignalResolutionControl', 'UseLocalSettings');   % Signal resolution 
cs.set_param('UnderSpecifiedDataTypeMsg', 'error');   % Underspecified data types 
cs.set_param('UnderspecifiedInitializationDetection', 'Simplified');   % Underspecified initialization detection 
cs.set_param('UniqueDataStoreMsg', 'error');   % Duplicate data store names 
cs.set_param('WriteAfterReadMsg', 'EnableAllAsError');   % Detect write after read 
cs.set_param('WriteAfterWriteMsg', 'EnableAllAsError');   % Detect write after write 

% Diagnostics:Type Conversion pane
cs.set_param('FixptConstOverflowMsg', 'none');   % Detect overflow 
cs.set_param('FixptConstPrecisionLossMsg', 'none');   % Detect precision loss 
cs.set_param('FixptConstUnderflowMsg', 'none');   % Detect underflow 
cs.set_param('Int32ToFloatConvMsg', 'warning');   % 32-bit integer to single precision float conversion 
cs.set_param('UnnecessaryDatatypeConvMsg', 'warning');   % Unnecessary type conversions 
cs.set_param('VectorMatrixConversionMsg', 'error');   % Vector/matrix block input conversion 

% Diagnostics:Connectivity pane
cs.set_param('BusNameAdapt', 'ErrorWithoutRepair');   % Repair bus selections 
cs.set_param('BusObjectLabelMismatch', 'error');   % Element name mismatch 
cs.set_param('FcnCallInpInsideContextMsg', 'EnableAllAsError');   % Context-dependent inputs 
cs.set_param('InvalidFcnCallConnMsg', 'error');   % Invalid function-call connection 
cs.set_param('NonBusSignalsTreatedAsBus', 'error');   % Non-bus signals treated as bus signals 
cs.set_param('RootOutportRequireBusObject', 'error');   % Unspecified bus object at root Outport block 
cs.set_param('SignalLabelMismatchMsg', 'error');   % Signal label mismatch 
cs.set_param('StrictBusMsg', 'ErrorOnBusTreatedAsVector');   % Mux blocks used to create bus signals 
cs.set_param('UnconnectedInputMsg', 'error');   % Unconnected block input ports 
cs.set_param('UnconnectedLineMsg', 'error');   % Unconnected line 
cs.set_param('UnconnectedOutputMsg', 'error');   % Unconnected block output ports 

% Diagnostics:Compatibility pane
cs.set_param('SFcnCompatibilityMsg', 'error');   % S-function upgrades needed 

% Diagnostics:Model Referencing pane
cs.set_param('ModelReferenceCSMismatchMessage', 'none');   % Model configuration mismatch 
cs.set_param('ModelReferenceDataLoggingMessage', 'error');   % Unsupported data logging 
cs.set_param('ModelReferenceIOMismatchMessage', 'error');   % Port and parameter mismatch 
cs.set_param('ModelReferenceIOMsg', 'error');   % Invalid root Inport/Outport block connection 
cs.set_param('ModelReferenceVersionMismatchMessage', 'warning');   % Model block version mismatch 

% Diagnostics:Saving pane
cs.set_param('SaveWithDisabledLinksMsg', 'error');   % Block diagram contains disabled library links 
cs.set_param('SaveWithParameterizedLinksMsg', 'error');   % Block diagram contains parameterized library links 

% Diagnostics:Stateflow pane
cs.set_param('SFInvalidInputDataAccessInChartInitDiag', 'warning');   % Invalid input data access in chart initialization 
cs.set_param('SFNoUnconditionalDefaultTransitionDiag', 'warning');   % No unconditional default transitions 
cs.set_param('SFTransitionOutsideNaturalParentDiag', 'warning');   % Transition outside natural parent 
cs.set_param('SFUnconditionalTransitionShadowingDiag', 'warning');   % Transition shadowing 
cs.set_param('SFUnexpectedBacktrackingDiag', 'warning');   % Unexpected backtracking 
cs.set_param('SFUnusedDataAndEventsDiag', 'warning');   % Unused data and events 

% Hardware Implementation pane
cs.set_param('ProdBitPerChar', 8);   % char 
cs.set_param('ProdBitPerInt', 32);   % int 
cs.set_param('ProdBitPerLong', 32);   % long 
cs.set_param('ProdBitPerShort', 16);   % short 
cs.set_param('ProdEndianess', 'LittleEndian');   % Byte ordering 
cs.set_param('ProdIntDivRoundTo', 'Zero');   % Signed integer division rounds to 
cs.set_param('ProdLargestAtomicFloat', 'None');   % floating-point 
cs.set_param('ProdLargestAtomicInteger', 'Char');   % integer 
cs.set_param('ProdShiftRightIntArith', 'on');   % Shift right on a signed integer as arithmetic shift 
cs.set_param('ProdWordSize', 32);   % native 

% Model Referencing pane
cs.set_param('EnableParallelModelReferenceBuilds', 'off');   % Enable parallel model reference builds 
cs.set_param('ModelDependencies', '');   % Model dependencies 
cs.set_param('ModelReferenceNumInstancesAllowed', 'Multi');   % Total number of instances allowed per top model 
cs.set_param('ModelReferencePassRootInputsByReference', 'on');   % Pass fixed-size scalar root inputs by value for code generation 
cs.set_param('ParallelModelReferenceMATLABWorkerInit', 'None');   % MATLAB worker initialization for builds 
cs.set_param('PropagateVarSize', 'Infer from blocks in model');   % Propagate sizes of variable-size signals 

% Simulation Target General pane
cs.set_param('SFSimEcho', 'on');   % Echo expressions without semicolons 
cs.set_param('SFSimEnableDebug', 'on');   % Enable debugging/animation 
cs.set_param('SFSimOverflowDetection', 'on');   % Enable overflow detection (with debugging) 
cs.set_param('SimBlas', 'on');   % Use BLAS library for faster simulation 
cs.set_param('SimBuildMode', 'sf_incremental_build');   % Simulation target build mode 
cs.set_param('SimCtrlC', 'on');   % Ensure responsiveness 
cs.set_param('SimIntegrity', 'on');   % Ensure memory integrity 

% Simulation Target:Custom Code pane
cs.set_param('SimCustomHeaderCode', '');   % Header file 
cs.set_param('SimCustomInitializer', '');   % Initialize function 
cs.set_param('SimCustomSourceCode', '');   % Source file 
cs.set_param('SimCustomTerminator', '');   % Terminate function 
cs.set_param('SimParseCustomCode', 'on');   % Parse custom code symbols 
cs.set_param('SimUserIncludeDirs', '');   % Include directories 
cs.set_param('SimUserLibraries', '');   % Libraries 
cs.set_param('SimUserSources', '');   % Source files 

% Code Generation General pane
cs.set_param('CheckMdlBeforeBuild', 'Off');   % Check model before generating code 
cs.set_param('GenCodeOnly', 'off');   % Generate code only 
cs.set_param('IgnoreCustomStorageClasses', 'off');   % Ignore custom storage classes 
cs.set_param('IgnoreTestpoints', 'on');   % Ignore test point signals 
cs.set_param('MakeCommand', 'make_rtw');   % Make command 
cs.set_param('ObjectivePriorities', '');   % Prioritized objectives 
cs.set_param('TLCOptions', '');   % TLC options 
cs.set_param('TargetLang', 'C');   % Language 
cs.set_param('TemplateMakefile', 'ert_default_tmf');   % Template makefile 

% Code Generation:Comments pane
cs.set_param('MATLABFcnDesc', 'off');   % MATLAB function help text 
cs.set_param('MATLABSourceComments', 'off');   % MATLAB source code as comments 

% Code Generation:Symbols pane
cs.set_param('CustomSymbolStrBlkIO', 'rtb_$N$M');   % Local block output variables 
cs.set_param('CustomSymbolStrFcn', '$N$M$F');   % Subsystem methods 
cs.set_param('CustomSymbolStrFcnArg', 'rt$I$N$M');   % Subsystem method arguments 
cs.set_param('CustomSymbolStrField', '$N$M');   % Field name of global types 
cs.set_param('CustomSymbolStrGlobalVar', '$N$M');   % Global variables 
cs.set_param('CustomSymbolStrMacro', '$N$M');   % Constant macros 
cs.set_param('CustomSymbolStrTmpVar', '$N$M');   % Local temporary variables 
cs.set_param('CustomSymbolStrType', '$N$M');   % Global types 
cs.set_param('DefineNamingRule', 'None');   % #define naming 
cs.set_param('InlinedPrmAccess', 'Literals');   % Generate scalar inlined parameters as 
cs.set_param('MangleLength', 4);   % Minimum mangle length 
cs.set_param('MaxIdLength', 31);   % Maximum identifier length 
cs.set_param('UseSimReservedNames', 'off');   % Use the same reserved names as Simulation Target 

% Code Generation:Custom Code pane
cs.set_param('CustomHeaderCode', '');   % Header file 
cs.set_param('CustomInclude', '');   % Include directories 
cs.set_param('CustomInitializer', '');   % Initialize function 
cs.set_param('CustomLibrary', '');   % Libraries 
cs.set_param('CustomSource', '');   % Source files 
cs.set_param('CustomSourceCode', '');   % Source file 
cs.set_param('CustomTerminator', '');   % Terminate function 
cs.set_param('RTWUseSimCustomCode', 'off');   % Use the same custom code settings as Simulation Target 

% Code Generation:Debug pane
cs.set_param('ProfileTLC', 'off');   % Profile TLC 
cs.set_param('RTWVerbose', 'off');   % Verbose build 
cs.set_param('RetainRTWFile', 'off');   % Retain .rtw file 
cs.set_param('TLCAssert', 'off');   % Enable TLC assertion 
cs.set_param('TLCCoverage', 'off');   % Start TLC coverage when generating code 
cs.set_param('TLCDebug', 'off');   % Start TLC debugger when generating code 

% Code Generation:Interface pane
cs.set_param('CombineSignalStateStructs', 'off');   % Combine signal/state structures 
cs.set_param('GenerateASAP2', 'off');   % Interface 
cs.set_param('GeneratePreprocessorConditionals', 'Disable all');   % Generate preprocessor conditionals 
cs.set_param('MultiInstanceErrorCode', 'Error');   % Reusable code error diagnostic 
cs.set_param('RootIOFormat', 'Individual arguments');   % Pass root-level I/O as 
cs.set_param('SupportAbsoluteTime', 'off');   % absolute time 
cs.set_param('SupportComplex', 'off');   % complex numbers 
cs.set_param('SupportVariableSizeSignals', 'off');   % variable-size signals 
cs.set_param('TargetFunctionLibrary', 'ANSI_C');   % Target function library 
cs.set_param('UtilityFuncGeneration', 'Shared location');   % Shared code placement 

% Code Generation:SIL and PIL Verification pane
cs.set_param('CodeExecutionProfileVariable', 'executionProfile');   % Workspace variable 
cs.set_param('CodeExecutionProfiling', 'off');   % Measure task execution time 
cs.set_param('CodeProfilingInstrumentation', 'off');   % Measure function execution times 
cs.set_param('CodeProfilingSaveOptions', 'SummaryOnly');   % Save options 
cs.set_param('CreateSILPILBlock', 'None');   % Create block 
%cs.set_param('CoverageToolSettings', 'BullseyeCoverage'); % Coverage tool
 

% Code Generation:Code Style pane
cs.set_param('ConvertIfToSwitch', 'off');   % Convert if-elseif-else patterns to switch-case statements 
cs.set_param('ParenthesesLevel', 'Maximum');   % Parentheses level 
cs.set_param('PreserveExpressionOrder', 'on');   % Preserve operand order in expression 
cs.set_param('PreserveExternInFcnDecls', 'on');   % Preserve extern keyword in function declarations 
cs.set_param('PreserveIfCondition', 'on');   % Preserve condition expression in if statement 
cs.set_param('SuppressUnreachableDefaultCases', 'off');   % Suppress generation of default cases for Stateflow switch statements if unreachable 

% Code Generation:Templates pane
cs.set_param('ERTCustomFileTemplate', 'example_file_process.tlc');   % File customization template 
cs.set_param('ERTDataHdrFileTemplate', 'ert_code_template.cgt');   % Header file (*.h) template 
cs.set_param('ERTDataSrcFileTemplate', 'ert_code_template.cgt');   % Source file (*.c) template 
cs.set_param('ERTHdrFileBannerTemplate', 'ert_code_template.cgt');   % Header file (*.h) template 
cs.set_param('ERTSrcFileBannerTemplate', 'ert_code_template.cgt');   % Source file (*.c) template 
cs.set_param('TargetOS', 'BareBoardExample');   % Target operating system 

% Code Generation:Code Placement pane
cs.set_param('ERTFilePackagingFormat', 'CompactWithDataFile');   % File packaging format 
cs.set_param('EnableDataOwnership', 'off');   % Use owner from mpt object for data definition placement 
cs.set_param('IncludeFileDelimiter', 'Auto');   % #include file delimiter 
cs.set_param('ParamTuneLevel', 10);   % Parameter tune level 
cs.set_param('SignalDisplayLevel', 10);   % Signal display level 

% Code Generation:Memory Sections pane
cs.set_param('MemSecDataConstants', 'Default');   % Constants 
cs.set_param('MemSecDataIO', 'Default');   % Inputs/Outputs 
cs.set_param('MemSecDataInternal', 'Default');   % Internal data 
cs.set_param('MemSecDataParameters', 'Default');   % Parameters 
cs.set_param('MemSecFuncExecute', 'Default');   % Execution 
cs.set_param('MemSecFuncInitTerm', 'Default');   % Initialize/Terminate 
cs.set_param('MemSecFuncSharedUtil', 'Default');   % Shared utility 
cs.set_param('MemSecPackage', '--- None ---');   % Package 

cs.set_param('AdvancedOptControl', '-SLCI');
