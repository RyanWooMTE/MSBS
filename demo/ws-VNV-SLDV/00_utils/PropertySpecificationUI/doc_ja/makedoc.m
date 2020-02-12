opts.evalCode=false;
opts.outputDir='.';
publish('description.m',opts);
publish('cd000_installation.m',opts);
publish('d001_format.m',opts);

  
%builddocsearchdb(pwd)
