Lesson 22 Simple Creation-Small Fan
====================================

Introduction
---------------------

In this experiment, we will learn how to control the direction and speed
of a small-sized DC motor by a driver chip L293D. Making simple
experiments, we will just make the motor rotate left and right, and
accelerate or decelerate automatically.

Components
---------------

.. image:: media_mega2560/mega35.png
    :align: center


* :ref:`SunFounder Mega Board`
* :ref:`Breadboard`
* :ref:`Jumper Wires`
* :ref:`Resistor`
* :ref:`Capacitor`
* :ref:`Button`
* :ref:`L293D`
* :ref:`DC Motor`

Schematic Diagram
------------------------

The maximum current of an Arduino I/O port is 20mA but the drive current
of a motor is at least 70mA. Therefore, we cannot directly use the I/O
port to drive the current; instead, we can use an L293D to drive the
motor.


The Enable pin 1,2EN of the L293D are connected to 5V
already, so L293D is always in the working state. Connect pin 1A and 2A
to pin 9 and 10 of the control board respectively. The two pins of the
motor are connected to pin 1Y and 2Y respectively. When pin 10 is set as
High level and pin 9 as Low, the motor will start to rotate towards one
direction. When the pin 10 is Low and pin 9 is High, it rotates in the
opposite direction.

The schematic diagram:

.. image:: media_mega2560/image239.png
   :align: center



Experimental Procedures
-------------------------------

**Step 1:** Build the circuit

.. image:: media_mega2560/image240.png

**Step 2:** Open the code file.

**Step 3:** Select the **Board** and **Port.**

**Step 4:** Upload the sketch to the board.

The blade of the DC motor will begin rotating left and right, in a speed
that varies accordingly.

.. image:: media_mega2560/image241.jpeg

Code

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/8eadc5e2-3cb8-466f-8b7b-b14f4b4c0dd1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
--------------------

**Workflow of the Small Fan**

.. code-block:: arduino

    void loop() {

      // read the state of the switch into a local variable:

      int reading = digitalRead(buttonPin);

      if (reading != lastButtonState)// If the button state is different from last time

      {

         lastDebounceTime = millis();// reset the debouncing timer

      }

      if ((millis() - lastDebounceTime) > debounceDelay) 
      /* Determine whether the button has been pressed 
      for over 50ms to prevent signal generated due to accidental touch.*/

      {

         if (reading != buttonState) 
         /*If it’s over 50ms and *reading* does not equal to *buttonState*, 
         it indicates the button state has changed.*/

         {

            buttonState = reading; // Store the state of button in buttonState

            if (buttonState == HIGH) 
            //If buttonState is high level, it means the button has been pressed.

            {

               digitalWrite(ledPin, HIGH); //turn on the LED

               stat = stat + 1;

               if(stat >= 4)// When stat>=4, set it as 0.

               {

                  stat = 0;

               }

            }

            else /*else, turn off the LED. When you press the button, the LED will
            light up and it goes out when you release the button.*/

               digitalWrite(ledPin, LOW);

         }

      }

      // The rotational speed is different when the button is pressed at different times.

      switch(stat)

      {

      case 1:

         clockwise(rank1);// When stat=1, set the rotate speed of the motor as rank1=150

         break;

      case 2:

         clockwise(rank2);// When stat=2, set the rotate speed of the motor as rank1=200

         break;

      case 3:

         clockwise(rank3);// When stat=3, set the rotate speed of the motor as rank1=250

         break;

      default:

         clockwise(0);

      }

      // save the reading. Next time through the loop,

      // it'll be the lastButtonState:

      lastButtonState = reading;

   }
   
**Code Analysis** **24-2** **clockwise() function**

.. code-block:: arduino

    void clockwise(int Speed)

    {

      analogWrite(motorIn1,0);

      analogWrite(motorIn2,Speed);

    }

This function is to set the rotational speed of the *motor*: write
*Speed* to pin 9 and 0 to pin 10. The motor rotates towards a certain
direction and the speed is the value of **Speed**.

Experiment Summary
-----------------------

In this experiment, you can also control the motor to rotate or not.
Just connect pin 1, 2EN of the L293D to an I/O port of the control
board. Set 1, 2EN as High level, and the motor will start rotating; set
it as Low level, it will stop the rotating.