opts.evalCode=false;
opts.outputDir='.';
publish('sldvmisscovtool_doc_details.m',opts);
publish('sldvmisscovtool_doc_gettingstarted.m',opts);
publish('sldvmisscovtool_doc_overview.m ',opts);
builddocsearchdb(pwd)
