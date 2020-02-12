function ResultDescription = hisl_0031(system)
ResultDescription={};

modelName = bdroot(system);
report_paragraph = ModelAdvisor.Paragraph;
modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system); 

modelNameLen = length(modelName);
if modelNameLen <= 2 || modelNameLen > 64
    report_text = ModelAdvisor.Text(['Model Name:', modelName, ' does not conform to the naming guidelines.']);
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
    report_text = ModelAdvisor.Text('Recommended Action:',{'bold'});
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
    report_text = ModelAdvisor.Text('The model name should use strings that are more than 2 and less than 64 characters.');
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
    ResultDescription{end+1} = report_paragraph;
elseif modelName(end) == '_'
    report_text = ModelAdvisor.Text(['Model Name: ', modelName, ' does not conform to the naming guidelines.']);
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak ModelAdvisor.LineBreak]);
    report_text = ModelAdvisor.Text('Recommended Action:',{'bold'});
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
    report_text = ModelAdvisor.Text('The model name should not use underscores at the end of a string.');
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
    ResultDescription{end+1} = report_paragraph; 
elseif ~isempty(regexp(modelName, '.*__.*', 'once'))
    report_text = ModelAdvisor.Text(['Model Name: ', modelName, ' does not conform to the naming guidelines.']);
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak ModelAdvisor.LineBreak]);
    report_text = ModelAdvisor.Text('Recommended Action:',{'bold'});
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
    report_text = ModelAdvisor.Text('The model name should not use more than one consecutive underscore.');
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
    ResultDescription{end+1} = report_paragraph; 
else
    modelAdvisorObject.setCheckResultStatus(true);    
    ResultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
end