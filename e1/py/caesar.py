def encryptText(text,shift):
    encryptedString = ""
    for i in range(0,len(text)):
        if text[i].isupper():
            encryptedString += chr((ord(text[i]) + shift - 65) % 26 + 65)
        elif text[i].islower():
            encryptedString += chr((ord(text[i]) + shift - 97) % 26 + 97)
        else:
            encryptedString += chr(ord(text[i]) + shift)
    return encryptedString

def decryptText(text,shift):
    decryptedString = ""
    for i in range(0,len(text)):
        if text[i].isupper():
            decryptedString += chr((ord(text[i]) - shift - 65) % 26 + 65)
        elif text[i].islower():
            decryptedString += chr((ord(text[i]) - shift - 97) % 26 + 97)
        else:
            decryptedString += chr(ord(text[i]) - shift)
    return decryptedString


text = input("Enter the text \n")
print(text)
shift = int(input("Enter the shift \n"))
print(encryptText(text,shift))
print(decryptText(encryptText(text,shift),shift))
