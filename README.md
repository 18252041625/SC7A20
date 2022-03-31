# SC7A20 ±2G/±4G/±8G/±16G三轴微机械数字加速度计
一直没找到简单好用的SC7A20驱动库，索性自己写了一个，采用IIC接口读取数据，需要注意网上查到的芯片地址都不对，应该是0x18,可以看我下面用逻辑分板仪抓取到的数据据包，只有0X18才反回ACK.  
![数据包](https://github.com/18252041625/SC7A20/blob/master/%E9%80%BB%E8%BE%91%E5%88%86%E6%9E%90%E4%BB%AA.png)  
另一点是芯片输出是2进制补码形式，负数需要转换成原码.  
## 软件 IDE   
PlatformIO   
## 硬件连接   
![接线图](https://github.com/18252041625/SC7A20/blob/master/%E6%8E%A5%E7%BA%BF%E5%9B%BE.png)
EPS23主控  
IIC SDA-----21  
IIC SCK-----22  
##测试数据
量程+-2g，12bit精度，无外力仅重力时1g=1023个测量值，1=1mg   
![测试数据](https://github.com/18252041625/SC7A20/blob/master/%E6%B5%8B%E8%AF%95.png)
