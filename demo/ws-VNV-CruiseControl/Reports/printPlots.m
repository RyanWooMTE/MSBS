function PrintOutFigureHandle = printPlots(slrg, idx, type)
%% printOutputs Function to print output signals
%%to a figure

PrintOutFigureHandle = [];
PrintOutFigureHandle = figure;

%% needs to plot the expected output as well
% saved baseline is blue, and sim result is red

logsoutAct = get(slrg.simOut{idx}, 'logsout'); % current sim result
logsoutExp = slrg.EOlogsig{idx};  % expected output

if strcmp(type, 'in')
    
    inp = find_system(slrg.modelName, 'SearchDepth', 1, ...
        'BlockType', 'Inport');
    
    sigName = get_param(inp, 'Name');
    position = get(PrintOutFigureHandle,'Position');
    
    for i = 1:numel(sigName)
        
        subplot(numel(sigName), 1, i); hold;
        sigNew = eval(['get(logsoutAct,''', sigName{i}, ''')']);
        %plot(sigNew.Values.Time, sigNew.Values.Data);
        plot(sigNew.Values);
        ylabel(sigName{i}, 'Interpreter', 'none');
        title('');
        if i==numel(sigName)
            xlabel('Time (seconds)', 'Interpreter', 'none');
        end
        
    end
    
    position(4) = 150*numel(sigName);
    set(PrintOutFigureHandle,'Position',position);
    
else
    
    sigName = get_param([slrg.harnessModel, '/Test Unit'], 'OutputSignalNames');
    position = get(PrintOutFigureHandle,'Position');
    
    for i = 1:numel(sigName)
        
        subplot(numel(sigName), 1, i);hold;
        sigExp = eval(['get(logsoutExp,''', sigName{i}, ''')']);
        plot(sigExp.Values);
        sigNew = eval(['get(logsoutAct,''', sigName{i}, ''')']);
        plot(sigNew.Values, 'r');
        ylabel(sigName{i}, 'Interpreter', 'none');
        if i==numel(sigName)
            xlabel('Time (seconds)', 'Interpreter', 'none');
        end
        
    end
    
    position(4) = 200*numel(sigName);
    set(PrintOutFigureHandle,'Position',position);
    
end

%close(PrintOutFigureHandle);
