import tinyweb as tw
import tinyweb_external as tw_external
tw.web_init(0)
tw.theme('paper')
tw.theme('no such theme')
tw.page_style('#fdf6e3', '#586e75', 'serif', 18, 12, 16, tw.page_style__default__align())
tw.button_style('#268bd2', 'white', 'none', 14, 'monospace', 16, 8)
tw.label_style('lightyellow', '#333333', '1px solid gold', 4, 'sans-serif', 14, 6)
tw.slider_style('crimson', 240, 'crimson', 'monospace', 20)
tw.canvas_style('3px solid teal', 10)
title = tw_external.label('Styled')
tw.set_style(title, 'navy', 'white', '2px dashed orange', 0, 'Georgia', 28, 10, tw.set_style__default__accent(), 300, tw.set_style__default__weight(), tw.set_style__default__height())
level = tw.slider(0, 10, 4, tw.slider__default__on_change())
tw.set_colors(level, 'seagreen', tw.set_colors__default__background())
c = tw_external.canvas(120, 60)
tw.set_style(c, tw.set_style__default__background(), tw.set_style__default__color(), '1px solid black', tw.set_style__default__radius(), tw.set_style__default__font(), tw.set_style__default__size(), tw.set_style__default__padding(), tw.set_style__default__accent(), tw.set_style__default__width(), tw.set_style__default__weight(), tw.set_style__default__height())

def pressed():
    tw.theme('retro')
    tw.set_colors(title, tw.set_colors__default__color(), 'black')
    print('now retro')
    return ()

ok = tw.button('Retro', pressed)
tw.set_colors(ok, 'black', 'gold')
