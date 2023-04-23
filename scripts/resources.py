import os

images = os.listdir('res')

for i in images:
        if '.ppm' not in i:
            images.remove(i)
for i in images:
        if '.ppm' not in i:
            images.remove(i)

d = []
for i in images:
    di = []
    f = open('res/' + i, 'rb')
    data = f.read(1)
    while data:
        di.append(int.from_bytes(data, 'big', signed=False))
        data = f.read(1)
    f.close()
    for i in range(13):
        di.pop(0)
    d.append(di)

for a in range(len(d)):
    filename = images[a].lower()
    filename = filename.replace('.ppm', '')
    header = ''
    header += '#pragma once\n#include "../src/util.h"\nstatic const u8 ' + filename.upper() + '_IMG[] = {'
    for b in d[a]:
        header += str(b) + ','
    header += '};\n'
    # print(header)
    f = open('res/' + filename + '.h', 'w')
    f.write(header)
    f.close()

# print(images)

