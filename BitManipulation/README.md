# BitManipulation
note:
- 感觉位操作可以解决某些hash的题，时间更快！！

### 187 重复DNA序列 **
思路：简单的hash法就对10个char构成的string作为key，位操作的话对ACGT进行二进制编码，这样10个char就变成最大值为1048576(2^10)的int hash，然后就可以用位操作替代字符串的substr操作，可以节省很多的时间
