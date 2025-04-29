from cs50 import get_int

def main():
    # promt the user for card number
    while True:
        card_number = get_int("Card Number: ")
        if card_number > 0:
            break
    # check for card length
    x = str(card_number)
    # check cardsum
    if sum(card_number) == 0:
        return 0

    # check mastercard, visa, AE, or invalid
    if len(x) == 15 and (x[:2] == '37' or x[:2] == '34'):
        print("AMEX")
    elif len(x) == 16 and (x[:2] == '51' or x[:2] == '52' or x[:2] == '53' or x[:2] == '54' or x[:2] == '55'):
        print("MASTERCARD")
    elif len(x) == 13 or len(x) == 16 and x[:1] == '4':
        print("VISA")
    else:
        print("INVALID")

def sum(no):
    digits = []
    strno = str(no)
    size = len(strno)

    for i in range(0, size, 2):
        save = strno[size - i - 1]
        digits.append(int(save))

    for i in range(0, size - 1, 2):
        save = strno[size - 2-i]
        digits.append(int(save)*2)

    sum = 0
    for i in digits:
        if i > 9:
            n = i % 10
            x = i//10
            i = x + n
        sum = sum + i
    lensum = str(sum)
    sumsize = len(lensum)
    if lensum[sumsize - 1] != '0':
        print("INVALID")
        return 0
    return sum

main()
