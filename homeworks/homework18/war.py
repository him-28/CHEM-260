from cards import *
adeck=deck()
adeck.shuffle()
adeck.printdeck()
bdeck=deck()
bdeck.shuffle()
a=0
b=0
c=0
for i in range(1000):
    adeck=deck()
    adeck.shuffle()
    #adeck.printdeck()
    bdeck=deck()
    bdeck.shuffle()
    for j in range(52):
        acard=adeck.dealcard()
        bcard=bdeck.dealcard()
        #print "acard:",
        #acard.printcard()
        #print "bcard:",
        #bcard.printcard()
        if acard.value() > bcard.value():
            #print "acard higher at %d" %j
            a+=2
        elif acard.value()<bcard.value():
            #print "bcard higher at %d" %j
            b+=2
        else:
            #print "cards equal at %d" %j
            a=1
            b=1
c=a-b
print c      
#print "cards left ",adeck.cardsleft()
