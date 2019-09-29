# Bugs / Known Issues:
## Global Issues:
* Insert Timestamp does not work in some DAWs, output may be all zeros or garbage values (GarageBand, Logic).
* Image windows are always on top.  This is a "hack" because the main plugin window always tries to gain focus and cover up the image window (in most DAWs).  To combat that, I've forced the new window to always be on top.

## VST in Reaper:
* Spacebar focus is being stolen - User needs to engage FX menu setting "Send all keyboard input to plug - in"

## AU in Garageband:
* Some text editor key commands aren't picked up, such as command+a for selecting all text
