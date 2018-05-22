# Track Notes
A simple AU/VST plugin to hold your session and track notes.

![alt tag](https://github.com/JosephTLyons/Track-Notes/blob/master/Images/Track%20Notes%20GUI.png?raw=true)
-GUI screenshot may not be the same size as the actual GUI

# License and Source Code:
* Track Notes is open source and under GPL_v3 licensing, you can find the code here: https://github.com/JosephTLyons/Track-Notes

# Purchase Information:
* This plugin isn't free, it costs 5 USD: https://www.paypal.me/JosephTimothyLyons/5
* There is a demo version for testing.  In demo mode, Track Notes will work normally for at least 20 minutes or more.  After 20 minutes, one of the text fields will be randomly selected and overwritten with a reminder that this is a demo version.  Once a purchase is made, I will manually send you a copy of the full version to the email associated with your Paypal account, within 24 hours.  I can also send the download link to another email address, if requested.  Note: If a full payment isn't received, I'll simply refund the amount paid.
* Do not blind purchase.  I am newer to audio plugin development and expect to have bugs in my initial release.  I'm not sure how long or what sort of research I'll have to do to fix these bugs (for instance, obtaining a DAW I don't own that isn't free), so its best to just demo it first.  If there's a bug, please report it to me at JosephTLyons@gmail.com and wait for a bug fix before purchasing.
* Do not purchase based on future features.  I have listed all the future features that I'd like to add in this README, but none of these are guaranteed.  I may not be able to implement them all due to my limited experience with programming, so please only purchase based on what is currently available.

# Features:
* Text fields for Performer's Name, Instrument Played, Microphone(s) Used, Timestamped Notes, and General Notes
* Performer's Name, Instrument Played, and Microphone(s) Used are user renameable
* A special text field for capturing timestamped notes, which is done through the "Insert Timestamp" button (this feature isn't available in all DAWs, only in ones that provide information about the playhead)
* Abilty to load up to two images into the plugin.  Image previews are available directly on the main GUI, but larger versions can be loaded into their own windows by clicking the buttons above that hold the image's filename.  Note - Images are not stored in the plugin binary data, only the pathway to the image on your system is stored.  This means that if you change the location of the image, rename the image, or move the entire session to another computer, your image links will be broken.  A good piece of advice is to copy the images you want to use into your session folders and then load them from there.
* Ability to export media to a folder (named by the user).  The export function saves all text-based information to a .txt file and copies any loaded images from their original location on the user's comp to the export folder.
* Stealth Mode: We may not always want to show the clients the notes we write about their performances, so when this button is engaged, Timestamped Notes and General Notes are hidden.  Additionally, it also deactivates the "Insert Timestamp" button.

# Currently Supported Formats:
* 64 bit for Mac 10.6+: VST, AU
* 64 bit for Windows: VST

# To Install:
* Mac AU: Copy AU to /Users/USERNAME/Library/Audio/Plug-Ins/Components
* Mac VST: Copy VST to /Users/USERNAME/Library/Audio/Plug-Ins/VST
* Windows VST: Copy VST to C:\Program Files\Steinberg\VstPlugins or the location specified by your DAW

## Changelog:
### July 30th, 2017 - v1.2.0
* PC VST builds are now available
* Stealth mode feature is added
* Corrected tabbing behaviour:  Now, when a text editor is in focus, pressing the tab key will move the focus to the next sequential text editor.
* Demo version now available

### June 26th, 2017 - v1.1.0
* Bug fix: Some images load and display larger than they really are.  Images that have dimensions that exceed those of the screen you are using will be scaled down (only the copy of the image loaded into the application is changed, not the original).  This is sort of guesswork, as its hard to know the exact dimensions of the docks/taskbars/etc, but it SHOULD work.  Also, images that don't exceed the desktop dimensions are not changed.
* Reworked the entire GUI to allow for image previews.  You can still open the image in a larger window as before, but now you have "at a glance" views of either loaded image
* Added support to allow the first three labels to be renameable by the user
* The windows that house the images can no longer be maximized, in an effort to some keep DAWs from crashing.  This doesn't affect anything, since the images didn't previously scale when the window changed sized
* Blank image windows now load in the center of the screen, the same as windows with images in them

### June 11th, 2017 - v1.0.1
* Fixed formatting issue with timestamps that included times above 60 minutes.
* Images now load in the center of the screen, instead of the upper left-hand corner, this fixes the "locked images" bug some users reported
* Changed the location, in the code, of where the method that calls the timestamping is located to hopefully increase the stability of the plugin and maybe fix some of the timestamping failures in some DAWs, but this comes with an ever-so-slight increase in CPU (Ex. 16 instances causes a 0.1 percent increase in CPU on my Macbook Pro 2.8 gHz i7 quad core).

### June 5, 2017 - v1.0.0
* Initial Release

# Note:
* I've only been able to test in GarageBand, Reaper, and Mixbus.  I've documented the known issues below in those DAWs.  Outside of those DAWs, I can't guarantee Track Notes will work properly.  If you encounter an issue, please email me.  I'll try to obtain the DAW and figure the bugs out.

## Bugs / Known Issues:
### Global Issues:
* Insert Timestamp does not work in some DAWs, output may be all zeros or garbage values (GarageBand, Logic).
* Image windows are always on top.  This is a "hack" because the main plugin window always tries to gain focus and cover up the image window (in most DAWs).  To combat that, I've forced the new window to always be on top.

### VST in Reaper:
* Spacebar focus is being stolen - User needs to engage FX menu setting "Send all keyboard input to plug - in"

### AU in Garageband:
* Some text editor key commands aren't picked up, such as command+a for selecting all text

## Future features to consider (after v1.0.0 release):
* Allow for many more images to be saved (maybe 16?) instead of just 2 - using a File Array to hold the paths
* Video support
* Resizable windows / GUI
* User picked fonts, font sizes, and background color?
* AAX (Mac and Windows)

## Other things to do before next release (developer notes):
* Installer script
* Refactor method for Exporting Media and method for image resizing
* Make public data members private
* Make setter and getter methods for processor class items
* Test other DAWs
* Embed a cool font

# Contact Information:
* Email: JosephTLyons@gmail.com
* Like the Facebook page: https://www.facebook.com/TheLyonsDenSoftware/
