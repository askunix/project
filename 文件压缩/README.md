http://askunix.top/



### 文件压缩小项目总结

本项目采用Huffman编码的方式进行文件压缩与解压缩。主要原理是通过Huffman编码来表示字符，出现次数多的编码短，出现次数少的编码长，这样整体而言，所需要的bit位是减少的，就实现了文件压缩功能。



### 需求分析

  输入：文本文件(压缩文件)

  输出：压缩文件/解压文件(文本文件)  (压缩时间)

  知识点：堆、霍夫曼树、二叉树遍历、存储数据结构设计、文件流操作、字符汉字编码方式、二进制文件读写、优先级队列。


### 模块及框架设计

主要模块：

1、压缩模块
2、解压模块

辅助模块：

1、字符识别及权重获取
2、Huffman树构造
3、获取huffman编码



### 压缩步骤

1、统计字符出现的次数

因为文件底层都是有256个字符存储的，所以使用一个256的数组来统计字符出现的次数。在项目中，使用了一个结构体，将次数、字符、huffman编码对应起来。因为不管是文件、图片、音频、视频。他们的底层都是以字符形式存储的，读取的时候就按照字符格式读取。

2、构建huffman树

采用Huffman编码，将一组集合中权值最小的两棵树拿出来构建一棵树，选择权值最小的两棵树拿出来构建一棵树，再将权值之和作为节点插入到这个集合中，不断重复，直到集合中只有一个树，寻找最小的两棵树，利用了priority_queue，在这里将字符出现的次数作为权值。

3、生成huffman编码

从根节点出发，向左走为0，向右走为1，每次走一步，都将这个节点的huffman编码存储下来，直到走到叶子结点，huffman编码就能用递归直接获得。

4、将Huffman编码写入文件

使用哈希表，可以实现在O(1)时间内找到字符对应的编码，将每八位编码构成一个字符按“位”写入文件中。如果最后几位不够8位，在后面补0。最后解码时，根据字符个数，实现解压缩，总的字符个数就是Huffman数根节点的权值。


### 解压缩步骤

1、读取解压文件
读取文件中每个字符出现的次数，便于还原Huffman树。

2、构建huffman树
构建Huffman树和压缩时的构建是一样的。

3、解压

首先在压缩文件中读取一个字符，然后解析这个字符的每一位，遇到一个叶子结点，就代表还原了一个字符，这时就将这个字符写到解压缩文件里。需要注意的是此时最后几位编码可能是自己补上去的，所以要用源文件中字符出现的次数来控制解压缩，根据Huffman性质可知，根节点权重就是字符出现的次数。



### 项目中遇到的问题

1、解压缩时解压不完全

由于使用文本形式读取压缩文件，有可能提前遇到文件结束标志，所以要改为二进制形式读写。二进制形式是读取二进制编码。

如果以文本形式读取的话，回车会被当成一个字符'\n'，而二进制形式则会认为它是两个字符即'\r'回车、'\n'换行；如果在文本形式中遇到0x1B的话，文本形式会认为这是文本结束符，而二进制模型则不会对它产生处理。

2、得到huffman编码

在压缩时我们要求解huffman编码，在这里可以使用stl中的string和reverse求解。也可以使用后序递归直接求解。


3、压缩汉字时出现问题
因为汉字是由多个字符表示，这些字符的范围是0—255,所以在结构体中要用unsigned char表示。


 4、对文本文件最后一个字符的处理
 补位数：压缩，解压无错误


### 改进方法

1、解压缩的时候有可能要解压缩文件的不是用huffman进行压缩的文件。所以再解压文件之前先判断是不是用huffman进行压缩的。

2、不使用配置文件时如何解压
    可以将huffman树的信息写入到压缩文件中。


###项目扩展
1、实现对文件夹的压缩
对文件夹进行压缩实际上还是对文件夹中的内容进行压缩，所以得到一个文件夹之后我们就一直向子文件夹中找，直到找到文件后进行压缩就可以了。
2、解压缩的时候要将文件夹还原出来。




### 踩过的坑

1、使用ifstrem和ofsteam函数对文本进行输出输入操作时，最好写成以二进制方式，否则可能会出现读取到特殊符号而终止，导致解压缩不完全，二进制方式如下：

```c++
ifstream ifs(filename,ios::in|ios::binary);
ofstream ofs(filename,ios::out|ios::binary);
```

2、对字符进行直接定址确定自己在哈希表中的位置时，要注意使用(unsigend char)ch强转，因为哈希表的定义范围是0到255，而字符的大小是-127到128

3、创建huffman树时，因为节点中保存的是一个结构体而不是一个简单的内置类型，因此在对节点进行“比较”操作的时候需要自己重载这些比较操作符，如：

```C++
bool operator>(const T& t);
bool operator!=(const T& t);
```


