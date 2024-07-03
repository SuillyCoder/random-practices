# prac 2 in python
# started at about 2:30 PM
# finished at about 3:20 PM

# gets input from user
numMonth = int(input("Enter month: "))
date = int(input("Enter day: "))

# converts numeric month into the phrase month
match numMonth:
    case 1:
        wordMonth = "January"
    case 2:
        wordMonth = "February"
    case 3:
        wordMonth = "March"
    case 4:
        wordMonth = "April"
    case 5:
        wordMonth = "May"
    case 6:
        wordMonth = "June"
    case 7:
        wordMonth = "July"
    case 8:
        wordMonth = "August"    
    case 9:
        wordMonth = "September"
    case 10:
        wordMonth = "October"
    case 11:
        wordMonth = "November"
    case 12:
        wordMonth = "December"

# converts MM/DD into a day on the year
# Dec 22 = 374
days = ((numMonth - 1) * 32 + date) % 374

# calculates the zodiac sign from the ranges provided
if (days <= 19): # Jan 19 = 19
    zodiac = "Capricorn"
elif (days <= 50): # Feb 18 = 50
    zodiac = "Aquarius"
elif (days <= 84): # Mar 20 = 84
    zodiac = "Pisces"
elif (days <= 115): # Apr 19 = 115
    zodiac = "Aries"
elif (days <= 148): # May 20 = 148
    zodiac = "Taurus"
elif (days <= 180): # Jun 20 = 180
    zodiac = "Gemini"
elif (days <= 214): # Jul 22 = 214
    zodiac = "Cancer"
elif (days <= 246): # Aug 22 = 246
    zodiac = "Leo"
elif (days <= 278): # Sep 22 = 278
    zodiac = "Virgo"
elif (days <= 310): # Oct 22 = 310
    zodiac = "Libra"
elif (days <= 341): # Nov 21 = 341
    zodiac = "Scorpio"
else: # Nov 22 to Dec 21, Dec 22 to Dec 31 is handled by % 374
    zodiac = "Sagittarius"

# prints the horoscope information
print("Zodiac sign for", wordMonth, date, "is", zodiac)

