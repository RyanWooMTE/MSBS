function out = isJapaneseEnv()
% isJapaneseEnv Check that whether your environment is Japanese or other

out = any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}));