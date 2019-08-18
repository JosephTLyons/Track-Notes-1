#  TODO.md

1. Fix all errors
2. Remove all deprecations
3. Add VST3 and Legacy VST support? 
4. Move Demo timer into plugin editor class and use inheritance
5. Clean up code
    - I think instead of linking all things across the process and editor class, I can just always use processor.whatever
        - After removing as much linked code as possible, I can probably move items into private spaces in both classes where they are declared public
    - Do I need to even have an imageMissing bool?  I can reference the imagePath.exists() directly or through process.whatever
6. Just launch a modal error when trying to open an image window with no images
7. Clean up README.md
