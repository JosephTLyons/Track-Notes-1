#  TODO.md

1. Fix all errors
2. Remove all deprecations
3. Add VST3 support and Legacy? 
4. Move Demo timer into plugin editor class and use inheritance
5. Clean up code
    - I think instead of linking all things across the process and editor class, I can just always use processor.whatever
    - Do I need to even have an imageMissing bool?  I can reference the imagePath.exists() directly or through process.whatever
