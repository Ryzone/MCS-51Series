00:01

我们按键的N种写法，就从这里开始了。大家可以新建一个网页，一边浏览代码，一半观看讲解。

首先观察源文件，我们能够看到，主函数程序在完成初始化函数后，就进入了死循环，整个中断服务函数里也仅有一行代码，拿它是如何实现按键检测功能呢/

实际上，赭黄大妈也只是用来标识按键按下。而真正的按键检测已交由硬件来完成了，在函数AllInit部分，配置好外部中断为下降沿，引脚电平置高并使能中断向量后




自然，如此基础的按键，免不了会遇到一些问题，是什么问题我先卖个关子，等到下一节再讲解
