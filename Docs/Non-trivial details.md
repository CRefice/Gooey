#Data structures
Most of the classes in this library only serve as a wrapper around system-specific handles.
For example, in windows, the Bitmap class defined in Drawing.hpp only contains an hbitmap handle. It doesn't contain the actual bitmap data.
#Default Control Visibility
By default, a control is visible on creation.
To change that, you must call SetDefaultVisible(false) before handle creation
(a.k.a. before calling Show(), Create(), or AddControl())
#Adding items to a menu
You cannot call Menu::AppendItem() with an rvalue as an argument, or you'll get undefined behavior.
This makes sense: why would you want to add a temporary menu item to a menu bar? You wouldn't be able to set any behavior for it, for example.
