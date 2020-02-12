% ハーネスモデルの作成

% モデルを開く
open_system('m_modelcov02')

% ハーネス生成オプションの設定
hopts = slvnvharnessopts;
hopts.modelRefHarness = 0;

% ハーネスモデルの作成
slvnvmakeharness(bdroot,[],hopts)

