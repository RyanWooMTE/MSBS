function setSignalBuilderReqLink(sigbuil,nGrp,xlsfile,sheet,range,description)
% setSignalBuilderReqLink  a helper function to create an RMI link in SignalBuilder block.
% sigbuil: a block handle of a SignalBuilder
% nGrp: Number of group which you want create a link
% xlsfile: Name of an Excel file
% range: A range of cell in the Excel sheet where you want to set the link
% description: A description of the link shown in the model

%   Copyright 2010-2011 The MathWorks, Inc.

if isSlVnVInstalled()
    relstr = version('-release');
    relyear = str2double(relstr(1:end-1));
    if relyear > 2007

        reqlink.doc = xlsfile;
        reqlink.reqsys = 'other';
        reqlink.keywords='';
        reqlink.linked = 1;
        reqlink.description=description;

        % String of range where the signal is defined
        reqlink.id=sprintf('$%s!%s',sheet,range);
        % call rmi command to set a link to requirement
        rmi('set',sigbuil,reqlink,nGrp)
    end
end
