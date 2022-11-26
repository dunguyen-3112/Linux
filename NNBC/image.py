import requests


f = open('/mnt/d/linux/NNBC/102180145.txt', 'r')
x = f.readline()
while x:
    x = x.strip()
    k = x[3: 5]

    with open('./img/{x}.jpg'.format(x=x), 'wb') as handle:
        print("http: // cb.dut.udn.vn/ImageSV/{k}/{x}.jpg".format(x=x, k=k))
        response = requests.get(
            "http://cb.dut.udn.vn/ImageSV/{k}/{x}.jpg".format(x=x, k=k), stream=True)

        if not response.ok:
            print(response)

        else:
            for block in response.iter_content(1024):
                if not block:
                    break

                handle.write(block)

    x = f.readline()
