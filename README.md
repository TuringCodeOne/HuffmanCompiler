# HuffmanCompiler
> 一个基于c语言的简易的哈夫曼编/译码器的设计与实现（控制台）

## 背景
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

`main.c`是程序的入口，`Header.h`为所有函数的声明


## 具备的功能

1. 初始化(Initialization)。从终端读入字符集大小n , 以及n个字符和n个权值，建立哈夫曼树，并将它存于文件hfmTree中。
2. 编码(Encoding)。利用已建好的哈夫曼树(如不在内存，则从文件hfmTree中读人)，对文件ToBeTran中的正文进行编码，然后将结果存入文件CodeFile中。
 3. 译码(Decoding)。利用已建好的哈夫曼树将文件 CodeFile 中的代码进行译码，结果存入文件TextFile中。
4. 打印代码文件(Print)。将文件CodeFile以紧凑格式显示在终端上，每行 50 个代码。同时将此字符形式的编码文件写入文件 CodePrin 中。
5. 打印哈夫曼树(Tree printing)。将已在内存中的哈夫曼树以直观的方式(树或凹入表形式)显示在终端上，同时将此字符形式的哈夫曼树写入文件TreePrint中。

## 实现
1. 在构造哈夫曼树时，使用结构体数组`HuffmanTree`作为哈夫曼树的存储，初始化功能从键盘接收字符集和字符所对应的权值。并使用这些数据按教材中的算法构造哈夫曼树，即将`HuffmanTree`各个节点的各个数据域都附初值，并通过相应变化，使这些数据通过下标建立一定的联系。哈夫曼编码使用一维数组`code`作为哈夫曼编码的存储。在初始化过程中既建立了树，也将各字符的编码遍历得到。
2. 编码操作，先打开`ToBeTran.txt`，并建立`tocode[SIZE]`存放从文件中读取到的编码的文件。并从数组开头起始，与`code`中的`character`字符相比较，若相等则输出该字符对应的`longchar`，依次遍历到最后。并将编码存入`codeFile.txt`文件中。
3. 译码操作，先打开`ToBeTran.txt`，并建立`tocode[SIZE]`存放从文件中读取到的编码的文件。并从数组开头起始，与`code`中的`character`字符相比较，若相等则输出该字符对应的`longchar`，依次遍历到最后。并将`0、1`代码串一一存入存入`codeFile.txt`文件中。
4. 译码功能，是打开文件`codfile.txt`，并从中读取`0、1`的的代码串于`temp[SIZE]`中，读取方式为一次仅读取一个`‘1’`或一个`‘0’`，按照初始化时建立的编码规则将其翻译成字符所组成的字符串形式，存入文件`textFile.txt`中。并且，在数组`temp[SIZE]`中，每翻译完一段`0、1`组成的字符串，就会被`voidStr[]=""`（空字符串）所覆盖，清空`temp[SIZE]`。
5. 打印哈夫曼树，需要打开树保存的文件hfmTree中读取每一个书的结点数据进行保存在一个数组之中`p = HT`;将p结点用`printree()`调到数组`HT`的最后一位，再将其传入`coprint(HuffmanTree start, HuffmanTree HT)`，进行递归输出，先输出其右子树，然后再输入其结点数据，最后输出左子树。设置全局变量n来控制行宽，以表现树的侧向长度。


## 使用方法
将项目pull到本地，使用IDE运行即可。

## 关于
Created by *PengTsinv*


