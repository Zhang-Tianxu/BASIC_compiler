# Minimal BASIC interpretor
这是我第一次动手写几百行的程序，花了几天的时间总算是完成了基本的功能。虽然**结构不太清晰，某些代码也比较乱**，但还是值得纪念的。:v:
## 功能介绍
&emsp;因为是简单翻译器，所有功能有限。    
&emsp;进入执行文件后，通过数字开头的字符串来编写程序。字符串开头的**数字用于对程序简单的编辑**，程序会按照数字递增的顺序存储和执行。
输入重复的数字会**替换**之前的输入，单独输入数字会**删除**该语句。语句中各部分之间以空格分开。
程序中只有**REM（注释）、LET（赋值）、INPUT（输入）、GOTO（跳转）、IF THEN（分支）、PRINT（打印）、END（结束）**
几个关键字，并且规定程序中的LET、INPUT、PRINT的数据类型都只能是整型（INT）。    
&emsp;输入的程序会被存储。并且通过直接输入命令（不以数字开头）来进行操作。
命令包括：**RUN（执行程序）、LET（赋值）、INPUT（输入）、CLEAR（清除程序）、PRINT（打印变量）、LIST（打印程序）、HELP（获取帮助）、QUIT（结束）**

## 具体使用
### 程序中关键字
1. REM（注释）    
*REM 注释内容*。例如：
> 100  REM Program to print the Fibonacci sequence 
2. LET（赋值）    
*LET variable（变量） = expression（表达式）*。例如：
> 110 LET n1 = 100
3. INPUT（输入）    
*INPUT variable（变量）*。例如：
> 120 INPUT n1
4. GOTO（跳转）    
*GOTO n（语句编码）*。例如：
> 130 GOTO 100
5. IF/THEN（分支）    
*IF expression1（表达式1） (> or = or <) expression2（表达式2） THEN n（语句编码）*。例如：
> 140 IF n1 > 100 + 10 * 2 THEN 100
6. PRINT（打印）    
*PRINT expression（表达式)*。例如：
> 150 PRINT 123
7. END（结束）    
*END*。例如：
> 160 END
### 操作命令语句
1. RUN（执行程序）    
*RUN*。例如：
> RUN
2. LET（赋值）    
*LET variable（变量） = expression（表达式）*。例如：
> LET x = y + z
3. INPUT（输入）    
*INPUT variable（变量）*。例如：
> INPUT y
4. CLEAR（清除程序）    
*CLEAR*。例如：
> CLEAR
5. PRINT（打印变量）    
*PRINT expression（表达式）*。例如：
> PRINT (x + 10) * 100
6. LIST（打印程序）    
*LIST*。例如：
> LIST
7. HELP（获取帮助）    
*HELP*。例如：
> HELP
8. QUIT（结束）    
*QUIT*。例如：
> QUIT

## 例子

```

100 REM Program to print the Fibonacci sequence
110 LET max = 10000
120 LET n1 = 0
130 LET n2 = 1
140 IF n1 > max THEN 190
150 LET n3 = n1 + n2
160 LET n1 = n2
170 LET n2 = n3
180 GOTO 140
190 END

RUN

145 PRINT n2
145 PRINT n1
135 LET x = 2
135

LIST

100 REM Program to print the Fibonacci sequence
110 LET max = 10000
120 LET n1 = 0
130 LET n2 = 1
140 IF n1 > max THEN 190
145 PRINT n1
150 LET n3 = n1 + n2
160 LET n1 = n2
170 LET n2 = n3
180 GOTO 140
190 END


RUN
0
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765

QUIT
```
