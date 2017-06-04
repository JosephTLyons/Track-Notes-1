# Track-Notes
A simple audio plugin to hold your session and track notes.

![alt tag](https://github.com/JosephTLyons/Track-Notes/blob/master/Images/Track%20Notes%20GUI.png?raw=true)
-GUI screenshot is larger than the actual GUI

# License and Source Code:
* Track Notes is under GPL-v3 licensing, you can find the code here: https://github.com/JosephTLyons/Track-Notes

# Purchase Information:
* This plugin isn't free, it costs 1 USD: https://www.paypal.me/JosephTimothyLyons/1
* There is no piracy protection, so I will never know if you purchased or not, this is entirely based on an honors system.
* Download the plugin and demo it as long as you like, but if you like it, please purchase it, and if you dislike it, please delete it from your system.
* Do not blind purchase.  I am brand new to developing and expect to have bugs in my initial release.  I'm not sure how long or what sort of research I'll have to do to fix these bugs (for instance, obtaining a DAW I don't own that isn't free), so its best to just demo it first.  If there's a bug, please report it to me at JosephTLyons@gmail.com and wait for a bug fix before purchasing.
* Do not purchase based on future features.  I have listed all the future features that I'd like to add in this README, but none of these are guaranteed.  I may not be able to implement them all due to my limited experience with programming, so please only purchase based on what is currently available.

# Features:
* Text fields for Performer's Name, Instrument Played, Microphone(s) Used, and General Notes
* A special text field for capturing timestamped notes, which is done through the "Insert Timestamp" button (this feature isn't available in all DAWs, only in ones that provide information about the playhead)
* Abilty to load up to two images into the plugin.  Note - Images are not stored in the plugin binary data, only the pathway to the image on your system is stored.  This means that if you change the location of the image, rename the image, or move the entire session to another computer, your image links will be broken.  A good piece of advice is to copy the images you want to use into your session folders and then load them from there.

## Currently Supported Formats:
* 64 bit for Mac 10.6+: VST, AU

## Bugs / Known Issues:
### Global Issues:
* Images are always on top.  This is a "hack" because the main plugin window always tries to gain focus and cover up the image window (in most DAWs).  To combat that, I've forced the new window to always be on top.
* Some images load and display larger than they really are.

### VST in Reaper:
* Spacebar focus is being stolen - User needs to engage FX menu setting "Send all keyboard input to plug - in"

### AU in Garageband
* Insert Timestamp does not work (DAW doesn't provide this info to developers?)
* Some text editor key commands aren't picked up, such as command+a for selecting all text

## Other things to do before next release:
* Make string pointers private
* Make setter and getter methods for processor class strings
* Set up plugin category information
* Test other DAWs

## Future features (after v1.0.0 release)
* Fix bugs and known issues
* Allow for as many images to be loaded into the plugin (not limited to 2)
* Show image preview so user doesn't need to open external full sized image every time'
* Resizable windows / GUI
* User picked fonts, font sizes, and background color?
* AAX
* PC Versions
