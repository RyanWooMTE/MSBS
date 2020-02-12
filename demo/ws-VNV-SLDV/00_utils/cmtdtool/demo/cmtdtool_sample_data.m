% クルーズコントロール定数定義ファイル

% 車速 最大・最小
speed_max = 300;
speed_min = -50;

% 目標車速 最大・最小
target_max = 100;
target_min = 40;

% スロットル開度 最大･最小
throt_max = 1;
throt_min = 0;

% 加速値・減速値
vel_inc = 1;
vel_dec= 1;

% PIコントローラ 比例・積分ゲイン値
cruise_kp = 0.02;
cruise_ki = 0.01;
