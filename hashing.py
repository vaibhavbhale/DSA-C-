 
def create_hash_table(size): 
    return [-1] * size 
 
def linear_probing_insert(hash_table, size, name, tel_no): 
    Data = (name, tel_no) 
    index = tel_no % size 
    ori_index = index 
 
    while hash_table[index] != -1: 
        index = (index + 1) % size 
        if index == ori_index: 
            print("Table is FULL. Cannot insert data.") 
            return 
 
    hash_table[index] = Data 
    print(f"{Data} is inserted at index {index}.") 
    
def search_in_linearprobing(hash_table, size, key): 
    index = key % size 
    ori_index = index 
    comp = 1 
    
    while hash_table[index] != -1: 
        if hash_table[index][1] == key: 
            print(f"Key found at index {index}") 
            print(f"Comparisons required: {comp}") 
            return hash_table[index] 
        index = (index + 1) % size 
        comp += 1 
        if index == ori_index: 
            print("Key not found.") 
            return 
 
    print("Key not found.") 
    return 
 
def display(hash_table): 
    print("Index\tName\tMobile No.") 
    for index, item in enumerate(hash_table): 
        if item != -1: 
            print(f"{index}\t{item[0]}\t{item[1]}") 
        else: 
            print(f"{index}\tEmpty") 
 
def quad_probing_insert(hash_table, size, name, tel_no): 
    Data = (name, tel_no) 
    index = tel_no % size 
    ori_index = index 
    i = 1 
 
    while hash_table[index] != -1: 
        index = (ori_index + i * i) % size 
        if index == ori_index: 
            print("Table is FULL. Cannot insert data.") 
            return 
        i += 1   
 
    hash_table[index] = Data 
    print(f"{Data} is inserted at index {index}.") 
 
    
def search_in_quadprobing(hash_table, size, key): 
    index = key % size 
    ori_index = index 
    comp = 1 
    i = 1 
 
    while hash_table[index] != -1: 
        if hash_table[index][1] == key: 
            print(f"Key found at index {index}") 
            print(f"Comparisons required: {comp}") 
            return hash_table[index] 
        index = (ori_index + i * i) % size 
        comp += 1 
        if index == ori_index: 
            print("Key not found.") 
            return 
        i += 1 
 
    print("Key not found.") 
    return 
 
def main(): 
    size = int(input("Enter size of the table: ")) 
    hash_table = create_hash_table(size) 
 
    while True: 
        print("-----------MENU-------------") 
        print("1. Insert in Linear Probing") 
        print("2. Search in Linear Probing") 
        print("3. Insert in Quadratic Probing") 
        print("4. Search in Quadratic Probing") 
        print("5. Display Table") 
        print("6. Exit") 
        ch = int(input("Enter your choice: ")) 
 
        if ch == 1: 
            tel_no = int(input("Enter phone number: ")) 
            name = input("Enter name: ") 
            linear_probing_insert(hash_table, size, name, tel_no) 
 
        elif ch == 2: 
            key = int(input("Enter phone number to search: ")) 
            result = search_in_linearprobing(hash_table, size, key) 
            if result: 
                print(f"Found: {result}") 
 
        elif ch == 3: 
            tel_no = int(input("Enter phone number: ")) 
            name = input("Enter name: ") 
            quad_probing_insert(hash_table, size, name, tel_no) 
 
        elif ch == 4: 
            key = int(input("Enter phone number to search: ")) 
            result = search_in_quadprobing(hash_table, size, key) 
            if result: 
                print(f"Found: {result}") 
 
        elif ch == 5: 
            display(hash_table) 
 
        elif ch == 6: 
            print("Exit") 
            break 
 
        else: 
            print("Invalid choice. Please try again.") 
 
if __name__== "__main__": 
    main() 

