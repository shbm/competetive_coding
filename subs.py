a = input()
b = input()
s = input()

n = len(s)
count = 0
for i in range(0, n):
    for j in range(i+1, n+1):
        if (a in s[i:j]) and (b in s[i:j]):
            count += 1

print(count)
