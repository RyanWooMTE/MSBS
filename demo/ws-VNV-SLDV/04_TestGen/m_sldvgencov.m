mdl = 'sldvdemo_cruise_control'; 
open_system(mdl);    % モデルを開く
cvto = cvtest(mdl);  % テストオブジェクトを定義
cvdo1 = cvsim(cvto); % シミュレーション(全入力==0)しカバレッジデータを作成
[stat, cvdo2] = sldvgencov(mdl,[],true,cvdo1); % 未達カバレッジを測定

cvhtml('combinedcov.html',cvdo1,cvdo2) % 合算カバレッジレポートを作成
