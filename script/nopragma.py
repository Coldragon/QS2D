import os

f = open(os.path.join(os.path.dirname(__file__), '..', 'bin', 'qs2d.h'), 'r')
read = f.readlines()
f.close()
print 'r', read
name = '#pragma once' # set this to what ever you are looking for
newfile = """"""
for i in read:
    print i
    print i[1]
    if name in i:
        pass
    else:
        newfile += i
n = open(os.path.join(os.path.dirname(__file__), '..', 'bin', 'qs2d.h'), 'w')
one = str(newfile)
n.write(one)
n.close()