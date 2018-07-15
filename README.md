# HuffmanCompiler
> 一个基于c语言的简易的哈夫曼编/译码器的设计与实现（控制台）

### 背景
利用哈夫曼编码进行通信可以大大提高信道利用率，缩短信息传输时间，降低传输成本。但是，这要求在发送端通过一个编码系统对待传数据预先编码，在接收端将传来的数据进行译码(复原)。对于双工信道(即可以双向传输信息的信道)，每端都需要一个完整的编 /译码系统。

## 程序目录结构如下
```
G:\COMPILER
|   README.md
|
+---header
|       Header.h
|
\---source file
        codeFile.txt
        CodePrin.txt
        copyData.bin
        Header.c
        hfmTree.txt
        main.c
        TextFile.txt
        ToBeTran.txt
```

`main.c`是程序的入口，`Header.h`为所有函数的定义


### 具备的功能

1. 初始化(Initialization)。从终端读入字符集大小n , 以及n个字符和n个权值，建立哈夫曼树，并将它存于文件hfmTree中。
2. 编码(Encoding)。利用已建好的哈夫曼树(如不在内存，则从文件hfmTree中读人)，对文件ToBeTran中的正文进行编码，然后将结果存入文件CodeFile中。
 3. 译码(Decoding)。利用已建好的哈夫曼树将文件 CodeFile 中的代码进行译码，结果存入文件TextFile中。
4. 打印代码文件(Print)。将文件CodeFile以紧凑格式显示在终端上，每行 50 个代码。同时将此字符形式的编码文件写入文件 CodePrin 中。
5. 打印哈夫曼树(Tree printing)。将已在内存中的哈夫曼树以直观的方式(树或凹入表形式)显示在终端上，同时将此字符形式的哈夫曼树写入文件TreePrint中。

### 使用方法
将项目pull到本地，使用IDE运行即可。

### 关于
Create by *PengTsinv*


