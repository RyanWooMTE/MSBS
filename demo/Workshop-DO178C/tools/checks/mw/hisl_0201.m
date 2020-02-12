% Limitations:
% 1. Part B is not implemented. Not checkable.
%Consideration:
% 1. May add confusion to hisl_0032. Consider removing the rule and check
%    entirely.

% This check will flag any reserved keywords specified in the Model Advisor
% check input parameter that are not listed as keywords in the model
% configuration.
function resultDescription = hisl_0201(system)

resultDescription = {};

model = bdroot(system);
modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system); 
activeConfig = getActiveConfigSet(model);

reservedKeywords = activeConfig.get_param('SimReservedNameArray');
inputParamObj = modelAdvisorObject.getInputParameters;
inputParamVal = inputParamObj{1}.Value;

if ~isempty(inputParamVal)
    if isempty(reservedKeywords)
        report_paragraph = ModelAdvisor.Paragraph;
        report_text = ModelAdvisor.Text('No reserved keywords are specified in Simulation Configuration.');
        report_paragraph.addItem([report_text ModelAdvisor.LineBreak]);   
        report_text = ModelAdvisor.Text('Recommended Action:', {'bold'});
        report_paragraph.addItem([ModelAdvisor.LineBreak report_text ModelAdvisor.LineBreak]);
        report_text = ModelAdvisor.Text('Consider defining reserved keywords in the settings to prevent identifier clashes within the project namespace:');
        report_paragraph.addItem([report_text ModelAdvisor.LineBreak]); 
        link = Advisor.Utils.getHyperlinkToConfigSetParameter(model, 'SimReservedNameArray');
        report_paragraph.addItem([link ModelAdvisor.LineBreak]);
        resultDescription{end+1} = report_paragraph;
        
    else
        inputReservedKeywords = strtrim(strsplit(inputParamVal, ','));
        diff = setdiff(inputReservedKeywords, reservedKeywords);
        if ~isempty(diff)
            ft = ModelAdvisor.FormatTemplate('TableTemplate');
            setInformation(ft, 'Reserved Keywords specified in the configuration differ from the expected set:');
            ft.setColTitles({'Defined keywords','Missing keywords'});
            ft.addRow({reservedKeywords, diff});
            link = Advisor.Utils.getHyperlinkToConfigSetParameter(model, 'SimReservedNameArray');
            setRecAction(ft, ['Consider changing the defined reserved keywords in the settings: ' {link}]);
            resultDescription{end+1} = ft;
            
        else
            modelAdvisorObject.setCheckResultStatus(true);    
            resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
        end
    end
    
else
    % 
    modelAdvisorObject.setCheckResultStatus(true);    
    resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
end