from datetime import date

start = date(2010, 8, 9)

print("Enter the day: ", end='')
day = int(input())
print("Enter the month: ", end='')
month = int(input())
print("Enter the year: ", end='')
year = int(input())

userDay = date(year, month, day)
print(userDay.strftime("%A"))
print(f"{(userDay-start).days} days ago")