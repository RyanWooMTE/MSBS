function asts = getASTsFromSLCIMFn(slciMFunctionObj)
    mEMChart = slciMFunctionObj.fEMChart;
    mEMChart.prepareAst;
    functionAstMap = mEMChart.fFuncIDToAst;
    asts = functionAstMap.values;