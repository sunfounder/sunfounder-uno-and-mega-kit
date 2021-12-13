温湿度传感器模块
=============================

.. image:: img/dht11_pic.png
    :width: 400
    :align: center

数字温湿度传感器 DHT11 是一种复合传感器，包含经过校准的温湿度数字信号输出。采用专用数字模块采集技术和温湿度传感技术，确保产品具有高可靠性和优异的长期稳定性。

只有三个引脚可供使用：VCC、GND 和 DATA。通信过程开始于DATA线向DHT11发送启动信号，DHT11接收信号并返回应答信号。然后主机收到应答信号，开始接收40位温湿度数据（8位湿度整数+8位湿度小数+8位温度整数+8位温度小数+8位校验和）。

.. image:: img/Dht11.png


* `DHT11 数据表 <https://components101.com/sites/default/files/component_datasheet/DHT11-Temperature-Sensor.pdf>`_

**示例**

* :ref:`humi_mega` (Mega板项目)
* :ref:`humi_uno` （R3板项目）
* :ref:`11. 读取温湿度` （Scratch项目）
