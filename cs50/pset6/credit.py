from cs50 import get_int
import math

card = get_int("Card Number: ")
length = len(str(card))
start = int((card - (card % (10 ** (length - 2)))) / (10 ** (length - 2)))
card_string = str(card)
card_array = []

for i in range(len(str(card))):
    card_array.append(int(card_string[i]))

card_array.reverse()

for i in range(51, 56):
    if(start == i and length == 16):
        # Mastercard
        sum1, sum2 = 0, 0
        cursor = 0
        for i in range(1, len(card_array), 2):
            cursor = card_array[i] * 2
            if(cursor > 9):
                sum1 += (cursor % 10) + ((cursor - (cursor % 10)) / 10)

            else:
                sum1 += cursor

        for i in range(0, len(card_array), 2):
            cursor = card_array[i]
            sum2 += cursor

        if((sum1 + sum2) % 10 == 0):
            print("MASTER")

        else:
            print("INVALID")


if((start == 34 or start == 37) and length == 15):
    # Amex
    sum1, sum2 = 0, 0
    cursor = 0
    for i in range(1, len(card_array), 2):
        cursor = card_array[i] * 2
        if(cursor > 9):
            sum1 += (cursor % 10) + ((cursor - (cursor % 10)) / 10)

        else:
            sum1 += cursor

    for i in range(0, len(card_array), 2):
        cursor = card_array[i]
        sum2 += cursor

    if((sum1 + sum2) % 10 == 0):
        print("AMEX")

    else:
        print("INVALID")

if(math.floor(start / 10) == 4 and (length == 13 or length == 16)):
    # Visa
    sum1, sum2 = 0, 0
    cursor = 0
    for i in range(1, len(card_array), 2):
        cursor = card_array[i] * 2
        if(cursor > 9):
            sum1 += (cursor % 10) + ((cursor - (cursor % 10)) / 10)

        else:
            sum1 += cursor

    for i in range(0, len(card_array), 2):
        cursor = card_array[i]
        sum2 += cursor

    if((sum1 + sum2) % 10 == 0):
        print("VISA")

    else:
        print("INVALID")