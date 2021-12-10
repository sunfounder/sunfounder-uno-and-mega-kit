.. _humi_mega:


Lesson 15 Humiture Sensor
============================

Introduction
---------------------

The digital temperature and humidity sensor DHT11 is a composite sensor
that contains a calibrated digital signal output of temperature and
humidity. The technology of a dedicated digital modules collection and
the temperature and humidity sensing technology are applied to ensure
that the product has high reliability and excellent long-term stability.

The sensor includes a resistive sense of wet component and an NTC
temperature measurement device, and is connected with a high-performance
8-bit microcontroller.

Components
------------------

.. image:: media_mega2560/mega28.png
    :align: center


* :ref:`SunFounder Mega Board`
* :ref:`Breadboard`
* :ref:`Jumper Wires`
* :ref:`LCD1602`
* :ref:`Potentiometer`
* :ref:`Humiture Sensor Module`


Schematic Diagram
--------------------------

The schematic diagram:

.. image:: media_mega2560/image193.png

Experimental Procedures
-----------------------------

**Step 1:** Build the circuit

.. image:: media_mega2560/image195.png

**Step 2:** Open the code file.

**Step 3:** Select the **Board** and **Port.**

**Step 4:** Upload the sketch to the board.

Now, you can see the value of the current humidity and temperature
displayed on the LCD.

.. image:: media_mega2560/image196.jpeg
   

Code
-------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1babed03-2393-40a5-af20-41cc2a33bf20/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
------------------

**Initialize the humiture and LCD1602**

.. code-block:: arduino

    #include <dht.h> // Include the head file dht.h

    #include <LiquidCrystal.h> 

    LiquidCrystal lcd(4, 6, 10, 11, 12, 13); // initialize the LCD1602

    dht DHT;

    #define DHT11_PIN 3 // the humiture sensor attact to pin3

**Read the value of humiture**

.. code-block:: arduino

    int chk = DHT.read11(DHT11_PIN);

    switch (chk)

    {

    case DHTLIB_OK:

        Serial.println("OK,\t");

        break;

    case DHTLIB_ERROR_CHECKSUM:

        Serial.println("Checksum error,\t");

        break;

    case DHTLIB_ERROR_TIMEOUT:

        Serial.println("Time out error,\t");

        break;

    default:

        Serial.println("Unknown error,\t");

        break;

    }

Use the ``read11()`` function to read the value of the temperature and
humidity sensor. If OK is displayed on the Serial Monitor, the humiture
sensor is working properly.

``read11()``: Return values:

.. code-block:: arduino

    // DHTLIB_OK: Indicate the humiture sensor is work well.

    // DHTLIB_ERROR_CHECKSUM

    // DHTLIB_ERROR_TIMEOUT

**Display on the LCD1602**

.. code-block:: arduino

    lcd.setCursor(0, 0);

    lcd.print("Tem:");

    lcd.print(DHT.temperature,1); // print the temperature on lcd，keep one decimal point

    lcd.print(" C");

    lcd.setCursor(0, 1);

    lcd.print("Hum:");

    lcd.print(DHT.humidity,1); // print the humidity on lcd

    lcd.print(" %");

    delay(200); // wait a while
