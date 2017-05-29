# Track-Notes
A simple plugin to hold your session and track notes.

![alt tag](https://github.com/JosephTLyons/Track-Notes/blob/master/Images/Track%20Notes%20GUI.png?raw=true)
-Image is larger than the actual GUI

# Purchase:
* This plugin isn't free, it costs 1 USD: paypal.me/JosephTimothyLyons/1
* There is no piracy protection, so I will never know if you purchased or not, this is entirely based on an honors system.
* Download the plugin and demo it as long as you like, but if you like it, please purchase it, and if you dislike it, please delete it from your system.
* Do not blind purchase.  I am brand new to developing and expect to have bugs in my initial release.  I'm not sure how long or what sort of research I'll have to do to fix these bugs (for instance, obtaining a DAW I don't own that isn't free), so its best to just demo it first.  If there's a bug, please report it to me at JosephTLyons@gmail.com and wait for a bug fix before purchasing.
* Do not purchase based on future features.  I have listed all the future features that I'd like to add in this README, but none of these are guaranteed.  I may not be able to implement them all due to my limited experience with programming, so please do not buy based on what is currently available.

## Currently Supported Formats:
* Mac 10.6+: VST, AU

## Bugs / Known Issues:
### Global Issues:
* Images are always on top.  This is a "hack" because the main plugin window always tries to gain focus and cover up the image window.  To combat that, I've forced the new window to always be on top.
* Some images load and display larger than they really are.

### VST in Reaper:
* Spacebar focus is being stolen - User needs to engage FX menu setting "Send all keyboard input to plug - in"

### AU in Garageband
* Insert Timestamp does not work (DAW doesn't provide this info to developers?)
* Command+a to select all isn't working

## Things to do before release:
* Save image bug fixed
* Make string pointers private
* Make setter and getter methods for processor class strings
* Set up all menu information for each plugin format (category, company name, etc).
* Test other DAWs
* Graphics overhaul - revise separation line?
* Turn off JUCE splash screen if I open-source
* Add new GUI to ReadMe, Clean up ReadMe as well

## Future features (after v1.0.0 release)
* Fix bugs and known issues
* Resizable windows / GUI
* User picked fonts, font sizes, and background color?
* AAX
* PC Versions
