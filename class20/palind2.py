def palind2(s):
    alist=list(s)
    alist.reverse()
    revs="".join(alist)
    if revs==s:
        return True
    return False
print palind2("ratsliveonnoevilstar")
print palind2("amanaplanacanalpanama")
print palind2("madammimadam")
