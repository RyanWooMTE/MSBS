cmtdtool

[概要]
 cmtdtoolは制御モデルの検証に利用可能な補助ツールです。
 当初、このツールは、JMAAB-CMTD-WS (JMAAB: Japan MBD Automotive Advisory Board, 
 CMTD-WS: 制御モデル検証設計(Contol Model Test Design) Working Group)向けに
 作成されましたが、数度の改変を経て、MATLAB Centralから一般に公開されました。
 制御モデルのテストを実施する際には、テスト設計、テストモデルの構築、テスト実行、
 レポートが行われますが、このツールは、これらのフェーズにおいて必要となる
 手作業を可能な限り削減し、自動化します。

[インストール方法と実行方法]
(1) cmtdtool.zip を適当なフォルダに展開
(2) 上記(1)のフォルダをMATLABのパスに追加
(3) 展開したフォルダに含まれる次をMATLAB上で実行
 >> cmtdtool_setup

※ このファイルの実行により、cmtdtoolのヘルプを利用環境で使用できるように
設定します。この設定には、MATLABバージョンに合わせた文字コード設定(SJIS,UTF-8)
および、ヘルプの設定に必要なinfo.xmlファイル内のパス情報を設定します。

(4) コマンドウィンドウ上で次のコマンドを実行することによりcmtdtoolを起動
>> cmtdtool

[更新履歴]
* 2010/06/29 JMAAB-CMTD-WS向けに初版公開
* 2010/08/04 JMAAB-CMTD-WS向けに修正版公開
* 2010/11/04 JMAAB-CMTD-WS向けにv0.8公開
* 2011/02/14 JMAAB-CMTD-WS向けにv0.9公開
* 2011/05/27 MATLAB Centralにv1.0をアップロード
* 2011/12/28 MATLAB Centralにv1.1をアップロード
