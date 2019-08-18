#  TODO.md

1. Remove all deprecations
2. Add back Legacy VST support after everything else
3. Clean up code
    - I think instead of linking all things across the process and editor class, I can just always use processor.whatever
        - After removing as much linked code as possible, I can probably move items into private spaces in both classes where they are declared public'
    - Do I need to create entire editors in the processor just to save the contents are can it be created in editor and only store strings in processor
4. Just launch a modal error when trying to open an image window with no images
5. Clean up README.md
6. What all can I remove from processor public entirely (can I access editor from processor?)
