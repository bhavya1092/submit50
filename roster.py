# TODO
from sys import argv
from cs50 import SQL
import csv

def main(argv):
    
    # Check input
    if len(argv) != 2:
        print("Usage: python roster.py houses")
        exit(1)
    
    # Open database
    open("students.db", "r").close()
    db = SQL("sqlite:///students.db")
    
    # Lay gia tri ra
    first = []
    house_2 = argv[1]
    first = db.execute("SELECT first,middle,last,birth from students where house = ? order by last,first", house_2)
    print(first)
    for row in first:
        print(row["first"], end = ' ')
        if row["middle"] != None: print(row["middle"], end = ' ')
        print(row["last"], end = ',')
        print(f" born",row["birth"])
    
if __name__ == "__main__":
    main(argv)P