# Track-Notes
A simple plugin to hold your session and track notes.

![alt tag](https://github.com/JosephTLyons/Track-Notes/blob/master/Images/Track%20Notes%20GUI.png?raw=true)
-Image is larger than the actual GUI

# Purchase:
* This plugin isn't free, it costs 1 USD.  A link to my paypal is here: paypal.me/JosephTimothyLyons/1
* There is no piracy protection, so I will never know if you purchased or not, this is based on an honors system.
* Download the plugin and demo it as long as you like, but if you like it, please purchase it, and if you dislike it, please delete it from your system.
* Do not blind purchase.  I am brand new to developing and expect to have bugs in my initial release.  I'm not sure how long or what sort of research I'll have to do to fix these bugs (for instance, obtaining a DAW I don't own that isn't free), so its best to just demo it first.  If there's a bug, please report it to me at JosephTLyons@gmail.com and wait for a bug fix before purchasing.
* I have listed all the future features that I'd like to add, but none of these are guaranteed.  I may not be able to implement them all due to my limited experience with programming, so please do not buy based on what I might try to implement in the future, as they are not guaranteed.

## Bugs / Known Issues:
### Global Issues:
* New image windows are stuck behind main plugin window 

### VST in Reaper:
* Spacebar focus is being stolen - User needs to engage FX menu setting "Send all keyboard input to plug - in"

### AU in Garageband
* Insert Timestamp is broken
* Crashes DAW on reopening a window
* Command+a to select all isn't working

## Things to do before release:
* Image related:
* check to make sure image is loaded before trying to display
* save images
* load imates
* handle duplicate code in both load button handler regions
* will recall of the images set the names of their corresponding display buttons back to their correct names?
* New windows always pop up behind current window and in the corner 
* Some images are loaded at sizes that are different from their originals

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
* Resizable windows / GUI
* User picked fonts, font sizes, and background color?
* AAX
