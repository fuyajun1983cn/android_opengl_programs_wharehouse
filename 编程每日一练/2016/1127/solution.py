#!/usr/bin/env python3

def solution():
    size = int(input("Please input size of the array: "))
    elements = input ("Please input elements of the array separated by space: ")
    elements = elements.split(" ")

    result = [0 for i in range(size)]
    for i in range(size):
        if result[int(elements[i])] == 1:
            return elements[i]
        else:
            result[int(elements[i])] = 1

    return "not found"

if __name__ == "__main__":
    print("duplicat element is: " + solution() )
        
