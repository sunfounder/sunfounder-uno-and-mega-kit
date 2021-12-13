.. _photoresistor_uno:

第 9 课 光敏电阻
==========================

介绍
------------------

在本课中，你将学习如何使用光敏电阻测量光强度。光敏电阻的电阻值随着入射光强度的变化而变化。如果光照强度变高，阻值减少；如果光强度变暗，阻值就会增加。

所需器件
---------------

.. image:: media_uno/uno13.png
    :align: center

* :ref:`SunFounder R3板`
* :ref:`面包板`
* :ref:`跳线`
* :ref:`LED发光二极管`
* :ref:`电阻`
* :ref:`光敏电阻`

原理图
---------------------

在这个实验中，我们将用8个LED灯来显示光的强度。光强度越高，越多的LED灯会亮起来。当光强度足够高时，所有的LED灯都会亮起来。当没有光，所有的LED灯都会熄灭。

原理图如下所示：

.. image:: media_uno/image115.png
   :align: center

实验步骤
---------------------------

**第 1 步**：搭建电路。.

.. image:: media_uno/image116.png

**第 2 步**：打开代码文件 ``Lesson_9_Photoresistor.ino``。

**第 3 步**：选择 **开发板** 和 **端口**。

**第 4 步**：点击 **上传** 按钮来上传代码。

现在，用一些光照在光敏电阻上，你会看到几个LED灯亮起来。照更多的光，你会看到更多的LED灯亮起来。当你把它放在一个黑暗的环境中，所有的LED都会熄灭。

.. image:: media_uno/image117.jpeg


代码
--------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7484bb92-34dd-468e-b5f6-6400453fd9f6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

代码分析
------------------------

**设置变量**

.. code-block:: arduino

    const int NbrLEDs = 8; // 8 leds
    const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // 8 leds attach to pin 5-12 respectively
    const int photocellPin = A0; // photoresistor attach to A0
    int sensorValue = 0; // value read from the sensor
    int ledLevel = 0; // sensor value converted into LED 'bars'

8个LED被连接到5引脚-12引脚，在这段代码中，使用一个数组来存储这些引脚， ``ledPins[0]`` 等于5， ``ledPins[1]`` 等于6，以此类推。


**设置8个引脚为输出**

.. code-block:: arduino

    for (int led = 0; led < NbrLEDs; led++)
    {
        pinMode(ledPins[led], OUTPUT); // make all the LED pins outputs
    }

使用 ``for()`` 语句将8个引脚依次设置为输出。
依次为OUTPUT。

**读取光敏电阻的模拟值**。

.. code-block:: arduino

    sensorValue = analogRead(photocellPin); // read the value of A0

读取 ``photocellPin`` (A0引脚)的值并存储到变量 ``sensorValue`` 中。

* ``analogRead()``：从指定的模拟引脚读取数值。Arduino板包含一个多通道、10位的模拟数字转换器。这意味着它将映射出0到工作电压（5V或3.3V）之间的输入电压。电压（5V或3.3V）之间的输入电压映射为0至1023之间的整数值。

.. code-block:: arduino

    Serial.print("SensorValue: ");
    Serial.println(sensorValue); // Print the analog value of the photoresistor

使用 ``Serial.print()`` 函数来打印光敏电阻的模拟值，你将在串口监视器中看到它们。

* ``Serial.print()``：将数据作为人类可读的ASCII文本打印到串口。这个命令可以有多种形式。数字被打印为每个数字的ASCII字符。浮点数同样被打印为ASCII数字，默认为两位小数。字节以单个字符的形式发送。字符和字符串按原样发送。
* ``Serial.println()``：与 ``Serial.print()`` 相同，但它后面有一个回车字符（ASCII 13，或'\r'）和一个换行字符（ASCII 10，或'\n'）。


**将模拟值映射到8个LED上**

.. code-block:: arduino

    ledLevel = map(sensorValue, 0, 1023, 0, NbrLEDs); // map to the number of LEDs
    Serial.print("ledLevel: ");
    Serial.println(ledLevel);

这个 ``map()`` 函数是用来将 0-1023 映射到0-NbrLEDs(8)。

(1023-0)/(8-0)=127.875

+-------+-------+-------+-------+-------+-------+-------+-------+
| 0-12  | 128-2 | 2     | 384-  | 5     | 640-7 | 7     | 896   |
| 7.875 | 55.75 | 56-38 | 511.5 | 12-63 | 67.25 | 68-89 | -1023 |
|       |       | 3.625 |       | 9.375 |       | 5.125 |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
| 0     | 1     | 2     | 3     | 4     | 5     | 6     | 7     |
+-------+-------+-------+-------+-------+-------+-------+-------+

如果 ``sensorValue`` 等于560，则 ``ledLevel`` 为4.

* ``map(value, fromLow, fromHigh, toLow, toHigh)`` 函数是将数字从一个范围重新映射到另一个范围。也就是说，值fromLow将被映射到了tolow，值fromHigh到toHigh，值之间以值之间，等等。

**点亮LED灯**

.. code-block:: arduino

    for (int led = 0; led < NbrLEDs; led++)
    {
        if (led <= ledLevel ) //When led is smaller than ledLevel, run the following code.
        {
            digitalWrite(ledPins[led], HIGH); // turn on pins less than the level
        }
        else
        {
            digitalWrite(ledPins[led], LOW); // turn off pins higher than
        }
    }

点亮相应的LED。例如，当 ``ledLevel`` 为4时，点亮 ``ledPins[0]`` 到 ``ledPins[4]``，熄灭 ``ledPins[5]`` 到 ``ledPins[7]``。