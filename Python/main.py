import json

with open("movie.json", "r", encoding='utf-8') as j_file:
    contents = j_file.read()
    json_data = json.loads(contents)

print(json_data)
print(json_data["Title"])
