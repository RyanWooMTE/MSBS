function define_ModelAdvisorChecks
mdladvRoot = ModelAdvisor.Root;

%   Copyright 2012 The MathWorks, Inc. 

% 
rec = ModelAdvisor.Check('com.mathworks.slapi.sample1');
rec.Title = '[○〇ルール001]ブロックの向きのチェック';
rec.TitleTips = 'ブロックの向きが左右以外のブロックを探索します';
rec.setCallbackFcn(@mycheck1_callback,'None','StyleOne');
mdladvRoot.publish(rec, '○〇チェック');

rec = ModelAdvisor.Check('com.mathworks.slapi.sample2');
rec.Title = '[○〇ルール002]Switchブロックの判定条件をチェック';
rec.TitleTips = 'Switchブロックの判定条件が u2 >= 0 でないことをチェックします';
rec.setCallbackFcn(@mycheck2_callback,'None','StyleOne');
% Define an automatic fix action for this check
modifyAction = ModelAdvisor.Action;
modifyAction.setCallbackFcn(@mycheck2_action);
modifyAction.Name = 'Swtichブロックの設定を自動修正';
modifyAction.Description = 'Switchブロックの判定条件が u2 >= 0 に設定されている場合、u2 ~= 0 に修正します';
modifyAction.Enable = true;
rec.setAction(modifyAction);
mdladvRoot.publish(rec, '○〇チェック');

