%%%%%%%%%%%%%%%%%%%% SDOxlsIFの使用例 %%%%%%%%%%%%%%%%%%%%

% あらかじめ提供のコマンド(xlssdoinfo/xlsreadsdo/xlswritesdo)、
% および使用する定義体ファイル(Simulink.xls, mpt.xls等)に
% MATLABパスを設定する必要があります。

% <<SDOxlsIFのインストールディレクトリ>>         例：C:\hoge\SDOxlsIF
% <<定義体ファイル格納ディレクトリ>>             例：C:\hoge\SDOxlsIF\JPN

% TestFile_JPN.xlsからデータオブジェクトをSimulinkパッケージとしてロードします。
xlsreadsdo('TestFile_JPN.xls', 'Simulink')

% SimulinkデータオブジェクトをTestFile_JPN_Simulink.xlsにセーブします。
% 注意：ファイルが既にある場合には上書きされます。
xlswritesdo('TestFile_JPN_Simulink.xls', 'Simulink')

% TestFile_JPN.xlsからデータオブジェクトをmptパッケージとしてロードします。
xlsreadsdo('TestFile_JPN.xls', 'mpt')

% mptデータオブジェクトをTestFile_JPN_mpt.xlsにセーブします。
% 注意：ファイルが既にある場合には上書きされます。
xlswritesdo('TestFile_JPN_mpt.xls', 'mpt')



%%%%%%%%%%%%%%%%%%%% MAT定義体ファイルの運用について %%%%%%%%%%%%%%%%%%%%

% 定義体情報は通常、XLS定義体ファイルから読み込まれます。
% XLS定義体ファイルの情報は、xlssdoinfoコマンドにより、
% MATLABワークスペース上に取り込む事ができます。

Simulink = xlssdoinfo('Simulink');% Simulinkパッケージの定義体情報
mpt = xlssdoinfo('mpt');% mptパッケージの定義体情報

% xlssdoinfoコマンドの戻り値を
% <<変数名＝パッケージ名、ファイル名＝パッケージ名>>
% としてMATファイルにセーブし、元のXLS定義体ファイルと同様に
% MATLABパス上に配置すると、XLS定義体ファイルの代わりに
% このMAT定義体ファイルから定義体情報が読み込まれるようになります。
% XLS定義体ファイルの代わりにMAT定義体ファイルを使用すると、
% 一般にxlsreadsdo/xlswritesdoの処理が高速化されます。

% Simulinkパッケージ用MAT定義体ファイルがJPNディレクトリに作成されます。
save('..\JPN\Simulink', 'Simulink')

% mptパッケージ用MAT定義体ファイルがJPNディレクトリに作成されます。
save('..\JPN\mpt', 'mpt')

% 注意；定義体ファイルに拡張子が明示指定されている場合には、その拡張子の定義体ファイルが使用されます。
% XLS定義体ファイルを使用
xlsreadsdo('TestFile_JPN.xls', 'Simulink.xls')
% MAT定義体ファイルを使用
xlswritesdo('TestFile_JPN_Simulink.xls', 'Simulink.mat')

% xlssdoinfo/xlsreadsdo/xlswritesdoコマンドには、これ以外にも
% さまざまな引数やオプションを指定できます。詳細はドキュメントを参照願います。
% また、XLS定義体ファイルの詳細につきましては以下のテンプレートファイルを参照願います。

% JPN\Simulink.xls ---> Simulinkパッケージ用テンプレートファイル（日本語）
% JPN\mpt.xls      ---> mptパッケージ用テンプレートファイル（日本語）
