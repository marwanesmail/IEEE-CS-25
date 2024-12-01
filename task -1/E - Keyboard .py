def find_original_message(direction, typed_message):
    keyboard = [
        "qwertyuiop",
        "asdfghjkl;",
        "zxcvbnm,./"
    ]
    
    key_map = {}
    for row in keyboard:
        for i in range(len(row)):
            if direction == 'R':
                if i > 0:
                    key_map[row[i]] = row[i - 1]
            elif direction == 'L':
                if i < len(row) - 1:
                    key_map[row[i]] = row[i + 1]
    
    original_message = ''.join(key_map[char] for char in typed_message)
    return original_message

direction = 'R'
typed_message = 's;;upimrrfod;pbr'

print(find_original_message(direction, typed_message))
