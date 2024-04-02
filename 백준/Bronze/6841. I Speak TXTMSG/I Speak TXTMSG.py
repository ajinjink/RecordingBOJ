short = ["CU", ":-)", ":-(", ";-)", ":-P","(~.~)","TA","CCC","CUZ","TY","YW","TTYL"]
long = ["see you", "I’m happy", "I’m unhappy", "wink","stick out my tongue","sleepy","totally awesome","Canadian Computing Competition","because","thank-you","you’re welcome","talk to you later"]

while True:
    try:
        found = 0
        str = input().strip()
        if str == "TTYL":
            print("talk to you later")
            break
        for i in range(len(short)):
            if short[i] == str:
                print(long[i])
                found = 1
        if found == 0:
            print(str)
    except EOFError:
        break