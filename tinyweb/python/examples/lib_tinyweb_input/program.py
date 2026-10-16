import tinyweb as tw
import tinyweb_external as tw_external
tw_external.web_init(0)
c = tw_external.canvas(300, 200)
tw.rect(c, 0, 0, 300, 200, '#eeeeee')
tw.line(c, 0, 0, 300, 200, tw.line__default__color(), tw.line__default__width())
tw.line(c, 0, 200, 300, 0, 'red', 3)
tw.text(c, 10, 10, 'click "me"', tw.text__default__color(), 20)
status = tw_external.label('nothing yet')

def clicked(x, y):
    tw_external.set_label(status, 'clicked at ' + str(x) + ', ' + str(y))
    return tw.circle(c, x, y, 5, 'blue')

def pressed(key):
    print('key [' + key + ']')
    if key == 'Enter':
        tw.play_file('snare1.wav')
    return ()

def moved(value):
    return tw_external.set_label(status, 'slider at ' + str(value))

tw_external.on_mouse(c, clicked)
tw_external.on_key(pressed)
tw.slider(0, 10, 5, moved)
tw.slider(1, 3, 2, tw.slider__default__on_change())
