# ClassIn-Mover

A C++ program to move `ClassIn` classroom window in order to exit from focused learning mode.

Supported `ClassIn` version: `3.0.2.130` to `3.0.5.1`, as well as `3.0.7.x`. (ClassIn prior to `3.0.2.130` does not have focused learning mode at all)

Maybe the program will lose efficacy in the future versions.

## Usage

Run this program before entering the classroom, then get into the classroom as normal.

After that, the program will automatically detect the classroom window, and make it unable to occupy the whole screen.

If working well, the program should output one line of log each second, showing the current working status.

## Known issues

- **This program calls native API and thus can only work on Windows.**

- The patched classroom window will still be maximized, but you can place other windows above it or simply switch to another window.

- Occasionally the program will not work, please exit the classroom and retry.

- The program will only apply changes to one classroom if you open two or more at the same time.

  This is not a big matter, since few people need to login into multiple accounts at once.
