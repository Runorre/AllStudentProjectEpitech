from math import *
import sys

def average(n, period, temperatures):
    if n < period:
        return float('nan')
    
    sum = 0
    for i in range(n - period, n):
        val = temperatures[i + 1] - temperatures[i]
        if val > 0:
            sum += val
    
    return round(sum / period, 2)

def evolution(n, period, temperatures):
    if n < period:
        return float('nan')
    
    sum = (temperatures[n] - temperatures[n - period]) / temperatures[n - period]
    return round(sum * 100, 0)

def deviation(n, period, temperatures):
    if n < period - 1:
        return float('nan')
    
    last_seven = temperatures[n - period + 1:n + 1]
    mean = sum(last_seven) / period
    squared_diff = [(x - mean) ** 2 for x in last_seven]
    variance = sum(squared_diff) / period
    std_deviation = sqrt(variance)
    
    return round(std_deviation, 2)

def is_float(string):
    try:
        float(string)
        return True
    except ValueError:
        return False

def addFluctuationToList(fluctuation_list, temperatures, period, deviation):
    total = 0
    if len(temperatures) < period :
        return fluctuation_list
    for i in range (period) :
        total += temperatures[(len(temperatures) - period) + i]
    if 4 * deviation > 0 and deviation != 0:
        lastTemp = (temperatures[-1] - ((total / period) - (2 * deviation))) / (4 * deviation)
        fluctuation_list.append(1 - lastTemp if lastTemp > 0.5 else lastTemp)
    elif deviation == 0:
        fluctuation_list.append(temperatures[-1] - (total / period))
    return fluctuation_list

def getMinIndex(fluctuation_list):
    min = fluctuation_list[0]
    index = 0
    for i in range(len(fluctuation_list)):
        if fluctuation_list[i] < min :
            min = fluctuation_list[i]
            index = i
    return index

def displayStop(fluctuation_list, switch_occured):
    nbValues = 5
    weirdest_values = []
    fluctuation_list.pop(0)
    for i in range(nbValues):
        current_index = getMinIndex(fluctuation_list)
        weirdest_values.append(temperatures[current_index + period])
        fluctuation_list[current_index] = 42

    print(f"Global tendency switched {switch_occured} times")
    print(f"{nbValues} weirdest values are {weirdest_values}")


if sys.argv.__len__() != 2 or not sys.argv[1].isdigit() :
    exit(84)

period = int(sys.argv[1])

if period <= 1:
    exit(84)

i = 0
switch_occured = 0

fluctuation_list = []
temperatures = []

while (1) :
    try:
        myInput = input()
        if myInput == "STOP" :
            if temperatures.__len__() < period :
                exit(84)
            displayStop(fluctuation_list, switch_occured)
            exit(0)
        if not is_float(myInput) :
            exit(84)
        temperatures.append(float(myInput))
        if i >= 1 and (evolution(i-1, period, temperatures) * evolution(i, period, temperatures) < 0):
            switch_occured += 1
            print(f"g={average(i, period, temperatures):.2f}\t\tr={evolution(i, period, temperatures):.0f}%\t\ts={deviation(i, period, temperatures):.2f}\t\ta switch occurs")
        else:
            print(f"g={average(i, period, temperatures):.2f}\t\tr={evolution(i, period, temperatures):.0f}%\t\ts={deviation(i, period, temperatures):.2f}")
        fluctuation_list = addFluctuationToList(fluctuation_list, temperatures, period, deviation(i, period, temperatures))
        i += 1
    except KeyboardInterrupt:
        exit(84)
exit(0)
