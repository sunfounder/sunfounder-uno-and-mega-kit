RGB LED
=================

.. image:: img/rgb_led.png
    :width: 100
    
RGB LED又名彩色发光二极管，它发出各种颜色的光。RGB LED 将红、绿、蓝三种 LED 封装在透明或半透明的塑料外壳中。它可以通过改变三个引脚的输入电压并叠加来显示各种颜色，据统计，可以产生16,777,216种不同的颜色。

.. image:: img/rgb_light.png
    :width: 600

RGB LED 可分为共阳极和共阴极 LED。在本套件中，使用后者。在共阴极，或CC，装置连接的三个LED的阴极。将其与GND连接并插入三个引脚后，LED将闪烁相应的颜色。

其电路符号如图所示：

.. image:: img/rgb_symbol.png
    :width: 300

一个 RGB LED 有 4 个引脚：最长的一个是 GND；其他是红色、绿色和蓝色。触摸它的塑料外壳，你会发现一个切口。最靠近切口的引脚是第一个引脚，标记为红色，然后依次是 GND、绿色和蓝色。

.. image:: img/rgb_pin.jpg
    :width: 200

**示例**

* :ref:`rgb_mega` (Mega板项目)
* :ref:`rgb_uno` （R3板项目）
* :ref:`4. 彩灯` (Scratch项目)