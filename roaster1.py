import csv
import sys
from cs50 import SQL

if len(sys.argv) != 2:
    if sys.argv[1] != "Gryffindor" or sys.argv[1] != "Slytherin" or sys.argv[1] != "Hufflepuff" or sys.argv[1] != "Ravenclaw":
        print("Usage: python roster.py house")

db = SQL("sqlite:///students.db")

house_list = db.execute("SELECT first, middle, last, birth FROM students WHERE house = (?) ORDER BY last, first", sys.argv[1])

for row in house_list:
    if row["middle"] == None:
        print(row["first"] + " " + row["last"] + ", born " + str(row["birth"]))
    else:
        print(row["first"] + " " + row["middle"] + " " + row["last"] + ", born " + str(row["birth"]))