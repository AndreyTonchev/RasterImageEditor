# Raster Image Editor

A C++ image processing library with session-based editing and command pattern architecture.

## Image Class

The `Image` class is the abstract base for all raster images. It stores image metadata including dimensions, filename, and maximum pixel value. The class contains a pointer to an `AbstractPixelMatrix` that holds the actual pixel data.

Key features:
- Provides access to individual pixels through coordinate-based indexing
- Supports resizing operations that preserve existing pixel data
- Implements geometric transformations (rotations, mirroring, diagonal flips)
- Offers color transformations (negative, grayscale, monochrome)
- Manages image orientation through an orientation enumeration
- Handles file I/O operations for saving processed images

The Image class uses a transformation lookup table to efficiently combine multiple orientation operations without degrading image quality.

## Pixel Matrix

The `AbstractPixelMatrix` defines the interface for 2D pixel grids, implemented concretely by the templated `PixelMatrix<PixelType>` class.

Architecture:
- Stores pixels in a 2D vector structure for efficient access
- Provides coordinate-based pixel access with bounds checking
- Supports dynamic resizing while preserving overlapping regions
- Implements deep cloning for safe copying operations

The matrix supports multiple print orientations without modifying the underlying data - it can display the pixel grid rotated or mirrored for preview purposes while keeping the original data intact.

Transformation capabilities include applying filters across all pixels (negative, grayscale, monochrome) and supporting the various geometric transformations defined in the Image class.

## Pixel Classes

The pixel system uses a three-tier hierarchy:

**AbstractPixel**: Pure virtual interface defining pixel operations including channel access, copying, and color transformations.

**TemplatePixel<DataType, Channels>**: Template base class that implements the AbstractPixel interface for specific data types and channel counts. Handles generic operations like channel getting/setting and basic transformations.

**RGBPixel16**: Concrete implementation for 16-bit RGB pixels. Inherits from `TemplatePixel<uint16_t, 3>` and provides specialized implementations for RGB-specific operations like proper grayscale conversion using weighted averages.

The template design allows easy extension to different pixel formats (8-bit, 32-bit, different channel configurations) while maintaining type safety and performance.

## Session System

The `Session` class manages an editing workflow containing multiple images and their associated commands.

Features:
- Maintains a collection of `SessionImage` objects, each pairing an Image pointer with a status (PendingLoad, Loaded, Modified, Saved)
- Stores executed commands in a history for undo operations
- Tracks separate undo command stack for redo functionality
- Assigns unique IDs to each session for identification
- Prevents copying to maintain session integrity

The `SessionManager` singleton coordinates multiple sessions:
- Provides centralized access to all active sessions
- Manages the currently active session
- Handles session switching and lifecycle management
- Implements singleton pattern to ensure single point of control

## Command System

All image operations are implemented using the Command pattern through the abstract `Command` base class.

Command characteristics:
- Each command holds a reference to the current session
- Supports parsing of string arguments for parameterized operations
- Includes validation phase to check command validity before execution
- Can be marked as "instant" (executed immediately) or stored in history
- Supports undo capability flag for operations that can be reversed

Command lifecycle:
1. **Parse**: Process input arguments and configure command parameters
2. **Validate**: Check that the command can be executed with current parameters
3. **Execute**: Perform the actual operation on the target images
4. **History**: Store in session history if not marked as instant

The system automatically updates image status (Modified/Saved) based on command execution and provides utilities for status management across the session.