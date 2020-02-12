function checkfixInfoxml()
% check '<help_location> in info.xml shows correct location. If it locates
% wrong location, this function automatically correct it.

% obtain sldvmisscovtool's install directory.
instdir = regexprep(fileparts(which('sldvmisscovtool')),'\\','\/');

checkfix_infoxml_helper(instdir,[instdir,'/doc_en']); % for English doc
checkfix_infoxml_helper([instdir,'/ja'],[instdir,'/doc']); % for Japanese doc

function checkfix_infoxml_helper(infodir,helpdir)
% helper function of checkfix_infoxml
isReplaced = false;
infofile = sprintf('%s/info.xml',infodir);
fidr = fopen(infofile,'r');
temporary_file = [tempname '.xml'];
fidw = fopen(temporary_file,'w');

tline = fgets(fidr);
while ischar(tline)
    help_location_str=regexp(tline,'<help_location>([^<]*)</help_location>','match','once');
    if ~isempty(help_location_str) % only focus a line including <help_location>
        help_location = regexprep(help_location_str,'<help_location>([^<]*)</help_location>','$1');
        if ~strcmp(help_location,helpdir) % wrong location
            fprintf(fidw,'<help_location>%s</help_location>\n',helpdir);
            isReplaced = true;
        else
            fprintf(fidw,'%s',tline);
        end    
    else
        fprintf(fidw,'%s',tline);
    end
    tline = fgets(fidr);
    
end
fclose(fidr);
fclose(fidw);
if isReplaced
    % info.xml file is modified only when correction is needed.
    copyfile(temporary_file,infofile);
    docroot(docroot); % refresh Help browser
    fprintf('%s is generated.\n',infofile)
else
    % otherwise, just remove temporary file.
    delete(temporary_file);
end
