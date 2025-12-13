# zsa-voyager-qmk

Personal ZSA voyager keyboard config
qmk firmware version >= 0.28.0 with community modules

## configuration
* qwerty keyboard layout
* homerow mod: GACS
* thumbs
    * left: Enter, OSM(LSHIFT)
    * right: Backspace, Space
* layers
    * NAV: arrow keys/page up/page down/home/end/insert/delete etc + left-hand shortcuts
    * SYM: symbol layer
    * FN: Function keys
    * TMUX: tmux shortcuts
    * EXT: mouse keys
* combo:
    * cv = caps word toggle
    * m, = ctrl+space/win+space depending on OS, switch input method
    * fg = toggle DRAG_SCROLL
* community module: lumino/palettefx
    * randomly pick an effect/palette at startup
* community module: select word
    * quickly select word forward/backward or select line
* other custom keycodes
    * APPNEXT/APPPREV: swap foreground app
* optional feature: vim navigation layer DIR
    * DIR: prefix keystroke with [ or ] for vim, or other directional navigation, define DIRECTION_LAYER_ENABLE to enable DIR
