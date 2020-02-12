% Please ignore. Rule to be removed.
function [ResultDescription] = hisl_0055(system)

ResultDescription = {};

highPriorityObjectives = {'Traceability', 'Safety precaution'};
model = bdroot(system);
activeConfig = getActiveConfigSet(model);
modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system); 
modelAdvisorObject.setCheckResultStatus(false);

report_paragraph = ModelAdvisor.Paragraph;

% Check that highest priority is assigned to
% high-integrity and traceability objectives (Safety precaution and Traceability)
objectivePriorities = activeConfig.get_param('ObjectivePriorities');
if isempty(objectivePriorities)
    report_text = ModelAdvisor.Text('Code generation objectives are not set.');
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
    ResultDescription{end+1} = report_paragraph;
    
elseif ~isempty(setdiff(highPriorityObjectives, objectivePriorities(1:2)))       
    report_text = ModelAdvisor.Text(['Consider assigning top two priority to "',highPriorityObjectives{1}, '" and "', highPriorityObjectives{2}, '" in: ']);
    report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
    link = Advisor.Utils.getHyperlinkToConfigSetParameter(model, 'ObjectivePriorities');
    report_paragraph.addItem([link ModelAdvisor.LineBreak]);
    ResultDescription{end+1} = report_paragraph;
    
else
    chkModelBeforeCodeGeneration = activeConfig.get_param('CheckMdlBeforeBuild');
    % Check that the Code Generation Advisor is configured to run before 
    % generating code by setting "Check model before generating code" to On (proceed with warnings) or On (stop for warnings).
    if strcmp(chkModelBeforeCodeGeneration, 'Off')
        report_text = ModelAdvisor.Text('Consider configuring the Code Generation Advisor to run before generating code by setting:');
        report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
        report_text = ModelAdvisor.Text('"Check model before generating code" to On (proceed with warnings) or On (stop for warnings) in:');
        report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);
        link = Advisor.Utils.getHyperlinkToConfigSetParameter(model, 'CheckMdlBeforeBuild');
        report_paragraph.addItem([link ModelAdvisor.LineBreak]);
        ResultDescription{end+1} = report_paragraph;

    else
        modelAdvisorObject.setCheckResultStatus(true);    
        ResultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});

    end
end
    

