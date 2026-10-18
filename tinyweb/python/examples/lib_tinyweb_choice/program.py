import tinyweb as tw
import tinyweb_external as tw_external
tw.web_init(0)
names = ['ocean', 'candy', 'forest']
shown = tw_external.label('ocean')

def changed(position):
    return tw_external.set_label(shown, 'chose ' + str(position))

menu = tw.choice(names, tw.choice__default__chosen(), changed)
tw.choice(['one'], 0, tw.choice__default__on_change())
tw_external.set_value(menu, 2)
