% すべてのデモを自動実行するテストスクリプト

clear all
bdclose all

startup_demo
rundemo_helper('openTopModel')
rundemo_helper('openCtrlModel')
rundemo_helper('openCtrlChildMdl')
rundemo_helper('runSimMesureCov')
rundemo_helper('getGenCovChild')
rundemo_helper('runTestGenerationChild')
rundemo_helper('runTestGenerationChildFixpt')
rundemo_helper('openReqSpec')
rundemo_helper('makeTraceabilityReport')
rundemo_helper('openModelAdvisor')
rundemo_helper('runMAABCheck') 
rundemo_helper('openPropModelError')
rundemo_helper('runPropProveError')
rundemo_helper('openPropModel')
rundemo_helper('runPropProve')
rundemo_helper('genCodeGenFloatModel')
rundemo_helper('genCodeGenFixedModel')
rundemo_helper('runTestGen_MILSIL_Back2BackReport_Fixed')
