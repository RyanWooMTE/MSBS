function l = getModelList(argin)
   l1 = dir('*.slx');
   l2 = dir('*.mdl');
   l= [l1' l2']';
end
