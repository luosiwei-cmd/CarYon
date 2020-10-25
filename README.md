<h1 align="center">CarYon</h1>
<p align="center">一款基于C++的OI/ACM 比赛出题解题辅助工具</p>

![img](https://img.shields.io/badge/Avatar-luosw-red.svg) ![img](https://img.shields.io/github/package-json/v/luosiwei-cmd/caryon) ![img](https://img.shields.io/npm/dm/datamaker-caryon) ![img](https://img.shields.io/npm/dt/datamaker-caryon) ![img](https://img.shields.io/npm/l/datamaker-caryon)  ![img](https://img.shields.io/github/commit-activity/m/luosiwei-cmd/CarYon)

<p align="center">中文版文档：<a href="https://github.com/luosiwei-cmd/CarYon/wiki">Wiki</a></p>

<p align="center"><b>下面仅为文档摘要，详细中文文档请查看 <a href="https://github.com/luosiwei-cmd/CarYon/wiki">Wiki</a>。</b></p>

## CarYon 介绍

CarYon 是一款基于C++的OI/ACM 比赛出题解题辅助工具。

CarYon 可以被用来生成测试用例，并且迅速地通过标准程序生成输出文件；也可以被用来在赛场上进行迅速生成样例对拍程序。

CarYon 也可以作为一个现场生成样例的线下简易评测系统。内置三种比较器。支持 `AC,WA,TLE,UKE,RE` 等多种情况的判断。

您要是认为 CarYon 中的重中之重（详见 Wiki：`test.cpp`）的编写过于复杂，在生成样例要求简单的情况下，可以使用 CarYon 的配置文件生成功能。

## 快速开始

### 1. 安装 CarYon

访问 Wiki 了解如何下载 CarYon 后直接执行：

```cpp
#include"caryon.h"
```

就可以啦。

### 2. 升级 CarYon

直接用新的版本替换掉老版本，自行克服兼容问题。

请优先克隆 master 分支，其他分支无法保持稳定。

## 功能特性

CarYon 可以被分为下面几个板块：

- [x] 测试用例生成
- [x] 评测程序（对拍）
- [x] 数学库
- [x] 解析几何库
- [x] 配置文件生成
- [ ] （未完成）线下图形化评测系统

## Star 趋势
![Star](https://starchart.cc/luosiwei-cmd/caryon.svg)

## 协议

ISC 开源协议。
