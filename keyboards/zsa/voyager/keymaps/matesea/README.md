# zsa-voyager-qmk

Personal ZSA voyager keyboard config
qmk firmware version >= 0.28.0 with community modules

## configuration
* qwerty keyboard layout
* homerow mod: GACS
* thumbs
    * left: Enter, Repeat
    * right: Backspace, Space
* layers
    * NAV: arrow keys/page up/page down/home/end/insert/delete etc + left-hand shortcuts
    * SYM: symbol layer
    * FN: Function keys
    * TMUX: tmux shortcuts
    * EXT: mouse keys
    * DIR: prefix keystroke with [ or ] for vim, or other directional navigation
* combo:
    * cv = caps word toggle
    * m, = ctrl+space/win+space depending on OS, switch input method
    * fg = toggle DRAG_SCROLL
    * hj = Alt Repeat
* community module: lumino/palettefx
    * randomly pick an effect/palette at startup
* community module: select word
    * quickly select word forward/backward or select line
* other custom keycodes
    * APPNEXT/APPPREV: swap foreground app
