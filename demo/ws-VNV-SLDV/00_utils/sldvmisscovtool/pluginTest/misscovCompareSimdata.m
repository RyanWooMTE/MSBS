function misscovCompareSimdata(simdata1,simdata2)
% helper function for plugin testing of sldvmisscovtool
% Comare two simdata variable

if isequal(simdata1,simdata2)
    disp('[Pass]: simdata1 and simdat2 is identical')
else
    if ~subcompareSimdata(simdata1,simdata2)
        disp('!! Data is not correctly translated. !!')
        assignin('base','simdata1',simdata1);
        assignin('base','simdata2',simdata2);
    else
        disp('[Pass]: simdata1 and simdat2 is equivalent but is not exact match')
    end
end

function out =  subcompareSimdata(simdata1,simdata2)
out = true;
if ~isequal(size(simdata2),size(simdata1))
    disp('Size is different')
    simdata1, simdata2 %#ok
    out = false;
    return;
end
for n=1:length(simdata1)
    fprintf('%% Comparing with simdata1(%d) and simdata2(%d) %%\n',n,n)
    if ~isequal(simdata1(n).time,simdata2(n).time)
        fprintf('  simdata1(%d).time:',n)
        fprintf('%g,',simdata1(n).time)
        fprintf('\n')
        fprintf('  simdata2(%d).time:',n)
        fprintf('%g,',simdata2(n).time)
        fprintf('\n')
        if isequal(size(simdata1(n).time),size(simdata2(n).time))
            fprintf('  Diff:')
            fprintf('%g,',simdata1(n).time-simdata2(n).time)
            fprintf('\n')
        end
        if  max(abs(simdata1(n).time-simdata2(n).time))>eps*10
            % time data is always double so exact matching is not needed.
            disp('[Alert] Time data is different')
            out = false;
            return;
        else
            disp('  Differences are small enough')
        end
    end
        if ~isequal(simdata1(n).signals,simdata2(n).signals)
            fprintf('simdata1(%d).signals:\n',n)
            simdata1(n).signals
            fprintf('simdata2(%d).signals:\n',n)
            simdata2(n).signals
            out = false;
            for m=1:length(simdata1(n).signals)
                if ~isequal(simdata1(n).signals(m),simdata2(n).signals(m))
                    fprintf('simdata1(%d).signals(%d):\n',n,m)
                    simdata1(n).signals(m)
                    fprintf('simdata2(%d).signals(%d):\n',n,m)
                    simdata2(n).signals(m)
                    if ~isequal(simdata1(n).signals(m).values,simdata2(n).signals(m).values)
                        %
                        %                     if isfloat(simdata1(n).signals(m).values) && ...
                        %                             max(abs(simdata1(n).signals(m).values-simdata2(n).signals(m).values))<eps*10
                        %                         out = true;
                        %                     end
                        fprintf('simdata1(%d).signals(%d).values:\n',n,m)
                        fprintf('%g,',simdata1(n).signals(m).values)
                        fprintf('\b\n')
                        fprintf('simdata2(%d).signals(%d).values:\n',n,m)
                        fprintf('%g,',simdata2(n).signals(m).values)
                        fprintf('\b\n')
                    end
                end
            end
        end
    end
