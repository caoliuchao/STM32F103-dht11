**本工程使用的芯片为STM32F103ZET6，传感器使用的是温湿度传感器DHT11。**

**如果你是用的微控制器和本工程一样，只需要在DHT11.h文件中修改与STM32的接口。**

**你要注意的是，获取温湿度的函数不是线程安全的。所以你可以另外建立一个实时操作系统任务。**

**这个任务读取温湿度数据，并将数据放在一个带有标志位的结构体内就可以保证线程安全的了。**

**希望本工程能给你带来帮助。**





