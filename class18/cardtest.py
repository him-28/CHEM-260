from cards import *
adeck=deck()
adeck.shuffle()
adeck.printdeck()
bdeck=deck()
bdeck.shuffle()
for i in range(5):
    acard=adeck.dealcard()
    bcard=bdeck.dealcard()
    print "acard:",
    acard.printcard()
    print "bcard:",
    bcard.printcard()
    if acard.value()>bcard.value():
        print "acard higher"
    elif acard.value()<bcard.value():
        print "bcard higher"
    else:
        print "cards equal"
print "cards left ",adeck.cardsleft() 
