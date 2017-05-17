# Track-Notes
A simple plugin to hold your session and track notes.

![alt tag](https://github.com/JosephTLyons/Track-Notes/blob/master/Images/Track%20Notes%20GUI.png?raw=true)
-Image is larger than the actual GUI

## Bugs:
### VST in Reaper:
* Spacebar focus is being stolen

### AU in Garageband
* Insert Timestamp is broken
* Crashes DAW on reopening a window

## Things to do before release:
* Make string pointers private
* Make setter and getter methods for processor class strings

* Set up all menu information for each plugin format (category, company name, etc).
* Grab time in standalone crashes app (need to use an if-statement of some sort here)
* Reaper space focus steal (Make sure "Send all keyboard input to plugin" is turned on)
* Garageband playhead info for time grab
* Test other DAWs
* Graphics overhaul - revise separation line?
* Turn off Insert Timestamp button for standalone (doesn't really matter since I wont put out a standalone version)

Future features (after v1.0.0 release)
* Ability to load images
* User picked fonts, font sizes, and background color?
* AAX
