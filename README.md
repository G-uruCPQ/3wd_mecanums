# 3wd_mecanums
## はじめに
部室に余っているメカナムで3輪メカナム作ってみる<br>
理論上可能なので。
<!-- 概要はzennの記事[タイトル](https://zenn.dev/)にて公開しています。そちらを読んでいただければよいかと。 -->

## 各仕様説明
### programs
<pre>
programs/3wd_mecanums/
├── 3wd_mecanums.ino                          # main
├── config.h                                  # 定数等
├── mecanums.h                                # 採用した型の逆運動学テンソル
├── MecanumControll.h                         # メカナム運動学計算のヘッダー
├── MecanumControll.cpp                       # メカナム運動学計算の実装
├── DCMotor.h                                 # モータ駆動ヘッダー
├── DCMotor.cpp                             　# モータ駆動の実装
├── AMT.h                                     # AMT10エンコーダヘッダー
├── AMT.cpp                                   # AMT10エンコーダ実装
├── pid.h                                     # pid計算のヘッダー
├── pid.cpp                                   # pid計算の実装
├── myBLEController.h                         # MicroBlue復号ヘッダー
└── myBLEController.cpp                       # MicroBlue復号実装
</pre>

3輪メカナムの制御プログラム。
~~`config.h`の`CHASSY_TIPE`を0～2選択で各機種変換行列の切り替えができます。~~
何種類か作るつもりでしたが、<!-- 主に余裕の面から -->1種類だけになりました。

### cad
<!-- 3機種の -->3D CADファイル（Autodesk Inventor利用）

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
    ├── standard_assy/                        # 駆動基幹ユニット
    ├── mecanum1/                             # 3輪オムニ配置機
    └── step/                                 # STEP版
</pre>
