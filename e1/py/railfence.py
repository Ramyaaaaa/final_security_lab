def encryptText(text,key):
    rail = [['-' for i in range(len(text))] for j in range(key)]
    isDown = False
    row = 0
    col = 0
    for i in range(len(text)):
        if (row == 0) or (row == key-1):
            isDown = not isDown
        rail[row][col] = text[i]
        col+=1
        if isDown == True:
            row += 1
        else:
            row -= 1
    encryptedText = ""
    for i in range(key):
        for j in range(len(text)):
            if rail[i][j] != '-':
                encryptedText += rail[i][j]
    return encryptedText

def decryptText(text,key):
    rail = [['-' for i in range(len(text))] for j in range(key)]
    isDown = None
    row = 0 
    col = 0
    for i in range(len(text)):
        if row == 0:
            isDown = True
        if row == key - 1:
            isDown = False
        
        rail[row][col] = "*"
        col+=1

        if isDown == True:
            row += 1
        else:
            row -= 1
    index = 0
    for i in range(key):
        for j in range(len(text)):
            if rail[i][j] == "*":
                rail[i][j] = text[index]
                index+=1
    isDown = None
    row = 0
    col = 0
    decryptedText = ""
    for i in range(len(text)):
        if row == 0:
            isDown = True
        if row == key - 1:
            isDown = False
        if rail[row][col] != "-":
            decryptedText += rail[row][col]
            col+=1
        if isDown == True:
            row+=1
        else:
            row-=1
    return decryptedText

text = input("Enter the text\n")
key = int(input("Enter the key \n"))

print(encryptText(text,key))
print(decryptText(encryptText(text,key),key))
