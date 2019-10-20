def encryptText(text,key):
    encryptedString = ""
    for i in range(len(text)):
        if key[i].isupper():
            value = ord(key[i]) - 65
        elif key[i].islower():
            value = ord(key[i]) -97
        if text[i].isupper():
            encryptedString += chr((ord(text[i]) + value - 65)% 26 + 65)
        elif text[i].islower():
            encryptedString += chr((ord(text[i]) + value - 97)% 26 + 97)
        else:
            encryptedString += chr((ord(text[i]) + ord(key[i])))
    return encryptedString

def decryptText(text,key):
    decryptedString = ""
    for i in range(len(text)):
        if key[i].isupper():
            value = ord(key[i]) - 65
        elif key[i].islower():
            value = ord(key[i]) -97
        if text[i].isupper():
            decryptedString += chr((ord(text[i]) - value - 65)% 26 + 65)
        elif text[i].islower():
            decryptedString += chr((ord(text[i]) - value - 97)% 26 + 97)
        else:
            decryptedString += chr((ord(text[i]) - ord(key[i])))
    return decryptedString

# (p[i]+k[i])%26
#(e[i]-k[i]+26) %26
text = input("Enter the text \n")
key = input("Enter the key \n")
while(len(key) < len(text)):
    key += key

key = key[:len(text)]
print(encryptText(text,key))
print(decryptText(encryptText(text,key), key))
