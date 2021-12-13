电阻
============

.. image:: img/resistor.png
    :width: 300

电阻器是一种可以限制支路电流的电子元件。固定电阻器是一种阻值不能改变的电阻器，而电位器或可变电阻器的电阻器是可以调节的。

电阻器的两种常用电路符号。通常，电阻标在其上。因此，如果你在电路中看到这些符号，则它代表电阻器。

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** 是电阻的单位，较大的单位有KΩ、MΩ等，它们的关系可以表示为：1 MΩ=1000 KΩ，1 KΩ = 1000 Ω。通常，电阻值标在其上。

使用电阻时，首先要知道它的阻值。这里有两种方法：你可以观察电阻上的色环，或者用万用表测量电阻。建议你使用第一种方法，因为它更方便、更快捷。


.. image:: img/resistance_card.jpg

如卡片所示，每种颜色代表一个数字。

.. list-table::

   * - Black 黑
     - Brown 棕
     - Red 红
     - Orange 橙
     - Yellow 黄
     - Green 绿
     - Blue 蓝
     - Violet 紫
     - Grey 灰
     - White 白
     - Gold 金
     - Silver 银
   * - 0
     - 1
     - 2
     - 3
     - 4
     - 5
     - 6
     - 7
     - 8
     - 9
     - 0.1
     - 0.01

通常说的4环，5环和6环电阻指的是电阻上有多少种的颜色色环

通常，当你获得一个电阻器时，你可能会发现很难决定从哪一端开始读取颜色。提示是第 4 和第 5 个色环之间的差距会比较大。

因此，可以观察到电阻一端的两个色环之间的间隙；如果它比任何其他带隙都大，那么你可以从相反的一侧读取。

让我们看看如何读取 5环电阻器的阻值，如下所示。

.. image:: img/220ohm.jpg
    :width: 500

所以对于这个电阻，应该从左到右读取电阻。该值应采用以下格式：1st Band 2nd Band 3rd Band x 10^Multiplier (Ω) 并且允许误差为 ±Tolerance%。所以这个电阻的阻值为2(red) 2(red) 0(black) x 10^0(black) Ω = 220 Ω，允许误差为±1%（棕色）。

**常用电阻色环**

.. list-table::
    :header-rows: 1

    * - 电阻 
      - 色环  
    * - 10Ω   
      - 棕 黑 黑 金 棕
    * - 100Ω   
      - 棕 黑 黑 黑 棕
    * - 220Ω 
      - 红 红 黑 黑 棕
    * - 330Ω 
      - 橙 橙 黑 黑 棕
    * - 1kΩ 
      - 棕 黑 黑 棕 棕 
    * - 2kΩ 
      - 红 黑 黑 棕 棕 
    * - 5.1kΩ 
      - 绿 棕 黑 棕 棕
    * - 10kΩ 
      - 棕 黑 黑 红 棕
    * - 100kΩ 
      - 棕 黑 黑 橙 棕
    * - 1MΩ 
      - 棕 黑 黑 绿 棕

你可以从 Wiki： `Resistor - Wikipedia <https://en.wikipedia.org/wiki/Resistor>`_ 了解有关电阻器的更多信息。


**示例**

* :ref:`blinking_mega` (Mega板项目)
* :ref:`button_mega` (Mega板项目)
* :ref:`blinking_uno` （R3板项目）
* :ref:`button_uno` （R3板项目）
* :ref:`15. 游戏 - 吃苹果` （Scratch项目）
* :ref:`2. 台灯` （Scratch项目）