I've modified this to try to get it to work with full color pictures.

This is a hacked together program of the program discussed below so
your mileage may vary.  I'm only posting it since I've not seen
anything like it available free.  Perhaps someone can improve on it.

It seems to work ok with Labview6 and Windows 2000 and a hauppage
wintv theatre tv card.  (cheap image capture card.)  I have noticed
labview erroring something on exit earlier, but its not doing it
now.  I don't know why.  I figured out just enough to make this do
a full color image...  I suspect if a person had time and knew what
he was doing a much much better version could be made.

"vfw example mine.vi" is the vi that should work to test it.  
Set your capture format options to something like 24bit 320x240 
when the popup window appears.

Parts of the other vi's may not work since changes have been made
from the original I found at.

http://labview.pica.army.mil/archives/

-Robert


_____________________________________________________________________
- Video for Windows frame capture driver for LabView 4.0.
- Snappy frame capture driver for LabView 4.0 and Snappy 2.0.

   by Eric Eilebrecht (eilebrec@colorado.edu)


----------------------------------------------------------------------

NOTE:  When unzipping these files, make sure you set your "unzip"
program to preserve the directory structure.  Otherwise you'll
have a bunch of source files in your main directory.  Also, make
sure you use an "unzip" program that preserves long filenames.
I recommend the "Info-zip" suite of ZIP file programs - they will
do both of these things by default.

----------------------------------------------------------------------


This is a basic hacked-together driver for LabView that allows single
frames of video to be captured from any Video For Windows (VFW) video
capture device, or Snappy framegrabber.  I personally have used the VFW
vi's with both the VideoLogic Captivator card and the Connectix 
QuickCam.  The Snappy vi's require Snapy 2.0 software.

Examples of how to use these drivers are in "vfw example.vi" and 
"snappy example.vi"  Thie displays a preview window, captures a single 
frame, and displays it on screen.  For best results, make sure your 
video mode is set to 16-bit color or better.  To use the example, start
by executing the VI.  This will display a preview window, with some 
menu options.  Play around with the options, then go back to the VI and
press the "Snap!" button.  You should then see the captured frame on
the VI's panel.

There are four values across the bottom of the screen.  Try adjusting 
them to see what their effects on the captured frame are.  These are 
the parameters to the frame capture routine.  They work as follows:

rWeight, gWeight, and bWeight are all all weighting values for the R, 
G, and B components of the image.  They only have meaning relative to 
each other.  Values of (1, 1, 1) give you an evenly weighted greyscale
image.  (1, 0, 0) gives you just the red component.  (1, .5, .5) 
weights red twice as heavily as green or blue, and so on.

allWeight is the maximum possible value that can be present in the 
final image array.  Pixel values will be scaled between 0 and 
allWeight.

Here's the basic idea of how to use this library:  

1) Create a capture window using "Create Capture Window.vi" or 
   "Create Snappy Window.vi" This will return a "window handle," which
   will be used by the other VI's.  These take one parameter, which
   is a boolean.  Set this to "true" if you want to see a preview 
   window, or "false" if you don't.

2) When the camera is pointed at the thing you want to capture, execute
   one of the "Capture*.vi" vi's.  The differences between these are in
   whether or not they save the image to disk.  For the Snappy,
   you must use "Snap From Snappy.vi."

3) If you used "Capture to Temporary File.vi" or "Capture Frame.vi" in
   the previous step, then call "Get Frame Data.vi" to get a 2-D array
   of all of the pixel values that were just captured.  This is where 
   you specify the weightings discussed above.  If you used a different
   vi above, then you already have the image data.

Step 3 may be repeated many times for the same frame.  This is useful 
if you want to get the same image with different color weightings.

Step 2 may also be repeated if you want to capture more than one frame 
durring the execution of your VI.

4) When you are all done, destroy the capture window with 
   "Destroy Capture Window.vi" or "Destroy Snappy Window.vi."


BUGS:

If you stop your VI before destroying the capture window, you may have
trouble creating another one.  The only way I know of to make it work
again is to reboot. :(

With some old 16-bit VFW drivers (like the VideoLogic Captivator), you
will get a blank capture window every other time the window is created.
You may be able to fix this by re-selecting the capture driver from the
"Device" menu of the capture window.

If you have any problem that you can't figure out, send me email 
(eilebrec@colorado.edu)
