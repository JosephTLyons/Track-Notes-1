# Track Notes
A simple audio plugin to hold your session and track notes.

![alt tag](https://github.com/JosephTLyons/Track-Notes/blob/master/Images/Track%20Notes%20GUI.png?raw=true)
-GUI screenshot is larger than the actual GUI

# License and Source Code:
* Track Notes is open source and under GPL_v3 licensing, you can find the code here: https://github.com/JosephTLyons/Track-Notes

# Purchase Information:
* This plugin isn't free, it costs 1 USD: https://www.paypal.me/JosephTimothyLyons/1
* There is no piracy protection, so I will never know if you purchased or not, this is entirely based on an honors system.
* Download the plugin and demo it as long as you like, but if you like it, please purchase it, and if you dislike it, please delete it from your system.
* Do not blind purchase.  I am brand new to developing and expect to have bugs in my initial release.  I'm not sure how long or what sort of research I'll have to do to fix these bugs (for instance, obtaining a DAW I don't own that isn't free), so its best to just demo it first.  If there's a bug, please report it to me at JosephTLyons@gmail.com and wait for a bug fix before purchasing.
* Do not purchase based on future features.  I have listed all the future features that I'd like to add in this README, but none of these are guaranteed.  I may not be able to implement them all due to my limited experience with programming, so please only purchase based on what is currently available.

# Features:
* Text fields for Performer's Name, Instrument Played, Microphone(s) Used, Timestamped Notes, and General Notes
* Performer's Name, Instrument Played, and Microphone(s) Used are user renameable
* A special text field for capturing timestamped notes, which is done through the "Insert Timestamp" button (this feature isn't available in all DAWs, only in ones that provide information about the playhead)
* Abilty to load up to two images into the plugin.  Note - Images are not stored in the plugin binary data, only the pathway to the image on your system is stored.  This means that if you change the location of the image, rename the image, or move the entire session to another computer, your image links will be broken.  A good piece of advice is to copy the images you want to use into your session folders and then load them from there.
* Ability to export media to a folder (named by the user).  The export function saves all text-based information to a .txt file and copies any loaded images from their original location on the user's comp to the export folder.

# Currently Supported Formats:
* 64 bit for Mac 10.6+: VST, AU

# Note:
* I've only been able to test in GarageBand, Reaper, and Mixbus.  I've documented the known issues below in those DAWs.  Outside of those DAWs, I can't guarantee Track Notes will work properly.  If you encounter an issue, please message email me.  I'll try to obtain the DAW and figure the bugs out.

## Changelog:
### June XX, 2017 - v1.1.0
* Added support to allow the first three labels to be renameable

### June 11th, 2017 - v1.0.1
* Fixed formatting issue with timestamps that included times above 60 minutes.
* Images now load in the center of the screen, instead of the upper left-hand corner.
* Changed the location, in the code, of where the method that calls the timestamping is located to hopefully increase the stability of the plugin and maybe fix some of the timestamping failures in some DAWs, but this comes with an ever-so-slight increase in CPU (Ex. 16 instances causes a 0.1 percent increase in CPU on my Macbook Pro 2.8 gHz i7 quad core).

### June 5, 2017 - v1.0.0
* Initial Release

## Bugs / Known Issues:
### Global Issues:
* Insert Timestamp does not work in some DAWs, output may be all zeros or garbage values (GarageBand, Logic).
* Images are always on top.  This is a "hack" because the main plugin window always tries to gain focus and cover up the image window (in most DAWs).  To combat that, I've forced the new window to always be on top.
* Some images load and display larger than they really are.
* Images are locked in the upper left-hand corner for some users in Studio One 3.5

### VST in Reaper:
* Spacebar focus is being stolen - User needs to engage FX menu setting "Send all keyboard input to plug - in"

### AU in Garageband:
* Some text editor key commands aren't picked up, such as command+a for selecting all text

## Future features to consider (after v1.0.0 release):
* Allow for many more images to be saved (maybe 16?) instead of just 2 - using a File Array to hold the paths
* Show image preview so user doesn't need to open external full sized image every time, then maybe use a clear button over the image that would be used to define the clickable area to open the full sized image.
* Video support?
* Option to resave the images elsewhere?
* Resizable windows / GUI
* User picked fonts, font sizes, and background color?
* AAX
* PC Versions

## Other things to do before next release (developer notes):
* Installer script
* Refactor method for Exporting Media
* Make public data members private
* Make setter and getter methods for processor class items
* Set up plugin category information
* Test other DAWs
* Embed a cool font

# Contact Information:
* Email: JosephTLyons@gmail.com
* Like the Facebook page: https://www.facebook.com/TheLyonsDenSoftware/
