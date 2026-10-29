# Here we adapt list to imitate stack
s = input("Please input your string, which only include:(, ), [, ], {, }:")
priority = {'{':3, '[':2, '(':1, '}':4, ']':5, ')':6}
stack = []
top=-1

for i in range(0,len(s)):
    if top==-1 or priority[s[i]] <= priority[stack[top]]:
        top+=1
        stack.append(s[i])
    else:
        if priority[stack[top]] + priority[s[i]] != 7:
            break
        else:
            stack.pop()
            top -= 1

if s == '' or top==-1:
    print("expression is corret, enjoy it:)")
else:
    print("expression has some error, please check!")