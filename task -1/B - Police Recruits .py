def untreated_crimes(events):
    free_officers = 0
    untreated_crimes = 0

    for event in events:
        if event == -1:
            if free_officers > 0:
                free_officers -= 1
            else:
                untreated_crimes += 1
        else:
            free_officers += event

    return untreated_crimes

events = [1, -1, 1, -1, -1, 1, 1, 1]
print(untreated_crimes(events))  
