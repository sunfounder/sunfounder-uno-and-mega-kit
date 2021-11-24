LCD1602
==============

.. image:: img/image159.png
    :width: 400
    :align: center

LCD1602, or 1602 character-type liquid crystal
display, is a kind of dot matrix module to show letters, numbers, and
characters and so on. It's composed of 5x7 or 5x11 dot matrix positions;
each position can display one character. There's a dot pitch between two
characters and a space between lines, thus separating characters and
lines. The number 1602 means on the display, 2 rows can be showed and 16
characters in each. Now let's check more details!

Generally, LCD1602 has parallel ports, that is, it would control several
pins at the same time. LCD1602 can be categorized into eight-port and
four-port connections. If the eight-port connection is used, then all
the digital ports of the control board are almost completely occupied.
If you want to connect more sensors, there will be no ports available.
Therefore, the four-port connection is used here for better application.

**Pinouts**

* **VSS:** connected to ground
* **VDD:** connected to a +5V power supply
* **VO:** to adjust the contrast
* **RS:** A register select pin that controls where in the LCD’s memory you are writing data to. You can select either the data register, which holds what goes on the screen, or an instruction register, which is where the LCD’s controller looks for instructions on what to do next.
* **R/W:** A Read/Write pin to select between reading and writing mode
* **E:** An enabling pin that reads the information when High level (1) is received. The instructions are run when the signal changes from High level to Low level.
* **D0-D7:** to read and write data
* **A and K:** Pins that control the LCD backlight. Connect K to GND and A to 3.3v. Open the backlight and you will see clear characters in a comparatively dark environment.


**Example**

* :ref:`Lesson 11 LCD1602` (Mega Board Project)
* :ref:`Lesson 15 Humiture Sensor` (Mega Board Project)
* :ref:`lcd1602_uno` (R3 Board Project)
* :ref:`humi_uno` (R3 Board Project)
* :ref:`5. LCD1602` (Scratch Project)


