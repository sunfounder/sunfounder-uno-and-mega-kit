IR Receiver Module
===========================
.. image:: img/image185.png

.. image:: img/image186.jpeg


An infrared-receiver (as shown below) is a component which receives infrared signals and can independently receive infrared rays and output signals compatible with TTL level. It is similar with a normal plastic-packaged transistor in size and is suitable for all kinds of infrared remote control and infrared transmission.

**Description**

.. image:: img/image185.png
    :align: center


IR, or infrared, communication is a popular, low-cost, and easy to use wireless communication technology. IR light has a slightly longer wavelength than visible light, so  This  is undetectable by the human eye - perfect for wireless communication. A common modulation scheme for IR communication is 38kHz modulation. 38KHz Digital IR Receiver Sensor Module For Arduino IR is widely utilized in remote controls. With such IR receivers, the Arduino project is able to receive a command from any IR remote controller if you have the right decoder.

**Features**
Based on the 38KHz IR Receiver Sensor
Can be used for remote control
Power Supply: 5V
Interface: Digital
Modulate Frequency: 38Khz
Pin Definitions: (1) Output (2) Vcc (3) GND
Size: 23.5mm x 21.5mm

https://www.circuitbasics.com/arduino-ir-remote-receiver-tutorial/


**什么是红外线？**

红外辐射是一种类似于我们在我们周围看到的光的形式。红外光和可见光之间的唯一区别是频率和波长。红外辐射在可见光范围之外，所以人类看不到它.

由于 IR 是一种光，因此 IR 通信需要从接收器到发射器的直接视线。它不能通过墙壁或其他材料（如 WiFi 或蓝牙）传输

**红外遥控器和接收器的工作原理**

典型的红外通信系统需要一个红外发射器和一个红外接收器。发射器看起来就像一个标准的LED，除了它产生红外光谱而不是可见光谱的光。如果您看一下电视遥控器的正面，您会看到红外发射器 LED：

.. image:: img/

An infrared-receiver (as shown below) is a component which receives infrared signals and can independently receive infrared rays and output signals compatible with TTL level. It is similar with a normal plastic-packaged transistor in size and is suitable for all kinds of infrared remote control and infrared transmission.

.. image:: img/

**红外信号调制**

红外线由太阳、灯泡和任何其他产生热量的物体发出。这意味着我们周围有很多红外光噪声。为了防止这种噪声干扰 IR 信号，使用了信号调制技术。

在红外信号调制中，红外遥控器上的编码器将二进制信号转换为调制电信号。该电信号被发送到发射 LED。发射 LED 将调制的电信号转换为调制的 IR 光信号。然后红外接收器解调红外光信号并将其转换回二进制，然后将信息传递给微控制器：

.. image:: img/

调制的 IR 信号是一系列以称为载波频率的高频打开和关闭的 IR 光脉冲。大多数发射机使用的载波频率为 38 kHz，因为它在自然界中很少见，因此可以与环境噪声区分开来。这样 IR 接收器就会知道 38 kHz 信号是从发射器发送的，而不是从周围环境中接收到的。

接收器二极管检测所有频率的 IR 光，但它有一个带通滤波器，只允许 38 kHz 的 IR 通过。然后它用前置放大器放大调制信号并将其转换为二进制信号，然后将其发送到微控制器。

**红外传输协议**

调制的 IR 信号转换为二进制的模式由传输协议定义。有许多红外传输协议。Sony、Matsushita、NEC 和 RC5 是一些更常见的协议。

NEC 协议也是 Arduino 项目中最常见的类型，所以我将以它为例向您展示接收器如何将调制的 IR 信号转换为二进制信号。


逻辑“1”以 562.5 µs 长的 38 kHz IR 高脉冲开始，然后是 1,687.5 µs 长的低脉冲。逻辑“0”与 562.5 µs 长的高脉冲后跟 562.5 µs 长的低脉冲一起传输：
.. image:: img/

这就是 NEC 协议将二进制数据编码和解码为调制信号的方式。其他协议仅在单个高和低脉冲的持续时间上有所不同。

**红外代码**

每次按下遥控器上的按钮时，都会生成一个唯一的十六进制代码。这是经过调制并通过 IR 发送到接收器的信息。为了破译按下了哪个键，接收微控制器需要知道遥控器上的每个键对应的代码。

不同的遥控器会为按键发送不同的代码，因此您需要确定为特定遥控器上的每个键生成的代码。如果您能找到数据表，则应列出 IR 键代码。如果没有，有一个简单的 Arduino 草图，当您按下一个键时，它可以读取大多数流行的遥控器并将十六进制代码打印到串行监视器。我将在一分钟内向您展示如何进行设置，但首先我们需要将接收器连接到 Arduino……