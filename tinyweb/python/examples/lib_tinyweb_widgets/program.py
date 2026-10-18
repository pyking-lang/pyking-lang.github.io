import tinyweb as tw
import tinyweb_external as tw_external
tw.web_init(0)
shown = tw_external.label('nothing yet')

def trails(on):
    return tw_external.set_label(shown, 'trails on' if on else 'trails off')

def mode(title):
    return tw_external.set_label(shown, 'mode: ' + title)

def entered(name):
    return tw_external.set_label(shown, 'hello, ' + name)

def balls(n):
    return tw_external.set_label(shown, str(n) + ' balls')

box = tw.checkbox('Trails', tw.checkbox__default__checked(), trails)
tw.checkbox('Slow frames', True, tw.checkbox__default__on_change())
tw.radio('mode', 'time-based', tw.radio__default__chosen(), mode)
frame_based = tw.radio('mode', 'frame-based', tw.radio__default__chosen(), mode)
tw.radio('speed', 'slow', tw.radio__default__chosen(), tw.radio__default__on_pick())
tw.radio('speed', 'fast', True, tw.radio__default__on_pick())
tw.text_input('your name', entered)
tw.text_input(tw.text_input__default__placeholder(), tw.text_input__default__on_enter())
count = tw.number_input(1, 20, 3, balls)
speed = tw.slider(0, 10, 5, tw.slider__default__on_change())
tw_external.set_checked(box, True)
tw_external.set_checked(frame_based, True)
tw_external.set_value(count, 5)
tw_external.set_value(speed, 8)
print(frame_based)
