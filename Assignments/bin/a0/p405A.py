num = input()
list = [int(i) for i in input().split()]
list = sorted(list)
out = str(list[0])
for item in list[1:len(list)]:
    out += " " + str(item)
print(out)
