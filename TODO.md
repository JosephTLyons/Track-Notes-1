#  TODO.md

1. Clean up code
    - I think instead of linking all things across the process and editor class,
      I can just always use processor.whatever
        - After removing as much linked code as possible, I can probably move
          items into private spaces in both classes where they are declared
          public
    - Do I need to create entire editors in the processor just to save the
      contents are can it be created in editor and only store strings in
      processor
        - Create public strings in the processor that get saved with XML and
          loaded from it.  Put the editors in the editor class.  Ways to sync
          the data from the editors to the strings
            1. Use listeners to save the data to the strings in the proc when
               the user types
            2. Use listeners to save the data to the strings in the proc when
               the user stops typing
            3. Just save the data to the strings in the proc in the editors
               destructor
2. Clean up README.md
3. What all can I remove from processor public entirely (can I access editor
   from processor?)
4. Increment version number and add actual features outside of code fixes /
   cleanup?

SIGN VST SDK LICENSES FOR VST2 and VST3?
FOLLOW TUTORIALS FOR SAVING AND FETCHING PLUGIN STATE
