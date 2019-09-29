# Changelog:
## XXX - v?
* Updated to the newest JUCE framework
* Massive code refresh
* Erasing the custom text in a label will automatically default back to its original value without having to close and
  open the plugin

## July 30th, 2017 - v1.2.0
* PC VST builds are now available
* Stealth mode feature is added
* Corrected tabbing behaviour:  Now, when a text editor is in focus, pressing the tab key will move the focus to the next sequential text editor.
* Demo version now available

## June 26th, 2017 - v1.1.0
* Bug fix: Some images load and display larger than they really are.  Images that have dimensions that exceed those of the screen you are using will be scaled down (only the copy of the image loaded into the application is changed, not the original).  This is sort of guesswork, as its hard to know the exact dimensions of the docks/taskbars/etc, but it SHOULD work.  Also, images that don't exceed the desktop dimensions are not changed.
* Reworked the entire GUI to allow for image previews.  You can still open the image in a larger window as before, but now you have "at a glance" views of either loaded image
* Added support to allow the first three labels to be renameable by the user
* The windows that house the images can no longer be maximized, in an effort to some keep DAWs from crashing.  This doesn't affect anything, since the images didn't previously scale when the window changed sized
* Blank image windows now load in the center of the screen, the same as windows with images in them

## June 11th, 2017 - v1.0.1
* Fixed formatting issue with timestamps that included times above 60 minutes.
* Images now load in the center of the screen, instead of the upper left-hand corner, this fixes the "locked images" bug some users reported
* Changed the location, in the code, of where the method that calls the timestamping is located to hopefully increase the stability of the plugin and maybe fix some of the timestamping failures in some DAWs, but this comes with an ever-so-slight increase in CPU (Ex. 16 instances causes a 0.1 percent increase in CPU on my Macbook Pro 2.8 gHz i7 quad core).

## June 5, 2017 - v1.0.0
* Initial Release
