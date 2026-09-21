# 3wd_mecanums
## はじめに
部室に余っているメカナムで3輪メカナム作ってみました。<br>
理論上可能なので。
<!-- 概要はzennの記事[タイトル](https://zenn.dev/)にて公開しています。そちらを読んでいただければよいかと。 -->

## 各仕様説明
### programs
<pre>
programs/3wd_mecanums/
├── 3wd_mecanums.ino                          # main
├── config.h                                  # 定数等
├── MecanumControll.h                         # メカナム運動学計算のヘッダー
├── MecanumControll.cpp                       # メカナム運動学計算の実装
├── AMT.h                                     # AMT10エンコーダヘッダー
├── AMT.cpp                                   # AMT10エンコーダ実装
├── pid.h                                     # pid計算のヘッダー
└── pid.cpp                                   # pid計算の実装
</pre>

3輪メカナムの制御プログラム。
`config.h`の`CHASSY_TIPE`を0～2選択で各機種変換行列の切り替えができます。

### cad
3機種の3D CADファイル（Autodesk Inventor利用）

## 仕様ソフトウェアおよびバージョン
- ESP32Wroom*
- Arduino IDE（バージョン）
- Autodesk Inventor 2027

## リポジトリ構成
<pre>
.
├── README.md
├── .gitignore
├── programs/
│   └── 3wd_mecanums/                         # 制御プログラム（Arduino）
└── cad/
    ├── 3wd_mecanum.ipj                       # Inventorプロジェクトファイル
    ├── common_parts/                         # 共通パーツ（メカナムホイール、モータ等）
    ├── mecanum1/                             # 3輪オムニ配置機
    ├── mecanum2/                             # 対向2輪配置機
    ├── mecanum3/                             # 
    └── step/                                 # 各機STEP版
</pre>
