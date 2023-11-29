def dayOfWeek(year, month, day):
    #0S 1M 2T 3W 4Th 5F 6Sa
    #1 Jan 1900 is a monday (1)
    #First subtract years
    yearDistance = year-1900
    
    daysSinceEpoch = 365 * yearDistance
    
    numOfLeaps = (yearDistance//4) + ((yearDistance+300)//400) - (yearDistance//100) + 1

    daysSinceEpoch += numOfLeaps
    
    #2/28(9) 4/30 6/30 9/30
    monthDistance = (month-1) * 31
    if month > 9: monthDistance -= 1
    if month > 6: monthDistance -= 1
    if month > 4: monthDistance -= 1
    if month > 2: monthDistance -= 3

    daysSinceEpoch += monthDistance

    daysSinceEpoch += (day-1)

    return daysSinceEpoch % 7

def main():
    #for year in range 1901 - 2000
    #for month in year
    #check day-of-week for the first
    #sum
    fomSundays = 0
    for year in range(1901, 2001):
        for month in range(1,13):
            if dayOfWeek(year, month, 1) == 0:
                fomSundays += 1

    print(fomSundays)

if __name__ == "__main__":
    main()
