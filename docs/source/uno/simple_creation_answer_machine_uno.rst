.. _answer_uno:

Lesson 21 Simple Creation-Answer Machine
=============================================

Introduction
--------------------

In quiz shows, especially entertainment activities (e.g. competitive
answering activities), organizers often apply a buzzer system in order
to accurately, fairly and visually determine the seat number of a
responder.

Now the system can illustrate the accuracy and equity of the judgment by
data, which improves the entertainment. At the same time, it is more
fair and just. In this lesson, we will use some buttons, buzzers, and
LEDs to make a quiz buzzer system.

Components
---------------

.. image:: img/uno25.png
    :align: center

* :ref:`SunFounder R3 Board`
* :ref:`Breadboard`
* :ref:`Jumper Wires`
* :ref:`Resistor`
* :ref:`LED`
* :ref:`Button`
* :ref:`Buzzer`

Schematic Diagram
----------------------

Button 1, 2 and 3 are answer buttons, and button 4 is the reset button.
If button 1 is pressed first, the buzzer will beep, the corresponding
LED will light up and all the other LEDs will go out. If you want to
start another round, press button 4 to reset.

.. image:: img/image183.png



Experimental Procedures
------------------------------

**Step 1:** Build the circuit.

.. image:: img/image184.png


**Step 2:** Open the code file.

**Step 3:** Select the Board and Port.

**Step 4:** Upload the sketch to the board.

Now, first press button 4 to start. If you press button 1 first, you
will see the corresponding LED light up and the buzzer will beep. Then
press button 4 again to reset before you press other buttons.

.. image:: img/image185.jpeg
    :align: center

Code
--------

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ee24e4e8-02db-4a0a-83a2-ea9c9926a07e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
--------------------

The code for this experiment may be a bit long. But the syntax is very simple.

This code uses 6 nested if statements.

* The first if statement is used to determine if button 4 is pressed.
* The second if statement is used to determine again if button 4 is pressed, which is used to prevent false touches. If it is confirmed that it is pressed, the flag will be 1 and the LED will be lit.
* The third if statement is used to determine the value of flag, if it is 1 (button 4 is pressed), the value of button 1, 2 and 3 are read at this time.
* The fourth - six if statements are used to determine if buttons 1, 2, and 3 are pressed, and if they are pressed, then the LED is lit and the buzzer is sounded.

**Alarm() function**


.. code-block:: arduino

    void Alarm()
    {
    for(int i=0;i<100;i++){
        digitalWrite(buzzerPin,HIGH); //the buzzer sound
        delay(2);
        digitalWrite(buzzerPin,LOW);  //without sound
        delay(2);                     //when delay time changed,the frequency changed
    }
    }

This function is used to set the length and frequency of the sound emitted by the buzzer.
