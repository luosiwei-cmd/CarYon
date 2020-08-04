# CarYon：一款基于C++的OI/ACM 比赛测试数据生成器

![img](https://img.shields.io/badge/Avatar-luosw-red.svg) ![img](https://img.shields.io/github/package-json/v/luosiwei-cmd/caryon) ![img](https://img.shields.io/npm/dm/datamaker-caryon) ![img](https://img.shields.io/npm/dt/datamaker-caryon) ![](https://img.shields.io/npm/l/datamaker-caryon) ![img](https://img.shields.io/npm/v/datamaker-caryon)

在举办自己的OI比赛的时候，你有没有遇到过以下问题：

- 想快速生成一段文字？
- 想快速进行数学运算来生成数据？
- 想不用freopen等时间一个一个的生成测试数据？
- 希望生成一组随机数据或者数列？
- 快速生成数据来和两个程序对拍？

那么，你可以借助CarYon和C++，来快速生成数据。目前支持的特性有：

- 随机生成一段文章，一些单词，一些字母
- 脱离RAND_MAX的限制，自由拟定随机数
- 正在开发的数学库，支持多种特性
- 建一些圆形，正多边形和分数，用它来进行运算

## 使用 CarYon

CarYon 采用 C++ 编写，在安装好 C++ 的计算机上，只需要 include `caryon.h` 就可以使用内含的多种功能啦。

如果您对 C++ 不熟悉，请查看 C++ 快速入门 Wiki