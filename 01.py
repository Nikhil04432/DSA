def createset():
    n = int(input("Enter the number of elements you want to insert: "))
    s = set()
    for i in range(n):
        element = int(input(f"Enter the {i + 1} element: "))
        s.add(element)
    return s

def Insertele(s):
    element = int(input("Enter the element you want to insert: "))
    s.add(element)
    print(s)

def Deleteele(s):
    element = int(input("Enter the element you want to remove: "))
    if element in s:
        s.remove(element)
        print("Element Removed from set")
    else:
        print("Element Not Found in set")
    print(s)

def Searchele(s):
    element = int(input("Enter the element to search: "))
    if element in s:
        print("Element found in set")
    else:
        print("Element not found in set")

def Setsize(s):
    print("Size of the set:", len(s))

def operation(n, set1, set2):
    if n == 5:
        print("Union of sets:", set1.union(set2))
    elif n == 6:
        print("Intersection of sets:", set1.intersection(set2))
    elif n == 7:
        print("Difference of sets:", set1.difference(set2))
    elif n == 8:
        if set2.issubset(set1):
            print("Set B is a subset of Set A")
        else:
            print("Set B is not a subset of Set A")
    elif n == 9:
        if set2.issubset(set1) and set2 != set1:
            print("Set B is a proper subset of Set A")
        else:
            print("Set B is not a proper subset of Set A")

s1 = createset()

while True:
    print("\nOptions:")
    print("1. Add element")
    print("2. Remove element")
    print("3. Search element")
    print("4. Size of set")
    print("5. Union of sets")
    print("6. Intersection of sets")
    print("7. Difference of sets")
    print("8. Check subset")
    print("9. Check proper subset")
    print("0. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 0:
        print("Exiting the program.")
        break
    elif choice == 1:
        Insertele(s1)
    elif choice == 2:
        Deleteele(s1)
    elif choice == 3:
        Searchele(s1)
    elif choice == 4:
        Setsize(s1)
    elif 5 <= choice <= 9:
        print("\tEnter the data of second set.")
        s2 = createset()
        operation(choice, s1, s2)
    else:
        print("Invalid choice.")