import tinyweb as tw
import tinyweb_external as tw_external
tw.web_init(0)
shown = tw_external.label('nothing yet')

def trails(on):
    return tw.set_text(shown, 'trails on' if on else 'trails off')

def mode(title):
    return tw.set_text(shown, 'mode: ' + title)

def entered(name):
    return tw.set_text(shown, 'hello, ' + name)

def balls(n):
    return tw.set_text(shown, str(n) + ' balls')

box = tw.checkbox('Trails', False, trails)
tw.checkbox('Slow frames', True, tw.checkbox__default__on_change())
tw.radio('mode', 'time-based', False, mode)
frame_based = tw.radio('mode', 'frame-based', False, mode)
tw.radio('speed', 'slow', False, tw.radio__default__on_pick())
tw.radio('speed', 'fast', True, tw.radio__default__on_pick())
tw.text_input('your name', entered)
tw.text_input('', tw.text_input__default__on_enter())
count = tw.number_input(1, 20, 3, balls)
speed = tw.slider(0, 10, 5, tw.slider__default__on_change())
tw_external.set_checked(box, True)
tw_external.set_checked(frame_based, True)
tw_external.set_value(count, 5)
tw_external.set_value(speed, 8)
gone = tw_external.label('going')
tw.hide(gone)
tw.show(gone)
tw.disable(speed)
tw.enable(speed)
tw.disable(box)
tw.remove(gone)
blank = tw_external.label('')
tw.set_text(blank, 'filled in')
print(frame_based, blank)
