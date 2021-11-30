FAQ
============

1. the board does not work?
------------------------------------------
If you have clicked the green flag or sprite in PictoBlox' stage mode, you cannot send data to or receive data from the Arduino board.

You need to do the following.

1) Check if the correct board is selected and already connected.
2) Check if the correct pin is selected.
3) If you are using this Arduino board in PictoBlox for the first time, or if this Arduino board has uploaded code with Arduino IDE before. Then you need to click **Upload Firmware** before you use it.


2. COM14": Access is denied?
------------------------------

When uploading code in Arduino IDE, it shows :avrdude: ser_open(): can't open device "\. \COM14": Access is denied.

1) Check if you have selected the correct COM port.
2) If you have PictoBlox open and the board is connected at the same time, you need to disconnect it in PictoBlox and re-upload it again on the Arduino IDE.

3. How to work in PictoBlox' Stage Mode?
---------------------------------------------

For a detailed tutorial, please refer to :ref:`Stage Mode`.

4. How to work in PictoBlox' Upload mode?
---------------------------------------------

For a detailed tutorial, please refer to :ref:`Upload Mode`.