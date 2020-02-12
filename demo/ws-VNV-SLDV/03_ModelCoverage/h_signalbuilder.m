% モデルを開く
open_system('m_modelcov02_harness')
% SignalBuilderブロック
blk = 'm_modelcov02_harness/Inputs';

% 現在格納されている全信号を取得
[time,data,sig,grp] = signalbuilder(blk);

% 新しく作成したデータを追加
newtime = [0 1 2];
newdata = {[0 1 0];[0 1 0];[0 1 0];[0 1 0];[0 1 0]};
signalbuilder(blk,'append',newtime,newdata)
