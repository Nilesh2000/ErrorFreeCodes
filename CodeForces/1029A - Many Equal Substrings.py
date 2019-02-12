n, k = input().split()  # Splitting the input where a white space occurs. n corresponds to the first input nad k
# corresponds to the second input
t = input() # Input for the string
i = 1
while t[i:] != t[:-i] :
    i += 1
print(t[:i] * int(k) + t[i:])
