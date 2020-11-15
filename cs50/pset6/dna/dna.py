import csv
import cs50
import sys
import os

if(len(sys.argv) != 3):
    print("Usage: python dna.py <.csv file> <dna sequence>")
    exit()

with open(sys.argv[1]) as database_file:
    database_reader = csv.reader(database_file)
    header = next(database_reader)
    header.pop(0)

with open(sys.argv[2]) as sequence_file:
    sequence_reader = csv.reader(sequence_file)
    sequence = next(sequence_reader)[0]

subjects = {}

for item in header:
    subjects[item] = 1

for key in subjects:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(sequence)):

        while temp > 0:
            temp -= 1
            continue

        if sequence[i: i + l] == key:
            while sequence[i - l: i] == sequence[i: i + l]:
                temp += 1
                i += l

            if temp > tempMax:
                tempMax = temp

    subjects[key] += tempMax

with open(sys.argv[1], newline='') as peoplefile:
    people = csv.DictReader(peoplefile)
    for person in people:
        match = 0
        for subject in subjects:
            if(subjects[subject] == int(person[subject])):
                match += 1

            if(match == len(subjects)):
                print(person['name'])
                exit()

    print("No match")