import csv
import sys
from cs50 import SQL

if len(sys.argv) != 2:
    print("Usage: python import.py characters.csv")
    sys.exit(1)

db = SQL("sqlite:///students.db")

with open(sys.argv[1], "r") as characters:

    reader = csv.DictReader(characters, delimiter=",")

    for row in reader:

        name = row["name"]
        name_list = name.split()

        if len(name_list) == 2:
            first_name = name_list[0]
            last_name = name_list[1]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       first_name, None, last_name, row["house"], row["birth"])
        elif len(name_list) == 3:
            first_name = name_list[0]
            middle_name = name_list[1]
            last_name = name_list[2]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       first_name, middle_name, last_name, row["house"], row["birthP