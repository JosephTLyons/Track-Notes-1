# Track-Notes
A simple plugin to hold your session and track notes.

![alt tag](https://github.com/JosephTLyons/Track-Notes/blob/master/Images/Track%20Notes%20GUI.png?raw=true)
-Image is larger than the actual GUI

## Bugs / Known Issues:
### VST in Reaper:
* Spacebar focus is being stolen - User needs to engage FX menu setting "Send all keyboard input to plug - in"
* Images will always pop up behind plugin window, this is Reaper behaviour and can't be changed'

### AU in Garageband
* Insert Timestamp is broken
* Crashes DAW on reopening a window
* Command+a to select all isn't working

## Things to do before release:
* Image related - check to make sure image is loaded before trying to display - save images - handle duplicate code in both load button handler regions - will recall of the images set the names of their corresponding display buttons back to their correct names? - New windows always pop up behind current window and in the corner.

* Append pointer items with Ptr
* Make string pointers private
* Make setter and getter methods for processor class strings

* Set up all menu information for each plugin format (category, company name, etc).
* Grab time in standalone crashes app (need to use an if-statement of some sort here)
* Reaper space focus steal (Make sure "Send all keyboard input to plugin" is turned on)
* Garageband playhead info for time grab
* Test other DAWs
* Graphics overhaul - revise separation line?
* Turn off Insert Timestamp button for standalone (doesn't really matter since I wont put out a standalone version)
* Turn off JUCE splash screen if I close the code up

Future features (after v1.0.0 release)
* Ability to load images
* User picked fonts, font sizes, and background color?
* AAX
